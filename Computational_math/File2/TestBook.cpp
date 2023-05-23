#include "Book.hpp"

int main(int argc, char * argv[])
{
    Book my_book;
    my_book.author = "Stanley";
    my_book.title = "C++";
    my_book.publisher = "JVX";
    my_book.format = "pdf";
    my_book.price = 0;
    my_book.Pubyear = 2023;
    
    cout<< "Year of publication of "
        << my_book.title << " is "
        << my_book.Pubyear << endl;
    
}
