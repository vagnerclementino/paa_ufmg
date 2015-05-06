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

} /* namespace PAA */
