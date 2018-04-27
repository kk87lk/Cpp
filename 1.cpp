#include <iostream>
#include <string>
#define ElementType int

using namespace std;

int match(char *main, char *sub, int pos)
{
    int i = pos, j = 0;
    int ml = strlen(main), sl = strlen(sub);
    while( i < ml && j < sl)
    {
        if (main[i] == sub[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i -j + 2;
            j = 1;
        }
        if(j = sl)
            return (i - sl + 1);
        else
            return -1;
    }
}
int main()
{
    char str;
    cin >> str;
    char str1;
    cin >> str1;
    int c;
    cin >> c;
    int pos = match(str, str1, c);
    cout << pos;
}