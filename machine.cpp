#include "machine.h"


// ������������
machine::machine() {
	std::cout << TAB << "machine()\n";
	init();
}
machine::machine(
	const char *b,
	const char  *m,
	const char *n
) {
	std::cout << TAB << "machine(...)\n";
	init();
	setBrd(b);
	setMod(m);
	setNum(n);
}
machine::machine(const machine &m) {
	std::cout << TAB << "machine(const machine &f)\n";
	init();
	setBrd(m.brd);
	setMod(m.mod);
	setNum(m.num);
}
void machine::init() {
	brd = nullptr;
	mod = nullptr;
	num = nullptr;
}

//�������
void machine::setBrd(const char* b) {
	int n = my_strlen(b);
	clearBrd();
	if (n++) {
		brd = new char[n];
		strcopy(brd, b, n);
	}

}
void machine::setMod(const char* m) {
	int n = my_strlen(m);
	clearMod();
	if (n++) {
		mod = new char[n];
		strcopy(mod, m, n);
	}

}
void machine::setNum(const char* n) {
	int m = my_strlen(n);
	clearNum();
	if (m++) {
		num = new char[m];
		strcopy(num, n, m);
	}
}

//�������
const char* machine::getBrd() {
	return brd;
}
const char* machine::getMod() {
	return mod;
}
const char* machine::getNum() {
	return num;
}

//�������
void machine::clearBrd() {
	delete[] brd;
	brd = nullptr;
}
void machine::clearMod() {
	delete[] mod;
	mod = nullptr;
}
void machine::clearNum() {
	delete[] num;
	num = nullptr;
}

//����������
void machine::scanBrd() {
	delete[] brd;
	brd = read("\t������� �����: ");
	if (!my_strlen(brd))
		clearBrd();
}
void machine::scanMod() {
	delete[] mod;
	mod = read("\t������� ������: ");
	if (!my_strlen(mod))
		clearMod();
}
void machine::scanNum() {
	delete[] num;
	num = read("\t������� ���.�����: ");
	if (!my_strlen(num))
		clearNum();
}

//����� �� �����
std::ostream& operator<<(std::ostream& os, const machine &f) {
	os << "\t�������� ������:\n";
	const char* ptr;
	if (f.brd) ptr = f.brd;
	else ptr = o;
	writeln("\t\t�����: ", ptr);

	if (f.mod) ptr = f.mod;
	else ptr = o;
	writeln("\t\t������: ", ptr);

	if (f.num) ptr = f.num;
	else ptr = o;
	writeln("\t\t���.�����: ", ptr);

	return os;
}
void machine::print() {
	std::cout << *this;
}

machine& machine::operator=(const machine& m) {
	if (this == &m)
		return *this;
	setBrd(m.brd);
	setMod(m.mod);
	setNum(m.num);
	return *this;
}

//����������
machine::~machine() {
	std::cout << TAB << "~machine()\n";
	delete[] brd;
	delete[] mod;
	delete[] num;
}