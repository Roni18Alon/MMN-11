#include <stdio.h>
#include <ctype.h>

int main()
{
	int ch;
	int startOfSen=1;
	int inQuote=0 ;

	printf("\nWrite any text you want\n\n");
	ch=getchar();
	
	while (ch!= EOF) 							/*end of input*/
	{
		if (isdigit(ch) != 0)
		  	startOfSen = 0;						/*the char is a digit, hence next chart wont starts a sentence*/
				
		else 								/*not a digit, make additional checks*/
		{ 	
			if (isspace(ch) == 0)					/*if the char is a whitespace (!=0), print it and move to next char*/
			{
				if (startOfSen == 1 || inQuote == 1)
				{
					if (islower(ch) != 0)			/*if in starts sentence or a quote - turns lower letter to upper*/
	 					ch = toupper(ch);
				}
				else		
				{
					if (isupper(ch) != 0)  			/*convert upper to lower if needed */		
						 ch = tolower(ch);
				}
					
				startOfSen = 0;					/*not a whitespace, so next chart wont starts a sentence*/
			}
		putchar(ch);							/*prints the char*/
		if (ch =='.' && inQuote == 0) 
			 startOfSen = 1; 					/*a start of a sentence*/
		
		else{ if (ch =='"' && inQuote == 0) 
				 inQuote = 1; 					/*change status in a quote*/
				else if (ch =='"' && inQuote == 1) 				/*change status out of quote*/			
				inQuote = 0;
						
			}
	}			
		ch = getchar();	 						/*check the next char*/
	
	}
	return 0;
}

