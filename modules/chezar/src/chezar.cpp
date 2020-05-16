// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

Chezar::Chezar() {

}

Chezar::Chezar(std::string msg) {
    this->SetStr(msg);
}

Chezar::Chezar(std::string msg, int key) {
    this->SetStr(msg);
    this->key = key;
}

Chezar::~Chezar() {

}

bool Chezar::SetKey(int key) {
    this->key = key;
    return true;
}

bool Chezar::SetStr(std::string str) {
    this->msg = str;
    return true;
}

std::string Chezar::GetStr() {
    return msg;
}

bool Chezar::isEncrypt() {
    return is_e;
}

int Chezar::GetKey() {
    return key;
}

bool Chezar::Encrypt() {
    char ch;
    for (unsigned int i = 0; msg.c_str()[i] != '\0'; ++i) {
        ch = msg.c_str()[i];
        if (ch >= 'a' && ch <= 'z') {
           ch = ch + (key % 26);
           if (ch > 'z') {
              ch = ch - 'z' + 'a' - 1;
           }
           msg[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
           ch = ch + (key % 26);
           if (ch > 'Z') {
               ch = ch - 'Z' + 'A' - 1;
           }
           msg[i] = ch;
        }
    }
    is_e = true;
    return true;
}

bool Chezar::Decrypt() {
    char ch;
    for (unsigned int i = 0; msg.c_str()[i] != '\0'; ++i) {
       ch = msg.c_str()[i];
       if (ch >= 'a' && ch <= 'z') {
           ch = ch - (key % 26);
           if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
           }
           msg[i] = ch;
       } else if (ch >= 'A' && ch <= 'Z') {
           ch = ch - (key % 26);
           if (ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
           }
           msg[i] = ch;
       }
    }
    is_e = false;
    return true;
}
