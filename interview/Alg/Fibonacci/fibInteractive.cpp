/*
    Fib interactive
*/
#include <stdio.h>
#include <chrono>
#include <string>
using namespace std::chrono;
using namespace std;

//
// 1,1,2,3,5,8,13
//
long long getFibNumber(long long n)
{
    if (n == 1 || n == 2)
    {
        return 1;
    }

    long long first = 1;
    long long second = 1;
    for (int i = 3; i < n; i++)
    {
        long long temp = first + second;
        first = second;
        second = temp;
        // f:1 s:1
        // f:1 s:2
        // f:2 s:3
        // f:3 s:5
    }

    return first + second;
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