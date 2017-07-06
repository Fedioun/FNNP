#ifndef LAYER
#define LAYER

#include <cstdlib>

#include "Neuron.hpp"

class Layer {
	private :
	/*
		Neuron ** neurons = NULL;
		int functionId = 0;
		int size;
	*/
	public:

		Neuron ** neurons = NULL;
		int functionId = 0;
		int size;


		Layer(int size, int functionId) {
			this->size = size;
			this->neurons = 	(Neuron**)malloc(size * sizeof(Neuron*));
			for (int i =0; i < size; i++) {
				neurons[i] = new Neuron(functionId);
			}

		};



		~Layer() {
			for (int i =0; i < size; i++) {
				delete neurons[i];
			}
			free(neurons);

		};

		void connect(Layer * inputLayer) {
			for(int i =0; i < size; i++) {

				neurons[i]->connect(inputLayer->neurons, inputLayer->size);
			}
		};
};



#endif