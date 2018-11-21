#pragma once
#include "factory.h"

class machine : public factory {
public:
	machine();									//�����������
	machine(
		const char *b,
		const char  *m,
		const char *n
	);											//����������� � ����������
	machine(const machine &m);					//����������� �����������

	void setBrd(const char *b);					//��������� �����
	void setMod(const char  *m);				//			������
	void setNum(const char *n);					//			���.������

	const char* getBrd();						//��������� �����
	const char* getMod();						//			������
	const char* getNum();						//			���.������

	void clearBrd();							//�������� �����
	void clearMod();							//		������
	void clearNum();							//		���.������

	void scanBrd();							//������ �����
	void scanMod();							//		������
	void scanNum();							//		���.������

	void print();																	//������� ������
	friend std::ostream& operator<<(std::ostream& os, const machine &m);			//����������

	machine& operator=(const machine& m);			//�������� ������������
	~machine();										//����������
private:
	char *mod;					//���������
	char *brd;					//����
	char *num;					//�����	
	void init();				//������� �������������
};