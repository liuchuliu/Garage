#pragma once
class Owner
{
public:
	Owner();
	Owner(string acc, string plate, string id, string password);
	string Account;
	string plate;
	string id;
	string password;
	void INput(ifstream& in);
	void OUTput(ofstream& out);
};

