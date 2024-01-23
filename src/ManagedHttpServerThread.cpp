
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