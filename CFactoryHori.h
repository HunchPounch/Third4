#pragma once
using namespace std;
#include "CFactory.h"
#include "CComplexVectorHori.h"
#include <iostream>

class CFactoryHori : public CFactory {
public:
    virtual CComplexVector *Create(int dim, const string File){return new CComplexVectorHori(dim,File);}
};
