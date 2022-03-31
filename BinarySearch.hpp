// Алгоритм бинарного поиска единицы данных численного типа в массиве
// return: Индекс элемента поиска; -1 в случае отсутствия такого элемента
template <typename T>
int binary_search(vector<T> numsSet, T targetNumber)
{
    int left = 0, right = numsSet.size() - 1;
    while (left <= right)
    {
        // Исключения 
        if (numsSet[left] == targetNumber)
            return left;
        if (numsSet[right] == targetNumber)
            return right;
        // Точка разделения массива на две половины
        int step = left + (right - left) / 2;
        if(numsSet[step] == targetNumber) // нашли нужный номер
            return step;
        if(numsSet[step] > targetNumber) // элемент по индексу step больше, чем элемент поиска
            left = step + 1;
        else
            right = step - 1;
    }
    // элемент найден не был 
    return -1;
}
