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
