#include "m_Home.h"
#include "Usuario.h"
#include <wx/msgdlg.h>
#include <wx/event.h>
#include <iostream>
#include "m_Gestor.h"
#include "Grid.h"
#include <string>

m_Home::m_Home(Usuario *usuario) : Home(nullptr), m_usuario(usuario) {
	windowGrilla = nullptr;
	Persona p("admin","admin");
	if(m_usuario->Registrado(p) == false){
		m_usuario->AgregarUsuario(p);
	}
}

void m_Home::ClickInicio( wxCommandEvent& event )  {
	std::string name;
	std::string password;
	name = m_usuarioLabel->GetValue();
	password = m_contraLabel->GetValue();
	Persona p(name,password);
	if(m_usuario->BuscarUsuario(p) == true){
		if(name == "admin"){
			std::string aux = name;
			std::cout << aux;
			wxMessageBox("¡Bienvenido, Admin!","ÉXITO");
			m_grid = new Grid("adminGrid.dat","adminHist.txt");
			windowGrilla = new m_Gestor(m_grid,name,this);
			windowGrilla->Show();
		}else{
			archiUser = name + "Grid.dat";
			archiHist = name + "Hist.txt";
			m_grid = new Grid(archiUser,archiHist);
			windowGrilla = new m_Gestor(m_grid,name,this);
			windowGrilla->Show();
		}
	} else wxMessageBox("Los valores son incorrectos o no existen.","ERROR");
}

void m_Home::ClickRegistro( wxCommandEvent& event )  {
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

