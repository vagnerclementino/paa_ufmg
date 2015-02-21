/*
 * FileManager.h
 *
 *  Created on: 04/02/2015
 *      Author: vagner
 */

#ifndef FILEMANAGER_H_
#define FILEMANAGER_H_
#define MAXPATHLEN 200
#define PATHSEPARATOR '/'
#include <string>
#include <fstream>


namespace PAA {

class FileManager {

private:
	std::string fileName;

	std::fstream *pFile;

	std::string getCurrentDirectory(void) const;

	bool isfullPath(std::string&)const;


public:
	FileManager();
	FileManager(std::string&, char);
	std::string getFileName(void)const;
	void openFile(const std::string&, char);
	void closeFile(void);
	void writeToFile(const std::string&);
	std::string readLine(void);
	bool hasMore(void)const;
	virtual ~FileManager();
};

} /* namespace PAA */

#endif /* FILEMANAGER_H_ */
