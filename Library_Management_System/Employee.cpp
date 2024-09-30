#include <iostream>
#include <iomanip>
#include "Employee.h"

// Constructor to initialize an employee object
Employee::Employee(int id, std::string name, std::string job_title) :
    id(id), name(name), job_title(job_title) {}


// Getters for employee attributes
int Employee::getId() const
{
    return id;
}

std::string Employee::getName() const
{
    return name;
}

std::string Employee::getJobTitle() const
{
    return job_title;
}

// Prints employee information
void Employee::printInfo() const
{
    std::cout << id << " | "
        << std::left << std::setw(20) << name << " | "
        << job_title << "\n";
    std::cout << "------------------------------------------------\n";
}