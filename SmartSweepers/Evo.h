#pragma once

#include <vector>
#include <array>

class Evo
{
public:
	// Variables
	typedef std::pair<float, int> fitnessValues;
	std::vector<std::array<float, 9>> population;
	std::vector<fitnessValues> fitnessVals;

	int populationLimit;
	Evo(){}
	Evo(int numParents);
	~Evo(void);

	bool comparator(const fitnessValues& l, const fitnessValues& r);
	std::vector<std::array<float, 9>> selectBest();
	void crossover();
	std::array<float, 9> getGenotype(int i);
	void addFitness(float fit, int index);
	void updateFitness(float fit, int index);
	void clearFitness();
};

