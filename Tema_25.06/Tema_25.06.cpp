#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void citire()
{
    fstream file("produse.txt", ios::in|ios::out);

    if (!file)
    {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }

    string line;

    while (getline(file, line))
    {
        cout << line << endl;
    }

    file.close();

}

void adauga_produs()
{
    fstream file("produse.txt", ios::app);
    string produs_nou;
    cout << "Introduceti detaliile produsului nou: ";
    getline(cin, produs_nou);
    file << produs_nou << endl;
    file.close();
}

void sterge_produs()
{
    fstream file("produse.txt", ios::in | ios::out);
    if (!file)
    {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }
    ofstream temp("temp.txt");
    if (!temp)
    {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }

    string line;
    string denumire;
    cout << "Denumirea produsului pe care doriti sa-l stergeti: ";
    cin >> denumire;
    while (getline(file, line))
    {
        if (line.find(denumire))
            temp << line << endl;

    }
    file.close();
    temp.close();
    remove("produse.txt");
    bool check = rename("temp.txt", "produse.txt");
    if (check != 0)
        cout << "Eroare";
        
}

void actualizare_raport()
{
    fstream file("produse.txt", ios::in | ios::out);
    string line;
    ofstream raport("raport.txt");
    if (!raport)
    {
        cout << "Eroare la deschiderea fisierului" << endl;
        return;
    }
    while (getline(file, line))
        raport << line << endl;

}

int main()
{
    //citire();
    //adauga_produs();
    //sterge_produs();
    //actualizare_raport();

}

