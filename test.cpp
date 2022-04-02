#include "test.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int test1(){

    string file_name;
    string fileCheck_info;
    ifstream fin("test1.txt");
    string I;
    int Re;
    int Im;
    char k;
    int j =0;
    vector<CComplexVector*> v;
    map<string, CFactory*> factory;
    factory["Hori"] = new CFactoryHori;
    factory["Vert"] = new CFactoryVert;
    fin >> I;
    fin >> file_name;
    CComplexVector *w = factory[I]->Create(3, file_name);

        while(1){
            fin >> Re;
            fin >> Im;
            w->Set_Re_Im(Re,Im,j);

            if(fin.eof()){
                break;
            }
            k = fin.get();
            if(k == '\n' || k == '\0' ){
                j=0;
                break;
            }
            j++;
        }

    v.push_back(w);
    v[0]->output();
    fin.close();
    fin.open("TestFile1.txt");
    getline(fin,fileCheck_info);
    delete v[0];
	if(fileCheck_info == "(1 + 2i, 3 + 4i, 5 + 6i)"){
        cout << "test1 passed" << endl;
        return 0;
	}
	else {
        cout << "test1 not passed" << endl;
        return 1;
	}
}

int test2(){

    string file_name;
    string fileCheck_info1;
    string fileCheck_info2;

     ifstream fin("test2.txt");
    string I;
    int Re;
    int Im;
    char k;
    int j =0;
    vector<CComplexVector*> v;
    map<string, CFactory*> factory;
    factory["Hori"] = new CFactoryHori;
    factory["Vert"] = new CFactoryVert;
    fin >> I;
    fin >> file_name;
    CComplexVector *w = factory[I]->Create(2, file_name);

        while(1){
            fin >> Re;
            fin >> Im;
            w->Set_Re_Im(Re,Im,j);

            if(fin.eof()){
                break;
            }
            k = fin.get();
            if(k == '\n' || k == '\0' ){
                j=0;
                break;
            }
            j++;
        }
    v.push_back(w);
    v[0]->output();
    fin.close();
    fin.open("TestFile2.txt");
    getline(fin,fileCheck_info1);
    getline(fin,fileCheck_info2);
    delete v[0];
	if(fileCheck_info1 == "5 + 6i" && fileCheck_info2 == "7 + 8i"){
        cout << "test2 passed" << endl;
        return 0;
	}
	else {
        cout << "test2 not passed" << endl;
        return 1;
	}
}

int main_test(){
    if(test1() + test2() == 0){
        return 0;
    }
    else return 1;
}

