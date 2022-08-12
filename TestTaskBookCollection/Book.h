#pragma once
#include <string>

using namespace std;

class Book
{
public:
	string _bookName = "";
	string _authorName = "";
	string _authorSurname = "";
	string _bookGenre = "";
	int _yearOfIssue = 0;
	string _publisherName = "";
	int _numberOfPages = 0;


	Book(const string& bookName, const string& authorName, const string& authorSurname, const string& bookGenre, const int yearOfIssue, const string& publisherName, const int numberOfPages);

};

