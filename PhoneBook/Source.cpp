#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

class Contact {
    string name;
    int number;
public:
    Contact() : name(""), number(0) {}
    Contact(string name, int number) : name(name), number(number) {}

    void SetName(string name) {
        this->name = name;
    }
    string GetName() {
        return name;
    }
    void SetNumber(int number) {
        this->number = number;
    }
    int GetNumber() {
        return number;
    }
    void CreateContact() {
        cout << "enter name:" << endl;
        cin >> name;
        cout << "enter number:" << endl;
        cin >> number;
    }
    void Print() {
        cout << "name: " << name << endl << "number: " << number << endl << endl;
    }
};

void addNewContact(Contact*& arr, int& size) {
    Contact* arrContacts = new Contact[size + 1];
    for (int i = 0; i < size; i++) {
        arrContacts[i] = arr[i];
    }
    arrContacts[size].CreateContact();
    size++;
    delete[] arr;
    arr = arrContacts;
}

void PrintArray(Contact*& arr, int& size) {
    for (int i = 0; i < size; i++) {
        arr[i].Print();
    }
}

void searchContact(Contact*& arr, int& size) {
    string searchName;
    cout << "Enter name to search: ";
    cin >> searchName;
    bool contactFound = false;
    for (int i = 0; i < size; i++) {
        string lowercaseName = arr[i].GetName();
        transform(lowercaseName.begin(), lowercaseName.end(), lowercaseName.begin(), ::tolower);
        if (lowercaseName.find(searchName) != string::npos || arr[i].GetName().find(searchName) != string::npos) {
            arr[i].Print();
            contactFound = true;
        }
    }
    if (!contactFound) {
        cout << "No contact found" << endl;
    }
}

int main() {
    int SIZE = 5;
    Contact* arrContacts = new Contact[5]{
        Contact("Kate", 3439),
        Contact("Jonh", 4362),
        Contact("Peter Paka", 2354),
        Contact("Mom", 3533),
        Contact("Dad", 5664),
    };

    while (true) {
        cout << "Select action: " << endl
            << "1 - Create new contact" << endl
            << "2 - Search contact" << endl
            << "3 - Show all contacts" << endl;
        short select;
        cin >> select;

        switch (select) {
        case 1:
            addNewContact(arrContacts, SIZE);
            break;
        case 2:
            searchContact(arrContacts, SIZE);
            break;
        case 3:
            PrintArray(arrContacts, SIZE);
            break;
        default:
            cout << "Select correct action" << endl;
            break;
        }
        cin.get();
    }

    return 0;
}