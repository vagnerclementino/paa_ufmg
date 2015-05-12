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
	std::stringstream ss;
	if(numArgs == NUMBER_OF_ARGUMENTS){

		this->pArgs = new std::vector<std::string> (args, args + numArgs);


	}else{
		ss << "O numero de argumentos informado: "<< numArgs << " não é valido" << std::endl;
		throw PAA::PAAException(ss.str());

	}
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

            std::string inputFile = this->getInputFilePath();
            this->showUserMessage(inputFile);
            std::string outputFile = this->getOutputFilePath();
            this->showUserMessage("Iniciando a execução.");

			instances.load(inputFile);
			ss << "Tamanho da instância " << instances.getSize();
			this->showUserMessage(ss.str());
			ss.str(std::string());



			//solution = fb.execute(instances);

			greedy = new PAA::GreedyAlgorithm(instances.getSize());

			solution = greedy->execute(instances);

			if (solution.isValid()) {
				solution.setOutputFile(outputFile);
				solution.print();
				ss << "Resultado escrito no arquivo " << outputFile << std::endl;
				this->showUserMessage(ss.str());
				ss.str(std::string());
			} else {
				this->showUserMessage("Não foi encontrada um solução para a instância informada.");
			}



			solution = pd.execute(instances);

			if(solution.isValid()){
				solution.setOutputFile(outputFile);
				solution.print();
				ss << "Resultado escrito no arquivo " << outputFile << std::endl;
				this->showUserMessage(ss.str());
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


std::string TPParadigmas::getInputFilePath(void){
	std::cout <<this->pArgs->at(INPUT_FILE_NAME_POSITION) << std::endl;
	return this->pArgs->at(INPUT_FILE_NAME_POSITION);
}

std::string TPParadigmas::getOutputFilePath(void){

	return this->pArgs->at(OUTPUT_FILE_NAME_POSITION);
}

std::string TPParadigmas::getParadigmType(){

	return this->pArgs->at(PARADIGM_TYPE_POSITION);
}

} /* namespace PAA */
