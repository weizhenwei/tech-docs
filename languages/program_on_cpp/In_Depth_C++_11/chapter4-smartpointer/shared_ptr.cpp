#include <iostream>
#include <string>
#include <memory>

using namespace std;

static void test_unique() {
    unique_ptr<string> films[5] = {
        unique_ptr<string> (new string("Fowl Balls")),
        unique_ptr<string> (new string("Duck Walks")),
        unique_ptr<string> (new string("Chicken Runs")),
        unique_ptr<string> (new string("Turkey  Errors")),
        unique_ptr<string> (new string("Goose Eggs"))
    };

    cout << "The nominees for best avian baseball file are\n";
    for (int i = 0; i < 5; i++) {
        cout << *films[i] << endl;
    }
    unique_ptr<string> pwin = std::move(films[2]);

    cout << "The winner is " << *pwin << endl;
}

static void test_shared() {
    shared_ptr<string> films[5] = {
        shared_ptr<string> (new string("Fowl Balls")),
        shared_ptr<string> (new string("Duck Walks")),
        shared_ptr<string> (new string("Chicken Runs")),
        shared_ptr<string> (new string("Turkey  Errors")),
        shared_ptr<string> (new string("Goose Eggs"))
    };

    shared_ptr<string> pwin = films[2];
    cout << "The nominees for best avian baseball file are\n";
    for (int i = 0; i < 5; i++) {
        cout << *films[i] << endl;
    }

    cout << "The winner is " << *pwin << endl;
}

class A : public std::enable_shared_from_this<A> {
public:
    A() { cout << "A::A() constructor" << endl; }
    ~A() { cout << "A::~A() destructor" << endl; }

    std::shared_ptr<A> GetSelf() {
        return shared_from_this();
    }
};

void test_reset() {
    int *p = new int(1);
    std::shared_ptr<int> pInt = nullptr;
    pInt.reset(p);

    printf("i = %d\n", *pInt);
}

int main() {
    test_unique();
    test_shared();

    std::shared_ptr<A> pA(new A);
    std::shared_ptr<A> pB = pA->GetSelf();
    std::shared_ptr<A> pC = std::make_shared<A>();

    test_reset();

    return 0;
}

