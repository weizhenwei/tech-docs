/*
 * implement singleton pattern using c++11;
 * Author: weizhenwei
 */

#include <cstdio>
#include <string>

using namespace std;


template <typename T>
class Singleton {
public:
    template <typename... Args> static T* Instance(Args&&... args) {
        if (nullptr == m_pInstance) {
            m_pInstance = new T(std::forward<Args>(args)...);  // perfect forward;
        }

        return m_pInstance;
    }

    static T* GetInstance() {
        return m_pInstance;
    }

    static void DestroyInstance() {
        if (m_pInstance) {
            delete m_pInstance;
        }
        m_pInstance = nullptr;
    }

private:
    static T* m_pInstance;
};

template <class T> T* Singleton<T>::m_pInstance = nullptr;


struct A {
    A(const string& str) {
        printf("lvalue of A\n");
    }

    A(string&& str) {
        printf("rvalue of A\n");
    }
};

struct B {
    B(const string& str) {
        printf("lvalue of B\n");
    }

    B(string&& str) {
        printf("rvalue of B\n");
    }
};

struct C {
    C(int x, double y) {
        printf("constructor of C\n");
    }

    void Fun() {
        printf("test of C\n");
    }
};


int main() {
    string str {"bb"};

    Singleton<A>::Instance(str);
    Singleton<B>::Instance(move(str));
    Singleton<C>::Instance(1, 3.14);
    Singleton<C>::GetInstance()->Fun();

    Singleton<A>::DestroyInstance();
    Singleton<B>::DestroyInstance();
    Singleton<C>::DestroyInstance();

    return 0;
}

