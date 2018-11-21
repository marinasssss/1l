#pragma once
#include "factory.h"
class furniture : public factory {
public:
	enum { 
		N = 3
	};											//Константа для создания массива хранения габаритов
	furniture();								//Конструктор
	furniture(
		const char *t,
		const double *d,
		const char *c,
		const char *m,
		double p
	);											//Конструктор с параметром
	furniture(const furniture &f);				//Конструктор копирования

	void setType(const char *t);				//Установка типа
	void setDim(const double *d);				//			габаритов
	void setCol(const char *c);					//			цвета
	void setMat(const char *m);					//			материала
	void setPr(double p);						//			цены

	const char* getType();						//Получение типа
	const double* getDim();						//			габаритов
	const char* getCol();						//			цвета
	const char* getMat();						//			материала
	double getPr();								//			цены

	void addMat(const char* m);				//Добавление материала
	void addCol(const char* c);				//			цвета


	bool replaceCol(const char* c1, const char* c2);	// Перезапись города
	bool replaceMat(const char* m1, const char* m2);	// Перезапись одного из параметра габаритов

	void clearType();						//Отчистка типа
	void clearDim();						//		габаритов
	void clearCol();						//		цвета
	void clearMat();						//		материала
	void clearPr();							//		цены

	bool removeCol(const char* c);			//Убрать определенный материал
	bool removeMat(const char* c);								//цвет

	void scanType();						//Чтение типа
	void scanDim();							//		габаритов
	void scanCol();							//		цвета
	void scanMat();							//		материала
	void scanPr();							//		цены

	void print();																//Функция вывода
	friend std::ostream& operator<<(std::ostream& os, const furniture &p);		//информации

	furniture& operator=(const furniture& p);			//Оператор присваивания
	~furniture();										//Деструктор
private:
	char *type;                 //Тип
	double dim[N];				//Габариты
	char* color;				//Цвет
	char* material;				//Материал изделия
	double price;				//Цена
	void init();				//Функция инициализатор
};
