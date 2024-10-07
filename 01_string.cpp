#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>
#include <cctype>

#define MAX_ASCII_NUM 128

// 1. Is Unique
bool isUniqueCharacter(const std::string &str)
{
    auto len = str.length();
    if (len > MAX_ASCII_NUM)
        return false;

    bool charSet[MAX_ASCII_NUM] = {}; // dynamic programing

    for (int i = 0; i < len; i++)
    {
        int val = (int)str.at(i);
        if (charSet[val])
        {
            return false;
        }
        charSet[val] = true;
    }

    return true;
}

/* 2. Permutation (hoán vị)
    "dog", "god", "dgo"

    'aabbcc'
    'aaabbc'
*/
bool permutation(std::string &first, std::string &second)
{
    // 1. check len
    if (first.empty() || first.length() != second.length())
        return false;
    // 2. sort
    std::sort(first.begin(), first.end());
    std::sort(second.begin(), second.end());

    // 3.
    if (first != second)
        return false;

    return true;
}

/* 3. Palindrome Permutation (đối xứng)
    "dog cat" <----->"tac god"
*/
bool isPalindromePermutation(const std::string &first, const std::string &second)
{
    if (first.empty() || first.length() != second.length())
        return false;

    int len = second.length();
    for (int i = 0; i < len; i++)
    {
        if (second.at(i) != first.at(len - i - 1))
            return false;
    }

    return true;
}

/*
    4. split a string by delimiter

    splitString("one two three", ' ');
*/
std::vector<std::string> splitString(std::string &str, const std::string &delimiter)
{
    std::vector<std::string> ret;
    std::size_t pos = str.find(delimiter);
    while (pos != std::string::npos)
    {
        ret.push_back(str.substr(0, pos));
        str.erase(0, pos + delimiter.length());
        pos = str.find(delimiter);
    }
    ret.push_back(str);

    return ret;
}

/*
    5. Replace

    replaceString("one two three", "two", "aaa");

    Result: "one aaa three"
*/
std::string replaceString(std::string &str, const std::string &from, const std::string &to)
{
    // find from
    std::string ss;
    auto pos = str.find(from);
    while (pos != std::string::npos)
    {
        ss += str.substr(0, pos) + to;

        str.erase(0, pos + from.length());
        pos = str.find(from);
    }

    ss += str;

    return ss;
}

// 6.
std::string trimLeft(const std::string &buffer, const std::string &token)
{
    // abcdef
    std::string ret = buffer;
    auto pos = buffer.find(token);
    int tokenLen = token.length();
    while (pos == 0)
    {
        ret.erase(0, tokenLen);
        pos = ret.find(token);
    }
    return ret;
}

// 7.
std::string trimRight(const std::string &buffer, const std::string &token)
{
    std::string ret = buffer;
    auto pos = buffer.find_last_of(token);
    int tokenLen = token.length();
    int bufferLen = buffer.length();
    while (pos == ret.length() - tokenLen)
    {
        ret.erase(pos, tokenLen);
        pos = ret.find_last_of(token);
    }
    return ret;
}

/*
    8. strim String
    strimString("  one two three  ", " ");

    Result: "one two three"
*/

std::string strimString(const std::string &str, const std::string &tokens)
{
    std::string left = trimLeft(str, tokens);
    std::string ret = trimRight(left, tokens);
    return ret;
}

//  asd/asd/aaa/d.c
// 9.
std::string baseName(const std::string &path)
{
    std::string ret = path;
    auto pos = path.find_last_of("/");
    ret = path.substr(pos + 1, std::string::npos);

    return ret;
}

// 10.
std::string dirName(const std::string &path)
{
    std::string ret;
    auto pos = path.find_last_of("/");
    ret = path.substr(0, pos);

    return ret;
}

// 11.
std::string getFileExtension(const std::string &path)
{
    // aac.add.c
    std::string getBaseName = baseName(path);
    auto pos = getBaseName.find_last_of(".");
    std::string ret;
    ret = getBaseName.substr(pos + 1, std::string::npos);

    return ret;
}

// 12.
std::string toLower(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return std::tolower(c); });
    return str;
}

// 13. ASCII:
std::string toUpper(std::string &str)
{
    std::transform(str.begin(), str.end(), str.begin(),
                   [](unsigned char c)
                   { return std::toupper(c); });
    return str;
}

int main()
{
    // 1.
    std::string str_1 = "zxcvbnm";
    // bool check = isUniqueCharacter(str_1);
    // std::cout << "String 1: " << str_1 << std::endl;
    // std::cout << "Check unique str: " << check << std::endl;

    // 2.
    std::string str_2 = "mnbvcxz";
    // std::cout << "String 1: " << str_1 << std::endl;
    // std::cout << "String 2: " << str_2 << std::endl;
    // std::cout << "Permutation: " << permutation(str_1, str_2) << std::endl;

    // 3.
    // std::cout << "String 1: " << str_1 << std::endl;
    // std::cout << "String 2: " << str_2 << std::endl;
    // std::cout << "Palindrome permutation: " << isPalindromePermutation(str_1, str_2) << std::endl;

    // 4.
    std::string str_4 = "asd qwe dfg vbn dfg lkj";
    // std::string c = " ";
    // std::cout << "String: " << str_4 << std::endl;
    // std::vector<std::string> v = splitString(str_4, c);
    // for (auto i : v)
    // {
    //     std::cout << i << std::endl;
    // }

    // 5.
    std::string str_5_f = "dfg";
    std::string str_5_t = "zxc";
    // std::cout << "String: " << str_4 << std::endl;
    // std::cout << "Replace: " << str_5_f << " - To: " << str_5_t << std::endl;
    // std::cout << "Result: " << replaceString(str_4, str_5_f, str_5_t) << std::endl;

    // 6.
    std::string str_6 = "aaaabasdaaaa";
    std::string strTrim = "a";
    // std::cout << "String: " << str_6 << std::endl;
    // std::cout << "Trim left: " << trimLeft(str_6, strTrim) << "." << std::endl;

    // 7.
    // std::cout << "String: " << str_6 << std::endl;
    // std::cout << "Trim right: " << trimRight(str_6, strTrim) << "." << std::endl;

    // 8.
    // std::cout << "String: " << str_6 << std::endl;
    // std::cout << "Trim: " << strimString(str_6, "a") << "." << std::endl;

    // 9.
    std::string path = "/qwe/asd/abc.io.txt";
    // std::cout << "File: " << path << std::endl;
    // std::cout << "Basename: " << baseName(path) << std::endl;

    // 10.
    // std::cout << "Dirname: " << dirName(path) << std::endl;

    // 11.
    // std::cout << "File extension: " << getFileExtension(path) << std::endl;

    // 12.
    std::string str_12 = "ASDF_gh!JKL";
    std::cout << "String: " << str_12 << std::endl;
    std::cout << "To lower: " << toLower(str_12) << std::endl;

    // 13.
    std::cout << "To upper: " << toUpper(str_12) << std::endl;

    return 0;
}