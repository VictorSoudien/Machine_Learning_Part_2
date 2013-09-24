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
		
		fitnessValues temp;
		temp.first = 0;
		temp.second = i;
		fitnessVals.push_back(temp);
	}
}


Evo::~Evo(void)
{
}

bool Evo::comparator(const fitnessValues& l, const fitnessValues& r)
{
	return (l.first < r.first);
}

std::vector<std::array<float, 9>> Evo::selectBest() 
{
	std::vector<std::array<float, 9>> fittestCandidates;

	std::vector<std::pair<float, int>> tempFitness(populationLimit);

	std::copy(fitnessVals.begin(), fitnessVals.end(), tempFitness.begin());
	std::sort(tempFitness.begin(), tempFitness.end());

	// Select the 50 fittest candidates
	std::vector<fitnessValues>::reverse_iterator fitIter = tempFitness.rbegin();

	for (int i = 0; i < (populationLimit / 2); i++)
	{
		fittestCandidates.push_back(population.at((*fitIter).second));
		++fitIter;
	}

	return fittestCandidates;
}

void Evo::crossover() 
{
	float crossoverProb = 40; // Cross over rate

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

void Evo::addFitness(float fit, int index)
{
	fitnessValues temp;
	temp.first = fit;
	temp.second = index;
	fitnessVals.push_back(temp);
}

void Evo::updateFitness(float fit, int index)
{
	fitnessVals[index].first = fit;
}

void Evo::clearFitness()
{
	fitnessVals.clear();

	for (int i = 0; i < populationLimit; i++)
	{
		fitnessValues temp;
		temp.first = 0;
		temp.second = i;
		fitnessVals.push_back(temp);
	}
}
