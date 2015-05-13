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
#include "FBSolution.h"
#include "FBAlgorithm.h"
#include "PDAlgorithm.h"
#include "GreedyAlgorithm.h"
#include <algorithm>
#include <ctype.h>

namespace PAA {

TPParadigmas::TPParadigmas(int numArgs, char ** args):TrabalhoPratico(numArgs, args) {
	//Chamando o construtor da classe Pai(TrabalhoPratico)
	std::stringstream ss;
	if(numArgs == NUMBER_OF_ARGUMENTS){

		this->pArgs = new std::vector<std::string> (args, args + numArgs);
		this->loadMapParadigms();

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
	PAA::TPSolution solution;
	PAA::TPInstance instances;
	PAA::FBAlgorithm* fb = NULL;
	PAA::GreedyAlgorithm* greedy = NULL;
	PAA::PDAlgorithm* pd = NULL;
	try {

            std::string inputFile = this->getInputFilePath();
            std::string outputFile = this->getOutputFilePath();
            std::string paradigmType = this->getParadigmType();

            this->showUserMessage("Iniciando a execução.");

			instances.load(inputFile);
			ss << "Tamanho da instância " << instances.getSize();
			this->showUserMessage(ss.str());
			ss.str(std::string());

			switch (this->getParadigm(paradigmType)) {
				case FORCE_BRUTE:
					this->showUserMessage("Iniciando a execução do algoritmo de força bruta");

					fb = new PAA::FBAlgorithm();

					solution = fb->execute(instances);
					break;

				case GREEDY:
					this->showUserMessage("Iniciando a execução do algoritmo guloso");
					greedy = new PAA::GreedyAlgorithm(instances.getSize());
					solution = greedy->execute(instances);
					break;

				case PROG_DINAMIC:
					this->showUserMessage("Iniciando a execução do algoritmo de programação dinâmica");
					pd = new PAA::PDAlgorithm();
				    solution = pd->execute(instances);
				    break;
				default:
					throw PAA::PAAException("O tipo de paradigma informado não existe.");
			 }

			if (solution.isValid()) {
				solution.setOutputFile(outputFile);
				solution.print();
				ss << "Resultado escrito no arquivo " << outputFile << std::endl;
				this->showUserMessage(ss.str());
				ss.str(std::string());
			} else {
				this->showUserMessage("Não foi encontrada um solução para a instância informada.");
			}

			this->showUserMessage("Finalizando a execução.");

			this->setFinalTime();

			if(greedy != NULL){
				delete greedy;
			}
			if(fb != NULL){
				delete fb;
			}
			if(pd != NULL){
				delete pd;
			}


	} catch (const PAA::PAAException& e) {

		ss << "Erro durante a execução do programa: Detalhes: " << e.getDebugMessage() << std::endl;
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
	return this->pArgs->at(INPUT_FILE_NAME_POSITION);
}

std::string TPParadigmas::getOutputFilePath(void){

	return this->pArgs->at(OUTPUT_FILE_NAME_POSITION);
}

std::string TPParadigmas::getParadigmType(){

	return this->pArgs->at(PARADIGM_TYPE_POSITION);
}

void TPParadigmas::loadMapParadigms(void){

	this->mapAlgorithms["fb"] = FORCE_BRUTE;
	this->mapAlgorithms["greedy"] = GREEDY;
	this->mapAlgorithms["pd"] = PROG_DINAMIC;

}
int TPParadigmas::getParadigm(std::string& key){

	std::string lowerString = key;
	std::transform(lowerString.begin(), lowerString.end(), lowerString.begin(), ::tolower);
	return mapAlgorithms[lowerString];

}

} /* namespace PAA */
