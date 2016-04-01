#include <memory>
#include <functional>
#include <iostream>

struct Deletor {
    void operator()(int *p) {
        std::cout << "delete operator called" << std::endl;
        delete p;
    }
};

template<class T, class... Args> inline
typename std::enable_if<!std::is_array<T>::value, std::unique_ptr<T>>::type
make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

template<class T, class... Args> inline
typename std::enable_if<std::is_array<T>::value && std::extent<T>::value == 0,
         std::unique_ptr<T>>::type
make_uniqueArray(size_t size) {
    using targetType = typename std::remove_extent<T>::type;
    return std::unique_ptr<T>(new targetType[size]());
}

typedef struct Test {
    int a;
    int b;
    Test(int _a, int _b) : a(_a), b(_b) {}
}Test;

void deleteTestOperator(Test *pTest) {
    std::cout << "delete pTest operator" << std::endl;
    delete pTest;
}

void testDeleter() {
    int a = 3;
    int b = 4;
    std::unique_ptr<Test, std::function<void(Test*)>> pTest1(new Test(a, b),
            [&](Test* pT) {
            std::cout << "delete pTest" << std::endl;
            delete pT;
            });
    std::cout << "Test.a = " << pTest1->a << ", Test.b = " << pTest1->b << std::endl;

    a = 5;
    b = 6;
    std::unique_ptr<Test, std::function<void(Test*)>> pTest2(new Test(a, b), deleteTestOperator);
    std::cout << "Test.a = " << pTest2->a << ", Test.b = " << pTest2->b << std::endl;
}


int main(void) {
    using SmartPointer = std::unique_ptr<int, Deletor>;
    SmartPointer p1(new int(3));
    std::cout << "p1 value = " << *p1 << std::endl;

    SmartPointer p2 = std::move(p1); // after move, use of p1 cause crash.
    std::cout << "p2 value = " << *p2 << std::endl;

    p2.reset(new int(5));
    std::cout << "p2 value = " << *p2 << std::endl;

    std::unique_ptr<Test> pTest = make_unique<Test>(1, 2);
    std::cout << "Test.a = " << pTest->a << ", Test.b = " << pTest->b << std::endl;

    testDeleter();

    return 0;
}

