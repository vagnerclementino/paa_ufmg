/*
 * Brain.h
 *
 *  Created on: 04/05/2015
 *      Author: vagner
 */

#ifndef BRAIN_H_
#define BRAIN_H_

namespace PAA {

class Brain {
private:
	int id; 	//Identificador único para o Cerébro.
	int weight; //Peso do Cérebro
	int qi;		//QI do cérebro
public:
	int getID(void);
	void setID(int);
	int getWeight(void);
	void setWeight(int);
	int getQI(void);
	void setQI(int);
	int getCost(void);
	void print (void);



	Brain(int, int, int);
	virtual ~Brain();
};

} /* namespace PAA */

#endif /* BRAIN_H_ */
