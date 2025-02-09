#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

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
        char8_t kind;
        double value;
};
// TokenStream represents a stream of inputs as tokens.
class TokenStream {
    public:
        // constructs a token stream object.
        TokenStream();
        // obtains a token either from buffer or I/O.
        Token GetToken();
        // stores a token in the buffer.
        void PutBack(const Token _token);
    private:
        // full discribes if there is space to store a returned token.
        bool full {false};
        // buffer is where we keep a token that has been returned.
        Token buffer;
};

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

    }
}

double EvaluateExpression () {
    // the prior evaluated expression is left of the current expression.
    double _left = EvaluateTerm();
    // init token stream to translate charachters into operands.
    TokenStream _tokenStream;
    Token _token = _tokenStream.GetToken();
    // iteratively evaluate the right side and add to the left side.
    while (true) {
        switch (_token.kind) {
            // evaluate addition term.
            case '+':
                _left = _left + EvaluateTerm();
                _token = _tokenStream.GetToken();
                break;
            // evaluate substraction term.
            case '-':
                _left = _left + EvaluateTerm();
                _token = _tokenStream.GetToken();
                break;
            // return  unused token.
            default:
                _tokenStream.PutBack(_token);
                return _left;
        }
    }
}

double EvaluateTerm () {
    // the prior primary is left of the current Term.
    double _left = EvaluatePrimary();
    // init token stream to translate charachters into operands.
    TokenStream _tokenStream;
    Token _token = _tokenStream.GetToken();
    // iteratively evalute the right and operate on the left side.
    while (true) {
        switch (_token.kind) {
            // evaluate multiplication term.
            case '*':
                // scale multiplication on left term.
                _left = _left * EvaluatePrimary();
                // update token.
                _token = _tokenStream.GetToken();
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
                    _token = _tokenStream.GetToken();
                    break;
                }
            // return unused token to stream.
            default:
                _tokenStream.PutBack(_token);
                return _left;
        }
    }
}

double EvaluatePrimary() {
    TokenStream _tokenStream;
    Token _token = _tokenStream.GetToken();
    switch (_token.kind) {
        case '(':
            {
                double _value = EvaluateExpression();
                _token = _tokenStream.GetToken();
                if (_token.kind != ')') {
                    throw std::runtime_error("expected ')'.");
                }
                return _value;
            }
        case '8':
            return _token.value;
        default:
            throw std::runtime_error("primary expected.");
    }
}

int32_t main () {
    // place holder for expression value.
    double _value {0};
    // stream of tokens processor.
    TokenStream _tokenStream;
    try {
        // continue until console input terminates.
        while (std::cin) {
            Token _token = _tokenStream.GetToken();
            // quite program if stop command is reached.
            if (_token.kind == 'q') {
                return EXIT_SUCCESS;
            }
            // send output if statement end is reached.
            if (_token.kind == ';') {
                std::cout << "=" << _value << std::endl;
            } else {
                _tokenStream.PutBack(_token);
            }
            // evaluate the next expression.
            _value = EvaluateExpression();
        }
    } catch (std::exception& errorRef ) {
        std::cerr << errorRef.what() << std::endl;
        return EXIT_FAILURE;
    }
    // exit success.
    return EXIT_SUCCESS;
}