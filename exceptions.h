#pragma once
#include <iostream>
#include "string.h"
#define TAB "\t\t\t\t"

//����� ��� ������ ���� ����������
class exceptions {
public:
	exceptions();				//�����������
	exceptions(const char*);    //����������� � ����������
	exceptions(exceptions&);    //���������� �����������
	exceptions(exceptions&&);   //���������� �����������
	~exceptions();              //����������
	const char* what();         //������� ��������� ���������� �������� ������
private:
	char *mesg;                 //���� ������
};
