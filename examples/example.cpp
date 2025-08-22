#include <beman/cstring_view/cstring_view.hpp>

#include <iostream>
#include <string>
#include <string_view>

using namespace std::literals;
using namespace beman::literals;

std::string_view to_string(std::strong_ordering order) {
    if (order == std::strong_ordering::equal) {
        return "equal";
    } else if (order == std::strong_ordering::equivalent) {
        return "equivalent";
    } else if (order == std::strong_ordering::less) {
        return "less";
    } else if (order == std::strong_ordering::greater) {
        return "greater";
    } else {
        assert(false);
        return "internal error";
    }
}

int main() {
    std::string         s = "hello world";
    beman::cstring_view z0 = "hello";
    beman::cstring_view z1 = s;
    beman::cstring_view empty;
    std::cout << z0 << "\n";
    std::cout << s.starts_with(z0) << "\n";
    std::cout << z0.starts_with(s) << "\n";
    std::cout << z0.starts_with("hello") << "\n";
    std::cout << z0.starts_with("hello"_csv) << "\n";
    std::cout << std::hash<beman::cstring_view>{}(z1) << "\n";
    std::cout << z1 << std::endl;
    std::cout << ("hello"_csv == "hello"sv) << "\n";
    std::cout << ("hello"_csv == "hello"_csv) << "\n";
    std::cout << ("hello"_csv != "goodbye"sv) << "\n";
    std::cout << ("hello"_csv != "goodbye"_csv) << "\n";
    std::cout << (z0 == z1) << "\n";
    std::cout << to_string(z0 <=> z1) << "\n";
    std::cout << z0[z0.size()] * 1 << "\n";
    std::cout << z0.c_str() << "\n";
    std::cout << "\"" << empty << "\"\n";
    std::cout << (empty == ""_csv) << "\n";

    std::wstring         ws = L"hello world";
    beman::wcstring_view wz0 = L"hello";
    beman::wcstring_view wz1 = ws;
    beman::wcstring_view wempty;
    std::wcout << std::format(L"{}\n", wz0);
    std::cout << ws.starts_with(wz0) << "\n";
    std::cout << wz0.starts_with(ws) << "\n";
    std::cout << wz0.starts_with(L"hello") << "\n";
    std::cout << wz0.starts_with(L"hello"_csv) << "\n";
    std::cout << std::hash<beman::wcstring_view>{}(wz1) << "\n";
    std::wcout << wz1 << std::endl;
    std::cout << (L"hello"_csv == L"hello"sv) << "\n";
    std::cout << (L"hello"_csv == L"hello"_csv) << "\n";
    std::cout << (L"hello"_csv != L"goodbye"sv) << "\n";
    std::cout << (L"hello"_csv != L"goodbye"_csv) << "\n";
    std::cout << (wz0 == wz1) << "\n";
    std::cout << to_string(wz0 <=> wz1) << "\n";
    std::cout << wz0[wz0.size()] * 1 << "\n";
    std::wcout << std::format(L"{}\n", wz0.c_str());
    std::wcout << std::format(L"\"{}\"\n", wempty);
    std::cout << (wempty == L""_csv) << "\n";
}
