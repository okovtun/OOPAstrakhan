#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define delimiter "\n----------------------------------------------------------\n"

class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/(Fraction left, Fraction right);

class Fraction
{
	int integer;	//Целая часть
	int numerator;	//Числитель
	int denominator;//Знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//			Constructors:
	Fraction()
	{
		this->integer = 0;
		this->numerator = 0;
		this->denominator = 1;
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		this->denominator = 1;
		cout << "SingleArgumentConstructor:\t" << this << endl;
	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		this->set_integer(integer);
		this->set_numerator(numerator);
		this->set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyConstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t\t" << this << endl;
	}

	//			Operators:
	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t" << this << endl;
		return *this;
	}
	Fraction& operator*=(const Fraction& other)
	{
		return *this = *this*other;
	}
	Fraction& operator/=(const Fraction& other)
	{
		return *this = *this / other;
	}

	//			Increment/Decrement
	Fraction& operator++()	//Prefix increment
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction old = *this;	//CopyConstructor
		integer++;
		return old;
	}

	//			Type-cast operators:
	explicit operator int()const
	{
		return integer;
	}
	operator double()const
	{
		return integer + (double)numerator / denominator;
	}

	//			Methods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return *this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return *this;
	}
	Fraction inverted()
	{
		to_improper();
		Fraction inverted(denominator, numerator);
		return inverted;
	}

	void print()
	{
		if (integer)cout << integer;
		if (integer && numerator)cout << "(";
		if (numerator)cout << numerator << "/" << denominator;
		if (integer && numerator)cout << ")";
		if (integer == 0 && numerator == 0)cout << 0;
		cout << endl;
	}

	//friend istream& operator>>(istream& is, Fraction& obj); //Эта функция использует set-методы, 
	//поэтому данная строка не имеет смысла.
	/*friend istream& operator>>(istream& is, Fraction& obj)
	{
		int integer, numerator, denominator;
		is >> integer >> numerator >> denominator;
		obj.set_integer(integer);
		obj.set_numerator(numerator);
		obj.set_denominator(denominator);
		return is;
	}*/
};

Fraction operator*(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator()*right.get_numerator());
	result.set_denominator(left.get_denominator()*right.get_denominator());
	result.to_proper();
	return result;*/
	return Fraction//Явно вызываем конструктор и передаем в него параметры.
	(//Этот конструктор создает временный безымяный объект, который сразу ЖЕ отправляется return-у
		left.get_numerator()*right.get_numerator(),
		left.get_denominator()*right.get_denominator()
	).to_proper();
}
Fraction operator/(Fraction left, Fraction right)
{
	/*left.to_improper();
	right.to_improper();
	Fraction result
	(
		left.get_numerator()*right.get_denominator(),
		right.get_numerator()*left.get_denominator()
	);
	return result;*/
	return left * right.inverted();
}
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*if (left.get_numerator()*right.get_denominator() == right.get_numerator()*left.get_denominator())
	{
		return true;
	}
	else
	{
		return false;
	}*/
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();
}
bool operator!=(Fraction left, Fraction right)
{
	return !(left == right);
}

ostream& operator<<(ostream& os, const Fraction& obj)
{
	if (obj.get_integer())cout << obj.get_integer();
	if (obj.get_integer() && obj.get_numerator())cout << "(";
	if (obj.get_numerator())cout << obj.get_numerator() << "/" << obj.get_denominator();
	if (obj.get_integer() && obj.get_numerator())cout << ")";
	if (obj.get_integer() == 0 && obj.get_numerator() == 0)cout << 0;
	return os;
}
istream& operator>>(istream& is, Fraction& obj)
{
	int integer, numerator, denominator;
	integer = numerator = denominator = 0;
	char str[256]{};
	char* number[5]{};
	is.getline(str, 256);
	const char* delimiters = " (/)";
	int i = 0;
	for (char* pch = strtok(str, delimiters); pch; pch = strtok(NULL, delimiters), i++)
	{
		//cout << pch << tab;
		number[i] = pch;
	}
	//for (number[i] = strtok(str, delimiters); number[i]; number[i++] = strtok(NULL, delimiters));//???
	//for (int i = 0; i < 5; i++)cout << number[i] << tab; cout << endl;
	switch (i)
	{
	case 1: integer = atoi(number[0]); break;
	case 2:
		numerator = atoi(number[0]);
		denominator = atoi(number[1]);
		break;
	case 3:
		integer = atoi(number[0]);
		numerator = atoi(number[1]);
		denominator = atoi(number[2]);
		break;
	default:cout << "Что-то пошло не так :-(" << endl;
	}
	//is >> integer >> numerator >> denominator;
	obj.set_integer(integer);
	obj.set_numerator(numerator);
	obj.set_denominator(denominator);
	return is;
}

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK
//#define COMPARISON_OPERATORS_CHECK
//#define ISTREAM_OPERATOR
#define TYPE_CONVERSIONS

void main()
{
	setlocale(LC_ALL, "Russian");

#ifdef CONSTRUCTORS_CHECK
	double a = 5; cout << a << endl;
	Fraction A = 5;
	A.print();
	Fraction B(2, 3, 4);
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D;	//Default constructor
	D.print();
#endif // CONSTRUCTORS_CHECK

#ifdef ARITHMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a * b;

	Fraction A(1, 2, 3);
	Fraction B(19, 5);
	Fraction C = A * B;	C.print();
	Fraction D = A / B; D.print();

	A *= B;
	A.print();
	A /= B;
	A.print();
#endif // ARITHMETICAL_OPERATORS_CHECK

#ifdef INCREMENT_CHECK
	for (double i = .25; i < 10; i++)
	{
		cout << i << "\t";
	}
	cout << endl;
	//for(Counter; Condition; Expression);
	for (Fraction i(1, 4); i.get_integer() < 10; ++i)
	{
		//i.print();
		cout << i << "\t";
	}
#endif // INCREMENT_CHECK

#ifdef COMPARISON_OPERATORS_CHECK
	Fraction A(1, 2);
	Fraction B(5, 11);
	cout << (A != B) << endl;
#endif // COMPARISON_OPERATORS_CHECK

#ifdef ISTREAM_OPERATOR
	Fraction A;
	cout << "Введите целую часть, числитель и знаменатель через пробел: ";
	cin >> A;
	cout << A << endl;
#endif // ISTREAM_OPERATOR

#ifdef TYPE_CONVERSIONS
	//http://cplusplus.com/doc/tutorial/typecasting/
	/*
	---------------------------------------------------------
	Explicit conversions:
	(type)value - C-like notation;
	type(value) - Functional notation;

	implicit conversions - неявные преобразования.
	Warning: .... possible loss of data.
	---------------------------------------------------------
	*/
	//#define BASIC_TYPE_CONVERSIONS
#ifdef BASIC_TYPE_CONVERSIONS
	//				l-value = r-value;  
	int a = 2;		//No conversion
	double b = a;	//From less to more
	//int c = b;		//From more to less no data loss
	//int d = 5.2;	//From more to less with data loss
	//int* pa = a;	//Эти типы не преобразуются
	cout << 2 + 3.5 << endl;
	cout << double(5 / 2) << endl;
	cout << (double)5 / 2 << endl;
#endif // BASIC_TYPE_CONVERSIONS

	//#define OTHER_2_THIS_CONVERSIONS
#ifdef OTHER_2_THIS_CONVERSIONS
	//Single-Argument constructor
//Assignment operator
	int a = 2;	//No cenversion
	//Fraction A = a;	//From less to more
	Fraction A(a);	//explicit конструктор можно вызвать только так,
					//его невозможно вызвать оператором =, так как обычный конструктор с одним параметром
	cout << A << endl;
	cout << "\n==============================================================\n" << endl;;
	Fraction B;	//Default constructor
	cout << delimiter << endl;
	B = (Fraction)5;
	cout << delimiter << endl;
	cout << B << endl;
	cout << "\n==============================================================\n" << endl;;
#endif // OTHER_2_THIS_CONVERSION

	Fraction A(2, 3, 4);
	cout << A << endl;
	int a = (int)A;
	cout << "a = " << a << endl;
	double b = A;
	cout << "b = " << b << endl;
#endif // TYPE_CONVERSIONS

}

/*

			operator type()
			{
				...;
			}

*/