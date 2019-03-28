#ifndef EVALUATE_H
#define EVALUATE_H

#include "classify.h"

#pragma once

double EvaluatePercentageOfCorrectClassifications(string file);
std::vector<char> TestLabelsTo2DArray(string file);
std::vector<std::vector<double>> CreateConfusionMatrix(string file);
std::vector<double> CountNumOfDigitAppearances(string file);

#endif EVALUATE_H