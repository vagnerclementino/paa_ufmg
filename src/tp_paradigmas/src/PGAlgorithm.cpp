/*
 * PGAlgorithm.cpp
 *
 *  Created on: 10/05/2015
 *      Author: vagner
 */

#include "PGAlgorithm.h"
#include <iostream>
#include <sstream>

namespace PAA {

PGAlgorithm::PGAlgorithm() {
	// TODO Auto-generated constructor stub

}

PGAlgorithm::~PGAlgorithm() {
	// TODO Auto-generated destructor stub
}

/*PAA::TPSolution*/ void PGAlgorithm::execute(PAA::TPInstance& instances){

	PAA::TPSolution pgSolution;
	int maxLength = 1, bestEnd = 0;
	int instanceLenght = instances.getSize();
	std::vector<int> DP(instanceLenght);
	std::stringstream ss;
	std::vector<TPSolution> solutions (instanceLenght);

	DP[0] = 1;
	solutions.at(0).addToSolution(instances.getInstanceItem(0));

	for (int i = 1; i < instanceLenght; i++)
	{
	   DP[i] = 1;
	   solutions.at(i).addToSolution(instances.getInstanceItem(i));

	   for (int j = i - 1; j >= 0; j--){
	      if (DP[j] + 1 > DP[i] && (instances.getInstanceItem(i) > instances.getInstanceItem(j)))
	      {
	         DP[j] = DP[i] + 1;
	         solutions.at(i) += solutions.at(j);
	         std::cout << solutions.at(i).getCost() << std::endl;
	         solutions.at(i).print();
	      }
	   }
	   if (  solutions.at(i).getCost() > maxLength)
	   {
	      bestEnd = i;
	      maxLength =   solutions.at(i).getCost();
	   }
	}

	ss << "[";

	for(int k=0; k < instanceLenght; k++){

		ss << DP.at(k) << ",";

	}

	ss.seekp(ss.str().length()-1);

	ss << "]";

	std::cout << ss.str() << std::endl;


	solutions.at(bestEnd).print();
	//return pgSolution;

}

} /* namespace PAA */
