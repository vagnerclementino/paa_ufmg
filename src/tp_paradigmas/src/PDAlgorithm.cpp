/*
 * PGAlgorithm.cpp
 *
 *  Created on: 10/05/2015
 *      Author: vagner
 */

#include "PDAlgorithm.h"
#include <iostream>
#include <sstream>
#include <stack>
#include <limits>

namespace PAA {

PDAlgorithm::PDAlgorithm() {
	// TODO Auto-generated constructor stub

}

PDAlgorithm::~PDAlgorithm() {
	// TODO Auto-generated destructor stub
}

PAA::TPSolution PDAlgorithm::execute(PAA::TPInstance& instances){


	TPSolution pgSolution;
	int bestEnd = 0;
	int size = instances.getSize();
	int current;
	std::vector<int> prev(size, -1);
	std::vector<int> memo(size, 0);

	int maxLength = std::numeric_limits<int>::min();

	instances.sort();

	memo[0] = 1;

	for (int i = 1; i < size; ++i) {
		for (int j = 0; j < i; ++j) {
			if (instances.getInstanceItem(j).getQI() < instances.getInstanceItem(i).getQI() && memo[i] < memo[j] + 1) {
				memo[i] = memo[j] + 1;
				prev[i] = j;

			}
		}

		if (memo[i] > maxLength) {
			bestEnd = i;
			maxLength = memo[i];
		}
	}

	//Construindo a solução
	current = bestEnd;

	while (current != -1) {
		pgSolution.addToSolution(instances.getInstanceItem(current));

		current = prev[current];
	}

	return pgSolution;

}

} /* namespace PAA */
