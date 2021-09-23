#include <string>

double cutter(double number, int symbsCount)
{
    std::string taker = "", str = std::to_string(number);
    int counter = 0;
    for (int i = 0; i < str.size(); i++)
    {
        taker += str[i];
        if (str[i] == '.')
        {
            for (int j = i + 1; j < i + 1 + symbsCount; j++)
            {
                if (str.size() - counter < j)
                    break;
                taker += str[j];
            }
            break;
        }
        counter++;
    }
    number = std::atof(taker.c_str());
    return number;
}
