#include "m_Gestor.h"
#include <wx/msgdlg.h>
#include <wx/valtext.h>
#include <fstream>
#include <string>
#include <wx/string.h>
#include "string_conv.h"

m_Gestor::m_Gestor(Grid *grid,const std::string& userName, wxWindow *parent) : Gestor(parent), m_grid(grid), _userName(userName) {
	wxTextValidator tv(wxFILTER_NUMERIC);
	m_montoLabel->SetValidator(tv);
	m_diaLabel->SetValidator(tv);
	m_mesLabel->SetValidator(tv);
	m_anioLabel->SetValidator(tv);
	
	m_filtros = new m_Filtros(this);
	m_filtros->SetWindow(this);
	
	
	if(_userName != "admin"){
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
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
		
		Orden balanceT(2024,"Total","BALANCE: ",ingT-egrT);
		aux = balanceT;
		m_grid->AgregarCompra(balanceT);
		m_grid->Guardar();
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
	}
	
}

void m_Gestor::ClickIngreso( wxCommandEvent& event )  {
	if(_userName != "admin"){
		long d,m,a;
		long monto;
		std::string asunto;
		
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
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickEgreso( wxCommandEvent& event )  {
	if(_userName != "admin"){
		long d,m,a;
		long monto;
		std::string asunto;
		
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
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickGrilla( wxGridEvent& event )  {
	if(_userName != "admin"){
		int columna = event.GetCol();
		switch(columna) { 
		case 0: m_grid->Ordenar(FECHA); break;
		case 1: m_grid->Ordenar(TIPO_TRANSACCION); break;
		}
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
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
		
		m_grid->EliminarCompra(posOriginal[selectedRow]);
		m_grid->Guardar();
		FiltrarYRefresh(m_filtros->VerFechaInicio(),m_filtros->VerFechaFin(),m_filtros->VerAsunto(),m_filtros->VerTipo());
	}else{
		wxMessageBox("El admin solo puede ver e imprimir la grilla.","ERROR");
	}
}

void m_Gestor::ClickFiltrar( wxCommandEvent& event )  {
	if(_userName != "admin"){
		//m_filtros = new m_Filtros(this);
		//m_filtros->SetWindow(this);
		
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

void m_Gestor::FiltrarYRefresh(const long& fechaInicio, const long& fechaFin, const wxString& asunto, const wxString& tipo) {  ///fechaInicio, fechaFin, asunto y tipo contienen los filtros que puso el usuario
	if (!m_Historial) {
		wxMessageBox("Error: m_Historial no está inicializado correctamente.", "Error");     ///Validador 1
		return;
	}
	
	if (m_Historial->GetNumberRows() != 0) {
		m_Historial->DeleteRows(0, m_Historial->GetNumberRows());                            ///Validador 2
	}
	
	
	if (m_grid->CantidadDatos() > 0) {
		int c = 0;
		posOriginal.clear();
		for (int i = 0; i < m_grid->CantidadDatos(); i++) {                          ///Con este bucle cada dato se compara con los filtros
			Orden &a = m_grid->VerGasto(i);
			bool cumpleFiltros = true;                                               ///Este booleano tiene se mantiene true si cumple con los filtros
			
			if(a.VerAsunto() != "BALANCE: "){
				if (fechaInicio != 0 && a.VerFecha() < fechaInicio) {                   ///¿Fecha mayor a la inicial?
					cumpleFiltros = false;
				}
				
				if (fechaFin != 0 && a.VerFecha() > fechaFin) {                         ///¿Fecha menor a la final?
					cumpleFiltros = false;
				}
				
				if (asunto != "" && a.VerAsunto() != asunto) {                          ///¿Mismo asunto?
					cumpleFiltros = false;
				}
				
				if (tipo != "" && a.VerTipo() != tipo) {                                ///¿Mismo tipo?
					cumpleFiltros = false;
				}
			}
			
			if (cumpleFiltros) {   								 ///Si cumple con todos los filtros, se mostrará en pantalla
				posOriginal.push_back(i);
				m_Historial->AppendRows();            		               ///Historial es un arreglo que contiene los datos de las órdenes del usuario. (Lo limpia para agregar nuevas columanas)
				wxString fechaStr = wxString::Format("%ld", a.VerFecha()); ////////
				m_Historial->SetCellValue(c, 0, fechaStr);                 ///
				m_Historial->SetCellValue(c, 1, a.VerTipo());              ///Todas estas líneas de código restantes asignan la fecha, el tipo, el asunto y el monto a las columnas
				m_Historial->SetCellValue(c, 2, a.VerAsunto());            ///para que así se muestre la grilla actualizada con las órdenes.
				wxString montoStr = wxString::Format("%ld", a.VerMonto()); ///
				m_Historial->SetCellValue(c, 3, montoStr);                 ////////
				c++;
			}
			
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

