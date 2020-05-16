// Copyright 2020 Vedrukov Pavel

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/Quadratic-equation-app.h"

int main(int argc, const char** argv) {
    QuadraticEquationApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
