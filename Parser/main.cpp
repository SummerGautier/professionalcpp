#include <cstdint>
#include <iostream>
#include "token.h"
#include "parser.h"

// execute Full Calculation Loop & Deal with Exceptions.
int32_t main () {
    TokenStream _tokenStream;
    // place holder for expression value.
    double _value {0};
    try {
        // continue until console input terminates.
        while (std::cin) {
            // prompt
            std::cout << "> ";
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
                // evaluate the next expression.
                _value = EvaluateExpression(_tokenStream);
            }
        }
    } catch (std::exception& errorRef ) {
        std::cerr << errorRef.what() << std::endl;
        return EXIT_FAILURE;
    }
    // exit success.
    return EXIT_SUCCESS;
}