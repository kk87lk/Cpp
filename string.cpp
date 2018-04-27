#include <iostream>
#include <cstdlib>
#include <string>
#include <queue>

using namespace std;

class str
{
    private:

    public:
        int match(string MainStr, string SubStr, int pos)
        {
            int i = pos - 1, j = 0;
            int ml = MainStr.length, sl = SubStr.length;
            while( i < ml && j < sl)
            {
                if (MainStr[i] == SubStr[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    i = i -j + 2;
                    j = 1;
                }
            }
            if(j = sl)
                return (i - sl + 1);
            else
                return -1;
        }
        void replace(string MainStr, string StrToBeReplaced, string StrToReplace)
        {
            int ml = MainStr.length, sl = SubStr.length;
            queue<int> q1(ml);
            for (int i = 1; i <= ml - sl; i++)
            {
                if ( match(MainStr, StrToBeReplaced, i) != 0)
                    q1.push(i);
            }
        }
        void insert(string MainStr, string StrToBeInserted)
        {

        }
        char *takeout(char *MainStr, int n)
        {
            
        }
};