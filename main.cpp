#include <iostream>
#include <fstream>
#include <sstream>
#include "LinearRegression.h"

using namespace std;

vector< vector<double> > readMatrix(string filename){
	ifstream f;
	string line;
	stringstream ss;
	vector< vector<double> > M;

	f.open(filename);
	while ( getline (f,line) )
    {
    	double value;
    	vector<double> V;
      	ss << line;
      	while(ss>>value){
      		V.push_back(value);
      	}
      	M.push_back(V);
      	ss.clear();
    }
    f.close();

    return M;
}

template <typename T>
void printVector( vector<T> V){
	cout<<"[ ";
	for(int i = 0 ; i < V.size() ; i++){
		cout<<V[i]<<" ";
	}
	cout<<"]"<<endl;
}

int main(){
	
	vector< vector<double> > B = readMatrix("data/train.txt");
	vector< vector<double> > T = readMatrix("data/test.txt");
	vector<double> Y,W;
	
	for(int i = 0; i < B.size() ; i++){
		Y.push_back( B[i].back() );
		B[i].pop_back();
	}
	

	LinearRegression *lr = new LinearRegression();

	lr->adaptiveAlpha = true;
	lr->alpha = 0.5;
	lr->iterationCount = 100;
	lr->featureScaling = true;

	cout<<"---------- TRAINING ----------"<<endl;
	cout<<"Alpha: "<<lr->alpha<<endl;
	cout<<"Iteration Count: "<<lr->iterationCount<<endl;
	cout<<"Adaptive Alpha: "<<((lr->adaptiveAlpha)?("Yes"):("No"))<<endl;
	cout<<"Feature Scaling: "<<((lr->featureScaling)?("Yes"):("No"))<<endl;
	cout<<"Cost: "<<lr->train(B,Y)<<endl;
	W = lr->getWeights();
	cout<<"Weights: ";
	printVector(W);

	cout<<"\n---------- TEST ----------"<<endl;
	for (int i = 0; i < T.size(); i++)
	{
		cout<<"Prediction from: ";
		printVector(T[i]);
		cout<<"Result: "<<lr->predict(T[i])<<endl<<endl;
	}

	return 0;
}