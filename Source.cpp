#include "usrmenu.h"




int main() {
	int ch;
	int lenF = 0,
		lenM = 0,
		lenW = 0;
	bool flag = true;
	furniture *f = nullptr;
	machine *m = nullptr;
	worker *w = nullptr;
	setlocale(LC_ALL, "Russian");
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
			f = menu(f, lenF);
			break;
		case 2:
			w = menu(w, lenW);
			break;
		case 3:
			m = menu(m, lenM);
			break;
		case 4:
			flag = false;
			break;
		}
		std::cout << std::endl;
	}
	delete[] f;
	delete[] m;
	delete[] w;
	return 0;
}

