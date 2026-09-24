#include <iostream>
#include <cstring>
std::size_t str_len(const char *s)
{
    std::size_t len_s = 0;
    while (s[len_s] != '\0')
    {
        len_s++;
    }
    return len_s;
}
void str_copy(char *dst, const char *src)
{
    while (*src != '\0')
    {
        *dst = *src;
        src++;
        dst++;
    }
    *dst = '\0';
}
void str_delete(char *&s)
{
    delete[] s;
    s = nullptr;
}
void str_print(const char *s)
{
    std::cout << s << '\n';
}

char *str_alloc(const char *src)
{
    std::size_t len_res = str_len(src);
    char *res = new char[len_res + 1];
    str_copy(res, src);
    return res;
}

int main()
{
    char *s = new char[12];
    str_copy(s, "hello world");
    std::cout << "test_1" << "\n";
    const std::size_t len_s = str_len(s);
    std::cout << len_s << "\n";
    std::cout << "test_2" << "\n";
    char *d = new char[len_s + 1];
    str_copy(d, s);
    std::cout << d << '\n';
    std::cout << "test_3" << "\n";
    char new_s[] = "hello user";
    const std::size_t len_new_s = str_len(new_s);
    char *new_d = new char[len_new_s + 1];
    str_copy(new_d, new_s);
    std::cout << new_d << '\n';
    std::cout << "test_4" << "\n";
    str_delete(s);
    std::cout << (s == nullptr ? "deleted" : "not deleted") << '\n';
    std::cout << "test_5" << "\n";
    str_print(new_s);
    std::cout << "test_6" << "\n";
    char *alloc_s = str_alloc("hello everyone");
    str_print(alloc_s);
    delete[] new_d;
    delete[] d;
    delete[] alloc_s;
    return 0;
}
