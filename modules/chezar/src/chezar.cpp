// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

char* Encrypt(char* msg, char key) {
    char ch;
    for (int i = 0; msg[i] != '\0'; ++i) {
        ch = msg[i];
        if (ch >= 'a' && ch <= 'z') {
           ch = ch + key;
           if (ch > 'z') {
              ch = ch - 'z' + 'a' - 1;
           }
           msg[i] = ch;
        } else if (ch >= 'A' && ch <= 'Z') {
           ch = ch + key;
           if (ch > 'Z') {
               ch = ch - 'Z' + 'A' - 1;
           }
           msg[i] = ch;
        }
    }
    return msg;
}

char* Decrypt(char* msg, char key) {
    char ch;
    for (int i = 0; msg[i] != '\0'; ++i) {
       ch = msg[i];
       if (ch >= 'a' && ch <= 'z') {
           ch = ch - key;
           if (ch < 'a') {
                ch = ch + 'z' - 'a' + 1;
           }
           msg[i] = ch;
       } else if (ch >= 'A' && ch <= 'Z') {
           ch = ch - key;
           if (ch < 'A') {
               ch = ch + 'Z' - 'A' + 1;
           }
           msg[i] = ch;
       }
    }
    return msg;
}
