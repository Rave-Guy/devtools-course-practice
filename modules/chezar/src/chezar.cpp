// Copyright 2020 Suchkov Makar

#include "include/chezar.h"

char* Encrypt(char* msg, char key)
{
    char ch;
    for(int i = 0; msg[i] != '\0'; ++i)
    {
        ch = msg[i];
        //encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
           ch = ch + key;
           if (ch > 'z') {
              ch = ch - 'z' + 'a' - 1;
           }
           msg[i] = ch;
       }
        //encrypt for uppercase letter
        else if (ch >= 'A' && ch <= 'Z')
        {
           ch = ch + key;
           if (ch > 'Z'){
              ch = ch - 'Z' + 'A' - 1;
           }
           msg[i] = ch;
        }
    }
    return msg;
}

char* Decrypt(char* msg, char key)
{
    char ch;
    for(int i = 0; msg[i] != '\0'; ++i)
    {
       ch = msg[i];
       //decrypt for lowercase letter
       if(ch >= 'a' && ch <= 'z')
       {
           ch = ch - key;
           if(ch < 'a'){
                ch = ch + 'z' - 'a' + 1;
            }
            msg[i] = ch;
        }
       //decrypt for uppercase letter
       else if(ch >= 'A' && ch <= 'Z')
       {
          ch = ch - key;
          if(ch < 'A') {
             ch = ch + 'Z' - 'A' + 1;
           }
          msg[i] = ch;
       }
    }
    return msg;
}