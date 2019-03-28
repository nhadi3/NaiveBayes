#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	std::vector<std::vector<double>> confusionmatrix;
	confusionmatrix = CreateConfusionMatrix("testlabels");
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kNumOfDigits; j++) {
			std::cout << " " << confusionmatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::vector<double> count;
	count = CountNumOfDigitAppearances("traininglabels");
	for (int i = 0; i < kNumOfDigits; i++) {
		std::cout << " " << count[i];
	}
	std::cout << EvaluatePercentageOfCorrectClassifications("testlabels") << "%";
	return 0;
}
