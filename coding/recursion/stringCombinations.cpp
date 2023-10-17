/*
    input: abc
    ouput:
        a,ab,ac,abc,b,bc,c

                abc
        a(bc)       (bc)
    a     ab  ac    b    bc
        
    
*/
#include <stdio.h>
#include <string.h>

void print(char *input)
{
    char output[100];
    for (int i = 0; i < strlen(input); i++)
    {
        int k=0;
        output[k] = input[i];
        output[k+1] = '\0';
        printf("%s\n", output);
        k++;
        for (int j = i+1; j < strlen(input); j++)
        {
            output[k] = input[j];
            output[k+1] = '\0';
            printf("%s\n", output);
            k++;
        }
    }
}

void main()
{
    char input[100];
    strcpy(input, "abc");
    print(input);
}