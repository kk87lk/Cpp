#include <iostream>

using namespace std;

int maxsubseqsum(int A[], int N)
{
    int ThisSum = 0, MaxSum = 0;
    for (int i = 0; i < N; i++)
    {
        ThisSum += A[i];
        if (ThisSum > MaxSum)
            MaxSum = ThisSum;
        else if (ThisSum < 0)
            ThisSum = 0;
    }
    return MaxSum;
}

int main()
{
    int i = 0;
    cin >> i;
    int array[i];
    for (int u = 0; u < i; u++)
    {
        cin >> array[u];
    }
    int sum;
    sum = maxsubseqsum(array, i);
    std::cout << sum << '\n' <<std::endl;
}