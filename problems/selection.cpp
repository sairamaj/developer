#include <iostream> 

using namespace std;

void sort(int source[], int size){
    for(int i=0; i<size; i++){
        for(int k=i+1; k<size; k++){
            if( source[i] > source[k]){
                int temp = source[i];
                source[i] = source[k];
                source[k] = temp;
            }
        }
    }
}


void main()
{
    int num[8] = {1,4,5,2,0,1,6,3};

    for(int i=0; i<sizeof(num)/sizeof(int); i++)
    {
        cout << num[i] << endl;
    }

    sort(num, sizeof(num)/sizeof(int));

    cout << "After sort " << endl;

    for(int i=0; i<sizeof(num)/sizeof(int); i++)
    {
        cout << num[i] << endl;
    }
}