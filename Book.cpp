//Book.cpp
//Author: Sian McClean (Shane's Notes)
//Date: 22/11/2018
//Description: Continuing on with the pointers tutorial - Pointers to objects


#include <iostream>
#include <string>

using namespace std;

class Book {

private: 

	std::string title_;
	std::string author_;
	std::string publisher_;
	std::string isbn13_;
	float price_;

public:

	Book() {}

	Book(std::string title, std::string author, std::string publisher, std::string isbn13, float price) : title_{ title }, author_{ author }, publisher_{ publisher }, isbn13_{ isbn13 }, price_{price} {}

	std::string GetTitle() { return title_; };

};

int main() {

	Book myBook{ "Catch-22", "Joseph Heller", "Vintage Classics", "978-0099529125", 6.49f };

	cout << "The name of my favourite book is: " << myBook.GetTitle() << endl;

	Book* myBookPtr{ nullptr };
	myBookPtr = &myBook;

	cout << "The name of my favourite book is: " << myBookPtr->GetTitle() << "also!"<< endl; //when we use a pointer we dont use the . access operator like myBook.GetTitle() 
	// we use a - and > to make and arrow ->



	return 0;

}