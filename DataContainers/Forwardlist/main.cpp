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
		this->Data = Data; //�������� ��������
		this->pNext = pNext;// ��������� �� ��������� �������
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
	Element* Head; //����� ���������� ��������
public:
	ForwardList()
	{
		Head = nullptr;//���� ������ ����������� 0, �� ������ ����
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
	~ForwardList()
	{
		cout << "LDestructor:\t" << this << endl;
	}

	//                 Adding elements:

	void push_front(int Data)
	{
		//1) ������� ����� �������
		Element* New = new Element(Data);
		//2) ����������� ����� ������� � ������
		New->pNext = Head;
		//3) �������, ��� ����� ������� ����� ��������� ��������� ������
		Head = New;
	}
	void push_back(int Data)
	{
		if (Head == nullptr)
		{
			push_front(Data);
			return;
		}
		// 1) ������� ����� �������
		Element* New = new Element(Data);
		//2) ������� �� ����� ������
		Element * Temp = Head;
		while (Temp->pNext)
		{
			Temp = Temp->pNext;
		}
		//3)����������� ����� ������� � ����������
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
		//1) ������� ����� �������
		Element* New = new Element(Data);
		// 2) ������� �� ������� ��������
		Element* Temp = Head;
		for (int i = 0; i < Index - 1; i++)
		{
			Temp = Temp->pNext;
		}
		//3) ��������� ����� ������� �� ������ �������
		New->pNext = Temp->pNext;
		Temp->pNext = New;
	}

	//               Methods

	void print()
	{
		Element* Temp = Head; // �������� 
		                     // ��������� � ������� ��������
		                     //����� �������� ������ � ��������� 
		                     //��������� ������
		while (Temp)
		{
			cout << Temp << tab << Temp->Data << tab << Temp->pNext << endl;
			Temp = Temp->pNext; // ������� �� ��������� �������
		}
	}
	

		//             Errasing elements

	void pop_front()
	{
		//1) ���������� ������ ���������� ��������
		Element* to_del = Head;
		// 2) ��������� ��������� ������� �� ������
		Head = Head->pNext;
		//3) ������� ������� � ������
		delete to_del;
	}
	void pop_back()
	{
		//1) ������� �� �������������� ��������
		Element* Temp = Head;
		while (Temp->pNext->pNext)
			Temp = Temp->pNext;
		//2) ������� ��������� ������� �� ������
		delete Temp->pNext;
		//3) �������� ��������� �� ��������� �������
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
	int n; // ������ ������
	cout << "������� ���������� ��������� ������ "; cin >> n;
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
	cout << "������� ������ ������������ �������� "; cin >> index;
	cout << "������� �������� ������������ �������� "; cin >> value;
	list.insert(index, value);
	list.print();
	ForwardList list2 = list;
	list2.print();*/
	int index;
	cout << "������� ������ ���������� �������� "; cin >> index;
	list.erase(index);
	list.print();
}