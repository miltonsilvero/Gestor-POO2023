#ifndef M_FILTROS_H
#define M_FILTROS_H
#include "wxfb_project.h"
#include "m_Gestor.h"

class m_Filtros : public Filtros {
	
private:
	std::string fechaInicio;
	std::string fechaFin;
	std::string asunto;
	std::string tipo;
	
	m_Gestor *_mainWindow;
protected:
	void ClickGuardar( wxCommandEvent& event )  override;
	
public:
	m_Filtros(wxWindow *parent=NULL);
	
	void SetWindow(m_Gestor *mainWindow);
	std::string VerFechaInicio();
	std::string VerFechaFin();
	std::string VerAsunto();
	std::string VerTipo();
	
	~m_Filtros();
};

#endif

