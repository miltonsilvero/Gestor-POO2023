#ifndef M_FILTROS_H
#define M_FILTROS_H
#include "wxfb_project.h"
//#include "m_Gestor.h"
class m_Gestor;                  //declaracion forward

class m_Filtros : public Filtros {
	
private:
	long fechaInicio = 0;
	long fechaFin = 0;
	std::string asunto = "";
	std::string tipo = "";
	
	bool filtrosActivos = false;
	
	m_Gestor *_mainWindow;
protected:
	void ClickQuitar( wxCommandEvent& event )  override;
	void ClickGuardar( wxCommandEvent& event )  override;
	
public:
	m_Filtros(wxWindow *parent=NULL);
	
	void SetWindow(m_Gestor *mainWindow);
	long VerFechaInicio();
	long VerFechaFin();
	std::string VerAsunto();
	std::string VerTipo();
	bool EstadoFiltros();
	~m_Filtros();
};

#endif

