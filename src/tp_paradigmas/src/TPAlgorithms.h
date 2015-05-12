/*
 * IAlgorithms.h
 *
 *  Created on: 06/05/2015
 *      Author: vagner
 */

#ifndef TPALGORITHMS_H_
#define TPALGORITHMS_H_
#include "../../lib/Solution.h"
#include "TPInstance.h"
#include "TPSolution.h"

namespace PAA {

class TPAlgorithms {
public:
	TPAlgorithms();
	virtual ~TPAlgorithms();
	PAA::TPSolution execute (PAA::TPInstance&);
};

} /* namespace PAA */

#endif /* TPALGORITHMS_H_ */
