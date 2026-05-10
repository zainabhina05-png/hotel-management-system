# Hotel Management Project (Without Pointers)

A simple C++ console-based hotel management system for booking rooms, managing customer details, check-out, and restaurant billing.

## File

- Main source file: `hotel project without pointers & extra lib  .cpp`

## Features

- Book a room (room range: 1 to 100)
- View customer information by room number
- Display all allotted rooms
- Edit customer details
- Customer check-out with bill display
- Restaurant orders (Breakfast, Lunch, Dinner) added to customer bill

## Room Categories and Rates

- Deluxe: Rooms `1-50` -> `Rs. 10000` per day
- Executive: Rooms `51-80` -> `Rs. 12500` per day
- Presidential: Rooms `81-100` -> `Rs. 15000` per day

## Food Charges

- Breakfast: `Rs. 500` per person
- Lunch: `Rs. 1000` per person
- Dinner: `Rs. 1200` per person

## Requirements

- C++ compiler (GCC/MinGW recommended on Windows)
- Terminal or command prompt

## Compile (Windows PowerShell)

```powershell
g++ "hotel project without pointers & extra lib  .cpp" -o "hotel_project.exe"
```

## Run (Windows PowerShell)

```powershell
.\hotel_project.exe
```

## Main Menu

1. Book A Room
2. Customer Information
3. Rooms Allotted
4. Edit Customer Details
5. Order Food from Restaurant
6. Exit

## Notes

- This project stores data in memory only; data is lost when the program exits.
- Input fields like name/address currently accept single-word input (space-separated words are not fully supported).
