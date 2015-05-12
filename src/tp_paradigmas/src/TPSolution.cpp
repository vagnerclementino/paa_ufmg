/*
 * TPSolution.cpp
 *
 *  Created on: 07/05/2015
 *      Author: vagner
 */

#include "TPSolution.h"
#include <sstream>
#include <iostream>

namespace PAA {

TPSolution::TPSolution() {
	// TODO Auto-generated constructor stub

}

TPSolution::~TPSolution() {
	// TODO Auto-generated destructor stub
}

void TPSolution::print(void){

	std::list<PAA::Brain>::iterator it;
	std::list<PAA::Brain>::iterator itEnd;
	std::stringstream ss;

	ss << "[";

	itEnd = PAA::Solution<PAA::Brain>::getEndList();

	for( it = PAA::Solution<PAA::Brain>::getBeginList(); it != itEnd; it++){
		ss << it->getID() << ",";
	}
	//Removendo o último caractere da stream
	ss.seekp(ss.str().length()-1);

	ss << "]";
	std::cout << "Tamanho da solução: "  << this->getCost() << std::endl;
	std::cout << ss.str() << std::endl;
}
int TPSolution::getCost(void){

	return PAA::Solution<PAA::Brain>::getCost();
}
void TPSolution::addToSolution(const PAA::Brain& b){

	PAA::Solution<PAA::Brain>::addSolutionItem(b);
}
bool TPSolution::isValid(void){

	if (this->getCost() == 0){

		this->setIsValid(false);

	}else if(!this->isItValidated()){
		//if it was not validated. Do it
		this->validateSolution();
		this->setIsItValidated(true);
	}

	return PAA::Solution<PAA::Brain>::isValid();

}
bool TPSolution::isEmpty(void){

	return PAA::Solution<PAA::Brain>::isEmpty();

}

bool TPSolution::isItValidated(void){

	return PAA::Solution<PAA::Brain>::getWasValidated();
}

void TPSolution::setWasValidated(bool wasValidated){

	PAA::Solution<PAA::Brain>::setIsItValidated(wasValidated);

};



void TPSolution::setIsValid(bool isValid){

	PAA::Solution<PAA::Brain>::setIsValid(isValid);
}

void TPSolution::setCost(int newCost){

	PAA::Solution<PAA::Brain>::setCost(newCost);
}

PAA::Brain TPSolution::getLastItem(void){

	return PAA::Solution<PAA::Brain>::getLastItem();

}

/**********************************************************************
 * Verifica se uma solução é melhor do que outra.
 * Uma solução A é melhor do que uma solução B se o custo de
 * A for maior do que o custo de B. Apenas lembrando que no contexto
 * do problema o custo significa o número de Brain que existe em uma
 * solução válida.
 * ********************************************************************/
bool TPSolution::operator>(TPSolution& other){

	if (PAA::Solution<PAA::Brain>::getCost() > other.getCost()  ){
		return true;
	}else{
		return false;
	}
}

void TPSolution::validateSolution(void){
	std::list<PAA::Brain>::iterator itCurrent;
	std::list<PAA::Brain>::iterator itNext;
	std::list<PAA::Brain>::iterator itEnd;

	itEnd	  = PAA::Solution<PAA::Brain>::getEndList();

	for(itCurrent = PAA::Solution<PAA::Brain>::getBeginList(); itCurrent != itEnd; itCurrent++){
		for(itNext = itCurrent; itNext != itEnd; itNext++){
			if (itCurrent != itNext){



				if ((*itCurrent) > (*itNext)){
						//Solução Válida



				}else{
					PAA::Solution<PAA::Brain>::setIsValid(false);
					return;
				}

			}
		}
	}

	if(itCurrent == itEnd){
		//Saiu do loop: a solução é válida!
		PAA::Solution<PAA::Brain>::setIsValid(true);
	}
}

void TPSolution::operator+=(Solution<PAA::Brain>& other){

	PAA::Solution<PAA::Brain>::operator +=(other);

}

void TPSolution::clear(void){

	PAA::Solution<PAA::Brain>::clear();

}

void TPSolution::reverse(void){

	PAA::Solution<PAA::Brain>::reverse();

}

} /* namespace PAA */
