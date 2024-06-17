#include "pch.h"
#include "CFuntions.h"

bool CFuntions::Login(Owner wner)
{
    CString FilePath1 = _T(".\\车主信息.txt");
    CString FilePath2 = _T(".\\Partition.txt");
    CString FilePath3 = _T(".\\入库记录.txt");
    CString FilePath4 = _T(".\\出库记录.txt");
    CString FilePath5 = _T(".\\CarSite.txt");
    ifstream in1(FilePath1, ios::in);
    ifstream in2(FilePath2, ios::in);
    ifstream in3(FilePath3, ios::in);
    ifstream in4(FilePath4, ios::in);
    ifstream in5(FilePath5, ios::in);
    Owners.clear();
    int num1, num2,num3,num4,num5;
    if (in1.is_open())
    {
        in1 >> num1;
        for (int i = 0; i < num1; i++)
        {
            Owner s;
            s.INput(in1);
            Owners.push_back(s);
        }
    }
    for (int i = 0; i < Owners.size(); i++)
    {
        if (wner.Account == Owners[i].Account && wner.plate == Owners[i].plate && wner.id == Owners[i].id && wner.password == Owners[i].password)
        {
            curUser = wner;
            curIndex = i;
            Partitions.clear();
            cars.clear();
            if (in2.is_open())
            {
                in2 >> num2;
                for (int j = 0; j < num2; j++)
                {
                    CPartition pp;
                    pp.INput(in2);
                    Partitions.push_back(pp);
                }
            }
            if (in5.is_open())
            {
                in5 >> num5;
                for (int j = 0; j < num5; j++)
                {
                    int tmp;
                    in5 >> tmp;
                    cars.push_back(tmp);
                }
            }
            if(in3.is_open())
            {
                in3 >> num3;
                vector<vector<string>>   ntrr(num3 + 1);
                for (int j = 0; j < num3; j++)
                {
                    string str;
                    while (in3 >> str && str != "-1")
                    {
                        ntrr[j].push_back(str);
                    }
                }
                EEnter = ntrr;
            }
            
            
            if (in4.is_open())
            {
                in4 >> num4;
                vector<vector<string>>   ntrr(num4 + 1);
                for (int j = 0; j < num4; j++)
                {
                    string str;
                    while (in4 >> str && str != "-1")
                    {
                        ntrr[j].push_back(str);
                    }
                }
                Goout = ntrr;
            }
            return true;
        }
    }
    return false;
}

bool CFuntions::RRegister(Owner pt, CString surepassword)
{
    if (pt.password.c_str() != surepassword)
    {
        return false;
    }
    CString Path = _T(".\\车主信息.txt");
    CString Path2 = _T(".\\入库记录.txt");
    CString Path3 = _T(".\\出库记录.txt");
    CString Path4 = _T(".\\CarSite.txt");
    Owners.clear();
    cars.clear();
    ifstream in(Path, ios::in);
    ifstream in2(Path2, ios::in);
    ifstream in3(Path3, ios::in);
    ifstream in4(Path4, ios::in);
    int num;
    if (in.is_open())
    {
        in >> num;
        for (int i = 0; i < num; i++)
        {
            Owner SS;
            SS.INput(in);
            Owners.push_back(SS);
        }
    }
    if (in4.is_open())
    {
        in4 >> num;
        for (int i = 0; i < num; i++)
        {
            int tmp;
            in4 >> tmp;
            cars.push_back(tmp);
        }
    }
    cars.push_back(-1);
    if (in2.is_open())
    {
        in2 >> num;
        vector<vector<string>> IN_N(num + 1);
        for (int i = 0; i < num; i++)
        {
            string tr;
            while (in2 >> tr && tr != "-1")
            {
                IN_N[i].push_back(tr);
            }
        }
        EEnter = IN_N;
    }
    if (in3.is_open())
    {
        in3 >> num;
        vector<vector<string>> OUT_T(num + 1);
        for (int i = 0; i < num; i++)
        {
            string tr;
            while (in3 >> tr && tr != "-1")
            {
                OUT_T[i].push_back(tr);
            }
        }
        Goout = OUT_T;
    }
    Owners.push_back(pt);
    //注册信息写回文档
    ofstream out(Path2, ios::out);
    ofstream out2(Path3, ios::out);
    ofstream out3(Path4, ios::out);
    if (out3.is_open())
    {
        out3 << cars.size() << "\n";
        for (int i = 0; i < cars.size(); i++)
        {
            out3 << cars[i] << "\n";
        }
    }
    if (out.is_open())
    {
        out << Owners.size() << "\n";
        for (int i = 0; i < Owners.size(); i++)
        {
            for (int j = 0; j < EEnter[i].size(); j++)
            {
                out  << EEnter[i][j] << "\t";
            }
            out << "-1" << "\n";
        }
        out.close();
    }
    if (out2.is_open())
    {
        out2 << Owners.size() << "\n";
        for (int i = 0; i < Owners.size(); i++)
        {
            for (int j = 0; j < Goout[i].size(); j++)
            {
                out2 << "\t" << Goout[i][j];
            }
            out2 << "\t" << "-1" << "\n";
        }
        out2.close();
    }
    SavetoFile(Path);
    return true;
}

void CFuntions::SavetoFile(CString Path)
{
    ofstream out(Path, ios::out);
    if (out.is_open())
    {
        out << Owners.size() << endl;
        for (int i = 0; i < Owners.size(); i++)
        {
            Owners[i].OUTput(out);
        }
        out.close();
    }
}

string CFuntions::get_time_str(const std::chrono::system_clock::time_point& tp)
{
    auto time_t = std::chrono::system_clock::to_time_t(tp);
    std::tm local_time;
    // 使用localtime_s代替localtime
    localtime_s(&local_time, &time_t);
    std::ostringstream oss;
    oss << std::put_time(&local_time, "%Y-%m-%d,%H:%M:%S");
    return oss.str();
}

std::tm CFuntions::string_to_tm(const std::string& s)
{
    std::tm tm = {};
    std::istringstream iss(s);
    iss >> std::get_time(&tm, "%Y-%m-%d,%H:%M:%S");
    return tm;
}

std::chrono::system_clock::time_point CFuntions::tm_to_time_point(const std::tm& tm_in)
{
    std::tm tm = tm_in; // 复制tm_in到一个非const的tm对象中  
    std::time_t time_since_epoch = std::mktime(&tm);
    return std::chrono::system_clock::from_time_t(time_since_epoch);
}
