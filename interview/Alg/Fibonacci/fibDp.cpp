/*
    Fib recursive with Memoized.
*/
#include <stdio.h>
#include <chrono>
#include <memory.h>
#include <string>
using namespace std::chrono;
using namespace std;

class FibCalculator
{
private:
    long long *memoized;
    long long fibNumber;

    long long findFibNumber(int n)
    {
        int result;
        if (n == 1 || n == 2)
        {
            result = 1;
        }
        else
        {
            if (this->memoized[n] != 0)
            {
                return this->memoized[n];
            }
            result = findFibNumber(n - 1) + findFibNumber(n - 2);
            this->memoized[n] = result;
        }
        return result;
    }

public:
    FibCalculator(int n)
    {
        this->memoized = new long long[n + 1];
        memset(this->memoized, 0, sizeof(long long) * (n + 1));
        this->fibNumber = findFibNumber(n);
        delete[] this->memoized;
    }

    int getNumber()
    {
        return this->fibNumber;
    }
};

void main(int argc, char *argv[])
{
    int input = stoi(argv[1]);

    auto start = high_resolution_clock::now();
    long long num = FibCalculator(input).getNumber();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    printf("input:%d value:%llu time Taken:%llu\n", input, num, duration.count());
}