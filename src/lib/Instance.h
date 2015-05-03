/*
 * Instance.h
 *
 *  Created on: 02/05/2015
 *      Author: vagner
 */

#ifndef INSTANCE_H_
#define INSTANCE_H_
#include <list>

namespace PAA {

template <class T> class Instance {
private:
	int size;
	std::list<T>* instanceList;
protected:
	int getSize();
	void setSize(int);
	void incrementSize(void);
	void decreaseSize(void);
	void addInstanceItem(const T&);
	typename std::list<T>::iterator getBeginList();
	typename std::list<T>::iterator getEndList();
	virtual void load(void) = 0;
	virtual void print(void) = 0;


public:
	Instance();
	virtual ~Instance();
};

template<class T> void Instance<T>::decreaseSize(void){

	if(this->getSize() > 0){
		this->setSize((this->getSize()-1));
	}
}

template<class T> int Instance<T>::getSize(void){

	return this->size;

}

template<class T> void Instance<T>::incrementSize(void){

	this->setSize((this->getSize()+1));
}

template<class T> void Instance<T>::setSize(int newSize){
	this->size = newSize;
}

template<class T> void Instance<T>::addInstanceItem(const T& instanceItem){

	this->instanceList->push_back(instanceItem);
	this->incrementSize();

}

template<class T> typename std::list<T>::iterator Instance<T>::getBeginList(){

	if(!this->instanceList->empty()){
		return this->instanceList->begin();
	}

}
template<class T> typename std::list<T>::iterator Instance<T>:: getEndList(){

	if(!this->instanceList->empty()){
			return this->instanceList->end();
		}
}


template<class T> Instance<T>::Instance() {

	this->instanceList = new std::list<T>();
	this->setSize(0);
}



template<class T> Instance<T>::~Instance() {
	delete this->instanceList;
}



} /* namespace PAA */

#endif /* INSTANCE_H_ */
