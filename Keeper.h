#pragma once

#include "furniture.h"
#include "machine.h"
#include "worker.h"
#include "exceptions.h"

class Keeper {
public:
	enum {
		COUNT = 3
	};
	Keeper();
	~Keeper();
	void CreateObjectFactory(factory* ft, int N);
	void DeleteObjectFactory(int ftNum, int N);

	furniture* getFurniture() { return f; }
	machine* getMachine() { return m; }
	worker* getWorker() { return w; }
	int getLens(int trNum) { return lens[trNum]; }

	void SaveBaseFile();
	void LoadBaseFile();
private:
	furniture *f;
	worker *w;
	machine *m;
	int lens[COUNT];
};