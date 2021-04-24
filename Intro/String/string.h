#pragma once
#include<iostream>
using namespace std;
#define delimiter "-----------------------------------------"
/////////////////////////////////////////////////////////////////
/// //////////////////  CLASS DECLARATION  //////////////////////////
class String;
String operator+(const String& left, const String& right);
ostream& operator << (ostream& os, const String& obj);
bool operator==(const String& left, const String& right);
bool operator!=(const String& left, const String& right);
class String
{
	int size; //размер строки в байтах
	char* str; //указатель на строку 

public:

	//get/set methods:
	int get_size()const;
	const char* get_str()const;
	char* get_str();

	//constructors:
	explicit String(int size = 80);
	String(const char str[]);
	String(const String& other);
	String(String&& other);
	~String();
	//operators
	String& operator=(const String& other);
	String& operator=(String&& other);

	String& operator+= (const String& other);

	// Methods
	void print()const;
};
//////////////////////////////////   CLASS DECLARATION END   /////////////////////
///////////////////////////////////////////////////////////////////////////////