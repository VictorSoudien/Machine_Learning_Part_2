#pragma once

#include <vector>

class Genotype
{
public:
	std::vector<float> ANNweights;
	float fitness;

	Genotype(void);
	Genotype(std::vector<float> weights);
	~Genotype(void);

	void setFitness(float fit);
	friend bool operator<(const Genotype& lhs, const Genotype& rhs){return lhs.fitness < rhs.fitness;}
};

