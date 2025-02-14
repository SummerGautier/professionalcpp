#include <fstream> // file i/o stream
#include <iostream> // standard i/o stream.
#include <exception>
#include <format>
#include <vector>
#include <span>

#include "content.h"

int main () {
    /**
     * Read in a file of chars into integer interpretations using ifstream byte mode.
     */
    {
        std::string _localFileName = "numbers.txt";
        // read in letters as binary. 
        std::ifstream _inFileStream {_localFileName, std::ios_base::binary};
        // verify filestream.
        if (!_inFileStream) {
            // check if stream itself is corrupted.
            if (_inFileStream.bad()) {
                // filestream itself corrupted. Exit immediately.
                std::string message = std::format("can't open file \'{}\', filestream corrupted.", _localFileName);
                throw std::ios_base::failure(message);
            }
            // check if file contents are unreadable / not found.
            if (_inFileStream.fail()) {
                // signal stream fail bit & clear contents.
                _inFileStream.clear(std::ios_base::failbit);
                return EXIT_FAILURE;
            }
            // check if EOF reached.
            if (_inFileStream.eof()) {
                // log unexpcted EOF and exit without exception.
                std::cerr << "can't open file. EOF found." << std::endl;
                return EXIT_FAILURE;
            }
        }
       
        // proceed if filestream was successfully opened.
        if (_inFileStream) {
            // move reading point (g/get) to start position.
            _inFileStream.seekg(0);
            char _byte {' '};
            bool reading = !_inFileStream.eof();
            while (reading) {
                if (_inFileStream.fail() || _inFileStream.bad()){
                    std::string message = std::format("can't continue reading file \'{}\', filestream corrupted.", _localFileName);
                    throw std::ios_base::failure(message);
                }

                // read next byte and increment.
                _inFileStream >> _byte;
                if (!_inFileStream.eof()) {
                    std::cout << int(_byte) << std::endl;
                } else {
                    reading = false;
                }
                

            }
        }
    }
    return EXIT_SUCCESS;
}

