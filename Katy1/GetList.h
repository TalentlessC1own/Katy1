#pragma once
#include "Book.h"

Book* GetListofBooksByGivenAuthor(Book* array, int size, std::string author, int& endSize);

Book* GetListOfBooksPublisherByGivenPublisher(Book* array, int size, std::string publisher, int& endSize);

Book* GetListOfBooksPublisherAfterGivenYear(Book* array, int size, int year, int& endSize);