
// GarageDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "Garage.h"
#include "GarageDlg.h"
#include "afxdialogex.h"
#include "DENGLU.h"
#include "ZHUCE.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CGarageDlg 对话框



CGarageDlg::CGarageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_GARAGE_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGarageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, Partition);
	DDX_Control(pDX, IDC_LIST1, c_list);
}

BEGIN_MESSAGE_MAP(CGarageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON4, &CGarageDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON12, &CGarageDlg::OnBnClickedButton12)
	ON_BN_CLICKED(IDC_BUTTON2, &CGarageDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON8, &CGarageDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CGarageDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON3, &CGarageDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CGarageDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CGarageDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CGarageDlg::OnBnClickedButton7)
END_MESSAGE_MAP()


// CGarageDlg 消息处理程序

BOOL CGarageDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	c_font.CreatePointFont(240, _T("华文行楷"), NULL);
	GetDlgItem(IDC_STATIC)->SetFont(&c_font);
	DWORD dwStyle = c_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT; 
	dwStyle |= LVS_EX_GRIDLINES;	    
	c_list.SetExtendedStyle(dwStyle); 
	c_list.InsertColumn(0, TEXT("车库分区"), 0, 125);
	c_list.InsertColumn(1, TEXT("可停车类型"), 0, 125);
	c_list.InsertColumn(2, TEXT("车位大小"), 0, 125);
	c_list.InsertColumn(3, TEXT("总车位数"), 0, 125);
	c_list.InsertColumn(4, TEXT("可用车位数"), 0, 125);
	Partition.AddString(TEXT("P1"));
	Partition.AddString(TEXT("P2"));
	Partition.AddString(TEXT("P3"));
	Partition.AddString(TEXT("P4"));
	Partition.AddString(TEXT("P5"));
	Partition.AddString(TEXT("全部"));
	Partition.SetCurSel(5);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CGarageDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CGarageDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CGarageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CGarageDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码,登录
	if (status == false)
	{
		DENGLU D;
		if (IDOK == D.DoModal())
		{
			Owner own(D.name.GetBuffer(), D.plate.GetBuffer(),D.idd.GetBuffer(),D.passWord.GetBuffer());
			status = DInter.Login(own);
			if (status)
			{
				MessageBox(TEXT("登录成功！"), TEXT("提示"));
				LListUpdate();
			}
			else
			{
				MessageBox(TEXT("无效信息，登录失败"), TEXT("提示"));
			}
		}
	}
	else
	{
		MessageBox(TEXT("请勿二次登录本系统"), TEXT("提示"));
	}
}


void CGarageDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	if (status == true)
	{
		string faq = "";
		vector<string> Q;
		vector<string> A;
		CString FilePath = _T(".\\FAQ.txt");
		ifstream in(FilePath, ios::in);
		if (in.is_open())
		{
			int tmp;
			in >> tmp;
			for (int i = 0; i < tmp; i++)
			{
				string tmp1, tmp2;
				in >> tmp1;
				in >> tmp2;
				Q.push_back(tmp1);
				A.push_back(tmp2);

			}
		}
		for (int i = 0; i < Q.size(); i++)
		{
			faq += Q[i];
			faq += "\n";
			faq += A[i];
			faq += "\n";
		}
		string phone;
		string website;
		in >> phone;
		in >> website;
		faq += phone;
		faq += "\n";
		faq += website;
		MessageBox(faq.c_str(), TEXT("FAQ"));
	}
	else
	{
		MessageBox(TEXT("请登录本系统"), TEXT("提示"));
	}
}


void CGarageDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT index;
	index = MessageBox(_T("确认退出系统吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (index == IDYES)
	{
		exit(0);
	}
	else
	{
		return;
	}
}

void CGarageDlg::LListUpdate()
{
	c_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < DInter.Partitions.size(); i++)
	{
		c_list.InsertItem(i, DInter.Partitions[i].parti.c_str());
		c_list.SetItemText(i, 1, DInter.Partitions[i].ttype.c_str());
		c_list.SetItemText(i, 2, DInter.Partitions[i].sizee.c_str());
		str.Format(TEXT("%d"), DInter.Partitions[i].sum);
		c_list.SetItemText(i,3, str);
		str.Format(TEXT("%d"), DInter.Partitions[i].Remaining);
		c_list.SetItemText(i, 4, str);
	}
}


void CGarageDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (status == true)
	{
		CString st;
		int index = Partition.GetCurSel();
		Partition.GetLBText(index, st);
		int res1, res2;
		if (st == "全部")
		{
			res1 = 0;
			res2 = 0;
			for (int i = 0; i < DInter.Partitions.size(); i++)
			{
				res1 += DInter.Partitions[i].Remaining;
				res2 += DInter.Partitions[i].sum;
			}
		}
		else
		{
			res1 = DInter.Partitions[index].Remaining;
			res2 = DInter.Partitions[index].sum;
		}
		CString we;
		we.Format(TEXT("当前剩余车位：%d\n总车位：%d"), res1, res2);
		MessageBox(we, TEXT("车位查询"));
	}
	else
	{
		MessageBox(TEXT("请登录本系统"), TEXT("提示"));
	}
}


void CGarageDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (status == true)
	{
		int l1 = DInter.EEnter[DInter.curIndex].size();
		int l2 = DInter.Goout[DInter.curIndex].size();

		if (l1 == l2 && l1 > 0)
		{
			CString strr,strr2;
			string s1 = DInter.EEnter[DInter.curIndex][l1 - 1];
			string s2 = DInter.Goout[DInter.curIndex][l2 - 1];
			std::tm tm1 = DInter.string_to_tm(s1);
			std::chrono::system_clock::time_point tp1 = DInter.tm_to_time_point(tm1);
			std::tm tm2 = DInter.string_to_tm(s2);
			std::chrono::system_clock::time_point tp2 = DInter.tm_to_time_point(tm2);
			auto duration = tp2 - tp1;
			auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
			double fee = seconds * 0.001;
			strr.Format(TEXT("车牌号：%s\n入库时间：%s\n出库时间：%s\n本次停车费用为：%f\n发票已开具，请在Invoice.txt中查看"), DInter.curUser.plate.c_str(), DInter.EEnter[DInter.curIndex][l1 - 1].c_str(), DInter.Goout[DInter.curIndex][l1 - 1].c_str(), fee);
			strr2.Format(TEXT("车牌号：%s\n入库时间：%s\n出库时间：%s\n本次停车费用为：%f"), DInter.curUser.plate.c_str(), DInter.EEnter[DInter.curIndex][l1 - 1].c_str(), DInter.Goout[DInter.curIndex][l1 - 1].c_str(), fee);
			CString Path = _T(".\\Invoice.txt");
			ofstream out(Path, ios::out);
			out << strr2;
			MessageBox(strr, TEXT("提示"));
		}
		else if(l1 == 0)
		{
			MessageBox(TEXT("此车无停车记录"), TEXT("提示"));
		}
		else
		{
			MessageBox(TEXT("此车仍在库中，出库才可开具发票"), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请登录本系统"), TEXT("提示"));
	}
}


void CGarageDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	ZHUCE zz;
	if (IDOK == zz.DoModal())
	{
		Owner oow(zz.account.GetBuffer(), zz.plate.GetBuffer(), zz.ident.GetBuffer(), zz.password.GetBuffer());
		if (DInter.RRegister(oow, zz.sure.GetBuffer()) )
		{
			status = false;//重新登录
			MessageBox(TEXT("新车户注册成功"), TEXT("提示"));
		}
		else
		{
			MessageBox(TEXT("很遗憾，注册失败"), TEXT("提示"));
		}
	}
}


void CGarageDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码,入库
	if (status == true)
	{
		if (DInter.EEnter[DInter.curIndex].size() == DInter.Goout[DInter.curIndex].size())//保证上一次操作是出库
		{
			int index = c_list.GetSelectionMark();
			if (index > -1)
			{
				if (DInter.Partitions[index].Remaining > 0)
				{
					DInter.Partitions[index].Remaining--;
					DInter.cars[DInter.curIndex] = index;
					CString FilePath = _T(".\\Partition.txt");
					ofstream oout(FilePath, ios::out);
					if (oout.is_open())
					{
						oout << DInter.Partitions.size() << endl;
						for (int i = 0; i < DInter.Partitions.size(); i++)
						{
							DInter.Partitions[i].OUTput(oout);
						}
					}
					LListUpdate();
					auto start_time = std::chrono::system_clock::now();
					string ss = DInter.get_time_str(start_time);
					DInter.EEnter[DInter.curIndex].push_back(ss);
					CString Path = _T(".\\入库记录.txt");
					ofstream out(Path, ios::out);
					if (out.is_open())
					{
						out << DInter.Owners.size() << "\n";
						for (int i = 0; i < DInter.Owners.size(); i++)
						{
							for (int j = 0; j < DInter.EEnter[i].size(); j++)
							{
								out << DInter.EEnter[i][j] << "\t";
							}
							out << "-1" << "\n";
						}
						out.close();
					}
					CString Path4 = _T(".\\CarSite.txt");
					ofstream out3(Path4, ios::out);
					if (out3.is_open())
					{
						out3 << DInter.cars.size() << "\n";
						for (int i = 0; i < DInter.cars.size(); i++)
						{
							out3 << DInter.cars[i] << "\n";
						}
					}
					CString strr;
					strr.Format(TEXT("时间\t%s\n\t入库%s成功"),ss.c_str(),DInter.Partitions[index].parti.c_str());
					MessageBox(strr, TEXT("提示"));
				}
				else
				{
					MessageBox("该分区无可用车位，请重新选择", TEXT("提示"));
				}
				
			}
			else
			{
				MessageBox("请选择车库分区", TEXT("提示"));
			}
			
		}
		else
		{
			MessageBox("已在车库中，请勿重复操作", TEXT("提示"));
		}
		
	}
	else
	{
		MessageBox(TEXT("请登录本系统"), TEXT("提示"));
	}
}


void CGarageDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码，出库
	if (status == true)
	{
		if (DInter.EEnter[DInter.curIndex].size() == DInter.Goout[DInter.curIndex].size()+1)//保证上一次操作是出库
		{
			int tmp_ans = DInter.cars[DInter.curIndex];
			DInter.Partitions[DInter.cars[DInter.curIndex]].Remaining++;
			DInter.cars[DInter.curIndex] = -1;
			CString FilePath = _T(".\\Partition.txt");
			ofstream oout(FilePath, ios::out);
			if (oout.is_open())
			{
				oout << DInter.Partitions.size() << endl;
				for (int i = 0; i < DInter.Partitions.size(); i++)
				{
					DInter.Partitions[i].OUTput(oout);
				}
			}
			LListUpdate();
			auto end_time = std::chrono::system_clock::now();
			string ss = DInter.get_time_str(end_time);
			DInter.Goout[DInter.curIndex].push_back(ss);
			CString Path = _T(".\\出库记录.txt");
			ofstream out(Path, ios::out);
			if (out.is_open())
			{
				out << DInter.Owners.size() << "\n";
				for (int i = 0; i < DInter.Owners.size(); i++)
				{
					for (int j = 0; j < DInter.Goout[i].size(); j++)
					{
						out << DInter.Goout[i][j] << "\t";
					}
					out << "-1" << "\n";
				}
				out.close();
			}
			CString Path4 = _T(".\\CarSite.txt");
			ofstream out3(Path4, ios::out);
			if (out3.is_open())
			{
				out3 << DInter.cars.size() << "\n";
				for (int i = 0; i < DInter.cars.size(); i++)
				{
					out3 << DInter.cars[i] << "\n";
				}
			}
			CString strr;
			strr.Format(TEXT("时间\t%s\n\t出库%s成功"), ss.c_str(), DInter.Partitions[tmp_ans].parti.c_str());
			MessageBox(strr, TEXT("提示"));

		}
		else
		{
			MessageBox("已在库外，请勿重复操作", TEXT("提示"));
		}

	}
	else
	{
		MessageBox(TEXT("请登录本系统"), TEXT("提示"));
	}
}


void CGarageDlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (status == true)
	{
		int l1 = DInter.EEnter[DInter.curIndex].size();
		int l2 = DInter.Goout[DInter.curIndex].size();
		if (l1 == l2)
		{
			string s1 = DInter.EEnter[DInter.curIndex][l1 - 1];
			string s2 = DInter.Goout[DInter.curIndex][l2 - 1];
			std::tm tm1 = DInter.string_to_tm(s1);
			std::chrono::system_clock::time_point tp1 = DInter.tm_to_time_point(tm1);
			std::tm tm2 = DInter.string_to_tm(s2);
			std::chrono::system_clock::time_point tp2 = DInter.tm_to_time_point(tm2);
			auto duration = tp2 - tp1;
			auto seconds = std::chrono::duration_cast<std::chrono::seconds>(duration).count();
			double fee = seconds * 0.001;
			last_fee = fee;
			CString strr;
			strr.Format(TEXT("本次停车费用为：%f"), fee);
			MessageBox(strr, TEXT("提示"));
		}
		else if (l1 == 0)
		{
			MessageBox(TEXT("此车无停车记录"), TEXT("提示"));
		}
		else
		{
			MessageBox(TEXT("在库中，请出库再计费"), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请登录本系统"), TEXT("提示"));
	}
}
