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

bool GreedyAlgorithm::getIsAllEmpty(void){

	return this->isAllEmpty;

}
void GreedyAlgorithm::setIsAllEmpty(bool newSituation){

	this->isAllEmpty = newSituation;
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
	int pileIndex = 0;

	endList = instances.getEndList();

	instances.sort();

	for(itListBrain = instances.getBeginList(); itListBrain != endList; itListBrain++){

		b = *(itListBrain);

		pileIndex = this->greedyChoice(b);

		this->addToPile(pileIndex,b);
	}

	greedySolution = this->getBestSolution();

	/**Informando que a solução já foi validada
	 * Não sendo necessário a chamada da função de
	 * validação.
	 */
	greedySolution.setWasValidated(true);
	greedySolution.setIsValid(true);

	//Revertendo a ordem da lista para adequar a apresentação solicitada
	greedySolution.reverse();


	return greedySolution;
}

PAA::Brain GreedyAlgorithm::getTopBrain(int pileIndex){
	std::stringstream ss;

	try {

		 return ( (this->pSolutionPile->at(pileIndex))->getLastItem() );

	} catch (const std::out_of_range& oor) {

		ss << "Erro: o indice informado " << pileIndex << " está fora do limite. Detalhes: " << oor.what() << std::endl;

		throw PAA::PAAException(ss.str());
	}

}
int GreedyAlgorithm::greedyChoice(PAA::Brain& b){

	int pileIndex = 0;
	int i = 0;
	PAA::Brain topBrain;
	PAA::Brain maxCurrentCandidade;
	bool isCandidateFound = false;
	int indexMaxCandidate = 0;

	if(this->getIsAllEmpty()){
		//Primeira execução. Todas as pilhas estão limpa
		indexMaxCandidate = this->getNextFreePile();
		isCandidateFound = true;
		this->setNextFreePile(pileIndex + 1);
		//Informando que existe pelo menos uma pilha vazia
		this->setIsAllEmpty(false);

	}else{
		for(i=0;i< this->getNextFreePile();i++){

			topBrain = this->getTopBrain(i);

			if (b.getQI() > topBrain.getQI()){

				if(isCandidateFound){

					if (maxCurrentCandidade.getQI() < topBrain.getQI()){
						maxCurrentCandidade = topBrain;
						indexMaxCandidate = i;
					}

				}else{
					maxCurrentCandidade = topBrain;
					indexMaxCandidate = i;
					isCandidateFound = true;
				}

			}



		}

	if(isCandidateFound){
		pileIndex = indexMaxCandidate;
	}else{
		pileIndex = this->getNextFreePile();
		this->setNextFreePile(pileIndex+1);
		}

	}
	return pileIndex;
}


} /* namespace PAA */
