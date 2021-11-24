#include <iostream>

using namespace std;

template<class T>
class List
{
    struct Node
    {
        T value;
        Node* prev;
        Node* next;
        Node(T newValue, Node* newPrev = nullptr, Node* newNext = nullptr)
                       : value(newValue), prev(newPrev), next(newNext) {};
         
    };
    // Поля
    Node* headPtr;
    Node* tailPtr; 
    int listSize;
public:
    // Default constructor
    List() : headPtr(nullptr), tailPtr(nullptr), listSize(0) {}
    // Default destructor
    ~List() { clear(); }
    // Add new element to the list
    void push_back(const T valueToAdd)
    {
        if (headPtr == nullptr)
        {
            headPtr = new Node(valueToAdd); 
            tailPtr = headPtr; 
        }
        else
        {
            Node* currentPtr = headPtr; // проход по списку начинается с головы
            while (currentPtr != tailPtr) // пока не нашли последний элемент
                currentPtr = currentPtr->next; // переключение указателя на следующий элемент
            currentPtr->next = new Node(valueToAdd, tailPtr, headPtr); // добавление нового элемента
            tailPtr = currentPtr->next; // присвоение нового конца списка
            headPtr->prev = tailPtr;
        }
        listSize++;
    }
    // Add new element before the first one
    void push_front(const T valueToAdd)
    {
        if (headPtr == nullptr)
        {
            headPtr = new Node(valueToAdd);
            tailPtr = headPtr;
        }
        else
        {
            Node* headTaker = headPtr;
            headPtr = new Node(valueToAdd, tailPtr, headTaker);
            tailPtr->next = headPtr;
        }
        listSize++;
    }
    // Delete last added element
    void pop_back()  
    {
        if (headPtr == tailPtr)
            headPtr = nullptr;
        else
        {
            Node* tailTaker = tailPtr;
            tailPtr = tailPtr->prev;
            tailPtr->next = headPtr;
            delete tailTaker;
        }
        listSize--;
    }
    // Delete first element
    void pop_front()
    {
        Node* headTaker = headPtr;
        headPtr = headPtr->next;
        // Связь начала и конца списка
        headPtr->prev = tailPtr;
        tailPtr->next = headPtr;
        delete headTaker;
        listSize--;
    }
    // Delete everything from the list
    void clear()
    {
        if (headPtr == nullptr)
            return;
        pop_back();
        clear();
    }
    // Get or change value of the first element
    T& front() const
    {
        return headPtr->value;
    }
    // Get or change value of the last element
    T& back() const
    {
        return headPtr->value;
    }
    // Get the size of current list
    int size() const
    {
        return this->listSize;
    }

    class iterator
    {
    private:

        Node* currentPtr;
    public:
        iterator(Node* newCurrentPtr) : currentPtr(newCurrentPtr) {};
        T& operator * ()
        {
            return currentPtr->value;
        }
        T* operator -> ()
        {
            return currentPtr;
        }
        // Префиксное добавление 1 
        iterator& operator ++ ()
        {
            currentPtr = currentPtr->next;
            return *this;
        }
        // Постфиксное добавление 1
        iterator& operator ++ (int)
        {
            iterator taker = currentPtr;
            currentPtr = currentPtr->next;
            return taker;
        }
        
        friend bool operator == (const iterator& firstIterator, const iterator& secondIterator)
        {
            return firstIterator.currnetPtr == secondIterator.currnetPtr;
        }
        friend bool operator != (const iterator& firstIterator, const iterator& secondIterator)
        {
            return firstIterator.currentPtr != secondIterator.currentPtr;
        }
    };
    // Add after an existing element
    /*
    void insert(const iterator addAfter, const T valueToAdd)
    {
        Node* ptrTaker = addAfter.currentPtr;
        Node* newNode = new Node(valueToAdd, ptrTaker, ptrTaker->next);
        newNode->next->prev = newNode;
    }
    */
    // Merge a list to the current one
    void merge(const List<T>& listToCopy)
    {
        auto copyIterator = listToCopy.begin(); // уставновка итератора на начало списка
        while (copyIterator != listToCopy.end()) 
        {
            push_back(*copyIterator++); // добавление значения, на которое указывает итератор
        }
    }

    iterator begin() const
    {
        return iterator(headPtr);
    }
    iterator end() const
    {
        return iterator(tailPtr);
    }
};
