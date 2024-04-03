
#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

class Book {
private:
    string author;
    int year;

public:

    Book(string author, int year) : author(author), year(year) {}
    string getAuthor() const {
        return author;
    }
    int getYear() const {
        return year;
    }
};

void sortLibraryByYear(vector<Book>& library) {
    int n = library.size();
    for (int i = 0; i < n - 1; ++i) {
    for (int j = 0;j < n - i - 1; ++j) {
    if (library[j].getYear() > library[j + 1].getYear()) {
    swap(library[j], library[j + 1]);
       }
      }
     }
    }

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<Book> library;

    library.push_back(Book("Гаррі Поттер і філософський камінь", 1997));
    library.push_back(Book("Гаррі Поттер і Таємна кімната", 1998));
    library.push_back(Book("Гаррі Поттер і в'язень Азкабану", 1999));
    library.push_back(Book("Гаррі Поттер і Келих вогню", 2000));
    library.push_back(Book("Гаррі Поттер і Напівкровний Принц", 2005));
    library.push_back(Book("Гаррі Поттер і Смертельні реліквії", 2007));
    library.push_back(Book("Гаррі Поттер і Орден Фенікса", 2003));

    sortLibraryByYear(library);

    cout << "Бібліотека впорядкована за роками видання:\n";
    for (const auto& book : library) {
        cout << "Назва книги: " << book.getAuthor() << ", Рік: " << book.getYear() << endl;
    }
    return 0;
}
