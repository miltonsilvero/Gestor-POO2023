#ifndef M_GESTOR_H
#define M_GESTOR_H
#include "wxfb_project.h"
#include "Grid.h"
#include "Orden.h"
#include "m_Filtros.h"

class m_Gestor : public Gestor {
	
private:
	Orden aux;
	Grid *m_grid;
	m_Filtros *m_filtros;
	std::string _userName;
protected:
	void ClickIngreso( wxCommandEvent& event )  override;
	void ClickEgreso( wxCommandEvent& event )  override;
	void ClickGrilla( wxGridEvent& event )  override;
	void ClickBorrar( wxCommandEvent& event )  override;
	void ClickFiltrar( wxCommandEvent& event )  override;
	void ClickImprimir( wxCommandEvent& event )  override;
	
public:
	m_Gestor(Grid *grid,const std::string& userName,wxWindow *parent=NULL);
	
	void Refresh();
	void FiltrarYRefresh(const wxString& fechaInicio, const wxString& fechaFin, const wxString& asunto, const wxString& tipo);
	
	~m_Gestor();
};

#endif

