#include <iostream>
#include <Windows.h>
#include<string>
using namespace std;

#include <iostream>
#include <Windows.h>
using namespace std;

struct node {
    string patient_name;
    int fee_confirmation;
    string contact_number;

    string medicine;
    string dosage;

    node* next;
    node* prev;
};

class queue {
    node* front;
    node* rear;

public:
    queue() : front(nullptr), rear(nullptr) {} // Constructor to initialize pointers

    // Receptionist section; create appointment option
    void create_appointment(string name, int fee, string contact) {
        node* new_node = new node();
        new_node->patient_name = name;
        new_node->fee_confirmation = fee;
        new_node->contact_number = contact;

        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (front == nullptr) {
            front = rear = new_node;
        }
        else {
            rear->next = new_node;
            new_node->prev = rear;
            rear = new_node;
        }
    }

    // Receptionist section; cancel appointment option
    void cancel_appointment(string name) {
        node* todelete = front;

        if (todelete == nullptr) {
            cout << "There is no appointment registered." << endl;
            return;
        }

        while (todelete != nullptr && name != todelete->patient_name) {
            todelete = todelete->next;
        }

        if (todelete == nullptr) {
            cout << "Appointment not found." << endl;
            return;
        }

        if (todelete == front) {
            front = front->next;
            if (front != nullptr)
                front->prev = nullptr;
            else
                rear = nullptr;
        }
        else if (todelete == rear) {
            rear = rear->prev;
            rear->next = nullptr;
        }
        else {
            todelete->prev->next = todelete->next;
            todelete->next->prev = todelete->prev;
        }

        delete todelete;
        cout << "Appointment canceled." << endl;
    }

    // Receptionist section; confirm appointment option
    void appointment_confirmation(string name) {
        node* temp = front;
        int n = 0;
        while (temp != nullptr && name != temp->patient_name) {
            ++n;
            temp = temp->next;
        }

        if (temp != nullptr) {
            cout << "Appointment for Patient: " << temp->patient_name << endl;
            cout << "Appointment number: " << n << endl;
        }
        else {
            cout << "Appointment not found." << endl;
        }
    }

    // Receptionist section; create a priority appointment option
    void priority_appointment(string name, int fee, string contact) {
        node* new_node = new node();
        new_node->patient_name = name;
        new_node->fee_confirmation = fee;
        new_node->contact_number = contact;

        new_node->next = nullptr;
        new_node->prev = nullptr;

        if (front == nullptr) {
            front = rear = new_node;
        }
        else {
            new_node->next = front;
            front->prev = new_node;
            front = new_node;
        }

        cout << "Priority Appointment created" << endl;
    }

    void show_all_appointments() {
        node* temp = front;
        int n = 0;
        while (temp != nullptr) {
            cout << "    " << ++n << "   " << temp->contact_number << "   " << temp->patient_name << endl;
            temp = temp->next;
        }
    }

    void first_appointment() {
        cout << "Patient Name: " << front->patient_name << endl;
        cout << "Patient Contact: " << front->contact_number << endl;
        cout << "Fee Status: Paid" << endl;
    }

    void get_prescription(string med, string dos) {
        front->medicine = med;
        front->dosage = dos;
    }

    node* tranfer() {
        node* t_node = front;

        front = t_node->next;
        t_node->next = NULL;
        front->prev = NULL;

        return t_node;
    }

    void add_node(node* node) {

        if (front == NULL) {
            node->next = node->prev = NULL;
            front = rear = node;
            return;
        }

        node->next = NULL;
        node->prev = front;
        front->next = node;
        rear = node;
    }

    node* first_pharmacist_order() {
        node* temp = front;

        if (front == NULL) {
            cout << "No orders to prepare." << endl;
            return;
        }
        cout << "Patients Name: " << temp->patient_name << endl;
        cout << "Fee Status: Paid" << endl << endl;
        cout << "Medicine: " << temp->medicine << endl;
        cout << "Dosage: " << temp->dosage << endl;

        front = temp->next;
        temp->next = NULL;
        return temp;
    }

    void daily_revenue_appointments() {
        node* temp = front;
        int n = 0;
        int sum = 0;
        while (temp != nullptr) {
            cout << "    " << ++n << "   Paid   " << temp->contact_number << "   " << temp->patient_name << endl;
            sum += temp->fee_confirmation;
            temp = temp->next;
        }

        cout << "Total Revenue Earned (Appointments): " << sum;
    }
};

struct NODE {
    string medicine_name;
    string quantity;

    NODE* next;

    NODE() : next(nullptr) {}
    ~NODE() {}
};

class stack {
    NODE* top;

public:
    stack() : top(nullptr) {}

    void push_inventory(string name, string quantity) {
        NODE* new_node = new NODE();
        new_node->medicine_name = name;
        new_node->quantity = quantity;
        new_node->next = top;
        top = new_node;

        cout << "Element added to the inventory." << endl;
    }

    void pop_inventory() {
        if (top == nullptr) {
            cout << "Inventory is empty." << endl;
            return;
        }

        NODE* temp = top;
        top = top->next;
        delete temp;

        cout << "Element removed from the inventory." << endl;
    }

    void display_inventory() {
        if (top == nullptr) {
            cout << "Inventory is empty." << endl;
            return;
        }

        NODE* temp = top;
        int n = 0;
        while (temp != nullptr) {
            cout << ++n << " " << temp->medicine_name << " " << temp->quantity << endl;
            temp = temp->next;
        }
    }
};


node* head;

void insert_node(node* node) {
    if (head == NULL) {
        head = node;
    }
    node->next = head;
    head = node;
}

int main() {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Change color to yellow
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN);
    queue q1; queue q2; stack s1; 

    q1.create_appointment("Alex", 1500, "12345");
    q1.create_appointment("Ben", 1500, "23456");
    q1.create_appointment("Shelli", 1500, "34567");
    q1.create_appointment("Chad", 1500, "45678");
    s1.push_inventory("Panadol", "53");
    s1.push_inventory("Calamox", "27");
    s1.push_inventory("Brufen", "14");
    s1.push_inventory("Priton", "33");

    

main_menu:
    system("cls");
    cout << "WELCOME!" << endl;
    cout << "APPOINTMENT PRIORITY MANAGEMENT" << endl;
    cout << "Log-in as: " << endl;
    cout << "1- Receptionist\n2- Pharmacist\n3- Doctor" << endl;
    int option;
    cout << "Enter your choice: ";
    cin >> option;
    if (option == 1) {
        
    receptionist_dashboard:
        system("cls");
        cout << "RECEPTIONIST DASHBOARD" << endl;
        cout << "Select an option: " << endl;
        cout << "1- Create Appointment\n2- Cancel Appointment\n3- Confirm Appointment\n4- Add Priority Appointment\n5- Show All Appointments\n6- Show Daily Revenue\n\n0- Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        if (option == 1) {
            system("cls");
            string name;
            string contact;
            int fee;

            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Enter Contact Number: ";
            cin >> contact;
            cout << "Enter Fee: ";
            cin >> fee;

            q1.create_appointment(name, fee, contact);
            cout << "Appointment created successfully." << endl;
            goto receptionist_dashboard;
        }
        else if (option == 2) {
            system("cls");
            string name;
            cout << "Enter Patient Name: ";
            cin >> name;
            q1.cancel_appointment(name);

            cout << endl << endl;
            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto receptionist_dashboard;
            }
        }
        else if (option == 3) {
            system("cls");
            string name;
            cout << "Enter Patient Name: ";
            cin >> name;
            q1.appointment_confirmation(name);

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto receptionist_dashboard;
            }
        }
        else if (option == 4) {
            system("cls");
            string name;
            string contact;
            int fee;

            cout << "Enter Patient Name: ";
            cin >> name;
            cout << "Enter Contact Number: ";
            cin >> contact;
            cout << "Enter Fee: ";
            cin >> fee;

            q1.priority_appointment(name, fee, contact);

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto receptionist_dashboard;
            }
        }
        else if (option == 5) {
            system("cls");
            q1.show_all_appointments();

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto receptionist_dashboard;
            }
        }
        else if (option == 6) {
            system("cls");
            q2.daily_revenue_appointments();

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto receptionist_dashboard;
            }
            
        }
        else if(option == 0){
            goto main_menu;
        }
    }
    else if (option == 2){

    pharmacist_dashboard:
        system("cls");
        cout << "PHARMACIST DASHBOARD" << endl;
        cout << "Select an option: " << endl;
        cout << "1- Prepare Order\n2- Create Inventory List\n3- Show Inventory List\n\n0- Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> option;
        if (option == 1) {

        next_order:
            q2.first_pharmacist_order();

            cout << "1- Proceed to next order\n0- Go Back" << endl;
            cin >> option;
            if (option == 1) {
                goto next_order;
            }
            else if (option == 0) {
                goto pharmacist_dashboard;
            }
        }
        else if (option == 2) {
            add_again:
            string name, quantity;
            cout << "Enter Medicine name: ";
            cin >> name;
            cout << "Enter Quantity: ";
            cin >> quantity;
            s1.push_inventory(name, quantity);

            cout << "1- Add more products\n0- Go Back" << endl;
            cin >> option;
            if (option == 1) {
                goto add_again;
            }
            else if (option == 0) {
                goto pharmacist_dashboard;
            }
        }
        else if (option == 3) {
            s1.display_inventory();

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto pharmacist_dashboard;
            }
        }
        else if (option == 0) {
            goto main_menu;
        }
        else {
            
        }
        
    }
    else if (option == 3) {
    
    doctor_dashboard:
        system("cls");
        cout << "DOCTOR'S DASHBOARD" << endl;
        cout << "Select an option: " << endl;
        cout << "1- Attend Appointment\n2- Show All Appointments\n3- Show Daily Revenue\n\n0- Main Menu" << endl;
        cout << "Enter your choice: ";
        cin >> option;

        if (option == 1) {
        prescribe:
            system("cls");
            q1.first_appointment();
            string med;
            string dos;
            cout << "WRITE PRESCRIPTION:" << endl;
            cout << "Enter medicine name: ";
            cin >> med;
            cout << "Enter dosage: ";
            cin >> dos;

            q1.get_prescription(med, dos);

            cout << "1- Proceed to next appointment." << endl << endl;
            cout << "0- Go back." << endl;
            cin >> option;
            if (option == 1) {
                q2.add_node(q1.tranfer());
                goto prescribe;
            }
            else if (option == 0) {
                q2.add_node(q1.tranfer());
                goto doctor_dashboard;
            }
        }
        else if (option == 2) {
            system("cls");
            q1.show_all_appointments();

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto doctor_dashboard;
            }
        }
        else if (option == 3) {
            system("cls");
            q2.daily_revenue_appointments();

            cout << "Enter 0 to go back." << endl;
            cin >> option;
            if (option == 0) {
                goto doctor_dashboard;
            }
        }
        else if (option == 0) {
            goto main_menu;
        }
        else {

        }
        
    }
    return 0;
}