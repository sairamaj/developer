#include <list>
#include <iostream>
#include <algorithm>
using namespace std;

void testBasics()
{
    list<string> ls;
    ls.push_back("a1");
    ls.push_back("c1");
    ls.push_back("b1");
    for(list<string>::iterator iter= ls.begin(); iter != ls.end(); iter++ ){
        cout << (*iter).c_str() << endl;
    }

    ls.sort();
    cout << "----------- Sort ----------------" << endl;
    for(list<string>::iterator iter= ls.begin(); iter != ls.end(); iter++ ){
        cout << (*iter).c_str() << endl;
    }

    ls.sort(greater<string>());
    cout << "----------- Sort Desending----------------" << endl;
    for(list<string>::iterator iter= ls.begin(); iter != ls.end(); iter++ ){
        cout << (*iter).c_str() << endl;
    }

    ls.reverse();
    cout << "----------- Reverse ----------------" << endl;
    for(list<string>::iterator iter= ls.begin(); iter != ls.end(); iter++ ){
        cout << (*iter).c_str() << endl;
    }

}

void main()
{
    testBasics();
}