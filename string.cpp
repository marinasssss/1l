#include "string.h"

int strfnd(const char* s1, const char *s2) {
	int i, j;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0' && s1[i + j] != '\0'; ++j) {
			if (s1[i + j] != s2[j])
				break;
		}
		if (s2[j] == '\0')
			break;
	}
	return i;
}
bool replace(char** s1, const char *s2, const char *s3) {
	int i, j, k;
	int n = strfnd(*s1, s2);
	int n1 = strlen(*s1);
	int n2 = strlen(s2);
	int n3 = strlen(s3);
	if (n < n1) {
		char *newS1 = new char[n1 + n3 - n2 + 1];
		for (i = 0; i < n; ++i)
			newS1[i] = (*s1)[i];
		k = i + n2;
		for (j = 0; j < n3; ++j, ++i)
			newS1[i] = s3[j];
		for (j = k; j < n1; ++j, ++i)
			newS1[i] = (*s1)[j];
		newS1[i] = '\0';
		delete[] *s1;
		*s1 = newS1;
	}
	else
		return false;
	return true;
}
void strrd(char **s1, const char *sep) {
	int i, j;
	int k = 0;
	int n1 = strlen(*s1);
	bool flag = false;
	char *buff = new char[MAX_SIZE];
	for (i = 0; i < n1; ++i) {
		for (j = 0; SEPARATORS[j] != '\0'; ++j)
			if (SEPARATORS[j] == (*s1)[i])
				break;
		if (SEPARATORS[j] == '\0') {
			flag = true;
			buff[k++] = (*s1)[i];
		}
		else if (flag) {
			for (j = 0; sep[j] != '\0'; ++j)
				buff[k++] = sep[j];
			flag = false;
		}
	}
	buff[k] = '\0';

	n1 = strlen(buff);
	*s1 = new char[++n1];
	strcopy(*s1, buff, n1);
	delete[] buff;
}
int strcnt(const char *s1, const char* sep) {
	int i, j;
	int count = 0;
	bool flag = false;
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; sep[j] != '\0'; ++j)
			if (s1[i] == sep[j])
				break;
		if (sep[j] != '\0') {
			if (flag) {
				++count;
				flag = false;
			}
		}
		else
			flag = true;
	}
	return ((flag) ? ++count : count);
}
void strct(char **s1, const char* s2) {
	int i, j;
	int n1 = (*s1) ? strlen(*s1) : 0;
	int n2 = (s2) ? strlen(s2) : 0;
	int n = n1 + n2 + 1;
	if (n == 1)
		return;
	char *res = new char[n];
	for (i = 0; i < n1; ++i)
		res[i] = (*s1)[i];
	for (j = 0; j < n2; ++j, ++i)
		res[i] = s2[j];
	res[i] = '\0';
	delete[] *s1;
	*s1 = res;
}
void strcopy(char* s1, const char* s2, int len) {
	for (int i = 0; i < len; ++i)
		s1[i] = s2[i];
}
void strcopy(char* s1, const char* s2, int l, int r) {
	int j = 0;
	for (int i = l; i < r; ++i)
		s1[j++] = s2[i];
}
char* read(const char *s) {
	int i;
	char *ptr;
	char buff[MAX_SIZE];
	std::cout << s;
	for (i = 0; (buff[i] = std::cin.get()) != '\n'; ++i);
	buff[i] = '\0';
	ptr = new char[i + 1];
	do {
		ptr[i] = buff[i];
	} while (i--);
	return ptr;
}
char* read(std::ifstream &in) {
	int i;
	char *ptr = NULL;
	char buff[MAX_SIZE];
	for (i = 0; (buff[i] = in.get()) != '\n' && buff[i] != EOF; ++i);
	if (buff[i] == EOF) return ptr;
	buff[++i] = '\0';
	ptr = new char[i + 1];
	do {
		ptr[i] = buff[i];
	} while (i--);
	return ptr;
}
void writeln(const char *s1, const char *s2) {
	if(s2)
		std::cout << s1 << s2 << std::endl;
	else
		std::cout << s1 << o << std::endl;
}
void writeln(const char *s1, const double d) {
	if (d)
		std::cout << s1 << d << std::endl;
	else
		std::cout << s1 << o << std::endl;
}
size_t __cdecl my_strlen(const char *s) {
	return ((s) ? strlen(s) : 0);
}
double strdbl(const char *str) {
	int i;
	double num = 0.0;
	double k = 10.0;
	for (i = 0; str[i] != '\0'; ++i) {
		if (str[i] > 47 && str[i] < 58)
			num = num * k + ((int)str[i] - 48);
		if (str[i] == '.')
			break;
	}
	if (str[i] != '\0') {
		for (++i; str[i] != '\0'; ++i) {
			if (str[i] > 47 && str[i] < 58) {
				num += double((int)str[i] - 48) / k;
				k *= 10.0;
			}
		}
	}
	return num;
}