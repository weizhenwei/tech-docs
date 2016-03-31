
#include <chrono>
#include <ratio>
#include <thread>
#include <iomanip>
#include <iostream>

int main() {
    // duration;
    std::chrono::milliseconds ms{3};
    std::chrono::microseconds us = ms * 2;
    std::chrono::duration<double, std::ratio<1, 30>> hz30{3.5};
    std::cout << "3 ms duration has " << ms.count() << " ticks" << std::endl;
    std::cout << "6 us duration has " << us.count() << " ticks" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    // time_point;
    using days_type = std::chrono::duration<int, std::ratio<60 * 60 * 24>>;
    std::chrono::time_point<std::chrono::system_clock, days_type> today =
        std::chrono::time_point_cast<days_type>(std::chrono::system_clock::now());
    std::cout << today.time_since_epoch().count() << " days since epoch" << std::endl;

    std::chrono::system_clock::time_point now = std::chrono::system_clock::now();
    std::time_t hnow = std::chrono::system_clock::to_time_t(now);
    std::time_t last = std::chrono::system_clock::to_time_t(now - std::chrono::hours(24));
    std::time_t next = std::chrono::system_clock::to_time_t(now + std::chrono::hours(24));
    // std::cout << "today is " << std::put_time(std::localtime(&hnow), "%F %T") << std::endl;

    return 0;
}


