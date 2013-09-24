#include "ANN.h"

#include <vector>
#include <math.h>


float Node::getOutputValue()
{
	return output;
}

void Node::set(float value)
{
	output = value;
}

void Node::attachNode (Node * n, float weight)
{
	// Add node to network with its weight from Evolutionary algorithm
	toLeft.push_back(n);
	weights.push_back(weight); 
	NodesToLeft++;
}

float Node::calculateOutput()
{
	float netInput = 0;
			
	// Sum of input & weight of nodes - used to compute the sigmoid function
	for (int i = 0; i < NodesToLeft; ++i)
	{
		netInput += (toLeft[i]->getOutputValue() * weights[i]);
	}
	
	// Calculate the sigmoid function
	output = 1.0 / (1 + exp (-netInput));
			
	return output;
}

NeuralNetwork::NeuralNetwork()
{
	input_d = new Node(); // Inputs from minesweepers
	input_theta = new Node();

	outputNode = new Node(); // One output - the rotation force

	hiddenNode1 = new Node();	// 3 Hidden layers
	hiddenNode2 = new Node();
	hiddenNode3 = new Node();
}

NeuralNetwork::NeuralNetwork(std::vector<float> genotype)
{
	// Construct the neural network 
	input_d = new Node(); // Inputs from minesweepers
	input_theta = new Node();

	outputNode = new Node(); // One output - the rotation force

	hiddenNode1 = new Node();	// 3 Hidden layers
	hiddenNode2 = new Node();
	hiddenNode3 = new Node();


	// Attach appropriately with outputs from nodes on left - Feed forward
	hiddenNode1->attachNode(input_d, genotype[0]);
	hiddenNode1->attachNode(input_theta, genotype[1]);
	hiddenNode2->attachNode(input_d, genotype[2]);
	hiddenNode2->attachNode(input_theta, genotype[3]);
	hiddenNode3->attachNode(input_d, genotype[4]);
	hiddenNode3->attachNode(input_theta, genotype[5]);

	// The output node
	outputNode->attachNode(hiddenNode1, genotype[6]);
	outputNode->attachNode(hiddenNode2, genotype[7]);
	outputNode->attachNode(hiddenNode3, genotype[8]);
}

float NeuralNetwork::train(const float dist,const float theta)
{
	input_d->set(dist);
	input_theta->set(theta);

	hiddenNode1->calculateOutput();
	hiddenNode2->calculateOutput();
	hiddenNode3->calculateOutput();

	//outputNode->set(hiddenNode1->calculateOutput() + hiddenNode3->calculateOutput() + hiddenNode3->calculateOutput());

	return outputNode->calculateOutput();
}

