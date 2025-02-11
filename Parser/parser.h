// only include one copy.
#pragma once
// evaluate plus and minus, call term() and get_token()
double EvaluateExpression(TokenStream& _tokenStreamRef);
// evaluate multiply, divide, and modulo, call primary() and get_token()
double EvaluateTerm(TokenStream& _tokenStreamRef);
// evaluate numbers and parentheses, call expression() and get_token()
double EvaluatePrimary(TokenStream& _tokenStreamRef);