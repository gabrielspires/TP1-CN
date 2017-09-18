#ifndef TP1_INDIVIDUO_
#define TP1_INDIVIDUO_

#include "dependencies.h"
#include "Tree.h"

class Individual{
public:
	Individual();
	~Individual();

	double fitness;
	bool isElite;
	Tree genotype;

private:
	Tree generateGenotype();
};

#endif