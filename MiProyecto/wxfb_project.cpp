///////////////////////////////////////////////////////////////////////////
// C++ code generated with wxFormBuilder (version 4.0.0-0-g0efcecf)
// http://www.wxformbuilder.org/
//
// PLEASE DO *NOT* EDIT THIS FILE!
///////////////////////////////////////////////////////////////////////////

#include "wxfb_project.h"

///////////////////////////////////////////////////////////////////////////

Gestor::Gestor( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxSize( 750,400 ), wxSize( 750,400 ) );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_ACTIVECAPTION ) );
	this->SetBackgroundColour( wxColour( 213, 155, 70 ) );

	wxBoxSizer* bSizer2;
	bSizer2 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer4;
	bSizer4 = new wxBoxSizer( wxVERTICAL );

	m_fechaText = new wxStaticText( this, wxID_ANY, wxT("Fecha"), wxDefaultPosition, wxDefaultSize, 0 );
	m_fechaText->Wrap( -1 );
	m_fechaText->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("HP Simplified Hans") ) );
	m_fechaText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer4->Add( m_fechaText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer10;
	bSizer10 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer14;
	bSizer14 = new wxBoxSizer( wxVERTICAL );

	m_diaLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_diaLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );
	m_diaLabel->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_INFOBK ) );

	bSizer14->Add( m_diaLabel, 0, wxALL, 5 );

	m_mesLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_mesLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer14->Add( m_mesLabel, 0, wxALL, 5 );

	m_anioLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	m_anioLabel->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer14->Add( m_anioLabel, 0, wxALL, 5 );


	bSizer10->Add( bSizer14, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	m_diaText = new wxStaticText( this, wxID_ANY, wxT("Día"), wxDefaultPosition, wxDefaultSize, 0 );
	m_diaText->Wrap( -1 );
	m_diaText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer15->Add( m_diaText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_mesText = new wxStaticText( this, wxID_ANY, wxT("Mes"), wxDefaultPosition, wxDefaultSize, 0 );
	m_mesText->Wrap( -1 );
	m_mesText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer15->Add( m_mesText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_anioText = new wxStaticText( this, wxID_ANY, wxT("Año"), wxDefaultPosition, wxDefaultSize, 0 );
	m_anioText->Wrap( -1 );
	m_anioText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer15->Add( m_anioText, 1, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer10->Add( bSizer15, 1, wxEXPAND|wxALIGN_CENTER_VERTICAL, 5 );


	bSizer4->Add( bSizer10, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer11;
	bSizer11 = new wxBoxSizer( wxVERTICAL );

	m_asuntoText = new wxStaticText( this, wxID_ANY, wxT("Asunto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_asuntoText->Wrap( -1 );
	m_asuntoText->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("HP Simplified Hans") ) );
	m_asuntoText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer11->Add( m_asuntoText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_asuntoLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_asuntoLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_montoText = new wxStaticText( this, wxID_ANY, wxT("Monto"), wxDefaultPosition, wxDefaultSize, 0 );
	m_montoText->Wrap( -1 );
	m_montoText->SetFont( wxFont( 12, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("HP Simplified Hans") ) );
	m_montoText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer11->Add( m_montoText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_montoLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer11->Add( m_montoLabel, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer4->Add( bSizer11, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer13;
	bSizer13 = new wxBoxSizer( wxHORIZONTAL );

	m_ingresoButton = new wxButton( this, wxID_ANY, wxT("Ingreso"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_ingresoButton, 1, wxALL, 5 );

	m_egresoButton = new wxButton( this, wxID_ANY, wxT("Egreso"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer13->Add( m_egresoButton, 1, wxALL, 5 );


	bSizer4->Add( bSizer13, 1, wxEXPAND, 5 );


	bSizer2->Add( bSizer4, 0, wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer5;
	bSizer5 = new wxBoxSizer( wxVERTICAL );

	m_Historial = new wxGrid( this, wxID_ANY, wxDefaultPosition, wxDefaultSize, 0 );

	// Grid
	m_Historial->CreateGrid( 0, 4 );
	m_Historial->EnableEditing( false );
	m_Historial->EnableGridLines( true );
	m_Historial->EnableDragGridSize( false );
	m_Historial->SetMargins( 0, 0 );

	// Columns
	m_Historial->SetColSize( 0, 100 );
	m_Historial->SetColSize( 1, 110 );
	m_Historial->SetColSize( 2, 211 );
	m_Historial->SetColSize( 3, 90 );
	m_Historial->EnableDragColMove( false );
	m_Historial->EnableDragColSize( true );
	m_Historial->SetColLabelValue( 0, wxT("Fecha") );
	m_Historial->SetColLabelValue( 1, wxT("Tipo") );
	m_Historial->SetColLabelValue( 2, wxT("Asunto") );
	m_Historial->SetColLabelValue( 3, wxT("Monto") );
	m_Historial->SetColLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Rows
	m_Historial->EnableDragRowSize( true );
	m_Historial->SetRowLabelSize( 0 );
	m_Historial->SetRowLabelAlignment( wxALIGN_CENTER, wxALIGN_CENTER );

	// Label Appearance

	// Cell Defaults
	m_Historial->SetDefaultCellAlignment( wxALIGN_LEFT, wxALIGN_TOP );
	m_Historial->SetBackgroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );

	bSizer5->Add( m_Historial, 1, wxALL|wxEXPAND, 5 );

	wxBoxSizer* bSizer6;
	bSizer6 = new wxBoxSizer( wxHORIZONTAL );

	m_borrarButton = new wxButton( this, wxID_ANY, wxT("Borrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_borrarButton, 1, wxALL, 5 );

	m_filtrarButton = new wxButton( this, wxID_ANY, wxT("Filtrar"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_filtrarButton, 1, wxALL, 5 );

	m_imprimirButton = new wxButton( this, wxID_ANY, wxT("Imprimir"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer6->Add( m_imprimirButton, 1, wxALL, 5 );


	bSizer5->Add( bSizer6, 0, wxEXPAND, 5 );


	bSizer2->Add( bSizer5, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer2 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_ingresoButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickIngreso ), NULL, this );
	m_egresoButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickEgreso ), NULL, this );
	m_Historial->Connect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Gestor::ClickGrilla ), NULL, this );
	m_borrarButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickBorrar ), NULL, this );
	m_filtrarButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickFiltrar ), NULL, this );
	m_imprimirButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickImprimir ), NULL, this );
}

Gestor::~Gestor()
{
	// Disconnect Events
	m_ingresoButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickIngreso ), NULL, this );
	m_egresoButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickEgreso ), NULL, this );
	m_Historial->Disconnect( wxEVT_GRID_LABEL_LEFT_CLICK, wxGridEventHandler( Gestor::ClickGrilla ), NULL, this );
	m_borrarButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickBorrar ), NULL, this );
	m_filtrarButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickFiltrar ), NULL, this );
	m_imprimirButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Gestor::ClickImprimir ), NULL, this );

}

Home::Home( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetBackgroundColour( wxColour( 225, 187, 130 ) );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer17;
	bSizer17 = new wxBoxSizer( wxVERTICAL );

	m_tituloText = new wxStaticText( this, wxID_ANY, wxT("GESTOR DE GASTOS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_tituloText->Wrap( -1 );
	m_tituloText->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxT("Arial Rounded MT Bold") ) );

	bSizer17->Add( m_tituloText, 1, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer16->Add( bSizer17, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxVERTICAL );

	m_usuarioText = new wxStaticText( this, wxID_ANY, wxT("Usuario"), wxDefaultPosition, wxDefaultSize, 0 );
	m_usuarioText->Wrap( -1 );
	m_usuarioText->SetFont( wxFont( 11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Franklin Gothic Book") ) );
	m_usuarioText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer20->Add( m_usuarioText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_usuarioLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_usuarioLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_contraText = new wxStaticText( this, wxID_ANY, wxT("Contraseña"), wxDefaultPosition, wxDefaultSize, 0 );
	m_contraText->Wrap( -1 );
	m_contraText->SetFont( wxFont( 11, wxFONTFAMILY_SWISS, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false, wxT("Franklin Gothic Book") ) );
	m_contraText->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_BACKGROUND ) );

	bSizer20->Add( m_contraText, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );

	m_contraLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer20->Add( m_contraLabel, 0, wxALL|wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer18->Add( bSizer20, 1, wxEXPAND, 5 );


	bSizer16->Add( bSizer18, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );

	m_inicioButton = new wxButton( this, wxID_ANY, wxT("Iniciar Sesión"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_inicioButton, 1, wxALL, 5 );

	m_registroButton = new wxButton( this, wxID_ANY, wxT("Registrarse"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer19->Add( m_registroButton, 1, wxALL, 5 );


	bSizer16->Add( bSizer19, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	this->SetSizer( bSizer16 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_inicioButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Home::ClickInicio ), NULL, this );
	m_registroButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Home::ClickRegistro ), NULL, this );
}

Home::~Home()
{
	// Disconnect Events
	m_inicioButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Home::ClickInicio ), NULL, this );
	m_registroButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Home::ClickRegistro ), NULL, this );

}

Filtros::Filtros( wxWindow* parent, wxWindowID id, const wxString& title, const wxPoint& pos, const wxSize& size, long style ) : wxFrame( parent, id, title, pos, size, style )
{
	this->SetSizeHints( wxDefaultSize, wxDefaultSize );
	this->SetForegroundColour( wxSystemSettings::GetColour( wxSYS_COLOUR_WINDOWTEXT ) );
	this->SetBackgroundColour( wxColour( 225, 187, 130 ) );

	wxBoxSizer* bSizer15;
	bSizer15 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer16;
	bSizer16 = new wxBoxSizer( wxVERTICAL );

	m_staticText10 = new wxStaticText( this, wxID_ANY, wxT("FILTROS"), wxDefaultPosition, wxDefaultSize, 0 );
	m_staticText10->Wrap( -1 );
	m_staticText10->SetFont( wxFont( 18, wxFONTFAMILY_SWISS, wxFONTSTYLE_ITALIC, wxFONTWEIGHT_NORMAL, false, wxT("Arial Rounded MT Bold") ) );

	bSizer16->Add( m_staticText10, 0, wxALIGN_CENTER_HORIZONTAL|wxALL, 5 );


	bSizer15->Add( bSizer16, 0, wxEXPAND|wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer18;
	bSizer18 = new wxBoxSizer( wxVERTICAL );

	wxBoxSizer* bSizer19;
	bSizer19 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer24;
	bSizer24 = new wxBoxSizer( wxVERTICAL );

	m_finicioText = new wxStaticText( this, wxID_ANY, wxT("FECHA INICIO"), wxDefaultPosition, wxDefaultSize, 0 );
	m_finicioText->Wrap( -1 );
	bSizer24->Add( m_finicioText, 0, wxALIGN_CENTER_VERTICAL|wxALL|wxALIGN_RIGHT, 5 );

	m_ffinalText = new wxStaticText( this, wxID_ANY, wxT("FECHA FINAL"), wxDefaultPosition, wxDefaultSize, 0 );
	m_ffinalText->Wrap( -1 );
	bSizer24->Add( m_ffinalText, 0, wxALL|wxALIGN_CENTER_VERTICAL|wxALIGN_RIGHT, 5 );


	bSizer19->Add( bSizer24, 1, wxALIGN_RIGHT|wxALIGN_CENTER_VERTICAL, 5 );

	wxBoxSizer* bSizer25;
	bSizer25 = new wxBoxSizer( wxVERTICAL );

	m_finicioLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_finicioLabel, 0, wxALIGN_BOTTOM|wxALL, 5 );

	m_ffinalLabel = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer25->Add( m_ffinalLabel, 0, wxALL|wxALIGN_BOTTOM, 5 );


	bSizer19->Add( bSizer25, 1, wxALIGN_CENTER_HORIZONTAL|wxEXPAND, 5 );


	bSizer18->Add( bSizer19, 0, wxEXPAND, 5 );

	wxBoxSizer* bSizer20;
	bSizer20 = new wxBoxSizer( wxHORIZONTAL );

	wxBoxSizer* bSizer21;
	bSizer21 = new wxBoxSizer( wxVERTICAL );

	m_asuntoText2 = new wxStaticText( this, wxID_ANY, wxT("ASUNTO"), wxDefaultPosition, wxDefaultSize, 0 );
	m_asuntoText2->Wrap( -1 );
	bSizer21->Add( m_asuntoText2, 0, wxALL|wxALIGN_RIGHT, 5 );

	m_tipoText2 = new wxStaticText( this, wxID_ANY, wxT("TIPO"), wxDefaultPosition, wxDefaultSize, 0 );
	m_tipoText2->Wrap( -1 );
	bSizer21->Add( m_tipoText2, 0, wxALL|wxALIGN_RIGHT, 5 );


	bSizer20->Add( bSizer21, 1, wxALIGN_CENTER_HORIZONTAL, 5 );

	wxBoxSizer* bSizer22;
	bSizer22 = new wxBoxSizer( wxVERTICAL );

	m_asuntoLabel2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_asuntoLabel2, 0, wxALL, 5 );

	m_tipoLabel2 = new wxTextCtrl( this, wxID_ANY, wxEmptyString, wxDefaultPosition, wxDefaultSize, 0 );
	bSizer22->Add( m_tipoLabel2, 0, wxALL, 5 );


	bSizer20->Add( bSizer22, 1, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer18->Add( bSizer20, 1, wxEXPAND, 5 );

	wxBoxSizer* bSizer27;
	bSizer27 = new wxBoxSizer( wxHORIZONTAL );

	m_guardarButton = new wxButton( this, wxID_ANY, wxT("Guardar Filtros"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_guardarButton, 0, wxALL, 5 );

	m_quitarButton = new wxButton( this, wxID_ANY, wxT("Quitar Filtros"), wxDefaultPosition, wxDefaultSize, 0 );
	bSizer27->Add( m_quitarButton, 0, wxALL, 5 );


	bSizer18->Add( bSizer27, 0, wxALIGN_CENTER_HORIZONTAL, 5 );


	bSizer15->Add( bSizer18, 1, wxEXPAND, 5 );


	this->SetSizer( bSizer15 );
	this->Layout();

	this->Centre( wxBOTH );

	// Connect Events
	m_guardarButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Filtros::ClickGuardar ), NULL, this );
	m_quitarButton->Connect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Filtros::ClickQuitar ), NULL, this );
}

Filtros::~Filtros()
{
	// Disconnect Events
	m_guardarButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Filtros::ClickGuardar ), NULL, this );
	m_quitarButton->Disconnect( wxEVT_COMMAND_BUTTON_CLICKED, wxCommandEventHandler( Filtros::ClickQuitar ), NULL, this );

}
