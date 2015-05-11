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
#include "FBSolution.h"
#include "PGAlgorithm.h"
#include "GreedyAlgorithm.h"

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
	PAA::GreedyAlgorithm* greedy;
	PAA::TPSolution solution;
	PAA::TPInstance instances;
	PAA::PGAlgorithm pg;
	try {

            std::string fileName = "/home/vagner/workspace/paa_ufmg/src/tp_paradigmas/inputs/inputs.txt";
            this->showUserMessage("Iniciando a execução.");

			instances.load(fileName);
			ss << "Tamanho da instância " << instances.getSize();
			this->showUserMessage(ss.str());

			instances.print();

			//this->showUserMessage("Lista Ordenada");

			//instances.sort();

			//instances.print();

			//greedy = new PAA::GreedyAlgorithm(instances.getSize());

			//solution = greedy->execute(instances);

			pg.execute(instances);


			//solution.print();

			if(solution.isValid()){
				solution.print();
				this->showUserMessage("Resultado escrito no arquivo inputs.txt.");
			}else{
				this->showUserMessage("Não foi encontrada um solução para a instância informada.");
			}


			this->showUserMessage("Finalizando a execução.");

			this->setFinalTime();

			delete greedy;


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
