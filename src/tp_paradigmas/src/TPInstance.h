/*
 * TPInstance.h
 *
 *  Created on: 04/05/2015
 *      Author: vagner
 */

#ifndef TPINSTANCE_H_
#define TPINSTANCE_H_
#include <string>
#include "Brain.h"
#include "../../lib/Instance.h"
#include "../../lib/FileManager.h"
#include <vector>

namespace PAA {

class TPInstance: public Instance<PAA::Brain> {
private:
	PAA::FileManager* fm;
	int lastIntanceID; //Ultimo ID atribuido a alguma instancia
	std::vector<std::string> splitString(const char* , char);
	void setLastInstanceID(int);
	int getInstanceID(void);




public:
	TPInstance();
	virtual ~TPInstance();
	void load(std::string&);
	void print (void);
	//Retorna o nome do qual as instancias do Tabalho serão lidas
	std::string getInstanceFileName();
	int getSize(void);
	PAA::Brain getInstanceItem(int);
	bool hasMore(void);
	PAA::Brain getNextBrain();
	std::vector<int> getIdList();
};

} /* namespace PAA */

#endif /* TPINSTANCE_H_ */
