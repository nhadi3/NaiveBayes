#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::vector<std::vector<std::vector<int>>>number_vector(kNumberOfTrainingLabels, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	std::vector<char> number(kNumberOfTrainingLabels);
	std::vector<double> prob(kNumOfDigits);

	number_vector = TrainingImagesTo2DArray("trainingimages");
	number = TrainingLabelsTo2DArray("traininglabels");
	prob = CalculateProbabilityForEachClass("traininglabels");
	/*for (int i = 0; i < kNumberOfTrainingLabels; i++) {
		for (int j = 0; j < kImageDimension; j++) {
			for (int k = 0; k < kImageDimension; k++) {
				std::cout << " " << number_vector[i][j][k];
			}
			std::cout << std::endl;
		}
	}

	for (int i = 0; i < kNumberOfTrainingLabels; i++) {
		std::cout << " " << number[i];
	}*/

	for (int i = 0; i < kNumOfDigits; i++) {
		std::cout << " " << prob[i];
	}

	return 0;
}
