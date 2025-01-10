/*You are tasked with building a system to manage academic records. Each Record
object stores information about the student’s name, ID, and an array of 5 exam scores.
The system needs to duplicate records when a student transfers departments, and it
should be done in a way that each transferred record is an exact copy, but changes to
one record should not affect the other. */
#include <iostream>
#include <string>
using namespace std;

class Record {
    private:
    string name;
    int studentID;
    int* examScores;

    public:
    Record(string studentName, int id, int scores[5]) {
        name = studentName;
        studentID = id;
        examScores = new int[5];

        for (int i = 0; i < 5; ++i) {
            examScores[i] = scores[i];
        }
    }

    Record(const Record& other) {
        name = other.name;
        studentID = other.studentID;
        examScores = new int[5];

        for (int i = 0; i < 5; ++i) {
            examScores[i] = other.examScores[i];
        }
    }

    Record& operator=(const Record& other) {
        if (this == &other) {
            return *this;
        }

        delete[] examScores;
        name = other.name;
        studentID = other.studentID;
        examScores = new int[5];

        for (int i = 0; i < 5; ++i) {
            examScores[i] = other.examScores[i];
        }

        return *this;
    }

    ~Record() {
        delete[] examScores;
    }

    void displayRecord() const {
        cout << "Name: " << name << ", ID: " << studentID << ", Exam Scores: ";
        for (int i = 0; i < 5; ++i) {
            cout << examScores[i] << " ";
        }
        cout << endl;
    }

    void updateScore(int index, int newScore) {
        if (index >= 0 && index < 5) {
            examScores[index] = newScore;
        } else {
            cout << "Invalid index!" << endl;
        }
    }
};

int main() {
    int scores[5] = {85, 90, 78, 92, 88};
    Record student1("John Doe", 12345, scores);
    cout << "Original Record (student1):" << endl;
    student1.displayRecord();
    Record student2 = student1;
    cout << "\nCopied Record (student2):" << endl;
    student2.displayRecord();
    student2.updateScore(0, 95);
    cout << "\nAfter updating student2's first score:" << endl;
    cout << "Original Record (student1):" << endl;
    student1.displayRecord();
    cout << "Updated Copied Record (student2):" << endl;
    student2.displayRecord();
    return 0;
}