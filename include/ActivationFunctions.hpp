#ifndef ACTIVATIONFUNCTIONS
#define ACTIVATIONFUNCTIONS

#include <cstdlib>
#include <cmath>

typedef double (*activFun)(double);

double sigmoid(double input) {
	return (1 / (1 + exp(-input)));
}


activFun get_activation_fun(int id) {
	return (*sigmoid);
}


/*
double (*get_activation_fun(int input))(double) {
	return (*sigmoid);
}
*/

#endif