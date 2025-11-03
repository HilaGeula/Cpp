#include <iostream>
#include <cstring>
#include <stdexcept>

class LibraryFullException : public std::runtime_error {
public:
    LibraryFullException() : std::runtime_error("Library is at full capacity!") {}
};

class BookNotFoundException : public std::runtime_error {
public:
    BookNotFoundException() : std::runtime_error("Book not found!") {}
};

class BookUnavailableException : public std::runtime_error {
public:
    BookUnavailableException() : std::runtime_error("Book is already borrowed or not available!") {}
};

class Book {
    private:
    char* title;
    int year;
    bool isAvailable;

    public:
    char* getTitle() { return title; }
    int getYear() { return year; }

    void setTitle(const char* title) { 
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }
    void setYear(int year) { 
        this->year = year;
    }

    Book(const char* title, int year) 
        : year(year), isAvailable(true) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    Book() : year(2000), isAvailable(true) {
        this->title = new char[strlen(title) + 1];
        strcpy(this->title, title);
    }

    ~Book() {
        delete[] title;
    }

    void display() const {
        std::cout << "Title: " << title
                  << ", Year: " << year
                  << ", Available: " << (isAvailable ? "Yes" : "No") << std::endl;
    }

    void borrow() {
        if (!isAvailable) throw BookUnavailableException();
        isAvailable = false;
    }

    void returnBook() {
        if (isAvailable) throw BookUnavailableException();
        isAvailable = true;
    }
};

class Library{
    private: 
    Book** books;
    int maxBooks;
    int numOfBooks;

    public:
    Library(int maxBooks = 11) : maxBooks(maxBooks), numOfBooks(0) 
    {
        books = new Book*[maxBooks];
    }

    ~Library() {
        for (int i = 0; i < numOfBooks; i++) {
            delete books[i];
        }
        delete[] books;
    }

    void Add(Book* b){
         if (numOfBooks >= maxBooks) throw LibraryFullException();
        books[numOfBooks]=b;
        numOfBooks++;
    }

    void Print(){
        for(int i = 0; i < numOfBooks; i++)
        {
            books[i]->display();
        }
    }

    Book* Find(const char* t){
        for(int i = 0; i < numOfBooks; i++)
        {
            if(strcmp(books[i]->getTitle(),t)==0)
                return books[i];
        }
        throw BookNotFoundException();
    }

};

int main()
{Library library;

    Book* book1 = new Book("1984", 1949);
    Book* book2 = new Book("Brave New World", 1932);

    library.Add(book1);
    library.Add(book2);

    library.Print();

    try {
        Book* foundBook = library.Find("1984");
        foundBook->borrow();
        std::cout << "Borrowed: " << foundBook->getTitle() << std::endl;
    } catch (const BookNotFoundException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const BookUnavailableException& e) {
        std::cerr << e.what() << std::endl;
    } catch (const LibraryFullException& e) {
        std::cerr << e.what() << std::endl;
    }

    library.Print();


    return 0;
}