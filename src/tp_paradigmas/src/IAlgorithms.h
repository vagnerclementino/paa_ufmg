/*
 * IAlgorithms.h
 *
 *  Created on: 06/05/2015
 *      Author: vagner
 */

#ifndef IALGORITHMS_H_
#define IALGORITHMS_H_
#include "../../lib/Solution.h"
#include "Brain.h"
#include "TPInstance.h"

namespace PAA {

class IAlgorithms {
public:
	IAlgorithms();
	virtual ~IAlgorithms();
	virtual PAA::Solution<PAA::Brain>* execute (PAA::TPInstance&) = 0;
};

} /* namespace PAA */

#endif /* IALGORITHMS_H_ */
