#include "Book.h"

std::string Book::GetAuthor()
{
	return author;
}

std::string Book::GetTitle()
{
	return title;
}

std::string Book::GetPublisher()
{
	return publisher;
}

int Book::GetYear()
{
	return year;
}

int Book::GetNUmberOfPages()
{
	return numberOfPages;
}

bool Book::operator==(const Book& other)
{
	return author == other.author && title == other.title && publisher == other.publisher && year == other.year && numberOfPages == other.numberOfPages;
}

bool Book::operator!=(const Book& other)
{
	return !(*this == other);
}
