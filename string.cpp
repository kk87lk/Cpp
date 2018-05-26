#include <cstdlib>
#include <iostream>
#include <queue>
//#include <string>

using namespace std;

class String
{
  public:
    struct String1
    {
        char String[1000] = {'\0'};
    } unit;
    int length()
    {
        int i = 0;
        for (; unit.String[i] != 0; i++)
            ;
        return i;
    }
};
class str
{
  private:
    int match(String MainStr, String SubStr, int pos)
    {
        int i = pos - 1, j = 0;
        int ml = MainStr.length(), sl = SubStr.length();
        while (i < ml && j < sl)
        {
            if (MainStr.unit.String[i] == SubStr.unit.String[j])
            {
                i++;
                j++;
            }
            else
            {
                i = i + 1;
                j = 0;
            }
        }
        if (j == sl)
            return (i - sl + 1);
        else
            return -1;
    }

  public:
    void replace(String *MainStr, String StrToBeReplaced, String StrToReplace)
    {
        int ml = MainStr->length(), sl = StrToBeReplaced.length(), sl2 = StrToReplace.length();
        int reco, mark = 0;
        if (sl >= sl2)
        {
            for (int i = 1; i <= ml - sl;)
            {
                int flag = 0, rip = 0;
                while (1)
                {
                    mark = match(*MainStr, StrToBeReplaced, i);
                    if (mark == -1)
                        return;
                    for (int count = 0; count < sl2; count++)
                        (*MainStr).unit.String[mark + count - 1] = StrToReplace.unit.String[count];
                    for (int count = 0; count < ml - mark - sl + 2; count++)
                        (*MainStr).unit.String[mark + count + sl2 - 1] = (*MainStr).unit.String[mark + count + sl - 1];
                    i = i + sl2 + 1;
                }
            }
        }
        else
        {
            for (int i = 1; i <= ml - sl;)
            {

                int flag = 0, rip = 0;
                while (1)
                {
                    ml = MainStr->length();
                    mark = match(*MainStr, StrToBeReplaced, i) - 1;
                    if (mark == -2)
                        return;
                    for (int count = 0; count < ml - mark + sl2 - (sl * 2) - 1; count++)
                        (*MainStr).unit.String[ml - count + sl2 - sl - 1] = (*MainStr).unit.String[ml - count - 1];
                    for (int co = 0; co < sl2; co++)
                        (*MainStr).unit.String[mark + co] = StrToReplace.unit.String[co];
                    i = i + sl;
                }
            }
        }
    }
    String Takeout(String MainStr, int pos, int num)
    {
        String SubStr;
        for (int i = 0; i < num; i++)
            SubStr.unit.String[i] = MainStr.unit.String[pos + i];
        return SubStr;
    }
    void insert(String *MainStr, String StrToBeInserted, int pos)
    {
        int len = (*MainStr).length();
        int ml = MainStr->length();
        int sl = StrToBeInserted.length();
        for (int i = 0; i < len - pos; i++)
            (*MainStr).unit.String[ml + sl - 1 - i] = (*MainStr).unit.String[ml - i - 1];
        for (int i = 0; i < sl; i++)
            (*MainStr).unit.String[pos + i] = StrToBeInserted.unit.String[i];
        cout << "Successful insert.";
        system("pause");
        return;
    }
};

int main()
{
    int op = -1;
    while (op != 0)
    {
        system("cls");
        cout << "1-Replace." << endl;
        cout << "2-Insert." << endl;
        cout << "3-Get SubString." << endl;
        cout << "0-exit." << endl;
        cin >> op;
        switch (op)
        {
        case 0:
            return -1;
        case 1:
        {
            String a;
            String b;
            String c;
            str s;
            system("cls");
            cout << "Type in the main string:";
            cin >> a.unit.String;
            cout << "\nType in the string you want to be replaced:";
            cin >> b.unit.String;
            cout << "\nType in the string to replace it:";
            cin >> c.unit.String;
            s.replace(&a, b, c);
            cout << "\nReplace success!\nThe main string now is:";
            cout << a.unit.String;
            break;
        }
        case 2:
        {
            String a;
            String b;
            String c;
            str s;
            system("cls");
            cout << "Type in the main string:";
            cin >> a.unit.String;
            int pos;
            cout << "\nType in the position you want to insert:";
            cin >> pos;
            cout << "\nType in the string to insert:";
            cin >> b.unit.String;
            s.insert(&a, b, pos);
            cout << "\nReplace success!\nThe main string now is:";
            cout << a.unit.String;
            break;
        }
        case 3:
        {
            String a;
            str s;
            system("cls");
            cout << "Type in the main string:";
            cin >> a.unit.String;
            int pos;
            cout << "\nType in the position of string you want to takeout:";
            cin >> pos;
            int num;
            cout << "\nType in how many types you want to takeout:";
            cin >> num;
            String b = s.Takeout(a, pos - 1, num);
            cout << "\nTakeout success!\nThe substring now is:";
            cout << b.unit.String;
            system("pause");
            break;
        }
        default:
            cout << "Wrong option.";
        }
    }
}