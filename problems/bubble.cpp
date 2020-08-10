#include <iostream> 

using namespace std;

void sort(int source[], int size){
    for(int i=0; i<size; i++){
        bool swap = false;

        for(int k=0; k<size-1; k++){
            if( source[k] > source[k+1] ){
                int temp = source[k];
                source[k] = source[k+1];
                source[k+1] = temp;
                swap = true;
            }
        }
        if( swap == false){
            break;
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