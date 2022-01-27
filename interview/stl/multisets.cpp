#include <iostream>
#include <set>
using namespace std;

void testBasics()
{
    multiset<int, greater<int>> val = {6,10,5,1,1,1,1,1};

    for(auto iter = val.begin(); iter != val.end(); iter++){
        cout << *iter << endl;
    }
}

void main()
{
    testBasics();    
}