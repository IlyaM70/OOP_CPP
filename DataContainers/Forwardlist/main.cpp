#include<iostream>

using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "---------------------------------------"
class ForwardList;
ForwardList operator+(const ForwardList& left, const ForwardList& right);


class Element
{
	int Data;
	Element* pNext;
	static int count;
public:
	Element(int Data, Element* pNext = nullptr)
	{
		count++;
		this->Data = Data; //значение элемента
		this->pNext = pNext;// указатель на следующий элемент
		cout << "EConstructor:\t" << this << endl;
	}
	~Element()
	{
		count--;
		cout << "EDestructor:\t" << this << endl;
	}
	friend class ForwardList;
	friend ForwardList operator+(const ForwardList& left, const ForwardList& right);
	friend class Iterator;
};

int Element::count = 0;
class Iterator // этот класс обварачивает указатель на Element, что позволяет нам перегружать операции для указателя на Element
{
	Element* Temp;
public:
	Iterator(Element* Temp = nullptr)
	{
		this->Temp = Temp;
		cout << "ITConstructor:\t" << this << endl;
	}
	~Iterator()
	{
		cout << "ITDestructor:\t" << this << endl;
	}
	Iterator& operator++()  // Prefix increment
	{
		Temp = Temp->pNext;
		return*this;
	}
	Iterator& operator++(int)  // postfix increment
	{
		Iterator old = *this;
		Temp = Temp->pNext;
		return old;
	}
	bool operator==(const Iterator& other) const
	{
		return this->Temp == other.Temp;
	}
	bool operator!=(const Iterator& other) const
	{
		return this->Temp != other.Temp;
	}
	const int& operator*() const
	{
		return Temp->Data;
	}
	int& operator*()
	{
		return Temp->Data;
	}
};

class ForwardList
{
	Element* Head; //адрес начального элемента
	unsigned int size; // содержит размер списка
public:

	 Element* getHead() const
	{
		return Head;
	}
	 Iterator begin()
	 {
		 return Head;
	 }
	 const Iterator begin() const
	 {
		 return Head;
	 }
	 Iterator end()
	 {
		 return nullptr;
	 }
	 const Iterator end() const
	 {
		 return nullptr;
	 }
	 
	
	ForwardList()
	{
		Head = nullptr;//если голова указываетна 0, то список пуст
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	ForwardList(const initializer_list<int>& il) : ForwardList()
	{
		cout << typeid(il.begin()).name() << endl; // typeid определяет тип значения
		for (int const* it = il.begin(); it!= il.end(); it++)
		{
			push_back(*it);
		}
	}
	ForwardList(const ForwardList& other)
	{
		Head = nullptr;
		size = 0;
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "CopyConstructor" << this << endl;
	}
	 ForwardList( ForwardList&& other) noexcept
	{
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;
		
		cout << "MoveConstructor" << this << endl;
	}
	 
	
	~ForwardList()
	{
		/*Element* Temp = Head;
		while (Temp->pNext)
		{
			pop_front();
		}*/
		while (Head)
		{
			pop_front();
		}
		cout << "LDestructor:\t" << this << endl;
	}



	//                 Operators

	ForwardList& operator=(const ForwardList& other)
	{
		if (this == &other)return *this;
		while (Head) pop_front();
		Element* Temp = other.Head; // iterator
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "CopyAssignment" << this << endl;
		return *this;
	}
	ForwardList& operator=(ForwardList&& other) noexcept
	{
		while (Head)pop_front();
		this->Head = other.Head;
		this->size = other.size;
		other.Head = nullptr;

		cout << "MoveAssignment" << this << endl;
		return *this;
	}
	

	//                 Adding elements:

	void push_front(int Data)
	{
		////1) создаем новый элемент
		//Element* New = new Element(Data);
		////2) привязываем новый элемент к списку
		//New->pNext = Head;
		////3) говорим, что новый элемент будет начальным элементом списка
		//Head = New;
		Head = new Element(Data, Head);
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		//// 1) создаем новый элемент
		//Element* New = new Element(Data);
		////2) Доходим до конца списка
		//Element * Temp = Head;
		//while (Temp->pNext)
		//{
		//	Temp = Temp->pNext;
		//}
		////3)прикрепляем новый элемент к последнему
		//	Temp->pNext = New;
		//	size++;
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data);
		size++;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index == size)
		{
			push_back(Data);
			return;
		}
		if (Index > size)return;

		////1) создаем новый элемент
		//Element* New = new Element(Data);
		//// 2) доходим до нужного элемента
		//Element* Temp = Head;
		//for (int i = 0; i < Index - 1; i++)
		//{
		//	Temp = Temp->pNext;
		//}
		////3) вставляем новый элемент на нужную позицию
		//New->pNext = Temp->pNext;
		//Temp->pNext = New;
		//size++;

		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Temp->pNext = new Element(Data,Temp->pNext);
		size++;
	}

	//               Methods

	void print()
	{
		//Element* Temp = Head; // итератор 
		//                     // указатель с помощью которого
		//                     //можно получить доступ к элементам 
		//                     //структуры данных
		//while (Temp)
		//{
		//	cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		//	Temp = Temp->pNext; // переход на следующий элемент
		//}
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
		cout << "Количество элементов списка " << size << endl;
		cout << "Общее количество элементов  " << Element::count << endl;
	}
	

		//             Errasing elements

	void pop_front()
	{
		//1) запоминаем адресс удаляемого элемента
		Element* to_del = Head;
		// 2) исключаем удаляемый элемент из списка
		Head = Head->pNext;
		//3) удаляем элемент и памяти
		delete to_del;
		size--;
	}
	void pop_back()
	{
		//1) доходим до предпоследнего элемента
		Element* Temp = Head;
		while (Temp->pNext->pNext)
			Temp = Temp->pNext;
		//2) удаляем последний элемент из памяти
		delete Temp->pNext;
		//3) зануляем указатель на последний элемент
		Temp->pNext=nullptr;
		size--;
	}
	void erase(int Index)
	{
	
		if (Index > size)return;
		if (Index == 0)
		{
			pop_front();
			size--;
			return;
		}
		if (Index == size)
		{
			pop_back();
			size--;
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < Index-1; i++)
		{
			
			 Temp = Temp->pNext;
		}
		Element* buffer = Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		delete buffer;
		size--;
	}

	
	
	
	
};


ForwardList operator+(const ForwardList& left, const ForwardList& right)
{
	ForwardList cat = left; // CopyConstructor
	/*for (Element* Temp = right.getHead(); Temp; Temp = Temp->pNext)
		cat.push_back(Temp->Data);*/
	for (Iterator it = right.begin(); it != right.end(); it++)
		cat.push_back(*it);
	return cat;
}
#define BASE_CHECK
//#define COPY_METHODS
//#define OPERATOR_PLUS_CHECK
//#define RANGE_BASED_ARRAY
#define RANGE_BASED_LIST
void main()
{
	setlocale(LC_ALL, "Russian");

#if COPY_METHODS
	int n; // Размер списка
	cout << "Введите количество элементов списка "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
	list = list;
	list.print();
	/*list.push_back(123);
	list.print();
	list.pop_front();
	list.print();
	int index;
	int value;
	cout << "Введите индекс добавляемого элемента "; cin >> index;
	cout << "Введите значение добавляемого элемента "; cin >> value;
	list.insert(index, value);
	list.print();*/


	/*int index;
	cout << "Введите индекс удаляемого элемента "; cin >> index;
	list.erase(index);
	list.print();*/

	ForwardList list2 = list; //CopyConstructor
	list2.print();


	ForwardList list3; //CopyAssignment
	list3 = list2;
	list3.print();

	ForwardList list4;
	list4 = list2 + list3;
	list4.print();
#endif // COPY_METHODS

#ifdef OPERATOR_PLUS_CHECK
	ForwardList list1 = { 3,5,8,13,21 };
	/*list1.push_back(3);
	list1.push_back(5);
	list1.push_back(5);
	list1.push_back(13);
	list1.push_back(21);*/
	cout << delimiter << endl;
	ForwardList list2 = { 34,55,89 };
	/*list1.push_back(34);
	list1.push_back(55);
	list1.push_back(89);*/
	cout << delimiter << endl;
	//ForwardList list3 = list1 + list2; // MoveConstructor
	ForwardList list3; // MoveAssignment
	list3 = list1 + list2;
	cout << delimiter << endl;
	list3.print();
#endif // OPERATOR_PLUS_CHECK

#ifdef RANGE_BASED_ARRAY
	int arr[] = { 3,5,8,13,21 };
	for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
	{
		cout << arr[i] << tab;
	}
	cout << endl;
	
	// Range-based for - Цикл for для контейнера(аналог foreach)
	for (int i : arr)
	{
		cout << i << tab;
	}
	cout << endl;

#endif // RANGE_BASED_ARRAY


#ifdef RANGE_BASED_LIST
	ForwardList list = { 3,5,8,13,21 };

	for (int i : list)
	{
		cout << i << tab;
	}
	cout << endl;

	for (Iterator it = list.begin(); it != list.end(); it++) //  it != list.end() неявное преобразование nullptr  в iterator и создается временный безымянный объект
	{
		cout << *it << tab;

	}
	cout << endl;
#endif // RANGE_BASED_LIST

	
	
	
}