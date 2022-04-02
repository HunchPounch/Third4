#pragma once
using namespace std;
#include "CComplexVector.h"
#include <iostream>

class CFactory {

public:
    virtual CComplexVector *Create(int dim, const string File) = 0;
};
