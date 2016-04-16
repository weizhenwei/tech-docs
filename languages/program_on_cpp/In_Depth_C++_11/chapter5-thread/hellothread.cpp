/*
 * test c++11 thread;
 * Author: weizhenwei
 */

#include <iostream>
#include <thread>

void thread_task() {
    std::cout<< "hello, c++11 thread!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main() {
    std::thread t(thread_task);
    // t.join();
    t.detach();


    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<< "hello, main thread!" << std::endl;
    std::cout << "Current thread_id:" << t.get_id() << std::endl;
    std::cout << "Hardware CPU numbers:" << std::thread::hardware_concurrency() << std::endl;

    return 0;
}

