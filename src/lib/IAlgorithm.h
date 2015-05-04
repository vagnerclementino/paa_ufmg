/*
 * IAlgorithm.h
 *
 *  Created on: 03/05/2015
 *      Author: vagner
 */

#ifndef IALGORITHM_H_
#define IALGORITHM_H_
#include "Solution.h"
#include "Instance.h"

namespace PAA {

template<class T> class IAlgorithm {
protected:
	virtual PAA::Solution<T> execute (PAA::Instance<T>&) = 0;
public:
	IAlgorithm();
	virtual ~IAlgorithm();
};
template<class T> IAlgorithm<T>::IAlgorithm(){

}

template<class T> IAlgorithm<T>::~IAlgorithm(){

}
} /* namespace PAA */

#endif /* IALGORITHM_H_ */
