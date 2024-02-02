#include <wx/image.h>
#include "Application.h"
#include "m_Home.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	//archiUser = m_Home.verNombre();
	//m_grid = new Grid(archiUser,"historial.txt");
	m_usuario = new Usuario();
	wxInitAllImageHandlers();
	m_Home *win = new m_Home(m_usuario);
	win->Show();
	return true;
}

