#include <iostream>
#include <array>
using namespace std;

void testBasics()
{
    array<int,6> ar = {1,2,3,4,5,6};
    for(int i=0; i<6; i++){
        cout << ar.at(i) << endl;
    }

    cout << "_____________________" << endl;

    cout << get<0>(ar) << endl;
}

void main()
{
    testBasics();    

}