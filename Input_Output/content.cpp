#include <fstream> // file i/o stream
#include <iostream> // standard i/o stream.
#include <exception>
#include <format>


std::string GetContent (const char _terminator) {
    std::cout << "Please enter input file name: " << std::endl;
    // avoid leaks by setting filename to empty string.
    std::string _inFileName {" "};
    // obtain input file name. 
    std::cin >> _inFileName;
    // container object for file content.
    std::string _content {" "};
    
    
    { // using artificial local scope for safe filestream.
        // open input file stream.
        std::ifstream _inFileStream {_inFileName};
        // verify file was opened, escape if filestream is corrupted.
        if (!_inFileStream && _inFileStream.bad()) {
            // stream itself is corrupted, throw exception.
            std::string message = std::format("can't open input file \'{}\', stream corrupted.", _inFileName);
            throw std::ios_base::failure(message);
        }
        // verify file was opened, recover if file contents are unreadable / not found.
        if (!_inFileStream && _inFileStream.fail()) {
            // refresh stream state.
            _inFileStream.clear();
            // search for terminating charachter.
            char _next;
            _inFileStream >> _next;
            // if next charachter is NOT a terminator, fail() completely.
            if (_next != _terminator) {
                // return unexpected character to buffer.
                _inFileStream.unget();
                // clear and set state bit to fail.
                _inFileStream.clear(std::ios_base::failbit);
            }
        }
        // verify file was opened, return if EOF read.
        if (!_inFileStream && _inFileStream.eof()) {
            // return default content.
            return _content;
        }
        // finally, read in from file.
        if(_inFileStream) {
            _inFileStream >> _content;
        }
    }  // filestream closes by going out of scope.

    return _content;
}

void WriteContent (const std::string& _content) {
    std::cout << "Please enter input file name: " << std::endl;
    // just-in-time declaration of output filename.
    std::string _outFileName {" "};
    // obtain output file name.
    std:: cin >> _outFileName;

    { // using artificial local scope for safe filestream. 
        // open output file stream.
        std::ofstream _outFileStream {_outFileName};
        // verify that the file was properly opened.
        if (!_outFileStream) {
            std::string message = std::format("can't open output file \'{}\'", _outFileName);
            throw std::ios_base::failure(message);
        }
        // finally, send content into outstream buffer. 
        _outFileStream << _content << std::endl;
        // flush outstream buffer into file.
        _outFileStream.flush(); 
    } // filestream closes by going out of scope.

    return;
}

