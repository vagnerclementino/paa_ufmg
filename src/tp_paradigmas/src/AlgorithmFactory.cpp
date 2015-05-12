/*
 * AlgorithmFactory.cpp
 *
 *  Created on: 12/05/2015
 *      Author: vagner
 */

#include "AlgorithmFactory.h"
#include <locale>
#include <iostream>
#include "../../lib/PAAException.h"
#include "FBAlgorithm.h"
#include "PDAlgorithm.h"
#include "GreedyAlgorithm.h"
#include "TPAlgorithms.h"

namespace PAA {

AlgorithmFactory::AlgorithmFactory() {

}

AlgorithmFactory::~AlgorithmFactory() {
	// TODO Auto-generated destructor stub
}

void AlgorithmFactory::load (void){
	mapAlgorithms["fb"] = FB;
	mapAlgorithms["greedy"] = GREEDY;
	mapAlgorithms["pg"] = PD;

	this->wasLoaded = true;
}

int AlgorithmFactory::getAlgorithm(std::string& key){
	std::string lowerString;
	std::locale loc;

	for (std::string::size_type i=0; i<key.length(); ++i){

		lowerString[i] = std::tolower(key[i],loc);

	  }

	return mapAlgorithms[lowerString];
}

PAA::TPAlgorithms  AlgorithmFactory::create(std::string& algorithType, int instanceLength){

	if(!wasLoaded){

		load();
	}

	load();

	switch( this->getAlgorithm(algorithType))
	    {
	    case FB:
			std::cout  << "Force Brute!";
			return PAA::FBAlgorithm();
	    	break;
	    case GREEDY:
			std::cout  << "Greedy!";
			return PAA::GreedyAlgorithm(instanceLength);
	    	break;
	    case PD:
	        std::cout << "Programação Dinâmica!";
	        return PAA::PDAlgorithm();
	        break;
	    default:
	    	throw PAA::PAAException("O tipo de paradigma informado não existe.");
	    }

}


} /* namespace PAA */
