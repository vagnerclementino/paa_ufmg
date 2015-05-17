/*
 * Brain.cpp
 *
 *  Created on: 04/05/2015
 *      Author: vagner
 */

#include "Brain.h"
#include <iostream>
namespace PAA {

Brain::Brain(int id, int weight, int qi) {

	this->setID(id);
	this->setWeight(weight);
	this->setQI(qi);


}

int Brain::getID(void){
	return this->id;
}

int Brain::getQI(void){
	return this->qi;
}

int Brain::getWeight(void){

	return this->weight;
}

void Brain::setID(int newID){

	this->id = newID;

}

void Brain::setQI(int newQI){
	this->qi = newQI;
}

void Brain::setWeight(int newWeight){
	this->weight = newWeight;
}

void Brain::print(void){
	std::cout << "ID: " << this->getID() << std::endl;
	std::cout << "Weight: " << this->getWeight()<< std::endl;
	std::cout << "QI: " << this->getQI() << std::endl;
	std::cout << "********************" << std::endl;
}

/***********************************************
 *
 * Retorna o custo de incluir um cérebro
 * em um solução do problema.
 * Por padrão este valor é sempre 1
 *
 * *******************************************/
int Brain::getCost(void){
	return 1;
}

Brain::~Brain() {
	// Do nothing.
}

} /* namespace PAA */
