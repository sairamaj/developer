/*
        aabba
        a|            a|                        a |                   a|                    a|
          a|            aa| b                     aab | ba              abb|a (X)              abba (Y)
            b|              aa| bb                   aabb|a (X)
              b|               aa| bba (x)
                a

        aa|
           b|
            b|
             a

*/
#include <vector>
#include <map>
#include <iostream>

using namespace std;
class Solution
{
  string s;
  map<int,vector<vector<string>>> _m;
public:
  vector<vector<string>> partition(string s)
  {
    this->s = s;
    return dp(0);
  }

private:
  vector<vector<string>> dp(int i)
  {
    cout << "---- dp-----" << i << endl;
    if(i == this->s.size()){
      return vector<vector<string>>();
    }

    if(_m.find(i) != _m.end()){
      return _m[i];
    }

    // start  partition
    vector<vector<string>> ps;
    for (int j = i; j < s.size(); j++)
    {
      if (isPalindrome(i, j))
      {
          vector<vector<string>> result = dp(j+1);
          auto sub = this->s.substr(i, j-i+1);
          for(auto &x: result){
            x.insert(x.begin(), sub);
          }
          if(result.empty()){
            result.push_back({sub});
          }

          for(auto x: result){
            ps.push_back(x);
          }
      }
    }

    _m[i] = ps;
    return ps;
  }

  bool isPalindrome(int i, int j)
  {
    cout << "palindrome: " << s.substr(i,j+1).c_str() << endl;
    while (i <= j)
    {
      if (this->s[i] != this->s[j])
      {
       //cout << "no palindrome" << endl;
        return false;
      }
      i++;
      j--;
    }
    //cout << "yes palindrome" << endl;
    return true;
  }
};

void main()
{
  Solution s;
  string s1 = "abbba";
  auto ps = s.partition(s1);
  // for (vector<vector<string>>::iterator iter = ps.begin(); iter != ps.end(); iter++)
  // {
  //   for (vector<string>::iterator iter1 = (*iter).begin(); iter1 != (*iter).end(); iter1++)
  //   {
  //     cout << (*iter1).c_str() << ",";
  //   }
  //   cout << endl;
  // }
  for (auto x : ps)
  {
    cout << "---------------------" << endl;
    for (auto y : x)
    {
      cout << y.c_str() << ",";
    }
    cout << endl;
    cout << "---------------------";
  }
}
