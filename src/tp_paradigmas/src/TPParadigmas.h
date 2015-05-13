/*
 * TPParadigmas.h
 *
 *  Created on: 04/05/2015
 *      Author: vagner
 */

#ifndef TPPARADIGMAS_H_
#define TPPARADIGMAS_H_

#include <string>
#include "../../lib/TrabalhoPratico.h"
#include <vector>
#include <map>

#define NUMBER_OF_ARGUMENTS 7
#define PROGRAM_NAME_POSITION 0
#define INPUT_FILE_NAME_POSITION 2
#define OUTPUT_FILE_NAME_POSITION 4
#define PARADIGM_TYPE_POSITION 6

namespace PAA {

class TPParadigmas: public TrabalhoPratico {
private:
	std::vector<std::string>* pArgs;
	enum algorithms {
		FORCE_BRUTE = 1, GREEDY = 2, PROG_DINAMIC = 3
	};

	std::map<std::string, algorithms> mapAlgorithms;
	void loadMapParadigms(void);
	int getParadigm(std::string&);
public:
	TPParadigmas(int, char**);
	virtual ~TPParadigmas();
	void run(void);
	void showUserMessage(const std::string&);
	void showStatistics(void);
protected:
	void setFinalTime(void);
	int getNumberOfArgs(void);
	std::string getInputFilePath(void);
	std::string getOutputFilePath(void);
	std::string getParadigmType(void);
};

} /* namespace PAA */

#endif /* TPPARADIGMAS_H_ */
