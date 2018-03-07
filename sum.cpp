#include "iostream"
int main()
{
    int sum = 0;
    for (int i; std::cin >> i; sum += i);
    std::cout << "sum=" << sum << '\n' <<std::endl;
    return 0;
}
