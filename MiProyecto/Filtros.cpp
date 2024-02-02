#include "Filtros.h"
#include "m_Window.h"

Filtros::Filtros(wxWindow *parent) : MyFrame3(parent) {
	
}

void Filtros::ClickGuardar( wxCommandEvent& event )  {
	fechaInicio = m_finicioLabel->GetValue();
	fechaFin = m_ffinalLabel->GetValue();
	asunto = m_asuntoLabel2->GetValue();
	tipo = m_tipoLabel2->GetValue();
	
	this->Close();
	
	if (_mainWindow) {
		_mainWindow->FiltrarYRefresh(fechaInicio,fechaFin,asunto,tipo);
	}
}

std::string Filtros::VerFechaInicio(){
	return fechaInicio;
}
std::string Filtros::VerFechaFin(){
	return fechaFin;
}
std::string Filtros::VerAsunto(){
	return asunto;
}
std::string Filtros::VerTipo(){
	return tipo;
}
Filtros::~Filtros() {
	
}

void Filtros::SetWindow(m_Window *mainWindow){
	_mainWindow = mainWindow;
}
