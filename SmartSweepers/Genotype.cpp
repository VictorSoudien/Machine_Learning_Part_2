#include "Genotype.h"


Genotype::Genotype(void): fitness(-1)
{
}

Genotype::Genotype(std::vector<float> weights) : ANNweights(weights)
{
}

Genotype::~Genotype(void)
{
}

// Set the fitness of this genotype
void Genotype::setFitness(float fit)
{
	fitness = fit;
}