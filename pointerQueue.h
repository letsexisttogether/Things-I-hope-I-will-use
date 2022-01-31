#include <iostream>

template <class T>
class PointerQueue
{
private:
    struct Node
    {
        T value;
        Node* queueNext;
        Node(T newVal = 0, Node* newNext = nullptr) : value(newVal), queueNext(newNext) { }

        void operator = (const Node& secondNode)
        {
            value = secondNode.value;
            queueNext = secondNode.queueNext;
        }
    };

    int count;
    Node* currentFirst;

public:
    PointerQueue() noexcept
    {
        count = 0;
        currentFirst = nullptr;
    }
    
    // Добавление нового элемента в конец очереди
    void push(T value) 
    {
        if (!currentFirst)
            currentFirst = new Node(value);
        else
        {
            Node* taker = currentFirst;
            while (taker->queueNext != nullptr)
            {
                taker = taker->queueNext;
            }
            taker->queueNext = new Node(value);
        }

        ++count;
    }
    // Удаление текущего главного элемента
    void pop()
    {
        Node* taker = currentFirst;
        currentFirst = currentFirst->queueNext;
        delete[] taker;

        --count;
    }
    // Возвращает текущее количество элементов в очереди
    int size() const
    {
        return count;
    }

    // Возвращает изменяемое значение первого элемента в очереди
    const T& front() const
    {
        return currentFirst->value; 
    }

    const T& back() const
    {
        Node* taker = currentFirst;
        while (taker->queueNext)
            taker = taker->queueNext;
        return taker->value;
    }

    ~PointerQueue()
    {
        count = 0;
        while (currentFirst != nullptr)
            pop();
    }
};
