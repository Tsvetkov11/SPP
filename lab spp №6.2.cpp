#include <iostream>
#include <cstring>

using namespace std;

class MyString {
private:
    char* str;

public:
    // ����������� �� �������������
    MyString() : str(new char[1]) {
        str[0] = '\0';
    }

    // ����������� � �����������
    MyString(const char* s) {
        if (s) {
            str = new char[strlen(s) + 1];
            strcpy(str, s);
        }
        else {
            str = new char[1];
            str[0] = '\0';
        }
    }

    // ����������� ���������
    MyString(const MyString& other) {
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
    }

    // ����������
    ~MyString() {
        delete[] str;
    }

    // �������� ������������
    MyString& operator=(const MyString& other) {
        if (this == &other) {
            return *this;
        }
        delete[] str;
        str = new char[strlen(other.str) + 1];
        strcpy(str, other.str);
        return *this;
    }

    // �������� ��'������� �����
    MyString operator+(const MyString& other) const {
        char* combinedStr = new char[strlen(str) + strlen(other.str) + 1];
        strcpy(combinedStr, str);
        strcat(combinedStr, other.str);
        MyString newString(combinedStr);
        delete[] combinedStr;
        return newString;
    }

    // �������� ��������� ����� (�� ������)
    bool operator==(const MyString& other) const {
        return strcmp(str, other.str) == 0;
    }

    // �������� ��������� ����� (�� ������)
    bool operator!=(const MyString& other) const {
        return !(*this == other);
    }

    // ��������� �����
    friend ostream& operator<<(ostream& os, const MyString& myString) {
        os << myString.str;
        return os;
    }
};

int main() {
    MyString s1("Hello");
    MyString s2("World");
    MyString s3 = s1 + s2;

    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << "s3: " << s3 << endl;

    MyString s4 = s1;
    cout << "s4 (copy of s1): " << s4 << endl;

    if (s1 == s4) {
        cout << "s1 is equal to s4" << endl;
    }
    else {
        cout << "s1 is not equal to s4" << endl;
    }

    return 0;
}
