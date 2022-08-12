// TestTaskBookCollection.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <unordered_map>
#include <functional>
#include "Book.h"

vector<Book> repo;


using namespace std;

void showBooksOfTheAuthor()
{
	string name = "";
	string surname = "";
	cout << "What author are you looking for?\n";
	cout << "Name: ";
	cin >> name;
	cout << "Surname: ";
	cin >> surname;
	for (int i = 0; i < repo.size(); i++)
	{
		if (repo[i]._authorName == name && repo[i]._authorSurname == surname)
		{
			cout << "Book nr. " << i << " on the list" << endl;
			cout << "Book name: " << repo[i]._bookName << "\nAuthor: " << repo[i]._authorName << " " << repo[i]._authorSurname << "\nBook genre: " << repo[i]._bookGenre << "\nyear of issue: " << repo[i]._yearOfIssue << "\npublisher name: " << repo[i]._publisherName << "\nnumber of pages: " << repo[i]._numberOfPages << endl;
		}
	}
	printf("\n");
}

void showBooksOfGivenGenreAndPublisher()
{
	string genre = "";
	string publisher = "";
	cout << "What is the genre and publisher that you are looking for?\n";
	cout << "genre: ";
	cin >> genre;
	cout << "publisher: ";
	cin >> publisher;

	for (int i = 0; i < repo.size(); i++)
	{
		if (repo[i]._bookGenre == genre && repo[i]._publisherName == publisher)
		{
			cout << "Book nr. " << i << " on the list" << endl;
			cout << "Book name: " << repo[i]._bookName << "\nAuthor: " << repo[i]._authorName << " " << repo[i]._authorSurname << "\nBook genre: " << repo[i]._bookGenre << "\nyear of issue: " << repo[i]._yearOfIssue << "\npublisher name: " << repo[i]._publisherName << "\nnumber of pages: " << repo[i]._numberOfPages << endl;
		}
	}
	printf("\n");

}

void showPublisherWithMostBooks()
{
	
	vector<string> v;

	for (int i = 0; i < repo.size(); i++)
	{
		v.push_back(repo[i]._publisherName);
	}

	auto h = [](const string* s) {
		return hash<string>()(*s);
	};

	auto eq = [](const string* s1, const string* s2) {
		return s1->compare(*s2) == 0;
	};

	unordered_map<const std::string*, size_t, decltype(h), decltype(eq)> m(v.size(), h, eq);

	for (auto v_i = v.cbegin(); v_i != v.cend(); ++v_i)
		++m[&(*v_i)];

	for (auto m_i = m.begin(); m_i != m.end(); ++m_i)
		if (m_i->second > 1)
			cout << "The most populat publisher is: " << *m_i->first << " with " << m_i->second << " books" << endl;
}

void showTop3() //I was not able to implement this functionality in time
{

}

void addBookToRepo(const Book& rhs)
{
	repo.push_back(rhs);
}

void addBook() {
	cout << "adding book\n";
	string bookName;
	cout << "Insert the name of the book: ";
	cin >> bookName;

	string authorName;
	cout << "Insert the name of the author: ";
	cin >> authorName;

	string authorSurname;
	cout << "Insert the surname of the author: ";
	cin >> authorSurname;

	string bookGenre;
	cout << "Insert the genre of the book: ";
	cin >> bookGenre;

	int yearOfIssue;
	cout << "Insert the year of the issue: ";
	cin >> yearOfIssue;

	string publisherName;
	cout << "Insert the name of the publisher: ";
	cin >> publisherName;

	int numberOfPages;
	cout << "Insert the number of pages: ";
	cin >> numberOfPages;

	Book book(bookName, authorName, authorSurname, bookGenre, yearOfIssue, publisherName, numberOfPages);
	addBookToRepo(book);
}

void deleteBook()
{
	int numberToDelete;
	cout << "Which position do you want to delete? Index starts from 0: ";
	cin >> numberToDelete;
	cout << "deleting book nr " << numberToDelete << ": " << repo[numberToDelete]._bookName;
	repo.erase(repo.begin()+numberToDelete);
}

void seeReports()
{
	int repoChoice;
	bool exitRepos = false;
	while (exitRepos == false)
	{
		cout << "What report do you want to see?\n1 - Show all books by the same author\n2 - Show all books of a given genre and publisher\n3 - Show the name of the publisher with the maximum quantity of the books\n4 - Show TOP-3 genres\n";
		cin >> repoChoice;
		switch (repoChoice)
		{
		case 1:
			exitRepos = true;
			showBooksOfTheAuthor();
			break;
		case 2:
			exitRepos = true;
			showBooksOfGivenGenreAndPublisher();
			break;
		case 3:
			exitRepos = true;
			showPublisherWithMostBooks();
			break;
		case 4:
			exitRepos = true;
			showTop3();
			break;
		default:
			exitRepos = false;
			cout << "Invalid choice\n";
			break;
		}
	}
}

int main()
{
    int actionChoice;
	bool exit = false;
	while (exit == false)
	{
		cout << "What do you want to do?\n1 - add a book\n2 - delete a book\n3 - see reports\n4 - leave program\n";
		cin >> actionChoice;
		switch (actionChoice)
		{
		case 1:
			exit = false;
			addBook();
			break;
		case 2:
			exit = false;
			deleteBook();
			break;
		case 3:
			exit = false;
			seeReports();
			break;
		case 4:
			exit = true;
			break;
		default:
			cout << "Invalid choice\n";
			break;
		}
	}
	
}
