#include "Admin.h"
#include <fstream>
#include <cstring>
#include <cctype>

Admin::Admin(long fecha, std::string tipo, std::string asunto, long monto) {
	this->fecha = fecha;
	this->tipo = tipo;
	this->asunto = asunto;
	this->monto = monto;
}

void Admin::GuardarEnBinario(std::ofstream &archivo) {
	compras com;
	com.fecha = fecha;
	strcpy(com.tipo,tipo.c_str());
	strcpy(com.asunto,asunto.c_str());
	com.monto = monto;
	
	archivo.write((char*)&com,sizeof(com));
}

void Admin::LeerDesdeBinario(std::ifstream &archivo) {
	compras com;
	archivo.read((char*)&com,sizeof(com));
	fecha = com.fecha;
	tipo = com.tipo;
	asunto = com.asunto;
	monto = com.monto;
}

std::string Admin::ValidarDatos() {
	std::string errores;
	if (asunto.size()>256) errores+="El asunto es demasiado largo\n";
	return errores;
}

long Admin::VerFecha() const{
	return fecha;
}

std::string Admin::VerTipo() const{
	return tipo;
}

std::string Admin::VerAsunto() const{
	return asunto;
}

long Admin::VerMonto() const{
	return monto;
}

bool comparar_fecha(const Admin &a1, const Admin &a2){
	long f1 = a1.VerFecha();
	long f2 = a2.VerFecha();
	return f1<f2;
}

bool comparar_tipo(const Admin &a1, const Admin &a2){
	std::string t1 = a1.VerTipo();
	for (size_t i=0;i<t1.size();i++)
		t1[i]=std::tolower(t1[i]);
	
	std::string t2 = a2.VerTipo();
	for (size_t i=0;i<t2.size();i++)
		t2[i]=std::tolower(t2[i]);
	
	return t1<t2;
}
