#pragma once
#include "Keeper.h"

void menu_f(Keeper *k);			//���� ��� ������
void menu_m(Keeper *k);			//���� ��� �������
void menu_w(Keeper *k);			//���� ��� �����

template <typename T>
void print(T *obj, int l);					//������ ���� ��������
template <typename T>
int choose(T *obj, int l);					//����� ������ �� ���� ��������