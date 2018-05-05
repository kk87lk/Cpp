#include <iostream>
#include <queue>

using namespace std;

int main()
{
	int n;
    queue<int> Q, Qs, Qr;
    cout << "Input n:";
    cin >> n;
    int a = 0, b = 0, c = 0, flag = 0;
    Q.push(1);
    Qs.push(0);
    Qs.push(1);
    cout << "1" <<endl;
    for (int i = 1; i < n; i++)
    {
        if (i == 1) Q.push(0);
        while(flag != 2)
        {
            a = Q.front();
			Q.pop();
            b = Qs.front();
			Qs.pop();
            if (a == 1 || Q.empty()) flag++;
            Qr.push(a + b);
        }
        Q.push(0);
        while(!Qr.empty())
        {
            cout << Qr.front() << " ";
            Q.push(Qr.front());
            Qs.push(Qr.front());
			Qr.pop();
        }
        Qs.push(0);
        cout << '\n';
        flag = 0;
    }
}