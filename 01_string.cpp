#include <iostream>
#include <map>
#include <mutex> // for call_once
#include <numeric>
#include <optional>
#include <string>
#include <utility>
#include <vector>
#include <thread>
#include <algorithm>

// 1. Is Unique
bool isUniqueCharacter(const std::string str)
{
    if (str.length() > 128)
        return false;

    bool charSet[128] = {};
    for (int i = 0; i < str.length(); i++)
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
*/
bool permutation(const std::string first, const std::string second)
{
    if (first.length() != second.length())
        return false;

    for (int i = 0; i < first.length(); i++)
    {
        if (second.find(first.at(i)) == -1)
            return false;
    }

    return true;
}

/* 3. Palindrome Permutation (đối xứng)
    "dog cat" <----->"tac god"
*/
bool isPalindromePermutation(const std::string first, const std::string second)
{
    if (first.length() != second.length())
        return false;

    std::string tmp;
    for (int i = second.length() - 1; i > -1; i--)
    {

        if (first.at(second.length() - i - 1) != second.at(i))
            return false;
    }

    return true;
}

/*
    4. split a string by demiliter

    splitString("one two three", ' ');
*/
std::vector<std::string> splitString(const std::string str, const char delim)
{
    std::vector<std::string> ret;
    std::string tmp = "";
    for (int i = 0; i < str.length(); i++)
    {
        if (str.at(i) == delim)
        {
            ret.push_back(tmp);
            tmp = "";
            continue;
        }
        tmp += str.at(i);
        if (i == str.length() - 1)
            ret.push_back(tmp);
    }

    return ret;
}

/*
    5. Replace

    replaceString("one two three", "two", "aaa");

    Result: "one aaa three"
*/
std::string replaceString(std::string &str, const std::string &from, const std::string &to)
{
    std::string ret;
    std::vector<std::string> v;
    for (int i = 0; i < str.length();)
    {
        bool isFound = false;
        int tmp = 1;
        if (str.at(i) == from.at(0))
        {
            for (int j = 1; j < from.length(); j++)
            {
                if (str.at(i + j) != from.at(j))
                {
                    break;
                }
                tmp++;
                isFound = true;
            }
        }
        if (isFound)
        {
            v.push_back(ret);
            v.push_back(to);
            ret = "";
            i += tmp;
        }
        else
        {
            ret += str.at(i);
            if (i == str.length() - 1)
                v.push_back(ret);
            i++;
        }
    }
    ret = "";
    for (auto i : v)
    {
        ret += i;
    }

    return ret;
}

// 6.
std::string trimLeft(std::string const &buffer, std::string const &tokens)
{
    std::string ret;
    bool isTrim = true;
    for (int i = 0; i < buffer.length(); i++)
    {
        if (std::string(tokens.length(), buffer[i]) == tokens && isTrim)
        {
            continue;
        }
        isTrim = false;
        ret += buffer.at(i);
    }
    return ret;
}

// 7.
std::string trimRight(std::string const &buffer, std::string const &tokens)
{
    std::string ret;
    bool isTrim = true;
    for (int i = buffer.length() - 1; i > -1; i--)
    {
        if (std::string(tokens.length(), buffer[i]) == tokens && isTrim)
        {
            continue;
        }
        isTrim = false;
        ret += buffer.at(i);
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

/*
    8. strim String
    strimString("  one two three  ", " ");

    Result: "onetwothree"
*/

std::string strimString(const std::string &str, std::string const &tokens)
{
    std::string left = trimLeft(str, tokens);
    std::string ret = trimRight(left, tokens);
    return ret;
}

// 9.
std::string baseName(std::string const &path)
{
    std::string ret;
    for (int i = path.length() - 1; i > -1; i--)
    {
        if (std::string(1, path.at(i)) == "/")
        {
            break;
        }
        ret += path.at(i);
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

// 10.
std::string dirName(std::string const &path)
{
    std::string ret;
    bool isLast = true;
    for (int i = path.length() - 1; i > -1; i--)
    {
        // asd/asd/d.c
        if (std::string(1, path.at(i)) == "/" && isLast)
        {
            isLast = false;
            continue;
        }
        if (isLast)
        {
            continue;
        }
        ret += path.at(i);
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

// 11.
std::string getFileExtension(std::string const &path)
{
    std::string ret;
    for (int i = path.length() - 1; i > -1; i--)
    {
        ret += path.at(i);
        if (std::string(1, path.at(i)) == ".")
        {
            break;
        }
    }
    std::reverse(ret.begin(), ret.end());
    return ret;
}

// 12. ASCII: (65-90)+32
std::string toLower(std::string const &str)
{
    std::string ret;
    for (int i = 0; i < str.length(); i++)
    {
        if ((int)str.at(i) > 90 || (int)str.at(i) < 65)
        {
            ret += str.at(i);
            continue;
        }
        ret += std::string(1, char((int)str.at(i) + 32));
    }
    return ret;
}

// 13. ASCII: (97-122)-32
std::string toUpper(std::string const &str)
{
    std::string ret;
    for (int i = 0; i < str.length(); i++)
    {
        if ((int)str.at(i) > 122 || (int)str.at(i) < 97)
        {
            ret += str.at(i);
            continue;
        }
        ret += std::string(1, char((int)str.at(i) - 32));
    }
    return ret;
}

int main()
{
    // std::cout << __LINE__ << " | " << val << std::endl;
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
    // char c = ' ';
    // std::vector<std::string> v = splitString(str_4, c);
    // std::cout << "String: " << str_4 << std::endl;
    // std::cout << "Split string: " << str_4 << std::endl;
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
    // std::string strTrim = " ";
    // std::cout << "String: " << str_6 << std::endl;
    // std::cout << "Trim left: " << trimLeft(str_6, "a") << "." << std::endl;

    // 7.
    std::string strTrim = " ";
    // std::cout << "String: " << str_6 << std::endl;
    // std::cout << "Trim right: " << trimRight(str_6, "a") << "." << std::endl;

    // 8.
    // std::cout << "String: " << str_6 << std::endl;
    // std::cout << "Trim right: " << strimString(str_6, "a") << "." << std::endl;

    // 9.
    std::string path = "qwe/asd/abc.io.txt";
    // std::cout << "File: " << path << std::endl;
    // std::cout << "Basename: " << baseName(path) << std::endl;

    // 10.
    // std::cout << "Dirname: " << dirName(path) << std::endl;

    // 11.
    std::string file = "abc.io.txt";
    // std::cout << "File: " << file << std::endl;
    // std::cout << "File extension: " << getFileExtension(file) << std::endl;

    // 12.
    std::string str_12 = "ASDF_gh!JKL";
    std::cout << "String: " << str_12 << std::endl;
    std::cout << "To lower: " << toLower(str_12) << std::endl;

    // 13.
    std::cout << "To upper: " << toUpper(str_12) << std::endl;

    return 0;
}