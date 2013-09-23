#include "perceptron.h";

Perceptron::Perceptron(float t, float learnRate, float w1, float w2)
{
	threshold = t;
	learningRate = learnRate;
			
	weight1 = w1;
	weight2 = w2;
}

void Perceptron::train(float input1, float input2, float targetOutput)
{
	float linearRule = threshold + (weight1 * input1) + (weight2 * input2);
	int output = (linearRule > 0) ? 1 : 0; // output is 1 if linearRule is greater than 0
			
	// Weights need to be adjusted if the output was incorrect
	if (output != targetOutput)
	{
		weight1 += learningRate * (targetOutput - output) * input1;
		weight2 += learningRate * (targetOutput - output) * input2;
	}
}

int Perceptron::classify(float input1, float input2)
{
	float linearRule = threshold + (weight1 * input1) + (weight2 * input2);
	int output = (linearRule > 0) ? 1 : 0; // output is 1 if linearRule is greater than 0
			
	return output;
}
