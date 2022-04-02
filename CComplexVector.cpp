#include "CComplexVector.h"
#include <iostream>
using namespace std;
#include <omp.h>


CComplexVector::CComplexVector(int dim, const string fileName){
        filename = fileName;
        n = dim;
        for (int i = 0; i < n; i++) {
            vector<int> v;
            for (int j = 0; j < 2; j++) {
                v.push_back(0);
            }
            this->vec.push_back(v);
        }
    }

CComplexVector::CComplexVector(const CComplexVector& other) {
    this->n = other.n;
    //char buffer[256];

    for (int i = 0; i < this->n; i++) {
        vector<int> v;
        for (int j = 0; j < 2; j++) {
            v.push_back(other.vec[i][j]);
        }
        this->vec.push_back(v);
    }

}

string CComplexVector::Get_filename(){
    return filename;
}

int CComplexVector::Get_Re(int i) {
	return vec[i][0];
}
int CComplexVector::Get_Im(int i) {
	return vec[i][1];
}
int CComplexVector::Get_dim() {
	return n;
}

void CComplexVector::Set_Re_Im(int value_Re, int value_Im, int i){

	vec[i][0] = value_Re;
	vec[i][1] = value_Im;

}

CComplexVector& CComplexVector::operator =(const CComplexVector &other){
    if (this->n != other.n)exit(1);

    for(int i=0; i<this->n; i++){
        this->vec[i][0] = other.vec[i][0];
        this->vec[i][1] = other.vec[i][1];
    }
    this->filename = other.filename;
    return *this;
}


std::pair<int,int> operator *(CComplexVector &A, CComplexVector &B){
    if (A.n != B.n)exit(3);
    std::pair<int,int> retPair;
    #pragma omp parallel for                                            // reduction(+: retPair.first,retPair.second)
    for(int i=0;i<A.n; i++){
        retPair.first += A.Get_Re(i)*B.Get_Re(i) - A.Get_Im(i)*B.Get_Im(i);
        retPair.second += A.Get_Re(i)*B.Get_Im(i) + A.Get_Im(i)*B.Get_Re(i);
    }
    return retPair;
}
