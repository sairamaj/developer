/*
Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.

Implement the MovingAverage class:

MovingAverage(int size) Initializes the object with the size of the window size.
double next(int val) Returns the moving average of the last size values of the stream.

Example 1:

Input
    ["MovingAverage", "next", "next", "next", "next"]
    [[3], [1], [10], [3], [5]]
    Output
    [null, 1.0, 5.5, 4.66667, 6.0]

    Explanation
    MovingAverage movingAverage = new MovingAverage(3);
    movingAverage.next(1); // return 1.0 = 1 / 1
    movingAverage.next(10); // return 5.5 = (1 + 10) / 2
    movingAverage.next(3); // return 4.66667 = (1 + 10 + 3) / 3
    movingAverage.next(5); // return 6.0 = (10 + 3 + 5) / 3
*/

/*
    Strategy:
        Keep track of queue
        in next add it to the queue
        pop from queue and get average
        push back the data
ex:
    [0,0,0]
    curpos=0;
    1 -> [1,0,0] curpos=1
    10-> [1,10,0] curpos=2
    3 -> [1,10,3] curpos=3  curpos=0
    5 -> [5,10,3] curpos=1
    6 -> [5,6,3]
*/
/*
    My solution:
        added custom complexity
        sum is being calculated all the time
    Leet code
        used built-in queue
        sum is only calulcated one time
        each time reduce the front and added new value to calculate avg.
*/

#include <iostream>
#include <queue>
#include <limits>
#include <cfloat>
using namespace std;


class MovingAverage2
{
    int size, curPos, actualSize;
    int *data;

public:
    MovingAverage2(int size)
    {
        this->data = new int[size];
        memset(this->data, 0, sizeof(int) * size);
        this->size = size;
        this->curPos = 0;
        this->actualSize = 0;
    }

    double next(int val)
    {
        int sum = 0;
        this->data[this->curPos++] = val;
        if (this->curPos == this->size)
        {
            this->curPos = 0; // start overwriting.
        }
        for (int i = 0; i < this->size; i++)
        {
            sum += this->data[i];
        };
        this->actualSize++;
        return ((double)sum) / ((double)(this->actualSize > size ? size : this->actualSize));
    }
};

class MovingAverage 
{
    queue<int> stream;
    int elements;
    int sum;
    
public:
    MovingAverage(int size) 
    {
        elements = size;
        sum = 0;
    }
    
    double next(int val) 
    {        
        if (stream.size() == elements)
        {
            sum -= stream.front();
            stream.pop();
        }
        sum += val;
        stream.push(val);
        return (sum / (double)stream.size());
    }
};
void assert(char *msg, double expected, double actual)
{
    if (fabs(expected-actual) < 0.001 )
    {
        printf("[success] %s\n", msg);
    }
    else
    {
        printf("[failed] %s expected:%lf actual:%lf\n", msg, expected, actual);
    }
}
void test()
{
    MovingAverage mavg(3);
    assert("only 1", 1.0, mavg.next(1));
    assert("only 1+10", 5.5, mavg.next(10));
    assert("only 1+10+3", 4.666667, mavg.next(3));
    assert("only 1+10+3+5", 6.0, mavg.next(5));
}

void main()
{
    test();
}