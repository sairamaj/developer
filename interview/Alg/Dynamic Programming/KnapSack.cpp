#include <stdio.h>
#include <vector>
using namespace std;
void fillKnapSack(
    int *values,
    int valueSize,
    int *weights,
    int weightSize,
    int limit)
{
    // bruite force.
    // take each one and come up with combiation < limit
    // ex: 5 +4 =>50
    //  5+3  = 10+50 = 60
    // 4 + 6 - 70

    int currentTotalWeight = 0;
    int currentValue = 0;
    vector<int> finalOptimialWeights;
    int maxWeight = 0;
    for (auto i = 0; i < weightSize; i++)
    {
        currentTotalWeight = weights[i];
        vector<int> optimialWeights;
        currentValue = weights[i] * values[i];
        for (auto j = i+1; j < weightSize; j++)
        {
            auto weight = currentTotalWeight + weights[j];
            printf("weight:%d\n", weight);
            if (weight <= limit)
            {
                currentTotalWeight = weight;
                // then only collect
                currentValue += weights[j] * values[j];
                // collect
                optimialWeights.push_back(weights[j]);
            }
        }

        printf("max:%d current:%d\n", maxWeight, currentValue);
        // check
        if (maxWeight < currentValue)
        {
            // transfe = opr
            // copy vector: https://www.geeksforgeeks.org/ways-copy-vector-c/

            printf("________________\n");
            for (auto k = 0; k < optimialWeights.size(); k++)
            {
                printf("%d\n", optimialWeights[k]);
            }
            printf("________________\n");

            finalOptimialWeights = optimialWeights;
            maxWeight = currentValue;
        }
    }

    printf("-------------------------\n");
    // print final
    for (auto i = 0; i < finalOptimialWeights.size(); i++)
    {
        printf("%d\n", finalOptimialWeights[i]);
    }
    printf("-------------------------\n");
}

void main()
{
    int values[] = {10, 40, 30, 50};
    int weights[] = {5, 4, 6, 3};

    fillKnapSack(
        values,
        sizeof(values) / sizeof(int),
        weights,
        sizeof(weights) / sizeof(int),
        10);
}