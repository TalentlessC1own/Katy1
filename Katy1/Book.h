#pragma once
#include <iostream>
class Book
{
private:
	std::string author;
	std::string title;
	std::string publisher;
	int year;
	int numberOfPages;
public:
	Book() = default;
	Book(std::string authorValue, std::string titleValue, std::string publisherValue, int yearValue, int numberOfPagesValue)
		:author(authorValue), title(titleValue), publisher(publisherValue), year(yearValue), numberOfPages(numberOfPagesValue)
	{}

	std::string GetAuthor();

	std::string GetTitle();

	std::string GetPublisher();

	int GetYear();

	int GetNUmberOfPages();

	bool operator == (const Book& other);
	bool operator!=(const Book& other);
		
};

