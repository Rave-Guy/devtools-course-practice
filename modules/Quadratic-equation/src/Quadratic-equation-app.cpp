// Copyright 2020 Vedrukov Pavel

#include "include/Quadratic-equation.h"
#include "include/Quadratic-equation-app.h"

#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <iostream>

QuadraticEquationApp::QuadraticEquationApp() : message_("") {}

void QuadraticEquationApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is equation calculator application.\n\n " +
          "Equation: ax^2 + bx + c = 0 " +
          "Please provide arguments in the following format:\n\n" +

          "  $ " + appname + " <a> " + "<b> " + "<c>\n\n" +

          "Where all arguments are double-precision numbers\n" +
          "a != 0\n";
}

bool QuadraticEquationApp::validateNumberOfArguments(int argc,
                                                     const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 4) {
        help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string QuadraticEquationApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a = parseDouble(argv[1]);
        args.b = parseDouble(argv[2]);
        args.c = parseDouble(argv[3]);
    }
    catch(std::string& str) {
        return str;
    }

    QuadraticEquation equat(args.a, args.b, args.c);
    equat.SolveQuadraticEquation();
    std::ostringstream stream;
    char countRoots = equat.GetCountRoots();

    switch (countRoots) {
     case '0':
        stream << "This equation cannot have real roots!";
        break;
     case '1':
        stream << "This equation have one root!\n"
               << "Root: " << equat.GetRoot1();
        break;
     case '2':
        stream << "This equation have two roots!\n"
               << "Root1: " << equat.GetRoot1() << "\n"
               << "Root2: " << equat.GetRoot2();
        break;
    }

    message_ = stream.str();

    return message_;
}
