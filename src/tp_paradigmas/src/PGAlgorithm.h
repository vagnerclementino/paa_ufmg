/*
 * PGAlgorithm.h
 *
 *  Created on: 10/05/2015
 *      Author: vagner
 */

#ifndef PGALGORITHM_H_
#define PGALGORITHM_H_
#include "Brain.h"
#include "TPSolution.h"
#include "TPInstance.h"

namespace PAA {

class PGAlgorithm {
public:
	PGAlgorithm();
	virtual ~PGAlgorithm();
	/*PAA::TPSolution*/ void execute(PAA::TPInstance&);
};

} /* namespace PAA */

#endif /* PGALGORITHM_H_ */
