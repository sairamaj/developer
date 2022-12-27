#include <stdio.h>

bool isVowel(char ch){
    if(ch == 'a' || ch == 'A' || ch == 'e' || ch == 'E' || ch == 'i' || ch == 'I' || ch == 'o' || ch == 'O' || ch == 'u' || ch == 'U'){
        return true;
    }

    return false;
}
void main()
{
    char str[] = "How     are          you";

    int words = 1;
    int vowels = 0;
    char*ptr  = str;
    bool alreadySpace = false;
    while(*ptr){
        if(*ptr == ' '){
            if(!alreadySpace)
            {
                words++;
                alreadySpace = true;
            }
        }else{
            alreadySpace = false;
        }
        if(isVowel(*ptr)){
            vowels++;
        }
        ptr++;        
    }

    printf("Words:%d vowels:%d\n",words,vowels);
}