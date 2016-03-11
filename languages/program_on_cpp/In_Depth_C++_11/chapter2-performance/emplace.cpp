/*
 * test c++11 emplace method;
 * Author: weizhenwei
 */

#include <vector>
#include <map>
#include <string>
#include <iostream>

struct Complicated {
    int year;
    double country;
    std::string name;

    Complicated(int a, double b, std::string c) : year(a), country(b), name(c) {
        std::cout << "is constructed" << std::endl;
    }

    Complicated(const Complicated& other) : year(other.year),
    country(other.country), name(std::move(other.name)) {
        std::cout << "is copy constructed" << std::endl;
    }
};

int main() {
    std::map<int, Complicated> m;
    int anInt = 4;
    double aDouble = 0.5;
    std::string aString = "C++";

    std::cout << "--Insert--" << std::endl;
    m.insert(std::make_pair(4, Complicated(anInt, aDouble, aString)));
    std::cout << "--Emplace--" << std::endl;
    m.emplace(4, Complicated(anInt, aDouble, aString));

    std::cout << "--emplace_back--" << std::endl;
    std::vector<Complicated> v;
    v.emplace_back(anInt, aDouble, aString);
    std::cout << "--push_back--" << std::endl;
    v.push_back(Complicated(anInt, aDouble, aString));

    std::cout << "--copy constructor--" << std::endl;
    Complicated c(5, 5.5, "C++ 11");
    v.emplace_back(c);

    return 0;
}

