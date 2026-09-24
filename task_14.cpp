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
        }
        else if (s[start] != ' ' && s[end] == ' ')
        {
            end--;
        }
        else if (s[start] == ' ' && s[end] == ' ')
        {
            start++;
            end--;
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

void str_reverse_word(char *s, int start, int end)
{
    if (str_len(s) <= 1)
    {
        return;
    }
    while (start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
        start++;
        end--;
    }
}
void str_reverse_words(char *s)
{
    if (str_len(s) <= 1)
    {
        return;
    }
    str_reverse_word(s, 0, str_len(s) - 1);

    int word_start = 0;
    for (int i = 0; i <= str_len(s); i++)
    {
        if (s[i] == ' ' || s[i] == '\0')
        {
            str_reverse_word(s, word_start, i - 1);
            word_start = i + 1;
        }
    }
}

int main()
{
    std::cout << "test_7" << '\n';
    char *s = new char[20];
    str_copy(s, "   hello    ");
    char *res = str_trim(s);
    str_print(res);
    std::cout << str_len(res) << '\n';
    std::cout << "test_8" << '\n';
    char new_s[] = "one two three";
    str_reverse_words(new_s);
    str_print(new_s);
    delete[] s;
    delete[] res;
    return 0;
}