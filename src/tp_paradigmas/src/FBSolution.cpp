/*
 * FBSolution.cpp
 *
 *  Created on: 05/05/2015
 *      Author: vagner
 */

#include "FBSolution.h"
#include "Brain.h"
#include "../../lib/Solution.h"
#include <list>
#include <iostream>
namespace PAA {
FBSolution::FBSolution(){


}

FBSolution::~FBSolution() {
	// TODO Auto-generated destructor stub
}


void FBSolution::validateSolution(void) {
	std::list<PAA::Brain>::iterator itCurrent;
	std::list<PAA::Brain>::iterator itNext;
	std::list<PAA::Brain>::iterator itEnd;

	itEnd	  = PAA::Solution<PAA::Brain>::getEndList();

	for(itCurrent = PAA::Solution<PAA::Brain>::getBeginList(); itCurrent != itEnd; itCurrent++){
		for(itNext = itCurrent; itNext != itEnd; itNext++){
			if (itCurrent != itNext){



				if ((*itCurrent) < (*itNext)){
						//Solução inválida
						PAA::Solution<PAA::Brain>::setIsValid(false);
						return;

				}

			}
		}
	}
	//Saiu do loop: a solução é válida!
	PAA::Solution<PAA::Brain>::setIsValid(true);



}
void FBSolution::print(void){

	std::list<PAA::Brain>::iterator it;
	std::list<PAA::Brain>::iterator itEnd;

	itEnd = PAA::Solution<PAA::Brain>::getEndList();
	std::cout << PAA::Solution<PAA::Brain>::getCost() << std::endl;
	for( it = PAA::Solution<PAA::Brain>::getBeginList(); it != itEnd; it++){
		std::cout<< it->getID() << std::endl;
	}

}
int FBSolution::getCost(void){

	return PAA::Solution<PAA::Brain>::getCost();
}
void FBSolution::addToSolution(const PAA::Brain& b){

	PAA::Solution<PAA::Brain>::addSolutionItem(b);
}
bool FBSolution::isValid(void){

	return PAA::Solution<PAA::Brain>::isValid();

}
bool FBSolution::isEmpty(void){

	return PAA::Solution<PAA::Brain>::isEmpty();

}

/**********************************************************************
 * Verifica se uma solução é melhor do que outra.
 * Uma solução A é melhor do que uma solução B se o custo de
 * A for maior do que o custo de B. Apenas lembrando que no contexto
 * do problema o custo significa o número de Brain que existe em uma
 * solução válida.
 * ********************************************************************/
bool FBSolution::operator>(FBSolution& other){

	if (PAA::Solution<PAA::Brain>::getCost() > other.getCost()  ){
		return true;
	}else{
		return false;
	}
}
}
