// File: library_system.cpp

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Book
{
private:
    int bookID;
    char title[50], author[50], genre[30], status[20];

public:
    void input()
    {
        cout << "Enter Book ID: ";
        cin >> bookID;
        cin.ignore();

        cout << "Enter Title: ";
        cin.getline(title, 50);

        cout << "Enter Author: ";
        cin.getline(author, 50);

        cout << "Enter Genre: ";
        cin.getline(genre, 30);

        cout << "Enter Status (Available/Issued): ";
        cin.getline(status, 20);
    }

    void display()
    {
        cout << "Book ID: " << bookID
             << "\nTitle: " << title
             << "\nAuthor: " << author
             << "\nGenre: " << genre
             << "\nStatus: " << status << endl;
    }

    int getbookid()
    {
        return bookID;
    }
};

void addBook()
{
    Book b;
    ofstream file("books.dat", ios::binary | ios::app);

    b.input();
    file.write((char*)&b, sizeof(b));
    file.close();

    cout << "Book added successfully!\n";
}

void displayAll()
{
    Book b;
    ifstream file("books.dat", ios::binary);

    cout << "----- Book Records -----\n";

    while(file.read((char*)&b, sizeof(b)))
    {
        b.display();
        cout << "------------------------\n";
    }

    file.close();
}

void searchBook()
{
    Book b;
    ifstream file("books.dat", ios::binary);

    int id;
    bool found = false;

    cout << "Enter Book ID to search: ";
    cin >> id;

    while(file.read((char*)&b, sizeof(b)))
    {
        if(b.getbookid() == id)
        {
            cout << "Book Found:\n";
            b.display();
            found = true;
            break;
        }
    }

    if(!found)
        cout << "Book not found!\n";

    file.close();
}

void deleteBook()
{
    Book b;
    ifstream file("books.dat", ios::binary);
    ofstream temp("temp.dat", ios::binary);

    int id;
    bool found = false;

    cout << "Enter Book ID to delete: ";
    cin >> id;

    while(file.read((char*)&b, sizeof(b)))
    {
        if(b.getbookid() != id)
            temp.write((char*)&b, sizeof(b));
        else
            found = true;
    }

    file.close();
    temp.close();

    remove("books.dat");
    rename("temp.dat", "books.dat");

    if(found)
        cout << "Book deleted successfully!\n";
    else
        cout << "Book not found!\n";
}

void updateBook()
{
    Book b;

    fstream file("books.dat",
                 ios::binary | ios::in | ios::out);

    int id;
    bool found = false;

    cout << "Enter Book ID to update: ";
    cin >> id;

    while(file.read((char*)&b, sizeof(b)))
    {
        if(b.getbookid() == id)
        {
            cout << "Enter new details:\n";

            b.input();

            file.seekp(-sizeof(b), ios::cur);
            file.write((char*)&b, sizeof(b));

            found = true;
            break;
        }
    }

    if(found)
        cout << "Book updated successfully!\n";
    else
        cout << "Book not found!\n";

    file.close();
}

int main()
{
    int choice;

    do
    {
        cout << "===== Library Management System =====\n";
        cout << "1. Add Book\n";
        cout << "2. Display All Books\n";
        cout << "3. Search Book\n";
        cout << "4. Delete Book\n";
        cout << "5. Update Book\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";

        cin >> choice;

        switch(choice)
        {
            case 1: addBook(); break;
            case 2: displayAll(); break;
            case 3: searchBook(); break;
            case 4: deleteBook(); break;
            case 5: updateBook(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while(choice != 6);

    return 0;
}