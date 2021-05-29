#include<iostream>
using namespace std;

class Vehicle
{
	double hp;
	double max_speed;
	
public:
	//   constructor/destructor

	Vehicle(double hp, double max_speed)
	{
		this->hp = hp;
		this->max_speed = max_speed;
		cout << "VConstructor" << endl;
	}
	virtual ~Vehicle()
	{
		cout << "VDestructor" << endl;
	}
	//    methods
	virtual void info()
	{
		cout << "HP " << hp << " max_speed " << max_speed << endl;
	}
};
class Ground_Vehicle:public Vehicle
{
	bool can_move_on_ground = true;
	bool can_swim = false;
	bool can_fly = false;
public:
	//  constructor/destructor
	Ground_Vehicle(double hp, double max_speed):Vehicle( hp, max_speed)
	{
		cout << "GVConstructor" << endl;
	}
	//  methods

	 void info()
	{
		Vehicle::info();
		cout << "Can swim-" << ((can_swim == 1) ? "true" : "false") <<"; "<< "Can fly-" << ((can_fly == 1) ? "true" : "false")
			<< "; " << "Can move on the ground-" << ((can_move_on_ground == 1) ? "true" : "false") <<endl;
	}
};
class Car:public Ground_Vehicle
{
	string vehicle_type = "Car";
	string brand;
	string type;
	bool railroad_need = false;
public:
	//  constructor/destructor
	Car (double hp, double max_speed, string brand, string type):Ground_Vehicle(hp, max_speed)
	{
		this->brand = brand;
		this->type = type;
		cout << "CarConstructor" << endl;
	}
	~Car()
	{
		cout << "CarDectructor" << endl;
	}
	//  methods

	void info()
	{
		Ground_Vehicle::info();
		cout << "Railroad need " << ((railroad_need == 1) ? "true" : "false") << endl;
		cout <<vehicle_type<< "; Brand " << brand << "; Type " << type <<endl;
	}
};
class Motorcycle :public Ground_Vehicle
{
	string vehicle_type = "Motorcycle";
	string brand;
	string type;
	bool railroad_need = false;
public:
	//  constructor/destructor
	Motorcycle (double hp, double max_speed, string brand, string type) :Ground_Vehicle(hp, max_speed)
	{
		this->brand = brand;
		this->type = type;
		cout << "MCConstructor" << endl;
	}
	~Motorcycle()
	{
		cout << "MCDectructor" << endl;
	}
	//  methods

	void info()
	{
		Ground_Vehicle::info();
		cout << "Railroad need " << ((railroad_need == 1) ? "true" : "false") << endl;
		cout<< vehicle_type << "; Brand " << brand << "; Type " << type << endl;
	}
};
class Train :public Ground_Vehicle
{
	string vehicle_type = "Train";
	string brand;
	string type;
	bool railroad_need = true;
	int carriage_amount;
public:
	//  constructor/destructor
	Train(double hp, double max_speed, string brand, string type, int carriage_amount) :Ground_Vehicle(hp, max_speed)
	{
		this->brand = brand;
		this->type = type;
		this->carriage_amount = carriage_amount;
		cout << "TrainConstructor" << endl;
	}
	~Train()
	{
		cout << "TrainDectructor" << endl;
	}
	//  methods

	void info()
	{
		Ground_Vehicle::info();
		cout << "Railroad need " << ((railroad_need == 1) ? "true" : "false") << endl;
		cout << vehicle_type << "; Brand " << brand << "; Type " << type << "; Carriage amount " << carriage_amount << endl;
	}
};
class Ship :public Vehicle
{
	string vehicle_type = "Ship";
	string brand;
	string type;
	bool can_move_on_ground = false;
	bool can_swim = true;
	bool can_fly = false;
public:
	//  constructor/destructor
	Ship(double hp, double max_speed, string brand, string type ) :Vehicle(hp, max_speed)
	{
		this->brand = brand;
		this->type = type;
		cout << "ShipConstructor" << endl;
	}
	~Ship()
	{
		cout << "ShipDestructor" << endl;
	}
	//  methods

	void info()
	{
		Vehicle::info();
		cout << vehicle_type << "; Brand " << brand << "; Type " << type << endl;
		cout << "Can swim-" << ((can_swim == 1) ? "true" : "false") << "; " << "Can fly-" << ((can_fly == 1) ? "true" : "false")
			<< "; " << "Can move on the ground-" << ((can_move_on_ground == 1) ? "true" : "false") << endl;

	}
};
class Air_Vehicle :public Vehicle
{
	
	bool can_swim = false;
	bool can_fly = true;
	double max_flight_height;
public:
	//  constructor/destructor
	Air_Vehicle(double hp, double max_speed, double max_flight_height) :Vehicle(hp, max_speed)
	{
		this->max_flight_height = max_flight_height;
		cout << "AVConstructor" << endl;
	}
	~Air_Vehicle()
	{
		cout << "AVDestructor" << endl;
	}
	//  methods

	void info()
	{
		Vehicle::info();
		cout << "Can swim-" << ((can_swim == 1) ? "true" : "false") << "; " << "Can fly-" << ((can_fly == 1) ? "true" : "false")
			<< endl;
		cout << "Max flight height " << max_flight_height << endl;

	}
};
class Helicopter:public Air_Vehicle
{
	bool can_move_on_ground = false;
	string vehicle_type = "Helicopter";
	string brand;
	string type;
public:
	//  constructor/destructor
	Helicopter(double hp, double max_speed,double max_flight_height, string brand, string type) :Air_Vehicle(hp, max_speed, max_flight_height)
	{
		this->brand = brand;
		this->type = type;
		cout << "HConstructor" << endl;
	}
	~Helicopter()
	{
		cout << "HDestructor" << endl;
	}
	//  methods

	void info()
	{
		Air_Vehicle::info();
		cout << "Can move on the ground-" << ((can_move_on_ground == 1) ? "true" : "false")	<< endl;
		cout << vehicle_type << "; Brand " << brand << "; Type " << type << endl;
	}

};
class Plane: public Air_Vehicle
{
	bool can_move_on_ground = true;
	string vehicle_type = "Plane";
	string brand;
	string type;
public:
	//  constructor/destructor
	Plane(double hp, double max_speed, double max_flight_height, string brand, string type) :Air_Vehicle(hp, max_speed, max_flight_height)
	{
		this->brand = brand;
		this->type = type;
		cout << "PlaneConstructor" << endl;
	}
	~Plane()
	{
		cout << "PlaneDestructor" << endl;
	}
	//  methods

	void info()
	{
		Air_Vehicle::info();
		cout << "Can move on the ground-" << ((can_move_on_ground == 1) ? "true" : "false") << endl;
		cout << vehicle_type << "; Brand " << brand << "; Type " << type << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "Russian");
	Car c(100, 100, "Mersedes", "Sedan");
	c.info();
	cout << endl;
	Motorcycle d(100, 100, "Hyundai", "Sport");
	d.info();
	cout << endl;
	Train e(99999, 200,"Train","Passanger",10);
	e.info();
	cout << endl;
	Ship f(100, 50,"Ship","Cargo");
	f.info();
	cout << endl;
	Helicopter g(100, 300, 1000, "News", "News");
	g.info();
	cout << endl;
	Plane h(100, 1000, 2000, "Boing", "Passanger");
	h.info();
	cout << endl;
}