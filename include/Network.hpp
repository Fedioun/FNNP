#ifndef NETWORK	
#define NETWORK

#include <cstdlib>
#include "Layer.hpp"
#include <iostream>



class Network {
	private :
		static int networkCount;
		int networkId = -1;
		
	public:

		Layer ** layers = NULL;
		int size;


		Network(int * input, int size) {

			#ifndef NDEBUG
				std::cout << "New network n°"<< networkCount << std::endl;
			#endif

			this->networkId = networkCount++;
			this->size = size;
			this->layers = 		(Layer**)malloc(size * sizeof(Layer*));

			// Layers allocation
			for(int i = 0; i < size; i++) {

			#ifndef NDEBUG
				layers[i] = new Layer(input[2*i], input[2*i+1], i);
			#else
				layers[i] = new Layer(input[2*i], input[2*i+1]);
			#endif
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
			#ifndef NDEBUG
				std::cout << "Network " << networkId << " freed" << std::endl;
			#endif
			
		};


		/***
		 * Compute the output of the network by calling compute_forward() on each layer but the first
		 */
		void compute_forward() {
			// For each layer exept the first one (input layer)
			for (int j = 1; j < size; j++) {
				layers[j]->compute_forward();
			}
		}

};

int Network::networkCount = 0;


#endif