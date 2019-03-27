#ifndef CLASSIFY_H
#define CLASSIFY_H

#include <math.h>

#pragma once
#include "model.h"

const int kNumOfTestImages = 1000;

std::vector<int> ClassifyImages(string file, string newfile);
std::vector<std::vector<double>> ProbabilitiesForImages();
std::vector<std::vector<std::vector<int>>> ImagesToClassifyTo2DArray(string file);

#endif CLASSIFY_H
