#pragma once

class Perceptron
{
	private:
		// Only need two weights since only two inputs per perceptron are accepted in this implementation
		float threshold, weight1, weight2, learningRate;
		
	public:

		Perceptron();
		// Set threshold, learningRate and initial weights
		Perceptron (float t, float learnRate, float w1, float w2);
		
		// Adjust weights if necessary based on inputs and required outputs
		void train(float input1, float input2, float targetOutput);
		
		// Classify the given input values
		int classify (float input1, float input2);
};

