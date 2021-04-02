#include<iostream>

using namespace std;

#define tab "\t"

class Point  // ��� ������ Point
{

	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}
	//constructors

	/*Point()
	{
		x = y = 0;
		cout << "Default constructor:\t" << this << endl;
	}
	Point(double x)
	{
		
		this->x = x;
		this->y = 0;
		cout << "Single Argument Constructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constructor:\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyConstructor: " << this << endl;
	}
	~Point()
	{
		cout << "Descructor:\t" << this << endl;
	}

	//Operators

	void operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: " << this << endl;
	}

	//methods

	void print()const
	{
		cout << "X=" << x << tab << "Y=" << y << endl;
	}
	double distance()
	{
		double distance = sqrt(pow(x, 2) + pow(y, 2));
			return distance;
	}
};

// ��������� - ��� ��� ������
// ����� - ��� ��� ������


//#define STRUCT
//#define CONSTRUCT

//functions

double distance(Point A, Point B);


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT
	// type name;
	int a; // ��������� ���������� � ���� int
	Point A; // ��������� ���������� � ���� Point
			 // ��������� ������ ��������� Point
			 // ������� ��������� ���������� Point

	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; // ������� ��������� �� Point
	cout << pA->x << tab << pA->y << endl;
	cout << (*pA).x << tab << (*pA).y << endl;

#endif // STRUCT

#ifdef CONSTRUCT
	Point A; //default constructor
/*A.set_x(2);
A.set_y(3);*/
//cout << A.get_x() << tab << A.get_y() << endl;
	A.print();

	Point B(2, 3);
	B.print();

	Point C = 5; //single argument constructor
	C.print();

	Point D = B; //copy constructor
	D.print();

	Point E; //Default constructor
	E = D; //copy assignment
	E.print();
#endif // CONSTRUCT

	Point A(2.5, 3.5);
	cout << "����� �" << endl;
	A.print();
	cout << "���������� �� ����� "<<A.distance() << endl;

	Point B(2, 3);
	cout << "����� B" << endl;
	B.print();
	cout<< "���������� ����� ������� " << distance(A, B)<<endl;

}

double distance(Point A, Point B)
{
	double distance = sqrt(pow((A.get_x() - B.get_x()), 2) + pow((A.get_y() - B.get_y()), 2));

	return distance;
}