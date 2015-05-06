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
#include <limits>
#include "../../lib/PAAException.h"

namespace PAA {

FBAlgorithm::FBAlgorithm() {


}

FBAlgorithm::~FBAlgorithm() {

}
void FBAlgorithm::generateAllSolutions(PAA::TPInstance& instances, std::vector<int>& vectorSolution,int index, int maxDepth, std::list<PAA::FBSolution>& solutionList){

	std::vector<int>::iterator it;
	int i;

	for (i= 0; i <= 1; i++){
		vectorSolution.at(index) = i;

		if(index == (maxDepth - 1)){
			for(it = vectorSolution.begin(); it != vectorSolution.end(); it++ ){
				std::cout << (*it);

			}
			std::cout << std::endl;

	  }else{
		  generateAllSolutions(instances, vectorSolution, index + 1, maxDepth, solutionList);
	  }

	}
}

void FBAlgorithm::bruteForceSearch(PAA::TPInstance& instances, std::list<PAA::FBSolution>& solutions){

	std::list<PAA::FBSolution> solutionList;

	std::vector<int> solutionVector (instances.getSize());

	generateAllSolutions(instances, solutionVector,0,instances.getSize(),solutionList);

}

PAA::FBSolution findBestSolution(std::list<PAA::FBSolution>& solutionList){

	std::list<PAA::FBSolution>::iterator it;
	PAA::FBSolution best;

	//Definindo o custo como menos infinido
	best.setCost(std::numeric_limits<int>::min());

	for (it = solutionList.begin(); it != solutionList.end(); it++){

		if(it->getCost() > best.getCost()){
			best = *(it);
		}

	}

	return (best);

}

PAA::FBSolution FBAlgorithm::execute(PAA::TPInstance& instance){
	PAA::FBSolution solution;
	std::list<PAA::FBSolution> solutionList;

	this->bruteForceSearch(instance, solutionList);

	solution = this->findBestSolution(solutionList);

	if(solution.isValid()){
		return solution;
	}else{
		throw PAA::PAAException ("Não foi possível encontrar uma solução para a instância informada");
	}

}



} /* namespace PAA */
