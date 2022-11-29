#include "Book.h"
#include"Menu.h"
#include "Input.h"
#include "Output.h"
#include "GetList.h"


enum class InputType
{
	Console = 1,
	File
};


enum class ListType
{
	ByAuthor = 1,
	ByPublisher,
	ByYear
};

enum class Answer
{
	Yes = 1,
	No
};


int main()
{
	const int yes = 1;
	setlocale(LC_ALL, "Russian");
	std::cout << "K 415 kr 1" << std::endl;
	while (true)
	{

		Book* array = nullptr;
		int count = 0;

		InputType inputVar = static_cast<InputType>(AscUserInputType());

		switch (inputVar)
		{
		case InputType::Console:
			std::cout << "Enter books count. " << std::endl;
			count = CheckIntValue();
			array = ConsoleInput(count);
			break;


		case InputType::File:
			array = FileInput();
			std::cin.clear();
			std::cin.ignore(30000, '\n');
			break;
		}

		if (inputVar == InputType::Console)
		{
			Answer initialDataVar = static_cast<Answer> (AscInitialDataSaveMenu());
			if (initialDataVar == Answer::Yes)
				InitialFileOutput(array, count);
		}


		Book* endList = nullptr;
		int endSize = 0;

		std::string wishAuthor;
		std::string wishPublisher;
		int wishYear = 0;
		std::string listType;

		while (true)
		{
			ListType var = static_cast<ListType>(AscUserMenu());
			switch (var)
			{
			case ListType::ByAuthor:
				std::cout << "������� ������:";
				std::getline(std::cin, wishAuthor);
				listType = "����� " + wishAuthor + " \n";;
				endList = GetListofBooksByGivenAuthor(array, count, wishAuthor, endSize);
				break;

			case ListType::ByPublisher:
				std::cout << "������� ������� :";
				std::getline(std::cin, wishPublisher);


				listType = "����� ��������  " + wishPublisher + " \n";;

				endList = GetListOfBooksPublisherByGivenPublisher(array, count, wishPublisher, endSize);
				break;

			case ListType::ByYear:
				std::cout << "������� ���.\n";
				wishYear = CheckIntValue();
				listType = "����� �������� ����� " + std::to_string(wishYear) + " \n";
				endList = GetListOfBooksPublisherAfterGivenYear(array, count, wishYear, endSize);
				break;
			}


			InputType outputVar = static_cast<InputType> (AscOutputType());


			switch (outputVar)
			{
			case InputType::Console:
				ConsoleOutput(array, listType, endSize);
				break;
			case InputType::File:
				FileOutput(array, listType, endSize);
				break;
			}
			int varList = 0;
			std::cout << "������ �������� ������ ������?\n1 - ��\n2 - ���  " << std::endl;
			varList = CheckMenuItem(2);
			if (varList != yes)
			{
				break;
			}

		}
		delete[] array;
		delete[] endList;
		std::cout << "��������� ��������� 1 - �� 2 - ��� " << std::endl;
		Answer exitVar = static_cast<Answer>(CheckIntValue());
		switch (exitVar)
		{
		case Answer::Yes:
			return 0;
			
		case Answer::No:
			continue;
		
		}
	}
}

