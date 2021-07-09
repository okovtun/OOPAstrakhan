﻿#include<iostream>
using namespace std;

/*
TODO:
В класс ForwardList добавить методы:
	void pop_front();
	void pop_back();
	void insert(...);	//Вставляет элемент по указанному индексу
	void erase(...);	//Удавляет элемент по указанному индексу
*/

#define tab "\t"

class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr) :Data(Data), pNext(pNext)
	{
		count++;
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
};
int Element::count = 0;

class ForwardList
{
	Element* Head;
	size_t size;
public:
	ForwardList()	//Default constructor - создает пустой список.
	{
		this->Head = nullptr;	//Если Голова указывает на 0, то список пуст.
		this->size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//			Adding elements:
	void push_front(int Data)
	{
		//Добавление элемента в начало списка:
		
		//1) Создаем элемент:
		Element* New = new Element(Data);

		//2) Прикрепляем новый элемент к списку:
		New->pNext = Head;

		//3) Адрес нового элемента помещаем в голову, 
		Head = New;
		//после чего, новый элемент является начальным элементом списка
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			//ЕСЛИ список пуст, вызываем метод, который умеет добавлять элемент в пустой список.
			return push_front(Data);
			//return;
		}
		//1)Создать новый элемент:
		//Element* New = new Element(Data);
		
		//2)Дойти до конца списка (до последнего элемента):
		Element* Temp = Head;
		while (Temp->pNext)
			Temp = Temp->pNext;	//Переходим на следующий элемент

		//3)В pNext последнего элемента добавить адрес нового элемента:
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int index, int Data)
	{
		if (index > size)return;
		if (index == 0)return push_front(Data);
		//1) Создаем новый элемент:
		Element* New = new Element(Data);
		//2) Доходим до элемента, который находится перед добавляемым элементом:
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
			Temp = Temp->pNext;
		//3) Вставляем новый элемент в список:
		//Temp - Предыдущий элемент, тоносительно того элемента, на место которого нужно сделать вставку.
		//Temp->pNext - элемент, на место которого мы вставляет новый элемент.
		//Temp->pNext и все последующие элементы будут сдвинуты на 1 позицию вправо.
		New->pNext = Temp->pNext;
		Temp->pNext = New;
		size++;
	}

	//			Removing elements:
	void pop_front()
	{
		//1) Запоминаем адрес удаляемого элемента:
		Element* Temp = Head;

		//2) Смещаем Голову на следубщий элемент списка:
		Head = Head->pNext;

		//3) Удаляем элемент из памяти:
		delete Temp;
		size--;
	}
	void pop_back()
	{
		//1) Доходим до предпоследнего элемента:
		Element* Temp = Head;
		while (Temp->pNext->pNext)
			Temp = Temp->pNext;
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}

	//			Methods:
	void print()const
	{
		Element* Temp = Head;	//Temp - это итератор.
		//Итератор - это указатель, при помощи которого можно получить доступ к элементам структуры данных.
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext;	//Переход на следующий элемент.
		}
		cout << "Количество элементов списка: " << size << endl;
		cout << "Общее количество элементов:  " << Element::count << endl;
	}
};

//#define BASE_CHECK	//Almost DONE
//#define SIZE_CONSTRUCTOR_AND_SUBSCRIPT
//#define COPY_METHODS
//#define HARDCORE

void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef BASE_CHECK
	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		//list.push_front(rand() % 100);
		list.push_back(rand() % 100);
	}
	list.push_back(123);
	list.print();
	list.pop_front();
	list.pop_back();
	list.print();

	int index;
	int value;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> value;
	list.insert(index, value);
	list.print();

	ForwardList list2;
	list2.push_back(1024);
	list2.push_back(2048);
	list2.push_back(3072);
	list2.print();
#endif // BASE_CHECK

#ifdef SIZE_CONSTRUCTOR_AND_SUBSCRIPT
	int n; cout << "Введите размер списка: "; cin >> n;
	ForwardList list(n);	//Создается список на n элементов
	for (int i = 0; i < list.get_size(); i++)cout << list[i] << tab;
	for (int i = 0; i < list.get_size(); i++)list[i]=rand()%100;
	for (int i = 0; i < list.get_size(); i++)cout << list[i] << tab;
#endif // SIZE_CONSTRUCTOR_AND_SUBSCRIPT

#ifdef COPY_METHODS
	ForwardList list;
	list.push_back(3);
	list.push_back(5);
	list.push_back(8);
	list.push_back(13);
	list.push_back(21);
	//list.print();

	ForwardList list2 = list;
	list2.print();

	ForwardList list3;
	list3 = list2;
	list3.print();
#endif // COPY_METHODS

#ifdef HARDCORE
	ForwardList list = { 3, 5, 8, 13, 21 };
	for (int i : list)
		cout << i << tab;
	cout << endl;
#endif // INIT_LIST_LIKE_ARRAY

}