#include <string>

bool isPal(std::string str, int i = 0)
{
    if (i == str.size()) return true;
    if (str[i] != str[str.size() - i - 1])
        return false;
    return isPal(str, ++i);
}
