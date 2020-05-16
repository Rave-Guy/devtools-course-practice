// Copyright 2020 Vedrukov Pavel

#include <iostream>
#include <string>

#include "include/Quadratic-equation-app.h"

int main(int argc, const char** argv) {
    QuadraticEquationApp app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
