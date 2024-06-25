#include <iostream>
#include <string.h>
using namespace std;

//1//

int lungime_sir(string s)
{
	if (s.empty())               //verificam daca sirul este gol
		return 0;                //daca este gol returnam 0
	return 1 + lungime_sir(s.substr(1));   //altfel adunam 1 pentru caracterul de la indexul 0 si apelam functia pentru subsirul ce incepe de la indexul 1
}

void majuscula(string s)
{
	while (s.empty() == 0)
	{
		if (isupper(s.at(0)))
			cout << s.at(0);
		else
			majuscula(s.substr(1));
	}
	cout << "Nu avem majuscule in sir";
}
char majuscula1(string s)
{
	while (s.empty() == 0)
	{
		if (isupper(s[0]))
			return s[0];
		else
			return majuscula1(s.substr(1));
	}
	string s1 = "Nu avem majuscule in sir";
	return s1;
}

int main()
{
	string s = "Ana are mere!";
	cout << lungime_sir(s) << endl;
	majuscula(s);
}


//2//
