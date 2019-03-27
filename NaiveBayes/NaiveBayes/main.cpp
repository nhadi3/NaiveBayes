#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::vector<std::vector<std::vector<int>>>number_vector(kNumberOfTrainingLabels, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	std::vector<char> number(kNumberOfTrainingLabels);

	number_vector = FileTo2DArray("trainingimages");
	number = LabelsTo2DArray("traininglabels");

	for (int i = 0; i < kNumberOfTrainingLabels; i++) {
		for (int j = 0; j < kImageDimension; j++) {
			for (int k = 0; k < kImageDimension; k++) {
				std::cout << " " << number_vector[i][j][k];
			}
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < kNumberOfTrainingLabels; i++) {
		std::cout << " " << number[i];
	}

	return 0;
}
