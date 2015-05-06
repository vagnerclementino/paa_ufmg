/*
 * FBAlgorithm.cpp
 *
 *  Created on: 05/05/2015
 *      Author: vagner
 */

#include "FBAlgorithm.h"
#include <list>
#include <vector>
#include <iostream>
#include "TPInstance.h"
#include <sstream>

namespace PAA {

FBAlgorithm::FBAlgorithm() {


}

FBAlgorithm::~FBAlgorithm() {

}
void FBAlgorithm::bruteForceSearch(std::vector<int>& vectorSolution,int index, int maxDepth, std::list<PAA::FBSolution>& solutionList){

	std::vector<int>::iterator it;
	int i;

	for (i= 0; i <= 1; i++){
		vectorSolution.at(index) = i;

		if(index == (maxDepth - 1)){
				//vectorSolution.at(index) = 1;
				//vectorSolution.at(index) = 0;
			for(it = vectorSolution.begin(); it != vectorSolution.end(); it++ ){
				std::cout << (*it);

			}
			std::cout << std::endl;

	  }else{
		  bruteForceSearch(vectorSolution, index + 1, maxDepth, solutionList);
	  }

	}
}

PAA::FBSolution FBAlgorithm::execute(PAA::TPInstance& instance){
	PAA::FBSolution solution;

	std::list<PAA::FBSolution> solutionList;
	int maxDepth;

	maxDepth = instance.getSize();

	std::vector<int> solutionVector (maxDepth);

	bruteForceSearch(solutionVector,0,maxDepth,solutionList);


	return solution;
}

} /* namespace PAA */
