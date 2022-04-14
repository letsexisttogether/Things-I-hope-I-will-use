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
        return (... - values);
    }
}
