#ifndef READER_H
#define READER_H
#include <vector>
#include "Book.h"

class Reader
{
private:
    int id;
    std::string name;
    std::vector<Book*> borrowedBooks;
public:
    Reader(int id, std::string name);
    int getId() const;
    std::string getName() const;
    const std::vector<Book*>& getBorrowedBooks() const;
    void addBorrowedBook(Book* book);
    void removeBorrowedBook(Book* book);
    void printInfo() const;
};
#endif

