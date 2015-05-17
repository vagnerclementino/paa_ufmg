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

namespace PAA {

class TPParadigmas: public TrabalhoPratico {
public:
	TPParadigmas(int, char **);
	virtual ~TPParadigmas();
	void run(void);
	void showUserMessage(const std::string&);
	void showStatistics(void);
protected:
	void setFinalTime(void);
};

} /* namespace PAA */

#endif /* TPPARADIGMAS_H_ */
