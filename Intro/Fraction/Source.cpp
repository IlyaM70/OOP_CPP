#include"Header.h"
void main()
{
	setlocale(LC_ALL, "Rus");
	
#ifdef HOMEWORK
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
	Fraction B(5, 15);
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
	F += D;
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
	cout << F << endl;

	cout << "Operator ==" << endl;
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
#endif // HOMEWORK
#ifdef TYPE_CONVERSIONS
//// явное 
//
//	cout << (char)43 << endl;  //С-like style 
//	cout<<char(43) << endl; // functional style
//	// неявные преобразования 
//	int a = 2; //  no conversion
//	double b = 3.4;
//	cout << a * b << endl; // оператор * неявно преобразует переменную а в тип double чтобы вернуть результат double
//	double c = 4; // convert int to double от меньшего к большему 
//	int d = c; // от большего к меньшему без потери данных
//	int e = 2.5; // от большего к меньшему с потерей данных

	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << a << endl;
	double b = (double)A;
	cout << b << endl;
	int c = (int)A;
	cout << c << endl;

	Fraction B = (Fraction)3; //implicit convertion from int to fraction
	// неявное преобразование значение 3 типа int во frACTION ЭТО возможно благодаря конструктору с 1 параметром 
	cout << B << endl;
	B.to_proper();
	cout<<B<<endl;
	Fraction C(5);
	cout << C << endl;

	//Fraction E = 2.7;
	//cout << E << endl;

#endif // TYPE_CONVERSIONS

	/*
	* operator type()
	* ......
	* return value;
	* 
	* 
	* operator int()
	* {
	* return value;
	* }
	*/
}




