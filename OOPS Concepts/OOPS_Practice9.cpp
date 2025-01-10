/*You are building a ticket booking system for a bus company. The company allows
users to book tickets either with or without specifying additional options like food service
and extra luggage allowance. Write a function `bookTicket()` that allows a passenger to

book a ticket with a default argument for food service and luggage. Use both call by
value and call by reference to show how the ticket booking information is modified. */
#include <iostream>
#include <string>
using namespace std;

class Ticket {
    public:
    string passengerName;
    bool foodService;
    bool extraLuggage;

    Ticket(string name, bool food = false, bool luggage = false)
    : passengerName(name), foodService(food), extraLuggage(luggage) {}
    void display() const {
        cout << "Passenger: " << passengerName
        << "\nFood Service: " << (foodService ? "Yes" : "No")
        << "\nExtra Luggage: " << (extraLuggage ? "Yes" : "No") << endl;
    }
};

void bookTicketByValue(Ticket ticket) {
    ticket.foodService = true;
    ticket.extraLuggage = true;
    cout << "\nTicket details after booking (by value):" << endl;
    ticket.display();
    }

void bookTicketByReference(Ticket &ticket) {
    ticket.foodService = true;
    ticket.extraLuggage = true;
    cout << "\nTicket details after booking (by reference):" << endl;
    ticket.display();
}

int main() {
    Ticket t1("John Doe");
    cout << "Initial ticket details:" << endl;
    t1.display();
    bookTicketByValue(t1);

    cout << "\nTicket details after call by value:" << endl;
    t1.display();
    bookTicketByReference(t1);
    cout << "\nTicket details after call by reference:" << endl;
    t1.display();
    return 0;
}