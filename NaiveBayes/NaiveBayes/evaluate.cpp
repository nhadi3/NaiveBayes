#include "evaluate.h"

std::vector<std::vector<double>> CreateConfusionMatrix(string file) {
	std::vector<std::vector<double>> confusionmatrix(kNumOfDigits, std::vector<double>(kNumOfDigits));
	std::vector<double> numofdigits;
	std::vector<char> testlabels;
	std::vector<int> classifiedlabels;

	numofdigits = CountNumOfDigitAppearances(file);
	testlabels = TestLabelsTo2DArray("testlabels");
	classifiedlabels = ClassifyImages();

	double temppercentage = 0;

	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kNumOfDigits; j++) {
			double count = 0;
			for (int k = 0; k < kNumOfTestImages; k++) {
				if (i = j) {
					if (testlabels[k] == (char)(i + '0')) {
						count++;
					}
				}
				else {
					if ((testlabels[k] == (char)(j + '0')) && (testlabels[k] == (char)(i + '0'))) {
						count++;
					}
				}
			}
			confusionmatrix[i][j] = count / numofdigits[i];
		}
	}

	return confusionmatrix;
}

double EvaluatePercentageOfCorrectClassifications(string file) {
	std::vector<char> testlabels;
	std::vector<int> classifiedlabels;

	testlabels = TestLabelsTo2DArray(file);
	classifiedlabels = ClassifyImages();

	double count = 0;

	for (int i = 0; i < kNumOfTestImages; i++) {
		if (testlabels[i] == (char)(classifiedlabels[i] + '0')) {
			count++;
		}
	}

	return count/kNumOfTestImages * 100;
}

std::vector<char> TestLabelsTo2DArray(string file) {
	std::vector<char> number_vector(kNumOfTestImages);
	std::ifstream inFile;

	inFile.open(file);
	string temp;
	for (int i = 0; i < kNumOfTestImages; i++) {
		getline(inFile, temp);
		number_vector[i] = temp.at(0);
	}
	inFile.close();
	return number_vector;
}

std::vector<double> CountNumOfDigitAppearances(string file) {
	std::vector<double> digit_array(kNumOfDigits);
	std::vector<char> labels(kNumOfTestImages);
	labels = TestLabelsTo2DArray(file);
	double tempdigitcount = 0;
	for (int i = 0; i < kNumOfDigits; i++) {
		for (int j = 0; j < kNumOfTestImages; j++) {
			if (labels[j] == (char)(i + '0')) {
				tempdigitcount++;
			}
		}
		digit_array[i] = tempdigitcount;
		tempdigitcount = 0;
	}
	return digit_array;
}