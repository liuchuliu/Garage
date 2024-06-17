// DENGLU.cpp: 实现文件
//

#include "pch.h"
#include "Garage.h"
#include "afxdialogex.h"
#include "DENGLU.h"


// DENGLU 对话框

IMPLEMENT_DYNAMIC(DENGLU, CDialogEx)

DENGLU::DENGLU(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DENGLU, pParent)
	, name(_T(""))
	, plate(_T(""))
	, idd(_T(""))
	, passWord(_T(""))
{

}

DENGLU::~DENGLU()
{
}

void DENGLU::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, name);
	DDX_Text(pDX, IDC_EDIT2, plate);
	DDX_Text(pDX, IDC_EDIT3, idd);
	DDX_Text(pDX, IDC_EDIT4, passWord);
}


BEGIN_MESSAGE_MAP(DENGLU, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &DENGLU::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DENGLU::OnBnClickedButton3)
END_MESSAGE_MAP()


// DENGLU 消息处理程序


void DENGLU::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (name == TEXT("") || plate == TEXT("") || idd == TEXT("") || passWord == TEXT(""))
	{
		MessageBox(TEXT("信息不完整，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


void DENGLU::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
