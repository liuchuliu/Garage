#pragma once
#include "afxdialogex.h"


// ZHUCE 对话框

class ZHUCE : public CDialogEx
{
	DECLARE_DYNAMIC(ZHUCE)

public:
	ZHUCE(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ZHUCE();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZHUCE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString account;
	CString plate;
	CString ident;
	CString password;
	
	CString sure;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
