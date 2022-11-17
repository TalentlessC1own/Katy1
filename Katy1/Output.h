#pragma once
#include "Book.h"
#include <iostream>
#include <string>
#include <fstream>
#include "CheckFile.h"
void FileOutput(Book* array, std::string var, int endSize);
void ConsoleOutput(Book* array, std::string var, int endSize);
void InitialFileOutput(Book* array, int size);
