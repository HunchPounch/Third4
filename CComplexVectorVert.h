#pragma once
#include "CComplexVector.h"

class CComplexVectorVert : public CComplexVector
{
public:
    CComplexVectorVert(int dim,const string fileName):CComplexVector(dim, fileName){
    }
    ~CComplexVectorVert(){
    }
    int output() override;
    CComplexVectorVert(const CComplexVector& other) : CComplexVector(other){
    }
    using CComplexVector::operator=;

    //friend CComplexVector0 operator +(CComplexVector1 &A, CComplexVector1 &B);
    //friend CComplexVector0 operator -(CComplexVector1 &A, CComplexVector1 &B);

};
