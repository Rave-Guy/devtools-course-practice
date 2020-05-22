// Copyright 2020 Vedrukov Pavel

#include "include/Quadratic-equation.h"
#include "include/Quadratic-equation-app.h"

#include <string>
#include <sstream>

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

std::string QuadraticEquationApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.a = std::stod(argv[1]);
        args.b = std::stod(argv[2]);
        args.c = std::stod(argv[3]);
    }
    catch(std::invalid_argument& arg) {
        message_ = "Wrong number format!";
        return message_;
    }

    QuadraticEquation equat(args.a, args.b, args.c);
    equat.SolveQuadraticEquation();
    std::ostringstream stream;
    char countRoots = equat.GetCountRoots();

    switch (countRoots) {
     case '0':
        stream << "This equation cannot have real roots!\n";
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
