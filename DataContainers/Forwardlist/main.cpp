#include<iostream>
using namespace std;

#define tab "\t"

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
};

int Element::count = 0;

class ForwardList
{
	Element* Head; //адрес начального элемента
public:
	ForwardList()
	{
		Head = nullptr;//если голова указываетна 0, то список пуст
		cout << "LConstructor:\t" << this << endl;
	}
	
	ForwardList(const ForwardList& other)
	{
		Head = nullptr;
		Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}
		cout << "CopyConstructor" << this << endl;
	}
	 ForwardList(const ForwardList&& other)
	{
		Head = other.Head;
		/*Element* Temp = other.Head;
		while (Temp)
		{
			push_back(Temp->Data);
			Temp = Temp->pNext;
		}*/
		cout << "MoveConstructor" << this << endl;
	}
	 
	
	~ForwardList()
	{
		Element* Temp = Head;
		while (Temp->pNext)
		{
			pop_front();
		}
		cout << "LDestructor:\t" << this << endl;
	}

	//                 Adding elements:

	void push_front(int Data)
	{
		//1) создаем новый элемент
		Element* New = new Element(Data);
		//2) привязываем новый элемент к списку
		New->pNext = Head;
		//3) говорим, что новый элемент будет начальным элементом списка
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		// 1) создаем новый элемент
		Element* New = new Element(Data);
		//2) Доходим до конца списка
		Element * Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		//3)прикрепляем новый элемент к последнему
			Temp->pNext = New;
	}
	void insert(int Index, int Data)
	{
		if (Index == 0)
		{
			push_front(Data);
			return;
		}
		if (Index > Element::count)return;
		//1) создаем новый элемент
		Element* New = new Element(Data);
		// 2) доходим до нужного элемента
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) вставляем новый элемент на нужную позицию
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}

	//               Methods

	void print()
	{
		Element* Temp = Head; // итератор 
		                     // указатель с помощью которого
		                     //можно получить доступ к элементам 
		                     //структуры данных
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // переход на следующий элемент
		}
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
	}
	void erase(int Index)
	{
	
		if (Index > Element::count)return;
		if (Index == 0)
		{
			pop_front();
			return;
		}
		if (Index == Element::count)
		{
			pop_back();
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
	}

	
	
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n; // Размер списка
	cout << "Введите количество элементов списка "; cin >> n;
	ForwardList list;
	for (int i = 0; i < n; i++)
	{
		list.push_back(rand() % 100);
	}
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
	list.print();
	ForwardList list2 = list;
	list2.print();*/

	/*int index;
	cout << "Введите индекс удаляемого элемента "; cin >> index;
	list.erase(index);
	list.print();*/

	

}