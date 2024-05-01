#include <iostream>
#include <vector>
#include <string>
#include <windows.h>

using namespace std;

class Contact {
private:
    string surname;
    string name;
    string fatherName;
    string address;
    string phone;
    string workplace; // Додано поле для місця роботи
    string position; // Додано поле для посади

public:
    Contact(string s, string n, string f, string a, string p, string w, string pos)
        : surname(s), name(n), fatherName(f), address(a), phone(p), workplace(w), position(pos) {}

    void displayInfo() const {
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Father's name: " << fatherName << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Workplace: " << workplace << endl; // Додано виведення місця роботи
        cout << "Position: " << position << endl; // Додано виведення посади
    }

    const string& getSurname() const {
        return surname;
    }

    const string& getPhone() const {
        return phone;
    }
};

class ContactDatabase {
private:
    vector<Contact> contacts;

public:
    void addContact(const Contact& newContact) {
        contacts.push_back(newContact);
    }

    void deleteContact(const string& surnameToDelete, const string& phoneToDelete) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->getSurname() == surnameToDelete && it->getPhone() == phoneToDelete) {
                contacts.erase(it);
                break;
            }
        }
    }

    void displayAllContacts() const {
        for (const auto& contact : contacts) {
            contact.displayInfo();
            cout << endl;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    ContactDatabase database;

    int choice;
    do {
        cout << "Меню:" << endl;
        cout << "1. Додати контакт" << endl;
        cout << "2. Видалити контакт" << endl;
        cout << "3. Вивести всі контакти" << endl;
        cout << "4. Вихід" << endl;
        cout << "Введіть свій вибір: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string surname, name, fatherName, address, phone, workplace, position;
            cout << "Введіть прізвище: ";
            cin >> surname;
            cout << "Введіть ім'я: ";
            cin >> name;
            cout << "Введіть ім'я по батькові: ";
            cin >> fatherName;
            cout << "Введіть адресу: ";
            cin >> address;
            cout << "Введіть номер мобільного: ";
            cin >> phone;
            cout << "Введіть місце роботи: ";
            cin >> workplace;
            cout << "Введіть посаду: ";
            cin >> position;
            database.addContact(Contact(surname, name, fatherName, address, phone, workplace, position));
            break;
        }
        case 2: {
            string surname, phone;
            cout << "Введіть прізвище контакта для видалення: ";
            cin >> surname;
            cout << "Введіть номер контакта для видалення: ";
            cin >> phone;
            database.deleteContact(surname, phone);
            break;
        }
        case 3: {
            database.displayAllContacts();
            break;
        }
        case 4: {
            cout << "Вихід з програми..." << endl;
            break;
        }
        default: {
            cout << "Недійсний вибір! Введіть правильний параметр." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}
