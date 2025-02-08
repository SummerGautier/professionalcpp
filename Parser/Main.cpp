#include <cstdlib>
#include <cstdint>
#include <vector>
#include <iostream>

// represent the tokens.
class Token;
// read-in the tokens from terminal.
Token get_token();
// evaluate plus and minus, call term() and get_token()
double eval_expression();
// evaluate multiply, divide, and modulo, call primary() and get_token()
double eval_term();
// evaluate numbers and parentheses, call expression() and get_token()
double eval_primary();

class Token {
    public:
        char8_t kind;
        double value;
};

double eval_expression () {
    double left = eval_term();
    Token token = get_token();
    while (true) {
        switch (token.kind) {
            case '+':
                left += eval_term();
                token = get_token();
                break;
            case '-':
                left -= eval_term();
                token = get_token();
                break;
            default:
                return left;
        }
    }
}

int32_t main () {

    return EXIT_SUCCESS;
}