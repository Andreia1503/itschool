#ifndef LIBRARY_H
#define LIBRARY_H
#include "Book.h"
#include "Employee.h"
#include "Reader.h"
#include<vector>

class Library
{
public:
    std::vector<Book> books;
    std::vector<Employee> employees;
    std::vector<Reader> readers;

    
public:
    Library();
    ~Library();
    void loadBooksFromFile();
    void saveBooksToFile();
    void loadEmployeesFromFile();
    void saveEmployeesToFile();
    void loadReadersFromFile();
    void saveReadersToFile();
    void printBooks();
    void addBook();
    void removeBook(int bookId);
    Employee* findEmployeeById(int employeeId);
    void addEmployee();
    void removeEmployee(int employeeId);
    void printEmployees() const;
    void addReader();
    void removeReader(int readerId);
    void printReaders() const;
    Book* findBookById(int bookId);
    Reader* findReaderById(int readerId);
    void borrowBook(int bookId, int readerId);
    void returnBook(int bookId, int readerId);
    void generateBorrowedBooksReport() const;
};

#endif
