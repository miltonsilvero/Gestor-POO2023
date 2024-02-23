#ifndef ORDEN_H
#define ORDEN_H
#include <vector>
#include <string>

/***
Clase dedicada a almacenar los datos de cada orden ejecutada de compra y venta.
***/

struct compras{
	int fecha;
	char tipo[256];
	char asunto[256];
	int monto;
};

class Orden {
private:
	long fecha;
	std::string tipo;
	std::string asunto;
	long monto;
public:
	Orden(long fecha=0,std::string tipo="", std::string asunto="", long monto=0);
	void GuardarEnBinario(std::ofstream &archivo);
	void LeerDesdeBinario(std::ifstream &archivo);
	std::string ValidarDatos();
	void ExportarTXT(std::ofstream );
	
	long VerFecha() const;
	std::string VerTipo() const;
	std::string VerAsunto() const;
	long VerMonto() const;
	
	
};
	
	bool comparar_fecha(const Orden &a1, const Orden &a2);
	bool comparar_tipo(const Orden &a1, const Orden &a2);
#endif

