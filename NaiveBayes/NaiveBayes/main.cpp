#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::vector<std::vector<std::vector<int>>>number_vector(kNumberOfTrainingLabels, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	std::vector<char> number(kNumberOfTrainingLabels);
	std::vector<double> prob(kNumOfDigits);
	std::vector<std::vector<std::vector<double>>> pixelprob;
	
	Model model;

	model.InitializeModelAndWriteToFile("trainingimages", "test");

	pixelprob = model.GetWhitePixelProb();

	number_vector = TrainingImagesTo2DArray("trainingimages");
	number = TrainingLabelsTo2DArray("traininglabels");
	prob = CountNumOfTimesDigitAppears("traininglabels");
	//pixelprob = CalculateProbabilityForEachPixel("trainingimages", 0);
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

	/*for (int i = 0; i < kNumOfDigits; i++) {
		std::cout << " " << prob[i];
	}*/
	
	//for (int i = 0; i < kNumOfDigits; i++) {
	//	for (int j = 0; j < kImageDimension; j++) {
	//		for (int k = 0; k < kImageDimension; k++) {
	//			std::cout << " " << pixelprob[j][k][i];
	//		}
	//		std::cout << std::endl;
	//	}
	//}
	//std::vector<std::vector<std::vector<int>>>test_vector(kNumOfTestImages, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	//test_vector = ImagesToClassifyTo2DArray("testimages");

	//for (int i = 0; i < kNumOfTestImages; i++) {
	//	for (int j = 0; j < kImageDimension; j++) {
	//		for (int k = 0; k < kImageDimension; k++) {
	//			std::cout << " " << test_vector[i][j][k];
	//		}
	//		std::cout << std::endl;
	//	}
	//}

	std::vector<std::vector<double>> probabilities;

	probabilities = ProbabilitiesForImages();

	for (int i = 0; i < kNumOfTestImages; i++) {
		for (int l = 0; l < kNumOfDigits; l++) {
			std::cout << " " << probabilities[i][l];
		}
		std::cout << std::endl;
	}

	std::vector<int> classifications(kNumOfTestImages);

	classifications = ClassifyImages("testimages", "test");
	for (int i = 0; i < kNumOfTestImages; i++) {
		std::cout << classifications[i] << std::endl;
	}

	return 0;
}
