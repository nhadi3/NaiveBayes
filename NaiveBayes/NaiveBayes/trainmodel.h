#ifndef TRAINDATA_H
#define TRAINDATA_H

#include "number.h"

#pragma once

const int kNumberOfTrainingLabels = 5000;

std::vector<std::vector<std::vector<int>>> FileTo2DArray(string file);
std::vector<char> LabelsTo2DArray(string file);


#endif TRAINDATA_H