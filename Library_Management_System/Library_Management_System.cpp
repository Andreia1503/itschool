#include <iostream>
#include <string>
#include <vector>
#include <csignal>
#include "Library.h"
#include "Book.h"
#include "Employee.h"
#include "Reader.h"

Library library;

int main() {
	int choice;
	do {
		//dispays the main menu
		std::cout << "\n ================================\n";
		std::cout << "|  Library Management System     |\n";
		std::cout << " ================================\n";
		std::cout << "| 1. Manage Books                |\n";
		std::cout << "| 2. Manage Employees            |\n";
		std::cout << "| 3. Manage Readers              |\n";
		std::cout << "| 4. Generate Reports            |\n";
		std::cout << "| 0. Exit                        |\n";
		std::cout << " ================================\n";
		std::cout << "Enter your choice (0-4): ";
		std::cin >> choice;
		system("cls");

		switch (choice) {
		case 1: {
			int bookChoice;
			do {
				//book management submenu
				std::cout << "\n ================================\n";
				std::cout << "|         Book Management        |\n";
				std::cout << " ================================\n";
				std::cout << "| 1. Add new book                |\n";
				std::cout << "| 2. View books                  |\n";
				std::cout << "| 3. Remove book                 |\n";
				std::cout << "| 0. Save and Exit               |\n";
				std::cout << " ================================\n";
				std::cout << "Enter your choice (0-3): ";
				std::cin >> bookChoice;
				system("cls");

				switch (bookChoice) {
				case 1: {
					library.addBook();
					break;
				}
				case 2:
					library.printBooks();
					break;
				case 3: {
					int bookId;
					std::cout << "Enter book ID to remove: ";
					std::cin >> bookId;
					library.removeBook(bookId);
					break;
				}
				case 0:
					library.saveBooksToFile();
					break;
				default:
					std::cout << "Invalid choice! Please enter a number between 0 and 3.\n";
				}
			} while (bookChoice != 0);
			break;
		}
		case 2: {
			int employeeChoice;
			do {
				//employee management submenu
				std::cout << "\n ================================\n";
				std::cout << "|      Employee Management       |\n";
				std::cout << " ================================\n";
				std::cout << "| 1. Add New Employee            |\n";
				std::cout << "| 2. View Employees              |\n";
				std::cout << "| 3. Remove Employee Data        |\n";
				std::cout << "| 0. Save and Exit               |\n";
				std::cout << " ================================\n";
				std::cout << "Enter your choice (0-3): ";
				std::cin >> employeeChoice;
				system("cls");
				switch (employeeChoice) {
				case 1: {
					library.addEmployee();
					break;
				}
				case 2:
					library.printEmployees();
					break;
				case 3: {
					int employeeId;
					std::cout << "Enter employee ID to remove: ";
					std::cin >> employeeId;
					library.removeEmployee(employeeId);
					break;
				}
				case 0:
					library.saveEmployeesToFile();
					break;
				default:
					std::cout << "Invalid choice! Please enter a number between 0 and 3.\n";
				}
			} while (employeeChoice != 0);
			break;
		}
		case 3: {
			int readerChoice;
			do {
				//reader management submenu
				std::cout << "\n ================================\n";
				std::cout << "|       Reader Management        |\n";
				std::cout << " ================================\n";
				std::cout << "| 1. Add New Reader              |\n";
				std::cout << "| 2. View Readers                |\n";
				std::cout << "| 3. Remove Reader Data          |\n";
				std::cout << "| 4. Borrow a Book               |\n";
				std::cout << "| 5. Return a Book               |\n";
				std::cout << "| 0. Save and Exit               |\n";
				std::cout << " ================================\n";
				std::cout << "Enter your choice (0-5): ";
				std::cin >> readerChoice;
				system("cls");
				switch (readerChoice) {
				case 1: {
					library.addReader();
					break;
				}
				case 2:
					library.printReaders();
					break;
				case 3: {
					int readerId;
					std::cout << "Enter reader ID to remove: ";
					std::cin >> readerId;
					library.removeReader(readerId);
					break;
				}
				case 4:
					int bookId, readerId;

					std::cout << "\nAvailable Books:\n";
					library.printBooks();

					std::cout << "Enter book ID to borrow: ";
					std::cin >> bookId;

					std::cout << "Enter reader ID: ";
					std::cin >> readerId;

					library.borrowBook(bookId, readerId);
					break;
				case 5: {
					int bookId, readerId;

					std::cout << "Enter reader ID: ";
					std::cin >> readerId;

					Reader* reader = library.findReaderById(readerId);
					if (!reader) {
						std::cout << "Reader with ID " << readerId << " not found.\n";
						break;
					}

					const std::vector<Book*>& borrowedBooks = reader->getBorrowedBooks();
					if (borrowedBooks.empty()) {
						std::cout << "No borrowed books.\n";
					}
					else {
						std::cout << "\nBorrowed Books for " << reader->getName() << ":\n";
						for (const auto& book : borrowedBooks) {
							book->printInfo();
						}

						std::cout << "Enter book ID to return: ";
						std::cin >> bookId;

						Book* bookToReturn = library.findBookById(bookId);
						if (!bookToReturn) {
							std::cout << "Book with ID " << bookId << " not found.\n";
							break;
						}

						if (std::find(borrowedBooks.begin(), borrowedBooks.end(), bookToReturn) != borrowedBooks.end()) {
							library.returnBook(bookId, readerId);
						}
						else {
							std::cout << "This book was not borrowed by this reader.\n";
						}
					}

					break;
				}
				case 0:
					library.saveReadersToFile();
					library.saveBooksToFile();
					break;
				default:
					std::cout << "Invalid choice! Please enter a number between 0 and 5.\n";
				}
			} while (readerChoice != 0);
			break;
		}
		case 4: {
			int reportChoice;
			do {
				//report generation submenu
				std::cout << "\n ================================\n";
				std::cout << "|        Report Generation       |\n";
				std::cout << " ================================\n";
				std::cout << "| 1. Borrowed Books Report       |\n";
				std::cout << "| 0. Back to Main Menu           |\n";
				std::cout << " ================================\n";
				std::cout << "Enter your choice (0-1): ";
				std::cin >> reportChoice;
				system("cls");
				switch (reportChoice) {
				case 1:
					library.generateBorrowedBooksReport();
					break;
				case 0:
					break;
				default:
					std::cout << "Invalid choice! Please enter 0 or 1.\n";
				}
			} while (reportChoice != 0);
			break;
		}
		case 0:
			std::cout << "Exiting...\n";
			break;
		default:
			std::cout << "Invalid choice!\n";
		}

	} while (choice != 0);

	return 0;
}