#include <iostream> 

using namespace std;

template<class T>
class Stack
{
    // струтура узла отвечает за создание узлов, то есть элементов стека
    struct Node
    {
        T value;     // основные данные 
        Node* previousPtr; // указатель на следующий элемент

        // конструктор создания нового узла
        Node(T newValue) : value(newValue) {}
        // конструктор создания узла и передачи ему текущего указателя
        Node(T newValue, Node* currentNode) : value(newValue), previousPtr(currentNode) {}
    };
    
    void delete_current_node()
    {
        // сохранение текущего верхнего узла во избежание потери памяти
        Node* taker = topElement;
        // передача указателя на верхний элемент предыдущему элементу
        topElement = topElement->previousPtr;
        delete taker;
        // уменьшение размера стека
        currentSize--;
    }

    //поля
    Node* topElement; // верхний элемент структуры
    int currentSize;  // текущий размер стека 
public:
    // конструктор по умолчанию; в нём инициализируются переменные
    Stack() : topElement(nullptr), currentSize(0) {}
    // деструктор по умолчанию
    ~Stack() { erase(); }
    // метод для добавления нового элемента 
    void push(const T valueToAdd)
    {
        // если в списке ещё нет элементов, создаём новый узел, в обратном случае узел создаётся с передачей указателя
        topElement == nullptr ? topElement = new Node(valueToAdd) : topElement = new Node(valueToAdd, topElement);
        // увеличение текущего размера
        currentSize++;
    }  
    // метод для удаления всего содержимого текущего стека
    void erase()
    {
        if (currentSize == 1)
        {
            topElement = nullptr;
            return;
        }
        // удаление текущего верхнего узла
        delete_current_node();
        // рекурсивный вызов функции для удаления узлов
        erase();
    }

    // метод для удаления верхнего элемента стека
    void pop()
    {
        if (isEmpty()) // если стек пуст, выдаёт ошибку
            throw out_of_range("Error. Current stack is empty"); // throw ошибка_выхода_из_приложения ("текст ошибки");
        // удаление текущего верхнего узла
        delete_current_node();
    }
    // метод для получения верхнего значения в стеке
    T& top()
    {
        if (isEmpty()) // если стек пуст, выдаёт ошибку
            throw out_of_range("Error. Current stack is empty");
        // так как topElement является указателем, его нужно разыменовать при помощи &
        return topElement->value; 
    }
    // метод для возвращения текущего размера стека
    int size()
    {
        return currentSize;
    }
    // метод для проверки на наличие элементов в стеке
    bool isEmpty()
    {
        return topElement == nullptr;
    }
};
