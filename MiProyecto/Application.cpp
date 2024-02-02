#include <wx/image.h>
#include "Application.h"
#include "m_Home.h"

IMPLEMENT_APP(Application)

bool Application::OnInit() {
	m_usuario = new Usuario();
	wxInitAllImageHandlers();
	m_Home *win = new m_Home(m_usuario);
	win->Show();
	return true;
}

