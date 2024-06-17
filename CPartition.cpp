#include "pch.h"
#include "CPartition.h"

CPartition::CPartition()
{
}

CPartition::CPartition(string parti, string ttype, string sizee, int sum, int Remain)
{
	this->parti = parti;
	this->ttype = ttype;
	this->sizee = sizee;
	this->sum = sum;
	this->Remaining = Remain;
}

void CPartition::INput(ifstream& in)
{
	in >> parti;
	in >> ttype;
	in >> sizee;
	in >> sum;
	in >> Remaining;
}

void CPartition::OUTput(ofstream& out)
{
	out << parti << "\t" << ttype << "\t" << sizee << "\t" << sum << "\t" << Remaining << "\n";
}
