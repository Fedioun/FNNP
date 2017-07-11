#ifndef NEURON
#define NEURON

#include <cstdlib>
#include "ActivationFunctions.hpp"


class Neuron {
	private :
		Neuron ** inputs = NULL;
		double * weights = NULL;
		double threshold = 0;
		int inputSize = 0;
		int functionId = 0;
	public:

		Neuron(int functionId) {
			this->functionId = functionId;
		};

		Neuron(int inputSize, int functionId) {
			this->inputSize = inputSize;
			this->functionId = functionId;
			this->inputs = 		(Neuron**)malloc(inputSize * sizeof(Neuron*));
			this->weights =  	 (double*)malloc(inputSize * sizeof(double));

		};



		~Neuron() {
			free(inputs);
			free(weights);
		};

		/***
		 * 
		 */
		void connect(Neuron ** inputLayer, int size) {
			this->inputSize = inputSize;
			this->inputs = 		(Neuron**)malloc(inputSize * sizeof(Neuron*));
			this->weights =  	 (double*)malloc(inputSize * sizeof(double));
			for (int i = 0; i < inputSize ; i++) {
				this->inputs[i] = inputLayer[i];
			}
		}
};



#endif