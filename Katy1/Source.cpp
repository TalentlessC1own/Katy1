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

		ListType var = static_cast<ListType>(AscUserMenu());
		switch (var)
		{
		case ListType::ByAuthor:
			std::cout << "Введите автора:";
			std::cin >> wishAuthor;
			listType = "Книги " + wishAuthor + " \n";;
			endList = GetListofBooksByGivenAuthor(array, count, wishAuthor, endSize);
			break;

		case ListType::ByPublisher:
			std::cout << "ВВедите издание :";
			std::cin >> wishPublisher;
			

			listType = "Книги изданные  " + wishPublisher + " \n";;

			endList = GetListOfBooksPublisherByGivenPublisher(array, count, wishPublisher, endSize);
			break;

		case ListType::ByYear:
			std::cout << "Введите год:";
			wishYear = CheckIntValue();
			listType = "Книги изданные после " + std::to_string(wishYear) + " \n";
			endList = GetListOfBooksPublisherAfterGivenYear(array, count, wishYear, endSize);
			break;
		}

		InputType outputVar = static_cast<InputType> (AscOutputType());

		switch (outputVar)
		{
		case InputType::Console:
			ConsoleOutput(array,listType, endSize);
			break;
		case InputType::File:
			FileOutput(array,listType, endSize);
			break;
		}

		delete[] array;
		delete[] endList;
		std::cout << "Завершить программу 1 - да 2 - нет " << std::endl;
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

