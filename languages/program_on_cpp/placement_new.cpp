#include <iostream>
#include <string>
using namespace std;

#if 0
class X
{
public:
    X() { cout<<"constructor of X"<<endl; }
    ~X() { cout<<"destructor of X"<<endl;}

    void* operator new(size_t size, string str) {
        cout<<"operator new size "<<size<<" with string "<<str<<endl;
        return ::operator new(size);  // call global operator new;
    }

    void operator delete(void* pointee) {
        cout<<"operator delete"<<endl;
        ::operator delete(pointee);  // callglobal operator delete;
    }
private:
    int num;
};

int main() {
    X *px = new("A new class") X;
    delete px;

    return 0;
}
#endif

class X
{
public:
    X() { cout<<"constructor of X"<<endl; }
    ~X() { cout<<"destructor of X"<<endl;}

    void SetNum(int n)
    {
        num = n;
    }

    int GetNum()
    {
        return num;
    }

private:
    int num;
};

int main()
{
    char* buf = new char[sizeof(X)];
    X *px = new(buf) X;  // placement new;
    // X *px = new(buf) X;  // placement new;
    px->SetNum(10);
    cout<<px->GetNum()<<endl;
    px->~X();  // call destructor manually;
    delete []buf;

    return 0;
}


