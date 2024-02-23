#ifndef M_GESTOR_H
#define M_GESTOR_H
#include "wxfb_project.h"
#include "Grid.h"
#include "Orden.h"
#include "m_Filtros.h"
#include <vector>

class m_Gestor : public Gestor {
	
private:
	Orden aux;
	Grid *m_grid;
	m_Filtros *m_filtros;
	std::string _userName;
	std::string nameIng = "IngresosT.dat";
	std::string nameEgr = "EgresosT.dat";
	long ingT,egrT;
	std::vector<int> posOriginal;
	
protected:
	void ClickIngreso( wxCommandEvent& event )  override;
	void ClickEgreso( wxCommandEvent& event )  override;
	void ClickGrilla( wxGridEvent& event )  override;
	void ClickBorrar( wxCommandEvent& event )  override;
	void ClickFiltrar( wxCommandEvent& event )  override;
	void ClickImprimir( wxCommandEvent& event )  override;
	
public:
	m_Gestor(Grid *grid,const std::string& userName,wxWindow *parent=NULL);
	
	void FiltrarYRefresh(const long& fechaInicio, const long& fechaFin, const wxString& asunto, const wxString& tipo);
	void LeerTotales(std::ifstream &archivo,std::ifstream &archivo2);
	void GuardarTotales(std::ofstream &archivo, std::ofstream &archivo2);
	void ActualizarTotales(long montoI, long montoE);
	~m_Gestor();
};

#endif

