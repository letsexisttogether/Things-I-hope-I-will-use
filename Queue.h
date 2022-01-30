#include <iostream>

template <class T>
class Queue
{
private:
    T* generalArray;
    int count;

public:
    // default constructor
    Queue() : generalArray(nullptr), count(0) { };
    // copy constructor
    Queue(const Queue& newQueue)
    {
        count = newQueue.count();
        generalArray = new T[count];
        
        for (size_t i = 0; i < count; i++)
            generalArray[i] = newQueue.generalArray[i];
    }
    // add new value to the end of the queue
    void push(T value) 
    {
        T* taker = generalArray;
        generalArray = new T[count + 1];
        for (size_t i = 0; i < count; i++)
            generalArray[i] = taker[i];
        delete[] taker;
        generalArray[count] = value;
        ++count;
    }
    void pop()
    {
        T* taker = generalArray;
        generalArray = new T[count - 1];
        for (size_t i = 0; i < count - 1; i++)
            generalArray[i] = taker[i];
        delete[] taker;
        --count;
    }
    T first() const noexcept
    {
        return generalArray[0];
    }
    T back() const noexcept
    {
        return generalArray[count - 1];
    }
    ~Queue()
    {
        if (count)
        {
            count = 0;
            delete[] generalArray;
        }
    }
    bool empty() const noexcept
    {
        return count == 0;
    }
    int size() const noexcept
    {
        return count;
    }
    void swap(Queue& secondQueue) noexcept
    {
        T* taker = new T[count];
        for (size_t i = 0; i < count; i++)
            taker[i] = generalArray[i];
        //
        int prevCount = count;
        count = secondQueue.count;
        generalArray = new T[count];
        for (size_t i = 0; i < count; i++)
            generalArray[i] = secondQueue.generalArray[i];
        //
        secondQueue.count = prevCount;
        secondQueue.generalArray = new T[prevCount];
        for (size_t i = 0; i < prevCount; i++)
            secondQueue.generalArray[i] = taker[i];
        delete[] taker;
    }
};
