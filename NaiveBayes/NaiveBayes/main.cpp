#include "main.h"
#include <iostream>
#include <fstream>
#include <string>

int main() {
	string file_to_train;
	string file_to_write_model;

	std::cout << "Enter file to train from: " << std::endl;
	std::cin >> file_to_train;
	std::cout << "Enter file to write model to: " << std::endl;
	std::cin >> file_to_write_model;

	Model model;
	model.InitializeModelAndWriteToFile(file_to_train, file_to_write_model);
	
	std::vector<std::vector<double>> confusionmatrix;
	confusionmatrix = CreateConfusionMatrix("testlabels");
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kNumOfDigits; j++) {
			std::cout << " " << confusionmatrix[i][j];
		}
		std::cout << std::endl;
	}
	std::cout << EvaluatePercentageOfCorrectClassifications("testlabels") << "%";
	return 0;
}
