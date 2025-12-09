#include <stdio.h>

// check if an input is a valid password: only alphabet or digit, 8 or more characters
int main()
{
	char ch;
	int is_valid = 1;
	int count =0;
        printf("Enter input: ");
	ch = getchar();
	
	while(ch != '\n'){
	   if(!((ch >='a'&& ch<='z') ||(ch>='A'&&ch<='Z') || (ch>='0' && ch<='9')))
		is_valid = 0;	
	   count++;	
	   ch = getchar();
		
	}

	if(count <8 ) is_valid = 0; 
	if(is_valid) printf("Valid");
	else printf("Invalid");
		
	return 0;
}
