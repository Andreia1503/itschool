#include <iostream>
#include <fstream>
#include <vector>
#include "produs.h"
using namespace std;

bool citire(vector<produs>& p)
{
    fstream f("produse.txt", ios::in);
    string line;
    if (!f)
    {
        cout << "Eroare la deschidere";
        return;
    }

    string denumire;
    int cantitate;
    float valoare;
    while(!f.eof())  //cat timp nu am ajuns la sfarsitul fisierului
    { 
        f >> denumire;
        f >> cantitate;
        f >> valoare;
        produs temp = { denumire, cantitate, valoare };
        p.push_back(temp);
    }

    f.close();

}

//void adauga_produs()
//{
//    fstream file("produse.txt", ios::app);
//    string produs_nou;
//    if (!file)
//    {
//        cout << "Eroare la deschidere";
//        return;
//    }
//
//    cout << "Detalii produs nou: ";
//    getline(cin, produs_nou);
//    file << produs_nou << endl;
//
//    file.close();
//
//}
//
//void sterge_produs()
//{
//    fstream file("produse.txt");
//    ofstream temp("temp.txt");
//    string line;
//    string denumire;
//    if (!file)
//    {
//        cout << "Eroare la deschidere";
//        return;
//    }
//    if (!temp)
//    {
//        cout << "Eroare la deschidere";
//        return;
//    }
//
//    cout << "Denumirea produsului pe care doriti sa-l stergeti: ";
//    cin >> denumire;
//
//    while (getline(file, line))
//    {
//        if (line.find(denumire))
//            temp << line << endl;
//    }
//
//    file.close();
//    temp.close();
//
//    remove("produse.txt");
//    bool check = rename("temp.txt", "produse.txt");
//    
//    if (check != 0)
//        cout << "Eroare la redenumire";
//
//
//}
//
//void actualizare_raport()
//{
//    fstream file("produse.txt");
//    ofstream raport("raport.txt");
//    string line;
//    if (!file)
//    {
//        cout << "Eroare la deschidere";
//        return;
//    }
//    if (!raport)
//    {
//        cout << "Eroare la deschidere";
//        return;
//    }
//
//    while (getline(file, line))
//        raport << line << endl;
//
//    file.close();
//    raport.close();
//}



int main()
{
    int optiune;
    cout << "Dati optiunea" << endl;
    cin >> optiune;
    vector<produs> p;
    int sw = 0;
    while (optiune != 0 && sw == 0) 
    {
        switch (optiune)
        {
        case 0:
            break;
        case 1:
            if (!citire(p))
            {
                cout << "Eroare";
                sw = 1;
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        default:
            cout << "Optiunea gresita";
        }
        cout << "Dati optiune" << endl;
        cin >> optiune;
    }
    
}
