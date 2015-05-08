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
#include <sstream>
namespace PAA {
FBSolution::FBSolution(){


}

FBSolution::~FBSolution() {
	// TODO Auto-generated destructor stub
}


void FBSolution::validateSolution(void) {

	TPSolution::validateSolution();
}

void FBSolution::print(void){

	TPSolution::print();
}
int FBSolution::getCost(void){

	return TPSolution::getCost();
}
void FBSolution::addToSolution(const PAA::Brain& b){

	TPSolution::addToSolution(b);
}
bool FBSolution::isValid(void){

	return TPSolution::isValid();

}
bool FBSolution::isEmpty(void){

	return TPSolution::isEmpty();

}

bool FBSolution::isItValidated(void){

	return TPSolution::isItValidated();
}

void FBSolution::setIsValid(bool isValid){

	TPSolution::setIsValid(isValid);
}

void FBSolution::setCost(int newCost){

	TPSolution::setCost(newCost);
}

/**********************************************************************
 * Verifica se uma solução é melhor do que outra.
 * Uma solução A é melhor do que uma solução B se o custo de
 * A for maior do que o custo de B. Apenas lembrando que no contexto
 * do problema o custo significa o número de Brain que existe em uma
 * solução válida.
 * ********************************************************************/
bool FBSolution::operator>(FBSolution& other){

	return TPSolution::operator >(other);

}


}/* namespace PAA */
