#pragma once

// There are 6 colors:
//
// blue
// green
// cyan
// red
// magenta
// yellow

// Usage:
// color("red", "Error occured", true);
//       color  text           newLine

#ifdef _WIN32


#include <windows.h>
void color(std::string color, std::string line, bool newLine = false, bool card = false) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int col = 7;

    if (color == "blue") col = 1;
    else if (color == "green") col = 2;
    else if (color == "cyan") col = 3;
    else if (color == "red") col = 4;
    else if (color == "magenta") col = 5;
    else if (color == "yellow") col = 6;
    else if (color == "black") col = 0;
    else if (color == "grey") col = 8;

    SetConsoleTextAttribute(hConsole, col | (BACKGROUND_INTENSITY | BACKGROUND_BLUE & card));
    std::cout << line;
    if (newLine) {
        std::cout << std::endl;
    }
    SetConsoleTextAttribute(hConsole, 7);
}


#else



void color(std::string color, std::string line, bool newLine = false) {
    std::string col = "\033[0m";

    if (color == "blue") col = "\033[0;34m";
    else if (color == "green") col = "\033[0;32m";
    else if (color == "cyan") col = "\033[0;36m";
    else if (color == "red") col = "\033[0;31m";
    else if (color == "magenta") col = "\033[0;35m";
    else if (color == "yellow") col = "\033[0;33m";

    std::cout << col << line << "\033[0m";
    if (newLine) {
        std::cout << std::endl;
    }
}


#endif
