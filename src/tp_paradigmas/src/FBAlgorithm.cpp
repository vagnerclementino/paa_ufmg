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
	//Do nothing. Just call super construct

}

FBAlgorithm::~FBAlgorithm() {
	//Do nothing. Just call super construct


}
void FBAlgorithm::generateAllSolutions(PAA::TPInstance& instances, std::vector<int>& vectorSolution,int index, int maxDepth, std::list<PAA::FBSolution>& solutionList){

	std::vector<int>::iterator it;
	int i;
	PAA::FBSolution solutionTemp;

	for (i= 1; i <= 2; i++){
		vectorSolution.at(index) = i;

		if(index == (maxDepth - 1)){

			solutionTemp = this->buildSolution(vectorSolution,instances);

			if(solutionTemp.isValid()){
				solutionList.push_back(solutionTemp);
			}

		}else{
		  generateAllSolutions(instances, vectorSolution, index + 1, maxDepth, solutionList);
		}

	}
}

void FBAlgorithm::bruteForceSearch(PAA::TPInstance& instances, std::list<PAA::FBSolution>& solutionList){

	int maxSize = (instances.getSize());
	std::vector<int>* pVector;
	int index;

	for (index = 0; index <= (maxSize-1); index++){

		pVector = new std::vector<int>(index+1);

		generateAllSolutions(instances, *(pVector),0,index+1,solutionList);

		delete pVector;

	}



}

PAA::FBSolution FBAlgorithm::findBestSolution(std::list<PAA::FBSolution>& solutionList){

	std::list<PAA::FBSolution>::iterator it;
	PAA::FBSolution best;

	if(solutionList.size() > 0 ) {
			//Definindo o custo como menos infinido
			best.setCost(std::numeric_limits<int>::min());

			for (it = solutionList.begin(); it != solutionList.end(); it++){

				if(it->getCost() > best.getCost()){
					best = *(it);
				}

			}
	}else{
		best.setIsValid(false);
	}

	return (best);

}

PAA::FBSolution FBAlgorithm::buildSolution(std::vector<int>& solutionCoding, PAA::TPInstance& instanceList){
	PAA::FBSolution solution;
	PAA::Brain brain;

	std::vector<int>::iterator it;
	int offSet = 0;

	for(it = solutionCoding.begin(); it != solutionCoding.end(); it++){
		offSet = *(it);

		brain = instanceList.getInstanceItem(offSet);

		solution.addToSolution(brain);


	}

	return solution;


}

PAA::FBSolution FBAlgorithm::execute(PAA::TPInstance& instance){

	PAA::FBSolution solution;
	std::list<PAA::FBSolution> solutionList;
	std::stringstream ss;
	std::list<PAA::FBSolution>::iterator it;

	this->bruteForceSearch(instance, solutionList);

	std::cout << solutionList.size() << std::endl;
	std::cout << "Imprimindo todas as soluções" << std::endl;
	for(it = solutionList.begin(); it != solutionList.end(); it++){
		it->print();
		std::cout << "xxxx" << std::endl;
	}


	solution = this->findBestSolution(solutionList);

	return solution;


}



} /* namespace PAA */
