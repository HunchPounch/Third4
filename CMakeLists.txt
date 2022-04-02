cmake_minimum_required(VERSION 2.8)

project(Second4)

set(Second4_src test.cpp CComplexVector.cpp CComplexVectorVert.cpp CComplexVectorHori.cpp functions.cpp main.cpp)
set(Second4_hdr CComplexVector.h CComplexVectorVert.h CComplexVectorHori.h test.h CFactory.h CFactoryHori.h CFactoryVert.h)

add_executable(${PROJECT_NAME} ${Second4_src} ${Second4_hdr})