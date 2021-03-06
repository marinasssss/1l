#pragma once
#include <iostream>
#include <cstring>
#include <fstream>
#define MAX_SIZE 2048

const char o[8] = "_-_-_-_";
const char SEPARATORS[] = ". ,\\|/?!";


int strfnd(const char* s1, const char *s2);								//����� ������ ������� ������� ��������� s2 � s1
bool replace(char** s1, const char *s2, const char *s3);				//������ ���������
void strrd(char **s1, const char *sep);									//������ ����������� � ������ �� sep
int strcnt(const char *s1, const char* sep);							//������� ���-�� ����
void strct(char **s1, const char* s2);									//������������ �����
void strcopy(char* s1, const char* s2, int len);						//����������� �����
void strcopy(char* s1, const char* s2, int l, int r);
char* read(const char *s);												//������ ������
char* read(std::ifstream &is);											//���������� �� �����
void writeln(const char *s1, const char *s2 = "");						//����� �� �����
void writeln(const char *s1, const double d);							//����� �� �����
size_t __cdecl my_strlen(const char *s);								//������� �������� ������ � ������ nullptr
double strdbl(const char *str);