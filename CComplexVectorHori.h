#pragma once
#include "CComplexVector.h"

class CComplexVectorHori : public CComplexVector
{
public:
    CComplexVectorHori(int dim,const string fileName):CComplexVector(dim, fileName){
    }
    ~CComplexVectorHori(){
    }
    CComplexVectorHori(CComplexVector& other) : CComplexVector(other){
    }
    using CComplexVector::operator=;

    int output() override;
    friend CComplexVectorHori operator +(CComplexVector &A, CComplexVector &B);
    friend CComplexVectorHori operator -(CComplexVector &A, CComplexVector &B);
};


