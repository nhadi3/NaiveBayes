#include "trainmodel.h"

#include<iostream>
#include <fstream>
#include <vector>

std::vector<std::vector<std::vector<int>>> FileTo2DArray(string file) {
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

std::vector<char> LabelsTo2DArray(string file) {
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
