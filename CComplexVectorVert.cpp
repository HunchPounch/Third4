#include "CComplexVectorVert.h"
#include <fstream>



int CComplexVectorVert::output() {

    ofstream fout;
    fout.open(this->Get_filename());
    for(int i=0;i<n;i++){
        fout << vec[i][0] << " + " << vec[i][1] << "i";
        if(i != n-1){
            fout << "\n";
        }
    }
    //fout << "\n";
    fout.close();
    return 3;

}

