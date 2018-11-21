#pragma once
#include "factory.h"

class machine : public factory {
public:
	machine();									//Конструктор
	machine(
		const char *b,
		const char  *m,
		const char *n
	);											//Конструктор с параметром
	machine(const machine &m);					//Конструктор копирования

	void setBrd(const char *b);					//Установка марки
	void setMod(const char  *m);				//			модели
	void setNum(const char *n);					//			гос.номера

	const char* getBrd();						//Получение марки
	const char* getMod();						//			модели
	const char* getNum();						//			гос.номера

	void clearBrd();							//Отчистка марки
	void clearMod();							//		модели
	void clearNum();							//		гос.номера

	void scanBrd();							//Чтение марки
	void scanMod();							//		модели
	void scanNum();							//		гос.номера

	void print();																	//Функция вывода
	friend std::ostream& operator<<(std::ostream& os, const machine &m);			//информации

	machine& operator=(const machine& m);			//Оператор присваивания
	~machine();										//Деструктор
private:
	char *mod;					//Должность
	char *brd;					//Цена
	char *num;					//Номер	
	void init();				//Функция инициализатор
};