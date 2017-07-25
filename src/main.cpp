#include <iostream>

#include "Network.hpp"
#include <unistd.h>


#define NDEBUG

using namespace std;

int main() {
	cout << "Hello World !" << endl;

	int params[] = {3,0, 2,0};

	Network * nn = new Network(params, 2);

	for (int i = 0; i < nn->layers[0]->size; i++) {
		nn->layers[0]->neurons[i]->set_activation(0.3);
	}

	for (int i = 0; i < nn->layers[1]->size; i++) {
		nn->layers[1]->neurons[i]->compute();
	}

	delete nn;

	return 1;
}