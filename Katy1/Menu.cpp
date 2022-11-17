#include "Menu.h"

int AscUserMenu()
{
	int variant;
	std::cout << "Для получения нажмите : " << std::endl
		<< " 1 списка квартир, имеющих заданное число комнат, ." << std::endl
		<< " 2 списка квартир, имеющих заданное число комнат и расположенных на этаже,"
		<< "который находится в определенном промежутке " << std::endl
		<< " 3 списка квартир, имеющих площадь, превосходящую заданную. " << std::endl;
	variant = 	CheckMenuItem(3);
	return variant;
}

int AscUserInputType()
{
	int variant;
	std::cout << "Enter 1 for manual input " << std::endl
		<< "Enter 2 for file input " << std::endl;
	variant = CheckMenuItem(2);
	return variant;
}

int AscOutputType()
{
	int variant;
	std::cout << "Enter 1 for console output " << std::endl
		<< "Enter 2 for file output " << std::endl;
	variant = CheckMenuItem(2);
	return variant;
}

int AscOutputMenu()
{
	int variant;
	std::cout << "Enter 1 for overwriting an existing file " << std::endl
		<< "Enter 2 for creating a new file" << std::endl;
	variant =  CheckMenuItem(2);
	return variant;
}

int AscInitialDataSaveMenu()
{
	int variant;
	std::cout << "1 - сохранить исходные данные" << std::endl
		<< "2 - продолжить без сохранения " << std::endl;
	variant = CheckMenuItem(2);
	return variant;
}
