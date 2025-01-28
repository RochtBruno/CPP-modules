#ifndef FILEHANDLER_HPP
#define FILEHANDLER_HPP

#include <string>

class FileHandler {
	public:
		FileHandler(const std::string &filename, const std::string &s1, const std::string &s2);
		FileHandler();
		~FileHandler();
		bool replaceAndSave();

	private:
		std::string _filename;
		std::string _s1;
		std::string _s2;
		std::string _replaceOccurences(const std::string &content) const;
};
#endif
