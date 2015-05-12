/*
 * TPSolution.h
 *
 *  Created on: 07/05/2015
 *      Author: vagner
 */

#ifndef TPSOLUTION_H_
#define TPSOLUTION_H_
#include "Brain.h"
#include "../../lib/Solution.h"
#include <string>
#include "../../lib/FileManager.h"

namespace PAA {

class TPSolution: public Solution<PAA::Brain> {
private:
	PAA::FileManager* fm;
public:
	TPSolution();
	virtual ~TPSolution();
	void print(void);
	int getCost(void);
	void addToSolution(const PAA::Brain&);
	bool isValid(void);
	void setIsValid(bool);
	bool isEmpty(void);
	bool isItValidated(void);
	void setWasValidated(bool);
	bool operator>(TPSolution&);
	PAA::Brain getLastItem(void);
	void setCost(int);
	void validateSolution(void);
	void operator+=(Solution<PAA::Brain>&);
	void clear (void);
	void reverse(void);
	void setOutputFile(std::string&);

};

} /* namespace PAA */

#endif /* TPSOLUTION_H_ */
