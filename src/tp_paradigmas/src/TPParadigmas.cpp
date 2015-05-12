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
#include "PDAlgorithm.h"
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
	PAA::PDAlgorithm pd;
	try {

            std::string fileName = "/home/vagner/workspace/paa_ufmg/src/tp_paradigmas/inputs/inputs.txt";
            this->showUserMessage("Iniciando a execução.");

			instances.load(fileName);
			ss << "Tamanho da instância " << instances.getSize();
			this->showUserMessage(ss.str());

			solution = fb.execute(instances);

			greedy = new PAA::GreedyAlgorithm(instances.getSize());

			solution = greedy->execute(instances);

			solution.print();

			if (solution.isValid()) {
				solution.print();
				this->showUserMessage("Resultado escrito no arquivo inputs.txt.");
			} else {
				this->showUserMessage("Não foi encontrada um solução para a instância informada.");
			}

			solution = pd.execute(instances);

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

int TPParadigmas::getNumberOfArgs(void){

	return PAA::TrabalhoPratico::getArgc();
}

std::vector<std::string> TPParadigmas::getStingOfArgs(void){

	char** tempArgv = PAA::TrabalhoPratico::getArgv();
	int tempArgc = PAA::TrabalhoPratico::getArgc();

	std::vector<std::string> argList(tempArgc);
	for(int i=0;i<tempArgc;i++){
		argList.push_back(tempArgv[i]);
	}

    return argList;
}

std::string TPParadigmas::getInputFilePath(void){
	return this->getStingOfArgs().at(INPUT_FILE_NAME_POSITION);
}

std::string TPParadigmas::getOutputFilePath(void){

	return this->getStingOfArgs().at(OUTPUT_FILE_NAME_POSITION);
}

std::string TPParadigmas::getParadigmType(){

	return this->getStingOfArgs().at(PARADIGM_TYPE_POSITION);
}

} /* namespace PAA */
