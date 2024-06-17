#pragma once
#include "afxdialogex.h"


// DENGLU 对话框

class DENGLU : public CDialogEx
{
	DECLARE_DYNAMIC(DENGLU)

public:
	DENGLU(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~DENGLU();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DENGLU };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString name;
	CString plate;
	CString idd;
	CString passWord;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
};
