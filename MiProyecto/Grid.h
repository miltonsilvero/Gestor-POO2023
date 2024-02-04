#ifndef GRID_H
#define GRID_H
#include <string>
#include <vector>
#include "Orden.h"

enum CriterioOrden { FECHA, TIPO_TRANSACCION };

class Grid {
private:
	std::string nombreBin;
	std::string nombreTxt;
	std::vector<Orden> grid;
public:
	Grid(std::string archivobin, std::string archivotxt);
	bool Guardar();
	void AgregarCompra(const Orden &a);
	void EliminarCompra(int i);
	int CantidadDatos();
	long int MontoTotal();
	Orden &VerGasto(int i);
	void ExportarTxt(Orden &a);
	void Ordenar(CriterioOrden criterio);
	std::tuple<int,int,int> TotalesGlobales();
	void LimpiarGrid();
};

#endif

