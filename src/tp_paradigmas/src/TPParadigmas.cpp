/*
 * TPParadigmas.cpp
 *
 *  Created on: 04/05/2015
 *      Author: vagner
 */

#include "TPParadigmas.h"
#include "../../lib/TrabalhoPratico.h"
#include <iostream>
#include "../../lib/PAAException.h"
#include <new>
#include <sstream>
#include <unistd.h>
#include "Brain.h"
#include "TPInstance.h"
#include "FBAlgorithm.h"

namespace PAA {

TPParadigmas::TPParadigmas(int numArgs, char ** args):TrabalhoPratico(numArgs, args) {
	//Chamando o construtor da classe Pai(TrabalhoPratico)

}

TPParadigmas::~TPParadigmas() {
	// TODO Auto-generated destructor stub
}

void TPParadigmas::run(void ){
	std::stringstream ss;
	PAA::FBAlgorithm fb;
	PAA::FBSolution solution;
	PAA::TPInstance instances;
	try {

            std::string fileName = "/home/vagner/Vagner/workspace/paa_ufmg/src/tp_paradigmas/inputs/inputs.txt";
            this->showUserMessage("Iniciando a execução.");
            PAA::Brain b2 (2,6000,2100);
            PAA::Brain b3 (3,500,2000);

            if(b2 < b3){
            	std::cout << "Invalido" << std::endl;
            }


			instances.load(fileName);
			ss << "Tamanho da instância " << instances.getSize();
			this->showUserMessage(ss.str());

			instances.print();

			solution = fb.execute(instances);

			if(solution.isValid()){
				solution.print();
			}else{
				this->showUserMessage("Não foi encontrada um solução para a instância informada.");
			}


			this->showUserMessage("Finalizando a execução.");

			this->setFinalTime();

	} catch (const std::exception& e) {


		ss << "Erro durante a alocaco de memoria. Tipo de excecao: " << e.what();
		throw PAA::PAAException(ss.str());


	}


}

void TPParadigmas::showUserMessage(const std::string& message){

	PAA::TrabalhoPratico::showUserMessage(message);

}

void TPParadigmas::showStatistics(void){

	PAA::TrabalhoPratico::showStatistics();
}

void TPParadigmas::setFinalTime(void){

	PAA::TrabalhoPratico::setFinalTime();

}

} /* namespace PAA */
