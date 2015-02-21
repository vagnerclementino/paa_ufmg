/*
 * PAAException.cpp
 *
 *  Created on: 02/02/2015
 *      Author: vagner
 */

#include "PAAException.h"
#include <iostream>
#include <sstream>

namespace PAA {

PAAException::PAAException():exception() {
	// TODO Auto-generated constructor stub

}

PAAException::PAAException (const std::string& eMessage)

 {

	this->errorMessage = eMessage;

}

void PAAException::printDebugMessage(void)const{



	std::cerr << this->errorMessage << ". Detalhes: " << exception::what() << std::endl;



}

PAAException::~PAAException() throw(){


}

} /* namespace PAA */
