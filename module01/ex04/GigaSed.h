#ifndef GIGA_SED_H
# define GIGA_SED_H

# include <fstream>
# include <iostream>

class GigaSed {
private:
	std::ifstream& file;
	std::string outFilename;

public:
	GigaSed(std::ifstream& file, std::string outFilename);
	~GigaSed(void);
	void replace(std::string findStr, std::string replaceStr);

};
#endif
