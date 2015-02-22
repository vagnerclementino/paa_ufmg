/*
 * TP1.h
 *
 *  Created on: 02/02/2015
 *      Author: vagner
 */

#ifndef TP1_H_
#define TP1_H_

#include "../lib/TrabalhoPratico.h"

namespace PAA {

class TP0: public TrabalhoPratico {
public:
	TP0();
	virtual ~TP0();
	void run(void);
	void showUserMessage(const std::string&);
	void showStatistics(void);
protected:
	void setFinalTime(void);
};

} /* namespace PAA */

#endif /* TP1_H_ */
