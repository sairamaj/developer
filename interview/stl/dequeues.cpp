#include <iostream>
#include <deque>
using namespace std;

void testBasics()
{
    deque<int> qs;

    qs.push_front(1);
    qs.push_front(2);

    cout << qs.at(0) << endl;
    cout << qs.at(1) << endl;

    cout << "--------- Listing --------------" << endl;
    for(auto iter = qs.begin(); iter != qs.end(); iter++){
        cout << *iter << endl;
    }

    cout << "--------- Listing REverse--------------" << endl;
    for(auto iter = qs.rbegin(); iter != qs.rend(); iter++){
        cout << *iter << endl;
    }

    qs.pop_front();
    cout << "--------- Pop done--------------" << endl;
    
    cout << qs.front() << endl;
    return;
}
void main()
{
    testBasics();
}