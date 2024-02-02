#ifndef ADMIN_H
#define ADMIN_H
#include <vector>
#include <string>

struct compras{
	long fecha;
	char tipo[256];
	char asunto[256];
	long monto;
};

class Admin {
private:
	long fecha;
	std::string tipo;
	std::string asunto;
	long monto;
public:
	Admin(long fecha=0,std::string tipo="", std::string asunto="", long monto=0);
	void GuardarEnBinario(std::ofstream &archivo);
	void LeerDesdeBinario(std::ifstream &archivo);
	std::string ValidarDatos();
	void ExportarTXT(std::ofstream );
	
	long VerFecha() const;
	std::string VerTipo() const;
	std::string VerAsunto() const;
	long VerMonto() const;
	
	
};
	
	bool comparar_fecha(const Admin &a1, const Admin &a2);
	bool comparar_tipo(const Admin &a1, const Admin &a2);
#endif

