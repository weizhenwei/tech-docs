#include <string>
#include <iostream>

int main(void) {
    std::string str1 = R"(Hello, world!)";
    std::string str2 = R"test(Hello, c++11!)test";

    std::cout << str1 << std::endl;
    std::cout << str2 << std::endl;

    std::string str3 = R"html(
        <HTML>
        <HEAD>
        <TITLE> This is a test </TITLE>
        </HEAD>

        <BODY>
        <P>Hello, C++ 11 world! </P>
        </BODY>
        </HTML>
        )html";
    std::cout << str3 << std::endl;

    return 0;
}

