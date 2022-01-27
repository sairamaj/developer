#include <iostream>
#include <set>
using namespace std;

void testBasics()
{
    set<int> val = {6,10,5,1,1,1,1,1};

    for(auto iter = val.begin(); iter != val.end(); iter++){
        cout << *iter << endl;
    }
    
    cout << "_____________________" << endl;
    cout << *(val.lower_bound(5)) << endl;
    cout << "_____________________" << endl;
    cout << *(val.upper_bound(5)) << endl;
}

void main()
{
    testBasics();    
}