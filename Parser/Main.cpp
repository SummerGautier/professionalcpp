#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

/**
 * 
 * Classes & Functional Declarations.
 * 
 * */

// represent the tokens.
class Token;
// represent a stream of tokens.
class TokenStream;
// evaluate plus and minus, call term() and get_token()
double EvaluateExpression();
// evaluate multiply, divide, and modulo, call primary() and get_token()
double EvaluateTerm();
// evaluate numbers and parentheses, call expression() and get_token()
double EvaluatePrimary();
// Token type represents an operator and an operand. 
class Token {
    public:
        char kind;
        double value;
};
// TokenStream represents a stream of inputs as tokens.
class TokenStream {
    public:
        // obtains a token either from buffer or I/O.
        Token GetToken();
        // stores a token in the buffer.
        void PutBack(const Token _token);
    private:
        // Describes if there is space to store a returned token.
        bool full {false};
        // buffer is where we keep a token that has been returned.
        Token buffer;
};

/**
 * 
 * Global Constants & Singletons
 */

// init token stream to translate charachters into operands.
TokenStream TOKEN_STREAM;
// constant to represent token type 'number'.
constexpr char NUMBER_TYPE ='8';

/**
 * 
 * Implementation of Classes & Functions.
 * 
 * */

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
               // '8' is universal signifer we've chosen to mean 'number-type'. No relation to it's value.
               return Token{NUMBER_TYPE, _value};
              
            }
        default:
            throw std::runtime_error("Token is not valid.");
    }
}

// evaluate complete expressions into final result.
double EvaluateExpression () {
    // the prior evaluated expression is left of the current expression.
    double _left = EvaluateTerm();

    Token _token = TOKEN_STREAM.GetToken();

    // iteratively evaluate the right side and add to the left side.
    while (true) {
        switch (_token.kind) {
            // evaluate addition term.
            case '+':
                _left = _left + EvaluateTerm();
                _token = TOKEN_STREAM.GetToken();
                break;
            // evaluate substraction term.
            case '-':
                _left = _left - EvaluateTerm();
                _token = TOKEN_STREAM.GetToken();
                break;
            // return  unused token.
            default:
                TOKEN_STREAM.PutBack(_token);
                return _left;
        }
    }
}

// evalute the numeric value of a term.
double EvaluateTerm () {
    // the prior primary is left of the current Term.
    double _left = EvaluatePrimary();

    Token _token = TOKEN_STREAM.GetToken();

    // iteratively evalute the right and operate on the left side.
    while (true) {
        switch (_token.kind) {
            // evaluate multiplication term.
            case '*':
                // scale multiplication on left term.
                _left = _left * EvaluatePrimary();
                // update token.
                _token = TOKEN_STREAM.GetToken();
                break;
            // evaluate division term. 
            case '/':
                { // the curly brace 'block' is necessary since we define & init a variable (primary)
                    double _divisor = EvaluatePrimary();
                    // prohibit illegal division by zero.
                    if (_divisor == 0) {
                        throw std::logic_error("cannot divide by zero.");
                    }
                    // scale division on left term.
                    _left = _left / _divisor;
                    // update token.
                    _token = TOKEN_STREAM.GetToken();
                    break;
                }
            // return unused token to stream.
            default:
                TOKEN_STREAM.PutBack(_token);
                return _left;
        }
    }
}

// interpret the numeric value of a primary.
double EvaluatePrimary() {

    Token _token = TOKEN_STREAM.GetToken();

    // iteratively evalute the right and operate on the left side.
    switch (_token.kind) {
        case '(':
            {
                double _value = EvaluateExpression();
                _token = TOKEN_STREAM.GetToken();
                if (_token.kind != ')') {
                    throw std::runtime_error("expected ')'.");
                }
                return _value;
            }
        case NUMBER_TYPE:
            return _token.value;
        default:
            throw std::runtime_error("primary expected.");
    }
}

// execute Full Calculation Loop & Deal with Exceptions.
int32_t main () {
    // place holder for expression value.
    double _value {0};
    try {
        // continue until console input terminates.
        while (std::cin) {
            // prompt
            std::cout << "> ";
            Token _token = TOKEN_STREAM.GetToken();
            // quite program if stop command is reached.
            if (_token.kind == 'q') {
                return EXIT_SUCCESS;
            }
            // send output if statement end is reached.
            if (_token.kind == ';') {
                std::cout << "=" << _value << std::endl;
            } else {
                TOKEN_STREAM.PutBack(_token);
                // evaluate the next expression.
                _value = EvaluateExpression();
            }
        }
    } catch (std::exception& errorRef ) {
        std::cerr << errorRef.what() << std::endl;
        return EXIT_FAILURE;
    }
    // exit success.
    return EXIT_SUCCESS;
}