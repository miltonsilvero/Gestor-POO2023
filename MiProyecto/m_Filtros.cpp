#include "m_Gestor.h"
#include "m_Filtros.h"

m_Filtros::m_Filtros(wxWindow *parent) : Filtros(parent) {
	
}

void m_Filtros::ClickGuardar( wxCommandEvent& event )  {
	m_finicioLabel->GetValue().ToLong(&fechaInicio);
	m_ffinalLabel->GetValue().ToLong(&fechaFin);
	asunto = m_asuntoLabel2->GetValue();
	tipo = m_tipoLabel2->GetValue();

	this->Close();
	
	if (_mainWindow) {
		_mainWindow->FiltrarYRefresh(fechaInicio,fechaFin,asunto,tipo);
	}
	
	filtrosActivos = true;
}

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
	_mainWindow->Refresh();
	filtrosActivos = false;
}

bool m_Filtros::EstadoFiltros(){
	return filtrosActivos;
}

void m_Filtros::ClickQuitar( wxCommandEvent& event )  {
	
}

