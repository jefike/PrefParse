#include "global.h"

void parse2(int key[8], int next_tok){
      switch(next_tok){
	/////////////// PROTEIN /////////////////////////
      case CHK:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == SHR){
	    key[6] = 0;
	    generate_pairs(key,PROTEIN); // Generate pairs for 0000
	  }
	  else{
	    printf("Invalid comparison. Expected protein, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == SHR){
	    key[6] = 1;
	    generate_pairs(key, PROTEIN); // Generate for 0000
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end CHK
      case SHR:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == CHK){
	    key[6] = 1;
	    generate_pairs(key, PROTEIN); // Generate for 0010
	  }
	  else{
	    printf("Invalid comparison. Expected protein, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == CHK){
	    key[6] = 0;
	    generate_pairs(key, PROTEIN); // Generate for 0010
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end SHR
	//////////////// End PROTEIN //////////////////////
	/////////////// SIDE //////////////////////////////
      case PAS:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == POT){
	    key[7] = 0;
	    generate_pairs(key,SIDE); // Generate pairs for 0000
	  }
	  else{
	    printf("Invalid comparison. Expected side, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == POT){
	    key[7] = 1;
	    generate_pairs(key, SIDE); // Generate for 0001
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end PAS
      case POT:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == PAS){
	    key[7] = 1;
	    generate_pairs(key, SIDE); // Generate for 0001
	  }
	  else{
	    printf("Invalid comparison. Expected Side, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == PAS){
	    key[7] = 0;
	    generate_pairs(key, SIDE); // Generate for 0000
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end POT	
	/////////////// END SIDE ///////////////////////////
	/////////////// OPTIONAL //////////////////////////////
      case DES:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == APP){
	    key[4] = 1;
	    generate_pairs(key, OPTIONAL); // Generate pairs for 1000
	  }
	  else{
	    printf("Invalid comparison. Expected Optional plate, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == APP){
	    key[4] = 0;
	    generate_pairs(key, OPTIONAL); // Generate for 0000
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end DES
      case APP:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == DES){
	    key[4] = 0;
	    generate_pairs(key, OPTIONAL); // Generate for 0000
	  }
	  else{
	    printf("Invalid comparison. Expected Optional plate, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == DES){
	    key[4] = 1;
	    generate_pairs(key, OPTIONAL); // Generate for 0000
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end APP	
	/////////////// END OPTIONAL ///////////////////////////
	/////////////// STARTER  //////////////////////////////
      case SOU:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == SAL){
	    key[5] = 0;
	    generate_pairs(key,STARTER); // Generate pairs for 0000
	  }
	  else{
	    printf("Invalid comparison. Expected Starter, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == SAL){
	    key[5] = 1;
	    generate_pairs(key, STARTER); // Generate for 0100
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end SOU
      case SAL:
	if((next_tok = yylex()) == '>'){
	  if((next_tok = yylex()) == SOU){
	    key[5] = 1;
	    generate_pairs(key, STARTER); // Generate for 0100
	  }
	  else{
	    printf("Invalid comparison. Expected Starter, found other.");
	    exit(1);
	  }
	}// end if
	else if(( next_tok = yylex()) == '<'){
	  if((next_tok = yylex()) == SAL){
	    key[5] = 0;
	    generate_pairs(key, STARTER); // Generate for 0000
	  }
	}
	else{
	  printf("Error: Invalid preference expression.");
	  exit(1);
	}
	break;
	//end SAL	
	/////////////// END STARTER ///////////////////////////
      default:
	printf("Error. Invalid preference expression.");
	exit(1);
      }//end switch


}
