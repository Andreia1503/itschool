#ifndef EMPLOYEE_H
#define EMPLOYEE_H

class Employee
{
private:
    int id;
    std::string name;
    std::string job_title;
public:
    Employee(int id, std::string name, std::string job_title);
    int getId() const;
    std::string getName() const;
    std::string getJobTitle() const;
    void printInfo() const;
};
#endif

