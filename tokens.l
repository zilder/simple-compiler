%{
#include <string>
#include "nodes.h"
#include "gram.tab.h"
#define SAVE_TOKEN yylval.string = new std::string(yytext, yyleng)
#define TOKEN(t) (yylval.token = t)
extern "C" int yywrap() { }
%}

%%

[ \t\n]                 ;
[a-zA-Z_][a-zA-Z0-9_]*  SAVE_TOKEN; return TIDENTIFIER;
[0-9]+                  SAVE_TOKEN; return TINTEGER;
"=="                    return TOKEN(TCEQ);
"!="                    return TOKEN(TCNE);
"<="                    return TOKEN(TCLE);
">="                    return TOKEN(TCGE);
";"                     return yytext[0];
.                       printf("Unknown token!\n"); yyterminate();

%%
