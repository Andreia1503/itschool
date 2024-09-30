# Sistem de Management al Bibliotecii

Acest program C++ oferă o soluție pentru gestionarea unei biblioteci, inclusiv a cărților, angajaților și cititorilor.

## Funcționalități

* **Gestionarea cărților:**
    * Adăugarea de noi cărți în baza de date
    * Vizualizarea listei complete de cărți
    * Ștergerea cărților existente
* **Gestionarea angajaților:**
    * Adăugarea de noi angajați
    * Vizualizarea listei de angajați
    * Ștergerea informațiilor despre angajați
* **Gestionarea cititorilor:**
    * Adăugarea de noi cititori
    * Vizualizarea listei de cititori
    * Ștergerea datelor despre cititori
    * Împrumutarea cărților către cititori
    * Returnarea cărților de către cititori
* **Generarea de rapoarte:**
    * Afișarea unui raport cu cărțile împrumutate în prezent

## Cum se folosește

1. **Compilare:** Compilează codul sursă C++ folosind un compilator adecvat.
2. **Execuție:** Rulează fișierul executabil generat.
3. **Interacțiune:** 
    * Programul va afișa un meniu cu opțiuni.
    * Introdu numărul corespunzător opțiunii dorite și apasă Enter.
    * Urmează instrucțiunile afișate pentru a efectua operația selectată.
4. **Ieșire:** Selectează opțiunea "0. Exit" din meniul principal pentru a închide programul. Datele vor fi salvate automat.

## Stocarea datelor

Programul utilizează fișiere text pentru a stoca datele:

* `books.txt`: Conține informații despre cărți (ID, titlu, autor, număr de copii disponibile).
* `employees.txt`: Conține informații despre angajați (ID, nume, funcție).
* `readers.txt`: Conține informații despre cititori (ID, nume, cărți împrumutate).
