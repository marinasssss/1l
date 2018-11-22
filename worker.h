#pragma once
#include "factory.h"


class worker : public factory {
public:
	worker();								//�����������
	worker(
		const char *nm,
		const char  *p,
		double s,
		const char *a,
		const char *n
	);											//����������� � ����������
	worker(const worker &w);					//����������� �����������

	void setName(const char *nm);				//��������� ���
	void setPos(const char  *p);				//			���������
	void setSal(double s);						//			��
	void setAds(const char *a);					//			�����
	void setNum(const char* n);					//			�������

	const char* getName();						//��������� ���
	const char* getPos();						//			���������
	double getSal();							//			��
	const char* getAds();						//			�����
	const char* getNum();						//			�������

	void clearName();						//�������� ���
	void clearPos();						//		���������
	void clearSal();						//		��
	void clearAds();						//		�����
	void clearNum();						//		�������

	void scanName();						//������ ���
	void scanPos();							//		���������
	void scanSal();							//		��
	void scanAds();							//		�����
	void scanNum();							//		�������

	void print();																//������� ������
	friend std::ostream& operator<<(std::ostream& os, const worker &p);			//����������

	worker& operator=(const worker& w);			//�������� ������������
	~worker();									//����������
private:
	char *name;                 //���
	char *pos;					//���������
	double sal;					//��
	char* ads;					//�������� �������
	char* num;					//����
	void init();				//������� �������������
};
