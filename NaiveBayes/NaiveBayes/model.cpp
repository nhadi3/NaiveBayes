#include "model.h"

void Model::SetClassProb(std::vector<double> prob) {
	classprobability_ = prob;
}

std::vector<double> Model::GetClassProb() {
	return classprobability_;
}

void Model::SetWhitePixelProb(std::vector<std::vector<std::vector<double>>> prob) {
	whitepixelprobability_ = prob;
}

std::vector<std::vector<std::vector<double>>> Model::GetWhitePixelProb() {
	return whitepixelprobability_;
}

void Model::SetBlackPixelProb(std::vector<std::vector<std::vector<double>>> prob) {
	blackpixelprobability_ = prob;
}

std::vector<std::vector<std::vector<double>>> Model::GetBlackPixelProb() {
	return blackpixelprobability_;
}

void Model::InitializeModelAndWriteToFile(string file, string newfile) {
	std::vector<std::vector<std::vector<double>>> whitepixelprob;
	std::vector<std::vector<std::vector<double>>> blackpixelprob;
	std::vector<double> classprob(kNumOfDigits);

	whitepixelprob = CalculateProbabilityForEachPixel(file, kWhitePixel);
	blackpixelprob = CalculateProbabilityForEachPixel(file, kBlackPixel);
	classprob = CalculateProbabilityForEachClass("traininglabels");

	SetWhitePixelProb(whitepixelprob);
	SetBlackPixelProb(blackpixelprob);
	SetClassProb(classprob);

	std::ofstream outFile;
	outFile.open(newfile);
	for (int i = 0; i < kNumOfDigits; i++) {
		outFile << " " << classprob[i] << std::endl;
	}
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kImageDimension; j++) {
			for (int k = 0; k < kImageDimension; k++) {
				outFile << " " << whitepixelprob[j][k][i];
			}
			outFile << std::endl;
		}
	}
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kImageDimension; j++) {
			for (int k = 0; k < kImageDimension; k++) {
				outFile << " " << blackpixelprob[j][k][i];
			}
			outFile << std::endl;
		}
	}
	outFile.close();
}
