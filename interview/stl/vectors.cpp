#include <iostream>
#include <vector>
#include <algorithm>

bool myfunction(int i, int j) { return (i < j); }
struct myclass
{
    bool operator()(int i, int j) { return (i < j); }
} myobject;
using namespace std;

void sortExample(vector<int> intArray)
{
    // https://www.cplusplus.com/reference/algorithm/sort/
    // sort
    cout << "___________ sort ascending_____________" << endl;
    sort(intArray.begin(), intArray.end());
    for (int i = 0; i < intArray.size(); i++)
    {
        cout << i << " " << intArray[i] << endl;
    }

    cout << "___________ sort desending_____________" << endl;
    sort(intArray.begin(), intArray.end(), greater<int>());
    for (int i = 0; i < intArray.size(); i++)
    {
        cout << i << " " << intArray[i] << endl;
    }

    cout << "___________ sort custom _____________" << endl;
    sort(intArray.begin(), intArray.end(), myfunction);
    for (int i = 0; i < intArray.size(); i++)
    {
        cout << i << " " << intArray[i] << endl;
    }

    cout << "___________ sort custom 2_____________" << endl;
    sort(intArray.begin(), intArray.end(), myobject);
    for (int i = 0; i < intArray.size(); i++)
    {
        cout << i << " " << intArray[i] << endl;
    }
}

void createExamples()
{
    vector<int> intArray;

    intArray.push_back(1);
    intArray.push_back(5);
    intArray.push_back(3);

    for (int i = 0; i < intArray.size(); i++)
    {
        cout << i << " " << intArray[i] << endl;
    }

    vector<int> intArray2 = {10, 20, 30, 40};
    for (int i = 0; i < intArray2.size(); i++)
    {
        cout << i << " " << intArray2[i] << endl;
    }
    cout << "_____________________" << endl;

    vector<int> intArray3 = intArray2;
    for (int i = 0; i < intArray3.size(); i++)
    {
        cout << i << " " << intArray2[i] << endl;
    }
    cout << "_____________________" << endl;

    int myints[] = {32, 71, 12, 45, 26, 80, 53, 33};
    std::vector<int> myvector(myints, myints + 8);

    for (int i = 0; i < myvector.size(); i++)
    {
        cout << i << " " << myvector[i] << endl;
    }
}

void miscExamples()
{
    std::vector<int> myvector = {1, 2, 3};

    for (int i = 0; i < myvector.size(); i++)
    {
        cout << i << " " << myvector[i] << endl;
    }

    cout << "_________Reverse____________" << endl;
    reverse(myvector.begin(), myvector.end());
    for (int i = 0; i < myvector.size(); i++)
    {
        cout << i << " " << myvector[i] << endl;
    }

    cout << "front " << myvector.front() << endl;
    cout << "back " << myvector.back() << endl;

    // inintialize
    cout << "_________Initialize____________" << endl;
    vector<int> v;
    v.assign(7, 100);
    for (int i = 0; i < v.size(); i++)
    {
        cout << i << " " << v[i] << endl;
    }
}

void stringSamples()
{
    std::vector<string> array = {"a1", "b1", "c1"};
    for (int i = 0; i < array.size(); i++)
    {
        printf("%s\n", array[i].c_str());
    }
    printf("______________________\n");
}

void testBasics()
{
    // adding and listing
    vector<int> intArray;

    intArray.push_back(1);
    intArray.push_back(5);
    intArray.push_back(3);

    for (int i = 0; i < intArray.size(); i++)
    {
        cout << i << " " << intArray[i] << endl;
    }

    cout << "_____________________" << endl;
    vector<int>::iterator iter;
    for (iter = intArray.begin(); iter != intArray.end(); iter++)
    {
        cout << *iter << endl;
    }
    cout << "_____________________" << endl;

    // accessing random elements
    cout << intArray[2] << endl;

    sortExample(intArray);
}

void main()
{
    testBasics();
    cout << "_____________________" << endl;
    createExamples();
    cout << "_____________________" << endl;
    miscExamples();
    cout << "_____________________" << endl;
    stringSamples();
}