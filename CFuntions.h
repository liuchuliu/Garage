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
	vector<vector<string>> EEnter;  //入库记录
	vector<vector<string>> Goout;  //出库记录
	//将时间转化为字符串
	string get_time_str(const std::chrono::system_clock::time_point& tp);
	// 将字符串转换为std::tm结构  
	std::tm string_to_tm(const std::string& s);
	// 将std::tm结构转换为std::chrono::system_clock::time_point  
	std::chrono::system_clock::time_point tm_to_time_point(const std::tm& tm_in);
	vector<int> cars;
};

