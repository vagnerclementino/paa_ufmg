/*
 * FileManager.cpp
 *
 *  Created on: 04/02/2015
 *      Author: vagner
 */

#include "FileManager.h"
#include "PAAException.h"
#include <sys/param.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <locale>
#include <sstream>

namespace PAA {

FileManager::FileManager() {
	this->fileName = std::string();
	this->pFile = NULL;

}

FileManager::FileManager(std::string& fileName, char fileMode){

	std::string fileNameAux;

	if(this->isfullPath(fileName)){

		fileNameAux = fileName;

	}else{

		fileNameAux = this->getCurrentDirectory() + PATHSEPARATOR + fileName;
	}

	this->pFile = NULL;

	this->openFile(fileNameAux,fileMode);


}

FileManager::~FileManager() {
	if(this->pFile != NULL && this->pFile->is_open()){
		this->pFile->close();
		delete this->pFile;
	}
}

std::string FileManager::getCurrentDirectory(void) const {

	char *buffer = new char[MAXPATHLEN];

	getcwd(buffer, MAXPATHLEN);

	if (buffer != NULL) {
		std::string retString(buffer);
		delete[] buffer;
		return retString;
	} else {
		throw PAA::PAAException(
				"Erro no metodo getCurrentDirectory. Nao foi possivel recuperar o diretorio atual.");
	}

	}
std::string FileManager::getFileName(void)const{

	if (!this->fileName.empty()){

		return this->fileName;

	}else{
		throw PAA::PAAException("O nome do arquivo não foi definido.");
	}


}

bool FileManager::isfullPath(std::string& path)const{

	std::size_t found;

	found = path.find_first_of(PATHSEPARATOR, 0);
	if (found == std::string::npos){
		return false;
	}else{
		return true;
	}
}

void FileManager::writeToFile(const std::string& str){

	if(this->pFile == NULL ){

		throw PAA::PAAException("Falha ao escrever no arquivo. O apontador do arquivo é NULL");

	}else if( ! this->pFile->good()){

		throw PAA::PAAException("Falha ao escrever no arquivo " + this->getFileName() + ". O arquivo não está aberto");

	} else{
		//Nenhum erro, a string pode ser escrita.

		*(this->pFile) << str << std::endl;

	 }
}

void FileManager::openFile(const std::string& fileName, char fileMode){


	if (this->pFile == NULL ){

		try {

				switch (std::toupper(fileMode)) {
				case 'A':
					//Append mode
					this->pFile = new std::fstream(fileName.c_str(),
							std::ios::out | std::ios::app);
					break;
				case 'W':
					//Write mode
					this->pFile = new std::fstream(fileName.c_str(), std::ios::out);
					break;
				case 'R':
					//Read Mode
					this->pFile = new std::fstream(fileName.c_str(), std::ios::in);
					break;
				default:
					throw PAAException(
							"O modo informado não existe. Os valores permitidos são A - append, W - write e R - read.");

				}

				if (this->pFile->good()) {

					this->fileName = fileName;

				} else {
					throw std::ios::failure("Erro na abertura do arquivo.");
				}

			} catch (const std::exception& e) {
				throw PAA::PAAException(
						"Erro ao tentar abrir o arquivo " + fileName + ". Detalhes: "
								+ e.what());
			}


	}
	else if (this->pFile->is_open()){
		throw PAA::PAAException("O arquivo " + fileName + " já esta aberto. Nada a ser feito");
	}

}

void FileManager::closeFile(){
	if (this->pFile == NULL){
		throw PAA::PAAException("O arquivo não pode ser fechado. O apontador do arquivo é NULL");

	}else if (!this->pFile->is_open()){
		// O arquivo não está aberto
		throw PAA::PAAException("Falha em fechar o arquivo " + this->getFileName() + ". O arquivo não está aberto!");

	} else {
		try{
			this->pFile->close();
		} catch (const std::ios::failure& e){
			std::stringstream ss;
			ss << "Falha ao fechar o arquivo.  " <<  e.what() << std::endl;
			throw PAA::PAAException(ss.str());
		}
	}
}

bool FileManager::hasMore(void) const{

	return (!this->pFile->eof());

}


std::string FileManager::readLine(void){

	std::string line;

	if (this->pFile == NULL){

		throw PAA::PAAException("Não foi possível ler linha do arquivo. O apontador  é NULL");

	} else 	if(this->pFile->is_open()){


		std::getline(*(this->pFile), line);
		return line;

	} else{

		throw PAA::PAAException("O arquivo " + this->getFileName() + " não está aberto");
	}
}
}/* namespace PAA */
