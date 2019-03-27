#ifndef MODEL_H
#define MODEL_H

#include "trainmodel.h"

#pragma once
#include <string>
#include <vector>
#include <fstream>

using std::string;

class Model {
	std::vector<double> classprobability_;
	std::vector<std::vector<std::vector<double>>> whitepixelprobability_;
	std::vector<std::vector<std::vector<double>>> blackpixelprobability_;
public:
	void SetClassProb(std::vector<double> prob);
	std::vector<double> GetClassProb();
	void SetWhitePixelProb(std::vector<std::vector<std::vector<double>>> prob);
	std::vector<std::vector<std::vector<double>>> GetWhitePixelProb();
	void SetBlackPixelProb(std::vector<std::vector<std::vector<double>>> prob);
	std::vector<std::vector<std::vector<double>>> GetBlackPixelProb();
	void InitializeModelAndWriteToFile(string file, string newfile);
};

#endif MODEL_H