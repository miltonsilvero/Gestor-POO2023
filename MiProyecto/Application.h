#ifndef APPLICATION_H
#define APPLICATION_H

#include "m_Home.h"
#include <wx/app.h>
#include "Usuario.h"
#include "Grid.h"
#include <string>

class Application : public wxApp {
private:
	//std::string archiUser;
	//Grid *m_grid;
	Usuario *m_usuario;
public:
	virtual bool OnInit();
};

#endif
