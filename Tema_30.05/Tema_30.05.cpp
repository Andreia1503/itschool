#include <iostream>
using namespace std;

//1.Sa se scrie o functie care returneaza valoarea maxima dintr-un array//

int maxim(int a[], int n)
{
    int max = a[0];
    for (int i = 0; i < n; i++)
        if (a[i] > max)
            max = a[i];
    return max;
}

int main()
{
    int a[] = {2,3,12,10,0,4,24};
    int n = 7;
    cout << maxim(a, n);

}


//2.Declarati un array de 10 elemente si verificati daca un anumit element exista in array//

void cautare(int a[10], int x)
{
	int k = 0;
	for (int i = 0; i < 10 && k == 0; i++)
	{
		if (a[i] == x)
		{
			k = 1;
			
		}
	}
	if (k == 0)
		cout << x << " nu se afla in array";
	else cout << x << " se afla in array";
}

int main()
{
	int a[10];
	int x;
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	cin >> x;
	cautare(a, x);
}


//3.Declarati un array de 10 elemente si returnati de cate ori apare un element in array//

int nr_aparitii(int a[10], int x)
{
	int k = 0;
	for (int i = 0; i < 10; i++)
	{
		if (a[i] == x)
			k++;
	}
	return k;
}

int main()
{
	int a[10];
	int x;
	for (int i = 0; i < 10; i++)
		cin >> a[i];
	cin >> x;
	cout << nr_aparitii(a, x);

}

