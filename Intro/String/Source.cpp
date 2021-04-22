#include<iostream>
using namespace std;

#define delimiter "-----------------------------------------"
class String;
String operator+(const String& left, const String& right);

class String
{
	int size; //размер строки в байтах
	char* str; //указатель на строку 

public:

	//get/set methods:
	int get_size()const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
	 char* get_str()
	{
		return str;
	}

	//constructors:
	explicit String(int size=80)
	{
		this->size = size;
		this->str = new char[size] {};
		cout <<(size==80 ? "Default": "Size")<<"Constructor: \t" << this << endl;
	}
	String(const char str[])
	{
		this->size = strlen(str) + 1;// с учетом нуля
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = str[i];
		cout << "Constructor:\t\t" << this << endl;
	}
	String(const String& other)
	{
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
			cout << "CopyConstructor:\t" << this << endl;
	}
	String(String&& other)
	{
		this->size = other.size;
		this->str = other.str;
		other.str = nullptr;//указатель на ноль (NULL pointer) - указатель в никуда
		cout << "MoveConstructor:\t" << this << endl;
	}
	~String()
	{
		delete[] this->str;
	cout << "Destructor:\t\t" << this << endl;
	}
	//operators
	String& operator=(const String& other)
		
	{
		if (this == &other)return *this;
		delete[]this->str;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)
			this->str[i] = other.str[i];
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	String& operator+= (const String& other)
	{
		return *this = *this + other;
	}

	// Methods
	void print()const
	{
		cout << "size:\t" << size << endl;
		cout << "str:\t" << str << endl;
	}
};

ostream& operator << (ostream & os, const String & obj)
{
	return os << obj.get_str();
}
String operator+(const String& left, const String& right)
{
	String result(left.get_size() + right.get_size() - 1);
	for (int i = 0; i < left.get_size(); i++)
		result.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		result.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return result;
}






//#define CONSTRUCTORS_CHECK
//#define ASSIGNMEND_CHECK


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef CONSTRUCTORS_CHECK
	String str; //default constructor
	str.print();

	String str1 = "Hello"; // single argument constructor
	str1.print();
	cout << str1 << endl;
	String str2 = str1; // copy constructor
	cout << str2 << endl;

	str = str2; //copy assignment
	cout << str << endl;
#endif // CONSTRUCTORS_CHECK
	
	
#ifdef ASSIGNMENT_CHECK
	String str1 = "Hello";
	String str2;
	str1 = str1;
	str1.print();
	cout << "str1: " << str1 << endl;
	cout << "str2: " << str2 << endl;
#endif // ASSIGNMENT_CHECK

	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2; // operator + будет выполнять конкатенацию (слияние) строк
	cout << delimiter << endl;
	cout << str3 << endl;
	
	
	/*cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;*/
	
	
	

}