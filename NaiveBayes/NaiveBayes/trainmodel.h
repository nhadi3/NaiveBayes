#ifndef TRAINDATA_H
#define TRAINDATA_H

#pragma once
#include <string>
#include <vector>

using std::string;

const int kNumberOfTrainingLabels = 5000;
const double kKConst = 0.1;
const int kImageDimension = 28;
const int kNumOfDigits = 10;
const int kWhitePixel = 0;
const int kBlackPixel = 1;

std::vector<std::vector<std::vector<int>>> TrainingImagesTo2DArray(string file);
std::vector<char> TrainingLabelsTo2DArray(string file);
std::vector<double> CalculateProbabilityForEachClass(string file);
std::vector<std::vector<std::vector<double>>> CalculateProbabilityForEachPixel(string file, int pixel);
std::vector<double> CountNumOfTimesDigitAppears(string file);

#endif TRAINDATA_H