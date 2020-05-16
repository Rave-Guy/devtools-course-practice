// Copyright 2020 Suchkov Makar

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/chezar.h"

int main(int argc, const char** argv) {
    Chezar app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}

