#ifndef PERSONA_H
#define PERSONA_H
#include <string>
#include <fstream>

struct User{
	char name[256];
	char password[256];
	char archi[256];
};


class Persona {
private:
	std::string name;
	std::string password;
	std::string archi;
public:
	Persona(std::string name="", std::string password="");
	void GuardarEnBinario(std::ofstream &archivo);
	void LeerDesdeBinario(std::ifstream &archivo);
	std::string VerName() const;
	std::string VerPassword() const;
	std::string VerArchi() const;

};

#endif

