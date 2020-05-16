// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

char* Encrypt(char* msg, char key) {
    char ch;
    for (int i = 0; msg[i] != '\0'; ++i) {
        ch = msg[i];
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
    return msg;
}

char* Decrypt(char* msg, char key) {
    char cd;
    for (int i = 0; msg[i] != '\0'; ++i) {
       cd = msg[i];
       if (cd >= 'a' && cd <= 'z') {
           cd = cd - (key % 26);
           if (cd < 'a') {
                cd = cd + 'z' - 'a' + 1;
           }
           msg[i] = cd;
       } else if (cd >= 'A' && cd <= 'Z') {
           cd = cd - (key % 26);
           if (cd < 'A') {
               cd = cd + 'Z' - 'A' + 1;
           }
           msg[i] = cd;
       }
    }
    return msg;
}
