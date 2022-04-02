#include "CComplexVectorHori.h"
#include <fstream>



int CComplexVectorHori::output() {

    ofstream fout;
    fout.open(this->Get_filename());
    fout << "(";
    for(int i=0;i<n;i++){

        fout << vec[i][0] << " + " << vec[i][1] << "i";
        if(i != n-1){
            fout << ", ";
        }
    }
    fout << ")" << "\n";
    fout.close();
    return 2;

}
