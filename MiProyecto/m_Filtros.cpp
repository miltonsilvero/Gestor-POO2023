#include "m_Gestor.h"
#include "m_Filtros.h"

m_Filtros::m_Filtros(wxWindow *parent) : Filtros(parent) {
	
}

void m_Filtros::ClickGuardar( wxCommandEvent& event )  {
	fechaInicio = m_finicioLabel->GetValue();
	fechaFin = m_ffinalLabel->GetValue();
	asunto = m_asuntoLabel2->GetValue();
	tipo = m_tipoLabel2->GetValue();
	
	this->Close();
	
	if (_mainWindow) {
		_mainWindow->FiltrarYRefresh(fechaInicio,fechaFin,asunto,tipo);
	}
}

std::string m_Filtros::VerFechaInicio(){
	return fechaInicio;
}
std::string m_Filtros::VerFechaFin(){
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

