#include "trainmodel.h"

#include<iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<std::vector<double>>> CalculateProbabilityForEachPixel(string file, int pixel) {
	std::vector<std::vector<std::vector<double>>> probability_vector(kImageDimension, std::vector<std::vector<double>>(kImageDimension, std::vector<double>(kNumOfDigits)));
	std::vector<double> digit_vector(kNumOfDigits);
	std::vector<char> labels(kNumberOfTrainingLabels);
	std::vector<std::vector<std::vector<int>>> image_vector(kNumberOfTrainingLabels, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	digit_vector = CountNumOfTimesDigitAppears("traininglabels");
	labels = TrainingLabelsTo2DArray("traininglabels");
	image_vector = TrainingImagesTo2DArray(file);
	double tempixelcount = 0;
	for (int a = 0; a < kNumOfDigits; a++) {
		for (int i = 0; i < kImageDimension; i++) {
			for (int j = 0; j < kImageDimension; j++) {
				for (int k = 0; k < kNumberOfTrainingLabels; k++) {
					if ( labels[k] == (char) (a + '0')) {
						if (image_vector[k][i][j] == pixel) {
							tempixelcount++;
						}
					}
				}
				probability_vector[i][j][a] = (kKConst + tempixelcount) / (2 * kKConst + digit_vector[a]);
				tempixelcount = 0;
			}
		}
	}
	return probability_vector;
}

std::vector<double> CalculateProbabilityForEachClass(string file) {
	std::vector<double> probabilities(kNumOfDigits);
	std::vector<char> labels(kNumberOfTrainingLabels);
	labels = TrainingLabelsTo2DArray(file);
	double tempdigitcount = 0;
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kNumberOfTrainingLabels; j++) {
			if ( labels[j] == (char) (i + '0')) {
				tempdigitcount++;
			}
		}
		probabilities[i] = (tempdigitcount / kNumberOfTrainingLabels);
		tempdigitcount = 0;
	}
	return probabilities;
}

std::vector<double> CountNumOfTimesDigitAppears(string file) {
	std::vector<double> digit_array(kNumOfDigits);
	std::vector<char> labels(kNumberOfTrainingLabels);
	labels = TrainingLabelsTo2DArray(file);
	double tempdigitcount = 0;
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kNumberOfTrainingLabels; j++) {
			if (labels[j] == (char)(i + '0')) {
				tempdigitcount++;
			}
		}
		digit_array[i] = tempdigitcount;
		tempdigitcount = 0;
	}
	return digit_array;
}

std::vector<std::vector<std::vector<int>>> TrainingImagesTo2DArray(string file) {
	std::vector<std::vector<std::vector<int>>>number_vector(kNumberOfTrainingLabels, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	std::ifstream inFile;

	inFile.open(file);
	string temp;
	for (int i = 0; i < kNumberOfTrainingLabels; i++) {
		for (int j = 0; j < kImageDimension; j++) {
			getline(inFile, temp);
			for (int k = 0; k < kImageDimension; k++) {
				if (temp.at(k) == ' ') {
					number_vector[i][j][k] = kWhitePixel;
				}
				else {
					number_vector[i][j][k] = kBlackPixel;
				}
			}
		}
	}
	inFile.close();
	return number_vector;
}

std::vector<char> TrainingLabelsTo2DArray(string file) {
	std::vector<char> number_vector(kNumberOfTrainingLabels);
	std::ifstream inFile;

	inFile.open(file);
	string temp;
	for (int i = 0; i < kNumberOfTrainingLabels; i++) {
		getline(inFile, temp);
		number_vector[i] = temp.at(0);
	}
	inFile.close();
	return number_vector;
}
