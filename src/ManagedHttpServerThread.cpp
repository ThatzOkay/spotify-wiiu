
#include "ManagedHttpServerThread.h"
#include "../libs/chesto/src/Element.hpp"

ManagedHttpServerThread::ManagedHttpServerThread()
{
    isRunning = false;
}

ManagedHttpServerThread::~ManagedHttpServerThread()
{
    stop();
}

void ManagedHttpServerThread::start()
{
    httpServer.when("/")->serveFile(RAMFS "./res/index.html");

    httpServer.when("/callback")
        ->requested([](const HttpRequest& req) {
            std::string htmlFile = RAMFS "./res/callback.html";

            std::string queryStr = req.getQuery();
            std::string codeStr = queryStr.substr(queryStr.find("code="));
            std::string code = codeStr.substr(codeStr.find("=") + 1);

            WHBLogPrintf("Query string: %s", queryStr.c_str());
            WHBLogPrintf("Spotify code: %s", code.c_str());

            std::ifstream t(htmlFile.c_str());
                if (t.is_open())
                    return HttpResponse{200, getMimeType(htmlFile), std::string((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>())};
                else {
                    WHBLogPrintf("Could not locate file: %s\n", htmlFile.c_str());
                    return HttpResponse{404, "text/plain", "The requested file is missing from the server"};
                }
        });

    if(!isRunning)
    {
        isRunning = true;

        // start http server
        workerThread = std::thread([this](){
            httpServer.startListening(8088, isRunning);
        });
    }
}

void ManagedHttpServerThread::stop()
{
    if(isRunning)
    {
        isRunning = false;

        // stop http server
        httpServer.shutdown();

        // wait for thread to finish
        workerThread.join();
    }
}