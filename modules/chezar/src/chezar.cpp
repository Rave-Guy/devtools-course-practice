// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

char* Encrypt(char* msg, char key) {
    for (int i = 0; msg[i] != '\0'; ++i) {
        char ch = msg[i];
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
    for (int i = 0; msg[i] != '\0'; ++i) {
       char ch = msg[i];
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
    return msg;
}
