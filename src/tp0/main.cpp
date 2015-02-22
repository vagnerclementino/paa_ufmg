/*
 * main.cpp
 *
 *  Created on: 24/01/2015
 *      Author: vagner
 */
#include <iostream>
#include <string>
#include "TP0.h"
#include "../lib/PAAException.h"
#include "../lib/FileManager.h"
#include <cstdlib>

using namespace std;



int main(int argc, char **argv) {


    try {
    	PAA::TP0 tp0;
    	tp0.run();
    	//Exibindo os dados da execução
    	tp0.showStatistics();
    	exit(EXIT_SUCCESS);
	} catch (const PAA::PAAException& e) {
			e.printDebugMessage();
			exit(EXIT_FAILURE);
	}

}
