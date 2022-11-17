#pragma once
#include <iostream>
#include <fstream>
#include <string>

int CheckIntValue();

double CheckDoubleValue();

int CheckMenuItem(int numberOfPoints);

std::string CheckLineString(std::ifstream& file);

int CheckLineInt(std::ifstream& file);

 double CheckLineDouble(std::ifstream& file);


