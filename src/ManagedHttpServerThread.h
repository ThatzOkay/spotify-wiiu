#include <thread>
#include <atomic>
#include "../libs/tinyhttp/http.hpp"

class ManagedHttpServerThread
{
    public:
        ManagedHttpServerThread();
        ~ManagedHttpServerThread();

        void start();
        void stop();

    private:
    std::thread workerThread;
    bool isRunning;
    HttpServer httpServer;
};