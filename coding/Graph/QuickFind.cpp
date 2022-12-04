#include <stdio.h>
class QuickFindGraph
{
private:
    int array[10];

public:
    QuickFindGraph()
    {
        for (int i = 0; i < 10; i++)
        {
            this->array[i] = i;
        }
    }

    void Union(int v1, int v2)
    {
        int rootV1 = this->Find(v1);
        int rootV2 = this->Find(v2);

        if (rootV1 == rootV2)
        {
            return;
        }

        for (int i = 0; i < sizeof(array) / sizeof(int); i++)
        {
            if (this->array[i] == rootV2)
            {
                this->array[i] = rootV1;
            }
        }
    }

    bool Check(int v1, int v2)
    {
        return this->array[v1] == this->array[v2];
    }

    int Find(int v)
    {
        return this->array[v];
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
    QuickFindGraph graph;
    graph.Print();
    graph.Union(0, 1);
    graph.Print();
    graph.Union(0, 2);
    graph.Print();
    graph.Union(1, 3);
    graph.Print();
    graph.Union(1, 4);
    graph.Print();
    graph.Union(2, 5);
    graph.Print();
    graph.Union(2, 6);
    graph.Print();

    printf("%d\n", graph.Check(0, 3));
    printf("%d\n", graph.Check(1, 5));
    printf("%d\n", graph.Check(7, 8));
}

void main()
{
    test();
}
