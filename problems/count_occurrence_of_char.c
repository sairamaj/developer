#include <stdio.h>

int getCount(char *text, char ch){
    char *ptr = text;
    int count = 0;
    while(*ptr != '\0'){
        if( *ptr == ch){
            count++;
        }
        ptr++;  
    }
    
    return count;
}
void main()
{
    char text[20];

    strcpy(text,"this is text");
    int count = getCount(text,'i');
    printf("count: %d\n", count);
}