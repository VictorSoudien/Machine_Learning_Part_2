#include "Evo.h"
#include "utils.h"
#include <algorithm>
#include <array>

Evo::Evo(int numParents)
{
	populationLimit = numParents;

	for (int i = 0; i < populationLimit; i++)
	{
		std::array<float, 9> genotype;

		for (int g = 0; g < 9; g++)
		{
			float randomNumber = RandFloat();
			genotype[g] = randomNumber;
		}

		population.push_back(genotype);
	}
}


Evo::~Evo(void)
{
}

bool Evo::comparator(const fitnessValues& l, const fitnessValues& r)
{
	return (l.first < r.first);
}

std::vector<std::pair<float,int>> Evo::selectBest()
{
	std::vector<fitnessValues> fittestCandidates;

	std::vector<fitnessValues> tempFitness;

	std::sort(fitnessVals.begin(), tempFitness.begin());

	// Select the 50 fittest candidates
	std::vector<fitnessValues>::iterator fitIter = tempFitness.begin();

	for (int i = 0; i < (populationLimit / 2); i++)
	{
		fittestCandidates.push_back(*fitIter);
		++fitIter;
	}

	return fittestCandidates;
}

void Evo::crossover()
{
	float crossoverProb = 40;

	int p1 = 0;
	int p2 = population.size() / 2;

	while (population.size() != populationLimit)
	{
		std::array<float, 9> geno1 = population.at(p1);
		std::array<float, 9> geno2 = population.at(p2);

		std::array<float, 9> childGeno;

		for (int i = 0; i < geno1.size(); i++)
		{
			float random = RandInt(0, 100);

			if (random < crossoverProb)
			{
				childGeno[i] = (geno1[i] + geno2[i]) / 2;
			}
			else
			{
				childGeno[i] = geno1[i];
			}
		}

		population.push_back(childGeno);
		p1++;
		p2++;
	}
}

std::array<float, 9> Evo::getGenotype(int i)
{
	return population.at(i);
}
