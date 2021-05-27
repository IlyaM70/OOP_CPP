#include<iostream>
using namespace std;

class Animal
{
public:
	virtual void sound()=0; // чисто виртуальный метод - pure virtual function(method)
	// этот метод не имеет определения (реализации), но он обязательно должен быть определен
	// в дочернем классе иначе он тоже будет абстрактным
};
class Cat:public Animal
{
public:
	void sound()
	{
		cout << "Mяу" << endl;
	}
};
class Dog :public Animal
{
public:
	void sound()
	{
		cout << "Гав" << endl;
	}
};
class Human :public Animal
{
public:
	void sound()
	{
		cout << "Я 100% человек"<<endl;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	//Animal a;
	//Cat cat;
	Animal* zoo[] =
	{
		new Cat(),
		new Dog(),
		new Cat(),
		new Human(),
		new Cat(),
		new Dog()
	};
	for (int i = 0; i < sizeof(zoo) / sizeof(Animal*); i++)
	{
		zoo[i]->sound();
	}
}