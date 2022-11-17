#include "GetList.h"


Book* GetListofBooksByGivenAuthor(Book* array, int size, std::string author, int& endSize)
{
	Book* tmp_list = new Book[size];
	endSize = 0;
	for (int i = 0; i < size; i++)
		if (array[i].GetAuthor() == author)
		{
			tmp_list[endSize] = array[i];
			endSize++;
		}
	Book* endList = new Book[endSize];
	for (int i = 0; i < endSize; i++)
		endList[i] = tmp_list[i];

	return endList;
}

Book* GetListOfBooksPublisherByGivenPublisher(Book* array, int size, std::string publisher, int& endSize)
{
	Book* tmp_list = new Book[size];
	endSize = 0;
	for (int i = 0; i < size; i++)
		if (array[i].GetPublisher() == publisher)
		{
			tmp_list[endSize] = array[i];
			endSize++;
		}
	Book* endList = new Book[endSize];
	for (int i = 0; i < endSize; i++)
		endList[i] = tmp_list[i];

	return endList;
}

Book* GetListOfBooksPublisherAfterGivenYear(Book* array, int size, int year, int& endSize)
{
	Book* tmp_list = new Book[size];
	endSize = 0;
	for (int i = 0; i < size; i++)
		if (array[i].GetYear() > year)
		{
			tmp_list[endSize] = array[i];
			endSize++;
		}
	Book* endList = new Book[endSize];
	for (int i = 0; i < endSize; i++)
		endList[i] = tmp_list[i];

	return endList;
}
