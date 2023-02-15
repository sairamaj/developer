#include <iostream>
#include <string>

using namespace std;

bool isPalindromeRecursion2(string s, int i, int j){
    if(i == j){
        return true;
    }
    if(s[i] == s[j] && isPalindromeRecursion2(s, i+1, j-1)){
        return true;
    }

    return false;
}
bool isPalindromeRecursion(string s){
    return isPalindromeRecursion2(s,0,s.size()-1);
}
bool isPalindromeNoRecursion(string s){
    int i=0;
    int j=s.size()-1;
    while(i<=j){
        if(s[i] != s[j]){
            return false;
        }
        i++;
        j--;
    }

    return true;
}

void main()
{
    string s;
    cout << "enter a string";
    cin >> s;

    cout << "______No recursion___________" << endl;
    cout << isPalindromeNoRecursion(s) << endl;

    cout << "______Recursion___________" << endl;
    cout << isPalindromeRecursion(s) << endl;
}