#pragma once

#include <vector>
#include "Genotype.h"

class EvoAlgorithm
{
public:
	std::vector<Genotype> population;
	int populationSize;
	int genotypeLength;

	EvoAlgorithm(void);
	EvoAlgorithm(int popSize, int genoLength);
	~EvoAlgorithm(void);

	void selectBest();
	void doOneIteration();
	void performCrossover();
	void performMutation();
	void changeFitness(int index, float change);
	void resetFitness();
};

