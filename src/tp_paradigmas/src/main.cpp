/*
 * main.cpp
 *
 *  Created on: 24/01/2015
 *      Author: vagner
 */
#include <iostream>
#include <string>
#include "TPParadigmas.h"
#include "../../lib/PAAException.h"
#include "../../lib/FileManager.h"
#include <cstdlib>
#include "Brain.h"

using namespace std;



int main(int argc, char **argv) {


    try {
    	PAA::TPParadigmas tp (argc,argv);
    	tp.run();
    	//Exibindo os dados da execução
    	tp.showStatistics();
    	exit(EXIT_SUCCESS);
	} catch (const PAA::PAAException& e) {
			e.printDebugMessage();
			exit(EXIT_FAILURE);
	}

}
