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
void FBAlgorithm::generateAllSolutions(std::vector<int>& alphabet, int lastID, PAA::TPInstance& instances, std::vector<int>* vectorSolution,int index, int maxDepth, PAA::FBSolution& solution){

	std::vector<int>::iterator it;
	PAA::FBSolution solutionTemp;
	std::vector<int>::iterator itAlpha; // iterator for alphabet

	for ( itAlpha = alphabet.begin(); itAlpha != alphabet.end(); itAlpha++){

		/*
		 * Evitando a geração de soluções que possuem
		 * valores repitidos. Desta forma, apenas serão
		 * gerados soluções com valores distintos.
		 * */
		if(*(itAlpha) != lastID){
			vectorSolution->at(index) = *(itAlpha);
			lastID = *(itAlpha);
		}



		if(index == (maxDepth - 1)){

			solutionTemp = buildSolution(vectorSolution,instances);

			if(solutionTemp.isValid()){

				if(solutionTemp.getCost() > solution.getCost()){

					solution = solutionTemp;
				}

			}

		}else{
		  generateAllSolutions(alphabet, lastID, instances, vectorSolution, index + 1, maxDepth, solution);
		}

	}
}

void FBAlgorithm::bruteForceSearch(PAA::TPInstance& instances, PAA::FBSolution& solution){

	int maxSize = (instances.getSize());
	std::vector<int>* pVector;
	int index;

	/*
	 * Um alfabeto, será o conjunto com todos os ID dos
	 * cerebros
	 *
	 * */
	std::vector<int> alphabet = instances.getIdList();

	for (index = 0; index <= (maxSize-1); index++){

		pVector = new std::vector<int>(index+1);

		generateAllSolutions(alphabet, std::numeric_limits<int>::min(), instances, pVector,0,index+1,solution);

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

PAA::FBSolution FBAlgorithm::buildSolution(std::vector<int>* solutionCoding, PAA::TPInstance & instanceList){
	PAA::FBSolution solution;
	PAA::Brain brain;

	std::vector<int>::iterator it;
	int offSet = 0;

	for(it = solutionCoding->begin(); it != solutionCoding->end(); it++){
		offSet = *(it);

		brain = instanceList.getInstanceItem((offSet-1));

		solution.addToSolution(brain);


	}

	return solution;


}

PAA::FBSolution FBAlgorithm::execute(PAA::TPInstance& instance){

	PAA::FBSolution bestSolution;
	std::list<PAA::FBSolution> solutionList;
	std::stringstream ss;
	std::list<PAA::FBSolution>::iterator it;

	/* **********************************************
	 * Realiza a busca de toda as soluções possíveis
	 * de uma dada instância repesentada por
	 * pela varíavel 'instance'.
	 * Estas soluções, quando válidas, são inseridas
	 * na lista 'solutionList'
	 * ********************************************/
	this->bruteForceSearch(instance, bestSolution);

	/****************************************************
	 * Buscando entre todas as soluções válida aquela
	 * que é a melhor. Melhor neste contexto significa
	 * a de maior custo ou maior tamanho.
	 ***************************************************/
	//bestSolution = this->findBestSolution(solutionList);

	return bestSolution;


}



} /* namespace PAA */
