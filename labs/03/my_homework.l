%{
#include <stdio.h>
#include <string.h>
extern FILE *yyin, *yyout;
%}

Whitespace                         [" "|\t]*
AnyChar                            [a-zA-Z0-9]

%%
f                                  { fprintf(yyout,"floatdcl "); }
i                                  { fprintf(yyout,"intdcl "); }
[0-9]+"."[0-9]+                    { fprintf(yyout,"fnum "); }
[0-9]+                             { fprintf(yyout,"inum "); }
[a-eghj-oq-z]                      { fprintf(yyout,"id "); }
p                                  { fprintf(yyout,"print "); }
"\n"                               { fprintf(yyout,"\n");}
{Whitespace}                       { /* Ignore whitespaces */ }
\/\/.{AnyChar}*                      { /* Ignore comments */ }
"+"                                { fprintf(yyout,"plus "); }
"-"                                { fprintf(yyout,"minus "); }
"*"                                { fprintf(yyout,"mult "); }
"/"                                { fprintf(yyout,"div "); }
"="                                { fprintf(yyout,"assign "); }
%%

int main(int argc,char* argv[]) {
    //Read the input file given by the user
    yyin = fopen(argv[1],"r");
    //Create and write the lex output file
    yyout = fopen("lex.out","w");
    
    yylex();
    
    return 0;
}