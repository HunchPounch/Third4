#include "CComplexVector.h"
#include "CComplexVectorVert.h"
#include "CComplexVectorHori.h"
#include <sstream>
#include <string>
#include <chrono>
#include <omp.h>

CComplexVectorHori operator +(CComplexVector &A, CComplexVector &B){
    if (A.Get_dim() != B.Get_dim())exit(2);
    CComplexVectorHori C(A.Get_dim(),"buffer");
    auto begin = std::chrono::steady_clock::now();
    #pragma omp parallel for
    for(int i=0;i<A.Get_dim(); i++){
        C.Set_Re_Im(A.Get_Re(i)+B.Get_Re(i), A.Get_Im(i)+B.Get_Im(i),i);

        //printf ("iteration %d, thread=%d\n", i, omp_get_thread_num());
    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time of addition: " << elapsed_ms.count() << " ms\n";

    return C;
}

CComplexVectorHori operator -(CComplexVector &A, CComplexVector &B){
    if (A.Get_dim() != B.Get_dim())exit(1);
    CComplexVectorHori C(A.Get_dim(), "buf");
    auto begin = std::chrono::steady_clock::now();
    #pragma omp parallel for
    for(int i=0;i<A.Get_dim(); i++){
        C.Set_Re_Im(A.Get_Re(i)- B.Get_Re(i), A.Get_Im(i) - B.Get_Im(i),i);

    }
    auto end = std::chrono::steady_clock::now();
    auto elapsed_ms = std::chrono::duration_cast<std::chrono::milliseconds>(end - begin);
    std::cout << "The time of difference: " << elapsed_ms.count() << " ms\n";
    return C;
}
