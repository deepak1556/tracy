#ifndef __TRACYVIEW_HPP__
#define __TRACYVIEW_HPP__

#include <atomic>
#include <string>
#include <thread>

namespace tracy
{

struct QueueItem;

class View
{
public:
    View() : View( "127.0.0.1" ) {}
    View( const char* addr );
    ~View();

    static bool ShouldExit();

private:
    void Worker();
    void Process( const QueueItem& ev );

    std::string m_addr;

    std::thread m_thread;
    std::atomic<bool> m_shutdown;

    int64_t m_timeBegin;
};

}

#endif
