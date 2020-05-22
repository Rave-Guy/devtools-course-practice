// Copyright 2020 Vedrukov Pavel

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APP_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APP_H_

#include <string>

class QuadraticEquationApp {
 public:
    QuadraticEquationApp();
    std::string operator()(int argc, const char** argv);

 private:
    using Arguments = struct {
        double a, b, c;
    };
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQUATION_APP_H_
