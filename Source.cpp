#include "usrmenu.h"




int main() {
	int ch;
	int lenF = 0,
		lenM = 0,
		lenW = 0;
	bool flag = true;
	Keeper *k = new Keeper();
	setlocale(LC_ALL, "Russian");

	std::cout << "Считать файл бызы?(1 - y/0 - n) ";
	std::cin >> ch;
	std::cin.get();
	try {
		if (ch) k->LoadBaseFile();
	}
	catch (exceptions &e) {
		std::cout << e.what() << std::endl;
	}

	while (flag) {
		writeln("1. Мебель");
		writeln("2. Работники");
		writeln("3. Машины");
		writeln("4. Выход");
		std::cout << "Введите номер пункта: ";
		std::cin >> ch;
		std::cin.get();
		std::cout << std::endl;
		switch (ch) {
		case 1:
			menu_f(k);
			break;
		case 2:
			menu_w(k);
			break;
		case 3:
			menu_m(k);
			break;
		case 4:
			flag = false;
			break;
		}
		std::cout << std::endl;
	}

	std::cout << "Сохранить изменения?(1 - y/0 - n) ";
	std::cin >> ch;
	std::cin.get();
	try {
		if (ch) k->SaveBaseFile();
	}
	catch (exceptions &e) {
		std::cout << e.what() << std::endl;
	}
	delete k;
	return 0;
}

