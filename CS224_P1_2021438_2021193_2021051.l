%option noyywrap
%{
	#include <stdio.h>
	#include <stdlib.h>
	#include <string.h>
	int lineno = 1;
	void printToken(char *TOKEN);
	FILE * oFile; 
	FILE *iFile;
    void printOut(FILE *oFile);
	void yyerror();
%}

%x ML_COMMENT

alpha 		[a-zA-Z]
digit 		[0-9]
alnum 		{alpha}|{digit}
print		[ -~]

VARIABLE 		{alpha}+{alnum}*
INTCONST		"0"|[0-9]{digit}*

END_LINE		(\'\\[nftrbv]\')
STRING		\"{print}*\"
PREPROCESSOR "#include <"+{alpha}*+">"|"#include \""+{alnum}*+"."{alpha}*"\""|"#include <"+{alnum}*+"."{alpha}*""
DEFINE		"#define "+{alnum}*

%%

"//".*					{ printf("comment out single line %d\n", lineno); } 

"/*"					{ printf("Comment out starting line %d ", lineno); BEGIN(ML_COMMENT); }
<ML_COMMENT>"*/" 		{ printf("to line %d\n", lineno); BEGIN(INITIAL); }
<ML_COMMENT>[^*\n]+		
<ML_COMMENT>"*"			
<ML_COMMENT>"\n"		{ lineno += 1; }

"using namespace std"   {printToken("using_namespace_std");}
"switch"|"SWITCH"		{ printToken("KW_SWITCH"); }
"case"|"CASE"			{ printToken("KW_CASE"); }
"bool"|"BOOL"           { printToken("KW_BOOL"); }
"operator"|"OPERATOR"   { printToken("KW_OPERATOR"); }
"cout"|"COUT"       	{ printToken("KW_COUT"); }
"cin"|"CIN"          	{ printToken("KW_CIN"); }
"char"|"CHAR"       	{ printToken("KW_CHAR"); }
"friend"|"FRIEND"       { printToken("KW_FRIEND"); }
"delete"|"DELETE"       { printToken("KW_DELETE"); }
"long"|"LONG"           { printToken("KW_LONG"); }
"static"|"STATIC"       { printToken("KW_STATIC"); }
"const"|"CONST"         { printToken("KW_CONST"); }
"string"|"STRING"       { printToken("KW_STRING"); }
"int"|"INT"				{ printToken("KW_INT"); }
"float"|"FLOAT"			{ printToken("KW_FLOAT"); }
"double"|"DOUBLE"		{ printToken("KW_DOUBLE"); }
"if"|"IF"				{ printToken("KW_IF"); }
"else"|"ELSE"			{ printToken("KW_ELSE"); }
"while"|"WHILE"			{ printToken("KW_WHILE"); }
"do"|"DO"			    { printToken("KW_DO"); }
"for"|"FOR"				{ printToken("KW_FOR"); }
"continue"|"CONTINUE"	{ printToken("KW_CONTINUE"); }
"break"|"BREAK"			{ printToken("KW_BREAK"); }
"void"|"VOID"			{ printToken("KW_VOID"); }
"return"|"RETURN"		{ printToken("KW_RETURN"); }
"public"|"PUBLIC"		{ printToken("KW_PUBLIC"); }
"private"|"PRIVATE"		{ printToken("KW_PRIVATE"); }
"protected"|"PROTECTED"	{ printToken("KW_PROTECTED"); }


"+"					    { printToken("ADDOP"); }
"-"					    { printToken("SUBOP"); }
"*"						{ printToken("MULOP"); }
"/"						{ printToken("DIVOP"); }
"++"				    { printToken("INCR"); }
"--"				    { printToken("INCR"); }
"||"					{ printToken("OROR"); }
"|"					    { printToken("OR"); }
"&&"					{ printToken("ANDOP"); }
"!"						{ printToken("NOTOP"); }
"=="|"!="				{ printToken("EQUOP"); }
">"|"<"|">="|"<="		{ printToken("RELOP"); }
"<<"		            { printToken("INSERTIONOP"); }
">>"		            { printToken("EXTRACTIONOP"); }
"->"				    { printToken("ARROW"); }


"("				{ printToken("LPAREN"); }
")"				{ printToken("RPAREN"); }
"'"				{ printToken("SINGLEQUOTATION"); }
"]"				{ printToken("LBRACK"); }
"\\" 			{ printToken("BACKSLASH"); }
"["				{ printToken("RBRACK"); }
"~"				{ printToken("TILDE"); }
"{"				{ printToken("LBRACE"); }
"}"				{ printToken("RBRACE"); }
"_"				{ printToken("UNDERSCORE"); }
";"				{ printToken("SEMI"); }
"."				{ printToken("DOT"); }
":"				{ printToken("COLON"); }
","				{ printToken("COMMA"); }
"="				{ printToken("ASSIGN"); }
"&"				{ printToken("REFER"); }


{VARIABLE} 		{ printToken("VARIABLE"); }
{INTCONST} 		{ printToken("INT_CONST"); }
{END_LINE} 		{ printToken("END_LINE"); }
{STRING} 		{ printToken("STRING"); }
{PREPROCESSOR}  { printToken("PREPROCESSOR");}
{DEFINE}        { printToken("DEFINE");}


"\n"			{ lineno += 1; }
[ \t\r\f]+		

.				{ yyerror("Unrecognized character"); }

%%

void printToken(char *TOKEN){
	printf("Token: %s\ttoken_id: %s\tlineno: %d\n", yytext, TOKEN, lineno);
    fprintf(oFile,"%s, %s, %d\n", yytext, TOKEN, lineno);
}

void yyerror(char *message){
	printf("Error: \"%s\" in line %d. Token = %s\n", message, lineno, yytext);
	exit(1);
}

int main(int argc, char *argv[]){

	yyin = fopen("case4.cpp","r");
	
	if(yyin==NULL)
	{
		printf("ERROR Input source not found\n");
		exit(1);
	}
	oFile=fopen("output.csv", "w");
	yylex();
	fclose(yyin);
	return 0;
}