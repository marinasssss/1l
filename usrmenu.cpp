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
		writeln(" (1) �������� ������");
		writeln(" (2) ������� ������");
		writeln(" (3) ������� ������ ��� ��������� �� ����������");
		writeln(" (4) ������� ������ ���������� �� ��������� ������");
		writeln(" (5) �����");
		cout << "�������� ����� ������: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			writeln("��� ������ �������� ��������� �������� ������ ������� enter");
			writeln("���� �������� ��������, �� ������� \"0\"");
			writeln("�������-�����������: ", SEPARATORS);

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
				writeln("�������� ���������");
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
				writeln(" #1 ������ ����� ���");
				writeln(" #2 ������ ����� ��������");
				writeln(" #3 ������ ����� �����");
				writeln(" #4 ������ ����� ���������");
				writeln(" #5 ������ ����� ���������");
				writeln(" #6 �������� ����� ����");
				writeln(" #7 �������� ����� ��������");
				writeln(" #8 ��������� ���� �� ������");
				writeln(" #9 ��������� ���� �� ����������");
				writeln("#10 ������� �� ����� ���");
				writeln("#11 ������� �� ����� ��������");
				writeln("#12 ������� �� ����� �����");
				writeln("#13 ������� �� ����� ���������");
				writeln("#14 ������� �� ����� ��������");
				writeln("#15 ��������� ���� ����");
				writeln("#16 ��������� ���� ��������");
				writeln("#17 ��������� ���� �����");
				writeln("#18 ��������� ���� ���������");
				writeln("#19 ��������� ���� ����");
				writeln("#20 ������� ���� �� ������");
				writeln("#21 ������� ���� �� ����������");
				writeln("#22 ����� ����������");
				writeln("#23 �����");
				while (flag) {
					str = nullptr;
					cout << "�������� ����� ������: ";
					cin >> n;
					cin.get();
					switch (n--) {
					case 1:
						(k->getFurniture() + ch)->scanType();
						writeln("\t�������");
						break;
					case 2:
						(k->getFurniture() + ch)->scanDim();
						writeln("\t�������");
						break;
					case 3:
						(k->getFurniture() + ch)->scanCol();
						writeln("\t�������");
						break;
					case 4:
						(k->getFurniture() + ch)->scanMat();
						writeln("\t�������");
						break;
					case 5:
						(k->getFurniture() + ch)->scanPr();
						writeln("\t�������");
						break;
					case 6:
						str = read("\t������� �������� �����: ");
						(k->getFurniture() + ch)->addCol(str);
						writeln("\t�������");
						break;
					case 7:
						str = read("\t������� �������� ���������: ");
						(k->getFurniture() + ch)->addMat(str);
						writeln("\t�������");
						break;
					case 8:
						if ((k->getFurniture() + ch)->getCol()) {
							char *str2;;
							writeln("\t�����: ", (k->getFurniture() + ch)->getCol());
							str = read("������� ���������� ����: ");
							str2 = read("������� ���������� ����: ");
							if ((k->getFurniture() + ch)->replaceCol(str, str2))
								writeln("\t�������");
							else
								writeln("\t���� �� ������������ � ������");
						}
						else
							writeln("\t������ ������ ����");
						break;
					case 9:
						if ((k->getFurniture() + ch)->getCol()) {
							char *str2;;
							writeln("\t�����: ", (k->getFurniture() + ch)->getCol());
							str = read("������� ���������� ��������: ");
							str2 = read("������� ���������� ��������: ");
							if ((k->getFurniture() + ch)->replaceCol(str, str2))
								writeln("\t�������");
							else
								writeln("\t�������� �� ������������ � ������");
						}
						else
							writeln("\t������ ���������� ����");
						break;
					case 10:
						writeln("\t���: ", (k->getFurniture() + ch)->getType());
						break;
					case 11: {
						const double *t = (k->getFurniture() + ch)->getDim();
						writeln("\t��������: ");
						writeln("\t\t������: ", t[0]);
						writeln("\t\t������: ", t[1]);
						writeln("\t\t�������: ", t[2]);
					}
						break;
					case 12:
						writeln("\t�����: ", (k->getFurniture() + ch)->getCol());
						break;
					case 13:
						writeln("\t���������: ", (k->getFurniture() + ch)->getMat());
						break;
					case 14:
						writeln("\t����: ", (k->getFurniture() + ch)->getPr());
						break;
					case 15:
						(k->getFurniture() + ch)->clearType();
						writeln("\t�������");
						break;
					case 16:
						(k->getFurniture() + ch)->clearDim();
						writeln("\t�������");
						break;
					case 17:
						(k->getFurniture() + ch)->clearCol();
						writeln("\t�������");
						break;
					case 18:
						(k->getFurniture() + ch)->clearMat();
						writeln("\t�������");
						break;
					case 19:
						(k->getFurniture() + ch)->clearPr();
						writeln("\t�������");
						break;
					case 20:
						if ((k->getFurniture() + ch)->getCol()) {
							writeln("\t�����: ", (k->getFurniture() + ch)->getCol());
							str = read("������� �������� �����: ");
							if ((k->getFurniture() + ch)->removeCol(str))
								writeln("\t�������");
							else
								writeln("\t���� �� ������������ � ������");
						}
						else
							writeln("\t������ ������ ����");
						break;
					case 21:
						if ((k->getFurniture() + ch)->getMat()) {
							writeln("\t���������: ", (k->getFurniture() + ch)->getMat());
							str = read("������� �������� ���������: ");
							if ((k->getFurniture() + ch)->removeMat(str))
								writeln("\t�������");
							else
								writeln("\t�������� �� ������������ � ������");
						}
						else
							writeln("\t������ ���������� ����");
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
		writeln(" (1) �������� ���������");
		writeln(" (2) ������� ���������");
		writeln(" (3) ������� ��������� ��� ��������� ��� ����������");
		writeln(" (4) ������� ������ ���������� �� ���������� ����������");
		writeln(" (5) �����");
		cout << "�������� ����� ������: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			writeln("��� ������ �������� ��������� �������� ������ ������� enter");
			writeln("���� �������� ��������, �� ������� \"0\"");
			writeln("�������-�����������: ", SEPARATORS);
			
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
				writeln("�������� ���������");
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
				writeln(" #1 ������ ����� ���");
				writeln(" #2 ������ ����� ���������");
				writeln(" #3 ������ ����� ��");
				writeln(" #4 ������ ����� �����");
				writeln(" #5 ������ ����� �����");
				writeln(" #6 ������� �� ����� ���");
				writeln(" #7 ������� �� ����� ���������");
				writeln(" #8 ������� �� ����� ��");
				writeln(" #9 ������� �� ����� �����");
				writeln("#10 ������� �� ����� �����");
				writeln("#11 ��������� ���� ���");
				writeln("#12 ��������� ���� ���������");
				writeln("#13 ��������� ���� ��");
				writeln("#14 ��������� ���� ������");
				writeln("#15 ��������� ���� ������");
				writeln("#16 ����� ����������");
				writeln("#17 �����");
				while (flag) {
					str = nullptr;
					cout << "�������� ����� ������: ";
					cin >> n;
					cin.get();
					switch (n--) {
					case 1:
						(k->getWorker() + ch)->scanName();
						writeln("\t�������");
						break;
					case 2:
						(k->getWorker() + ch)->scanPos();
						writeln("\t�������");
						break;
					case 3:
						(k->getWorker() + ch)->scanSal();
						writeln("\t�������");
						break;
					case 4:
						(k->getWorker() + ch)->scanAds();
						writeln("\t�������");
						break;
					case 5:
						(k->getWorker() + ch)->scanNum();
						writeln("\t�������");
						break;
					case 6:
						writeln("\t���: ", (k->getWorker() + ch)->getName());
						break;
					case 7:
						writeln("\t���������: ", (k->getWorker() + ch)->getPos());
						 break;
					case 8:
						writeln("\t��: ", (k->getWorker() + ch)->getSal());
						break;
					case 9:
						writeln("\t�����: ", (k->getWorker() + ch)->getAds());
						break;
					case 10:
						writeln("\t����� ��������: ", (k->getWorker() + ch)->getNum());
						break;
					case 11:
						(k->getWorker() + ch)->clearName();
						writeln("\t�������");
						break;
					case 12:
						(k->getWorker() + ch)->clearPos();
						writeln("\t�������");
						break;
					case 13:
						(k->getWorker() + ch)->clearSal();
						writeln("\t�������");
						break;
					case 14:
						(k->getWorker() + ch)->clearAds();
						writeln("\t�������");
						break;
					case 15:
						(k->getWorker() + ch)->clearNum();
						writeln("\t�������");
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
		writeln(" (1) �������� ������");
		writeln(" (2) ������� ������");
		writeln(" (3) ������� ������ ��� ��������� ��� ����������");
		writeln(" (4) ������� ������ ���������� �� ���������� �������");
		writeln(" (5) �����");
		cout << "�������� ����� ������: ";
		cin >> ch;
		cin.get();
		switch (ch) {
		case 1:
			writeln("��� ������ �������� ��������� �������� ������ ������� enter");
			writeln("���� �������� ��������, �� ������� \"0\"");
			writeln("�������-�����������: ", SEPARATORS);
		
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
				writeln("�������� ���������");
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
				writeln(" #1 ������ ����� �����");
				writeln(" #2 ������ ����� ������");
				writeln(" #3 ������ ����� ���.�����");
				writeln(" #4 ������� �� �����");
				writeln(" #5 ������� �� ������");
				writeln(" #6 ������� �� ���.�����");
				writeln(" #7 ��������� ���� �����");
				writeln(" #8 ��������� ���� ������");
				writeln(" #9 ��������� ���� ���.������");
				writeln("#10 ����� ����������");
				writeln("#11 �����");
				while (flag) {
					str = nullptr;
					cout << "�������� ����� ������: ";
					cin >> n;
					cin.get();
					switch (n--) {
					case 1:
						(k->getMachine() + ch)->scanBrd();
						writeln("\t�������");
						break;
					case 2:
						(k->getMachine() + ch)->scanMod();
						writeln("\t�������");
						break;
					case 3:
						(k->getMachine() + ch)->scanNum();
						writeln("\t�������");
						break;
					case 4:
						writeln("\t�����: ", (k->getMachine() + ch)->getBrd());
						break;
					case 5:
						writeln("\t������: ", (k->getMachine() + ch)->getMod());
						break;
					case 6:
						writeln("\t�����: ", (k->getMachine() + ch)->getNum());
						break;
					case 7:
						(k->getMachine() + ch)->clearBrd();
						writeln("\t�������");
						break;
					case 8:
						(k->getMachine() + ch)->clearMod();
						writeln("\t�������");
						break;
					case 9:
						(k->getMachine() + ch)->clearNum();
						writeln("\t�������");
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
	cout << "\n\t������ ������: ";
	if (!l) cout << "�����������";
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
	cout << "�������� ����� �������(0~N): ";
	cin >> ch;
	cin.get();
	if (ch >= l)
		throw exceptions("����������� � �������� ��������\n");
	return ch;
}