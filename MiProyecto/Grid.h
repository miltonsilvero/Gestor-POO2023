#ifndef GRID_H
#define GRID_H
#include <string>
#include <vector>
#include "Admin.h"

enum CriterioOrden { FECHA, TIPO_TRANSACCION };

class Grid {
private:
	std::string nombreBin;
	std::string nombreTxt;
	std::vector<Admin> grid;
public:
	Grid(std::string archivobin, std::string archivotxt);
	bool Guardar();
	void AgregarCompra(const Admin &a);
	void EliminarCompra(int i);
	int CantidadDatos();
	long int MontoTotal();
	Admin &VerGasto(int i);
	void ExportarTxt(Admin &a);
	void Ordenar(CriterioOrden criterio);
	std::tuple<int,int,int> TotalesGlobales();
	bool EsAdmin(const std::string& nombreUsuario);
};

#endif

