#include <iostream>
#include <vector>
using namespace std;


void printVector(vector<int> &result)
{
    cout << result[0];
    for (int i = 1; i < result.size(); ++i)
        cout << " " << result[i];
    cout << endl;
}

void recursiveCombination(vector<int> &stack, int *arrayPtr, int amount, int choose)
{
    if (choose == 1)
    {
        for (int i = 0; i < amount; i++)
        {
            stack.push_back(arrayPtr[i]);
            printVector(stack);
            stack.pop_back();
        }
    }
    else
    {
        for (int i = 0; i < amount; i++)
        {
            stack.push_back(arrayPtr[i]);
            recursiveCombination(stack, arrayPtr + 1 + i, amount - 1 - i, choose - 1);
            stack.pop_back();
        }
    }
}

void PrintCombination(int *arrayPtr, int amount, int choose)
{
    vector<int> stack;
    recursiveCombination(stack, arrayPtr, amount, choose);
}

#define ELEMENTS_FOR_COMBINATION 10
#define DLEMENTS_FOR_CHOICE 8
int main(void)
{
    int *arrayPtr = new int[ELEMENTS_FOR_COMBINATION];  // Get all elements for combination
    for (int i = 0; i < ELEMENTS_FOR_COMBINATION; ++i)
        arrayPtr[i] = i + 1;
    PrintCombination(arrayPtr, ELEMENTS_FOR_COMBINATION, DLEMENTS_FOR_CHOICE);
    if (arrayPtr != NULL)
        delete[] arrayPtr;
    return 0;
}