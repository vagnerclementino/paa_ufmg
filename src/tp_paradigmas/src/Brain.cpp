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

Brain::Brain(){

}

int Brain::getID(void) const{
	return this->id;
}

int Brain::getQI(void)const{
	return this->qi;
}

int Brain::getWeight(void)const{

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
int Brain::getCost(void) const{
	return 1;
}
/**********************************************************
 * Método que verifica se um Brain é melhor do que outro,
 * considerando que um Brain é melhor se ele possui um  QI
 * maior mas com um peso de cérebro menor.
  *********************************************************/
bool Brain::operator>(const Brain& other) {
    if( (this->getQI() > other.getQI()) && (this->getWeight() < other.getWeight())){
        return true;
    }else{
        return false;
    }
}

/*******************************************************************
 * Verifica se um cerébro é "pior" do que outro. Um cerébro será
 * pior se ele tiver um QI menor mas um peso de cérebro maior *
 * ******************************************************************/
bool Brain::operator<(const Brain& other) {
    if (this->getQI() > other.getQI() ){
        return true;
    }else{
        return false;
    }
}

 /**************************************************************************************
  * Verifica se dois cérebros são iguais. Um cerebro A é igual a um cerebro B se eles
 * possuirem o mesmo QI e o mesmo peso.
  *********************************************************************************** */

bool Brain::operator==(const Brain& other) {
    if( (this->getQI() ==  other.getQI()) && (this->getWeight() == other.getWeight())){
        return true;
    }else{
        return false;
    }
}

/***************************************************************************************
 *  Verifica se dois cerebros são diferentes. Um cerebro A é diferente de um cerebro B
 *  se o QI de A for diferente do QI de B ou o peso de A for diferente do peso de B *
 * ************************************************************************************/
bool Brain::operator!=(const Brain& other) {
    if( (this->getQI() != other.getQI()) || (this->getWeight() != other.getWeight())){
        return true;
    }else{
        return false;
    }
}
Brain::~Brain() {
	// Do nothing.
}

} /* namespace PAA */
