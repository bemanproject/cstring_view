#include <beman/cstring_view/cstring_view.hpp>

#include <iostream>
#include <string>
#include <string_view>
#include <print>

using namespace std::literals;

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
    }
}

int main() {
    std::string s = "hello world";
    std::cstring_view z0 = "hello";
    std::cstring_view z1 = s;
    std::cstring_view empty;
    std::println("{}", z0);
    std::println("{}", s.starts_with(z0));
    std::println("{}", z0.starts_with(s));
    std::println("{}", z0.starts_with("hello"));
    std::println("{}", z0.starts_with("hello"csv));
    std::println("{}", std::hash<std::cstring_view>{}(z1));
    std::cout<<z1<<std::endl;
    std::println("{}", "hello"csv == "hello"sv);
    std::println("{}", "hello"csv == "hello"csv);
    std::println("{}", "hello"csv != "goodbye"sv);
    std::println("{}", "hello"csv != "goodbye"csv);
    std::println("{}", z0 == z1);
    std::println("{}", to_string(z0 <=> z1));
    std::println("{}", z0[z0.size()] * 1);
    std::println("{}", z0.c_str());
    std::println("\"{}\"", empty);
    std::println("{}", empty == ""csv);
    std::formatter<std::string_view> f;
    
    std::wstring ws = L"hello world";
    std::wcstring_view wz0 = L"hello";
    std::wcstring_view wz1 = ws;
    std::wcstring_view wempty;
    std::wcout << std::format(L"{}\n", wz0);
    std::println("{}", ws.starts_with(wz0));
    std::println("{}", wz0.starts_with(ws));
    std::println("{}", wz0.starts_with(L"hello"));
    std::println("{}", wz0.starts_with(L"hello"csv));
    std::println("{}", std::hash<std::wcstring_view>{}(wz1));
    std::wcout<<wz1<<std::endl;
    std::println("{}", L"hello"csv == L"hello"sv);
    std::println("{}", L"hello"csv == L"hello"csv);
    std::println("{}", L"hello"csv != L"goodbye"sv);
    std::println("{}", L"hello"csv != L"goodbye"csv);
    std::println("{}", wz0 == wz1);
    std::println("{}", to_string(wz0 <=> wz1));
    std::println("{}", wz0[wz0.size()] * 1);
    std::wcout << std::format(L"{}\n", wz0.c_str());
    std::wcout << std::format(L"\"{}\"\n", wempty);
    std::println("{}", wempty == L""csv);
    std::formatter<std::wstring_view, wchar_t> wf;
}
