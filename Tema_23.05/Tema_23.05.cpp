#include <iostream>
using namespace std;

void produs(int n)
{
    int i = 1, p = 1;
    while (i <= n)
    {
        p = p * i;
        i++;
    }
    cout << "Produsul numerelor este: " << p;
}

int main()
{
    int n;
    cin >> n;
    produs(n);

    return 0;
}
