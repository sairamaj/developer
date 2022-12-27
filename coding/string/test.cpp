#include <iostream>
using namespace std;

template<class T>
class Arthimetic
{
private:
    T a;
    T b;

public:
    Arthimetic(T a, T b)
    {
        this->a = a;
        this->b = b;
    }

    T sum()
    {
        return a + b;
    }
};


void main()
{
    Arthimetic<int> x(10, 20);
    Arthimetic<double> y(10.2, 20.2);

    printf("%d\n", x.sum());
    printf("%f\n", y.sum());
}