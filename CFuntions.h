#pragma once
#include "Owner.h"
#include "CPartition.h"

class CFuntions
{
public:
	vector<Owner> Owners;
	vector<CPartition> Partitions;
	bool Login(Owner wner);
	bool RRegister(Owner pt, CString surepassword);
	void SavetoFile(CString Path);
	Owner curUser;
	int curIndex; 
	vector<vector<string>> EEnter;  //����¼
	vector<vector<string>> Goout;  //�����¼
	//��ʱ��ת��Ϊ�ַ���
	string get_time_str(const std::chrono::system_clock::time_point& tp);
	// ���ַ���ת��Ϊstd::tm�ṹ  
	std::tm string_to_tm(const std::string& s);
	// ��std::tm�ṹת��Ϊstd::chrono::system_clock::time_point  
	std::chrono::system_clock::time_point tm_to_time_point(const std::tm& tm_in);
	vector<int> cars;
};

