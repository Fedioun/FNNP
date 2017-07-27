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

		Layer(int size, int functionId, int id) {
			#ifndef NDEBUG
				std::cout << "Layer n°" << id << " of size " << size << " using the activation function n°" << functionId << std::endl;
			#endif
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


		/***
		 * Compute the ouput of the layer by calling compute() on each neuron 
		 */
		void compute_forward() {
			// For each neuron 
			for (int i = 0; i < this->size; i++) {
				this->neurons[i]->compute_forward();
			} 
		}


};



#endif