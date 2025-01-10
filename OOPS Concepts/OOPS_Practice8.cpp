/*You are building a system for an online bookstore where each Book object is
initialized dynamically with data like title , author , price , and availableCopies . Overload
the constructor of the Book class such that it allows creating a Book object with partial
data (e.g., without availableCopies ) and full data. Additionally, write a program that
dynamically initializes an array of Book objects and adjusts the availableCopies based

on the stock received from the publisher. Ensure that the stock adjustment happens
only when new copies are delivered. */
#include <iostream>
using namespace std;

class Book {
    private:
    string title, author;
    double price;
    int availableCopies;

    public:
    Book(string t, string a, double p, int copies = 0) : title(t), author(a), price(p), availableCopies(copies) {}
        void adjustStock(int newCopies) {
        if (newCopies > 0) {
        availableCopies += newCopies;
        }
    }

    void displayBook() {
        cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << ", Available Copies: " <<
        availableCopies << endl;
    }
};

int main() {
    Book book1("C++ Programming", "Author A", 29.99, 10);
    Book book2("Java Basics", "Author B", 19.99);
    book1.displayBook();
    book2.displayBook();
    book1.adjustStock(5);
    book1.displayBook();
    return 0;
}