#include "LinearRegression.h"

double LinearRegression::h(vector<double> &X){
	vector<double> V = multiplyVectors(X,W);
	return sumVectorValues( V );
}

double LinearRegression::error( vector<double> &X, double y){
	return h(X)-y;
}

double LinearRegression::cost( vector< vector<double> > &A, vector<double>&Y){
	double cost = 0;

	for(int i = 0 ; i < A.size() ; i++){
		cost += pow( error( A[i], Y[i] ), 2 );
	}

	return cost / ( 2 * A.size() );
}

vector<double> LinearRegression::costDerivativeVector( vector< vector<double> > &A, vector<double>&Y){
	vector<double> D(W.size(),0);

	for(int i = 0 ; i < W.size() ; i++){
		for(int j = 0 ; j < A.size() ; j++){
			D[i] += error( A[j], Y[j] )*A[j][i];
		}
		D[i] = D[i]/A.size();
	}

	return D;
}

double LinearRegression::gradient_descent(vector< vector<double> > &A, vector<double>&Y){
	double pCost,cCost;

	pCost = cCost = cost(A,Y);

	for(int i = 0 ; i < iterationCount ; i++){
		vector<double> D = costDerivativeVector(A,Y);
		D = multiplyVectorWithScalar( D, alpha);
		W = subtractVectors( W, D );
		
		if(adaptiveAlpha){
			pCost = cCost;
			cCost = cost(A,Y);
			if( pCost < cCost ){
				alpha = 0.9*alpha;
			}
		}

	}
	return cost(A,Y);
}

vector<double> LinearRegression::scaleFeatures( vector<double> &I){
	vector<double> Z = subtractVectors( I , M );
	Z = divideVectors( Z , R );
	return Z;
}

LinearRegression::LinearRegression(){

	alpha = 0.01;
	iterationCount = 1000;
	adaptiveAlpha = false;
	featureScaling = false;
	
}

double LinearRegression::train(vector< vector<double> > &B, vector<double> &Y){
	vector< vector<double> > A(B);

	if(featureScaling){
		M = calculateMeanVector(B);
		R = calculateRangeVector(B);
	}

	for(int i = 0; i < A.size(); i++){
		if(featureScaling) A[i] = scaleFeatures(A[i]);
		A[i].push_back(1);
	}
	W.resize(A[0].size(),0);

	return gradient_descent(A,Y);
}

double LinearRegression::predict(vector<double> &I){
	vector<double> Z(I);
	if(featureScaling) Z = scaleFeatures(Z);
	Z.push_back(1);
	return h(Z);
}

vector<double> LinearRegression::getWeights(){
	return W;
}

