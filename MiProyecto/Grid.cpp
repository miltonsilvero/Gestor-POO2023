#include "Grid.h"
#include <fstream>
#include <algorithm>
#include <string>
#include "Orden.h"
#include <iostream>
#include <tuple>

Grid::Grid(std::string nombreBin, std::string nombreTxt) {
	this->nombreBin = nombreBin;
	this->nombreTxt = nombreTxt;
	std::ifstream archivobin(nombreBin.c_str(),std::ios::binary|std::ios::ate);
	if(archivobin.is_open()){
		std::cout << "Se creó el archivo." << std::endl;
		int archivoSize = archivobin.tellg();
		int cantCompras = archivoSize/sizeof(compras);
		grid.resize(cantCompras);
		archivobin.seekg(0,std::ios::beg);
		for(int i=0;i<cantCompras;i++){
			grid[i].LeerDesdeBinario(archivobin);
		}
		archivobin.close();
	}
}

bool Grid::Guardar(bool borrar){
	std::ofstream archivobin(nombreBin.c_str(),std::ios::binary|std::ios::trunc);
	if(!archivobin.is_open()){
		return false;
	}
	
	if(nombreBin != "adminGrid.dat"){
		long ultFecha = 0;
		if(grid.size()>0){
			for(size_t i=0;i<grid.size();i++){
				if(grid[i].VerFecha() > ultFecha){
					ultFecha = grid[i].VerFecha();
				}
			}
		}
		if(!borrar){
			Orden total(ultFecha,"------","BALANCE: ",MontoTotal());
			grid.push_back(total);
		}
	}
	
	int cantCompras = CantidadDatos();
	if(cantCompras>0){
		for(int i=0;i<cantCompras;i++){
			grid[i].GuardarEnBinario(archivobin);
		}
	}
	archivobin.close();
	return true;
}

void Grid::AgregarCompra(const Orden &a){
	if(nombreBin != "adminGrid.dat"){
		if (!grid.empty()) grid.erase(grid.end()-1);
		grid.push_back(a);
	}else{
		grid.push_back(a);
	}
}

void Grid::EliminarCompra(int i){
	if (!grid.empty()) grid.erase(grid.end()-1);
	grid.erase(grid.begin()+i);
}

int Grid::CantidadDatos() {
	return grid.size();
}

int Grid::MontoTotal(){
	int suma = 0;
	for(size_t i=0;i<grid.size();i++){
		if(grid[i].VerAsunto() != "BALANCE: "){
			if(grid[i].VerTipo() == "Egreso"){
				suma-=grid[i].VerMonto();
			}
			else suma+=grid[i].VerMonto();
		}
		
	}
	return suma;
}

Orden &Grid::VerGasto(int i) {
	return grid[i];
}

void Grid::ExportarTxt(Orden &a){
	std::ofstream Archivo(nombreTxt,std::ios::trunc);
	
	Archivo << nombreTxt << std::endl;
	Archivo << std::endl;
	Archivo << "HISTORIAL DE GASTOS" << std::endl;
	
	for(size_t i=0;i<grid.size();i++){
		Archivo << grid[i].VerFecha() << "  " << grid[i].VerTipo() << "  " << grid[i].VerAsunto() << "  " << grid[i].VerMonto() << std::endl;
	}
	Archivo.close();
}

void Grid::Ordenar(CriterioOrden criterio) {
	grid.erase(grid.end()-1);
	switch (criterio) {
	case FECHA: 
		sort(grid.begin(),grid.end(),comparar_fecha); 
		break;
	case TIPO_TRANSACCION: 
		sort(grid.begin(),grid.end(),comparar_tipo); 
		break;
	case ASUNTO:
		sort(grid.begin(),grid.end(),comparar_asunto);
		break;
	case MONTO:
		sort(grid.begin(),grid.end(),comparar_monto);
		break;
	};
	long ultFecha = 0;
	for(size_t i=0;i<grid.size();i++){
		if(grid[i].VerFecha() > ultFecha){
			ultFecha = grid[i].VerFecha();
		}
	}
	
	Orden total(ultFecha,"------","BALANCE: ",MontoTotal());
	grid.push_back(total);
}

void Grid::LimpiarGrid(){
	grid.clear();
}
