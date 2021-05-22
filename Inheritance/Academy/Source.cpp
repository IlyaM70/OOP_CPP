#include<iostream>
using namespace std;

class Human
{
	string last_name;
	string first_name;
	unsigned int age;

public:
	const string& get_last_name() const
	{
		return last_name;
	}
	const string& get_first_name() const
	{
		return first_name;
	}
	unsigned int get_age() const
	{
		return age;
	}
	void set_last_name(const string& last_name)
	{
		this->last_name = last_name;
	}
	void set_first_name(const string& first_name)
	{
		this->first_name = first_name;
	}
	void set_age(unsigned int age)
	{
		this->age = age;
	}
	// constructors

	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "Hconstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//Methods

	void info()
	{
		cout << last_name << " " << first_name << " " << age << " "<<"лет" << endl;
	}
};
class Student : public Human
{
	string speciality;
	string group;
	double rating;
public:
	const string& get_speciality()const
	{
		return speciality;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	// constructors

	Student(const string& last_name, const string& first_name, unsigned int age, //human parameters
		const string& speciality, const string& group, double rating) //student parameters
		:Human(last_name,first_name,age)
	{
		this->speciality = speciality;
		this->group = group;
		this->rating = rating;
		cout << "Sconstructor:\t" << this << endl;

	}
	~Student()
	{
		cout << "SDesctuctor:\t" << this << endl;
	}
	//methods
	void info()
	{
		Human::info();
		cout << "Специальность\t" << speciality << "\t группа\t" << group << "\t успеваемость\t" << rating << endl;
	}
};

class Graduate :public Student
{
	string diploma_theme;
public:
	const string& get_diploma_theme() const
	{
		return diploma_theme;

	}
	Graduate(const string& last_name, const string& first_name, unsigned int age, 
		const string& speciality, const string& group, double rating,
		const string& diploma_theme)
		:Student (last_name, first_name, age,
			speciality, group, rating)
	{
		this->diploma_theme = diploma_theme;
		cout << "GConstructor\t" << endl;
	}
	~Graduate()
	{
		cout << "GDestructor\t" << endl;
	}
	//Methods 
	void info()
	{
		Student::info();
		cout << "Тема дилома\t" << diploma_theme << endl;
	}
		

};
void main()

{
	setlocale(LC_ALL, "");
	Human human("Тупенко", "Василий", 18);
	human.info();
	Student Ivan("Остроумный", "Иван",19, "Китайская философия", "OST_01",4.9);
	Ivan.info();

	Graduate jessi("Pinkman", "Jessi", 25, "Meth", "WithWalter", 4.5, "Meth");
	jessi.info();

}