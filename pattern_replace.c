#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

//Assuption - strlen(pattern) >= strlen(replace)
//Assuption - character '*' is not in the input string (sentinel)


void remove_char(char* input, char c)
{
    char *read = input, *write = input;
    while (*read) {
        *write = *read++;
        //Increment write only if the current char is not the char to be deleted
        write += (*write != c); 
    }
    *write = '\0';
}

bool replace_substr(char* input, char* pattern, char* replace)
{
	char* temp = &input[0];
	int i=0, flag = 0, count = 0;
	while(*temp != '\0')
	{
		flag = 0, count = 0;
		if(strlen(temp) < strlen(pattern))
			break;
		while(strncmp(temp,pattern,strlen(pattern)) == 0)
		{
			temp+=strlen(pattern);
			count++;
			flag = 1;
		}
		if(flag)
		{
			temp-=count*strlen(pattern);
			strncpy(temp,replace,strlen(replace));
			temp+=strlen(replace);
			for(i=0; i<((count*strlen(pattern)) - strlen(replace)); i++, temp++)
				*temp = '*';
		}
		if(!flag)
			temp++;
	}
	input = temp - strlen(input);
	remove_char(input, '*');
	return 1;
}
int main(void) {
	// Find and Replace
	char input[50] = "abcabcxefabaabcabcabc";
	char pattern[5] = "abc";
	char replace[5] = "x";
	if(replace_substr(input,pattern,replace))
		printf("%s\n",input);
	else
		printf("Replace failed\n");	
	return 0;
}

