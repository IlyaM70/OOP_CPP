#include<iostream>
#include<regex>
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
	virtual ~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//Methods

	virtual void info()
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
class Teacher:public Human
{

	string speciality;
	int experience;
public:
	const string& get_speciality() const
	{
		return speciality;
	}
	const int& get_experience() const
	{
		return experience;
	}
	Teacher(const string& last_name, const string& first_name, unsigned int age,
		const string& speciality, const int experience)
		: Human(last_name, first_name, age)
	{
		this->experience = experience;
		this->speciality = speciality;
		cout << "TConstructor" << endl;
	}
	~Teacher()
	{
		cout << "TDestructor" << endl;
	}
	void info()
	{
		Human::info();
		cout << "Специальность\t" << speciality << "\t стаж\t" << experience << endl;
	}
	
};

//operators
 ostream& operator<<(ostream& os, const Human& obj) 
{
	 os << "Фамилия " << obj.get_last_name() << " Имя " << obj.get_first_name() << " Возраст " << obj.get_age() << endl;
	 return os;

}
 ostream& operator<<(ostream& os, const Student& obj)
 {
	 os << "Фамилия " << obj.get_last_name() << " Имя " << obj.get_first_name() << " Возраст " << obj.get_age() << endl;
	 os << " Специальность " << obj.get_speciality() << " группа "<< obj.get_group() << " успеваемость " << obj.get_rating() << endl;
	 	 return os;

 }
 ostream& operator<<(ostream& os, const Teacher& obj)
 {
	 os << "Фамилия " << obj.get_last_name() << " Имя " << obj.get_first_name() << " Возраст " << obj.get_age() << endl;
	 os << " Специальность " << obj.get_speciality() << " Стаж " << obj.get_experience() << endl;
	 return os;

 }
 ostream& operator<<(ostream& os, const Graduate& obj)
 {
	 os << "Фамилия " << obj.get_last_name() << " Имя " << obj.get_first_name() << " Возраст " << obj.get_age() << endl;
	 os << " Специальность " << obj.get_speciality() << " группа " << obj.get_group() << " успеваемость " << obj.get_rating() << endl;
	 os << "Тема диплома " << obj.get_diploma_theme() << endl;
	 return os;

 }
//#define RGX_NAME_CHECK
//#define RGX_EMAIL_CHECK
//#define INFERITANCE
#define POLYMORPHISM
void main()

{
	setlocale(LC_ALL, "");
#ifdef INHERITANCE
	Human human("Тупенко", "Василий", 18);
	human.info();
	Student Ivan("Остроумный", "Иван", 19, "Китайская философия", "OST_01", 4.9);
	Ivan.info();

	Graduate jessi("Pinkman", "Jessi", 25, "Meth", "WithWalter", 4.5, "Meth");
	jessi.info();
#endif // INHERITANCE


#ifdef RGX_NAME_CHECK
	regex name_template("[A-Z][a-z]{1,30}");
	string name;
	cout << "Введите имя "; cin >> name;
	//regex_match(строка для проверки, регулярное выражение,шаблон проверки)
	cout << regex_match(name.c_str(), name_template, std::regex_constants::match_any) << endl;
#endif // RGX_NAME_CHECK

#ifdef RGX_EMAIL_CHECK
	regex email_check("[A-Za-z0-9].{3,15}[@][A-Za-z]{1,10}.[A-Za-z]{2,3}");
	string email="vasya.tupenko@mail.ru";
	//cout << "Введите email "; cin >> email;
	cout << regex_match(email.c_str(), email_check, std::regex_constants::match_any) << endl;
#endif // RGX_EMAIL_CHECK

	//genreralization
	Teacher teacher("Einshtein", "Albert", 140, "Austronomy",99);
	Student student("Ломоносов", "Михаил", 100, "Phisics","SPD_011",99);

	Human* p_techer = &teacher;
	Human* p_student = &student;

	p_techer->info();
	p_student->info();
	cout << "..........................."<<endl;
	Human* group[]
	{
		new Teacher ("Einshtein", "Albert", 140, "Austronomy",99),
	new Teacher("Ломоносов", "Михаил", 100, "Phisics",99),
	new Student("Шведенко","Евгений",35,"Провизор","SPD_011",99),
	new Student("Пермяков","Роман",36,"Инженер","SPD_011",98),
	new Graduate("Кудратов","Шахзод",18,"РПО","SPD_011",98,"Разработка ИИ")
	};
	for (int i = 0; i<sizeof(group)/sizeof(Human*); i++)
	{
		//group[i]->info();
		cout << *group[i] << endl;
		cout << "................." << endl;
	}
	for (int i = 0; i < sizeof(group) / sizeof(Human*); i++)
	{
		delete group[i];
	}
	

}