#include "Book.h"



Book::Book(const string& bookName, const string& authorName, const string& authorSurname, const string& bookGenre, const int yearOfIssue, const string& publisherName, const int numberOfPages) : _bookName(bookName), _authorName(authorName), _authorSurname(authorSurname), _bookGenre(bookGenre), _yearOfIssue(yearOfIssue), _publisherName(publisherName), _numberOfPages(numberOfPages)
{
}
