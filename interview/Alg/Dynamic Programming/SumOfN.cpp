/*
    Demonasrates basic DP programming
    source: https://www.youtube.com/watch?v=KTDwvph8Tzo&list=PLVrpF4r7WIhTT1hJqZmjP10nxsmrbRvlf&index=3
*/
#include <iostream>
using namespace std;

int sumOfNIterativeDp(int n){
    int *dp = new int[n+1];
    dp[0] = 0;
    for(auto i=1; i<=n; i++){
        dp[i] = i + dp[i-1];        // f(i) = i + f(i-1)
    }

    int sum = dp[n];
    delete []dp;
    return sum;
}


int sumOfNIterative(int n){
    auto sum = 0;
    for(auto i=1; i<=n; i++){
        sum += i;
    }

    return sum;
}

void main()
{
    cout << "Sum of 2 " << sumOfNIterative(2) << endl;
    cout << "Sum of 5 " << sumOfNIterative(5) << endl;
    cout << "Sum of 10 " << sumOfNIterative(10) << endl;
    cout << "Sum of 1000000 " << sumOfNIterative(1000000) << endl;
    cout << "___________________________" << endl;

    cout << "Sum of 2 " << sumOfNIterativeDp(2) << endl;
    cout << "Sum of 5 " << sumOfNIterativeDp(5) << endl;
    cout << "Sum of 10 " << sumOfNIterativeDp(10) << endl;
    cout << "Sum of 1000000 " << sumOfNIterativeDp(1000000) << endl;

}