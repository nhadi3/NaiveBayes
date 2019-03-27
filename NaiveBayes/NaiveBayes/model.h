#ifndef MODEL_H
#define MODEL_H

#include "trainmodel.h"

#pragma once
#include <string>
#include <vector>

using std::string;

class Model {
	std::vector<char> classprobability[10];
	double pixelprobability[28][28][10];
	int label_;
public:
	void SetClassProb(double array[]);

};

#endif MODEL_H