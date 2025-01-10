/*Write a C++program to create a class `Student` that stores marks of a student in 3
subjects. Define a parameterized constructor to initialize the marks. Overload the `+`
operator to add the marks of two students and find out which student has scored higher. */
#include <iostream>
using namespace std;

class Student {
    private:
    int marks[3];

    public:
    Student(int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    Student operator+(const Student &other) {
        return Student(marks[0] + other.marks[0],
        marks[1] + other.marks[1],
        marks[2] + other.marks[2]);
    }

    int totalMarks() const {
        return marks[0] + marks[1] + marks[2];
    }

    void displayMarks() const {
        cout << "Marks: " << marks[0] << ", " << marks[1] << ", " << marks[2] << endl;
    }

    void compareWith(const Student &other) const {
        if (totalMarks() > other.totalMarks()) {
            cout << "This student has higher marks." << endl;
        } else if (totalMarks() < other.totalMarks()) {
            cout << "The other student has higher marks." << endl;
        } else {
            cout << "Both students have equal marks." << endl;
        }
    }
};

int main() {
    Student student1(85, 90, 78);
    Student student2(88, 76, 95);
    cout << "Student 1: ";
    student1.displayMarks();
    cout << "Student 2: ";
    student2.displayMarks();
    Student totalMarksStudent = student1 + student2;
    cout << "Total Marks of both students: ";
    totalMarksStudent.displayMarks();
    cout << "Comparison of marks:" << endl;
    student1.compareWith(student2);
    return 0;
}