#include <iostream>
using namespace std;


//1//

void func(int n)
{
    int suma = 0;
    int produs = 1;
    do 
    {
        suma += n % 10;
        produs *= n % 10;
        n /= 10;

    } while (n);
    cout << "Suma cifrelor este " << suma << endl;
    cout << "Produsul cifrelor este " << produs;
}

int main()
{
    int n;
    cin >> n;
    func(n);
}


//2//

void num_inversa(unsigned int n)
{
	do
	{
		cout << n << ' ';
		n--;

	} while (n);
}

int main()
{
	unsigned int n;
	cin >> n;
	num_inversa(n);
}


//3//

void putere(int baza, int exponent)
{
	int produs = 1;
	do
	{
		if (exponent == 0)
			break;
		produs *= baza;
		exponent--;

	} while (exponent);

	cout << produs;
}

int main()
{
	int baza, exponent;
	cin >> baza;
	cin >> exponent;
	putere(baza, exponent);
}


//4//

void produs(int n)
{
	int nr;
	int i = 1;
	int p = 1;
	do
	{
		cin >> nr;
		p *= nr;
		i++;

	} while (i <= n);

	cout << "Produsul este " << p;
}

int main()
{
	int n;
	cin >> n;
	produs(n);
}