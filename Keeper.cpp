#include "Keeper.h"
#include "exceptions.h"
#include <fstream>

using std::cout;
using std::cin;
using std::endl;
using std::ifstream;
using std::ofstream;

#define PATH "D:/tc/TP/1l/Т_P_TWO/dev.txt"

Keeper::Keeper() : f(nullptr), m(nullptr), w(nullptr) {
	for (int i = 0; i < COUNT; ++i)
		lens[i] = 0;
}
Keeper::~Keeper() {
	delete[] f;
	delete[] m;
	delete[] w;
}

void Keeper::CreateObjectFactory(factory* ft, int N) {
	int i;
	furniture *furn = nullptr;
	machine *mach = nullptr;
	worker *work = nullptr;
	switch (N) {
	case 0:
		furn = new furniture[lens[0] + 1];
		for (i = 0; i < lens[0]; ++i) {
			furn[i] = *(f + i);
		}
		delete[] f;
		f = furn;
		if (ft) f[lens[0]] = (*(furniture*)(ft));
		++lens[0];
		break;
	case 1:
		work = new worker[lens[1] + 1];
		for (i = 0; i < lens[1]; ++i) {
			work[i] = *(w + i);
		}
		delete[] w;
		w = work;
		if (ft) w[lens[1]] = (*(worker*)(ft));
		++lens[1];
		break;
	case 2:
		mach = new machine[lens[2] + 1];
		for (i = 0; i < lens[2]; ++i) {
			mach[i] = *(m + i);
		}
		delete[] m;
		m = mach;
		if (ft) m[lens[2]] = (*(machine*)(ft));
		++lens[2];
		break;
	}
}
void Keeper::DeleteObjectFactory(int trNum, int dec) {
	int i;
	furniture *furn = nullptr;
	machine *mach = nullptr;
	worker *work = nullptr;
	switch (trNum) {
	case 0:
		furn = new furniture[lens[0] - 1];
		for (i = 0; i < dec; ++i) {
			furn[i] = f[i];
		}
		for (++i; i < lens[0]; ++i) {
			furn[i - 1] = f[i];
		}
		delete[] f;
		f = furn;
		--lens[0];
		break;
	case 1:
		work = new worker[lens[1] - 1];
		for (i = 0; i < dec; ++i) {
			work[i] = w[i];
		}
		for (++i; i < lens[1]; ++i) {
			work[i - 1] = w[i];
		}
		delete[] w;
		w = work;
		--lens[1];
		break;
	case 2:
		mach = new machine[lens[2] - 1];
		for (i = 0; i < dec; ++i) {
			mach[i] = m[i];
		}
		for (++i; i < lens[2]; ++i) {
			mach[i - 1] = m[i];
		}
		delete[] m;
		m = mach;
		--lens[2];
		break;
	}
}

void Keeper::SaveBaseFile() {
	int i, j;
	ofstream out(PATH);
	exceptions e("Файл не был открыт");
	if (!out.is_open()) {
		throw e;
	}
	for (i = 0; i < lens[0]; ++i) {
		if (f[i].getType())
			out << f[i].getType() << ';';
		else
			out << '\0' << ';';
		for (j = 0; j < furniture::N; ++j) {
			if (*(f[i].getDim() + j))
				out << *(f[i].getDim() + j) << ';';
			else
				out << '\0' << ';';
		}
		if (f[i].getCol())
			out << f[i].getCol() << ';';
		else
			out << '\0' << ';';
		if (f[i].getMat())
			out << f[i].getMat() << ';';
		else
			out << '\0' << ';';
		if (f[i].getPr())
			out << f[i].getPr() << ';';
		else
			out << '\0' << ';';
		out << endl;
	}
	out << endl;
	for (i = 0; i < lens[1]; ++i) {
		if (w[i].getName())
			out << w[i].getName() << ';';
		else
			out << '\0' << ';';
		if (w[i].getPos())
			out << w[i].getPos() << ';';
		else
			out << '\0' << ';';
		if (w[i].getSal())
			out << w[i].getSal() << ';';
		else
			out << '\0' << ';';
		if (w[i].getAds())
			out << w[i].getAds() << ';';
		else
			out << '\0' << ';';
		if (w[i].getNum())
			out << w[i].getNum() << ';';
		else
			out << '\0' << ';';
		out << endl;
	}
	out << endl;
	for (i = 0; i < lens[2]; ++i) {
		if (m[i].getBrd())
			out << m[i].getBrd() << ';';
		else
			out << '\0' << ';';
		if (m[i].getMod())
			out << m[i].getMod() << ';';
		else
			out << '\0' << ';';
		if (m[i].getNum())
			out << m[i].getNum() << ';';
		else
			out << '\0' << ';';
		out << endl;
	}
	out.close();
}
void Keeper::LoadBaseFile() {
	int i, j, k;
	int n;
	char* str;
	char* tmp;
	ifstream in(PATH);
	exceptions e("Файл не был открыт");
	if (!in.is_open()) {
		throw e;
	}
	for (i = 0; 1; ++i) {
		str = read(in);
		if (!str) {
			in.close();
			return;
		}
		if (str[0] != '\n') {
			CreateObjectFactory(nullptr, 0);

			for (k = 0; str[k] != ';'; ++k);
			n = k;
			tmp = new char[n + 1];
			strcopy(tmp, str, 0, n);
			tmp[n] = '\0';
			f[lens[0] - 1].setType(tmp);
			delete[] tmp;

			double d[furniture::N];
			for (int t = 0; t < furniture::N; ++t) {
				j = ++k;
				for (; str[k] != ';'; ++k);
				n = k - j;
				tmp = new char[n + 1];
				strcopy(tmp, str, j, k);
				tmp[n] = '\0';
				d[t] = strdbl(tmp);
				delete[] tmp;
			}
			f[lens[0] - 1].setDim(d);

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			f[lens[0] - 1].setCol(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			f[lens[0] - 1].setMat(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			f[lens[0] - 1].setPr(strdbl(tmp));
			delete[] tmp;

			delete[] str;
		}
		else {
			delete[] str;
			break;
		}
	}
	for (i = 0; 1; ++i) {
		str = read(in);
		if (!str) {
			in.close();
			return;
		}
		if (str[0] != '\n') {
			CreateObjectFactory(nullptr, 1);

			for (k = 0; str[k] != ';'; ++k);
			n = k;
			tmp = new char[n + 1];
			strcopy(tmp, str, 0, n);
			tmp[n] = '\0';
			w[lens[1] - 1].setName(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			w[lens[1] - 1].setPos(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			w[lens[1] - 1].setSal(strdbl(tmp));
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			w[lens[1] - 1].setAds(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			w[lens[1] - 1].setNum(tmp);
			delete[] tmp;

			delete[] str;
		}
		else {
			delete[] str;
			break;
		}
	}
	for (i = 0; 1; ++i) {
		str = read(in);
		if (!str) {
			in.close();
			return;
		}
		if (str[0] != '\n') {
			CreateObjectFactory(nullptr, 2);

			for (k = 0; str[k] != ';'; ++k);
			n = k;
			tmp = new char[n + 1];
			strcopy(tmp, str, 0, k);
			tmp[n] = '\0';
			m[lens[2] - 1].setBrd(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			m[lens[2] - 1].setMod(tmp);
			delete[] tmp;

			j = ++k;
			for (; str[k] != ';'; ++k);
			n = k - j;
			tmp = new char[n + 1];
			strcopy(tmp, str, j, k);
			tmp[n] = '\0';
			m[lens[2] - 1].setNum(tmp);
			delete[] tmp;

			delete[] str;
		}
		else {
			delete[] str;
			break;
		}

	}
	in.close();
}