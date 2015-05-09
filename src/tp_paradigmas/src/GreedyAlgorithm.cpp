/*
 * GreedyAlgorithm.cpp
 *
 *  Created on: 07/05/2015
 *      Author: vagner
 */

#include "GreedyAlgorithm.h"
#include "TPSolution.h"
#include "../../lib/PAAException.h"
#include <stdexcept>
#include <sstream>

namespace PAA {

GreedyAlgorithm::GreedyAlgorithm(int instanceLength) {

	std::vector<PAA::TPSolution*>::iterator it;
	if (instanceLength > 0) {

		this->pSolutionPile = new std::vector<PAA::TPSolution*>(instanceLength);

		for (it = (this->pSolutionPile->begin());
				it != this->pSolutionPile->end(); it++) {

			*(it) = NULL;
		}

	} else {
		throw PAA::PAAException(
				"O tamanho de instância informado não é valido.");
	}

try {

	this->setMaxOfPiles(instanceLength);

	this->setBestSolutionIndex(0);

	this->setMaxSequenceLength(0);

	this->setNextFreePile(0);

}  catch (const std::exception& e) {

	throw PAA::PAAException("Erro na criação do algoritimo guloso.");

}




}

GreedyAlgorithm::~GreedyAlgorithm() {
	std::vector<PAA::TPSolution*>::iterator it;

	for (it = (this->pSolutionPile->begin()); it != this->pSolutionPile->end();
			it++) {

		if ((*it) != NULL){
			delete *(it);
		}
	}

	delete this->pSolutionPile;
}

int GreedyAlgorithm::getNextFreePile(void){

	return this->nextFreePile;

}

void GreedyAlgorithm::setNextFreePile(int nextPile){

	if(0 <= nextPile && nextPile <= (this->getMaxOfPiles()-1)){
		this->nextFreePile = nextPile;
	}
}

int GreedyAlgorithm::getMaxSequenceLength(void){

	return this->maxSequenceLength;
}

void GreedyAlgorithm::setMaxSequenceLength(int newMaxLength){

	if(0 <= newMaxLength && newMaxLength <= (this->getMaxOfPiles()-1)){

		this->maxSequenceLength = newMaxLength;

	}else{
		throw PAA::PAAException("O tamanho máximo de sequência informado é invalido.");
	}




}
int GreedyAlgorithm::getBestSolutionIndex(void){

	return this->bestSolution;

}
void GreedyAlgorithm::setBestSolutionIndex(int newBestSolution){

	if (0 <= newBestSolution && newBestSolution <= (this->getMaxOfPiles() - 1)) {

		this->bestSolution = newBestSolution;

	} else {
		throw PAA::PAAException("O indicie da melhor solução informada é inválido.");
	}
}

int GreedyAlgorithm::getMaxOfPiles(void){

	return this->maxOfPiles;

}
void GreedyAlgorithm::setMaxOfPiles(int maxPiles){
	if(maxPiles > 0){
		this->maxOfPiles = maxPiles;
	}else{

		throw PAA::PAAException("O tamanho máximo de uma pilha deve ser maior do que 0 (zero) ");

	}
}

void GreedyAlgorithm::addToPile(int pileIndex, PAA::Brain& b){


	std::stringstream ss;
	int currentSolutionCost;
	try {

		if(this->pSolutionPile->at(pileIndex) == NULL){
			this->pSolutionPile->at(pileIndex) = new PAA::TPSolution();
		}

		this->pSolutionPile->at(pileIndex)->addToSolution(b);

		currentSolutionCost = this->pSolutionPile->at(pileIndex)->getCost();

		if( currentSolutionCost > this->getMaxSequenceLength()){
			this->setMaxSequenceLength(currentSolutionCost);
			this->setBestSolutionIndex(pileIndex);
		}

	} catch (const std::out_of_range& oor) {

		ss << "Erro: o indice infomrado está fora do limite. Detalhes: " << oor.what() << std::endl;

		throw PAA::PAAException(ss.str());

	}catch (const std::exception& e){

		ss << "Erro ao inserir o cerebro " << b.getID() <<
			" para a solução de indice " << pileIndex <<
			" Detalhes: " << e.what()  << std::endl;

	}

}
PAA::TPSolution GreedyAlgorithm::getBestSolution(void){
	int bestSolutionIndex;

	bestSolutionIndex = this->getBestSolutionIndex();

	if(0 <= bestSolutionIndex && bestSolutionIndex <= (this->getMaxOfPiles()-1)){
		return *(this->pSolutionPile->at(bestSolutionIndex));
	}else{
		throw PAA::PAAException("Não foi possível encontrar uma solução.");
	}
}

PAA::TPSolution GreedyAlgorithm::execute(PAA::TPInstance& instances){
	PAA::TPSolution greedySolution;
	std::list<PAA::Brain>::iterator itListBrain;
	std::list<PAA::Brain>::iterator endList;
	PAA::Brain b;
	int pileIndex;

	while(instances.hasMore()){

		b = instances.getNextBrain();

		pileIndex = this->greedyChoice(b);

		this->addToPile(pileIndex,b);
	}

	greedySolution = this->getBestSolution();

	return greedySolution;
}

int GreedyAlgorithm::greedyChoice(PAA::Brain& b){

	int pileIndex;


	pileIndex = this->getNextFreePile();

	this->setNextFreePile(pileIndex + 1);

	return pileIndex;
}


} /* namespace PAA */
