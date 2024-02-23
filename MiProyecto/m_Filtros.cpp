#include "m_Gestor.h"
#include "m_Filtros.h"

m_Filtros::m_Filtros(wxWindow *parent) : Filtros(parent) {
	
}

void m_Filtros::ClickGuardar( wxCommandEvent& event )  {  ///Esta funci�n asigna lo que ingresa el usario en los labels a las variables.
	m_finicioLabel->GetValue().ToLong(&fechaInicio);  
	m_ffinalLabel->GetValue().ToLong(&fechaFin);
	asunto = m_asuntoLabel2->GetValue();
	tipo = m_tipoLabel2->GetValue();
	
	std::cout << fechaInicio << std::endl;
	std::cout << fechaFin << std::endl;
	std::cout << asunto << std::endl;
	std::cout << tipo << std::endl;
	
	this->Close();
	
	if (_mainWindow) {
		_mainWindow->FiltrarYRefresh(fechaInicio,fechaFin,asunto,tipo);
	}
	
	filtrosActivos = true;
}                                                         ///A partir de ac� hay funciones que devuelven las variables privadas ya con valores asignados.

long m_Filtros::VerFechaInicio(){
	return fechaInicio;               
}
long m_Filtros::VerFechaFin(){
	return fechaFin;
}
std::string m_Filtros::VerAsunto(){
	return asunto;
}
std::string m_Filtros::VerTipo(){
	return tipo;
}

void m_Filtros::SetWindow(m_Gestor *mainWindow){
	_mainWindow = mainWindow;
}

m_Filtros::~m_Filtros() {
}

bool m_Filtros::EstadoFiltros(){
	return filtrosActivos;
}

void m_Filtros::ClickQuitar( wxCommandEvent& event )  {
	long fechaInicio = 0;
	long fechaFin = 0;
	std::string asunto = "";
	std::string tipo = "";
	_mainWindow->Refresh();
	filtrosActivos = false;
	
	this->Close();
}

