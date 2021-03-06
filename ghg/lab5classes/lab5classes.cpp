// lab5classes.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
// 1. ОПРЕДЕЛЕНИЕ КЛАССА И ОБЪЕКТА
//свойтво(property) - переменная в составе класса
//метод() - функция в составе класса
//инкапсуляция - обединение в единую конструкцю
//наследование - создание производных классов от родительского 
//полиморфизм - экземпляры одного класса ведут себя по-разному
//Синтаксис объявления класса
//class Имя-Класса
//{
// int hp
class vehicle // игровое транспортное средство
{
private://спецификаторы доступа только для классов
public://общедоступны 
	double speed;//скорость
	char regnumber[6] = { 0 };//госномер
	unsigned char capacity;//число пасажиров
	bool check_regnumber();
		//void add_passenger (int passengers);
		//void accelerate(double delta_valocity);
};
// 2. CИНТАКСИС ОБЪЯВЛЕНИЯ И ОБРАЩЕНИЯ К СВОЙСТВАМ И МЕТОДАМ
//Имя_Класса объект1;
//vehicle car;
//car.speed = 123;
//объект1.св-во1 = 1;
//объект1.метод3();

// 3. СПЕЦИФИКАТОРЫ ДОСТУПА
// К полям (свойствам и методам)б объявленным в разделе 
//можно обращаться везде ( и из методов классаи снаружи, где виден объект
//

// 4. КОНСТРУКТОР И ДЕСТРУКТОР КЛАСАА

class user_data
{
private:
	char first_name[255];
	char second_name[255];
	char str_passport[10];
	char str_birthdate[10];
public:
	user_data();//конструктор
	~user_data();//дестрктор

	user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10]);
	user_data(char first_name[255], char second_name[255]);

   bool set_first_name(char p_first_name[255])
	{
	   //прверять на отсутствие цифр, точек и других знаков кроме тире
	   bool check;
	   for (int i = 0; i < '\0'; i++)
	   {
		   if (((p_first_name[i] >= 33) && (p_first_name[i] <= 44)) || 
			   ((p_first_name[i] >= 46) && (p_first_name[i] <= 64)))
		   {
			   return false;
		   }
		   if ((p_first_name[i] >= 91) && (p_first_name[i] <= 96))
		   {
			   return false;
		   }
	   }
	   return true;
   };
   bool set_second_name(char p_second_name[255])
   {
	   //прверять на отсутствие цифр, точек и других знаков кроме тире
	   bool check;
	   for (int i = 0; i < '\0'; i++)
	   {
		   if (((p_second_name[i] >= 33) && (p_second_name[i] <= 44)) ||
			   ((p_second_name[i] >= 46) && (p_second_name[i] <= 64)))
		   {
			   return false;
		   }
		   if ((p_second_name[i] >= 91) && (p_second_name[i] <= 96))
		   {
			   return false;
		   }
	   }
	   return true;
   };
   bool set_birthdate(char p_birthdate[10])
   {
	   //должно соответствовать формату "00.00.0000"
	   for (int i = 0; i < 10; i++)
	   {
		   if ((p_birthdate[i] >= '.') && (p_birthdate[i] <= '9'))
		   {
			   return true;
		   }
		   else
		   {
			   return false;
		   }
	   }
   };
   bool set_passport(char p_birthdate[10])
   {
	   return false;
   };
  /* bool set_passwort(char p_birthdate[10])
   {
	   //должно соответствовать формату "0000000000"
	   return false;
   };
   */
};
user_data::user_data()
{
}
user_data::~user_data()
{
}

user_data::user_data(char p_first_name[255], char p_second_name[255], char p_str_passport[10], char p_str_birthdate[10])
{
	for (int i = 0; i < 10; i++)
	{
		first_name[i] = p_first_name[i];
		second_name[i] = p_second_name[i];
		str_passport[i] = p_str_passport[i];
		str_birthdate[i] = p_str_birthdate[i];
	}
}

user_data::user_data (char p_first_name[255], char p_second_name[255])
{
	for (int i = 0; i < 10; i++)
	{
		first_name[i] = p_first_name[i];
		second_name[i] = p_second_name[i];
	}
}

int main()
{
	user_data person;
	char firstname[] = "Julia";// написать отдельно для имени и фамилии
	if (person.set_first_name(firstname) == true)
	{
		std::cout << "firstname : OK" << std::endl;
	}
	else
	{
		std::cout << "firstname : bad" << std::endl;
	}
	char secondname[] = "Ziborowa";

	if (person.set_second_name(secondname) == true)
	{
		std::cout << "secondname : OK" << std::endl;
	}
	else
	{
		std::cout << "secondname : bad" << std::endl;
	}

	char date[] = "06.11.2000";

    if (person.set_birthdate(date) == true)
	{
		std::cout << "date : OK" << std::endl;
	}
	else
	{
		std::cout << "date : bad" << std::endl;
	}

    return 0;
}