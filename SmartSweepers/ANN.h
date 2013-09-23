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
	
	Node();  // for hidden and output nodes
	Node(float value);
	void setInput(float value);
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

	NeuralNetwork(){}
	NeuralNetwork(std::array<float, 9> genotype);
	float train(float dist, float theta);

};