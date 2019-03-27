#ifndef MODEL_H
#define MODEL_H

#include "trainmodel.h"

#pragma once
#include <string>
#include <vector>

using std::string;

class Model {
	std::vector<double> classprobability_;
	std::vector<std::vector<std::vector<double>>> pixelprobability_;
public:
	void SetClassProb(std::vector<double> prob);
	std::vector<double> GetClassProb();
	void SetPixelProb(std::vector<std::vector<std::vector<double>>> prob);
	std::vector<std::vector<std::vector<double>>> GetPixelProb();
};

#endif MODEL_H