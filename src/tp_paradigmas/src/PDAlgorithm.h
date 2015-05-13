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

class PDAlgorithm {
public:
	PDAlgorithm();
	virtual ~PDAlgorithm();
	PAA::TPSolution execute(PAA::TPInstance&);
};

} /* namespace PAA */

#endif /* PGALGORITHM_H_ */
