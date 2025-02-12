#include <iostream>
#include "token.h"

// return a read Token back into TokenStream buffer.
void TokenStream::PutBack(const Token _token) {
    // error on trying to overwrite non-empty buffer.
    if (this->full) {
        throw std::runtime_error("Failed PutBack() : TokenStream Buffer is full.");
    }

    // buffer is updated, overwite is allowed if  'official' state is empty (full=false)
    this->buffer = _token;
    // udpate official state to full.
    this->full = true;

    // void exit.
    return;
}

// read from I/O and construct Tokens to represent operands or numbers.
Token TokenStream::GetToken() {
    // empty the buffer and reset full to false.
    if (this->full) {
        // reset full status.
        this->full = false;
        // return buffer token.
        return this->buffer;
    }

    // obtain user input from keyboard.
    char _input {' '};
    std::cin >> _input;

    // check for kind and create token.
    switch (_input) {
        // all of these cases fall through to "return Token with charachter as value"
        case ';':
        case 'q':
        case '(': 
        case ')': 
        case '+': 
        case '-': 
        case '*': 
        case '/':
            return Token{_input}; // all the symbol cases are just single charachter tokens.
        case '.':
        // the digit indicates we are about to read a number which may be multiple charachters.
        case '0': 
        case '1': 
        case '2': 
        case '3': 
        case '4': 
        case '5': 
        case '6': 
        case '7': 
        case '8': 
        case '9':
            {
               // return the digit back to the stream so it can be re-read.
               std::cin.putback(_input);
               // next read not just the digit but the whole next availabile number.
               // cin will stop once a space or non-digit is encountered.
               double _value;
               std::cin >> _value;
               // create a Token whose value is the complete number value read in.
               return Token{NUMBER_TYPE, _value};
            }
        default:
            throw std::runtime_error("Token is not valid.");
    }
}