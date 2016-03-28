#include <iostream>
#include <utility>
#include <future>
#include <thread>
#include <vector>

int func(int x) {
    return x + 2;
}

int main(void) {
    // future
    std::packaged_task<int (int)> tsk(func);
    std::future<int> fut = tsk.get_future();
    std::thread(std::move(tsk), 2).detach();
    int value = fut.get();
    std::cout << "The result is " << value << std::endl;

    // promise
    std::promise<int> pr;
    std::thread t([](std::promise<int> &p) { p.set_value_at_thread_exit(9); },
            std::ref(pr));
    t.join();
    std::future<int> f = pr.get_future();
    auto r = f.get();
    std::cout << "The future get from promise is " << r << std::endl;

#if 0
    std::vector<std::shared_future<int>> v;
    auto ff = std::async(std::launch::async, [](int a, int b) { return a + b; }, 2, 3);
    v.push_back(ff);
    std::cout << "The shared_future result is " << v[0].get() << std::endl;
#endif

    return 0;
}

