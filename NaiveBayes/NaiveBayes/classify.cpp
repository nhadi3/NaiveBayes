#include "classify.h"
#include <iostream>

std::vector<std::vector<double>> ProbabilitiesForImages() {
	std::vector<std::vector<double>> probabilities(kNumOfTestImages, std::vector<double>(kNumOfDigits));
	std::vector<std::vector<std::vector<int>>> images;
	std::vector<std::vector<std::vector<double>>> whitepixelprob;
	std::vector<std::vector<std::vector<double>>> blackpixelprob;
	std::vector<double> classprob(kNumOfDigits);

	images = ImagesToClassifyTo2DArray("testimages");
	Model model;
	model.InitializeModelAndWriteToFile("trainingimages", "test");

	whitepixelprob = model.GetWhitePixelProb();
	blackpixelprob = model.GetBlackPixelProb();
	classprob = model.GetClassProb();

	double prob = 0;
	for (int i = 0; i < kNumOfTestImages; i++) {
		for (int l = 0; l < kNumOfDigits; l++) {
			prob += log (classprob[l]);
			for (int j = 0; j < kImageDimension; j++) {
				for (int k = 0; k < kImageDimension; k++) {
					if (images[i][j][k] == 0) {
						prob += log (whitepixelprob[j][k][l]);
					}
					else {
						prob += log (blackpixelprob[j][k][l]);
					}
				}
			}
			probabilities[i][l] = prob;
			prob = 0;
		}
	}

	return probabilities;
}

std::vector<int> ClassifyImages() {
	std::vector<int> classifications(kNumOfTestImages);
	std::vector<std::vector<double>> image_probabilities(kNumOfTestImages, std::vector<double>(kNumOfDigits));

	image_probabilities = ProbabilitiesForImages();
	double max = -1000000;
	int digit = 0;
	for (int i = 0; i < kNumOfTestImages; i++) {
		for (int j = 0; j < kNumOfDigits; j++) {
			if (image_probabilities[i][j] > max) {
				max = image_probabilities[i][j];
				digit = j;
			}
		}
		max = -1000000;
		classifications[i] = digit;
	}

	return classifications;
}

std::vector<std::vector<std::vector<int>>> ImagesToClassifyTo2DArray(string file) {
	std::vector<std::vector<std::vector<int>>>number_vector(kNumOfTestImages, std::vector<std::vector<int>>(kImageDimension, std::vector<int>(kImageDimension)));
	std::ifstream inFile;

	inFile.open(file);
	string temp;
	for (int i = 0; i < kNumOfTestImages; i++) {
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