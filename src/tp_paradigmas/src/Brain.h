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
	int getID(void) const;
	void setID(int);
	int getWeight(void) const;
	void setWeight(int);
	int getQI(void) const;
	void setQI(int);
	int getCost(void) const;
	void print (void);
    bool operator > (const Brain&) ;
    bool operator<(const PAA::Brain&);
    bool operator == (const Brain&) ;
    bool operator != (const Brain&) ;



	Brain(int, int, int);
	Brain();
	virtual ~Brain();
};

} /* namespace PAA */

#endif /* BRAIN_H_ */
