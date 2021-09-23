#include <string>

double cutter(double number, int symbsCount)
{
    std::string taker = "", str = std::to_string(number);
    for (int i = 0; i < str.size(); i++)
    {
        taker += str[i];
        if (str[i] == '.')
        {
            if (symbsCount > str.size() - i - 1)
                return number;
            for (int j = i + 1; j < i + 1 + symbsCount; j++)
                taker += str[j];
            return std::atof(taker.c_str());
        }
    }
}
