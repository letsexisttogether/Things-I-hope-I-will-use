#include <iostream>

namespace fold
{
    // Сумма
    template <typename ... sType>
    auto Sum(sType ... values)
    {
        return (values + ... + 0);
    }

    // Умножение
    template <typename ... mType>
    auto Multi(mType ... values)
    {
        return (1 * ... * values);
    }
    
    // Вычитание чисел, начиная слева
    template <typename ... dType>
    auto Deduction(dType ... values)
    {
        return (0 - ... - values);
    }

    // Логическое &&
    // возврещает true, если нет параметров
    template <typename ... aType>
    bool logAnd(aType ... expressions)
    {
        return (expressions && ...);
    }

    // Логическое ||
    // возвращает false, если нет параметров
    template <typename ... rType>
    bool logOrr(rType ... expressions)
    {
        return (expressions || ...);
    }
}
