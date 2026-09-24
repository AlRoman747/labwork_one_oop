#include <iostream>
#include <cstring>
#include "str_ops.h"

char *str_trim(const char *s)
{
    if (str_len(s) == 0)
    {
        return nullptr;
    }
    int start = 0;
    int end = str_len(s) - 1;
    while (s[start] == ' ' || s[end] == ' ')
    {
        if (s[start] == ' ' && s[end] != ' ')
        {
            start++;
            std::cout << start << " " << end << '\n';
        }
        else if (s[start] != ' ' && s[end] == ' ')
        {
            end--;
            std::cout << start << " " << end << '\n';
        }
        else if (s[start] == ' ' && s[end] == ' ')
        {
            start++;
            end--;
            std::cout << start << " " << end << '\n';
        }
    }
    int res_len = end - start + 1;
    char *res = new char[res_len];
    for (int i = 0; i < (res_len); i++)
    {
        res[i] = s[start];
        start++;
    }
    res[res_len] = '\0';
    return res;
}

void str_reverse_words(char *s)
{
    //
}

int main()
{
    std::cout << "test_7" << '\n';
    char *s = new char[20];
    str_copy(s, "   hello    ");
    char *res = str_trim(s);
    str_print(res);
    std::cout << str_len(res) << '\n';
    return 0;
}