
#include "auxiliary.h"

double pow(double a, int b){
	if(b <= 0) return 1;
	return a*pow(a,b-1);
}

double max(double a, double b){
	if(a > b) return a;
	return b;
}

double min(double a, double b){
	if(a > b) return b;
	return a;
}

double sumVectorValues(vector<double> &a){
	double sum = 0;

	for(int i = 0; i < a.size() ; i++){
		sum += a[i];
	}

	return sum;
}

vector<double> sumVectors(vector<double> &a, vector<double> &b){
	if(a.size() == b.size()){
		vector<double> c( a.size(), 0 );

		for(int i = 0; i < a.size() ; i++){
			c[i] = a[i]+b[i];
		}

		return c;
	}
	return vector<double>();
}

vector<double> subtractVectors(vector<double> &a, vector<double> &b){
	if(a.size() == b.size()){
		vector<double> c( a.size(), 0 );

		for(int i = 0; i < a.size() ; i++){
			c[i] = a[i]-b[i];
		}

		return c;
	}
	return vector<double>();
}

vector<double> multiplyVectors(vector<double> &a, vector<double> &b){
	if(a.size() == b.size()){
		vector<double> c( a.size(), 0 );

		for(int i = 0; i < a.size() ; i++){
			c[i] = a[i]*b[i];
		}

		return c;
	}
	return vector<double>();
}

vector<double> divideVectors(vector<double> &a, vector<double> &b){
	if(a.size() == b.size()){
		vector<double> c( a.size(), 0 );

		for(int i = 0; i < a.size() ; i++){
			if(b[i] != 0){//ignoring may not be right
				c[i] = a[i]/b[i];
			}
		}

		return c;
	}
	return vector<double>();
}

vector<double> vectorMax(vector<double> &a, vector<double> &b){
	if(a.size() == b.size()){
		vector<double> c( a.size(), 0 );

		for(int i = 0; i < a.size() ; i++){

			c[i] = max(a[i],b[i]);
		}

		return c;
	}
	return vector<double>();
}

vector<double> vectorMin(vector<double> &a, vector<double> &b){
	if(a.size() == b.size()){
		vector<double> c( a.size(), 0 );

		for(int i = 0; i < a.size() ; i++){
			c[i] = min(a[i],b[i]);
		}

		return c;
	}
	return vector<double>();
}

vector<double> calculateMeanVector(vector< vector<double> > &a){
	if(a.size() > 0){
		vector<double> m( a[0].size(), 0 );

		for(int i = 0; i < a.size() ; i++){
			m = sumVectors(m, a[i]);
		}
		m = divideVectorWithScalar(m, a.size());
		return m;
	}
	return vector<double>();
}

vector<double> calculateRangeVector(vector< vector<double> > &a){
	if(a.size() > 0){
		vector<double> r( a[0].size(), 0 );
		vector<double> max(a[0]);
		vector<double> min(a[0]);

		for(int i = 1; i < a.size() ; i++){
			max = vectorMax(max,a[i]);
			min = vectorMin(min,a[i]);
		}
		r = subtractVectors(max, min);
		return r;
	}
	return vector<double>();
}

vector<double> multiplyVectorWithScalar(vector<double> &a, double b){
	vector<double> c( a.size(), 0 );

	for(int i = 0; i < a.size() ; i++){
		c[i] = a[i]*b;
	}

	return c;
}

vector<double> divideVectorWithScalar(vector<double> &a, double b){
	vector<double> c( a.size(), 0 );

	for(int i = 0; i < a.size() ; i++){
		c[i] = a[i]/b;
	}

	return c;
}