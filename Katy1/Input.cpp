#include "Input.h"

Book* ConsoleInput(int count)
{
	std::string valuerAuthor;
	std::string valueTitle;
	std::string valuePublisher;
	int valueYear;
	int valueNumberOfPages;
	Book* array = new Book[count];

    for (int i = 0; i < count; i++)
    {
        std::cout << "Enter author(#" + std::to_string(i+1) + ")." << std::endl << "ENTER: ";
        std::cin >> valuerAuthor;

        std::cout << "Enter title(#" + std::to_string(i + 1) + ")." << std::endl;
		std::cin >> valueTitle;

        std::cout << "Enter publisher(#" + std::to_string(i + 1) + ")." << std::endl;
		std::cin >> valuePublisher;

        std::cout << "Enter year(#" + std::to_string(i + 1) + ")." << std::endl;
		valueYear = CheckIntValue();

		std::cout << "Enter number of pages(#" + std::to_string(i + 1) + ")." << std::endl;
		valueNumberOfPages = CheckIntValue();

        std::cout << "Correct data entered(#" << i + 1 << ")!" << std::endl;

		array[i] = Book(valuerAuthor, valueTitle, valuePublisher, valueYear, valueNumberOfPages);
    }
	return array;
}

Book* FileInput()
{
	std::string fileName = "";	
	std::ifstream file;
	int count = 0;

	file.exceptions(std::ifstream::badbit | std::ifstream::failbit);
	while (true)
	{
		std::cout << "Enter file name. " << std::endl << "ENTER : ";
		std::cin >> fileName;
		try
		{
			file.open(fileName);
			std::cout << "Sucefull file open " << std::endl;
		}
		catch (const std::exception)
		{
			std::cout <<  "Eror.Try again ." << std::endl;
			continue;

		}

		std::string valuerAuthor;
		std::string valueTitle;
		std::string valuePublisher;
		int valueYear;
		int valueNumberOfPages;;
		Book* array;

		try
		{
			count = CheckLineInt(file);
			array = new Book[count];
			for (int i = 0; i < count; i++)
			{
				valuerAuthor = CheckLineString(file);
				valueTitle = CheckLineString(file);;
				valuePublisher = CheckLineString(file);;
				valueYear = CheckLineInt(file);
				valueNumberOfPages = CheckLineInt(file);
				
				array[i] = Book(valuerAuthor, valueTitle, valuePublisher, valueYear, valueNumberOfPages);

			}
		}
		catch (std::invalid_argument iaex)
		{
			file.close();
			continue;
		}

		file.close();
		return array;

	}
}

