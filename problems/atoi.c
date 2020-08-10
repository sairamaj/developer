#include <stdio.h>

int convert(char *data){
    int len = strlen(data);
    char *ptr = data + len-1;
    int i = len;
    int value = 0;
    int asciiZero = 48;
    int place =1;
    while(i >0 ){
        printf("%c-%d\n", *ptr, *ptr);
        int digit = (int)*ptr - asciiZero;
        value += (digit* place);
        i--;
        ptr--;
        place = place * 10;
    }

    return value;

}
void main(){
    char data[20];
    printf("value to convert:");
    scanf("%s", data);

    int val = convert(data);
    printf("val:%d", val);
}