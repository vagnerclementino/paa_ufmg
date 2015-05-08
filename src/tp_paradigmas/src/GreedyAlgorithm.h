/*
 * GreedyAlgorithm.h
 *
 *  Created on: 07/05/2015
 *      Author: vagner
 */

#ifndef GREEDYALGORITHM_H_
#define GREEDYALGORITHM_H_
#include "Brain.h"
#include "TPSolution.h"
#include "TPInstance.h"

namespace PAA {

class GreedyAlgorithm {

private:
	std::vector<PAA::TPSolution*> *pSolutionPile;
	int nextFreePile; 		//Armazena a próxima pilha a ser preenchida
	int maxSequenceLength;	//A maior sequeência encontrada até o momento
	int bestSolution;		//Indice da pilha com a melhor solução até o momento.
	int maxOfPiles;			//O número máximo de pilhas a ser criado. Geralmente igual ao tamanha da instância.
protected:

   int greedyChoice(PAA::TPInstance&);
   void initialize();
   int getNextFreePile(void);
   void setNextFreePile(int);
   int getMaxSequenceLength(void);
   void setMaxSequenceLength(int);
   int getBestSolution(void);
   void setBestSolution(int);




public:
	GreedyAlgorithm();
	virtual ~GreedyAlgorithm();
	PAA::TPSolution execute(PAA::TPInstance&);
};

} /* namespace PAA */

#endif /* GREEDYALGORITHM_H_ */
