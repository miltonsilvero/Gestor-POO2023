#include "m_Gestor.h"
#include "m_Filtros.h"

m_Filtros::m_Filtros(wxWindow *parent) : Filtros(parent) {
	
}

void m_Filtros::ClickGuardar( wxCommandEvent& event )  {  ///Esta funci�n asigna lo que ingresa el usario en los labels a las variables.
	m_finicioLabel->GetValue().ToLong(&fechaInicio);  
	m_ffinalLabel->GetValue().ToLong(&fechaFin);
	asunto = m_asuntoLabel2->GetValue();
	switch(m_tipoChoise->GetSelection()){
	case 0: tipo = "";
		break;
	case 1: tipo = "Ingreso";
		break;
	case 2: tipo = "Egreso";
		break;
	}
	
	this->Hide();
	
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
	fechaInicio = 0;
	fechaFin = 0;
	asunto = "";
	tipo = "";
	_mainWindow->FiltrarYRefresh(fechaInicio, fechaFin, asunto, tipo);
	filtrosActivos = false;
	
	this->Hide();
}

