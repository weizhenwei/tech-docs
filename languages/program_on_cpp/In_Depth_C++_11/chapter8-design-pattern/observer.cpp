#include <iostream>
#include <string>
#include <functional>
#include <map>

class NonCopyable {
protected:
    NonCopyable() = default;
    ~NonCopyable() = default;

    NonCopyable(const NonCopyable&) = delete;
    NonCopyable& operator = (const NonCopyable&) = delete;
};

template<typename Func>
class Events : public NonCopyable {
public:
    Events() {}
    ~Events() {}

    int connect(Func&& f) {
        return assign(f);
    }

    int connect(Func& f) {
        return assign(f);
    }

    void disconnect(int key) {
        m_connections.erase(key);
    }

    template<typename... Args>
    void notify(Args&&... args) {
        for (auto& it : m_connections) {
            std::cout << "key = " << it.first << std::endl;
            it.second(std::forward<Args>(args)...);
        }
    }

private:
    template<typename F>
    int assign(F&& f) {
        int k = m_observerID++;
        m_connections.emplace(k, std::forward<F>(f));
        return k;
    }

    int m_observerID = 0;
    std::map<int, Func> m_connections;
};

struct stA {
    int a, b;
    void print(int a, int b) {
        std::cout << a << ", " << b << std::endl;
    }
};

void print(int a, int b) {
    std::cout << a << ", " << b << std::endl;
}

int main() {
    Events<std::function<void(int, int)>> myevent;
    auto key = myevent.connect(print);
    std::cout << "key = " << key << std::endl;

    stA t;
    auto lambdakey = myevent.connect([&t](int a, int b) {
            t.a = a;
            t.b = b;
            std::cout << t.a << ", " << t.b << std::endl;
            });
    std::cout << "lambdakey = " << lambdakey << std::endl;

    std::function<void(int, int)> f = std::bind(&stA::print, &t, std::placeholders::_1, std::placeholders::_2);
    auto funckey = myevent.connect(f);
    std::cout << "funckey = " << funckey << std::endl;

    std::cout << std::endl;

    int a = 1;
    int b = 2;
    myevent.notify(a, b);
    std::cout << std::endl;

    a = 3;
    b = 4;
    myevent.disconnect(key);
    myevent.notify(a, b);
    std::cout << std::endl;

    a = 5;
    b = 6;
    myevent.disconnect(lambdakey);
    myevent.notify(a, b);
    std::cout << std::endl;

    a = 7;
    b = 8;
    myevent.disconnect(funckey);
    myevent.notify(a, b);
    std::cout << std::endl;

    return 0;
}

