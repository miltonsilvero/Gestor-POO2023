#include "Persona.h"
#include <cstring>
#include <fstream>
using namespace std;

Persona::Persona(std::string name, std::string password){
	this->name = name;
	this->password = password;
	this->archi = name + "Grid.dat";
}


void Persona::GuardarEnBinario(std::ofstream &archivo) {
	User u;
	strcpy(u.name,name.c_str());
	strcpy(u.password,password.c_str());
	strcpy(u.archi,archi.c_str());
	
	archivo.write((char*)&u,sizeof(u));
}

void Persona::LeerDesdeBinario(std::ifstream &archivo) {
	User u;
	archivo.read((char*)&u,sizeof(u));
	name = u.name;
	password = u.password;
	archi = u.archi;
}

std::string Persona::VerName() const{
	return name;
}

std::string Persona::VerPassword() const{
	return password;
}

std::string Persona::VerArchi() const{
	return archi;
}
