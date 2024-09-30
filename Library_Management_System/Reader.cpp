#include <iostream>
#include <iomanip>
#include "Reader.h"

// Constructor to initialize a reader object
Reader::Reader(int id, std::string name) : id(id), name(name) {}

// Getters for reader attributes
int Reader::getId() const {
    return id;
}

std::string Reader::getName() const
{
    return name;
}

const std::vector<Book*>& Reader::getBorrowedBooks() const{
    return borrowedBooks;
}

// Adds a book to the reader's borrowed list
void Reader::addBorrowedBook(Book* book) {
    borrowedBooks.push_back(book);
}

// Removes a book from the reader's borrowed list
void Reader::removeBorrowedBook(Book* book) {
    auto it = std::find(borrowedBooks.begin(), borrowedBooks.end(), book);
    if (it != borrowedBooks.end()) {
        borrowedBooks.erase(it);
    }
}

// Prints reader information, including borrowed books
void Reader::printInfo() const {
    std::cout << "ID: " << std::left << std::setw(5)<<id << "Name: " << name << std::endl;

    if (borrowedBooks.empty()) {
        std::cout << std::left << std::setw(12) << "Borrowed books:" << "None\n";
    }
    else {
        std::cout << std::left << std::setw(12) << "Borrowed books:\n";
        for (const auto& book : borrowedBooks) {
            std::cout << "(" << book->getId() << ")" << book->getTitle();
            std::cout << std::endl;
        }
    }
}