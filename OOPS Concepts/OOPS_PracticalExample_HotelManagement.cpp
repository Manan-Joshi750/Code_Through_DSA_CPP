// --------------------------- Hotel Management System ---------------------------
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Room {
public:
    int roomNumber;
    string type;
    bool isAvailable;
    double price;

    Room(int roomNumber, string type, double price) {
        this->roomNumber = roomNumber;
        this->type = type;
        this->price = price;
        this->isAvailable = true;
    }

    void displayRoomDetails() const {
        cout << "Room Number: " << roomNumber << ", Type: " << type
             << ", Price: $" << price << ", Available: " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Guest {
public:
    string name;
    string contact;

    Guest(string name, string contact) {
        this->name = name;
        this->contact = contact;
    }
};

class Booking {
public:
    Room* room;
    Guest* guest;
    int numberOfDays;

    Booking(Room* room, Guest* guest, int numberOfDays) {
        this->room = room;
        this->guest = guest;
        this->numberOfDays = numberOfDays;
        room->isAvailable = false;
    }

    double calculateTotalCost() const {
        return room->price * numberOfDays;
    }

    void displayBookingDetails() const {
        cout << "Guest: " << guest->name << ", Contact: " << guest->contact
             << ", Room: " << room->roomNumber << ", Days: " << numberOfDays
             << ", Total Cost: $" << calculateTotalCost() << endl;
    }
};

class Hotel {
    vector<Room> rooms;
    vector<Booking> bookings;

public:
    Hotel(int roomCount) {
        for (int i = 1; i <= roomCount; ++i) {
            double price = (i % 2 == 0) ? 150 : 100; // Deluxe rooms are more expensive
            rooms.push_back(Room(i, i % 2 == 0 ? "Deluxe" : "Standard", price));
        }
    }

    void displayAvailableRooms() const {
        cout << "Available Rooms: \n";
        for (const auto &room : rooms) {
            if (room.isAvailable) {
                room.displayRoomDetails();
            }
        }
    }

    bool bookRoom(string guestName, string guestContact, int days) {
        for (auto &room : rooms) {
            if (room.isAvailable) {
                Guest* guest = new Guest(guestName, guestContact);
                bookings.push_back(Booking(&room, guest, days));
                cout << "Room " << room.roomNumber << " booked for " << guestName << "\n";
                return true;
            }
        }
        cout << "No rooms available!\n";
        return false;
    }

    void displayAllBookings() const {
        cout << "Bookings: \n";
        for (const auto &booking : bookings) {
            booking.displayBookingDetails();
        }
    }

    void checkoutGuest(int roomNumber) {
        for (auto &booking : bookings) {
            if (booking.room->roomNumber == roomNumber) {
                booking.room->isAvailable = true;
                cout << "Room " << roomNumber << " is now available. Checkout complete for guest: "
                     << booking.guest->name << "\n";
                return;
            }
        }
        cout << "No booking found for room number " << roomNumber << "\n";
    }

    void displayRevenue() const {
        double totalRevenue = 0;
        for (const auto &booking : bookings) {
            totalRevenue += booking.calculateTotalCost();
        }
        cout << "Total Revenue: $" << totalRevenue << endl;
    }
};

int main() {
    Hotel hotel(5); // Initialize a hotel with 5 rooms

    // Display available rooms
    hotel.displayAvailableRooms();

    // Book rooms for guests
    hotel.bookRoom("Alice", "1234567890", 3);
    hotel.bookRoom("Bob", "0987654321", 2);

    // Display bookings
    hotel.displayAllBookings();

    // Display revenue
    hotel.displayRevenue();

    // Checkout a guest
    hotel.checkoutGuest(1);

    // Display available rooms after checkout
    hotel.displayAvailableRooms();

    return 0;
}