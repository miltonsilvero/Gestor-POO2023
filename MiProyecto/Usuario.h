#ifndef USUARIO_H
#define USUARIO_H
#include <vector>
#include <string>
#include "Persona.h"


class Usuario {
private:
	std::string nombreLista = "BD_Usuarios.dat";
	std::vector<Persona> lista_usuarios;
	struct aux{
		char name[256];
		char password[256];
		char archi[256];
	};
	std::string nombreArchi;
public:
	Usuario();
	void AgregarUsuario(const Persona &p);
	bool BuscarUsuario(const Persona &p);
	bool Registrado(const Persona &p);
	void Cargar();
	void Guardar();
	int CantidadDatos();
	std::string NombreArchivo();
	std::vector<Persona> usuarios();
	void BorrarUsuario(int i);
	
};

#endif

