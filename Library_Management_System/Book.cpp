#include <iostream>
#include <iomanip>
#include "Book.h"

// Constructor to initialize a book object
Book::Book(int id, std::string title, std::string author, int bookCount)
    : id(id), title(title), author(author), bookCount(bookCount) {}

// Getters for book attributes
int Book::getId() const
{
    return id;
}

std::string Book::getTitle() const
{
    return title;
}

std::string Book::getAuthor() const
{
    return author;
}

int Book::getBookCount() const
{
    return bookCount;
}

// Setter to update the number of available copies
void Book::setBookCount(int bookCount)
{
    this->bookCount = bookCount;
}

// Prints book information
void Book::printInfo() const {
    std::cout << id << " | "
        << std::left << std::setw(40) << title << " | "
        << std::left << std::setw(20) << author << " | "
        << bookCount << "\n";
    std::cout << "----------------------------------------------------------------------------\n";
}
