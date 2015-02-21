/*
 * TrabalhoPratico.h
 *
 *  Created on: 02/02/2015
 *      Author: vagner
 */

#ifndef TRABALHOPRATICO_H_
#define TRABALHOPRATICO_H_

#include <ctime>
#include <string>
#include "FileManager.h"
#define MAX_TIME_STRING 100
#define SECONDS_IN_A_DAY 864000
#define SECONDS_IN_A_HOUR 3600
#define SECONDS_IN_A_MIN 60

namespace PAA {

class TrabalhoPratico {


private:
	struct tm* startTime;
	struct tm* finalTime;
	int argc;
	char **argv;
	bool writeLog;
	FileManager* logFile;

protected:
	TrabalhoPratico();
	TrabalhoPratico(int , char **);

	virtual void run(void)= 0;
	void showUserMessage(const std::string&);
	void showStatistics(void);
	virtual ~TrabalhoPratico();
	struct tm getSystemTime(void);
	void setFinalTime(void);
	std::string getFormatedTimeString(const struct tm&) const;
};

} /* namespace PAA */

#endif /* TRABALHOPRATICO_H_ */
