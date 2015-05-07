/*
 * FBSolution.h
 *
 *  Created on: 05/05/2015
 *      Author: vagner
 */

#ifndef FBSOLUTION_H_
#define FBSOLUTION_H_
#include "Brain.h"
#include "../../lib/Solution.h"

namespace PAA {

class FBSolution: public PAA::Solution<Brain>{
public:
	FBSolution();
	virtual ~FBSolution();

	void print(void);
	int getCost(void);
	void addToSolution(const PAA::Brain&);
	bool isValid(void);
	void setIsValid(bool);
	bool isEmpty(void);
	bool isItValidated(void);
	bool operator>(FBSolution&);
	void setCost(int);
private:
	void validateSolution(void);

};
} /* namespace PAA */

#endif /* FBSOLUTION_H_ */
