#include "model.h"

void Model::SetClassProb(std::vector<double> prob) {
	classprobability_ = prob;
}

std::vector<double> Model::GetClassProb() {
	return classprobability_;
}

void Model::SetPixelProb(std::vector<std::vector<std::vector<double>>> prob) {
	pixelprobability_ = prob;
}

std::vector<std::vector<std::vector<double>>> Model::GetPixelProb() {
	return pixelprobability_;
}