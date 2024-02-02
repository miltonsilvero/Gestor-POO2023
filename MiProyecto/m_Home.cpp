#include "m_Home.h"
#include "Usuario.h"
#include <wx/msgdlg.h>
#include <wx/event.h>
#include <iostream>
#include "m_Window.h"
#include "Grid.h"
#include <string>

//(wxWindow *parent)
m_Home::m_Home(Usuario *usuario) : Home(nullptr), m_usuario(usuario) {
	windowGrilla = nullptr;
}

void m_Home::ClickInicio( wxCommandEvent& event )  {
	std::cout << "Inicio presionado." << std::endl;
	std::string name;
	std::string password;
	windowGrilla->GetName(name);
	name = m_usuarioLabel->GetValue();
	password = m_contraLabel->GetValue();
	Persona p(name,password);
	if(m_usuario->BuscarUsuario(p) == true){
		if(name == "admin"){
			wxMessageBox("�Bienvenido, Admin!","�XITO");
			m_grid = new Grid("adminGrid.dat","adminHist.txt");
			windowGrilla = new m_Window(m_grid,this);
			windowGrilla->Show();
		}else{
			archiUser = name + "Grid.dat";
			archiHist = name + "Hist.txt";
			m_grid = new Grid(archiUser,archiHist);
			windowGrilla = new m_Window(m_grid,this);
			windowGrilla->Show();
		}
	} else wxMessageBox("Los valores son incorrectos o no existen.","ERROR");
}

void m_Home::ClickRegistro( wxCommandEvent& event )  {
	std::cout << "Registro presionado." << std::endl;
	std::string name;
	std::string password;
	name = m_usuarioLabel->GetValue();
	password = m_contraLabel->GetValue();
	Persona p(name,password);
	if(m_usuario->Registrado(p) == false){
		m_usuario->AgregarUsuario(p);
		wxMessageBox("Se pudo agregar el usuario.","SUCCESS");
	} else wxMessageBox("Los valores son incorrectos o ya existen.","ERROR");
}

/*std::string m_Home::verNombre(){
	return archiUser;
}*/