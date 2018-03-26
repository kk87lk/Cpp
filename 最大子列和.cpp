#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int maxsubseqsum1(int A[], int N)
{
    int ThisSum , MaxSum=0;
    int i, j, k;
    for (i = 0; i <= N; i++) {

        for (j = i; j <= N; j++) {
            ThisSum = 0;
            for (k = i; k <= j; k++) 
                ThisSum += A[k];
                if (ThisSum > MaxSum)
                    MaxSum = ThisSum;

        }
    }
    return MaxSum;
}
int maxsubseqsum2(int A[], int N)
{
    int ThisSum, MaxSum = 0;
    int i, j;
    for (i = 0; i <= N; i++) {
        ThisSum = 0;
        for (j = i; j <= N; j++) {
            ThisSum += A[j];
            if (ThisSum > MaxSum)
                MaxSum = ThisSum;
        }
    }
    return MaxSum;
}
int maxsubseqsum3(int A[], int N)
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
int maxsubseqsum4(int A[], int N)
{

}


int main()
{
    clock_t beginning, end;
    int array[7000];
    for (int i = 0; i < 7000; i++)
    {
        if (i == 0)
        {
            array[i] = 8;
        }
        else if ((i % 3) == 0)
        {
            array[i] = i * 2;
        }
        else if ((i % 3) == 1)
        {
            array[i] = i * 3;
        }
        else if ((i % 3) == 2)
        {
            array[i] = i * 1;
        }
    }
    for (int j = 0; j < 7000; j++)        //original array
    {
        std::cout << array[j] << " ";
    }
    std::cout << "\noriginal array" << '\n' <<std::endl;
//function block
    int res, num = 7000;
    double duration;
    beginning = clock();
    res = maxsubseqsum1(array, num);
    end = clock();
    std::cout << "Maxsubseqsum is " << res << '\n';
    std::cout << "\n" << '\n' << std::endl;
    duration = (double)(end - beginning) / CLOCKS_PER_SEC;
    std::cout << "time to do this function1 is " << duration << '\n' <<std::endl;
//second
    beginning = clock();
    res = maxsubseqsum2(array, num);
    end = clock();
    std::cout << "Maxsubseqsum is " << res << '\n';
    std::cout << "\n" << '\n' << std::endl;
    duration = (double)(end - beginning) / CLOCKS_PER_SEC;
    std::cout << "time to do this function2 is " << duration << '\n' <<std::endl;
//third
    beginning = clock();
    res = maxsubseqsum3(array, num);
    end = clock();
    std::cout << "Maxsubseqsum is " << res << '\n';
    std::cout << "\n" << '\n' << std::endl;
    duration = (double)(end - beginning) / CLOCKS_PER_SEC;
    std::cout << "time to do this function3 is " << duration << '\n' <<std::endl;
//fourth
//     beginning = clock();
//     res = maxsubseqsum4(array, num);
//     end = clock();
//     std::cout << "Maxsubseqsum is " << res << '\n';
//     std::cout << "\n" << '\n' << std::endl;
//     duration = (double)(end - beginning) / CLOCKS_PER_SEC;
//     std::cout << "time to do this function4 is " << duration << '\n' <<std::endl;
}