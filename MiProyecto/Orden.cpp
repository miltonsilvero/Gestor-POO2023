#include "Orden.h"
#include <fstream>
#include <cstring>
#include <cctype>

Orden::Orden(long fecha, std::string tipo, std::string asunto, long monto) {
	this->fecha = fecha;
	this->tipo = tipo;
	this->asunto = asunto;
	this->monto = monto;
}

void Orden::GuardarEnBinario(std::ofstream &archivo) {
	compras com;
	com.fecha = fecha;
	strcpy(com.tipo,tipo.c_str());
	strcpy(com.asunto,asunto.c_str());
	com.monto = monto;
	
	archivo.write((char*)&com,sizeof(com));
}

void Orden::LeerDesdeBinario(std::ifstream &archivo) {
	compras com;
	archivo.read((char*)&com,sizeof(com));
	fecha = com.fecha;
	tipo = com.tipo;
	asunto = com.asunto;
	monto = com.monto;
}

std::string Orden::ValidarDatos() {
	std::string errores;
	if (asunto.size()>256) errores+="El asunto es demasiado largo\n";
	return errores;
}

long Orden::VerFecha() const{
	return fecha;
}

std::string Orden::VerTipo() const{
	return tipo;
}

std::string Orden::VerAsunto() const{
	return asunto;
}

long Orden::VerMonto() const{
	return monto;
}

bool comparar_fecha(const Orden &a1, const Orden &a2){
	long f1 = a1.VerFecha();
	long f2 = a2.VerFecha();
	return f1<f2;
}

bool comparar_tipo(const Orden &a1, const Orden &a2){
	std::string t1 = a1.VerTipo();
	for (size_t i=0;i<t1.size();i++)
		t1[i]=std::tolower(t1[i]);
	
	std::string t2 = a2.VerTipo();
	for (size_t i=0;i<t2.size();i++)
		t2[i]=std::tolower(t2[i]);
	
	return t1<t2;
}
