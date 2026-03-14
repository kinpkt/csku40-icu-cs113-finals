#include <iostream>
#include <vector>

using namespace std;

class Book
{
    private:
        string title;
        string author;
        string isbn;

    public:
        Book(string title, string author, string isbn)
        {
            this->title = title;
            this->author = author;
            this->isbn = isbn;
        }

        string getTitle()
        {
            return title;
        }

        string getAuthor()
        {
            return author;
        }

        string getIsbn()
        {
            return isbn;
        }
};

class User
{
    // ใช้ protected แทน private เพื่อให้ subclass เข้าถึงค่าได้โดยตรง
    protected:
        string username;
        string displayName;
    public:
        User(string username, string displayName)
        {
            this->username = username;
            this->displayName = displayName;
        }

        string getUsername()
        {
            return username;
        }

        string getDisplayName()
        {
            return displayName;
        }

        void chat()
        {
            cout << "@" << username << ": Hi! My name is " << displayName << ". I am a user." << endl;
        }
};

class Student : public User
{
    private:
        string institute;
        vector<Book> books;
    public:
        Student(string username, string displayName, string institute) : User(username, displayName)
        {
            this->institute = institute;
            this->books = vector<Book>();
        }

        string getInstitute()
        {
            return institute;
        }

        const vector<Book>& getBooks() const
        {
            return books;
        }

        void addBook(Book book)
        {
            books.push_back(book);
        }

        void chat()
        {
            User::chat(); // Superclass::function() แทนการเรียกฟังก์ชันของ superclass
            cout << displayName << "'s Book List" << endl;

            if (books.empty())
                cout << "\t- No books yet." << endl;

            for (auto &book : books)
                cout << "\t- " << book.getTitle()<< " by " << book.getAuthor() << " (" << book.getIsbn() << ")" << endl;
        }
};

int main()
{
    User normalUser = User("user1", "First User");
    Student studentUser = Student("student1", "First Student", "Kasetsart University");

    normalUser.chat();

    cout << endl;

    studentUser.chat();

    studentUser.addBook(Book("Design Patterns", "Gang of Four", "1212312121"));
    studentUser.addBook(Book("Python 101", "Guido van Rossum", "1234567890"));
    studentUser.addBook(Book("Mastering C++", "Bjarne Stroustrup", "01418113"));

    studentUser.chat();

    return 0;
}
