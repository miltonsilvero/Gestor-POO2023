#include "m_Gestor.h"
#include <wx/msgdlg.h>
#include <wx/valtext.h>
#include <fstream>
#include <string>
#include <wx/string.h>
#include "string_conv.h"

m_Gestor::m_Gestor(Grid *grid,const std::string& userName, wxWindow *parent) : Gestor(parent), m_grid(grid), _userName(userName) {
	//Validar solo numeros en el monto
	wxTextValidator tv(wxFILTER_NUMERIC);
	m_montoLabel->SetValidator(tv);
	m_filtros = nullptr;
	std::cout << "_userName: " << _userName << std::endl;
	
	if(_userName != "admin"){
		Refresh();
	} else{
		m_grid->LimpiarGrid();
		
		ActualizarTotales(0,0);
		Orden ingresosT(2024,"Total","Ingresos:",ingT);
		aux = ingresosT;
		m_grid->AgregarCompra(ingresosT);
		m_grid->Guardar();
		
		Orden egresosT(2024,"Total","Egresos:",egrT);
		aux = egresosT;
		m_grid->AgregarCompra(egresosT);
		m_grid->Guardar();
		
		Orden balanceT(2024,"Total","Balance:",ingT-egrT);
		aux = balanceT;
		m_grid->AgregarCompra(balanceT);
		m_grid->Guardar();
		Refresh();
	}
	
}

void m_Gestor::ClickIngreso( wxCommandEvent& event )  {
	if(_userName != "admin"){
		if(m_filtros->EstadoFiltros() == false){
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
			
			ActualizarTotales(monto,0);
			
			long fecha = a*10000+m*100+d;
			Orden ingreso(fecha,"Ingreso",asunto,monto);
			aux = ingreso;
			m_grid->AgregarCompra(ingreso);
			m_grid->Guardar();
			Refresh();
		}else{
			wxMessageBox("No puede agregar items con los filtros puestos.","ERROR");
		}
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickEgreso( wxCommandEvent& event )  {
	if(_userName != "admin"){
		if(m_filtros->EstadoFiltros() == false){
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
			
			ActualizarTotales(0,monto);
			
			long fecha = a*10000+m*100+d;
			Orden egreso(fecha,"Egreso",asunto,monto);
			aux = egreso;
			m_grid->AgregarCompra(egreso);
			m_grid->Guardar();
			Refresh();
		}else{
			wxMessageBox("No puede agregar items con los filtros puestos.","ERROR");
		}
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickGrilla( wxGridEvent& event )  {
	if(_userName != "admin"){
		if(m_filtros->EstadoFiltros() == false){
			int columna = event.GetCol();
			switch(columna) { 
			case 0: m_grid->Ordenar(FECHA); break;
			case 1: m_grid->Ordenar(TIPO_TRANSACCION); break;
			}
			Refresh();
		}else{
			wxMessageBox("Filtros activados.","ERROR");
		}
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickBorrar( wxCommandEvent& event )  {
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

void m_Gestor::ClickFiltrar( wxCommandEvent& event )  {
	if(_userName != "admin"){
		if (!m_filtros) {
			m_filtros = new m_Filtros(this);
			m_filtros->SetWindow(this);
		}
		m_filtros->Show();
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickImprimir( wxCommandEvent& event )  {
	if(m_Historial->GetNumberRows() != 0){
		m_grid->ExportarTxt(aux);
		wxMessageBox("Se imprimio el historial","EXITO");
	}
}

void m_Gestor::FiltrarYRefresh(const long& fechaInicio, const long& fechaFin, const wxString& asunto, const wxString& tipo) {
	if (!m_Historial) {
		wxMessageBox("Error: m_Historial no está inicializado correctamente.", "Error");
		return;
	}
	
	if (m_Historial->GetNumberRows() != 0) {
		m_Historial->DeleteRows(0, m_Historial->GetNumberRows());
	}
	
	
	if (m_grid->CantidadDatos() > 0) {
		for (int i = 0; i < m_grid->CantidadDatos(); i++) {
			Orden& a = m_grid->VerGasto(i);
			
			bool cumpleFiltros = true;
			
			if (fechaInicio != 0 && a.VerFecha() < fechaInicio) {
				cumpleFiltros = false;
			}
			
			if (fechaFin != 0 && a.VerFecha() > fechaFin) {
				cumpleFiltros = false;
			}
			
			if (asunto != "" && a.VerAsunto() != asunto) {
				cumpleFiltros = false;
			}
			
			if (tipo != "" && a.VerTipo() != tipo) {
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

void m_Gestor::Refresh(){
	if(m_Historial->GetNumberRows() != 0){
		m_Historial->DeleteRows(0,m_Historial->GetNumberRows());
	}
	
	if(m_grid->CantidadDatos()>0){
		for(int i=0;i<m_grid->CantidadDatos();i++){
			Orden &a = m_grid->VerGasto(i);
			m_Historial->AppendRows();
			wxString fecha = wxString::Format("%1d",a.VerFecha());
			m_Historial->SetCellValue(i,0,fecha);
			m_Historial->SetCellValue(i,1,a.VerTipo());
			m_Historial->SetCellValue(i,2,a.VerAsunto());
			wxString monto = wxString::Format("%1d",a.VerMonto());
			m_Historial->SetCellValue(i,3,monto);
		}
	}
}

void m_Gestor::LeerTotales(std::ifstream &archivo,std::ifstream &archivo2){
	long ingresos;
	archivo.read((char*)&ingresos,sizeof(ingresos));
	ingT = ingresos;
	
	long egresos;
	archivo2.read((char*)&egresos,sizeof(egresos));
	egrT = egresos;
}

void m_Gestor::GuardarTotales(std::ofstream &archivo, std::ofstream &archivo2){
	long ingresos, egresos;
	ingresos = ingT;
	egresos = egrT;
	
	archivo.write((char*)&ingresos,sizeof(ingresos));
	archivo2.write((char*)&egresos,sizeof(egresos));
}

void m_Gestor::ActualizarTotales(long montoI, long montoE){
	std::fstream archivoIng(nameIng.c_str(), std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
	std::fstream archivoEgr(nameEgr.c_str(), std::ios::binary | std::ios::in | std::ios::out | std::ios::ate);
	
	if (archivoIng.is_open() && archivoEgr.is_open()) {
		archivoIng.seekg(0, std::ios::beg);
		archivoEgr.seekg(0, std::ios::beg);
		
		archivoIng.read((char*)&ingT, sizeof(ingT));
		archivoEgr.read((char*)&egrT, sizeof(egrT));
		
		ingT += montoI;
		egrT += montoE;
		
		archivoIng.seekp(0, std::ios::beg);
		archivoEgr.seekp(0, std::ios::beg);
		
		archivoIng.write((char*)&ingT, sizeof(ingT));
		archivoEgr.write((char*)&egrT, sizeof(egrT));
	}
	
	archivoIng.close();
	archivoEgr.close();
}

m_Gestor::~m_Gestor() {
	
}

