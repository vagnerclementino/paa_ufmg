/*
 * TP1.cpp
 *
 *  Created on: 02/02/2015
 *      Author: vagner
 */

#include "TP0.h"
#include "../lib/TrabalhoPratico.h"
#include <iostream>
#include "../lib/PAAException.h"
#include <new>
#include <sstream>
#include <unistd.h>

namespace PAA {

TP0::TP0():TrabalhoPratico()
{
	this->setLogFile(std::string("./outputs/tp0.log"));

}

TP0::~TP0() {
	// TODO Auto-generated destructor stub
}

void TP0::run(void ){
	try {
			this->showUserMessage("Iniciando a execução do TP1");

			this->showUserMessage("Ola Mundo");

			sleep(15);

			this->showUserMessage("Finalizando a execução do TP1");

			this->setFinalTime();

	} catch (const std::exception& e) {

		std::stringstream ss;
		ss << "Erro durante a alocaco de memoria. Tipo de excecao: " << e.what();
		throw PAA::PAAException(ss.str());


	}


}

void TP0::showUserMessage(const std::string& message){

	PAA::TrabalhoPratico::showUserMessage(message);

}

void TP0::showStatistics(void){

	PAA::TrabalhoPratico::showStatistics();
}

void TP0::setFinalTime(void){

	PAA::TrabalhoPratico::setFinalTime();

}

}/* namespace PAA */
