/*
    goal:
        maximize the rob money.
    condition:
        cannot rob next consecuitve homes.
    strategy
        using dp
            {1,2,3,1}
               1     2     3     1
            {3,1}   {1}   {1}  {1}
            [4,3,1,1]

            [1,2,4,3]

            c1 = 0,c2=0
            [1,]
            c1=sum; c2=c1  (c1=1, c2=0)
            val+c2;
            [1,2]
            c1=2 c2=1
            [1,2,4]
            c1=4 c2=2
            [1,2,4,3]

            // recursive
                [1,2,3,1]
                  1
                {3,1}
*/
#include <stdio.h>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>>

using namespace std;
class Solution
{
    map<int,int> _memo;
public:
    int rob2(vector<int> &nums, int i)
    {
        if (i >= nums.size())
        {
            return 0;
        }

        if(_memo.find(i) != _memo.end()){
            //cout << "returning from cache for: " << i << "val:" << _memo[i] << endl;
            return _memo[i];
        }

        // dp(i,0) = max( dp(i+1,0) , dp(i+1,1))
        // the max at ith location is 
            // max of , (rob the next house , not rob the house)
        // find max if next house is robbed
        int robbedNextHouse = rob2(nums,i+1);
        int notRobbedNextHouse = nums[i] + rob2(nums,i+2);

        auto val = max(robbedNextHouse,notRobbedNextHouse);
        //cout << "caching for: " << i << "val:" << val << endl;
        _memo[i] = val;
        return val;
    }

    int rob(vector<int> &nums)
    {

        vector<int> sums;
        int c1 = 0;
        int c2 = 0;
        int max = INT32_MIN;
        for (vector<int>::iterator iter = nums.begin(); iter != nums.end(); iter++)
        {
            auto current = *iter + c2;
            c2 = c1;
            sums.push_back(current);
            c1 = current;
            if(current > max){
                max = current;
            }
        }

        return max;
    }

    void print(string title, vector<int> &data)
    {
        cout << "------------- " << title.c_str() << "--------------" << endl;
        for (vector<int>::iterator iter = data.begin(); iter != data.end(); iter++)
        {
            cout << *iter << " ";
        }

        cout << endl;
    }
};

void main()
{
    Solution s;
    vector<int> nums;
    nums.push_back(2);
    nums.push_back(7);
    nums.push_back(9);
    nums.push_back(3);
    nums.push_back(1);
    cout << s.rob(nums) << endl;
    cout << s.rob2(nums, 0) << endl;
}