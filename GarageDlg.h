
// GarageDlg.h: 头文件
//

#pragma once
#include "CFuntions.h"

// CGarageDlg 对话框
class CGarageDlg : public CDialogEx
{
// 构造
public:
	CGarageDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GARAGE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CComboBox Partition;
	CListCtrl c_list;
	afx_msg void OnBnClickedButton4();
	CFont c_font;
	afx_msg void OnBnClickedButton12();
	afx_msg void OnBnClickedButton2();
	bool status = false;
	CFuntions DInter;
	void LListUpdate();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	double last_fee = -1;
};
