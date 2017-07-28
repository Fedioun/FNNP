#ifndef NEURON
#define NEURON

#include <iostream>
#include <cstdlib>
#include "ActivationFunctions.hpp"
#include "Random.hpp"


class Neuron {
	private :
		int networkId = 	-1;
		int layerId = 		-1;
		int neuronId = 	-1;

	public:
		Neuron ** inputs = NULL;
		double * weights = NULL;
		double threshold = 0;
		double activation = 0;
		activFun activationFunction = NULL;
		int inputSize = 0;
		int functionId = 0;

	

		Neuron(int functionId) {
			this->activation = RandomGenerator::get_gaussian_noise(0.0,0.5);
			this->functionId = functionId;
			this->activationFunction = get_activation_fun(functionId);
		};

		Neuron(int inputSize, int functionId) {
			

			this->functionId = functionId;
			this->activationFunction = get_activation_fun(functionId);

			this->inputSize = inputSize;
			this->inputs = 		(Neuron**)malloc(inputSize * sizeof(Neuron*));
			this->weights =  	 (double*)malloc(inputSize * sizeof(double));

		};



		~Neuron() {
			#ifndef NDEBUG
				//std::cout  << "Neuronne détruit" << std::endl;
			#endif
			free(inputs);
			free(weights);
		};

		void set_activation(double activation) {
			this->activation = activation;
		}


		/***
		 * 
		 */
		void connect(Neuron ** inputLayer, int size) {
			this->inputSize = size;
			this->inputs = 		(Neuron**)malloc(inputSize * sizeof(Neuron*));
			this->weights =  	 (double*)malloc(inputSize * sizeof(double));
			for (int i = 0; i < inputSize ; i++) {
				this->inputs[i] = inputLayer[i];
				this->weights[i] = RandomGenerator::get_gaussian_noise(0.0,0.5);
			}
		}

		/***
		 * Compute the output of the neuron, access the input neurons to get their _activation,
		 * store the value into _activation
		 */
		void compute_forward() {
			// The current aggregating function is the sum
			double inputSum = 0;

			for(int i = 0; i < inputSize; i++) {
				inputSum += (this->inputs[i])->activation * (this->weights)[i]; 
			}

			this->activation = activationFunction(inputSum);

			std::cout << " Activation = " << this->activation << std::endl ;



		}





};



#endif