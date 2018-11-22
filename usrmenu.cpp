#include "usrmenu.h"

using std::cout;
using std::cin;
using std::endl;

furniture* menu(furniture* f, int &l) {
	int i;
	int ch;
	bool flag = true;
	furniture *ptr;
	while (flag) {
		ptr = nullptr;
		writeln(" (1) Добавить мебель");
		writeln(" (2) Удалить мебель");
		writeln(" (3) Выбрать мебель для изменения ее параметров");
		writeln(" (4) Вывести полную информацию по имеющейся мебели");
		writeln(" (5) Назад");
		cout << "Выберите номер пункта: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			writeln("сли хотите оставить строковый параметр пустым нажмите enter");
			writeln("Если параметр числовой, то введите \"0\"");
			writeln("Символы-разделители: ", SEPARATORS);
			ptr = new furniture[l + 1];
			for (i = 0; i < l; ++i) {
				ptr[i] = *(f + i);
			}
			delete[] f;
			f = ptr;
			f[l].scanType();
			f[l].scanDim();
			f[l].scanCol();
			f[l].scanMat();
			f[l].scanPr();
			++l;
			break;
		case 2:
			if (l) {
				try {
					ch = choose(f, l);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new furniture[l - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = f[i];
				}
				for (++i; i < l; ++i) {
					ptr[i - 1] = f[i];
				}
				delete[] f;
				f = ptr;
				--l;
				writeln("Удаление завершено");
			}
			else {
				print(f, l);
			}
			break;
		case 3:
			if (l) {
				int n;
				char *str;
				try {
					ch = choose(f, l);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout << endl << endl;
				writeln(" #1 Задать новый тип");
				writeln(" #2 Задать новые габариты");
				writeln(" #3 Задать новые цвета");
				writeln(" #4 Задать новые материалы");
				writeln(" #5 Задать новую стоимость");
				writeln(" #6 Добавить новый цвет");
				writeln(" #7 Добавить новый материал");
				writeln(" #8 Измениить один из цветов");
				writeln(" #9 Измениить один из материалов");
				writeln("#10 Вывести на экран тип");
				writeln("#11 Вывести на экран габариты");
				writeln("#12 Вывести на экран цвета");
				writeln("#13 Вывести на экран материалы");
				writeln("#14 Вывести на экран стоимоть");
				writeln("#15 Отчситить поле типа");
				writeln("#16 Отчситить поле габариты");
				writeln("#17 Отчситить поле цвета");
				writeln("#18 Отчситить поле материалы");
				writeln("#19 Отчситить поле цены");
				writeln("#20 Удалить один из цветов");
				writeln("#21 Удалить один из материалов");
				writeln("#22 Вывод информации");
				writeln("#23 Назад");
				while (flag) {
					str = nullptr;
					cout << "Выберите номер пункта: ";
					cin >> n;
					cin.get();
					switch (n--) {
					case 1:
						f[ch].scanType();
						writeln("\tУспешно");
						break;
					case 2:
						f[ch].scanDim();
						writeln("\tУспешно");
						break;
					case 3:
						f[ch].scanCol();
						writeln("\tУспешно");
						break;
					case 4:
						f[ch].scanMat();
						writeln("\tУспешно");
						break;
					case 5:
						f[ch].scanPr();
						writeln("\tУспешно");
						break;
					case 6:
						str = read("\tВведите название цвета: ");
						f[ch].addCol(str);
						writeln("\tУспешно");
						break;
					case 7:
						str = read("\tВведите название материала: ");
						f[ch].addMat(str);
						writeln("\tУспешно");
						break;
					case 8:
						if (f[ch].getCol()) {
							char *str2;;
							writeln("\tЦвета: ", f[ch].getCol());
							str = read("Введите заменяемый цвет: ");
							str2 = read("Введите заменяющий цвет: ");
							if (f[ch].replaceCol(str, str2))
								writeln("\tУспешно");
							else
								writeln("\tЦвет не присутствует в списке");
						}
						else
							writeln("\tСписок цветов пуст");
						break;
					case 9:
						if (f[ch].getCol()) {
							char *str2;;
							writeln("\tЦвета: ", f[ch].getCol());
							str = read("Введите заменяемый метериал: ");
							str2 = read("Введите заменяющий метериал: ");
							if (f[ch].replaceCol(str, str2))
								writeln("\tУспешно");
							else
								writeln("\tМатериал не присутствует в списке");
						}
						else
							writeln("\tСписок материалов пуст");
						break;
					case 10:
						writeln("\tТип: ", f[ch].getType());
						break;
					case 11: {
						const double *t = f[ch].getDim();
						writeln("\tГабариты: ");
						writeln("\t\tВысота: ", t[0]);
						writeln("\t\tШирина: ", t[1]);
						writeln("\t\tГлубина: ", t[2]);
					}
						break;
					case 12:
						writeln("\tЦвета: ", f[ch].getCol());
						break;
					case 13:
						writeln("\tМатериалы: ", f[ch].getMat());
						break;
					case 14:
						writeln("\tЦена: ", f[ch].getPr());
						break;
					case 15:
						f[ch].clearType();
						writeln("\tУспешно");
						break;
					case 16:
						f[ch].clearDim();
						writeln("\tУспешно");
						break;
					case 17:
						f[ch].clearCol();
						writeln("\tУспешно");
						break;
					case 18:
						f[ch].clearMat();
						writeln("\tУспешно");
						break;
					case 19:
						f[ch].clearPr();
						writeln("\tУспешно");
						break;
					case 20:
						if (f[ch].getCol()) {
							writeln("\tЦвета: ", f[ch].getCol());
							str = read("Введите название цвета: ");
							if (f[ch].removeCol(str))
								writeln("\tУспешно");
							else
								writeln("\tЦвет не присутствует в списке");
						}
						else
							writeln("\tСписок цветов пуст");
						break;
					case 21:
						if (f[ch].getMat()) {
							writeln("\tМатериалы: ", f[ch].getMat());
							str = read("Введите название материала: ");
							if (f[ch].removeMat(str))
								writeln("\tУспешно");
							else
								writeln("\tМатериал не присутствует в списке");
						}
						else
							writeln("\tСписок материалов пуст");
						break;
					case 22:
						f[ch].print();
						break;
					case 23:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(f, l);
			}
			break;
		case 4:
			print(f, l);
			break;
		case 5:
			flag = false;
			break;
		}
		cout << endl;
	}
	return f;
}
worker* menu(worker* w, int &l) {
	int i;
	int ch;
	bool flag = true;
	worker *ptr;
	while (flag) {
		ptr = nullptr;
		writeln(" (1) Добавить работника");
		writeln(" (2) Удалить работника");
		writeln(" (3) Выбрать работника для изменения его параметров");
		writeln(" (4) Вывести полную информацию по имеющеимся работникам");
		writeln(" (5) Назад");
		cout << "Выберите номер пункта: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			writeln("сли хотите оставить строковый параметр пустым нажмите enter");
			writeln("Если параметр числовой, то введите \"0\"");
			writeln("Символы-разделители: ", SEPARATORS);
			ptr = new worker[l + 1];
			for (i = 0; i < l; ++i) {
				ptr[i] = *(w + i);
			}
			delete[] w;
			w = ptr;
			w[l].scanName();
			w[l].scanPos();
			w[l].scanSal();
			w[l].scanAds();
			w[l].scanNum();
			++l;
			break;
		case 2:
			if (l) {
				try {
					ch = choose(w, l);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new worker[l - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = w[i];
				}
				for (++i; i < l; ++i) {
					ptr[i - 1] = w[i];
				}
				delete[] w;
				w = ptr;
				--l;
				writeln("Удаление завершено");
			}
			else {
				print(w, l);
			}
			break;
		case 3:
			if (l) {
				int n;
				char *str;
				try {
					ch = choose(w, l);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout << endl << endl;
				writeln(" #1 Задать новое ФИО");
				writeln(" #2 Задать новую должность");
				writeln(" #3 Задать новую ЗП");
				writeln(" #4 Задать новый адрес");
				writeln(" #5 Задать новый номер");
				writeln(" #6 Вывести на экран ФИО");
				writeln(" #7 Вывести на экран должность");
				writeln(" #8 Вывести на экран ЗП");
				writeln(" #9 Вывести на экран адрес");
				writeln("#10 Вывести на экран номер");
				writeln("#11 Отчситить поле ФИО");
				writeln("#12 Отчситить поле должности");
				writeln("#13 Отчситить поле ЗП");
				writeln("#14 Отчситить поле адреса");
				writeln("#15 Отчситить поле номера");
				writeln("#16 Вывод информации");
				writeln("#17 Назад");
				while (flag) {
					str = nullptr;
					cout << "Выберите номер пункта: ";
					cin >> n;
					cin.get();
					switch (n--) {
					case 1:
						w[ch].scanName();
						writeln("\tУспешно");
						break;
					case 2:
						w[ch].scanPos();
						writeln("\tУспешно");
						break;
					case 3:
						w[ch].scanSal();
						writeln("\tУспешно");
						break;
					case 4:
						w[ch].scanAds();
						writeln("\tУспешно");
						break;
					case 5:
						w[ch].scanNum();
						writeln("\tУспешно");
						break;
					case 6:
						writeln("\tФИО: ", w[ch].getName());
						break;
					case 7:
						writeln("\tДолжность: ", w[ch].getPos());
						 break;
					case 8:
						writeln("\tЗП: ", w[ch].getSal());
						break;
					case 9:
						writeln("\tАдрес: ", w[ch].getAds());
						break;
					case 10:
						writeln("\tНомер телефона: ", w[ch].getNum());
						break;
					case 11:
						w[ch].clearName();
						writeln("\tУспешно");
						break;
					case 12:
						w[ch].clearPos();
						writeln("\tУспешно");
						break;
					case 13:
						w[ch].clearSal();
						writeln("\tУспешно");
						break;
					case 14:
						w[ch].clearAds();
						writeln("\tУспешно");
						break;
					case 15:
						w[ch].clearNum();
						writeln("\tУспешно");
						break;
					case 16:
						w[ch].print();
						break;
					case 17:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(w, l);
			}
			break;
		case 4:
			print(w, l);
			break;
		case 5:
			flag = false;
			break;
		}
		cout << endl;
	}
	return w;
}
machine* menu(machine* m, int &l) {
	int i;
	int ch;
	bool flag = true;
	machine *ptr;
	while (flag) {
		ptr = nullptr;
		writeln(" (1) Добавить машину");
		writeln(" (2) Удалить машину");
		writeln(" (3) Выбрать машину для изменения его параметров");
		writeln(" (4) Вывести полную информацию по имеющеимся машинам");
		writeln(" (5) Назад");
		cout << "Выберите номер пункта: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			writeln("сли хотите оставить строковый параметр пустым нажмите enter");
			writeln("Если параметр числовой, то введите \"0\"");
			writeln("Символы-разделители: ", SEPARATORS);
			ptr = new machine[l + 1];
			for (i = 0; i < l; ++i) {
				ptr[i] = *(m + i);
			}
			delete[] m;
			m = ptr;
			m[l].scanBrd();
			m[l].scanMod();
			m[l].scanNum();
			++l;
			break;
		case 2:
			if (l) {
				try {
					ch = choose(m, l);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				ptr = new machine[l - 1];
				for (i = 0; i < ch; ++i) {
					ptr[i] = m[i];
				}
				for (++i; i < l; ++i) {
					ptr[i - 1] = m[i];
				}
				delete[] m;
				m = ptr;
				--l;
				writeln("Удаление завершено");
			}
			else {
				print(m, l);
			}
			break;
		case 3:
			if (l) {
				int n;
				char *str;
				try {
					ch = choose(m, l);
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				cout << endl << endl;
				writeln(" #1 Задать новую марку");
				writeln(" #2 Задать новую модель");
				writeln(" #3 Задать новый гос.номер");
				writeln(" #4 Вывести на марку");
				writeln(" #5 Вывести на модель");
				writeln(" #6 Вывести на гос.номер");
				writeln(" #7 Отчситить поле марки");
				writeln(" #8 Отчситить поле модели");
				writeln(" #9 Отчситить поле гос.номера");
				writeln("#10 Вывод информации");
				writeln("#11 Назад");
				while (flag) {
					str = nullptr;
					cout << "Выберите номер пункта: ";
					cin >> n;
					cin.get();
					switch (n--) {
					case 1:
						m[ch].scanBrd();
						writeln("\tУспешно");
						break;
					case 2:
						m[ch].scanMod();
						writeln("\tУспешно");
						break;
					case 3:
						m[ch].scanNum();
						writeln("\tУспешно");
						break;
					case 4:
						writeln("\tМарка: ", m[ch].getBrd());
						break;
					case 5:
						writeln("\tМодель: ", m[ch].getMod());
						break;
					case 6:
						writeln("\tНомер: ", m[ch].getNum());
						break;
					case 7:
						m[ch].clearBrd();
						writeln("\tУспешно");
						break;
					case 8:
						m[ch].clearMod();
						writeln("\tУспешно");
						break;
					case 9:
						m[ch].clearNum();
						writeln("\tУспешно");
						break;
					case 10:
						m[ch].print();
						break;
					case 11:
						flag = false;
						break;
					}
					delete[] str;
					cout << '\n';
				}
				flag = true;
			}
			else {
				print(m, l);
			}
			break;
		case 4:
			print(m, l);
			break;
		case 5:
			flag = false;
			break;
		}
		cout << endl;
	}
	return m;
}

template <typename T>
void print(T *obj, int l) {
	cout << "\n\tПолный список: ";
	if (!l) cout << "отсутствует";
	else cout << endl;
	for (int i = 0; i < l; ++i) {
		cout << '(' << i << ')';
		obj[i].print();
	}
	cout << endl;
}
template <typename T>
int choose(T *obj, int l) {
	int ch;
	print(obj, l);
	cout << "Выберите номер объекта(0~N): ";
	cin >> ch;
	cin.get();
	if (ch >= l)
		throw exceptions("Непоподание в диапазон значений\n");
	return ch;
}