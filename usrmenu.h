#pragma once
#include "Keeper.h"

void menu_f(Keeper *k);			//Меню для мебели
void menu_m(Keeper *k);			//Меню для рабочих
void menu_w(Keeper *k);			//Меню для машин

template <typename T>
void print(T *obj, int l);					//Печать всех объектов
template <typename T>
int choose(T *obj, int l);					//Выбор одного из всех объектов