#include <iostream>

#include "Network.hpp"
#include <unistd.h>
#include "Random.hpp"
#include <iterator>



using namespace std;

int main() {

	#ifndef NDEBUG
		cout << "////////////////////////////////////////////////////////" << endl
		     << "//// Welcome to Fedioun's Neural Network Playground ////" << endl
		     << "////////////////////////////////////////////////////////" << endl << endl;
	#endif
	



	int params[] = {3,0, 2,0, 2 ,0 , 2, 0};

	Network * nn = new Network(params, 4);

	nn->compute_forward();

	delete nn;

	/*
	float progress = 0.0;
	while (progress < 1.0) {
	    int barWidth = 70;

	    std::cout << "[";
	    int pos = barWidth * progress;
	    for (int i = 0; i < barWidth; ++i) {
	        if (i < pos) std::cout << "=";
	        else if (i == pos) std::cout << ">";
	        else std::cout << " ";
	    }
	    std::cout << "] " << int(progress * 100.0) << " %\r";
	    std::cout.flush();

	    sleep(1);
	    progress += 0.01; // for demonstration only
	}
	std::cout << std::endl;

	*/

	return 1;
}