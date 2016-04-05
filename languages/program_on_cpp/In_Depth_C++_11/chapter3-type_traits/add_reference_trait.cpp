
#include <iostream>
#include <type_traits>
#include <memory>

template <class T>
struct Construct {
    typedef typename std::remove_reference<T>::type U;  // remove the possible reference;
    Construct() : m_ptr(new U) {}
    typename std::add_lvalue_reference<U>::type Get() const {
        return *m_ptr.get();
    }

private:
    std::unique_ptr<U> m_ptr;
};

void foo(void) {
    std::cout << "call a foo function" << std::endl;
}

template<typename F>
struct SimpleFunction {
    using FnType = typename std::decay<F>::type;
    SimpleFunction(F& f) : m_fn(f) {}
    void Run() { m_fn(); }
private:
    FnType m_fn;
};


int main(void) {
    Construct<int> c;
    int a = c.Get();
    std::cout << a << std::endl;

    // SimpleFunction<decltype(foo)> f(foo);
    using FN = decltype(foo);
    SimpleFunction<FN> f(foo);
    f.Run();

    return 0;
}

