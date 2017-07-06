#include <iostream>

#include "Network.hpp"

using namespace std;

int main() {
	cout << "Hello World !" << endl;

	int params[] = {3,0, 2,0};

	Network * nn = new Network(params, 2); 

	delete nn;

	return 1;
}