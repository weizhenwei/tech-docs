#include <iostream>
#include <string>

int main() {
    double df = 1.5324;
    std::string strdf = std::to_string(df);
    std::cout << strdf << std::endl;

    // wchar;
    double wdf = 1.5324;
    std::wstring wstrdf = std::to_wstring(wdf);
    std::wcout << wstrdf << std::endl;

    std::wstring zstr = L"中国人";
    std::wcout << zstr << std::endl;

    return 0;
}

