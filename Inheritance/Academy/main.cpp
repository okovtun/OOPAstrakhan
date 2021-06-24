#include<iostream>
#include<string>
using namespace std;

class Human
{
protected:
	string last_name;	//Фамилия
	string first_name;	//Имя
	unsigned int age;	//Возраст
public:
	const string& get_last_name()const
	{
		return last_name;
	}
	const string& get_first_name()const
	{
		return first_name;
	}
	unsigned int get_age()const
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
	//				Constructors:
	Human(const string& last_name, const string& first_name, unsigned int age)
	{
		set_last_name(last_name);
		set_first_name(first_name);
		set_age(age);
		cout << "HConstructor:\t" << this << endl;
	}
	~Human()
	{
		cout << "HDestructor:\t" << this << endl;
	}

	//				Methods:
	void print()
	{
		cout << last_name << " " << first_name << " " << age << " лет.\n";
	}
};

class Student :public Human
{
	string specialty;
	string group;
	double rating;
public:
	const string& get_specialty()const
	{
		return specialty;
	}
	const string& get_group()const
	{
		return group;
	}
	double get_rating()const
	{
		return rating;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_group(const string& group)
	{
		this->group = group;
	}
	void set_rating(double rating)
	{
		this->rating = rating;
	}

	//				Constructors:
	Student
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, const string& group, double rating
	) :Human(last_name, first_name, age)
	{
		set_specialty(specialty);
		set_group(group);
		set_rating(rating);
		cout << "SConstructor:\t" << this << endl;
	}
	~Student()
	{
		cout << "SDestructor:\t" << this << endl;
	}

	//				Methods:
	void print()
	{
		Human::print();
		cout << "специальность: " << specialty << ", группа: " << group << ", успеваемость: " << rating << endl;
	}
};

class Teacher : Human
{
	string specialty;
	unsigned int experience;
public:
	int evil;
	const string& get_specialty()const
	{
		return specialty;
	}
	unsigned int get_experience()const
	{
		return experience;
	}
	void set_specialty(const string& specialty)
	{
		this->specialty = specialty;
	}
	void set_experience(unsigned int experience)
	{
		this->experience = experience;
	}
	//				Constructors:
	Teacher
	(
		const string& last_name, const string& first_name, unsigned int age,
		const string& specialty, unsigned int experience
	) :Human(last_name, first_name, age)
	{
		this->specialty = specialty;
		this->experience = experience;
		cout << "TConstructor:\t" << this << endl;
	}
	~Teacher()
	{
		this->age = 123;
		//cout << "TDestructor:\t" << this << endl;
	}
	//			Methods:
	void print()
	{
		Human::print();
		cout << "специальность: " << specialty << ", опыт преподавания: " << experience << " лет" << endl;
	}
};

void main()
{
	setlocale(LC_ALL, "Russian");
	/*Human human("Тупенко", "Василий", 18);
	human.print();*/
	Student stud("Тупенко", "Василий", 18, "РПО", "BV_123", 43.4);
	stud.print();
	Teacher Albert("Einstein", "Albert", 150, "Astrophisics", 120);
	Albert.print();
	cout << Albert.get_last_name() << endl;
	//Albert.get_first_name();
}

/*
---------------------------------------------------------------
class DericedClass:access_modifier BaseClass
{
	specification;
};
---------------------------------------------------------------
*/