#pragma once
#include <iostream>
#include <cstring>
#define MAX_SIZE 2048

const char o[8] = "_-_-_-_";
const char SEPARATORS[] = ". ,\\|/?!";


int strfnd(const char* s1, const char *s2);								//Поиск номера первого символа подстроки s2 в s1
bool replace(char** s1, const char *s2, const char *s3);				//Замена подстроки
void strrd(char **s1, const char *sep);									//Замена раделителей в строке на sep
int strcnt(const char *s1, const char* sep);							//Подсчет кол-ва слов
void strct(char **s1, const char* s2);									//Конкатенация строк
void strcopy(char* s1, const char* s2, int len);						//Копирование строк
char* read(const char *s);												//Чтение строки
void writeln(const char *s1, const char *s2 = "");						//Вывод на экран
void writeln(const char *s1, const double d);							//Вывод на экран
size_t __cdecl my_strlen(const char *s);								//Подсчет символов строке с учетов ullptr