#include <iostream>
#include <map>
using namespace std;

void testBasics()
{
    map<int,int> m;
    m.insert(pair<int,int>(1,40));
    m[2] = 50;

    for(auto iter =m.begin(); iter != m.end(); iter++){
        cout << (*iter).first << ":" << (*iter).second << endl;
    }

    if(m.find(1) != m.end()){
        cout << "found : 1:" << m[1] << endl;
    }
}

void main()
{
    testBasics();    
}