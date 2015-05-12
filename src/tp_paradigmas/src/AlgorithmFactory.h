/*
 * AlgorithmFactory.h
 *
 *  Created on: 12/05/2015
 *      Author: vagner
 */

#ifndef ALGORITHMFACTORY_H_
#define ALGORITHMFACTORY_H_
#include <string>
#include <map>
#include "TPAlgorithms.h"
namespace PAA {

class AlgorithmFactory {
private:
	bool wasLoaded;
	enum algorithms{
		FB = 1,
		GREEDY = 2,
		PD	= 3
	};

   std::map<std::string, algorithms> mapAlgorithms;
   void load (void);
   int getAlgorithm(std::string&);
public:
	AlgorithmFactory();
	virtual ~AlgorithmFactory();
	PAA::TPAlgorithms create(std::string&, int);

};

} /* namespace PAA */

#endif /* ALGORITHMFACTORY_H_ */
