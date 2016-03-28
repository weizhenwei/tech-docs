#include <iostream>
#include <utility>
#include <future>
#include <thread>
#include <vector>

int main(void) {
    std::future<int> f1 = std::async(std::launch::async, []() {
            return 8;
            });
    std::cout << f1.get() << std::endl;


    std::future<int> f2 = std::async(std::launch::async, []() {
            std::cout << 8 << std::endl;
            return 8;
            });
    f2.wait();


    // check future status;
    std::future<int> future = std::async(std::launch::async, []() {
            std::this_thread::sleep_for(std::chrono::seconds(3));
            return 8;
            });
    std::cout << "waiting..." << std::endl;
    std::future_status status;
    do {
        status = future.wait_for(std::chrono::seconds(1));
        if (status == std::future_status::deferred) {
            std::cout << "deferred" << std::endl;
        } else if (status == std::future_status::timeout) {
            std::cout << "timeout" << std::endl;
        } else if (status == std::future_status::ready) {
            std::cout << "ready" << std::endl;
        }
    } while (status != std::future_status::ready);
    std::cout << "result is " << future.get() << std::endl;

    return 0;
}

