/*Imagine you are developing a library management system. Create a `Book` class that
includes a title and the number of available copies. Write a function `borrowBook` that
takes a reference to the number of copies and a string title as parameters. If the number
of available copies is greater than zero, decrease the count by one and confirm the
borrowing process. Otherwise, indicate that the book is not available. */
#include <iostream>
#include <string>
using namespace std;

class Book {
    private:
    string title;
    int availableCopies;

    public:
    Book(string bookTitle, int copies) : title(bookTitle), availableCopies(copies) {}
        void displayInfo() const {
        cout << "Title: " << title << ", Available Copies: " << availableCopies << endl;
    }

    int getAvailableCopies() const {
        return availableCopies;
    }

    void borrowBook() {
        if (availableCopies > 0) {
            availableCopies--;
            cout << "You've successfully borrowed '" << title << "'. Remaining copies: " << availableCopies <<
            endl;
        } else {
            cout << "Sorry, '" << title << "' is not available right now." << endl;
        }
    }

    string getTitle() const {
        return title;
    }
};

void borrowBook(Book &book) {
    book.borrowBook();
}

int main() {
    Book book1("The Great Gatsby", 3);
    Book book2("1984", 0);
    cout << "Library Inventory:" << endl;
    book1.displayInfo();
    book2.displayInfo();
    cout << "\nTrying to borrow 'The Great Gatsby':" << endl;
    borrowBook(book1);
    cout << "\nTrying to borrow '1984':" << endl;
    borrowBook(book2);
    cout << "\nUpdated Library Inventory:" << endl;
    book1.displayInfo();
    book2.displayInfo();
    return 0;
}