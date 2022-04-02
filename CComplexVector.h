#pragma once
using namespace std;
#include <string>
#include <iostream>
#include <vector>
#include <string.h>
#include <fstream>

class CComplexVector {

protected:
    vector<vector<int> > vec;
    int n;
    string filename;

public:

    CComplexVector(){
    }
    virtual ~CComplexVector(){
    }
    CComplexVector(int dim,const string fileName);
    CComplexVector(const CComplexVector& other);

    int Get_dim();
    int Get_Re(int i);
    int Get_Im(int i);
    string Get_filename();
    void Set_Re_Im(int value_Re, int value_Im, int i);

    CComplexVector& operator =(const CComplexVector &other);
    friend std::pair<int,int> operator *(CComplexVector &A, CComplexVector &B);

    virtual int output() = 0;

};




