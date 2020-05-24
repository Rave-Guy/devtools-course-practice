// Copyright 2020 Suchkov Makar

#include "include/bitfield.h"
#include "include/bitfield-app.h"


#include <iostream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <sstream>
#include <ctime>


Bitfieldapp::Bitfieldapp() : message_("") {}

void Bitfieldapp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a Bitfield application.\n\n" +
          "Please provide arguments in the following format:\n\n"+
          "  $ " + appname + " <type> <bitfield_size> " +
          "<position>\n\n" +
          "Where all arguments are positive integer numbers, \n" +
          "set <type> to 1 to create bitfield and set" +
          "in <position> flag, " +
          "set <type> to 2 to create bitfield and set\n" +
          "and random set flag and unset in <position>\n" +
          "set <type> to 3 to create bitfield and set\n" +
          "all flags up and unset in <position>; \n" +
          "you can use multi up flags if " +
          "use some argiments <position>\n\n";
}

bool Bitfieldapp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc < 4 && argc > 1) {
        help(argv[0], "ERROR: Should be three arguments.\n\n");
        return false;
    }
    return true;
}

unsigned int Bitfieldapp::parseInt(const char* arg) {
    char* end;
    unsigned int value = static_cast<unsigned int>(std::strtol(arg, &end, 0));

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string Bitfieldapp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.type = parseInt(argv[1]);
        args.bitfield_size = parseInt(argv[2]);
        if (argc == 4) {
            args.position = parseInt(argv[3]);
        } else {
            for (int i = 0; i < argc - 3; i++) {
            args.arr[i] = parseInt(argv[i + 3]);
            }
        }
    }
    catch(std::string& str) {
        return str;
    }

    Bitfield bitf(args.bitfield_size);
    std::ostringstream stream;
    if (argc == 4) {
        switch (args.type) {
         case 1:
            bitf.set(args.position);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 2:
           std::srand(unsigned(std::time(0)));
           for (unsigned int i = 0; i < bitf.get_size(); i++) {
                if (std::rand() % 2 == 0) {
                bitf.set(i);
                }
            }
            bitf.unset(args.position);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 3:
            bitf.fill();
            bitf.unset(args.position);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         default:
           stream << "ERROR: unknow operation" << std::endl;
        }
    } else if (argc > 4) {
        switch (args.type) {
         case 1:
            bitf.set(args.arr);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 2:
            std::srand(unsigned(std::time(0)));
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                if (std::rand() % 4 == 0) {
                    bitf.set(i);
                }
            }
            bitf.unset(args.arr);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         case 3:
            bitf.fill();
            bitf.unset(args.arr);
            for (unsigned int i = 0; i < bitf.get_size(); i++) {
                stream << bitf.get(i) << " ";
            }
            stream << std::endl;
            break;
         default:
            stream << "ERROR: unknow operation" << std::endl;
        }
    }

    message_ = stream.str();

    return message_;
}
