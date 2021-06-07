#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

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
	Fraction(int integer)
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

//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define INCREMENT_CHECK

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

	Fraction A(1, 2);
	Fraction B(5, 11);
	cout << (A != B) << endl;
}