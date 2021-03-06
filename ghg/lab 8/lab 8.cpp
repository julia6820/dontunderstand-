// lab 8.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <cstring> //stcat(), strlen(), strcmp()
#include <string> // для С++ класса string 
#include <fstream> 
//СТРОКИ И ФАЙЛЫ 

//строки старого С-типа предсставляют из себя всего лишь массив символов с нулевым оконанием:
int sim;
char cstr1[] = "C-style  string1";
char cstr2[] = { 'C', '-', 's', 't', 'y','l', 'e', ' ','s','t','r','i', 'n', 'g', '2','\0' };
char cstr3[] = { '\67', '\45', '\115','t', 'y','l','e',' ', 's','t','r','i', 'n','g','3','\0' };
// в типе char на самом деле хранится знаковое целое число. Можно складывать, делить, умножать char
//чтобы придать символьный смысл данным, хранимым в char , нужна таблица соответствия чисел с символами - кодовая таблица 
//(ASCII, ANSI, UNICODE)

//ФУНКЦИИ ДЛЯ РАБОТЫ С С-СТРОКАМИ

//вывод на печать printf(char[],,,)  или printf(*char,,,) - print formatted
//форматирование print ("базовая %s строка %f", параметр1, параметр2)

//с помощью  pritf можно не просто печатать готовую строку, но и подставлять в нее другие переменные, попутно преобразовывая их в символьный вид и применяя форматирование
//форматирование printf ("базовая %s строка %f", параметр1, параметр2)

//позиции, куда будут подставляться параметры, обозначаются в базовой строке символом "%"
//значение символов форматирования берется из таблицы справки к функции http://www.cplusplus.com/refarence/cstdio/printf/
//значение некоторых из них %f - параметр подмтавляется на место %f, оформленное в виде числа с плавающей точкой 
//%s - параметр подставляется на место %s как строка 
//%d -параметр подставляется на место %d как целое число 
//%e - парметр подставляется на место %e как число в экспоненциальном виде

//объединение(конкатенация) строк strcat(*char, *char)
//копирование из одной строки в другую strcpy()
//сравнение strcmp()
//длина строки strlen()
//вставка строки в подстроку производится в несколько действий

//в стандартной библиотеке с++ массив символов инкапсулирован в класс std::string в который также собраны самые частоиспользуемые методы обработки
//и для которого перегружены операторы + (конкатенация), ввод, вывод и т.д.
//еще одно отличие от строк с - длина строки теперь задается отдельным числом, а не нулевым окончанием

//std::string cppstr1 = "C++ - style string 1";
//std::string cppstr2 = "";

//#define ANSI_COLOR_RED    "\33[0:31m\\]"
//#define ANSI_COLOR_RESET  "\33[0m\\]"*/


using namespace std;

int main()
{
	/*
printf(cstr1);
в функцию передается массив char (а имя массива является УКАЗАТЕЛЕМ на самй первый элемент массива),
либо указатель *char
printf("\n\n");

printf("Parametr1 = %f, parametr2 = %d\n\n", 1.5, 100);
Parametr1 = 1.5, parametr2 = 100

char n1 = '\n';

printf ("Insert double: %f,\n"
"insert long long: %d, \n"    целое число
"insert string: %s,\n"
"insert exponential: %e,\n")   мантиса - дробное число между >=1 и <2, умножаемое на 10^экспонента
"insert double: %f with pricision: %10.2f\n")   10.2 - 10 пустых мест до запятой и 2 знака после запятой
"ERROR insert long ;ong as double: %10.2f\n"  ошибка неверное привидение типов
"ERROR insert double as int: %010d\n"  ошибка неверное привидение типов
1000.15,
132456789,
"string =)",
1123456.1123456,
1.1123456,
1.1123456,
(long loong)10000,
10.5)


далее идут примеры работы со строками в С и эквивалентные примеры из с++ сравнение
int i = strcmp(cstr1,cstr2);
printf_s )"Result of strcmp(%s, %s) = %d\n", cstr1, cstr2, i);
cout << "Instead of strcmp () use (cppstr2) = "
<< (cppstr1 == cppstr2) << endl <<andl; для сравнения строк перегружен логический оператор "=="

длина строки
int lngth = strlen(cstr1);
printf_s ("Result of strlen (%s) = %d\n", cstrq, lngth);
cout << "Instead of strlen() use std::string.length():\t"
<< cppstr1.length() << endl << endl;  для определения длины - метод length() класса string

копирование из одной строки в другую
char cstr3[255];
strcpy_s (cstr3, 255, cstr2); требуется использование более сложного безопасного аналога strcpy_s()
printf_s("Result of strcpy(%s, %s)\n", cstr3,cstr2);
cppstr2 = cppsr1; для копирования перегружен оператор"="
cout << "Instread of strcpy() use operstor =: \t"
<< cppstr2<< endl << endl;

объудинение строк
strcat_s(cstr3, 255, cstr1);
cout << "Result of strcat(cstr2, cstr1) = "<< cstr3 << endl;
cout <<"Instead of strcat() usr operstor +:\t"
<< (cppstr1 + cppstr2) << endl << endl; для конкатенации перегружен "+"
mode
цикт работы с файлом заключается в
0.1 Проверить, существует ли файл ( в случае, если еужно открыть готовый)
0.2 При работе в С++ - осздать объект для работы с файлом
1.Открытие файла
2. Работа с файлом (чтение, запись, поиск)
3. Закрытие файла

с ФС программа работает не напрямую, а через ф-цию ОС:
ф-ция_программы (чтение/запись/открвтие) ->
ф-ция ОС из системной dll (+допю прверки, безопасность) ->
доступ к диску (барабан, головка, сектора)

работа с файлами на С аналогична работе со строками: указатель на файл + группа ф-ций
std::ifstream - класс для ввода (чтения из файла)
std::ofstream - класс для вывода (запись в файл)
аналагично cout - потоку, предназначенным для ввода/вывода из/в файл
fstream является потоком, предназначенным для ввода/вывода из/в файл
fstream -> basic_fstream -> basic_iostream : public
basic_istream, public basic_ostream

fstream fs; 0.Cоздание объекта при работе в С++

1.Открытие файла
fs.open ("Some text file.txt", std::fstream::in | std::fstream:: out | std::fstream::trunc);
fs.open ("Some text file.txt", при открытии файла необходимо указать имя файла
а также режим открытия: с перезаписью или без, для чтения/для записи/ оба режим и т.д.
std::fstream::in - добавляется режим вывод из файла
std::fstream::out -добавялется режим записи в файл
std::fstream::app - append добавляется режим с записью в конец файла
std::fstream::trunc); - trunc = truncste - режим с перезаписью всего файла

ВСПОМОГАТЕЛЬНЫЙ УЧЕБНЫЙ КОД: разбор, что такое режимы открытия и как шифруется информация в них 

auto fstream_mode = std::fstream::in | std::fstream::put  | std::fstream::app;
чтобы не вникать в служебныые типы страндартной библиотеки (что это там за mode) используется тип auto:
в зависимости от правой части выражения крмпилятор сам подбирает тип

cout << "std::fstream::in | std::fstream::out  | std::fstream::app = " <<std::bitset<8>(fstream_mode) << andl;

CОБСТВЕННО, РАБОТА С ФАЙЛОМ. Вывод в файл
fs << 1000.15 << endl
<< 132456789 <<endl;
<<"string =)" << endl
<<1123456.1123456 << endl
<<1.1123456 << endl
<< (long long ) 10000 << endl
<< 10.5 << endl;
fs.close();

getchar();
return 0;
*/
	std::fstream fs, text;
	text.open("Cucumber.txt", std::fstream::in);
	fs.open("Not Cucumber.txt", std::fstream::out);

	std::string str1;
	std::string str2;
	std::getline(text, str1);
	std::getline(text, str2);

	int pos = 0, temp = 0;
	while (str1.find(str2, pos) != -1)
	{
		pos = str1.find(str2, pos);
		pos++;
		temp++;
		fs << pos << '\t';
	}
	if (temp == 0)
		temp = -1;
	fs << '\n' << temp;
	fs.close();
}
