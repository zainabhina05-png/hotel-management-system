#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

const int MAX_ROOMS = 100;

struct Customer {
    int room_no;
    char name[30];
    char address[50];
    char phone[15];
    long days;
    long cost;
    char rtype[30];
};

Customer customers[MAX_ROOMS];
bool roomOccupied[MAX_ROOMS] = { false };
int customerCount = 0;

void addCustomer();
void displayCustomer();
void listRooms();
void editCustomer();
int checkRoom(int room_no);
void modifyCustomer(int room_no);
void deleteCustomer();
void orderFood(int room_no, const char* mealType);
void restaurantMenu();

int main() {
    int choice;
    do {
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t **THE HOTEL**";
        cout << "\n\t\t\t\t *************";
        cout << "\n\t\t\t\t * MAIN MENU *";
        cout << "\n\t\t\t\t *************";
        cout << "\n\n\n\t\t\t\t1. Book A Room";
        cout << "\n\t\t\t\t2. Customer Information";
        cout << "\n\t\t\t\t3. Rooms Allotted";
        cout << "\n\t\t\t\t4. Edit Customer Details";
        cout << "\n\t\t\t\t5. Order Food from Restaurant";
        cout << "\n\t\t\t\t6. Exit";
        cout << "\n\n\t\t\t\tEnter Your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addCustomer(); break;
            case 2: displayCustomer(); break;
            case 3: listRooms(); break;
            case 4: editCustomer(); break;
            case 5: restaurantMenu(); break;
            case 6: break;
            default: cout << "\n\n\t\t\tWrong choice."; break;
        }
    } while (choice != 6);

    return 0;
}

void addCustomer() {
    Customer customer;
    cout << "\n ENTER CUSTOMER DETAILS";
    cout << "\n ----------------------";
    cout << "\n\n Room Number: ";
    cin >> customer.room_no;

    if (checkRoom(customer.room_no)) {
        cout << "\n Sorry, Room is already booked.\n";
    } else if (customer.room_no < 1 || customer.room_no > MAX_ROOMS) {
        cout << "\n Sorry, Room does not exist.\n";
    } else {
        cout << " Name: ";
        cin >> customer.name;
        cout << " Address: ";
        cin >> customer.address;
        cout << " Phone Number: ";
        cin >> customer.phone;
        cout << " Number of Days: ";
        cin >> customer.days;

        if (customer.room_no >= 1 && customer.room_no <= 50) {
            strcpy(customer.rtype, "Deluxe");
            customer.cost = customer.days * 10000;
        } else if (customer.room_no >= 51 && customer.room_no <= 80) {
            strcpy(customer.rtype, "Executive");
            customer.cost = customer.days * 12500;
        } else if (customer.room_no >= 81 && customer.room_no <= 100) {
            strcpy(customer.rtype, "Presidential");
            customer.cost = customer.days * 15000;
        }

        customers[customerCount++] = customer;
        roomOccupied[customer.room_no - 1] = true; // Mark room as occupied
        cout << "\n Room has been booked.";
    }
    cout << "\n Press any key to continue.";
    cin.ignore();
    cin.get();
}

void displayCustomer() {
    int room_no;
    cout << "\n Enter Room Number: ";
    cin >> room_no;

    if (room_no < 1 || room_no > MAX_ROOMS || !roomOccupied[room_no - 1]) {
        cout << "\n Room is Vacant.";
    } else {
        Customer& customer = customers[room_no - 1];
        cout << "\n Customer Details";
        cout << "\n ----------------";
        cout << "\n\n Room Number: " << customer.room_no;
        cout << "\n Name: " << customer.name;
        cout << "\n Address: " << customer.address;
        cout << "\n Phone Number: " << customer.phone;
        cout << "\n Staying for " << customer.days << " days.";
        cout << "\n Room Type: " << customer.rtype;
        cout << "\n Total cost of stay: " << customer.cost;
    }
    cout << "\n\n Press any key to continue.";
    cin.ignore();
    cin.get();
}

void listRooms() {
    cout << "\n\t\t\t    LIST OF ROOMS ALLOTED";
    cout << "\n\t\t\t   -----------------------";
    cout << "\n\n +---------+------------------+-----------------+--------------+--------------+";
    cout << "\n | Room No.|    Guest Name    |      Address    |   Room Type  |  Contact No. |";
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";

    for (int i = 0; i < customerCount; i++) {
        Customer& customer = customers[i];
        cout << "\n |" << setw(9) << customer.room_no << " |";
        cout << setw(17) << customer.name << " |";
        cout << setw(16) << customer.address << " |";
        cout << setw(13) << customer.rtype << " |";
        cout << setw(13) << customer.phone << " |";
    }
    cout << "\n +---------+------------------+-----------------+--------------+--------------+";
    cout << "\n\n\n\t\t\tPress any key to continue.";
    cin.ignore();
    cin.get();
}

void editCustomer() {
    int choice;
    cout << "\n EDIT MENU";
    cout << "\n ---------";
    cout << "\n\n 1. Modify Customer Information.";
    cout << "\n 2. Customer Check Out.";
    cout << "\n Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: {
            int room_no;
            cout << "\n Enter Room Number: ";
            cin >> room_no;
            modifyCustomer(room_no);
            break;
        }
        case 2: deleteCustomer(); break;
        default: cout << "\n Wrong Choice."; break;
    }
    cout << "\n Press any key to continue.";
    cin.ignore();
    cin.get();
}

int checkRoom(int room_no) {
    if (room_no < 1 || room_no > MAX_ROOMS) {
        return 2; // Room does not exist
    }
    return roomOccupied[room_no - 1] ? 1 : 0; // Room is booked or not
}

void modifyCustomer(int room_no) {
    if (room_no < 1 || room_no > MAX_ROOMS || !roomOccupied[room_no - 1]) {
        cout << "\n Sorry, Room is Vacant.";
        return;
    }

    Customer& customer = customers[room_no - 1];
    cout << "\n Enter New Name: ";
    cin >> customer.name;
    cout << "\n Enter New Address: ";
    cin >> customer.address;
    cout << "\n Enter New Phone Number: ";
    cin >> customer.phone;
    cout << "\n Enter New Number of Days of Stay: ";
    cin >> customer.days;

    if (customer.room_no >= 1 && customer.room_no <= 50) {
        strcpy(customer.rtype, "Deluxe");
        customer.cost = customer.days * 10000;
    } else if (customer.room_no >= 51 && customer.room_no <= 80) {
        strcpy(customer.rtype, "Executive");
        customer.cost = customer.days * 12500;
    } else if (customer.room_no >= 81 && customer.room_no <= 100) {
        strcpy(customer.rtype, "Presidential");
        customer.cost = customer.days * 15000;
    }

    cout << "\n Customer information has been modified.";
}

void deleteCustomer() {
    int room_no;
    char ch;
    cout << "\n Enter Room Number: ";
    cin >> room_no;

    if (room_no < 1 || room_no > MAX_ROOMS || !roomOccupied[room_no - 1]) {
        cout << "\n Sorry, Room is Vacant.";
        return;
    }

    Customer& customer = customers[room_no - 1];
    cout << "\n Name: " << customer.name;
    cout << "\n Address: " << customer.address;
    cout << "\n Phone Number: " << customer.phone;
    cout << "\n Room Type: " << customer.rtype;
    cout << "\n Your total bill is: Rs. " << customer.cost;
    cout << "\n\n Do you want to check out this customer (y/n): ";
    cin >> ch;

    if (ch == 'y') {
        roomOccupied[room_no - 1] = false; // Mark room as vacant
        cout << "\n Customer Checked Out.";
    }
}

void restaurantMenu() {
    int room_no, choice;
    cout << "\n RESTAURANT MENU:";
    cout << "\n --------------- ";
    cout << "\n\n 1. Order Breakfast\n 2. Order Lunch\n 3. Order Dinner";
    cout << "\n\n Enter your choice: ";
    cin >> choice;
    cout << " Enter Room Number: ";
    cin >> room_no;

    switch (choice) {
        case 1: orderFood(room_no, "Breakfast"); break;
        case 2: orderFood(room_no, "Lunch"); break;
        case 3: orderFood(room_no, "Dinner"); break;
        default: cout << "\n Invalid choice."; break;
    }
    cout << "\n\n Press any key to continue.";
    cin.ignore();
    cin.get();
}

void orderFood(int room_no, const char* mealType) {
    int num;
    if (room_no < 1 || room_no > MAX_ROOMS || !roomOccupied[room_no - 1]) {
        cout << "\n Sorry, Room is Vacant.";
        return;
    }

    Customer& customer = customers[room_no - 1];
    cout << " Enter number of people: ";
    cin >> num;

    long pay = 0;
    if (strcmp(mealType, "Breakfast") == 0) {
        pay = 500 * num;
    } else if (strcmp(mealType, "Lunch") == 0) {
        pay = 1000 * num;
    } else if (strcmp(mealType, "Dinner") == 0) {
        pay = 1200 * num;
    }
    customer.cost += pay;
    cout << "\n Amount added to the bill: Rs. " << pay;
} 
