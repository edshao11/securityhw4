#include <iostream>

using namespace std;

long factorial(int n);

int main()
{
    int n(0);
    cout << "please enter a positive integer: " << endl;
    cin >> n long val = factorial(n);
    cout << "The factorial is: " << val << endl;
    cin.get() return 0;
}

long factorial(int n)
{
    long result(1);
    while (n--)
    {
        result *= n;
    }
    return result;
}