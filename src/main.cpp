// Ticket Booking & Waiting System using Singly Linked List, Queue, and Stack
// Team Members:
// Muhammad Nihaas Bhatti - F2024266196
// Saim Ullah - F2024266594
// Salik Saeed - F2024266596

#include <iostream>
#include <string>
#include <limits>
using namespace std;

// ---------- Helper ----------
void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// ---------- Movie Node ----------
struct Movie {
    string title;
    bool bookedSeats[20];
    Movie* next;
};

// Insert movie at beginning
Movie* insertMovie(Movie* head, string title) {
    Movie* newMovie = new Movie;
    newMovie->title = title;
    newMovie->next = head;
    for (int i = 0; i < 20; i++) newMovie->bookedSeats[i] = false;
    cout << "Movie \"" << title << "\" added successfully.\n";
    return newMovie;
}

// Remove movie by title
Movie* removeMovie(Movie* head, string title) {
    Movie* current = head;
    Movie* prev = nullptr;
    while (current) {
        if (current->title == title) {
            if (prev) prev->next = current->next;
            else head = current->next;
            delete current;
            cout << "Movie \"" << title << "\" removed.\n";
            return head;
        }
        prev = current;
        current = current->next;
    }
    cout << "Movie not found.\n";
    return head;
}

// Display movies
void displayMovies(Movie* head) {
    if (!head) { cout << "No movies available.\n"; return; }
    Movie* temp = head;
    cout << "\n--- Movies ---\n";
    while (temp) {
        int available = 0;
        for (int i = 0; i < 20; i++) if (!temp->bookedSeats[i]) available++;
        cout << temp->title << " | Seats Left: " << available << endl;
        temp = temp->next;
    }
}

// Get movie by title
Movie* getMovie(Movie* head, string title) {
    Movie* temp = head;
    while (temp) {
        if (temp->title == title) return temp;
        temp = temp->next;
    }
    return nullptr;
}

// Show seat map
void showSeatMap(Movie* m) {
    for (int i = 0; i < 20; i++) {
        cout << (m->bookedSeats[i] ? "[X] " : "[" + to_string(i+1) + "] ");
        if ((i+1) % 5 == 0) cout << endl;
    }
}

// Book seat
bool bookSeat(Movie* m, int seat) {
    if (seat < 1 || seat > 20 || m->bookedSeats[seat-1]) return false;
    m->bookedSeats[seat-1] = true;
    return true;
}

// ---------- Customer Node (Booked List) ----------
struct Customer {
    string name;
    Movie* bookedMovie;
    Customer* next;
};

// Insert at beginning
Customer* insertCustomer(Customer* head, string name, Movie* m) {
    Customer* newCustomer = new Customer;
    newCustomer->name = name;
    newCustomer->bookedMovie = m;
    newCustomer->next = head;
    return newCustomer;
}

// Display booked customers
void displayBooked(Customer* head) {
    if (!head) { cout << "No customers booked yet.\n"; return; }
    Customer* temp = head;
    cout << "\n--- Booked Customers ---\n";
    while (temp) {
        cout << temp->name << " | " << temp->bookedMovie->title << endl;
        temp = temp->next;
    }
}

// Cancel booking
Customer* cancelBooking(Customer* head, string name) {
    Customer* current = head;
    Customer* prev = nullptr;
    while (current) {
        if (current->name == name) {
            if (prev) prev->next = current->next;
            else head = current->next;
            delete current;
            cout << "Booking cancelled for " << name << ".\n";
            return head;
        }
        prev = current;
        current = current->next;
    }
    cout << "No booking found for " << name << ".\n";
    return head;
}

// ---------- Queue Node ----------
struct QueueNode {
    string name;
    Movie* requestedMovie;
    QueueNode* next;
};
QueueNode* front = nullptr;
QueueNode* rear = nullptr;

// Enqueue at rear
void enqueue(string name, Movie* m) {
    QueueNode* newNode = new QueueNode{name, m, nullptr};
    if (!rear) front = rear = newNode;
    else { rear->next = newNode; rear = newNode; }
    cout << name << " added to waiting line for \"" << m->title << "\".\n";
}

// Dequeue from front
QueueNode* dequeue() {
    if (!front) return nullptr;
    QueueNode* temp = front;
    front = front->next;
    if (!front) rear = nullptr;
    return temp;
}

// Display queue
void displayQueue() {
    if (!front) { cout << "Waiting line is empty.\n"; return; }
    QueueNode* temp = front;
    cout << "\n--- Waiting Line ---\n";
    while (temp) {
        cout << temp->name << " | " << temp->requestedMovie->title << endl;
        temp = temp->next;
    }
}

// ---------- Stack Node (Recent Bookings) ----------
struct StackNode {
    string name;
    Movie* bookedMovie;
    StackNode* next;
};
StackNode* top = nullptr;

// Push at beginning
void push(string name, Movie* m) {
    StackNode* newNode = new StackNode{name, m, top};
    top = newNode;
}

// Display stack
void displayStack() {
    if (!top) { cout << "No recent bookings.\n"; return; }
    StackNode* temp = top;
    cout << "\n--- Recent Bookings (Last Served First) ---\n";
    while (temp) {
        cout << temp->name << " | " << temp->bookedMovie->title << endl;
        temp = temp->next;
    }
}

// ---------- Main ----------
int main() {
    Movie* movies = nullptr;          
    Customer* bookedList = nullptr;   

    int choice;
    do {
        cout << "\n--- Ticket Booking System ---\n";
        cout << "1. Admin Panel\n2. Customer Panel\n3. Exit\nChoice: ";
        cin >> choice;
        if (cin.fail()) { clearInput(); cout << "Invalid input.\n"; continue; }

        if (choice == 1) {
            int a;
            do {
                cout << "\n--- Admin Panel ---\n";
                cout << "1. Add Movie\n2. Remove Movie\n3. View Movies\n4. Back\nChoice: ";
                cin >> a;
                if (cin.fail()) { clearInput(); cout << "Invalid input.\n"; continue; }

                cin.ignore();
                string title;
                if (a == 1) {
                    cout << "Enter movie title: "; getline(cin, title);
                    if (!title.empty()) movies = insertMovie(movies, title);
                }
                else if (a == 2) {
                    cout << "Enter movie title to remove: "; getline(cin, title);
                    if (!title.empty()) movies = removeMovie(movies, title);
                }
                else if (a == 3) displayMovies(movies);

            } while (a != 4);
        }
        else if (choice == 2) {
            int c;
            do {
                cout << "\n--- Customer Panel ---\n";
                cout << "1. View Movies\n2. Join Waiting Line\n3. Issue Ticket\n4. Show Booked Customers\n5. Show Waiting Line\n6. Show Recent Bookings\n7. Back\nChoice: ";
                cin >> c;
                if (cin.fail()) { clearInput(); cout << "Invalid input.\n"; continue; }

                cin.ignore();
                string name, title;

                if (c == 1) displayMovies(movies);
                else if (c == 2) {
                    cout << "Enter your name: "; getline(cin, name);
                    cout << "Enter movie title: "; getline(cin, title);
                    Movie* m = getMovie(movies, title);
                    if (m) enqueue(name, m);
                    else cout << "Movie not found.\n";
                }
                else if (c == 3) {
                    QueueNode* nextCustomer = dequeue();
                    if (!nextCustomer) { cout << "No one in waiting line.\n"; continue; }
                    Movie* m = nextCustomer->requestedMovie;
                    int available = 0;
                    for (int i = 0; i < 20; i++) if (!m->bookedSeats[i]) available++;
                    if (available == 0) { cout << "No seats left.\n"; delete nextCustomer; continue; }

                    int ticketCount;
                    cout << nextCustomer->name << ", how many tickets? (Available: " << available << "): ";
                    cin >> ticketCount;
                    if (cin.fail() || ticketCount <= 0 || ticketCount > available) { clearInput(); cout << "Invalid count.\n"; delete nextCustomer; continue; }

                    for (int i = 0; i < ticketCount; i++) {
                        int seat;
                        showSeatMap(m);
                        cout << "Select seat #" << i+1 << ": ";
                        cin >> seat;
                        if (!bookSeat(m, seat)) i--;
                    }

                    bookedList = insertCustomer(bookedList, nextCustomer->name, m);
                    push(nextCustomer->name, m);
                    cout << ticketCount << " ticket(s) booked for " << nextCustomer->name << ".\n";
                    delete nextCustomer;
                }
                else if (c == 4) displayBooked(bookedList);
                else if (c == 5) displayQueue();
                else if (c == 6) displayStack();

            } while (c != 7);
        }

    } while (choice != 3);

    cout << "Thank you for using Ticket Booking System!\n";
    return 0;
}