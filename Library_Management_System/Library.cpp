#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include "Library.h"

// Constructor: Initializes the library by loading data from files
Library::Library() {
	loadBooksFromFile();
	loadEmployeesFromFile();
	loadReadersFromFile();
}

// Destructor: Saves data to files before the library object is destroyed
Library::~Library() {
	saveBooksToFile();
	saveEmployeesToFile();
	saveReadersToFile();
}

//loads book data from books.txt file and adds them to the books vector
void Library::loadBooksFromFile() {
	std::ifstream bookFile("books.txt");
	if (bookFile.is_open()) {
		int id, bookCount;
		std::string title, author, line, temp;

		while (std::getline(bookFile, line)) {
			std::stringstream ss(line);

			ss >> id;
			ss.ignore();

			std::getline(ss, title, ',');
			std::getline(ss, author, ',');

			ss >> bookCount;

			books.push_back(Book(id, title, author, bookCount));
		}
		bookFile.close();
	}
	else {
		std::cout << "Unable to open books.txt for reading. Starting with an empty library.\n";
	}
}

//saves data from the books vector to the books.txt file, ensuring that the file is updated
void Library::saveBooksToFile() {
	std::ofstream bookFile("books.txt", std::ios::trunc);
	if (bookFile.is_open()) {
		for (const auto& book : books) {
			bookFile << book.getId() << ","
				<< book.getTitle() << ","
				<< book.getAuthor() << ","
				<< book.getBookCount() << std::endl;
		}
		bookFile.close();
	}
	else {
		std::cout << "Error opening books file for writing.\n";
	}
}

//loads employee data from employees.txt file and adds them to the employees vector
void Library::loadEmployeesFromFile() {
	std::ifstream employeeFile("employees.txt");
	if (employeeFile.is_open()) {
		int id;
		std::string name, job_title, line, temp;
		while (std::getline(employeeFile, line)) {
			std::stringstream ss(line);

			ss >> id;
			ss.ignore();

			std::getline(ss, name, ',');
			std::getline(ss, job_title, ',');

			employees.push_back(Employee(id, name, job_title));
		}
		employeeFile.close();
	}
	else {
		std::cout << "Unable to open employees.txt for reading.\n";
	}
}

//saves data from the employees vector to the employees.txt file, ensuring that the file is updated
void Library::saveEmployeesToFile() {
	std::ofstream employeeFile("employees.txt", std::ios::trunc);
	if (employeeFile.is_open()) {
		for (const auto& employee : employees) {
			employeeFile << employee.getId() << ","
				<< employee.getName() << ","
				<< employee.getJobTitle() << std::endl;
		}
		employeeFile.close();
	}
	else {
		std::cout << "Error opening employees file for writing.\n";
	}
}

//loads reader data from readers.txt file and adds them to the readers vector
void Library::loadReadersFromFile() {
	std::ifstream readerFile("readers.txt");
	if (readerFile.is_open()) {
		int id, bookId;
		std::string name, line, bookTitle;
		while (std::getline(readerFile, line)) {
			std::stringstream ss(line);
			std::vector<Book*> borrowedBooks;
			ss >> id;

			ss.ignore();

			std::getline(ss, name, ',');

			while (ss >> bookId) {
				ss.ignore();

				std::getline(ss, bookTitle, ',');

				Book* book = findBookById(bookId);
				if (book) {
					borrowedBooks.push_back(book);
				}
			}

			readers.push_back(Reader(id, name));
			Reader* currentReader = &readers.back();
			for (Book* book : borrowedBooks) {
				currentReader->addBorrowedBook(book);
			}
		}
		readerFile.close();
	}
	else {
		std::cout << "Unable to open readers.txt for reading.\n";
	}
}

//saves data from the readers vector to the readers.txt file, ensuring that the file is updated
void Library::saveReadersToFile() {
	std::ofstream readerFile("readers.txt", std::ios::trunc);
	if (readerFile.is_open()) {
		for (const auto& reader : readers) {
			readerFile << reader.getId() << ","
				<< reader.getName() << ",";

			const std::vector<Book*>& borrowedBooks = reader.getBorrowedBooks();
			for (int i = 0; i < borrowedBooks.size(); ++i) {
				readerFile << borrowedBooks[i]->getId() << "," << borrowedBooks[i]->getTitle() << ",";
			}
			readerFile << std::endl;
		}
		readerFile.close();
	}
	else {
		std::cout << "Error opening readers file for writing.\n";
	}
}

void Library::printBooks() {
	if (books.empty()) {
		std::cout << "No books in the library.\n";
		return;
	}

	std::cout << "----------------------------------------------------------------------------\n";
	std::cout << "ID|Title                                     |Author                |Copies\n";
	std::cout << "----------------------------------------------------------------------------\n";

	for (const auto& book : books) {
		book.printInfo();
	}

}

//searches through the books vector and returns the book with the given id
Book* Library::findBookById(int bookId) {
	for (auto& book : books) {
		if (book.getId() == bookId) {
			return &book;
		}
	}
	return nullptr;
}

//asks the user for input and adds the new book to the library
void Library::addBook() {
	int id, bookCount;
	std::string title, author;

	std::cout << "Enter the book's ID: ";
	std::cin >> id;
	if (findBookById(id) != nullptr)
	{
		std::cout << "A book with this ID already exists!\n";
		return;
	}
	std::cout << "Enter the book's title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Enter the book's author: ";
	std::getline(std::cin, author);
	std::cout << "Enter the number of available copies: ";
	std::cin >> bookCount;

	books.push_back(Book(id, title, author, bookCount));
	std::cout << "Book added successfully!\n";
}

//removes from the library the book with the given id
void Library::removeBook(int bookId) {
	auto it = std::find_if(books.begin(), books.end(),
		[bookId](const Book& book) {
			return book.getId() == bookId;
		});

	if (it != books.end()) {
		books.erase(it);
		std::cout << "Book removed successfully.\n";
	}
	else {
		std::cout << "Book not found.\n";
	}
}

void Library::printEmployees() const {
	if (employees.empty()) {
		std::cout << "No employees in the library.\n";
		return;
	}

	std::cout << "------------------------------------------------\n";
	std::cout << "ID| Name                 | Position               \n";
	std::cout << "------------------------------------------------\n";

	for (const auto& employee : employees) {
		employee.printInfo();
	}
}

//searches through the employees vector and returns the employee with the given id
Employee* Library::findEmployeeById(int employeeId) {
	for (auto& employee : employees) {
		if (employee.getId() == employeeId) {
			return &employee;
		}
	}
	return nullptr;
}

//asks the user for input and adds the new employee
void Library::addEmployee() {
	int id;
	std::string name, job_title;

	std::cout << "Enter the employee's ID: ";
	std::cin >> id;
	if (findEmployeeById(id) != nullptr)
	{
		std::cout << "An employee with this ID already exists!\n";
		return;
	}
	std::cout << "Enter the employee's name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Enter the employee's position: ";
	std::getline(std::cin, job_title);

	employees.push_back(Employee(id, name, job_title));
	std::cout << "Employee added successfully!\n";
}

void Library::removeEmployee(int employeeId) {
	auto it = std::find_if(employees.begin(), employees.end(),
		[employeeId](const Employee& employee) {
			return employee.getId() == employeeId;
		});

	if (it != employees.end()) {
		employees.erase(it);
		std::cout << "Employee removed successfully.\n";
	}
	else {
		std::cout << "Employee not found.\n";
	}
}

void Library::printReaders() const {
	if (readers.empty()) {
		std::cout << "No readers in the library.\n";
		return;
	}

	std::cout << "\nList of Readers:\n";
	std::cout << "========================================\n";

	for (const auto& reader : readers) {
		reader.printInfo();
		std::cout << "---------------------------------\n";
	}

	std::cout << "========================================\n";
}

Reader* Library::findReaderById(int readerId) {
	for (auto& reader : readers) {
		if (reader.getId() == readerId) {
			return &reader;
		}
	}
	return nullptr;
}

void Library::addReader() {
	int id;
	std::string name;

	std::cout << "Enter the reader's ID: ";
	std::cin >> id;
	if (findReaderById(id) != nullptr)
	{
		std::cout << "A reader with this ID already exists!\n";
		return;
	}
	std::cout << "Enter the reader's name: ";
	std::cin.ignore();
	std::getline(std::cin, name);

	readers.push_back(Reader(id, name));
	std::cout << "Reader added successfully!\n";
}

void Library::removeReader(int readerId) {
	auto it = std::find_if(readers.begin(), readers.end(),
		[readerId](const Reader& reader) {
			return reader.getId() == readerId;
		});

	if (it != readers.end()) {
		readers.erase(it);
		std::cout << "Reader removed successfully.\n";
	}
	else {
		std::cout << "Reader not found.\n";
	}
}

void Library::borrowBook(int bookId, int readerId) {
	Book* book = findBookById(bookId); //tries to find a book in the library that matches the provided id
	Reader* reader = findReaderById(readerId); //tries to find a reader that matches the provided id

	if (book == nullptr) {  //checks if the book was found
		std::cout << "Book not found!\n";
		return;
	}

	if (reader == nullptr) { //checks if the reader was found
		std::cout << "Reader not found!\n";
		return;
	}

	if (book->getBookCount() > 0) { //checks if there are any available copies of the book
		reader->addBorrowedBook(book); //adds the book to reader's list of borrowed books
		book->setBookCount(book->getBookCount() - 1); //decrements the book count by 1

		std::cout << "Book borrowed successfully!\n";
	}
	else {
		std::cout << "No copies of this book are available.\n";
	}
}

void Library::returnBook(int bookId, int readerId) {
	Reader* reader = findReaderById(readerId); //searches for the reader with the provided id

	auto& borrowedBooks = reader->getBorrowedBooks(); //gets a reference to the vector of borrowed books associated with the reader
	auto it = std::find_if(borrowedBooks.begin(), borrowedBooks.end(), //looks for the book the reader wants to return, in the borrowed books vector
		[bookId](Book* book) { return book->getId() == bookId; });

	if (it != borrowedBooks.end()) { //checks if the book was found
		Book* book = *it;
		reader->removeBorrowedBook(book); //removes the book from the reader's borowed books vector
		book->setBookCount(book->getBookCount() + 1); //increments the book count by 1

		std::cout << "Book returned successfully!\n";
	}
	else {
		std::cout << "The book with ID " << bookId << " was not borrowed by this reader.\n";
	}
}

void Library::generateBorrowedBooksReport() const {
	std::cout << std::left << std::setw(15) << " " << "===== Borrowed Books Report =====\n";
	std::cout << "=======================================================================\n";
	std::cout << "ID| Reader Name            | Book Title           \n";
	std::cout << "=======================================================================\n";

	for (const auto& reader : readers) {
		const auto& borrowedBooks = reader.getBorrowedBooks();
		if (!borrowedBooks.empty()) {
			// Print the first book with reader details
			std::cout << reader.getId() << " | "
				<< std::left << std::setw(22) << reader.getName() << " | "
				<< std::left << std::setw(20) << borrowedBooks[0]->getTitle() << "\n";

			// Print subsequent books (if any) with empty reader details
			for (int i = 1; i < borrowedBooks.size(); ++i) {
				std::cout << std::setw(2) << " " << "|" << std::setw(23) << " " << " | "
					<< std::setw(20) << borrowedBooks[i]->getTitle() << "\n";
			}
			std::cout << "-----------------------------------------------------------------------\n";
		}	
	}
}