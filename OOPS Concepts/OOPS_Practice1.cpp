/*Objective: Implement single inheritance between two classes.
Task: Create a base class Person with attributes name and age, and a derived class
Student that inherits from Person and has an additional attribute grade. Implement
methods to set and display these attributes in both classes. */
#include <iostream>
#include <string>
using namespace std;

class Person {
    protected:
    string name;
    int age;

    public:
    // Method to set attributes of Person
    void setPersonDetails(const string &name, int age) {
        this->name = name;
        this->age = age;
    }

    // Method to display attributes of Person
    void displayPersonDetails() const {
        cout << "Name: " << name << ", Age: " << age << endl;
    }
};

class Student : public Person {
    private:
    char grade;

    public:
    // Method to set attributes of Student
    void setStudentDetails(const string &name, int age, char grade) {
        setPersonDetails(name, age); // Set base class attributes
        this->grade = grade;
    }

    // Method to display attributes of Student
    void displayStudentDetails() const {
        displayPersonDetails(); // Display base class attributes
        cout << "Grade: " << grade << endl;
    }
};

int main() {
    Student student;
    // Set student details
    student.setStudentDetails("Alice", 20, 'A');
    // Display student details
    student.displayStudentDetails();
    return 0;
}