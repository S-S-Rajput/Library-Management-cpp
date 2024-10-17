#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    int id;

public:
    Book(string t, string a, int i) : title(t), author(a), id(i) {}

    string getTitle() {
        return title;
    }

    string getAuthor() {
        return author;
    }

    int getId() {
        return id;
    }

    void displayBookInfo() {
        cout << "ID: " << id << " | Title: " << title << " | Author: " << author << endl;
    }
};

class Library {
private:
    vector<Book> books;

public:
    void addBook(Book book) {
        books.push_back(book);
    }

    void displayBooks() {
        for (Book book : books) {
            book.displayBookInfo();
        }
    }

    void searchBookByTitle(string title) {
        for (Book book : books) {
            if (book.getTitle() == title) {
                book.displayBookInfo();
                return;
            }
        }
        cout << "Book not found" << endl;
    }
};

int main() {
    Library library;
    library.addBook(Book("The Catcher in the Rye", "J.D. Salinger", 1));
    library.addBook(Book("To Kill a Mockingbird", "Harper Lee", 2));
    library.addBook(Book("1984", "George Orwell", 3));

    cout << "All Books in Library:" << endl;
    library.displayBooks();

    cout << "\nSearching for '1984':" << endl;
    library.searchBookByTitle("1984");

    return 0;
}
