#ifndef TRAINDATA_H
#define TRAINDATA_H

#include "number.h"

#pragma once

const int kNumberOfTrainingLabels = 5000;

std::vector<std::vector<std::vector<int>>> TrainingImagesTo2DArray(string file);
std::vector<char> TrainingLabelsTo2DArray(string file);
std::vector<double> CalculateProbabilityForEachClass(string file);


#endif TRAINDATA_H