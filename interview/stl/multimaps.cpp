#include <iostream>
#include <map>
using namespace std;

// Multimap is similar to a map with the addition that multiple elements can have the same keys. Also, it is NOT required that the key-value 
// and mapped value pair have to be unique in this case. One important thing to note about multimap is that multimap keeps all the keys in sorted order always. 
// These properties of multimap make it very much useful in competitive programming
void testBasics()
{
    multimap<int,int> m;
    m.insert(pair<int,int>(1,40));
    m.insert(pair<int,int>(1,50));
    m.insert(pair<int,int>(0,0));

    for(auto iter =m.begin(); iter != m.end(); iter++){
        cout << (*iter).first << ":" << (*iter).second << endl;
    }

    if(m.find(1) != m.end()){
        cout << "found : 1:" << endl;
    }
}

void main()
{
    testBasics();    
}