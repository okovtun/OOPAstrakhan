https://github.com/okovtun/OOPAstrakhan
https://www.youtube.com/watch?v=z2xE0bfnxB0&list=PLeqyOOqxeiIMnV5a0GG-WBAvP8UUln_jp&index=1
https://meet.google.com/mho-khdw-fhj

TOREAD:
https://drive.google.com/drive/folders/1mIhAKMp5-Jpy6s5X8u924tRCXFEdHE_z?usp=sharing

//////////////////////////////////////////////////////////////////////////////////////
///////////////////////				DATA CONTAINERS			//////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

Boost:
https://www.boost.org/doc/libs/?view=categorized
https://www.boost.org/doc/libs/1_76_0/doc/html/boost_asio.html
https://www.boost.org/doc/libs/1_76_0/doc/html/atomic.html
https://www.boost.org/doc/libs/1_76_0/libs/filesystem/doc/index.htm
https://www.boost.org/doc/libs/1_76_0/doc/html/thread.html

Qt:
https://www.qt.io/
https://doc.qt.io/qt-5/gettingstarted.html
https://doc.qt.io/qt-5/qtwidgets-tutorials-notepad-example.html
https://doc.qt.io/qt-5/qtdoc-tutorials-alarms-example.html

TODO:
От ветки InheritIteratorInList2 создать ветку SeparatedList2withInheritIterator 
и в этой разделить классы на файлы. Сделать это в 2 commit-а:
1. Methods out of class: просто вынести методы за пределы класса в пределах файла main.cpp;
2. Вынести класса в отдельные файлы: List.h, List.cpp;

DONE:
1. Написать метод void erase();
2. Проверочный код в секциях 
	HARDCORE;	//Для этого нужен итератор 
	COPY_CONSTRUCTOR_CHECK;
	COPY_ASSIGNMENT_CHECK;
   должен заработать;
3. Написать класс ReverseIterstor, который позволит перемещаться по списку в обратном направлении 
   (от Хвоста до Головы);

//	ForwardList DONE

DONE:
1. В класс ForwardList добавить методы:
	void pop_front();			DONE
	void pop_back();			DONE
	void insert(...);	//Вставляет элемент по указанному индексу DONE
	void erase(...);	//Удавляет элемент по указанному индексу
2. Проверочный код в секции SIZE_CONSTRUCTOR_AND_SUBSCRIPT должен заработать;	DONE
3. Код в секции COPY_METHODS должен НЕ падать;	DONE
4. Проверчный код в секции HARDCORE должен заработать;

//////////////////////////////////////////////////////////////////////////////////////
///////////////////////		INHERITANCE & POLYMORPHISM		//////////////////////////
//////////////////////////////////////////////////////////////////////////////////////

TOREAD:
http://cplusplus.com/doc/tutorial/typecasting/

TODO:
1. В проект Geometry добавить Равнобедренный треугольник (IsoscelesTriangle) 
   и прямоугольный треугольник (OrthogonalTryangle);
   https://drive.google.com/drive/folders/1PtH0LBlm7PpmBcaE6mwBnkftAcEui32y?usp=sharing
   https://drive.google.com/file/d/1hdvH4_wuL71ZhGvodGXATvmKqK3tiHa4/view?usp=sharing стр. 379. (397)
2. Толщину линии и начальную позицию вынести в базовый класс;

DONE:
В проекте Academy вынести все классы в отдельные файлы. 
Разделение выполнить в ветке DistributedAcademy.

DONE:
1. В проект Academy добавить класс Graduate, который будет описывать дипломника;	DONE
2. В set-методах реализовать фильтрацию данных;
3. Подумать, как в ostream& operator-ах использовать виртуальные методы;			DONE

DONE:
Реализовать класс String, описывающий строку.
Класс должен позволять  создавать обекты следующим образом:
String str;	//Создается пустая строка размером 80 Байт	DONE
String str1 = "Hello";				DONE
String str2;
cin >> str2;
String str3 = str1 + str2;
cout << str3 << endl;	//Здесь должно вывестись HelloWorld

Думаю под это будет веселее работать: https://www.youtube.com/watch?v=KMtPMINLO9I

Nick:
Реализовать класс Binary, описывающий двоичное число. 
Обеспечить:
1. арифметические операции: +, -, *, /; (Прямой, Обратный и Дополнительный код)
2. побитовые операции:
				~ NOT;
				|  OR;
				& AND;
				^ XOR;
3. Преобразование в дечсятичную систему счисления;
4. Объекты должны инициализироваться как двоиным, так и десятичным числом;

DONE:
В классе перегрузить недостающие операторы
1. Выучить теорию;
2. Реализовать класс Fraction, описывающий простую дробь. 
   В классе должны быть все необходимые методы, включая конструкторы, 
   а так же перегруженные операторы:
	-Арифметические операторы: +, -, *, /; 
	-Increment/Decrement (++/--);
	-Составные присваивания: +=, -=, *=, /=;
	-Операторы сравнения: ==, !=, >, <, >=, <=;
	-Операторы ввода/вывода <</>>;
   Постарайтесь максимально точно и осмысленно назвать переменные в классе.
   И не забываем про повторное использование кода ;-).


DONE:
1. Выучить теорию;
2. В классе Point написать метод ??? distance(???), который возвращает расстояние ДО УКАЗАННОЙ ТОЧКИ;	DONE
3. Написать функцию ??? distance(???), которая возвращает расстояние между двумя точками;