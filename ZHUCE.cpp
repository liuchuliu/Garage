// ZHUCE.cpp: 实现文件
//

#include "pch.h"
#include "Garage.h"
#include "afxdialogex.h"
#include "ZHUCE.h"


// ZHUCE 对话框

IMPLEMENT_DYNAMIC(ZHUCE, CDialogEx)

ZHUCE::ZHUCE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ZHUCE, pParent)
	, account(_T(""))
	, plate(_T(""))
	, ident(_T(""))
	, password(_T(""))
	, sure(_T(""))
{

}

ZHUCE::~ZHUCE()
{
}

void ZHUCE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, account);
	DDX_Text(pDX, IDC_EDIT5, plate);
	DDX_Text(pDX, IDC_EDIT6, ident);
	DDX_Text(pDX, IDC_EDIT7, password);
	DDX_Text(pDX, IDC_EDIT8, sure);
}


BEGIN_MESSAGE_MAP(ZHUCE, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &ZHUCE::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &ZHUCE::OnBnClickedButton2)
END_MESSAGE_MAP()


// ZHUCE 消息处理程序


void ZHUCE::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (account == TEXT("") || plate == TEXT("") || ident == TEXT("") || password == TEXT("") || sure == TEXT(""))
	{
		MessageBox(TEXT("注册信息不足，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


void ZHUCE::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
