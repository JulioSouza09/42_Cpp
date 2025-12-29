#include "GigaSed.h"
#include "error.h"
#include <string>

GigaSed::GigaSed(std::ifstream& file, std::string filename) : 
	file(file),
	outFilename(filename.append(".replace")) {}

GigaSed::~GigaSed(void) {}

void GigaSed::replace(std::string findStr, std::string replaceStr) {
	std::string line;
	std::ofstream fileOutput;
	size_t found;

	fileOutput.open(this->outFilename.c_str());
	if (fileOutput.fail()) {
		error("Failed opening output file");
		return ;
	}
	while (!std::getline(this->file, line).eof()) {
		while ((found = line.find(findStr)) != std::string::npos) {
			line.erase(found, findStr.length());
			line.insert(found, replaceStr);
		}
		line += "\n";
		fileOutput.write(line.c_str(), line.length());
	}
}
