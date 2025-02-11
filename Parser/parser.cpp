#include <iostream>
#include "token.h"
#include "parser.h"

// evaluate complete expressions into final result.
double Parser::EvaluateExpression (TokenStream& _tokenStreamRef) {
    // the prior evaluated expression is left of the current expression.
    double _left = Parser::EvaluateTerm(_tokenStreamRef);

    Token _token = _tokenStreamRef.GetToken();

    // iteratively evaluate the right side and add to the left side.
    while (true) {
        switch (_token.kind) {
            // evaluate addition term.
            case '+':
                _left = _left + Parser::EvaluateTerm(_tokenStreamRef);
                _token = _tokenStreamRef.GetToken();
                break;
            // evaluate substraction term.
            case '-':
                _left = _left - Parser::EvaluateTerm(_tokenStreamRef);
                _token = _tokenStreamRef.GetToken();
                break;
            // return  unused token.
            default:
                _tokenStreamRef.PutBack(_token);
                return _left;
        }
    }
}

// evalute the numeric value of a term.
double Parser::EvaluateTerm (TokenStream& _tokenStreamRef) {
    // the prior primary is left of the current Term.
    double _left = Parser::EvaluatePrimary(_tokenStreamRef);

    Token _token = _tokenStreamRef.GetToken();

    // iteratively evalute the right and operate on the left side.
    while (true) {
        switch (_token.kind) {
            // evaluate multiplication term.
            case '*':
                // scale multiplication on left term.
                _left = _left * Parser::EvaluatePrimary(_tokenStreamRef);
                // update token.
                _token = _tokenStreamRef.GetToken();
                break;
            // evaluate division term. 
            case '/':
                { // the curly brace 'block' is necessary since we define & init a variable (primary)
                    double _divisor = Parser::EvaluatePrimary(_tokenStreamRef);
                    // prohibit illegal division by zero.
                    if (_divisor == 0) {
                        throw std::logic_error("cannot divide by zero.");
                    }
                    // scale division on left term.
                    _left = _left / _divisor;
                    // update token.
                    _token = _tokenStreamRef.GetToken();
                    break;
                }
            // return unused token to stream.
            default:
                _tokenStreamRef.PutBack(_token);
                return _left;
        }
    }
}

// interpret the numeric value of a primary.
double Parser::EvaluatePrimary(TokenStream& _tokenStreamRef) {
    Token _token = _tokenStreamRef.GetToken();
    // iteratively evalute the right and operate on the left side.
    switch (_token.kind) {
        case '(':
            {
                double _value = Parser::EvaluateExpression(_tokenStreamRef);
                _token = _tokenStreamRef.GetToken();
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