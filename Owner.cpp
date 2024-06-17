#include "pch.h"
#include "Owner.h"

Owner::Owner()
{
}

Owner::Owner(string acc, string plate, string id, string password)
{
	this->Account = acc;
	this->plate = plate;
	this->id = id;
	this->password = password;
}

void Owner::INput(ifstream& in)
{
	in >> Account >> plate >> id >> password;
}

void Owner::OUTput(ofstream& out)
{
	out << Account <<"\t" << plate <<"\t" << id <<"\t" << password << "\n";
}
