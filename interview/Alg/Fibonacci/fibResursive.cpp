/*
    Fib recursive
*/
#include <stdio.h>
#include <chrono>
#include <string>
using namespace std::chrono;
using namespace std;

//
// 1,1,2,3,5,8,13
//
long long getFibNumber(int n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    long long prev1 = getFibNumber(n - 1);
    long long prev2 = getFibNumber(n - 2);

    return prev1 + prev2;
}

void main(int argc, char* argv[])
{
    int input = stoi(argv[1]);
    auto start = high_resolution_clock::now();
    long long num = getFibNumber(input);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("input:%d value:%llu time Taken:%llu\n", input, num, duration.count());
}