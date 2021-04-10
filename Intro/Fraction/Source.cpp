#include<iostream>

using namespace std;

class Fraction
{
	int num; //numerator
	int den; //denominator
	int int_part; //integer part

public:

	// get/set
	int get_num() const
	{
		return num;
	}
	int get_den() const
	{
		return den;
	}
	int get_int_part()const
	{
		return int_part;
	}
	void set_num(int num)
	{
		this->num = num;
	}
	void set_den(int den)
	{
		this->den = den;
	}
	void set_int_part(int int_part)
	{
		this->int_part = int_part;
	}

	// constructors

	Fraction(int num = 0, int den = 0, int int_part=0)
	{
		this->num = num;
		this->den = den;
		this->int_part = int_part;
		//cout << "Consctructor\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->num = other.num;
		this->den = other.den;
		this->int_part = other.int_part;
		//cout << "CopyConstructor\t" << this << endl;
	}
	~Fraction()
	{
		//cout << "Destcructor\t" << this << endl;
	}

	// operators

	Fraction& operator=(const Fraction& other)
	{
		this->num = other.num;
		this->den = other.den;
		this->int_part = other.int_part;
		//cout << "CopyAssignment\t" << this << endl;
		return *this;
	}
	Fraction& operator+=(const Fraction& other)
	{
		this->set_num(this->num + other.num);
		this->set_den(this->den + other.den);
		this->set_int_part(this->int_part + other.int_part);
		return *this;
	}
	Fraction& operator-=(const Fraction& other)
	{
		this->set_num(this->num - other.num);
		this->set_den(this->den - other.den);
		this->set_int_part(this->int_part + other.int_part);
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		this->set_num(this->num * other.num);
		this->set_den(this->den * other.den);
		this->set_int_part(this->int_part * other.int_part);
		return *this;
	}
	Fraction& operator/=(const Fraction& other)
	{
		this->set_num(this->num / other.num);
		this->set_den(this->den / other.den);
		if(other.int_part!=0) this->set_int_part(this->int_part / other.int_part);
		return *this;
	}
	// Increment/Decrement
	Fraction& operator++() //prefix increment
	{
		this->num++;
		this->den++;
		this->int_part++;
		return *this;
	}
	Fraction operator++(int) //Postfix increment
	{
		Fraction old = *this;
		this->num++;
		this->den++;
		this->int_part++;
		return old;
	}

	Fraction& operator--() //prefix decrement
	{
		this->num--;
		this->den--;
		this->int_part--;
		return *this;
	}
	Fraction operator--(int) //Postfix decrement
	{
		Fraction old = *this;
		this->num--;
		this->den--;
		this->int_part--;
		return old;
	}

	//methods

	void print()const
	{
		if (int_part == 0)cout << num << "/" << den << endl;
		else cout << int_part << "(" << num << "/" << den << ")" << endl;
	}
	void to_proper()
	{
		int_part = num / den;
		num = num % den;
		
	}
	void to_improper()
	{
		num = int_part * den + num;
		int_part = 0;
	}
	void reduce()
	{
		if (den % num == 0) 
		{ 
			den = den / num;
			num = num / num;

		}

	}

};

//functions

Fraction operator+(const Fraction& left, const Fraction& right);
Fraction operator-( Fraction left,  Fraction right);
Fraction operator*( Fraction left,  Fraction right);
Fraction operator/( Fraction left, Fraction right);

ostream& operator<<(ostream& os, const Fraction& obj);
istream& operator>>(istream& is, Fraction& obj);


bool operator==(const Fraction& left, const Fraction& right);
bool operator!=(const Fraction& left, const Fraction& right);
bool operator>(const Fraction& left, const Fraction& right);
bool operator<(const Fraction& left, const Fraction& right);
bool operator>=(const Fraction& left, const Fraction& right);
bool operator<=(const Fraction& left, const Fraction& right);

void main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Fraction:" << endl;
	Fraction A(12, 5);
	A.print();

	cout << "To proper:" << endl;
	A.to_proper();
	A.print();

	cout << "To improper:" << endl;
	A.to_improper();
	A.print();

	cout << "Reduce:" << endl;
	Fraction B(5,15);
	B.print();
	B.reduce();
	B.print();

	cout << "Operator '=' " << endl;
	A.print();
	 A = B;
	A.print();

	cout << "Operator '+' " << endl;
	Fraction C = A + B;
	C.print();

	cout << "Operator '-' " << endl;
	Fraction D(4, 5);
	Fraction E(2, 3);
	Fraction F = D - E;
	F.print();

	cout << "Operator '*' " << endl;
	F = D * E;
	F.print();

	cout << "Operator '/' " << endl;
	F = D / E;
	F.print();

	
	cout << "Operator '+=' " << endl;
	F +=D ;
	F.print();

	cout << "Operator '-=' " << endl;
	F -= D;
	F.print();

	cout << "Operator '*=' " << endl;
	F *= D;
	F.print();

	cout << "Operator '/=' " << endl;
	F /= D;
	F.print();

	F.to_proper();
	cout << "Increment " << endl;
	F++;
	F.print();

	cout << "Decrement " << endl;
	F--;
	F.print();

	cout << "Введите числитель, знаменатель и целую часть(0 если отсутвует) "; 
	cin >> F;
	cout << F<<endl;
	
	cout << "Operator =="<<endl;
	cout << (F == D) << endl;

	cout << "Operator !=" << endl;
	cout << (F != D) << endl;

	cout << "Operator >" << endl;
	cout << (F > D) << endl;

	cout << "Operator <" << endl;
	cout << (F < D) << endl;

	cout << "Operator >=" << endl;
	cout << (F >= D) << endl;

	cout << "Operator <=" << endl;
	cout << (F <= D) << endl;
}


Fraction operator+(const Fraction& left, const Fraction& right)
{
	Fraction result;
	result.set_num(left.get_num() * right.get_den() + right.get_num() * left.get_den());
	result.set_den(left.get_den() * right.get_den());
	result.set_int_part(left.get_int_part() + right.get_int_part());
	return result;
}
Fraction operator-( Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_num(left.get_num() * right.get_den() - right.get_num() * left.get_den());
	result.set_den(left.get_den() * right.get_den());
	result.to_improper();
	return result;
}
Fraction operator*( Fraction left,  Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_num(left.get_num() * right.get_num());
	result.set_den(left.get_den() * right.get_den());
	result.to_improper();
	return result;
}
Fraction operator/(Fraction left, Fraction right)
{
	left.to_proper();
	right.to_proper();
	Fraction result;
	result.set_num(left.get_num() *  right.get_den());
	result.set_den(left.get_den() *right.get_num());
	result.to_improper();
	return result;
}
ostream& operator<<(ostream& os, const Fraction& obj)
{
	if(obj.get_int_part()!=0) os << obj.get_int_part() <<"("<< obj.get_num() << "\\" << obj.get_den()<<")";
	else os << obj.get_num() << "\\" << obj.get_den();
		return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	int num, den, int_part;
	is >> num >> den>>int_part;
	obj.set_num(num);
	obj.set_den(den);
	obj.set_int_part(int_part);
	return is;
}


bool operator==(const Fraction& left, const Fraction& right)
{
	
	return left.get_num() == right.get_num() && left.get_den() == right.get_den() && left.get_int_part() == right.get_int_part();
}
bool operator !=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
bool operator >(const Fraction& left, const Fraction& right)
{
	return left.get_num() > right.get_num() && left.get_den() > right.get_den() && left.get_int_part() >right.get_int_part();
}
bool operator <(const Fraction& left, const Fraction& right)
{
	return!(left > right);
}
bool operator >=(const Fraction& left, const Fraction& right)
{
	return left.get_num() >= right.get_num() && left.get_den() >=right.get_den() && left.get_int_part() >= right.get_int_part();
}
bool operator <=(const Fraction& left, const Fraction& right)
{
	return!(left >= right);
}