#pragma once
#include "factory.h"
class furniture : public factory {
public:
	enum { 
		N = 3
	};											//��������� ��� �������� ������� �������� ���������
	furniture();								//�����������
	furniture(
		const char *t,
		const double *d,
		const char *c,
		const char *m,
		double p
	);											//����������� � ����������
	furniture(const furniture &f);				//����������� �����������

	void setType(const char *t);				//��������� ����
	void setDim(const double *d);				//			���������
	void setCol(const char *c);					//			�����
	void setMat(const char *m);					//			���������
	void setPr(double p);						//			����

	const char* getType();						//��������� ����
	const double* getDim();						//			���������
	const char* getCol();						//			�����
	const char* getMat();						//			���������
	double getPr();								//			����

	void addMat(const char* m);				//���������� ���������
	void addCol(const char* c);				//			�����


	bool replaceCol(const char* c1, const char* c2);	// ���������� ������
	bool replaceMat(const char* m1, const char* m2);	// ���������� ������ �� ��������� ���������

	void clearType();						//�������� ����
	void clearDim();						//		���������
	void clearCol();						//		�����
	void clearMat();						//		���������
	void clearPr();							//		����

	bool removeCol(const char* c);			//������ ������������ ��������
	bool removeMat(const char* c);								//����

	void scanType();						//������ ����
	void scanDim();							//		���������
	void scanCol();							//		�����
	void scanMat();							//		���������
	void scanPr();							//		����

	void print();																//������� ������
	friend std::ostream& operator<<(std::ostream& os, const furniture &p);		//����������

	furniture& operator=(const furniture& p);			//�������� ������������
	~furniture();										//����������
private:
	char *type;                 //���
	double dim[N];				//��������
	char* color;				//����
	char* material;				//�������� �������
	double price;				//����
	void init();				//������� �������������
};
