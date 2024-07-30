#include <iostream>
#include <string.h>
#include <vector>
#include <algorithm>
#include <fstream>
using namespace std;

struct produs
{
    string denumire;
    int cantitate;
    float pret;  
};


//bool comparare(const produs& a, produs& b)
//{
//    return a.pret < b.pret;
//}


int main()
{
    fstream file("produse.txt", ios::in);
    if (!file)
    {
        cout << "Fisierul nu s-a deschis corespunzator";
        return;
    }
    string p;
    vector<produs> catalog;
    /*const produs p1 = {"Mere", "123", 12, 6.5};
    catalog.push_back(p1);
    catalog.push_back({ "Portocale", "131", 20, 9.2 });
    catalog.push_back({ "Cartofi", "96", 60, 3.5 });
    afisare_catalog(catalog);*/

    /*sort(catalog.begin(), catalog.end(), comparare);
    cout << endl;
    afisare_catalog(catalog);
    */
}
