#include<iostream>
using namespace std;

#define tab "\t"
#define delimiter "--------------------------------------------------------"
class List
{
	class Element
	{
		int Data;
		Element* pNext;
		Element* pPrev;
	public:
		Element(int Data, Element* pNext = nullptr, Element* pPrev = nullptr)
		{
			this->Data = Data;
			this->pNext = pNext;
			this->pPrev = pPrev;
			cout << "EConstructor:\t" << this << endl;
		}
		~Element()
		{
			cout << "EDestructor:\t" << this << endl;
		}
		friend class List;
	}*Head,*Tail;

	class Iterator 
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

	unsigned int size;
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

	List()
	{
		Head = Tail = nullptr;
		size = 0;
		cout << "LConstructor:\t" << this << endl;
	}
	List(const initializer_list<int>& il) : List()
	{
		
		for (int const* it = il.begin(); it != il.end(); it++)
		{
			push_back(*it);
		}
	}
	~List()
	{
		while (Head)
		{
			pop_front();
		}
		cout << "LDestructor:\t" << this << endl;
	}
	//////////////////////   Adding elements  ////////////////////////////
	void push_front(int Data)
	{
		if (Head == nullptr && Tail == nullptr)
		{
			Head = Tail = new Element(Data);
			size++;
			return;
		}
		Element* New = new Element(Data);
		New->pNext = Head;
		Head->pPrev = New;
		Head = New;
		size++;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		Element* Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		Element* New = new Element(Data);
		Temp->pNext = New;
		New->pPrev = Temp;
		size++;

	}
	void insert(int index, int Data)
	{
		if (index > size-1) return;
		if (index == 0)
		{
			push_front(Data);
			return;
		}
		if (index == size-1)
		{
			push_back(Data);
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index-1; i++)
		{
			Temp=Temp->pNext;
		}
		Element* New = new Element(Data);
		
		New->pNext = Temp->pNext;
		New->pPrev = Temp;
		Temp->pNext = New;
		size++;
	}

	/////////////////////    Erasing elements  /////////////////////////

	void pop_front()
	{
		Element* to_del = Head;
		Head = Head->pNext;
		Tail = nullptr;
		delete to_del;
		size--;
	}
	void pop_back()
	{
		Element* Temp = Head;
		while (Temp->pNext->pNext)
		{
			Temp = Temp->pNext;
		}
		delete Temp->pNext;
		Temp->pNext = nullptr;
		size--;
	}
	void erase(int index)
	{
		if (index > size-1) return;
		if (index == 0)
		{
			pop_front();
			return;
		}
		if (index == size-1)
		{
			pop_back();
			return;
		}
		Element* Temp = Head;
		for (int i = 0; i < index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		Element* to_del= Temp->pNext;
		Temp->pNext = Temp->pNext->pNext;
		Temp->pNext->pPrev = Temp;
		delete to_del;
		size--;
	}

	////////////////////     Methods  ///////////////////////////////

	void print()
	{
		for (Element* Temp = Head; Temp; Temp = Temp->pNext)
			cout << Temp << tab << Temp->pPrev << tab << Temp->Data << tab << Temp->pNext << endl;
}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	int n;
	cout << "Введите размер списка: "; cin >> n;
	List list;
	for (int i = 0; i < n; i++)
	{
		list.push_front(rand() % 100);
		
	}
	list.print();
	cout << delimiter << endl;

	list.push_back(10000);
	list.print();
	cout << delimiter << endl;


	list.pop_front();
	list.print();
	cout << delimiter<< endl;

	list.pop_back();
	list.print();
	cout << delimiter << endl;

	int index;
	int Data;
	cout << "Введите индекс добавляемого элемента: "; cin >> index;
	cout << "Введите значение добавляемого элемента: "; cin >> Data;
	list.insert(index, Data);
	list.print();
	cout << delimiter << endl;
	
	cout << "Введите индекс удаляемого элемента: "; cin >> index;
	list.erase(index);
	list.print();
	cout << delimiter << endl;

	List list1 = { 3,5,8,13,21 };
	for (int i : list1)
		cout << i << tab;
	cout << endl;
	cout << delimiter << endl;

}