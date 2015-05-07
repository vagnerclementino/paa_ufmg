/*
 * FBAlgorithm.h
 *
 *  Created on: 05/05/2015
 *      Author: vagner
 */

#ifndef FBALGORITHM_H_
#define FBALGORITHM_H_
#include "FBSolution.h"
#include "Brain.h"
#include "IAlgorithms.h"
#include <vector>
#include <list>
#include "TPInstance.h"
#include <limits>
namespace PAA {

class FBAlgorithm{
public:
	FBAlgorithm();
	virtual ~FBAlgorithm();
	PAA::FBSolution execute(PAA::TPInstance&);

private:
	void generateAllSolutions(PAA::TPInstance&, std::vector<int>&,int, int, std::list<PAA::FBSolution>&);

	void bruteForceSearch(PAA::TPInstance&, std::list<PAA::FBSolution>&);

	PAA::FBSolution findBestSolution(std::list<PAA::FBSolution>&);

	PAA::FBSolution buildSolution(std::vector<int>&, PAA::TPInstance&);


};


} /* namespace PAA */

#endif /* FBALGORITHM_H_ */
