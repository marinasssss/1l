#pragma once
#include "furniture.h"
#include "machine.h"
#include "worker.h"

furniture* menu(furniture* f, int &l);		//Меню для мебели
worker* menu(worker* w, int &l);			//Меню для рабочих
machine* menu(machine* m, int &l);			//Меню для машин

template <typename T>
void print(T *obj, int l);					//Печать всех объектов
template <typename T>
int choose(T *obj, int l);					//Выбор одного из всех объектов