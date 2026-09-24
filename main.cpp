#include <iostream>
#include <cstring>
#include "task_14.h"
#include "str_ops.h"
#include <limits>
#include <cstdlib>

char *string_input()
{

    int cap = 8;
    int size = 0;
    char *buffer = new char[cap];
    char ch;

    while (std::cin.get(ch) && ch != '\n')
    {

        if (size > cap - 1)
        {
            cap *= 2;
            char *new_buffer = new char[cap];
            for (int i = 0; i < size; i++)
            {
                new_buffer[i] = buffer[i];
            }
            delete[] buffer;
            buffer = new_buffer;
        }
        buffer[size] = ch;
        size++;
    }
    buffer[size] = '\0';
    return buffer;
}

int main()
{
    std::system("chcp 65001 > nul");
    char *buffer = nullptr;
    int input;

    while (1)
    {
        std::cout << "Вариант лабораторной №14 (C-строки через указатели char*)" << '\n';
        std::cout << "1. Ввести строку" << '\n';
        std::cout << "2. Напечатать" << '\n';
        std::cout << "3. Длина" << '\n';
        std::cout << "4. Скопировать в буфер и напечатать" << '\n';
        std::cout << "5. Алгоритм варианта №14: char* str_trim(const char* s) — вернуть новую строку без пробельных символов по краям; void str_reverse_words(char* s) — развернуть порядок слов (слова разделены одним пробелом), сами слова не разворачивать." << '\n';
        std::cout << "0. Выход" << '\n';

        if (!(std::cin >> input))
        {
            std::cout << "Ошибка! Вы ввели буквы или спецсимволы. Попробуйте еще раз:" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if (input == 1)
        {
            if (buffer != nullptr)
            {
                str_delete(buffer);
            }
            std::cout << "Введите строку: ";
            std::cin.ignore();
            buffer = string_input();
            std::cout << "Строка успешно сохранена!" << '\n';
            continue;
        }
        else if (input == 2)
        {
            if (buffer == nullptr)
            {
                std::cout << "Чтобы работать со строками, введите её под цифрой 1" << '\n';
                continue;
            }
            str_print(buffer);
            continue;
        }
        else if (input == 3)
        {
            if (buffer == nullptr)
            {
                std::cout << "Чтобы работать со строками, введите её под цифрой 1" << '\n';
                continue;
            }
            std::cout << str_len(buffer) << '\n';
            continue;
        }
        else if (input == 4)
        {
            if (buffer == nullptr)
            {
                std::cout << "Чтобы работать со строками, введите её под цифрой 1" << '\n';
                continue;
            }
            const std::size_t len_buff = str_len(buffer);
            char *new_d = new char[len_buff + 1];
            str_copy(new_d, buffer);
            std::cout << "копия массива и её адрес: " << new_d << " " << (void *)new_d << '\n'
                      << "массив и его адрес: " << buffer << " " << (void *)buffer << '\n';
            delete[] new_d;
        }
        else if (input == 5)
        {
            int new_input;

            std::cout << "Введите вариант задания" << '\n';
            std::cout << "1. Вернуть новую строку без пробельных символов по краям" << '\n';
            std::cout << "2. Развернуть порядок слов" << '\n';

            if (!(std::cin >> new_input))
            {
                std::cout << "Ошибка! Вы ввели буквы или спецсимволы." << '\n';
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (new_input == 1)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Введите строку: ";
                char *new_buffer = string_input();
                char *res = str_trim(new_buffer);
                if (res == nullptr)
                {
                    std::cout << "Ошибка обработки строки\n";
                    continue;
                }
                str_print(res);

                delete[] res;
                delete[] new_buffer;
            }
            else if (new_input == 2)
            {
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                std::cout << "Введите строку: ";
                char *new_buffer = string_input();
                str_reverse_words(new_buffer);
                str_print(new_buffer);

                delete[] new_buffer;
            }
        }
        else if (input == 0)
        {
            std::cout << "Спасибо за использование";
            return 0;
        }
    }
    return 0;
}