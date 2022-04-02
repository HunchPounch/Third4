#pragma once
using namespace std;
#include "CFactory.h"
#include "CComplexVectorVert.h"
#include <iostream>

class CFactoryVert : public CFactory {
public:
    virtual CComplexVector *Create(int dim, const string File){return new CComplexVectorVert(dim,File);}
};

