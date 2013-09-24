#include "EvoAlgorithm.h"
#include "utils.h"
#include <algorithm>

EvoAlgorithm::EvoAlgorithm(void)
{
}

EvoAlgorithm::EvoAlgorithm(int popSize, int genoLength):populationSize(popSize), genotypeLength(genoLength)
{
	// Randomly initialise the population
	for (int i = 0; i < populationSize; i++)
	{

		Genotype geno = *(new Genotype());

		for (int g = 0; g < genotypeLength; g++)
		{
			float randomWeight = RandomClamped();

			geno.ANNweights.push_back(randomWeight);
		}

		population.push_back(geno);
	}
}

EvoAlgorithm::~EvoAlgorithm(void)
{
}

// Select the top half of the population
void EvoAlgorithm::selectBest()
{
	std::vector<Genotype> temp;

	for (int i = 0; i < (populationSize / 2); i++)
	{
		temp.push_back(population[i]);
	}

	population = temp;
}

// Create offspring from current parents to fill the population
void EvoAlgorithm::performCrossover()
{
	while (population.size() != populationSize)
	{
		// Cross random parents
		Genotype parent1 = population.at(RandInt(0, population.size() - 1));
		Genotype parent2 = population.at(RandInt(0, population.size() - 1));

		std::vector<float> child1Weights;
		std::vector<float> child2Weights;

		int crossoverPoint = RandInt(0, genotypeLength - 1);

		for (int i = 0; i < crossoverPoint; i++)
		{
			child1Weights.push_back(parent1.ANNweights[i]);
			child2Weights.push_back(parent2.ANNweights[i]);
		}

		for (int z = crossoverPoint; z < genotypeLength; z++)
		{
			child1Weights.push_back(parent1.ANNweights[z]);
			child2Weights.push_back(parent2.ANNweights[z]);
		}

		Genotype child1 = *(new Genotype(child1Weights));
		Genotype child2 = *(new Genotype(child2Weights));
	}
}

// Mutate the currentPopulation
void EvoAlgorithm::performMutation()
{
	float probOfChosen = 0.6;
	float probOfMutation = 0.4;

	for (int i = 0; i < population.size(); i++)
	{
		if (RandFloat() <= probOfChosen)
		{
			for (int g = 0; g < genotypeLength; g++)
			{
				if (RandFloat() < probOfMutation)
				{
					population[i].ANNweights[g] += 0.1; 
				}
			}
		}
	}
}

// Change the fitness of a specific genotpye
void EvoAlgorithm::changeFitness(int index, float change)
{
	population[index].fitness += change;
}

// Reset the fitness of the genotypes from the old population
void EvoAlgorithm::resetFitness()
{
	for (int i = 0; i < (populationSize / 2); i++)
	{
		population[i].fitness = 0;
	}
}

void EvoAlgorithm::doOneIteration()
{
	//std::vector<Genotype> peviousGeneration = population;

	std::sort(population.begin(), population.end());
	selectBest();
	performCrossover();
	performMutation();

	resetFitness();
}