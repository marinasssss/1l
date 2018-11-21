#pragma once
#include <iostream>
#include "string.h"
#define TAB "\t\t\t\t"

//Класс для отлова всех исключений
class exceptions {
public:
	exceptions();				//Конструктор
	exceptions(const char*);    //Конструктор с параметром
	exceptions(exceptions&);    //Конструтор копирования
	exceptions(exceptions&&);   //Конструтор копирования
	~exceptions();              //Деструктор
	const char* what();         //Функция получения текстового описания ошибки
private:
	char *mesg;                 //Текс ошибка
};
