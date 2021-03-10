#include "fun.h"
#include <iostream>
#include <cctype>
#include <vector>
std::vector<std::pair<const char*, const char*>> split(const char* str, char sep = ' ') 
{
    bool on_word = false;
    const char* StrStart = nullptr;
    const char* StrEnd = nullptr;
    std::vector<std::pair<const char*, const char*>> result;
    int i = 0;
    for (; str[i] != '\0'; i++) 
    {
        if (str[i] != sep && !on_word) 
        {
            on_word = true;
            StrStart = str + i;
        }
        else if (str[i] == sep && on_word) 
        {
            on_word = false;
            StrEnd = str + i;
            result.emplace_back(StrStart, str + i);
            StrStart = StrEnd = nullptr;
        }
        else 
        {
            continue;
        }
    }

    if (StrStart != nullptr && StrEnd == nullptr) 
    {
        result.emplace_back(StrStart, str + i);
    }
    return result;
}

unsigned int faStr1(const char* str) 
{
    auto words = split(str);
    int result = 0;
    auto process_word = [&result](const char* begin, const char* end) 
    {
        for (; begin != end; begin++) 
        {
            if (std::isdigit(*begin)) 
            {
                return;
            }
        }
        result++;
    };
    for (auto word : words) 
    {
        process_word(word.first, word.second);
    }
    return result;
}

unsigned int faStr2(const char* str) 
{
    auto words = split(str);
    int result = 0;
    auto process_word = [&result](const char* begin, const char* end) 
    {
        if (!std::isupper(*(begin++))) 
        {
            return;
        }
        for (; begin != end; begin++) 
        {
            if (!std::islower(*begin)) 
            {
                return;
            }
        }
        result++;
    };
    for (auto word : words) 
    {
        process_word(word.first, word.second);
    }
    return result;
}

unsigned int faStr3(const char* str) 
{
    auto words = split(str);
    int result = 0;
    auto process_word = [&result](const char* begin, const char* end) 
    {
        result += end - begin;
    };
    for (auto word : words) 
    {
        process_word(word.first, word.second);
    }
    return words.size() ? (result / (float)words.size() + 0.5) : 0;
}
