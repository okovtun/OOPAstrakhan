#define _USE_MATH_DEFINES
#include<iostream>
#include<Windows.h>
#include<wingdi.h>
using namespace std;
using std::cin;
using std::cout;
using std::endl;


namespace Geometry
{
	//typedef unsigned int Color;
	enum Color
	{
		console_black = 0x00,
		console_white = 0xFF,//0xFFFFFF00,
		console_red = 0xCC,//0xFF000000,
		console_green = 0xAA,//0x00FF0000,
		console_blue = 0x99,//0x0000FF00
		default_console_color = 7,

		black = 0x00000000,
		red = 0x000000FF,
		green = 0x0000AA00,
		yellow = 0x0000FFFF,
		blue = 0x00FF0000,
		grey = 0x00555555,
		white = 0x00FFFFFF,
	};

	class Shape
	{
	protected:
		Color color;
		UINT start_x;
		UINT start_y;
	public:
		Shape(Color color, UINT start_x = 0, UINT start_y = 0) :color(color), start_x(start_x), start_y(start_y) {}
		virtual	~Shape() {}

		virtual double get_area()const = 0;
		virtual double get_perimeter()const = 0;
		virtual void drow()const = 0;
		virtual void info()const = 0;
	};

	class Square :public Shape
	{
		double side;
	public:
		double get_side() { return side; }
		double set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
			return this->side;
		}
		void set_start_x(UINT x)
		{
			if (x > 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y > 700)y = 700;
			start_y = y;
		}
		Square(Color color, UINT start_x, UINT start_y, double side) :Shape(color, start_x, start_y)
		{
			set_side(side);
		}
		~Square() {}


		double get_area()const
		{
			return side * side;
		}
		double get_perimeter()const
		{
			return side * 4;
		}
		void drow()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 50, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			Rectangle(hdc, start_x, start_y, start_x + side, start_y + side);

			DeleteObject(hPen);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << endl;
			cout << "???????      :\n";
			cout << "????? ???????: " << side << endl;
			cout << "???????      : " << get_area() << endl;
			cout << "????????     : " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};

	class Rectangles :public Shape
	{
		double lenght;
		double width;
	public:
		double get_lenght()const { return lenght; }
		double get_width()const { return width; }

		void set_lenght(double lenght)
		{
			if (lenght <= 0)lenght = 1;
			this->lenght = lenght;
		}
		void set_widht(double width)
		{
			if (width <= 0)width = 1;
			this->width = width;
		}
		Rectangles(Color color, UINT start_x, UINT start_y, double lenght, double width) :Shape(color, start_x, start_y)
		{
			set_lenght(lenght);
			set_widht(width);
		}
		~Rectangles() {}

		double get_area()const
		{
			return lenght * width;
		}
		double get_perimeter()const
		{
			return (lenght + width) * 2;
		}
		void drow()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 20, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);

			Rectangle(hdc, start_x, start_y, start_x + lenght, start_y + width);

			DeleteObject(hPen);
			//DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);

		}
		void info()const
		{
			cout << endl;
			cout << "?????????????  :\n";
			cout << "?????          : " << lenght << endl;
			cout << "??????         : " << width << endl;
			cout << "???????        : " << get_area() << endl;
			cout << "????????       : " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};

	class Circle :public Shape
	{
		double radius;
	public:
		double get_radius()const { return radius; }
		double get_diameter()const { return radius * 2; }
		void set_radius(double radius)
		{
			if (radius <= 0)radius - 1;
			this->radius = radius;
		}
		void set_start_x(UINT x)
		{
			if (x >= 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y >= 700)y = 700;
			start_y = y;
		}
		Circle(Color color, UINT start_x, UINT start_y, double radius) :Shape(color, start_x, start_y)
		{
			set_radius(radius);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~Circle() {};

		double get_area()const
		{
			return M_PI * pow(radius, 2);
		}
		double get_perimeter()const
		{
			return 2 * M_PI * radius;
		}
		void drow()const
		{
			int x1 = 200;
			int y1 = 200;
			int x2 = x1 + get_diameter();
			int y2 = y1 + get_diameter();
			cout << "????? ?????? ???? ????:-)" << endl;
			HWND hwnd = GetConsoleWindow();
			// 1) ??????? ??????? ??????????
			//hwnd = FindWindow(NULL, L"Inheritance - Microsoft Visual Studio");
			HDC hdc = GetDC(hwnd);
			// 2) ??????? ????? ??????? ????? ????????
			HPEN hPen = CreatePen(PS_SOLID, 5, blue); //PS_SOLID - ???????? ?????, 5 - ????????, ????(RGB )

			HBRUSH hBrush = CreateSolidBrush(blue);

			// 3) ????????: ?? ??? ? ??? ????? ????????
			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);

			// 4) ??????:
			//Ellipse(hdc, 200, 200, 500, 500);
			Ellipse(hdc, start_x, start_y, start_x + get_radius(), start_y + get_radius());

			//????? ???? ??? ????? ????????????, ?? ????? ???????
			DeleteObject(hPen);
			DeleteObject(hBrush);
			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << endl;
			cout << "????\n";
			cout << "??????: " << radius << endl;
			cout << "???????: " << get_area() << endl;
			cout << "????????: " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};

	class Triangle :public Shape
	{
	public:
		Triangle(Color color) :Shape(color, start_x, start_y) {}
		~Triangle() {}

	};

	class EquilateralTriangle : Triangle
	{
		double side;
	public:
		double get_side()const { return side; }
		double get_height()const
		{
			return side * pow(3, .5) / 2;
		}
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		void set_start_x(UINT x)
		{
			if (x >= 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y >= 700)y = 700;
			start_y = y;
		}

		EquilateralTriangle(Color color, UINT start_x, UINT start_y, double side) :Triangle(color)
		{
			set_side(side);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~EquilateralTriangle() {}

		double get_area()const
		{
			return side * side * pow(3, 0.5) / 4;
		}
		double get_perimeter()const
		{
			return side * 3;
		}

		void drow()const
		{
			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HPEN hPen = CreatePen(PS_SOLID, 5, color);
			HBRUSH hBrush = CreateSolidBrush(color);

			SelectObject(hdc, hPen);
			SelectObject(hdc, hBrush);
			POINT points[] =
			{
				{start_x, start_y + side},
				{start_x + side, start_y + side},
				{start_x + side / 2, start_y + side - get_height()}
			};

			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			DeleteObject(hPen);
			DeleteObject(hBrush);

			ReleaseDC(hwnd, hdc);
		}
		void info()const
		{
			cout << endl;
			cout << "?????????????? ???????????\n";
			cout << "???? ???????: " << side << endl;
			cout << "??????      : " << get_height() << endl;
			cout << "???????: " << get_area() << endl;
			cout << "????????: " << get_perimeter() << endl;
			cout << endl;
			drow();
		}

	};

	class IsoscelesTriange : Triangle
	{
		double side;
	public:
		double get_side()const { return side; }
		double get_height()const { return side / 4 * 3.7; }
		double get_baseside()const { return sqrt(side * side - get_height() * get_height()) * 2; }
		void set_side(double side)
		{
			if (side <= 0)side = 1;
			this->side = side;
		}
		void set_start_x(UINT x)
		{
			if (x > 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y > 700)y = 700;
			start_y = y;
		}

		IsoscelesTriange(Color color, UINT start_x, UINT start_y, double side) :Triangle(color)
		{
			set_side(side);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~IsoscelesTriange() {};

		double get_area()const { return (get_baseside() * get_height()) / 2; }
		double get_perimeter()const { return side * 2 + get_baseside(); }

		void drow()const
		{
			cout << "?????????????? ???????????" << endl;

			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HBRUSH hBrash = CreateSolidBrush(color);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);

			SelectObject(hdc, hPen);
			//SelectObject
			POINT points[] =
			{
				{start_x, start_y + side},
				{start_x + get_baseside(), start_y + side},
				{start_x + get_baseside() / 2,start_y + side - get_height()}

			};

			Polygon(hdc, points, sizeof(points) / sizeof(POINT));


			DeleteObject(hPen);
			DeleteObject(hBrash);
			ReleaseDC(hwnd, hdc);
		}

		void info()const
		{
			cout << endl;
			cout << "?????????????? ???????????" << endl;
			cout << "????? ??????? ???????: " << get_side() << endl;
			cout << "??????: (3/4 ????? ?????)" << get_height() << endl;
			cout << "???????: " << get_area() << endl;
			cout << "????????: " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};

	class OrthogonalTriangle : Triangle
	{
		double leg_a;
		double leg_b;
	public:
		double get_leg_a()const { return leg_a; }
		double get_leg_b()const { return leg_b; }
		double get_hypotenuse()const { return sqrt(leg_a* leg_a + leg_b * leg_b); }

		void set_leg_a(double leg_a)
		{
			if (leg_a <= 0)leg_a = 1;
			this->leg_a = leg_a;
		}
		void set_leg_b(double leg_b)
		{
			if (leg_b <= 0)leg_b = 1;
			this->leg_b = leg_b;
		}

		void set_start_x(UINT x)
		{
			if (x > 1000)x = 1000;
			start_x = x;
		}
		void set_start_y(UINT y)
		{
			if (y > 700)y = 700;
			start_y = y;
		}

		OrthogonalTriangle(Color color, UINT start_x, UINT start_y, double leg_a, double leg_b) :Triangle(color)
		{
			set_leg_a(leg_a);
			set_leg_b(leg_b);
			set_start_x(start_x);
			set_start_y(start_y);
		}
		~OrthogonalTriangle() {};

		double get_area()const { return (leg_a * leg_b) / 2; }
		double get_perimeter()const { return leg_a + leg_b + get_hypotenuse(); }

		void drow()const
		{
			cout << "????????????? ???????????" << endl;

			HWND hwnd = GetConsoleWindow();
			HDC hdc = GetDC(hwnd);

			HBRUSH hBrash = CreateSolidBrush(color);
			HPEN hPen = CreatePen(PS_SOLID, 5, color);

			SelectObject(hdc, hPen);
			//SelectObject
			POINT points[] =
			{
				{start_x, start_y + leg_a},
				{start_x + leg_b, start_y + leg_a},
				{start_x,start_y}

			};

			Polygon(hdc, points, sizeof(points) / sizeof(POINT));

			DeleteObject(hPen);
			DeleteObject(hBrash);
			ReleaseDC(hwnd, hdc);
		}

		void info()const
		{
			cout << endl;
			cout << "????????????? ???????????" << endl;
			cout << "????? A: " << get_leg_a() << endl;
			cout << "????? B: " << get_leg_b() << endl;
			cout << "??????????: " << get_hypotenuse() << endl;
			cout << "???????: " << get_area() << endl;
			cout << "????????: " << get_perimeter() << endl;
			cout << endl;
			drow();
		}
	};
}

//Rectangle(HDC hdc, UINT left_up_x, UNIT left_up_y, UNIT right _down_x, UNIT right _down_y);
//Ellipse(HDC hdc, UINT left_up_x, UNIT left_up_y, UNIT right _down_x, UNIT right _down_y);

void main()
{
	setlocale(LC_ALL, "Russian");

	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD buffer = { 80,50 };
	SetConsoleDisplayMode(hConsole, CONSOLE_FULLSCREEN, &buffer);

	unsigned int delay = 3000;

	Geometry::Square square(Geometry::Color::red, 300, 300, 200);
	square.info();
	//Sleep(delay);
	cin.get();

	system("CLS");
	Geometry::Rectangles rectangle(Geometry::Color::blue, 100, 350, 300, 400);
	rectangle.info();
	//Sleep(delay);
	cin.get();

	system("CLS");
	Geometry::Circle circle(Geometry::Color::red, 200, 280, 200);
	circle.info();
	//Sleep(delay);
	cin.get();

	system("CLS");
	Geometry::EquilateralTriangle equil_triangle(Geometry::Color::red, 250, 400, 400);
	equil_triangle.info();
	//Sleep(delay);
	cin.get();

	system("CLS");
	Geometry::IsoscelesTriange iso_triangle(Geometry::Color::red, 100, 300, 300);
	iso_triangle.info();
	//Sleep(delay);
	cin.get();

	system("CLS");
	Geometry::OrthogonalTriangle Ort_Triangle(Geometry::Color::red, 100, 300, 300, 200);
	Ort_Triangle.info();
	//Sleep(delay);
	cin.get();

	//BOOL Rectangle
}