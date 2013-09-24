#pragma once

#include <vector>
#include <math.h>
#include <array>
using namespace std;
class Node
{
public:
	float output;
	int NodesToLeft;
	vector<Node*> toLeft; // All the nodes that serve as input to this node
	vector<float> weights; // The weight associated with each toLeft node
	
public:
	Node()
		:output(0){}  // for hidden and output nodes

	void set(float value);
	float getOutputValue();
	void attachNode(Node * n , float weight);
	float calculateOutput();
};

class NeuralNetwork
{
public:
	Node * input_d;
	Node * input_theta;
	Node * outputNode;
	Node * hiddenNode1;
	Node * hiddenNode2;
	Node * hiddenNode3;

	NeuralNetwork();
	NeuralNetwork(std::vector<float> genotype);
	float train(const float dist, const float theta);

};