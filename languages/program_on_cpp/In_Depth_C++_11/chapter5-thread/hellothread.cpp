/*
 * test c++11 thread;
 * Author: weizhenwei
 */

#include <iostream>
#include <thread>

void thread_task() {
    std::cout<< "hello, c++11 thread!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
}

int main() {
    std::thread t(thread_task);
    // t.join();
    t.detach();

    std::cout<< "hello, main thread!" << std::endl;

    return 0;
}

