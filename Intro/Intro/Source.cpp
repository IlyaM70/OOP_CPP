#include<iostream>

using namespace std;

#define tab "\t"

class Point  // тип данных Point
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

	Point& operator=(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CopyAssignment: " << this << endl;
		return *this;
	}
	Point& operator+=(const Point& other)
	{
		/*this->x += other.x;
		this->y += other.y;*/
		this->set_x(this->x + other.x);
		this->set_y(this->y + other.y);
		return *this;
	}
	// Increment/Decrement
	Point& operator++() //prefix increment
	{
		this->x++;
		this->y++;
		return *this;
	}
	Point operator++(int) //Postfix increment
	{
		Point old = *this;
		this->x++;
		this->y++;
		return old;
	}


	Point& operator()(double x, double y)
	{
		set_x(x);
		set_y(y);
		return *this;
	}

	//methods

	void print()const
	{
		cout << "X=" << x << tab << "Y=" << y << endl;
	}
	double distance(const Point& other)
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(pow(x_distance, 2) + pow(y_distance, 2));
			return distance;
	}
};

// структура - это тип данных
// класс - это тип данных


//#define STRUCT
//#define CONSTRUCT
//#define DISTANCE
//#define ASSIGNMENT_CHECK
//#define STREAMS

//function declarations

double distance(Point A, Point B);

Point operator+(const Point& left, const Point& right);

ostream& operator<<(ostream& os, const Point& obj);
istream& operator>>(istream& is, Point& obj);

bool operator==(const Point& left, const Point& right);
bool operator !=(const Point& left, const Point& right);


void main()
{
	setlocale(LC_ALL, "Russian");
#ifdef STRUCT
	// type name;
	int a; // объявляем переменную а типа int
	Point A; // объявляем переменную А типа Point
			 // объявляем объект стркутуры Point
			 // создаем экземпляр струкртруы Point

	A.x = 2;
	A.y = 3;
	cout << A.x << tab << A.y << endl;

	Point* pA = &A; // создаем указатель на Point
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

#ifdef DISTANCE
	Point A(2.5, 3.5);
	cout << "точка А" << endl;
	A.print();
	cout << "Расстояние до точки " << A.distance(0) << endl;

	Point B(2, 3);
	cout << "точка B" << endl;
	B.print();
	cout << "Расстояние между точками " << distance(A, B) << endl;
#endif // DISTANCE

#ifdef ASSIGNMENT_CHECK
	int a, b, c;
	a = b = c = 0;

	Point A, B, C;
	A = B = C = Point(2, 3);
	A.print();
	B.print();
	C.print();
#endif // ASSIGNMENT_CHECK
	
#ifdef STREAMS
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	Point B(3, 4);
	//Point C = A + B;
	//C.print();
	//A += B;
	//A.print();
	//A++;
	//A.print();  



	cout << A << endl;
	cout << B << endl;
	cout << "Введите координаты точки "; cin >> A;
	cout << "Вы ввели " << A << endl;
#endif // STREAMS

	Point A(2, 3);
	Point B(3, 4);
	/*if (A == B)
	{
		cout << "Точки равны" << endl;
	}
	else
	{
		cout << "Точки разные" << endl;
	}*/
	//cout << (A == B) << endl;
	cout << (A != B) << endl;

	cout << A << endl;
	/*A.set_x(33);
	A.set_y(44);*/
	A(33, 44);
	cout << A << endl;





}

double distance(Point A, Point B)
{
	double distance = sqrt(pow((A.get_x() - B.get_x()), 2) + pow((A.get_y() - B.get_y()), 2));

	return distance;
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
ostream& operator<<(ostream& os, const Point& obj)
{
	os << "X= " << obj.get_x() << tab << "Y= " << obj.get_y();
	return os;
}
istream& operator>>(istream& is,  Point& obj)
{
	double x, y;
	is >> x >> y;
	obj.set_x(x);
	obj.set_y(y);
	return is;
}

bool operator==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();
}
bool operator !=(const Point& left, const Point& right)
{
	return!(left == right);
}