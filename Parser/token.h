// only include one copy.
#pragma once
// constant expression known at compile time to represent 'number' type.
constexpr char NUMBER_TYPE ='8';
// Token represents an individual term (number/symbol) in an equation.
class Token {
    public:
        // token type (number, operand, associative)
        char kind;
        // value, if numeric
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