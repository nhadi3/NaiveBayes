#include "trainmodel.h"

#include<iostream>
#include <fstream>
#include <vector>

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
					number_vector[i][j][k] = 0;
				}
				else {
					number_vector[i][j][k] = 1;
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
