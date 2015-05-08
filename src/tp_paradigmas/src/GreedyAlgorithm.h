/*
 * GreedyAlgorithm.h
 *
 *  Created on: 07/05/2015
 *      Author: vagner
 */

#ifndef GREEDYALGORITHM_H_
#define GREEDYALGORITHM_H_
#include "Brain.h"
#include "TPSolution.h"
#include "TPInstance.h"

namespace PAA {

class GreedyAlgorithm {
public:
	GreedyAlgorithm();
	virtual ~GreedyAlgorithm();
	PAA::TPSolution execute(PAA::TPInstance&);
private:

	PAA::Brain greedyChoice(PAA::TPInstance&);
};

} /* namespace PAA */

#endif /* GREEDYALGORITHM_H_ */
