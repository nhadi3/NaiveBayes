#ifndef NUMBER_H
#define NUMBER_H

#pragma once
#include <string>
#include <vector>

const int kImageDimension = 28;

using std::string;

class Number {
	std::vector<std::vector<int>> number_array_;
	string digit_;
public:
	std::vector<std::vector<char>> FileTo2DArray(string file);

};

#endif NUMBER_H