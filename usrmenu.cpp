#include "usrmenu.h"

using std::cout;
using std::cin;
using std::endl;

void menu_f(Keeper* k) {
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

			ptr = new furniture();
			ptr->scanType();
			ptr->scanDim();
			ptr->scanCol();
			ptr->scanMat();
			ptr->scanPr();
			k->CreateObjectFactory(ptr, 0);
			delete ptr;
			break;
		case 2:
			if (k->getLens(0)) {
				try {
					ch = choose(k->getFurniture(), k->getLens(0));
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				k->DeleteObjectFactory(0, ch);
				writeln("Удаление завершено");
			}
			else {
				print(k->getFurniture(), k->getLens(0));
			}
			break;
		case 3:
			if (k->getLens(0)) {
				int n;
				char *str;
				try {
					ch = choose(k->getFurniture(), k->getLens(0));
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
						(k->getFurniture() + ch)->scanType();
						writeln("\tУспешно");
						break;
					case 2:
						(k->getFurniture() + ch)->scanDim();
						writeln("\tУспешно");
						break;
					case 3:
						(k->getFurniture() + ch)->scanCol();
						writeln("\tУспешно");
						break;
					case 4:
						(k->getFurniture() + ch)->scanMat();
						writeln("\tУспешно");
						break;
					case 5:
						(k->getFurniture() + ch)->scanPr();
						writeln("\tУспешно");
						break;
					case 6:
						str = read("\tВведите название цвета: ");
						(k->getFurniture() + ch)->addCol(str);
						writeln("\tУспешно");
						break;
					case 7:
						str = read("\tВведите название материала: ");
						(k->getFurniture() + ch)->addMat(str);
						writeln("\tУспешно");
						break;
					case 8:
						if ((k->getFurniture() + ch)->getCol()) {
							char *str2;;
							writeln("\tЦвета: ", (k->getFurniture() + ch)->getCol());
							str = read("Введите заменяемый цвет: ");
							str2 = read("Введите заменяющий цвет: ");
							if ((k->getFurniture() + ch)->replaceCol(str, str2))
								writeln("\tУспешно");
							else
								writeln("\tЦвет не присутствует в списке");
						}
						else
							writeln("\tСписок цветов пуст");
						break;
					case 9:
						if ((k->getFurniture() + ch)->getCol()) {
							char *str2;;
							writeln("\tЦвета: ", (k->getFurniture() + ch)->getCol());
							str = read("Введите заменяемый метериал: ");
							str2 = read("Введите заменяющий метериал: ");
							if ((k->getFurniture() + ch)->replaceCol(str, str2))
								writeln("\tУспешно");
							else
								writeln("\tМатериал не присутствует в списке");
						}
						else
							writeln("\tСписок материалов пуст");
						break;
					case 10:
						writeln("\tТип: ", (k->getFurniture() + ch)->getType());
						break;
					case 11: {
						const double *t = (k->getFurniture() + ch)->getDim();
						writeln("\tГабариты: ");
						writeln("\t\tВысота: ", t[0]);
						writeln("\t\tШирина: ", t[1]);
						writeln("\t\tГлубина: ", t[2]);
					}
						break;
					case 12:
						writeln("\tЦвета: ", (k->getFurniture() + ch)->getCol());
						break;
					case 13:
						writeln("\tМатериалы: ", (k->getFurniture() + ch)->getMat());
						break;
					case 14:
						writeln("\tЦена: ", (k->getFurniture() + ch)->getPr());
						break;
					case 15:
						(k->getFurniture() + ch)->clearType();
						writeln("\tУспешно");
						break;
					case 16:
						(k->getFurniture() + ch)->clearDim();
						writeln("\tУспешно");
						break;
					case 17:
						(k->getFurniture() + ch)->clearCol();
						writeln("\tУспешно");
						break;
					case 18:
						(k->getFurniture() + ch)->clearMat();
						writeln("\tУспешно");
						break;
					case 19:
						(k->getFurniture() + ch)->clearPr();
						writeln("\tУспешно");
						break;
					case 20:
						if ((k->getFurniture() + ch)->getCol()) {
							writeln("\tЦвета: ", (k->getFurniture() + ch)->getCol());
							str = read("Введите название цвета: ");
							if ((k->getFurniture() + ch)->removeCol(str))
								writeln("\tУспешно");
							else
								writeln("\tЦвет не присутствует в списке");
						}
						else
							writeln("\tСписок цветов пуст");
						break;
					case 21:
						if ((k->getFurniture() + ch)->getMat()) {
							writeln("\tМатериалы: ", (k->getFurniture() + ch)->getMat());
							str = read("Введите название материала: ");
							if ((k->getFurniture() + ch)->removeMat(str))
								writeln("\tУспешно");
							else
								writeln("\tМатериал не присутствует в списке");
						}
						else
							writeln("\tСписок материалов пуст");
						break;
					case 22:
						(k->getFurniture() + ch)->print();
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
			print(k->getFurniture(), k->getLens(0));
			}
			break;
		case 4:
			print(k->getFurniture(), k->getLens(0));
			break;
		case 5:
			flag = false;
			break;
		}
		cout << endl;
	}
}
void menu_w(Keeper* k) {
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
			
			ptr = new worker();
			ptr->scanName();
			ptr->scanPos();
			ptr->scanSal();
			ptr->scanAds();
			ptr->scanNum();
			k->CreateObjectFactory(ptr, 1);
			delete ptr;
			break;
		case 2:
			if (k->getLens(1)) {
				try {
					ch = choose(k->getWorker(), k->getLens(1));
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				k->DeleteObjectFactory(1, ch);
				writeln("Удаление завершено");
			}
			else {
				print(k->getWorker(), k->getLens(1));
			}
			break;
		case 3:
			if (k->getLens(1)) {
				int n;
				char *str;
				try {
					ch = choose(k->getWorker(), k->getLens(1));
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
						(k->getWorker() + ch)->scanName();
						writeln("\tУспешно");
						break;
					case 2:
						(k->getWorker() + ch)->scanPos();
						writeln("\tУспешно");
						break;
					case 3:
						(k->getWorker() + ch)->scanSal();
						writeln("\tУспешно");
						break;
					case 4:
						(k->getWorker() + ch)->scanAds();
						writeln("\tУспешно");
						break;
					case 5:
						(k->getWorker() + ch)->scanNum();
						writeln("\tУспешно");
						break;
					case 6:
						writeln("\tФИО: ", (k->getWorker() + ch)->getName());
						break;
					case 7:
						writeln("\tДолжность: ", (k->getWorker() + ch)->getPos());
						 break;
					case 8:
						writeln("\tЗП: ", (k->getWorker() + ch)->getSal());
						break;
					case 9:
						writeln("\tАдрес: ", (k->getWorker() + ch)->getAds());
						break;
					case 10:
						writeln("\tНомер телефона: ", (k->getWorker() + ch)->getNum());
						break;
					case 11:
						(k->getWorker() + ch)->clearName();
						writeln("\tУспешно");
						break;
					case 12:
						(k->getWorker() + ch)->clearPos();
						writeln("\tУспешно");
						break;
					case 13:
						(k->getWorker() + ch)->clearSal();
						writeln("\tУспешно");
						break;
					case 14:
						(k->getWorker() + ch)->clearAds();
						writeln("\tУспешно");
						break;
					case 15:
						(k->getWorker() + ch)->clearNum();
						writeln("\tУспешно");
						break;
					case 16:
						(k->getWorker() + ch)->print();
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
			print(k->getWorker(), k->getLens(1));
			}
			break;
		case 4:
			print(k->getWorker(), k->getLens(1));
			break;
		case 5:
			flag = false;
			break;
		}
		cout << endl;
	}
}
void menu_m(Keeper* k) {
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
		
			ptr = new machine();
			ptr->scanBrd();
			ptr->scanMod();
			ptr->scanNum();
			k->CreateObjectFactory(ptr, 2);
			delete ptr;
			break;
		case 2:
			if (k->getLens(2)) {
				try {
					ch = choose(k->getMachine(), k->getLens(2));
				}
				catch (exceptions e) {
					std::cout << e.what();
					break;
				}
				k->DeleteObjectFactory(2, ch);
				writeln("Удаление завершено");
			}
			else {
				print(k->getMachine(), k->getLens(2));
			}
			break;
		case 3:
			if (k->getLens(2)) {
				int n;
				char *str;
				try {
					ch = choose(k->getMachine(), k->getLens(2));
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
						(k->getMachine() + ch)->scanBrd();
						writeln("\tУспешно");
						break;
					case 2:
						(k->getMachine() + ch)->scanMod();
						writeln("\tУспешно");
						break;
					case 3:
						(k->getMachine() + ch)->scanNum();
						writeln("\tУспешно");
						break;
					case 4:
						writeln("\tМарка: ", (k->getMachine() + ch)->getBrd());
						break;
					case 5:
						writeln("\tМодель: ", (k->getMachine() + ch)->getMod());
						break;
					case 6:
						writeln("\tНомер: ", (k->getMachine() + ch)->getNum());
						break;
					case 7:
						(k->getMachine() + ch)->clearBrd();
						writeln("\tУспешно");
						break;
					case 8:
						(k->getMachine() + ch)->clearMod();
						writeln("\tУспешно");
						break;
					case 9:
						(k->getMachine() + ch)->clearNum();
						writeln("\tУспешно");
						break;
					case 10:
						(k->getMachine() + ch)->print();
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
				print(k->getMachine(), k->getLens(2));
			}
			break;
		case 4:
			print(k->getMachine(), k->getLens(2));
			break;
		case 5:
			flag = false;
			break;
		}
		cout << endl;
	}
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