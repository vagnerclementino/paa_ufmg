/*
 * GreedyAlgorithm.cpp
 *
 *  Created on: 07/05/2015
 *      Author: vagner
 */

#include "GreedyAlgorithm.h"

namespace PAA {

GreedyAlgorithm::GreedyAlgorithm() {

	this->pSolutionPile = NULL;



}

GreedyAlgorithm::~GreedyAlgorithm() {
	// TODO Auto-generated destructor stub
}

int GreedyAlgorithm::getNextFreePile(void){

	return this->nextFreePile;

}

void GreedyAlgorithm::setNextFreePile(int nextPile){

	this->nextFreePile = nextPile;

}

int GreedyAlgorithm::getMaxSequenceLength(void){

	return this->maxSequenceLength;
}

void GreedyAlgorithm::setMaxSequenceLength(int newMaxLength){

	this->maxSequenceLength = newMaxLength;


}
int GreedyAlgorithm::getBestSolution(void){

	return this->bestSolution;

}
void GreedyAlgorithm::setBestSolution(int newBestSolution){

	this->bestSolution = newBestSolution;

}


PAA::TPSolution GreedyAlgorithm::execute(PAA::TPInstance&){
	PAA::TPSolution greedySolution;


	return greedySolution;
}

int GreedyAlgorithm::greedyChoice(PAA::TPInstance&){
	PAA::Brain b;

	return b;
}


} /* namespace PAA */
