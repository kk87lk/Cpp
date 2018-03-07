#include <iostream>
#include <stdlib.h>
#include <stdio.h>
int stb(const void *a,const void *b)
{
    return *(int *)a - *(int *)b;
}
int bts(const void *a,const void *b)
{
    return *(int *)b - *(int *)a;
}
int main()
{
    int array[10];
    for (int i = 0; i < 10; i++)
    {
        if (i == 0)
        {
            array[i] = 888;
        }
        else if ((i % 2) == 0)
        {
            array[i] = i * 2;
        }
        else if ((i % 2) != 0)
        {
            array[i] = i * 3;
        }
    }
    for (int j = 0; j < 10; j++)        //original array
    {
        std::cout << array[j] << " ";
    }
    std::cout << '\n' <<std::endl;
    qsort(array, 10, sizeof(int), stb);//sort from small to big
    for (int j = 0; j < 10; j++)
    {
        std::cout << array[j] << " ";
    }
    std::cout << '\n' <<std::endl;
    qsort(array, 10, sizeof(int), bts); //sort from big to small
    for (int j = 0; j < 10; j++)
    {
        std::cout << array[j] << " ";
    }


    //search block
    int *c;
    int key = 15;
    c = (int*)bsearch(&key, array, 10, sizeof(int), bts);
    if (c != NULL)
    {
        std::cout << '\n' << "Found key=" << *c << '\n' <<std::endl;
    }
    else
    {
        std::cout << '\n' << "Can't found key=" << key << '\n' << std::endl;
    }
}