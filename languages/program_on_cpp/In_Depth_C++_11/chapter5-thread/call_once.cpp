/*
 * test c++11 thread call_once function;
 * Author: weizhenwei
 */

#include <iostream>
#include <thread>
#include <mutex>

std::once_flag flag;
std::mutex g_mutex;
int g_Counter = 1;

void do_once() {
    std::call_once(flag, []() {
            std::cout << "Called only once" << std::endl;
            g_Counter++;
            });

    g_mutex.lock();
    std::cout << "g_Counter = " << g_Counter
        << "thread ID = " << std::this_thread::get_id() << std::endl;
    g_mutex.unlock();
}

int main() {
    std::thread t1(do_once);
    std::thread t2(do_once);
    std::thread t3(do_once);

    t1.join();
    t2.join();
    t3.join();
}

