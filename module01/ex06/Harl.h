#ifndef HARL_H
# define HARL_H

# include <iostream>

class Harl {
private:
	enum Option {
		DEBUG,
		INFO,
		WARNING,
		ERROR,
		UNKNOWN
	};
	void debug(void);
	void info(void);
	void warning(void);
	void error(void);

public:
	void complain(std::string level);
};
#endif
