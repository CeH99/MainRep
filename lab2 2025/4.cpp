#include <iostream>
#include <string>

using namespace std;

class card{
    private:
        string bookname;
        string author;
        int amount_of_books;
    public:
        void store(string title, string nameofauthor, int copies)
        {
            bookname = title;
            author = nameofauthor;
            amount_of_books = copies;
        }

        void show()
        {
            cout << "Name of the book - " << bookname << endl;
            cout << "Author of the book is - " << author << endl;
            cout << "Amount of books is - " << amount_of_books << endl << endl << endl;
        }

};

int main()
{
    card first, second, third;

    first.store("Harry Potter", "J.Roaling", 2000);
    second.store("Game of Thrones","George R. R. Martin", 3000);
    third.store("Mikky Mouse", "Disney", 1000 );

    first.show();
    second.show();
    third.show();

    return 0;
}