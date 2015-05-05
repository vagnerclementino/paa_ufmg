/*
 * FBSolution.h
 *
 *  Created on: 05/05/2015
 *      Author: vagner
 */

#ifndef FBSOLUTION_H_
#define FBSOLUTION_H_

class FBSolution: public PAA::Solution<PAA::Brain> {
public:
	FBSolution();
	virtual ~FBSolution();
	void validateSolution(void);
	void print(void);
	int getCost(void);
	void addToSolution(const PAA::Brain&);
	bool isValid(void);
	bool isEmpty(void);
	bool operator>(FBSolution&);
};

#endif /* FBSOLUTION_H_ */
