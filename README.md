# 🎟️ Ticket Booking & Waiting System

A console-based C++ simulation of a real-time ticket booking system for movies and events. Customers join a waiting queue, get issued tickets in order, and recent bookings are tracked — demonstrating all three core data structure concepts in one cohesive project.

**Course:** Data Structures Lab — Spring 2025  
**Institution:** University of Management and Technology (UMT), Lahore  
**Language:** C++

---

## 📊 Data Structures Used

| Structure | Implementation | Role in System |
|-----------|----------------|----------------|
| **Singly Linked List** | `MovieManager` | Stores the movie catalog |
| **Singly Linked List** | `CustomerManager` | Stores all confirmed bookings |
| **Queue** (linked list) | `WaitingQueue` | Manages the waiting line — FIFO |
| **Stack** (linked list) | `BookingStack` | Tracks recent ticket issuances — LIFO |

---

## 🎯 Features

### Admin Panel (Password Protected)
- Add movies to the catalog
- Remove movies from the catalog
- View all available movies

### Customer Panel
- View available movies
- Join the waiting line for a movie
- Issue ticket to the next customer in line
- Cancel an existing booking
- View all booked customers
- View current waiting line
- View recent bookings (latest first)

---

## 🎬 Demo
```
=====================================
  Ticket Booking System
=====================================
1. Admin Panel
2. Customer Panel
3. Exit
Choice: 2

=====================================
  Customer Panel
=====================================
1. View Movies
2. Join Waiting Line
3. Issue Ticket (next in line)
4. Cancel Booking
...
Choice: 2

Enter your name: Ahmed Khan
Enter movie title: Inception
"Ahmed Khan" added to waiting line for "Inception".

Choice: 3
Ticket issued to "Ahmed Khan" for "Inception".

Choice: 7

=====================================
  Recent Bookings (latest first)
=====================================
  1. Ahmed Khan → Inception
```

---

## Getting Started

### Prerequisites
- A C++ compiler supporting C++11 or later (GCC, Clang, MSVC)

### Compile & Run

```bash
# Clone the repository
git clone https://github.com/YOUR_USERNAME/ticket-booking-system.git
cd ticket-booking-system

# Compile
g++ -std=c++11 -o ticket_system src/main.cpp

# Run
./ticket_system
```

On Windows (MinGW):
```bash
g++ -std=c++11 -o ticket_system.exe src/main.cpp
ticket_system.exe
```

> **Default admin password:** `umt101`

---

## Project Structure

```
ticket-booking-system/
├── src/
│   └── main.cpp          # Full application source
├── docs/
│   └── proposal.md       # Original project proposal
├── screenshots/          # Sample output screenshots
└── README.md
```

---

## Design Overview

```
MovieManager        CustomerManager     WaitingQueue        BookingStack
(Linked List)       (Linked List)       (Queue — FIFO)      (Stack — LIFO)
─────────────       ───────────────     ──────────────       ────────────
Movie nodes    →    Confirmed           Customers wait   →   Most recent
added by admin      bookings after      here until            bookings on
                    ticket issued       ticket issued         top
```

**Flow:** Admin adds movies → Customer joins queue → Ticket is issued (dequeue) → Customer added to booked list (linked list) + recent bookings (push to stack)

---

## Concepts Demonstrated

- Singly linked list operations (insert, delete, traverse, search)
- Queue operations (enqueue, dequeue) with FIFO ordering
- Stack operations (push, display) with LIFO ordering
- Dynamic memory allocation and proper deallocation (destructors)
- OOP encapsulation — private data members with public interfaces
- `const` correctness on read-only methods
- Multi-panel menu-driven console interface
- Input validation and stream recovery

---

**Instructor:** Muhammad Rizwan — Data Structures Lab, V1, SST, UMT
