/*
 * Soluction.h
 *
 *  Created on: 03/05/2015
 *      Author: vagner
 */

#ifndef SOLUCTION_H_
#define SOLUCTION_H_

#include <list>

namespace PAA {

template <class T> class Solution {
private:
	int cost;
	bool isValidSolution;
	std::list<T> solutionList;
protected:
	void setCost(int);
	int getCost(void);
	void addSolutionItem(const T&);
	bool isValid(void);
	bool isEmpty(void);
	void setIsValid(bool);
	typename std::list<T>::iterator getBeginList();
	typename std::list<T>::iterator getEndList();
	void calculeCost(const T&);

	virtual void validateSolution(void) = 0;
	virtual void print(void) = 0;
public:
	Solution();
	virtual ~Solution();
};

template<class T> void Solution<T>::calculeCost(const T& solutionItem){

	int previousCost = this->getCost();

	int newCost = previousCost + solutionItem.getCost();

	this->setCost(newCost);

}
template<class T> int Solution<T>::getCost(){

	return this->cost;

}

template<class T> void Solution<T>::setCost(int newCost){

	this->cost = newCost;

}

template<class T> void Solution<T>::addSolutionItem(const T& solutionItem){
	this->solutionList.push_back(solutionItem);
}

template<class T> bool Solution<T>::isValid(void){

	return this->isValidSolution;

}

template<class T> void Solution<T>::setIsValid(bool newIsValid){

	this->isValidSolution = newIsValid;

}

template<class T> typename std::list<T>::iterator Solution<T>::getBeginList(){

	if(!this->solutionList.empty()){
		return this->solutionList.begin();
	}

}

template<class T> typename std::list<T>::iterator Solution<T>::getEndList(){

	if(!this->solutionList.empty()){
			return this->solutionList.end();
		}
}

template<class T> bool Solution<T>::isEmpty(void){
	return this->solutionList.empty();
}


template<class T> Solution<T>::Solution(){
	this->solutionList = std::list<T> ();
	this->setCost(0);
	this->setIsValid(false);
}

template<class T> Solution<T>::~Solution(){
	//Do nothing
}

} /* namespace PAA */

#endif /* SOLUCTION_H_ */
