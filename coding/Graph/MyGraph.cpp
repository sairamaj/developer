/*
 Notes: Trying to come up with my own implementation after reading about disjoint data structure.
*/

/*
    Implementation:
        array initialized to its index
        [0,1,2,3,4,5,6,7,8,9]
        Union(int v1, int v2)
        0,1
            - select root - 0
            - update at index[1] to 0
            [0,0,2,3,4,5,6,7,8,9]
        0,2
            - select root-0
            - update at index[2] = 0
            [0,0,2,3,4,5,6,7,8,9]
        1,3
            - select root as 1
            - get head of 1-> 0
            - update [3] to 0
            [0,0,0,0,4,5,6,7,8,9]
        Find(int v1)
            - get the value at [v1]
            - if same then return it
            - if not get the index of v1 and get the root
            2
                - value at 2: 0
                - value at 0 is :0 so root is 0
                (looks like we can use recrusion)
        Print
            - Print the array with its index and value.

*/

#include <stdio.h>
class MyGraph
{
private:
    int array[10];

public:
    MyGraph()
    {
        for (int i = 0; i < sizeof(array) / sizeof(int); i++)
        {
            array[i] = i;
        }
    }
    void Union(int v1, int v2)
    {
        int root = v1;
        array[v2] = this->Find(root);
    }

    int Find(int v1)
    {
        // get value at v1
        int val = array[v1];
        if (val == v1)
        {
            return v1;
        }
        
        return Find(val);
    }

    bool Check(int v1, int v2){
        return this->Find(v1) == this->Find(v2);
    }
    void Print()
    {
        for (int i = 0; i < sizeof(array) / sizeof(int); i++)
        {
            printf("%d-%d|", i, array[i]);
        }
        printf("\n");
    }
};

void test()
{
    MyGraph graph;
    graph.Print();
    graph.Union(0, 1);
    graph.Print();
    graph.Union(0, 2);
    graph.Print();
    graph.Union(1, 3);
    graph.Print();
    graph.Union(4, 8);
    graph.Print();
    graph.Union(5, 6);
    graph.Print();
    graph.Union(5, 7);
    graph.Print();

    printf("%d\n",graph.Check(0,3));
    printf("%d\n",graph.Check(1,5));
    printf("%d\n",graph.Check(7,8));
}

void main()
{
    test();
}