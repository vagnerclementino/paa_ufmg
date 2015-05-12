/*
 * TPInstance.cpp
 *
 *  Created on: 04/05/2015
 *      Author: vagner
 */

#include "TPInstance.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <stdexcept>
#include <exception>
#include <sstream>
#include <algorithm>
#include "../../lib/PAAException.h"

namespace PAA {

TPInstance::TPInstance():Instance<PAA::Brain>() {
	this->fm = new PAA::FileManager();
	this->setLastInstanceID(0);
}

TPInstance::~TPInstance() {
	delete this->fm;
}

 void TPInstance::load(std::string& filePath){
	 std::string line;
	 std::vector<std::string> valuesRead;
	 std::stringstream ss;
	 char delimiter = ' ';
	 int idBrain;
	 int weightBrain;
	 int qiBrain;


	 //Abrindo o arquivo em modo de leitura
	 this->fm->openFile(filePath,'R');
	 while(this->fm->hasMore()){

		line  =  this->fm->readLine();

		valuesRead = this->splitString(line.c_str(),delimiter);

		idBrain = this->getInstanceID();

		try {
			weightBrain = atoi(valuesRead.at(0).c_str());
			qiBrain = atoi(valuesRead.at(1).c_str());

			//std::cout << idBrain << " |  " << weightBrain <<  " | " << qiBrain << std::endl;

		} catch (const std::out_of_range& oo){

			ss << "Acesso a uma posiçaõ invalida do vetor. Detalhes: " << oo.what();

			throw PAA::PAAException(ss.str());

		}
		catch (const std::exception& e) {

		    ss << "Erro duranto a carga das intancias. Detalhes: "  << e.what();

			throw PAA::PAAException(ss.str());

		}


		this->addInstanceItem(PAA::Brain(idBrain,weightBrain,qiBrain));

		valuesRead.clear();

	 }

	 Instance<PAA::Brain>::setNextItem(this->getBeginList());



}

void TPInstance::setLastInstanceID(int newID){
	this->lastIntanceID = newID;
}

std::string TPInstance::getInstanceFileName(){
	return this->fm->getFileName();
}

int TPInstance::getInstanceID(void){

	int lastID;
	lastID = (++this->lastIntanceID);
	return lastID;

}


void TPInstance::print(void){

	std::list<PAA::Brain>::iterator listIterator;

	std::cout << "Tamanho da Instância: " << Instance<PAA::Brain>::getSize() << std::endl;

	for(listIterator = Instance<PAA::Brain>::getBeginList(); listIterator != Instance<PAA::Brain>::getEndList(); listIterator++){
		listIterator->print();
	}
}

std::vector<std::string> TPInstance::splitString (const char *str, char delimiter){
	    std::vector<std::string> result;

	    do
	    {
	        const char *begin = str;

	        while(*str != delimiter && *str)
	            str++;

	        result.push_back(std::string(begin, str));
	    } while (0 != *str++);

	    return result;
}

int TPInstance::getSize(void){
	return Instance::getSize();
}

PAA::Brain TPInstance::getInstanceItem(int offSet){
	return PAA::Instance<PAA::Brain>::getInstanceItem(offSet);
}

std::vector<int> TPInstance::getIdList(void){
	std::list<PAA::Brain>::iterator it;
	std::list<PAA::Brain>::iterator itEnd;
	std::vector<int> idList (this->getSize());
	int index = 0;


	itEnd = PAA::Instance<PAA::Brain>::getEndList();

	for(it =PAA::Instance<PAA::Brain>::getBeginList(); it != itEnd; it++ ){

		idList.at(index) = it->getID();
		index++;

	}
	return idList;
}

bool TPInstance::hasMore(){

	return PAA::Instance<PAA::Brain>::hasMore();
}

PAA::Brain TPInstance::getNextBrain(void){

	return PAA::Instance<PAA::Brain>::getNextItem();

}

void TPInstance::sort(void){

	PAA::Instance<PAA::Brain>::sort();
}

std::list<PAA::Brain>::iterator TPInstance::getBeginList(){

	return PAA::Instance<PAA::Brain>::getBeginList();

}
std::list<PAA::Brain>::iterator TPInstance::getEndList(){

	return PAA::Instance<PAA::Brain>::getEndList();

}

bool TPInstance::compareWeight(PAA::Brain& b1, PAA::Brain& b2){

	return (b1.getWeight() > b2.getWeight());

}
bool TPInstance::compareQI(PAA::Brain& b1, PAA::Brain& b2){
	return (b1.getQI() < b2.getQI());
}

void TPInstance::sortByQI(void){

	PAA::Instance<PAA::Brain>::sort();

}

void TPInstance::sortByWeight(void){

}

} /* namespace PAA */
