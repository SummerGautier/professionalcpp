#include <fstream> // file i/o stream
#include <iostream> // standard i/o stream.
#include <exception>
#include <format>
#include "content.h"

int main () {
    // retrieve content form File A
    std::string words = GetContent('\n');
    // write content to File B
    WriteContent(words);
}

