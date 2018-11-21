#include "furniture.h"


//Конструкторы
furniture::furniture() {
	std::cout << TAB << "furniture()\n";
	init();
}
furniture::furniture(
	const char *t,
	const double *d,
	const char *c,
	const char *m,
	double p
){
	std::cout << TAB << "furniture(...)\n";
	init();
	setType(t);
	setDim(d);
	setCol(c);
	setMat(m);
	setPr(p);
}
furniture::furniture(const furniture &f) {
	std::cout << TAB << "furniture(const furniture &f)\n";
	init();
	setType(f.type);
	setDim(f.dim);
	setCol(f.color);
	setMat(f.material);
	setPr(f.price);
}
void furniture::init() {
	type = nullptr;
	memset(dim, 0, sizeof(double) * N);
	color = nullptr;
	material = nullptr;
	price = 0.0;
}

//Сеттеры
void furniture::setType(const char* t) {
	int n = my_strlen(t);
	clearType();
	if (n++) {
		type = new char[n];
		strcopy(type, t, n);
	}

}
void furniture::setDim(const double* d) {
	memcpy(dim, d, sizeof(double) * N);

}
void furniture::setCol(const char* c) {
	int n = my_strlen(c);
	clearCol();
	if (n++) {
		color = new char[n];
		strcopy(color, c, n);
		strrd(&color, sep);
	}

}
void furniture::setMat(const char* m) {
	int n = my_strlen(m);
	clearMat();
	if (n++) {
		material = new char[n];
		strcopy(material, m, n);
		strrd(&material, sep);
	}

}
void furniture::setPr(double p) {
	price = p;
}

//Геттеры
const char* furniture::getType() {
	return type;
}
const double* furniture::getDim() {
	return dim;
}
const char* furniture::getCol() {
	return color;
}
const char* furniture::getMat() {
	return material;
}
double furniture::getPr() {
	return price;
}

//Добавление
void furniture::addMat(const char* m) {
	if (my_strlen(m)) {
		if (material) {
			strct(&material, sep);
			strct(&material, m);
		}
		else
			strct(&material, m);
	}
}
void furniture::addCol(const char* c) {
	if (my_strlen(c)) {
		if (color) {
			strct(&color, sep);
			strct(&color, c);
		}
		else
			strct(&color, c);
	}
}

//Перезапись
bool furniture::replaceMat(const char* m1, const char* m2) {
	if (!material)
		return false;
	if (!my_strlen(m2))
		return removeMat(m1);
	if (!replace(&material, m1, m2))
		return false;
	return true;
}
bool furniture::replaceCol(const char* c1, const char* c2) {
	if (!color)
		return false;
	if (!my_strlen(c2))
		return removeCol(c1);
	if (!replace(&color, c1, c2))
		return false;
	return true;
}

//Отчиска
void furniture::clearType() {
	delete[] type;
	type = nullptr;
}
void furniture::clearDim() {
	memset(dim, 0, sizeof(double) * N);
}
void furniture::clearCol() {
	delete[] color;
	color = nullptr;
}
void furniture::clearMat() {
	delete[] material;
	material = nullptr;
}
void furniture::clearPr() {
	price = 0;
}

//Удаление
bool furniture::removeCol(const char *c) {
	char *tmp = nullptr;
	if (!color)
		return false;
	strct(&tmp, c);
	strct(&tmp, sep);
	if (!replace(&color, tmp, "")) {
		if (!replace(&color, c, "")) {
			delete[] tmp;
			return false;
		}
	}
	if (!strcnt(color, sep)) {
		clearCol();
	}
	delete[] tmp;
	return true;
}
bool furniture::removeMat(const char *m) {
	char *tmp = nullptr;
	strct(&tmp, m);
	strct(&tmp, sep);
	if (!material)
		return false;
	if (!replace(&material, tmp, "")) {
		if (!replace(&material, m, "")) {
			delete[] tmp;
			return false;
		}
	}
	if (!strcnt(material, sep)) {
		clearMat();
	}
	delete[] tmp;
	return true;
}

//Считывание
void furniture::scanType() {
	delete[] type;
	type = read("\tВведите тип мебели: ");
	if (!my_strlen(type))
		clearType();
}
void furniture::scanDim() {
	std::cout << "\tВведите высоту: ";
	std::cin >> dim[0];
	std::cin.get();
	std::cout << "\tВведите ширину: ";
	std::cin >> dim[1];
	std::cin.get();
	std::cout << "\tВведите глубину: ";
	std::cin >> dim[2];
	std::cin.get();
}
void furniture::scanCol() {
	delete[] color;
	color = read("\tВведите цвет мебели: ");
	if (!my_strlen(color))
		clearCol();
	else
		strrd(&color, sep);
}
void furniture::scanMat() {
	delete[] material;
	material = read("\tВведите мaтeриал мебели: ");
	if (!my_strlen(material))
		clearMat();
	else
		strrd(&material, sep);
}
void furniture::scanPr() {
	std::cout << "\tВведите стоимость: ";
	std::cin >> price;
}

//Вывод на экран
std::ostream& operator<<(std::ostream& os, const furniture &f) {
	os << "\tОписание мебели:\n";
	const char* ptr;
	if (f.type) ptr = f.type;
	else ptr = o;
	writeln("\t\tТип: ", ptr);

	std::cout << "\t\tВысота: ";
	if (f.dim[0]) os << f.dim[0];
	else os << o;
	os << std::endl;
	std::cout << "\t\tШирина: ";
	if (f.dim[1]) os << f.dim[1];
	else os << o;
	os << std::endl;
	std::cout << "\t\tГлубина: ";
	if (f.dim[2]) os << f.dim[2];
	else os << o;
	os << std::endl;

	if (f.color) ptr = f.color;
	else ptr = o;
	writeln("\t\tЦвет: ", ptr);

	if (f.material) ptr = f.material;
	else ptr = o;
	writeln("\t\tМатериал: ", ptr);

	std::cout << "\t\tЦена: ";
	if (f.price) os << f.price;
	else os << f.price;
	os << std::endl;

	return os;
}
void furniture::print() {
	std::cout << *this;
}


furniture& furniture::operator=(const furniture& f) {
	if (this == &f)
		return *this;
	setType(f.type);
	setDim(f.dim);
	setCol(f.color);
	setMat(f.material);
	setPr(f.price);
	return *this;
}

//Деструктор
furniture::~furniture() {
	std::cout << TAB << "~furniture()\n";
	delete[] type;
	delete[] color;
	delete[] material;
}