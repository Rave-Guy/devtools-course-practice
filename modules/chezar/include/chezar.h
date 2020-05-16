// Copyright 2020 Suchkov Makar

#ifndef MODULES_CHEZAR_INCLUDE_CHEZAR_H_
#define MODULES_CHEZAR_INCLUDE_CHEZAR_H_

#include <iostream>
#include <string>

class Chezar {
 public:
    Chezar();
    Chezar(std::string msg, int key);
    ~Chezar();
    std::string GetStr();
    bool SetStr(std::string str);
    bool SetKey(int key);
    int GetKey();
    bool isEncrypt();
    bool Decrypt();
    bool Encrypt();
 private:
    std::string msg;
    int key = 0;
    bool is_e;
};

#endif  // MODULES_CHEZAR_INCLUDE_CHEZAR_H_
