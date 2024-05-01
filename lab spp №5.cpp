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
    string workplace; // ������ ���� ��� ���� ������
    string position; // ������ ���� ��� ������

public:
    Contact(string s, string n, string f, string a, string p, string w, string pos)
        : surname(s), name(n), fatherName(f), address(a), phone(p), workplace(w), position(pos) {}

    void displayInfo() const {
        cout << "Surname: " << surname << endl;
        cout << "Name: " << name << endl;
        cout << "Father's name: " << fatherName << endl;
        cout << "Address: " << address << endl;
        cout << "Phone: " << phone << endl;
        cout << "Workplace: " << workplace << endl; // ������ ��������� ���� ������
        cout << "Position: " << position << endl; // ������ ��������� ������
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
        cout << "����:" << endl;
        cout << "1. ������ �������" << endl;
        cout << "2. �������� �������" << endl;
        cout << "3. ������� �� ��������" << endl;
        cout << "4. �����" << endl;
        cout << "������ ��� ����: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            string surname, name, fatherName, address, phone, workplace, position;
            cout << "������ �������: ";
            cin >> surname;
            cout << "������ ��'�: ";
            cin >> name;
            cout << "������ ��'� �� �������: ";
            cin >> fatherName;
            cout << "������ ������: ";
            cin >> address;
            cout << "������ ����� ���������: ";
            cin >> phone;
            cout << "������ ���� ������: ";
            cin >> workplace;
            cout << "������ ������: ";
            cin >> position;
            database.addContact(Contact(surname, name, fatherName, address, phone, workplace, position));
            break;
        }
        case 2: {
            string surname, phone;
            cout << "������ ������� �������� ��� ���������: ";
            cin >> surname;
            cout << "������ ����� �������� ��� ���������: ";
            cin >> phone;
            database.deleteContact(surname, phone);
            break;
        }
        case 3: {
            database.displayAllContacts();
            break;
        }
        case 4: {
            cout << "����� � ��������..." << endl;
            break;
        }
        default: {
            cout << "�������� ����! ������ ���������� ��������." << endl;
            break;
        }
        }
    } while (choice != 4);

    return 0;
}
