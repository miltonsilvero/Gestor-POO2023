#ifndef M_WINDOW_H
#define M_WINDOW_H
#include "wxfb_project.h"
#include "Grid.h"
#include "Admin.h"
#include "Filtros.h"

class m_Window : public Window {
	
private:
	Admin aux;
	Grid *m_grid;
	Filtros *m_filtros;
	std::string _userName;
protected:
	void ClickFiltrar( wxCommandEvent& event )  override;
	void ClickIngreso( wxCommandEvent& event )  override;
	void ClickEgreso( wxCommandEvent& event )  override;
	void ClickGrilla( wxGridEvent& event )  override;
	void ClickBorrar( wxCommandEvent& event )  override;
	void ClickImprimir( wxCommandEvent& event )  override;
	
public:
	//m_Window(Grid *grid);
	m_Window(Grid *grid,wxWindow *parent=NULL);
	void Refresh();
	void FiltrarYRefresh(const wxString& fechaInicio, const wxString& fechaFin, const wxString& asunto, const wxString& tipo);
	void GetName(std::string userName);
	~m_Window();
};

#endif

