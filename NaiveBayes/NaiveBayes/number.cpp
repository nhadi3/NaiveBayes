#include "number.h"

std::vector<std::vector<char>> Number::FileTo2DArray(string file) {
	std::vector<std::vector<char>>number_vector(kImageDimension, std::vector<char>(kImageDimension, '-'));
	int dim = 0;
	for (int i = 0; i < kImageDimension; i++) {
		for (int j = 0; j < kImageDimension; j++) {
			number_vector[i][j] = file.at(j + dim);
		}
		dim += kImageDimension;
	}
	return number_vector;
}
