#pragma once
#include "furniture.h"
#include "machine.h"
#include "worker.h"

furniture* menu(furniture* f, int &l);		//���� ��� ������
worker* menu(worker* w, int &l);			//���� ��� �������
machine* menu(machine* m, int &l);			//���� ��� �����

template <typename T>
void print(T *obj, int l);					//������ ���� ��������
template <typename T>
int choose(T *obj, int l);					//����� ������ �� ���� ��������