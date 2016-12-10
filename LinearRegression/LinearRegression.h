#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H

#include "auxiliary.h"

class LinearRegression{
	/*
	W: weight vector,
	M: mean vector,
	R: range vector,
	X: processed input vector,
	Y: desired output vector,
	A: processed training matrix,
	I: input vector,
	B: training matrix
	*/
	private:
		vector<double> W, M, R;

		double h( vector<double>&);//X
		double error( vector<double>&, double);//X,y
		double cost( vector< vector<double> > &, vector<double>&);//A,Y
		double gradient_descent(vector< vector<double> >&, vector<double>&);//A,Y
		vector<double> costDerivativeVector( vector< vector<double> >&, vector<double>&);//A,Y
		vector<double> scaleFeatures( vector<double>&);//I
	public:	
		double alpha;
		int iterationCount;
		bool adaptiveAlpha;
		bool featureScaling;

		LinearRegression();
		double train(vector< vector<double> > &, vector<double>&);//B,Y
		double predict(vector<double>&);//I
		vector<double> getWeights();
};

#endif 
