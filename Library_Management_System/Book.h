#ifndef BOOK_H
#define BOOK_H

class Book
{
private:
    int id;
    std::string title;
    std::string author;
    int bookCount;

public:
    Book(int id, std::string title, std::string author, int bookCount);

    int getId() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    int getBookCount() const;

    void setBookCount(int bookCount);

    void printInfo() const;
};
#endif 

