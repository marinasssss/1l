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
				writeln("�������� ���������");
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
						f[ch].scanType();
						writeln("\t�������");
						break;
					case 2:
						f[ch].scanDim();
						writeln("\t�������");
						break;
					case 3:
						f[ch].scanCol();
						writeln("\t�������");
						break;
					case 4:
						f[ch].scanMat();
						writeln("\t�������");
						break;
					case 5:
						f[ch].scanPr();
						writeln("\t�������");
						break;
					case 6:
						str = read("\t������� �������� �����: ");
						f[ch].addCol(str);
						writeln("\t�������");
						break;
					case 7:
						str = read("\t������� �������� ���������: ");
						f[ch].addMat(str);
						writeln("\t�������");
						break;
					case 8:
						if (f[ch].getCol()) {
							char *str2;;
							writeln("\t�����: ", f[ch].getCol());
							str = read("������� ���������� ����: ");
							str2 = read("������� ���������� ����: ");
							if (f[ch].replaceCol(str, str2))
								writeln("\t�������");
							else
								writeln("\t���� �� ������������ � ������");
						}
						else
							writeln("\t������ ������ ����");
						break;
					case 9:
						if (f[ch].getCol()) {
							char *str2;;
							writeln("\t�����: ", f[ch].getCol());
							str = read("������� ���������� ��������: ");
							str2 = read("������� ���������� ��������: ");
							if (f[ch].replaceCol(str, str2))
								writeln("\t�������");
							else
								writeln("\t�������� �� ������������ � ������");
						}
						else
							writeln("\t������ ���������� ����");
						break;
					case 10:
						writeln("\t���: ", f[ch].getType());
						break;
					case 11: {
						const double *t = f[ch].getDim();
						writeln("\t��������: ");
						writeln("\t\t������: ", t[0]);
						writeln("\t\t������: ", t[1]);
						writeln("\t\t�������: ", t[2]);
					}
						break;
					case 12:
						writeln("\t�����: ", f[ch].getCol());
						break;
					case 13:
						writeln("\t���������: ", f[ch].getMat());
						break;
					case 14:
						writeln("\t����: ", f[ch].getPr());
						break;
					case 15:
						f[ch].clearType();
						writeln("\t�������");
						break;
					case 16:
						f[ch].clearDim();
						writeln("\t�������");
						break;
					case 17:
						f[ch].clearCol();
						writeln("\t�������");
						break;
					case 18:
						f[ch].clearMat();
						writeln("\t�������");
						break;
					case 19:
						f[ch].clearPr();
						writeln("\t�������");
						break;
					case 20:
						if (f[ch].getCol()) {
							writeln("\t�����: ", f[ch].getCol());
							str = read("������� �������� �����: ");
							if (f[ch].removeCol(str))
								writeln("\t�������");
							else
								writeln("\t���� �� ������������ � ������");
						}
						else
							writeln("\t������ ������ ����");
						break;
					case 21:
						if (f[ch].getMat()) {
							writeln("\t���������: ", f[ch].getMat());
							str = read("������� �������� ���������: ");
							if (f[ch].removeMat(str))
								writeln("\t�������");
							else
								writeln("\t�������� �� ������������ � ������");
						}
						else
							writeln("\t������ ���������� ����");
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
				writeln("�������� ���������");
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
						w[ch].scanName();
						writeln("\t�������");
						break;
					case 2:
						w[ch].scanPos();
						writeln("\t�������");
						break;
					case 3:
						w[ch].scanSal();
						writeln("\t�������");
						break;
					case 4:
						w[ch].scanAds();
						writeln("\t�������");
						break;
					case 5:
						w[ch].scanNum();
						writeln("\t�������");
						break;
					case 6:
						writeln("\t���: ", w[ch].getName());
						break;
					case 7:
						writeln("\t���������: ", w[ch].getPos());
						 break;
					case 8:
						writeln("\t��: ", w[ch].getSal());
						break;
					case 9:
						writeln("\t�����: ", w[ch].getAds());
						break;
					case 10:
						writeln("\t����� ��������: ", w[ch].getNum());
						break;
					case 11:
						w[ch].clearName();
						writeln("\t�������");
						break;
					case 12:
						w[ch].clearPos();
						writeln("\t�������");
						break;
					case 13:
						w[ch].clearSal();
						writeln("\t�������");
						break;
					case 14:
						w[ch].clearAds();
						writeln("\t�������");
						break;
					case 15:
						w[ch].clearNum();
						writeln("\t�������");
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
				writeln("�������� ���������");
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
						m[ch].scanBrd();
						writeln("\t�������");
						break;
					case 2:
						m[ch].scanMod();
						writeln("\t�������");
						break;
					case 3:
						m[ch].scanNum();
						writeln("\t�������");
						break;
					case 4:
						writeln("\t�����: ", m[ch].getBrd());
						break;
					case 5:
						writeln("\t������: ", m[ch].getMod());
						break;
					case 6:
						writeln("\t�����: ", m[ch].getNum());
						break;
					case 7:
						m[ch].clearBrd();
						writeln("\t�������");
						break;
					case 8:
						m[ch].clearMod();
						writeln("\t�������");
						break;
					case 9:
						m[ch].clearNum();
						writeln("\t�������");
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