/* $Id$ */

%{



#undef YY_INPUT
#define YY_INPUT(buf, read, siz) (read = readcmd(buf, siz))
%}

%token SET
%token SHOW

%%

ident:		

set:		

show:		SHOW


%%

void
parsecmd(char *s)
{
	yyparse();
}

int
readcmd(char *buf, int siz)
{
	
	if (interactive) {
		
	} else {
		
	}
}
