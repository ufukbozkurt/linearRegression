#ifndef AUXILIARY_H
#define AUXILIARY_H

#include <vector>
using namespace std;

double pow(double, int);
double max(double, double);
double min(double, double);

double sumVectorValues(vector<double>&);

vector<double> sumVectors(vector<double>&, vector<double>&);
vector<double> subtractVectors(vector<double>&, vector<double>&);
vector<double> multiplyVectors(vector<double>&, vector<double>&);
vector<double> divideVectors(vector<double>&, vector<double>&);

vector<double> calculateMeanVector(vector< vector<double> >&);
vector<double> calculateRangeVector(vector< vector<double> >&);

vector<double> multiplyVectorWithScalar(vector<double>&, double);
vector<double> divideVectorWithScalar(vector<double> &, double);

#endif