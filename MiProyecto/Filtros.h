#ifndef FILTROS_H
#define FILTROS_H
#include "wxfb_project.h"
#include "m_Window.h"

class Filtros : public MyFrame3 {
	
private:
	std::string fechaInicio;
	std::string fechaFin;
	std::string asunto;
	std::string tipo;
	
	m_Window *_mainWindow;
protected:
	void ClickGuardar( wxCommandEvent& event )  override;
	
public:
	Filtros(wxWindow *parent=NULL);
	
	void SetWindow(m_Window *mainWindow);
	
	std::string VerFechaInicio();
	std::string VerFechaFin();
	std::string VerAsunto();
	std::string VerTipo();
	~Filtros();
};

#endif

