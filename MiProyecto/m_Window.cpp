#include "m_Window.h"
#include <wx/msgdlg.h>
#include <wx/valtext.h>
#include <fstream>
#include <string>
#include <wx/string.h>
#include "string_conv.h"

m_Window::m_Window(Grid *grid, wxWindow *parent) : Window(parent), m_grid(grid) {
	Refresh();
	//Validar solo numeros en el monto
	wxTextValidator tv(wxFILTER_NUMERIC);
	m_montoLabel->SetValidator(tv);
	m_filtros = nullptr;
}

void m_Window::ClickIngreso( wxCommandEvent& event )  {
	if(_userName != "admin"){
		long d,m,a;
		long monto;
		std::string asunto;
		//Obtener datos
		m_diaLabel->GetValue().ToLong(&d);
		m_mesLabel->GetValue().ToLong(&m);
		m_anioLabel->GetValue().ToLong(&a);
		m_montoLabel->GetValue().ToLong(&monto);
		asunto = m_asuntoLabel->GetValue();
		
		if (d < 1 || d > 31 or m < 1 || m > 12) {
			wxMessageBox("Fecha no válida. Por favor, ingrese un día entre 1 y 31 y un mes entre 1 y 12.", "Error");
			return;
		}
		
		long fecha = a*10000+m*100+d;
		Admin ingreso(fecha,"Ingreso",asunto,monto);
		aux = ingreso;
		m_grid->AgregarCompra(ingreso);
		m_grid->Guardar();
		//FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
		Refresh();
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
	
}

void m_Window::ClickEgreso( wxCommandEvent& event )  {
	if(_userName != "admin"){
		//Variables
		long d,m,a;
		long monto;
		std::string asunto;
		//Obtener datos
		m_diaLabel->GetValue().ToLong(&d);
		m_mesLabel->GetValue().ToLong(&m);
		m_anioLabel->GetValue().ToLong(&a);
		m_montoLabel->GetValue().ToLong(&monto);
		asunto = m_asuntoLabel->GetValue();
		
		if (d < 1 || d > 31 or m < 1 || m > 12) {
			wxMessageBox("Fecha no válida. Por favor, ingrese un día entre 1 y 31 y un mes entre 1 y 12.", "Error");
			return;
		}
		
		long fecha = a*10000+m*100+d;
		Admin egreso(fecha,"Egreso",asunto,monto);
		aux = egreso;
		m_grid->AgregarCompra(egreso);
		m_grid->Guardar();
		//FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
		Refresh();
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
	
}

void m_Window::ClickGrilla( wxGridEvent& event )  {
	if(_userName != "admin"){
		int columna = event.GetCol();
		switch(columna) { 
		case 0: m_grid->Ordenar(FECHA); break;
		case 1: m_grid->Ordenar(TIPO_TRANSACCION); break;
		}
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
		//Refresh();
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Window::ClickBorrar(wxCommandEvent& event) {
	if(_userName != "admin"){
		int selectedRow = m_Historial->GetGridCursorRow();
		int numRows = m_Historial->GetNumberRows();
		
		if (selectedRow == numRows - 1) {
			wxMessageBox("No se puede borrar la última fila directamente. Utilice el botón para borrar.", "ERROR");
			return;
		}
		
		
		m_grid->EliminarCompra(selectedRow);
		m_grid->Guardar();
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
		//Refresh();
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}


void m_Window::ClickImprimir( wxCommandEvent& event )  {
	if(m_Historial->GetNumberRows() != 0){
		m_grid->ExportarTxt(aux);
		wxMessageBox("Se imprimio el historial","EXITO");
	}
}


void m_Window::Refresh(){
	if(m_Historial->GetNumberRows() != 0){
		m_Historial->DeleteRows(0,m_Historial->GetNumberRows());
	}
	if(m_grid->CantidadDatos()>0){
		for(int i=0;i<m_grid->CantidadDatos();i++){
			Admin &a = m_grid->VerGasto(i);
			m_Historial->AppendRows();
			wxString fecha = wxString::Format("%1d",a.VerFecha());
			m_Historial->SetCellValue(i,0,fecha);
			m_Historial->SetCellValue(i,1,a.VerTipo());
			m_Historial->SetCellValue(i,2,a.VerAsunto());
			wxString monto = wxString::Format("%1d",a.VerMonto());
			m_Historial->SetCellValue(i,3,monto);
		}
	}
	
	if (m_grid->EsAdmin(_username)) {
		auto totales = m_grid->TotalesGlobales();
		int newRow = m_Historial->AppendRows();
		m_Historial->SetCellValue(newRow, 0, "Totales:");
		m_Historial->SetCellValue(newRow, 1, wxString::Format("%d", std::get<0>(totales)));
		m_Historial->SetCellValue(newRow, 2, wxString::Format("%d", std::get<1>(totales)));
		m_Historial->SetCellValue(newRow, 3, wxString::Format("%d", std::get<2>(totales)));
	}
}	

void m_Window::FiltrarYRefresh(const wxString& fechaInicio, const wxString& fechaFin, const wxString& asunto, const wxString& tipo) {
	if (m_Historial->GetNumberRows() != 0) {
		m_Historial->DeleteRows(0, m_Historial->GetNumberRows());
	}
	
	if (m_grid->CantidadDatos() > 0) {
		for (int i = 0; i < m_grid->CantidadDatos(); i++) {
			Admin& a = m_grid->VerGasto(i);
			
			bool cumpleFiltros = true;
			
			if (!fechaInicio.IsEmpty() && a.VerFecha() < wxAtoi(fechaInicio)) {
				cumpleFiltros = false;
			}
			
			if (!fechaFin.IsEmpty() && a.VerFecha() > wxAtoi(fechaFin)) {
				cumpleFiltros = false;
			}
			
			if (!asunto.IsEmpty() && a.VerAsunto() != asunto) {
				cumpleFiltros = false;
			}
			
			if (!tipo.IsEmpty() && a.VerTipo() != tipo) {
				cumpleFiltros = false;
			}
			
			if (cumpleFiltros) {
				int newRow = m_Historial->AppendRows();
				wxString fechaStr = wxString::Format("%d", a.VerFecha());
				m_Historial->SetCellValue(newRow, 0, fechaStr);
				m_Historial->SetCellValue(newRow, 1, a.VerTipo());
				m_Historial->SetCellValue(newRow, 2, a.VerAsunto());
				wxString montoStr = wxString::Format("%d", a.VerMonto());
				m_Historial->SetCellValue(newRow, 3, montoStr);
			}
		}
	}
}

void m_Window::GetName(std::string userName){
	_userName = userName;
}

void m_Window::ClickFiltrar( wxCommandEvent& event )  {
	if(_userName != "admin"){
		if (!m_filtros) {
			m_filtros = new Filtros(this);
			m_filtros->SetWindow(this);
		}
		m_filtros->Show();
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

m_Window::~m_Window() {
}
