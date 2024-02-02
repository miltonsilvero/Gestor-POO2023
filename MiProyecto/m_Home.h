#ifndef M_HOME_H
#define M_HOME_H
#include "wxfb_project.h"
#include "Usuario.h"
#include "Grid.h"
#include <string>
#include "m_Window.h"

class m_Home : public Home {
	
private:
	m_Window *windowGrilla;
	Grid *m_grid;
	
	
	Usuario *m_usuario;
	std::string archiUser;
	std::string archiHist;
protected:
	void ClickInicio( wxCommandEvent& event )  override;
	void ClickRegistro( wxCommandEvent& event )  override;
	
public:
	m_Home(Usuario *usuario);
	//std::string verNombre();
	//m_Home(wxWindow *parent=NULL);
};

#endif

