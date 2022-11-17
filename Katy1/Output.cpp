#include "Output.h"

void FileOutput(Book* array, std::string var, int endSize)
{
	std::ofstream fileRecorder = CheckFileOutput();

	fileRecorder << var << std::endl;

	for (int i = 0; i < endSize; i++)
	{
		fileRecorder << "Book #" << i + 1 << std::endl;

		fileRecorder << "Author is " + array[i].GetAuthor() << std::endl;

		fileRecorder << "Title is " + array[i].GetTitle() << std::endl;

		fileRecorder << "Publisher is " + array[i].GetPublisher() << std::endl;

		fileRecorder << "Year is " + std::to_string(array[i].GetYear()) + "\n" << std::endl;

		fileRecorder << "Number of Pages is is " + std::to_string(array[i].GetNUmberOfPages()) + "\n" << std::endl;
	}

	std::cout << "File saved successfully!!!" << std::endl;;
	
	fileRecorder.close();
}


void InitialFileOutput(Book* array, int size )
{
	std::ofstream fileRecorder = CheckFileOutput();
	fileRecorder << size << std::endl;
	for (int i = 0; i < size; i++)
	{
		fileRecorder << array[i].GetAuthor() << std::endl;
		fileRecorder << array[i].GetTitle() << std::endl;
		fileRecorder << array[i].GetPublisher() << std::endl;
		fileRecorder << array[i].GetYear() << std::endl;
		fileRecorder << array[i].GetNUmberOfPages() << std::endl;

	}
}

void ConsoleOutput(Book* array, std::string var, int endSize)
{

	std::cout << var;
	for (int i = 0; i < endSize; i++)
	{
		std::cout << "Book #" << i + 1 << std::endl;

		std::cout << "Author is " + array[i].GetAuthor() << std::endl;

		std::cout << "Title is " + array[i].GetTitle() << std::endl;

		std::cout << "Publisher is " + array[i].GetPublisher() << std::endl;

		std::cout << "Year is " + std::to_string(array[i].GetYear()) + "\n" << std::endl;

		std::cout << "Number of Pages is is " + std::to_string(array[i].GetNUmberOfPages()) + "\n" << std::endl;
	}
}
