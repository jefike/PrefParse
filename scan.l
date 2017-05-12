%{
  #include "global.h"
%}
%option noyywrap
ws [\t \n]+


%%

{ws}  { /* skip whitespace */}
"and" { /* skip */}
"anything"  {return ANY;}
"chicken"   {return CHK;}
"shrimp"    {return SHR;}
"pasta"     {return PAS;}
"potatoes"  {return POT;}
"appetizer" {return APP;}
"dessert"   {return DES;}
"soup"      {return SOU;}
"salad"     {return SAL;}
"<"         {return '<';}
"|"         {return '|';}
">"         {return '>';}
<<EOF>>     {return DONE;}
. {printf("Invalid token: [%s]\n", yytext);}
%%
