#include"string.h"



//#define CONSTRUCTORS_CHECK
//#define ASSIGNMEND_CHECK
#define OPERATOR_PLUS_CHECK
//#define MOVE_ASSIGNMENT
//#define MATCHING_OPERATORS
//#define CONSTRUCTORS_CALLING


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

#ifdef OPERATOR_PLUS_CHECK
	String str1 = "Hello";
	String str2 = "World";
	cout << delimiter << endl;
	String str3 = str1 + str2; // operator + будет выполнять конкатенацию (слияние) строк
	cout << delimiter << endl;
	cout << str3 << endl;
	String str4 = str3;
	cout << str4 << endl;


	/*cout << delimiter << endl;
	str1 += str2;
	cout << str1 << endl;*/
#endif // OPERATOR_PLUS_CHECK

#ifdef MOVE_ASSIGNMENT
	String str1 = "Hello";
	cout << "str1 " << str1 << endl;
	String str2;
	str2 = str1;
	cout << "str2 " << str2 << endl;
#endif // MOVE_ASSIGNMENT

#ifdef MATCHING_OPERATORS
	String str1 = "Hello";
	String str2 = "Hello";
	cout << (str1 == str2) << endl;
	cout << (str1 != str2) << endl;
#endif // MATCHING_OPERATORS

#ifdef CONSTRUCTORS_CALLING
	String str; // default constructor
	str.print();
	String str1(5);
	str1.print();
	String str2 = "Hello"; // single-argument constructor
	str2.print();
	String str3("Hello"); // single-argument constructor
	str3.print();

	String str4(); // НЕ конструктор по умолчанию,
				   // объявляется функция str4 которая ничего не принимает и возращает значение типа String
	//str4.
	String str5; // НЕ явный вызов конструктора по умолчанию
	String str6{}; //явный вызов конструктора по умолчанию
	str6.print();

	String("Привет").print(); // явный вызов конструктора для создания временного безымянного объекта  
#endif // CONSTRUCTORS_CALLING

}
