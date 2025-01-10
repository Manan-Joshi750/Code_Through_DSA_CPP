/*Create a system where the class Student holds private data about a student’s name
and grades, and the class Teacher evaluates the student. The Teacher class has a
function that accepts a Student object as an argument and calculates the grade point
average (GPA) based on the grades. The function should print a message based on the
GPA (e.g., &quot;Excellent&quot; if GPA&gt;9, &quot;Good&quot; if GPA &gt; 7,
etc.). Make sure to handle a situation where a student has no grades entered. */
#include <iostream>
#include <vector>
using namespace std;

class Student {
    private:
    string name;
    vector<int> grades;

    public:
    Student(string n, vector<int> g) : name(n), grades(g) {}

    vector<int> getGrades() const {
        return grades;
    }
};

class Teacher {
    public:
    void evaluateStudent(const Student& s) {
        vector<int> grades = s.getGrades();
        if (grades.empty()) {
        cout << "No grades available" << endl;
        return;
    }

    int sum = 0;
        for (int grade : grades) {
        sum += grade;
    }

    double gpa = sum / (double)grades.size();
        if (gpa > 9) cout << "Excellent" << endl;
        else if (gpa > 7) cout << "Good" << endl;
        else if (gpa > 5) cout << "Average" << endl;
        else cout << "Needs Improvement" << endl;
    }
};

int main() {
    Student student1("John", {8, 9, 10, 7});
    Student student2("Jon", {8, 9, 2, 7});
    Student student3("Jn", {8, 9, 5, 7});
    Teacher teacher;
    teacher.evaluateStudent(student1);
    teacher.evaluateStudent(student2);
    teacher.evaluateStudent(student3);
    return 0;
}