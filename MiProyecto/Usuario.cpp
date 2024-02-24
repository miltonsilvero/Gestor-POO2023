#include "Usuario.h"
#include <cstring>
#include <fstream>
#include <iostream>
#include "Grid.h"


Usuario::Usuario() {
	Cargar();
}

void Usuario::AgregarUsuario(const Persona &p) {
	lista_usuarios.push_back(p);
	Guardar();
}

void Usuario::Cargar(){
	std::ifstream archivobin(nombreLista.c_str(),std::ios::binary|std::ios::ate);
	if(archivobin.is_open()){
		int archivoSize = archivobin.tellg();
		int cantUser = archivoSize/sizeof(User);
		lista_usuarios.resize(cantUser);
		archivobin.seekg(0,std::ios::beg);
		for(int i=0;i<cantUser;i++){
			lista_usuarios[i].LeerDesdeBinario(archivobin);
		}
		archivobin.close();
	}
	
}

bool Usuario::BuscarUsuario(const Persona &p) {
	Cargar();
	if(lista_usuarios.size() > 0){
		for (size_t i=0;i<lista_usuarios.size();i++) {
			if (lista_usuarios[i].VerName() == p.VerName() && lista_usuarios[i].VerPassword() == p.VerPassword()) {
				std::cout << "TRUE" << std::endl;
				nombreArchi = p.VerName() + "Grid.dat";
				return true;
			}
		}
	}
	return false;
}

bool Usuario::Registrado(const Persona &p) {
	Cargar();
	if(lista_usuarios.size() > 0){
		for (size_t i=0;i<lista_usuarios.size();i++) {
			if (lista_usuarios[i].VerName() == p.VerName()) {
				nombreArchi = p.VerName() + "Grid.dat";
				return true;
			}
		}
	}
	return false;
}

void Usuario::Guardar(){
	std::ofstream archivobin(nombreLista.c_str(),std::ios::binary|std::ios::trunc);
	if(archivobin.is_open()){
		int cantUser = CantidadDatos();
		for(int i=0;i<cantUser;i++){
			lista_usuarios[i].GuardarEnBinario(archivobin);
		}
		archivobin.close();
	}
}

int Usuario::CantidadDatos(){
	return lista_usuarios.size();
}

std::string Usuario::NombreArchivo(){
	return nombreArchi;
}

std::vector<Persona> Usuario::usuarios(){
	return lista_usuarios;
}

void Usuario::BorrarUsuario(int i){
	lista_usuarios.erase(lista_usuarios.begin()+i);
	std::string nomBin = lista_usuarios[i].VerName() + "Grid.dat";
	std::string nomTxt = lista_usuarios[i].VerName() + "Hist.txt";
	Grid *grid = new Grid(nomBin,nomTxt);
	grid->LimpiarGrid();
	grid->Guardar(true);
}
