#include <vector>
using namespace std;

/*
    Using new for loop  
*/
void main()
{
    vector<int> map(101, 0);

    // Using new for loop
    for (int m : map)
    {
        printf("%d\n", m);
    }
}