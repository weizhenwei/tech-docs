/*
 * test c++11 mutex;
 * Author: weizhenwei
 */

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

std::mutex g_mutex;

void fun() {
    // g_mutex.lock();
    std::lock_guard<std::mutex> locker(g_mutex);

    std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
    std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;

    // g_mutex.unlock();
}

int main() {
    std::thread t1(fun);
    std::thread t2(fun);
    std::thread t3(fun);
    t1.join();
    t2.join();
    t3.join();

    return 0;
}

