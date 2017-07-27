#ifndef RANDOM
#define RANDOM

#include <chrono>
#include <random>
#include <iostream>
#include <functional>

class RandomGenerator {
	private: 
		static unsigned seed;

	public:

		static double get_gaussian_noise(double mean, double var) {

			//std::default_random_engine generator(seed);
			//std::random_device{}()
    		auto dist = std::bind(std::normal_distribution<double>{mean, var}, std::mt19937(seed));
    		seed *= 4524118;
    		return dist();
		}

};

unsigned RandomGenerator::seed = std::chrono::system_clock::now().time_since_epoch().count();


#endif