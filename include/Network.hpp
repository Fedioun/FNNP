#ifndef NETWORK	
#define NETWORK

#include <cstdlib>
#include "Layer.hpp"


class Network {
	private :
		Layer ** layers = NULL;
		int size;
	public:


		Network(int * input, int size) {
			this->size = size;

			this->layers = 		(Layer**)malloc(size * sizeof(Layer*));

			for(int i = 0; i < size; i++) {
				layers[i] = new Layer(input[2*i], input[2*i+1]);
			}

			// Full connection for now
			for(int i = size-1; i > 0 ; i--) {
				layers[i]->connect(layers[i-1]);
			}


		};



		~Network() {
			for(int i = 0; i < size; i++) {
				delete(layers[i]);
			}
			free(layers);
		};
};



#endif