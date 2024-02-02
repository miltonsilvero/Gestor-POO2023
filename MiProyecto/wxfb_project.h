///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#pragma once

#include <wx/artprov.h>
#include <wx/xrc/xmlres.h>
#include <wx/string.h>
#include <wx/stattext.h>
#include <wx/gdicmn.h>
#include <wx/font.h>
#include <wx/colour.h>
#include <wx/settings.h>
#include <wx/textctrl.h>
#include <wx/sizer.h>
#include <wx/button.h>
#include <wx/bitmap.h>
#include <wx/image.h>
#include <wx/icon.h>
#include <wx/grid.h>
#include <wx/frame.h>

///////////////////////////////////////////////////////////////////////////


///////////////////////////////////////////////////////////////////////////////
/// Class Window
///////////////////////////////////////////////////////////////////////////////
class Window : public wxFrame
{
	private:

	protected:
		wxStaticText* m_fechaText;
		wxTextCtrl* m_diaLabel;
		wxTextCtrl* m_mesLabel;
		wxTextCtrl* m_anioLabel;
		wxStaticText* m_diaText;
		wxStaticText* m_mesText;
		wxStaticText* m_anioText;
		wxStaticText* m_asuntoText;
		wxTextCtrl* m_asuntoLabel;
		wxStaticText* m_montoText;
		wxTextCtrl* m_montoLabel;
		wxButton* m_ingresoButton;
		wxButton* m_egresoButton;
		wxGrid* m_Historial;
		wxButton* m_borrarButton;
		wxButton* m_filtrarButton;
		wxButton* m_imprimirButton;

		// Virtual event handlers, override them in your derived class
		virtual void ClickIngreso( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickEgreso( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickGrilla( wxGridEvent& event ) { event.Skip(); }
		virtual void ClickBorrar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickFiltrar( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickImprimir( wxCommandEvent& event ) { event.Skip(); }


	public:

		Window( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("REGISTRO DE GASTOS"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 750,400 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Window();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Home
///////////////////////////////////////////////////////////////////////////////
class Home : public wxFrame
{
	private:

	protected:
		wxStaticText* m_tituloText;
		wxStaticText* m_usuarioText;
		wxTextCtrl* m_usuarioLabel;
		wxStaticText* m_contraText;
		wxTextCtrl* m_contraLabel;
		wxButton* m_inicioButton;
		wxButton* m_registroButton;

		// Virtual event handlers, override them in your derived class
		virtual void ClickInicio( wxCommandEvent& event ) { event.Skip(); }
		virtual void ClickRegistro( wxCommandEvent& event ) { event.Skip(); }


	public:

		Home( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxT("GESTOR DE GASTOS"), const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 400,300 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Home();

};

///////////////////////////////////////////////////////////////////////////////
/// Class Filtros
///////////////////////////////////////////////////////////////////////////////
class Filtros : public wxFrame
{
	private:

	protected:
		wxStaticText* m_staticText10;
		wxStaticText* m_finicioText;
		wxStaticText* m_ffinalText;
		wxTextCtrl* m_finicioLabel;
		wxTextCtrl* m_ffinalLabel;
		wxStaticText* m_asuntoText2;
		wxStaticText* m_tipoText2;
		wxTextCtrl* m_asuntoLabel2;
		wxTextCtrl* m_tipoLabel2;
		wxButton* m_guardarButton;

		// Virtual event handlers, override them in your derived class
		virtual void ClickGuardar( wxCommandEvent& event ) { event.Skip(); }


	public:

		Filtros( wxWindow* parent, wxWindowID id = wxID_ANY, const wxString& title = wxEmptyString, const wxPoint& pos = wxDefaultPosition, const wxSize& size = wxSize( 350,250 ), long style = wxDEFAULT_FRAME_STYLE|wxTAB_TRAVERSAL );

		~Filtros();

};

