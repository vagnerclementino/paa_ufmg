/*
 * PAAException.h
 *
 *  Created on: 02/02/2015
 *      Author: vagner
 */

#ifndef PAAEXCEPTION_H_
#define PAAEXCEPTION_H_

#include <exception>
#include <string>

namespace PAA {

class PAAException: public std::exception {
private:
	std::string errorMessage;
	std::exception raisedException;



public:
	PAAException();
	PAAException (const std::string&, const std::exception&);
	PAAException (const std::string&);
	void printDebugMessage(void) const ;
	~PAAException() throw();
};

} /* namespace PAA */

#endif /* PAAEXCEPTION_H_ */
