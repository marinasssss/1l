#include "worker.h"

// ������������
worker::worker() {
	std::cout << TAB << "worker()\n";
	init();
}
worker::worker(
	const char *nm,
	const char  *p,
	double s,
	const char *a,
	const char *n
) {
	std::cout << TAB << "worker(...)\n";
	init();
	setName(nm);
	setPos(p);
	setSal(s);
	setAds(a);
	setNum(n);
}
worker::worker(const worker &w) {
	std::cout << TAB << "worker(const worker &f)\n";
	init();
	setName(w.name);
	setPos(w.pos);
	setSal(w.sal);
	setAds(w.ads);
	setNum(w.num);
}
void worker::init() {
	name = nullptr;
	pos = nullptr;
	sal = 0;
	ads = nullptr;
	num = nullptr;
}

//�������
void worker::setName(const char* nm) {
	int n = my_strlen(nm);
	clearName();
	if (n++) {
		name = new char[n];
		strcopy(name, nm, n);
	}

}
void worker::setPos(const char* p) {
	int n = my_strlen(p);
	clearPos();
	if (n++) {
		name = new char[n];
		strcopy(name, p, n);
	}

}
void worker::setSal(double s) {
	sal = s;
}
void worker::setAds(const char* a) {
	int n = my_strlen(a);
	clearAds();
	if (n++) {
		ads = new char[n];
		strcopy(ads, a, n);
	}
}
void worker::setNum(const char* n) {
	int m = my_strlen(n);
	clearNum();
	if (m++) {
		num = new char[m];
		strcopy(num, n, m);
	}
}

//�������
const char* worker::getName() {
	return name;
}
const char* worker::getPos() {
	return pos;
}
double worker::getSal() {
	return sal;
}
const char* worker::getAds() {
	return ads;
}
const char* worker::getNum() {
	return num;
}

//�������
void worker::clearName() {
	delete[] name;
	name = nullptr;
}
void worker::clearPos() {
	delete[] pos;
	pos = nullptr;
}
void worker::clearSal() {
	sal = 0;
}
void worker::clearAds() {
	delete[] ads;
	ads = nullptr;
}
void worker::clearNum() {
	delete[] num;
	num = nullptr;
}

//����������
void worker::scanName() {
	delete[] name;
	name = read("\t������� ��� ���������: ");
	if (!my_strlen(name))
		clearName();
}
void worker::scanPos() {
	delete[] pos;
	pos = read("\t������� ���������: ");
	if (!my_strlen(pos))
		clearPos();
}
void worker::scanSal() {
	std::cout << "\t������� ��: ";
	std::cin >> sal;
	std::cin.get();
}
void worker::scanAds() {
	delete[] ads;
	ads = read("\t������� ����� ���������: ");
	if (!my_strlen(ads))
		clearAds();
}
void worker::scanNum() {
	delete[] num;
	num = read("\t������� ����� ��������: ");
	if (!my_strlen(num))
		clearNum();
}

//����� �� �����
std::ostream& operator<<(std::ostream& os, const worker &f) {
	os << "\t�������� ���������:\n";
	const char* ptr;
	if (f.name) ptr = f.name;
	else ptr = o;
	writeln("\t\t���: ", ptr);

	if (f.pos) ptr = f.pos;
	else ptr = o;
	writeln("\t\t���������: ", ptr);

	std::cout << "\t\t��: ";
	if (f.sal) os << f.sal;
	else os << o;
	os << std::endl;

	if (f.ads) ptr = f.ads;
	else ptr = o;
	writeln("\t\t�����: ", ptr);

	if (f.num) ptr = f.num;
	else ptr = o;
	writeln("\t\t�������: ", ptr);

	return os;
}
void worker::print() {
	std::cout << *this;
}


worker& worker::operator=(const worker& w) {
	if (this == &w)
		return *this;
	setName(w.name);
	setPos(w.pos);
	setSal(w.sal);
	setAds(w.ads);
	setNum(w.num);
	return *this;
}

//����������
worker::~worker() {
	std::cout << TAB << "~worker()\n";
	delete[] name;
	delete[] pos;
	delete[] ads;
	delete[] num;
}