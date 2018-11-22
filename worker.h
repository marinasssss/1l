#pragma once
#include "factory.h"


class worker : public factory {
public:
	worker();								//Конструктор
	worker(
		const char *nm,
		const char  *p,
		double s,
		const char *a,
		const char *n
	);											//Конструктор с параметром
	worker(const worker &w);					//Конструктор копирования

	void setName(const char *nm);				//Установка ФИО
	void setPos(const char  *p);				//			должности
	void setSal(double s);						//			ЗП
	void setAds(const char *a);					//			Адрес
	void setNum(const char* n);					//			Телефон

	const char* getName();						//Получение ФИО
	const char* getPos();						//			должности
	double getSal();							//			ЗП
	const char* getAds();						//			Адрес
	const char* getNum();						//			Телефон

	void clearName();						//Отчистка ФИО
	void clearPos();						//		должности
	void clearSal();						//		ЗП
	void clearAds();						//		Адрес
	void clearNum();						//		Телефон

	void scanName();						//Чтение ФИО
	void scanPos();							//		должности
	void scanSal();							//		ЗП
	void scanAds();							//		Адрес
	void scanNum();							//		Телефон

	void print();																//Функция вывода
	friend std::ostream& operator<<(std::ostream& os, const worker &p);			//информации

	worker& operator=(const worker& w);			//Оператор присваивания
	~worker();									//Деструктор
private:
	char *name;                 //ФИО
	char *pos;					//Должность
	double sal;					//Зп
	char* ads;					//Материал изделия
	char* num;					//Цена
	void init();				//Функция инициализатор
};
