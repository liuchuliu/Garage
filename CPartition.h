#pragma once
class CPartition
{
public:
	CPartition();
	CPartition(string parti, string ttype, string sizee, int sum, int Remain);
	string parti;
	string ttype;
	string sizee;
	int sum;
	void INput(ifstream& in);
	void OUTput(ofstream& out);
	int Remaining;
};

