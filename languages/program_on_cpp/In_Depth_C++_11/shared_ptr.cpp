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

int main() {
    test_unique();
    test_shared();

    return 0;
}


