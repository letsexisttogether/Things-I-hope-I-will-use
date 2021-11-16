#include <iostream>

using namespace std;

template <class T>
class List
{
	struct Node
	{
		T value;    // значение узла 
		Node* next; // указатель на следующий элемент

		Node(int newValue, Node* nextPtr = nullptr) : value(newValue), next(nextPtr) {}
	};

	int listSize;     // текущий размер списка 
	Node* headPtr;    // указатель на первый элемент
public:
	// Конструктор по умолчанию
	List() : listSize(0), headPtr(nullptr) {}

	// Метод добавления нового элемента
	void push_front(const T valueToAdd)
	{
		if (headPtr == nullptr) // в списке нет элементов
			headPtr = new Node(valueToAdd); // создание главного элемента списка
		else
		{
			Node* currentPtr = headPtr; // проход по списку начинается с головы 
			while (currentPtr->next != nullptr) // пока не наткнулись на конец списка 
				currentPtr = currentPtr->next;  // переставление текущего указателя на следующий элемент
			currentPtr->next = new Node(valueToAdd); // создание нового узла в списке
		}
		listSize++;
	}
	// Метод для удаления последнего добавленого элемента
	void pop_front()
	{
		Node* currentPtr = headPtr; // проход в списке всегда начинается с самого начала
		while (currentPtr->next->next != nullptr) // пока не нашли предпослений элемент
		{
			currentPtr = currentPtr->next; // переставление текущего указателя на следующий элемент 
		}
		Node* taker = currentPtr->next; // сохранение указатля последнего элемента для избежания потери памяти
		currentPtr->next = nullptr; // зануление указателя на полследний элемент
		delete taker;
		listSize--;
	}
	// Очистить список
	void clear()
	{
		if (headPtr == nullptr)
			return;
		pop_front();
		clear();
	}
	// Получить размер
	int size()
	{
		return listSize;
	}
	// 
	bool empty()
	{
		return headPtr == nullptr;
	}
	// Класс итератор на список
	class iterator
	{
		// Приватный указатель на текущий узел
		Node* current;
	public:
		iterator(Node* newCurrentPtr) :  current(newCurrentPtr) {} //
		// оператор для возвращения значения, на которое ссылается итератор
		T& operator * ()
		{
			return current->value;
		}
		// оператор для возвращения текущего указателя 
		T* operator -> ()
		{
			return current;
		}
		//префиксная операция добавления 1
		iterator& operator ++ ()
		{
			current = current->next;
			return *this;
		}
		//постфиксная операция добавления 1 
		iterator& operator ++ (int)
		{
			iterator taker = current;
			current = current->next;
			return taker;
		}
		// операторы сравнения
		friend bool operator == (iterator& firstList, iterator& secondList)
		{
			return firstList.current == secondList.current; 
		}
		friend bool operator != (iterator& firstList, iterator& secondList)
		{
			return firstList.current != secondList.current;
		}

	};

	// Указатель на первый элемент
	iterator begin()
	{
		return iterator(headPtr);
	}
	// Указатель на последний элемент
	iterator end()
	{
		Node* currentPtr = headPtr;
		while (currentPtr->next != nullptr)
		{
			currentPtr = currentPtr->next;
		}
		return iterator(currentPtr);
	}

};
