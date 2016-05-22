%{
#include "nodes.h"

Block *programBlock; /* the top level root node of our final AST */

int yyerror(char *s);
int yylex(void);
%}

/* Represents the many different ways we can access our data */
%union {
    Node    *node;
    Block   *block;
    Stmt    *stmt;
    VarDecl *var_decl;
    Ident   *ident;
    std::string *string;
    int      token;
}

%token <string> TIDENTIFIER TINTEGER TDOUBLE
%token <token> TCEQ TCNE TCLT TCLE TCGT TCGE TEQUAL
%token TSEMICOLON ";"

/* Define the type of node our nonterminal symbols represent.
   The types refer to the %union declaration above. Ex: when
   we call an ident (defined by union type ident) we are really
   calling an (NIdentifier*). It makes the compiler happy.
 */

%type <block> program
%type <block> stmts
%type <stmt> stmt
%type <stmt> var_decl
%type <ident> ident

%%

program : stmts			{ programBlock = $1; }

stmts : stmt ';'		{ $$ = new Block(); $$->statements.push_back($1); }
	| stmts stmt ';'	{ $1->statements.push_back($2); }
	;

stmt : var_decl
	 ;

var_decl : ident ident { $$ = new VarDecl($1, $2); }
		 ;

ident : TIDENTIFIER { $$ = new Ident(*$1); delete $1; }
	  ;

%%

int yyerror(std::string s)
{
	extern int yylineno;	// defined and maintained in lex.c
	extern char *yytext;	// defined and maintained in lex.c

	std::cerr << "!ERROR: " << s << " at symbol \"" << yytext;
	std::cerr << "\" on line " << yylineno << std::endl;
	exit(1);
}

int yyerror(char *s)
{
	return yyerror(std::string(s));
}
