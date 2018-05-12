#include <cstdlib>
#include <iostream>
#include <queue>
#include <string>

using namespace std;

class str
{
  public:
    int match(string MainStr, string SubStr, int pos)
    {
        int i = pos - 1, j = 0;
        int ml = MainStr.length(), sl = SubStr.length();
        while (i < ml && j < sl)
        {
            if (MainStr[i] == SubStr[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i - j + 2;
                j = 1;
            }
        }
        if (j = sl)
            return (i - sl + 1);
        else
            return -1;
    }
    void replace(string MainStr, string StrToBeReplaced, string StrToReplace)
    {
        int ml = MainStr.length(), sl = StrToBeReplaced.length(), sl2 = StrToReplace.length();
        queue<int> q1(ml);
        int reco, mark;
        for (int i = 1; i <= ml - sl; i++)
        {
            reco = match(MainStr, StrToBeReplaced, i);
            if (reco != -1)
            {
                q1.push(reco - 1); //存入下标
                i = i + sl - 1;
            }
            else
            {
                if (sl >= sl2)
                {
                    while (!q1.empty())
                    {
                        mark = q1.front();
                        q1.Pop();
                        for (int count = 0; count < sl2; count++)
                            MainStr[mark + count] = StrToReplace[count];
                        for (count = 0; count < ml - mark - sl; count++)
                            MainStr[mark + count + sl2] = MainStr[mark + count + sl2 + 1];
                        if (q1.empty())
                            return;
                        mark = q1.front();
                        q1.Pop();
                        q1.Push(mark - sl + sl2);
                    }
                }
                else
                {
                }
            }
        }
    }
    void insert(string MainStr, string StrToBeInserted, int pos)
    {
    }
    char *takeout(string MainStr, int n)
    {
    }
};