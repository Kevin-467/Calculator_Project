//Userlabel meaning： "v":visitor【访客】 "u":registered_user【已注册用户】)
#include<iostream>
#include<cstdio>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<iterator>//迭代器，stl容器用
#include<cctype>
#include<cmath>
#include<string>
#include<utility>
#include<ctime>
#include<Windows.h>//显示时间
#include "GeometricSolidCalc.h"
#include "ComplexCalc.h"
#include "HighCalculation.h"
using namespace std;
typedef  unsigned long long ull;
typedef long long ll;

void welcome_page();//首页
void login_page();//登录界面，让用户进行登录到计算器中,登录前询问用户是否忘记密码，如忘记密码，则进入重置密码界面
void signup_page();//注册界面，让新用户注册账户登录界面
void main_page(string JumptoLabel);//主页
void PersoanlCenter(string JumptoLabel);//个人中心界面
void calculator_page(string Userlabel);//计算器界面
void OtherCalculationPage(string Userlabel);//其他计算界面
//功能
void resetUsername(string JumptoLabel);//重置用户名界面
void resetPassword();//重置密码界面，让忘记密码的用户重置密码
void CancelAccount();//注销账号
bool prime(ull num);//素数判断
void HighIntegarCalc(string Userlabel);//高精度整数运算
void DemicalCalc(string Userlabel);//小数高精度运算
void ComplexCalc(string Userlabel);//复数运算
void TriFunctionCalc(string Userlabel);//三角函数模块
void LogExpCalc(string Userlabel);//对指数运算
void PrimeMoudle(string Userlabel);//素数模块
void ShapeCalc(string Userlabel);//周长面积计算
void GeoSolidCalc(string Userlabel);//体积计算
void BMICalc(string Userlabel);//BMI计算
void TriFunc(string Userlabel);//三角函数
void InverseTriFunc(string Userlabel);//反三角函数
void HighIntPlus(string Userlabel);
void HighIntMinus(string Userlabel);
void HighIntMultiply(string Userlabel);
void HighIntDivide(string Userlabel);
void HighIntMod(string Userlabel);
void HighFactorialCalc(string Userlabel);//高精度阶乘运算
bool CheckInput (string username);
void ShowSystemTime();
void IfContainerEmpty();
char Exitchoice(string ChoiceInput);
pair<bool, double> VerifyDemicalValid(string demical,double l,double r);
bool cmpnum(string a, string b);
void readuserdata(string In_useraccount, string In_blacklistuser);
int cmp(int a[], int b[]);
void numcpy(int p[], int q[], int times);
void minu(int a[], int b[]);
void print(int res[]);
//用户信息、黑名单文件、存储用户数据的容器
const string userinfoFile = R"(F:\课程设计（程序设计基础）-Calculator\Userdata\userinfo.txt)";//账户信息文件
const string blacklistFile = R"(F:\课程设计（程序设计基础）-Calculator\Userdata\blacklist.txt)";//黑名单用户文件
vector<string> Usernamelist, Passwordlist,EmailAddressList,BlacklistUser;
const double pi = acos(-1.0);
int factorres[10000000] ;
//主函数
int main()
{
    welcome_page();
    return 0;
}

void welcome_page()//首页
{
    string welcomePageOption;char WelcomePageChoice;
    cout << " ";
    for (int i = 0; i < 103 ; i++){cout << "*";}
    cout << endl;
    cout << " *  11        11        11  11111111111  11        1111111111  1111111111  111        111  1111111111  *" << endl;                                          
    cout << " *   11      1111      11   11           11        11          11      11  1111      1111  11          *" << endl;
    cout << " *    11    11  11    11    1111111111   11        11          11      11  11 11    11 11  1111111111  *" << endl;
    cout << " *     11  11    11  11     11           11        11          11      11  11  11  11  11  11          *" << endl;
    cout << " *      1111      1111      11111111111  11111111  1111111111  1111111111  11   1111   11  1111111111  *" << endl;
    cout << " ";
    for (int i = 0; i < 103; i++){cout << "*";}
    cout << endl;
    cout << endl;
    for (int i = 0; i < 40; i++) { cout << "-"; }
    cout << " 欢 迎 使 用 计 算 器 !） " ;
    for (int i = 0; i < 41; i++) { cout << "-"; }
    cout << "\n                                        【  请将窗口全屏使用! 】\n\n";
    ShowSystemTime();//显示时间
    while (true)
    {
        int out = 0;
        cout << "\n功 能 菜 单:\n1.试用/游客登录\n2.登录\n3.注册\n4.找回密码\n5.退出\n\n";
        cout << "请输入所需功能【1、2、3、4】:";
        getline(cin,welcomePageOption);
        WelcomePageChoice = welcomePageOption[0];
        if (!('1' <= WelcomePageChoice && WelcomePageChoice <= '5' && welcomePageOption.length() == 1))
        {
            cout << "您的输入有误，请重新输入!" << endl;
            out++;
        }
        if (out == 0) { break; }
    }
    if (WelcomePageChoice == '1'){main_page("v");}
    else if(WelcomePageChoice=='2'){login_page();}
    else if (WelcomePageChoice == '3') {  signup_page();}
    else if (WelcomePageChoice == '4'){resetPassword();}
    else if (WelcomePageChoice == '5')
    {
        cout << "\n\n----------     再      见      !   ----------\n\n";
        cout << "           欢  迎  下  次  使  用           \n\n";
    }
}
void signup_page()//注册界面
{
    IfContainerEmpty();
    string newUsername,newPassword,confirmedPassword;
    string GetExistUser_Signuppage,GetBlacklistUser_SignupPage;  
    readuserdata(GetExistUser_Signuppage, GetBlacklistUser_SignupPage);
    cout << "-------------- 注 册 -------------\n";
    while (true)
    {
        int out0 = 0;
        cout << "请输入用户名【用户名至少含有6个字符，且每个字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】:";
        getline(cin, newUsername);
        //检查用户名是否符合规范
        if (CheckInput(newUsername)==false)
        {
            out0++; cout << "输入错误，用户名至少含有6个字符，且每个字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种\n";
            continue;
        }
        //检测用户名是否存在
        if(out0==0)
        {
            for (vector<string>::const_iterator it1 = Usernamelist.begin(); it1 != Usernamelist.end(); it1++)
            {
                if (newUsername == *it1) { out0++; break; }
            }
        }
        if (out0 == 1)
        {
            cout << "用户名已存在,请重新输入！" << endl;
            continue;
        }
        //检测用户名是否在黑名单中
        for (vector<string>::const_iterator it2 = BlacklistUser.begin(); it2 != BlacklistUser.end(); it2++)
        {
            if (newUsername == *it2) { out0++; break; }
        }
        if (out0 == 1)
        {
            cout << "用户名已锁定,请重新输入！" << endl;
            continue;
        }
        if (out0 == 0) { break; }//退出用户名键入与检测
    }
    ofstream writeuserinfo(userinfoFile, ios::app);
    //if (writeuserinfo.is_open() == false) { cout << "File open failed!\n"; }
    writeuserinfo << newUsername << ":";
    IfContainerEmpty();
    while (true)
    {
        int out1 = 0;
        cout << "请输入新密码:";
        getline(cin ,newPassword);
        if (CheckInput(newPassword))
        {
            while(true)
            {
                cout << "请再次输入密码：";
                getline(cin , confirmedPassword);
                if (newPassword == confirmedPassword)
                {
                    writeuserinfo << newPassword << '\n';//写入新注册用户的密码
                    writeuserinfo.close();
                    cout << "\n注册成功!\n\n";
                    out1 = 0;
                    break;
                }
                else {cout << "两次输入的密码不一致，请重新输入\n";}    
            }
            break;
        }
        else { cout << "密码格式错误，请重新输入！【密码至少含有6个字符，且每个字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】" << endl; out1++; }
    }
    welcome_page();
} 
void login_page()//登录界面 
{   
    char ForgetState;
    IfContainerEmpty();
    string GetForgetState, Username, Password, OriginPassword;
    string GetBlacklistUser_loginPage, GetExistUser_loginpage;
    readuserdata(GetExistUser_loginpage, GetBlacklistUser_loginPage);
    cout << "----------- 已注册用户登录 ------------\n\n";   
    while (true)
    {
        cout << "忘记密码？（1.是，2.否):";//询问是否忘记密码
        int out3 = 0;
        getline(cin, GetForgetState);
        ForgetState = GetForgetState[0];
        if (!('1' <= ForgetState && ForgetState <= '2' && GetForgetState.length() == 1))
        {
            cout << "您的输入有误，请重新输入!" << endl;
            out3++;
        }
        if (out3 == 0) { break; }
    }
    if (ForgetState == '1') {resetPassword();}
    if (ForgetState == '2')
    {
        int username_index=0;
        while (true)//输入并检测用户名
        {
            cout << "\n请输入用户名：";
            int out4 = 0;
            getline(cin, Username);
            if (CheckInput(Username) == false && Username != "v") { out4++; cout << "用户名不符合规范！【用户名至少含有6个字符，且每个字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】" << endl; }
            if (out4 == 0)
            {
                bool flag0 = false;
                for (int i = 0; i < Usernamelist.size(); i++)
                {
                    if (Username == Usernamelist.at(i)) { username_index = i; flag0 = true; break; }
                }
                if (flag0 == false) { cout << "用户名不存在!\n"; out4++; }
            }
            if (out4 == 0)
            {
                bool flag1 = true;
                for (int i = 0; i < BlacklistUser.size(); i++)
                {
                    if (Usernamelist.at(username_index) == BlacklistUser.at(i)) { flag1 = false; break; }
                }
                if (flag1 == false)
                {
                    out4++; cout << "用户名已被锁定\n";
                }
            }
            if (out4 == 0) { break; }
        }
        //输入并检测密码
        int times = 3;
        OriginPassword = Passwordlist.at(username_index);
        int ExitLoginPage = 0;
        while (times--)
        {
            cout << "请输入密码：";
            getline(cin, Password);
            int out5 = 0;
            while (true)
            {
                if (CheckInput(Password) == false) { out5++; cout << "输入错误，密码不符合规范！【密码至少含有6个字符，且每个字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】" << endl; }
                if (out5 == 0) { break; }
                if (out5 == 1) { break; }
            }
            if (out5 == 0 && Password == OriginPassword) { cout << "登录成功!\n"; break; }
            else
            {
                if (times >= 1 && out5 == 1) { printf("您还有%d次机会\n", times); }
                else if (times >= 1 && out5 == 0) { printf("密码错误,您还有%d次机会\n", times); }
                else
                {
                    ofstream writeblacklistuser(blacklistFile, ios::app);
                    if (writeblacklistuser.is_open() == false) { cout << "File open failed!\n"; }
                    bool flag3 = true;
                    for (int i = 0; i < BlacklistUser.size(); i++)
                    {
                        if (Usernamelist.at(username_index) == BlacklistUser.at(i)) { { flag3 = false; break; } }
                    }
                    if (flag3) { writeblacklistuser << Usernamelist.at(username_index) << " "; }
                    cout << "您的帐户已被锁定，请稍后重试\n";
                    ExitLoginPage = 1;
                    writeblacklistuser.close();
                    break;
                }
            }
            
        }
        if (ExitLoginPage == 1)
        {
            cout << "\n--------------------------------------------- 即将返回首页! ---------------------------------------------\n\n";
            welcome_page();
        }
        else
        {
            cout << "\n---------- 即将您登入主页! ----------\n\n";
            main_page(Username); 
        }
    }
    IfContainerEmpty();
}
void main_page(string JumptoLabel)//主页
{
    string Username = JumptoLabel;
    string MainPageOption; char MainPageChoice;
    if (JumptoLabel != "v" && JumptoLabel != "u") { cout << "欢迎回来, " << JumptoLabel << " !\n"; }
    else if (JumptoLabel == "v") { cout << "访客，欢迎登陆！\n"; }
    ShowSystemTime();
    while (true)
    {
        int exit1 = 0; 
        cout << "\n功能菜单：\n1.计算器\n2.其他计算\n3.个人中心【仅限已注册用户使用】\n4.退出程序/退出登录\n\n";
        cout << "请选择所需功能【输入1、2、3、4】:";
        getline(cin, MainPageOption);
        MainPageChoice = MainPageOption[0];
        if(!('1'<=MainPageChoice&&MainPageChoice<='4'&&MainPageOption.length()==1))
        {exit1++; cout << "输入错误，请重新选择！\n\n"; }
        if (exit1 == 0) { break; }
    }
    if (MainPageChoice == '1')
    {
        if (JumptoLabel == "v" || JumptoLabel == "u") { calculator_page(JumptoLabel); }
        else{ calculator_page("u"); }
    }
    if (MainPageChoice == '2')
    {
        if (JumptoLabel == "v" || JumptoLabel == "u") { OtherCalculationPage(JumptoLabel); }
        else { OtherCalculationPage("u"); }
    }
    if (MainPageChoice == '3')
    {
        if (JumptoLabel == "v") { cerr << "您暂无访问权限！\n\n"; Sleep(1000);main_page(JumptoLabel); }
        else{PersoanlCenter(JumptoLabel);}  
    }
    if (MainPageChoice == '4') {welcome_page();}  
}
void PersoanlCenter(string JumptoLabel)//个人中心界面
{
    cout << "\n----- 欢迎进入个人中心！-----\n\n";
    string PersonCenterOption; char PersonCenterChoice;
    
    while (true)
    {
        int exit2 = 0;
        cout << "功能菜单：\n1.修改用户名\n2.修改密码\n3.切换账号\n4.账号注销\n5.退出个人中心\n";
        cout << "请选择所需功能【输入1、2、3、4、5】:";
        getline(cin, PersonCenterOption);
        PersonCenterChoice = PersonCenterOption[0];
        if (!('1' <= PersonCenterChoice && PersonCenterChoice <= '5' && PersonCenterOption.length() == 1))
        {
            exit2++; cout << "输入错误，请重新选择！\n\n";
        }
        if (exit2 == 0) { break; }
    }
    if (PersonCenterChoice == '1'){resetUsername(JumptoLabel);}
    if (PersonCenterChoice == '2'){ resetPassword();}
    if (PersonCenterChoice == '3')
    {
        cout << "请登录所需切换的账号!\n\n";
        login_page();
    }
    if (PersonCenterChoice == '4'){CancelAccount();}
    if (PersonCenterChoice == '5'){main_page(JumptoLabel);} 
}
void calculator_page(string Userlabel)//计算器界面
{
    cout << "\n----- 欢迎进入计算器！-----\n\n";
    string CalculateTypeOption; char CalculateTypeChoice;

    while (true)
    {
        int exit2 = 0;
        cout << "功能菜单：\n1.高精度整数运算\n2.小数运算\n3.复数运算\n4.三角函数运算\n5.对数指数运算\n6.退出计算器\n\n";
        cout << "请选择所需功能【输入1、2、3、4、5、6】:";
        getline(cin, CalculateTypeOption);
        CalculateTypeChoice = CalculateTypeOption[0];
        if (!('1' <= CalculateTypeChoice && CalculateTypeChoice <= '6' && CalculateTypeOption.length() == 1))
        {
            exit2++; cout << "输入错误，请重新选择！\n\n";
        }
        if (exit2 == 0) { break; }
    }
    if (CalculateTypeChoice == '1'){HighIntegarCalc(Userlabel);}
    if (CalculateTypeChoice == '2') { DemicalCalc(Userlabel);}
    if (CalculateTypeChoice == '3'){ ComplexCalc(Userlabel);}
    if ( CalculateTypeChoice == '4'){TriFunctionCalc(Userlabel);}
    if (CalculateTypeChoice == '5'){LogExpCalc(Userlabel);}
    if (CalculateTypeChoice == '6'){ main_page(Userlabel);}
}
void OtherCalculationPage(string Userlabel)//其他计算界面
{
    cout << "\n----- 欢迎进入其他计算界面！-----\n\n";
    string CaluclateType; char CaluclateTypeChoice;
    while (true)
    {
        int exit3 = 0;
        cout << "功能菜单：\n1.素数模块\n2.周长面积计算模块\n3.体积计算\n4.BMI计算模块\n5.退出其他计算\n";
        cout << "请选择所需功能【输入1、2、3、4、5】:";
        getline(cin, CaluclateType);
        CaluclateTypeChoice = CaluclateType[0];
        if (!('1' <= CaluclateTypeChoice && CaluclateTypeChoice <= '6' && CaluclateType.length() == 1))
        {
            exit3++; cout << "输入错误，请重新选择！\n\n";
        }
        if (exit3 == 0) { break; }
    }
    if (CaluclateTypeChoice == '1')  { PrimeMoudle(Userlabel);}
    if (CaluclateTypeChoice == '2') { ShapeCalc(Userlabel);}
    if (CaluclateTypeChoice == '3') { GeoSolidCalc(Userlabel); }
    if (CaluclateTypeChoice == '4') { BMICalc(Userlabel); }
    if (CaluclateTypeChoice == '5') { main_page(Userlabel); }
}
void resetUsername( string JumptoLabel)//修改用户名
{
    IfContainerEmpty();
    string Readuserdata,Readblacklistdata,Originusername,Newusername;
    readuserdata(Readuserdata, Readblacklistdata);
    cout << "--------- 重置用户名 ---------\n\n";
    int userIndex=-1;
    while(true)
    {
        if (JumptoLabel != "u"&&JumptoLabel!="v") 
        {
            for (int i = 0; i < Usernamelist.size(); i++)
            {
                if (Usernamelist.at(i) == JumptoLabel) { userIndex = i; break; }
            }
            break; 
        }
        else
        {
            int exit3_1 = 0;
            cout << "请输入原用户名:";
            cin >> Originusername;
            if (CheckInput(Originusername) == false) { exit3_1++; cout << "格式有误!用户名至少由6个字符组成，字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种!\n\n"; }
            if (exit3_1 == 0)
            {
                for (vector<string>::const_iterator iter0 = BlacklistUser.begin(); iter0 != BlacklistUser.end(); iter0++)
                {
                    if (*iter0 == Originusername) { exit3_1++; cout << "该账户已锁定，请重新输入!\n\n"; break; }
                }
            }
            if (exit3_1 == 0)
            {
                bool anly2 = false;
                for (int i = 0; i < Usernamelist.size(); i++)
                {
                    if (Usernamelist.at(i) == Originusername) { userIndex = i; anly2 = true; break; }
                }
                if (anly2 == false) { exit3_1++; cout << "用户名不存在,请重新输入!\n\n"; }
            }
            if (exit3_1 == 0) { break; }
        }
    }
    while (true)
    {
        int exit3_2 = 0;
        cout << "请输入新用户名:";
        cin >> Newusername;
        if (CheckInput(Newusername) == false) { exit3_2++; cout << "格式有误!用户名至少由6个字符组成，字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种!\n\n"; }
        if (exit3_2 == 0)
        {
            for (vector<string>::const_iterator iter2 = BlacklistUser.begin(); iter2 != BlacklistUser.end(); iter2++)
            {
                if (*iter2== Newusername) { exit3_2++; cout << "新用户名不能为黑名单中已有的用户名，请重新输入!\n\n"; break; }
            }
        }
        if (exit3_2 == 0)
        {
            bool anly2 = true;
            for (int i = 0; i < Usernamelist.size(); i++)
            {
                if (Usernamelist.at(i) == Newusername) { anly2 = false; break; }
            }
            if (anly2 == false) { exit3_2++; cout << "用户名已存在,请重新输入!\n\n"; }
        }
        if (exit3_2 == 0) { break; }
    }
    Usernamelist.at(userIndex) = Newusername;
    ofstream updateusername(userinfoFile, ios::out);
    //if (updateusername.is_open() == false) { cout << "File open failed!\n";}
    for (int i = 0; i < Usernamelist.size(); i++)
    {updateusername << Usernamelist.at(i) << ':' << Passwordlist.at(i) << '\n';}
    IfContainerEmpty();
    cout << "\n\n用户名修改成功！\n\n";
    updateusername.close();
    cout << "用户数据已更新，请重新登录！\n\n";
    welcome_page();
}
void resetPassword()//重置密码界面，让忘记密码的用户重置密码或让想修改密码的用户修改密码（modify_information_page应包含)
{
    IfContainerEmpty();
    int userindex=-1;
    string Getuserinfo_modifyPage,  Usernameinput, GetblacklistuserForcmp;
    string modify_password, confirmed_password , used_password;
    readuserdata(Getuserinfo_modifyPage, GetblacklistuserForcmp);
    cout << "---------------- 重置/修改密码 ----------------\n";
    while (true)//输入并检测用户名
    {
        cout << "\n请输入用户名：";
        int out6 = 0;
        getline(cin, Usernameinput);
        if (CheckInput(Usernameinput) == false) { out6++; cout << "用户名格式不正确！【用户名至少由6个字符组成，字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】" << endl; }
        if (out6 == 0)
        {
            bool anly0 = true;
            for (vector<string>::const_iterator it3 = BlacklistUser.begin(); it3 != BlacklistUser.end(); it3++)
            {
                if (Usernameinput == *it3) { anly0 = false; break; }
            }
            if (anly0 == false)
            {
                out6 = 2; cout << "账户已被锁定，请重新输入！\n";
            }
        }
        if (out6 == 0)
        {
            bool anly1 = false;
            for (int i = 0; i < Usernamelist.size(); i++)
            {
                if (Usernameinput == Usernamelist.at(i)) { userindex = i; anly1 = true; break; }
            }
            if (anly1 == false) { cout << "用户名不存在!\n"; out6++; }
        }
        if (out6 == 0) { break; }
    }
    while (true)
    {
        int out7 = 0;
        cout << "请输入新密码【密码至少由6个字符组成，字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】:";
        getline(cin, modify_password);
        if (CheckInput(modify_password) == false)
        {cout << "密码格式错误，请重新输入！【密码至少由6个字符组成，字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种】" << endl; out7++;}
        if (out7 == 0)//判断与原密码是否重复
        {
            used_password = Passwordlist.at(userindex);
            if (used_password == modify_password) { out7++; cout << "新密码不能与原密码相同!\n"; }
        }
        if (out7 == 0) { break; }
    }
    while (true)
    {
        cout << "请再次输入密码：";
        getline(cin, confirmed_password);
        if (modify_password == confirmed_password)
        {
            Passwordlist.at(userindex) = confirmed_password;
            ofstream writeuserinfo_modify_page(userinfoFile, ios::out);
            if (writeuserinfo_modify_page.is_open() == false) { cout << "File open failed!\n"; }
            for (int i = 0; i < Usernamelist.size(); i++)
            {
                writeuserinfo_modify_page << Usernamelist.at(i) << ":" << Passwordlist.at(i) << "\n";
            }
            writeuserinfo_modify_page.close();
            break;
        }
        else{cout << "两次输入的密码不一致，请重新输入\n";}
    } 
    cout << "密码修改成功!\n\n";
    IfContainerEmpty();
    welcome_page();
}
void CancelAccount() //注销账号
{
    IfContainerEmpty();
    int CancelUserIndex=-1;
    string CancelUsername,GetUser,GetblacklistUser;
    readuserdata(GetUser, GetblacklistUser);
    while (true)
    {
        int exit4 = 0;
        cout << "---------- 账户注销 ----------\n\n";
        cout << "请输入所需注销的账号:";
        getline(cin,CancelUsername);
        if (CheckInput(CancelUsername) == false) { exit4++; cout << "用户名格式有误，用户名至少由6个字符组成，字符只能为数字（0~9）、大小写字母、下划线（\"_\")的其中一种!\n\n"; }
        if(exit4==0)
        {
            for (vector<string>::const_iterator iter00 = BlacklistUser.begin(); iter00 != BlacklistUser.end(); iter00++)
            {
                if (CancelUsername == *iter00) { exit4++; break; cout << "不能注销黑名单里的用户!\n\n"; }
            }
        }
        if (exit4 == 0)
        {
            bool anly4 = false;
            for (int i = 0; i < Usernamelist.size(); i++)
            {
                if (Usernamelist.at(i) == CancelUsername) { anly4 = true; CancelUserIndex = i; break; }
            }
            if (anly4 == false) { cout << "用户名不存在！\n\n"; }
        }
        if (exit4 == 0) { break; }
    }
    for (vector<string>::iterator deluser = Usernamelist.begin(); deluser != Usernamelist.end();)
    {
        if (*deluser == CancelUsername) { Usernamelist.erase(deluser); break; }
        else { ++deluser; }
    }
    for (vector<string>::iterator delpassword = Passwordlist.begin(); delpassword != Passwordlist.begin();)
    {
        if (*delpassword == Passwordlist.at(CancelUserIndex)) { Usernamelist.erase(delpassword); break; }
        else { ++delpassword; }
    }
    ofstream newUserinfo(userinfoFile, ios::out);
    if (newUserinfo.is_open() == false) { cout << "File open failed!"; }
    for (int i = 0; i < Usernamelist.size(); i++){ newUserinfo << Usernamelist.at(i) << ':' << Passwordlist.at(i) << '\n'; }
    newUserinfo.close();
    IfContainerEmpty();
    cout << "账户注销成功!\n\n";
    cout << "--------------------------------------------- 即将返回首页! ---------------------------------------------\n\n";  
    welcome_page();
}
void HighIntegarCalc(string Userlabel)
{
    string HighIntCalcChoice; char HighIntCalcOp;
    while (true)
    {
        int HighInt = 0;
        cout << "--------- 高精度正整数运算 ----------\n";
        cout << " 功能菜单：\n1.正整数加法\n2.正整数减法\n3.正整数乘法\n4.正整数除法\n5.正整数取余\n6.阶乘\n7.退出\n\n";
        cout << "请选择所需功能【输入所需功能前的数字】:";
        getline(cin, HighIntCalcChoice);
        HighIntCalcOp = HighIntCalcChoice[0];
        if (!(HighIntCalcOp >= '1' && HighIntCalcOp <= '7' && HighIntCalcChoice.length() == 1)) { HighInt++; cout << "输入错误！\n"; }
        if (HighInt == 0)
        {
            if (HighIntCalcOp == '7') { HighInt = 0; break; }
            else
            {
                if (HighIntCalcOp == '1') { HighIntPlus(Userlabel); HighInt = 1; }
                if (HighIntCalcOp == '2') { HighIntMinus(Userlabel); HighInt = 1;}
                if (HighIntCalcOp == '3') { HighIntMultiply(Userlabel); HighInt = 1; }
                if (HighIntCalcOp == '4') { HighIntDivide(Userlabel); HighInt = 1;}
                if (HighIntCalcOp == '5') { HighIntMod(Userlabel); HighInt = 1; }
                if (HighIntCalcOp == '6') { HighFactorialCalc(Userlabel); HighInt = 1; }
            }
        }
    }
    calculator_page(Userlabel);
}
void ComplexCalc(string Userlabel)//复数运算
{
    string ComplexCalcChoice; char ComplexCalcOp;
    while (true)
    {
        int ComplexMoudle = 0;
        cout << "--------- 复数运算 ----------\n";
        cout << " 功能菜单：\n1.复数加法\n2.复数减法\n3.复数乘法\n4.复数除法\n5.复数的模\n6.退出\n\n";
        cout << "请选择所需功能【输入所需功能前的数字】:";
        getline(cin, ComplexCalcChoice);
        ComplexCalcOp = ComplexCalcChoice[0];
        if (!(ComplexCalcOp >= '1' && ComplexCalcOp <= '6' && ComplexCalcChoice.length() == 1)) { ComplexMoudle++; cout << "输入错误！\n"; }
        if (ComplexMoudle == 0)
        {
            if (ComplexCalcOp == '6') { ComplexMoudle = 0; break; }
            else
            {
                if (ComplexCalcOp == '1') 
                {
                    while (true)
                    {
                        int Complex1 = 0; string Getplusnum, num1_1, num1_2, num1_3, num1_4, C_Exit1; double Pnum1, Pnum2, Pnum3, Pnum4; char C_ExitOp1;
                        cout << "请以小数的形式分别输入四个数据【范围：-8.98*（10^307)~8.98*(10^307)】,代表复数1的实部和虚部,复数2的实部和虚部(每两个数据之间用一个空格隔开):";
                        getline(cin, Getplusnum);
                        istringstream c_numarr1(Getplusnum);
                        getline(c_numarr1, num1_1, ' ');
                        getline(c_numarr1, num1_2, ' ');
                        getline(c_numarr1, num1_3, ' ');
                        getline(c_numarr1, num1_4);
                        pair<bool, double>GetPlusnum1 = VerifyDemicalValid(num1_1, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetPlusnum1.first == 0) { Complex1++; }
                        else { Pnum1 = GetPlusnum1.second; }
                        pair<bool, double>GetPlusnum2 = VerifyDemicalValid(num1_2, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetPlusnum2.first == 0) { Complex1++; }
                        else { Pnum2 = GetPlusnum2.second; }
                        pair<bool, double>GetPlusnum3 = VerifyDemicalValid(num1_3, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetPlusnum3.first == 0) { Complex1++; }
                        else { Pnum3 = GetPlusnum3.second; }
                        pair<bool, double>GetPlusnum4 = VerifyDemicalValid(num1_4, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetPlusnum4.first == 0) { Complex1++; }
                        else { Pnum4 = GetPlusnum4.second; }
                        if (Complex1 != 0) { cout << "数据输入有误,请重新输入\n"; }
                        else
                        {
                            Complex c3(0, 0), c1(Pnum1, Pnum2), c2(Pnum3, Pnum4);
                            c3 = c1 + c2;
                            c3.Show();
                            C_ExitOp1 = Exitchoice(C_Exit1);
                            if (C_ExitOp1 == '1') { break; }
                        }
                    }
                }
                if (ComplexCalcOp == '2') 
                {
                    while (true)
                    {
                        int Complex2 = 0; string Getminusnum, num2_1, num2_2, num2_3, num2_4, C_Exit2; double Subnum1, Subnum2, Subnum3, Subnum4; char C_ExitOp2;
                        cout << "请以小数的形式分别输入四个数据【范围：-8.98*（10^307)~8.98*(10^307)】,代表复数1的实部和虚部,复数2的实部和虚部(每两个数据之间用一个空格隔开):";
                        getline(cin, Getminusnum);
                        istringstream c_numarr2(Getminusnum);
                        getline(c_numarr2, num2_1, ' ');
                        getline(c_numarr2, num2_2, ' ');
                        getline(c_numarr2, num2_3, ' ');
                        getline(c_numarr2, num2_4);
                        pair<bool, double>GetSubnum1 = VerifyDemicalValid(num2_1, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetSubnum1.first == 0) { Complex2++; }
                        else { Subnum1 = GetSubnum1.second; }
                        pair<bool, double>GetSubnum2 = VerifyDemicalValid(num2_2, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetSubnum2.first == 0) { Complex2++; }
                        else { Subnum2 = GetSubnum2.second; }
                        pair<bool, double>GetSubnum3 = VerifyDemicalValid(num2_3, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetSubnum3.first == 0) { Complex2++; }
                        else { Subnum3 = GetSubnum3.second; }
                        pair<bool, double>GetSubnum4 = VerifyDemicalValid(num2_4, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetSubnum4.first == 0) { Complex2++; }
                        else { Subnum4 = GetSubnum4.second; }
                        if (Complex2 != 0) { cout << "数据输入有误,请重新输入\n"; }
                        else
                        {
                            Complex c3(0, 0), c1(Subnum1, Subnum2), c2(Subnum3, Subnum4);
                            c3 = c1 - c2;
                            c3.Show();
                            C_ExitOp2 = Exitchoice(C_Exit2);
                            if (C_ExitOp2 == '1') { break; }
                        }
                    }
                }
                if (ComplexCalcOp == '3') 
                {
                    while (true)
                    {
                        int Complex3 = 0; string Getmultinum, num3_1, num3_2, num3_3, num3_4, C_Exit3; double multinum1, multinum2, multinum3, multinum4; char C_ExitOp3;
                        cout << "请以小数的形式分别输入四个数据【范围：-1.34*（10^154)~1.34*（10^154)】,代表复数1的实部和虚部,复数2的实部和虚部(每两个数据之间用一个空格隔开):";
                        getline(cin, Getmultinum);
                        istringstream c_numarr3(Getmultinum);
                        getline(c_numarr3, num3_1, ' ');
                        getline(c_numarr3, num3_2, ' ');
                        getline(c_numarr3, num3_3, ' ');
                        getline(c_numarr3, num3_4);
                        pair<bool, double>Getmultinum1 = VerifyDemicalValid(num3_1, -(1.34 * pow(10, 154)), 1.34 * pow(10, 154));
                        if (Getmultinum1.first == 0) { Complex3++; }
                        else { multinum1 = Getmultinum1.second; }
                        pair<bool, double>Getmultinum2 = VerifyDemicalValid(num3_2, -(1.34 * pow(10, 154)), 1.34 * pow(10, 154));
                        if (Getmultinum2.first == 0) { Complex3++; }
                        else { multinum2 = Getmultinum2.second; }
                        pair<bool, double>Getmultinum3 = VerifyDemicalValid(num3_3, -(1.34 * pow(10, 154)), 1.34 * pow(10, 154));
                        if (Getmultinum3.first == 0) { Complex3++; }
                        else { multinum3 = Getmultinum3.second; }
                        pair<bool, double>Getmultinum4 = VerifyDemicalValid(num3_4, -(1.34 * pow(10, 154)), 1.34 * pow(10, 154));
                        if (Getmultinum4.first == 0) { Complex3++; }
                        else { multinum4 = Getmultinum4.second; }
                        if (Complex3 != 0) { cout << "数据输入有误,请重新输入\n"; }
                        else
                        {
                            Complex c3(0, 0), c1(multinum1, multinum2), c2(multinum3, multinum4);
                            c3 = c1 * c2;
                            c3.Show();
                            C_ExitOp3 = Exitchoice(C_Exit3);
                            if (C_ExitOp3 == '1') { break; }
                        }
                    }
                }
                if (ComplexCalcOp == '4') 
                {
                    while (true)
                    {
                        int Complex4 = 0; string Getdivnum, num4_1, num4_2, num4_3, num4_4, C_Exit4; double Divnum1, Divnum2, Divnum3, Divnum4; char C_ExitOp4;
                        cout << "请以小数的形式分别输入四个数据【范围：-6.7*（10^153)~6.7*(10^153)】,代表复数1的实部和虚部,复数2的实部和虚部(每两个数据之间用一个空格隔开):";
                        getline(cin, Getdivnum);
                        istringstream c_numarr4(Getdivnum);
                        getline(c_numarr4, num4_1, ' ');
                        getline(c_numarr4, num4_2, ' ');
                        getline(c_numarr4, num4_3, ' ');
                        getline(c_numarr4, num4_4);
                        pair<bool, double>GetDivnum1 = VerifyDemicalValid(num4_1, -(6.7 * pow(10, 153)), 6.7 * pow(10, 153));
                        if (GetDivnum1.first == 0) { Complex4++; }
                        else { Divnum1 = GetDivnum1.second; }
                        pair<bool, double>GetDivnum2 = VerifyDemicalValid(num4_2, -(6.7 * pow(10, 153)), 6.7 * pow(10, 153));
                        if (GetDivnum2.first == 0) { Complex4++; }
                        else { Divnum2 = GetDivnum2.second; }
                        pair<bool, double>GetDivnum3 = VerifyDemicalValid(num4_3, -(6.7 * pow(10, 153)), 6.7 * pow(10, 153));
                        if (GetDivnum3.first == 0) { Complex4++; }
                        else { Divnum3 = GetDivnum3.second; }
                        pair<bool, double>GetDivnum4 = VerifyDemicalValid(num4_4, -(6.7 * pow(10, 153)), 6.7 * pow(10, 153));
                        if (GetDivnum4.first == 0||Divnum3*Divnum3+GetDivnum4.second* GetDivnum4.second==0) { Complex4++; }
                        else { Divnum4 = GetDivnum4.second; }
                        if (Complex4 != 0) { cout << "数据输入有误,请重新输入\n"; }
                        else
                        {
                            cout<<"如数据过大，将以inf或-inf呈现\n";
                            Complex c3(0, 0), c1(Divnum1, Divnum2), c2(Divnum3, Divnum4);
                            c3 = c1 / c2;
                            c3.Show();
                            C_ExitOp4 = Exitchoice(C_Exit4);
                            if (C_ExitOp4 == '1') { break; }
                        }
                    }
                }
                if (ComplexCalcOp == '5') 
                {
                    while (true)
                    {
                        int Complex5 = 0; string GetModnum, num5_1, num5_2, C_Exit5; double Modnum1, Modnum2; char C_ExitOp2;
                        cout << "请以小数的形式分别输入两个数据【范围：-6.7*（10^153)~6.7*(10^153)】,代表复数的实部和虚部(每两个数据之间用一个空格隔开):";
                        getline(cin, GetModnum);
                        istringstream c_numarr5(GetModnum);
                        getline(c_numarr5, num5_1, ' ');
                        getline(c_numarr5, num5_2, ' ');
                        pair<bool, double>GetModnum1 = VerifyDemicalValid(num5_1, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetModnum1.first == 0) { Complex5++; }
                        else { Modnum1 = GetModnum1.second; }
                        pair<bool, double>GetModnum2 = VerifyDemicalValid(num5_2, -(8.98 * pow(10, 307)), 8.98 * pow(10, 307));
                        if (GetModnum2.first == 0) { Complex5++; }
                        else { Modnum2 = GetModnum2.second; }
                        if (Complex5 != 0) { cout << "数据输入有误,请重新输入\n"; }
                        else
                        {
                            Complex c1(Modnum1, Modnum2);
                            printf(" 该复数的模是 %lf", c1.Modulous());
                            C_ExitOp2 = Exitchoice(C_Exit5);
                            if (C_ExitOp2 == '1') { break; }
                        }
                    }
                }
            }
        }
    }
    calculator_page(Userlabel);
}
void DemicalCalc(string Userlabel)//小数运算
{
    string DemicalCalcChoice; char DemicalCalcOp;
    while (true)
    {
        int DemicalMoudle = 0;
        cout << "--------- 小数运算 ----------\n";
        cout << " 功能菜单：\n1.小数加法\n2.小数减法\n3.小数乘法\n4.小数除法\n5.以e为底指数运算\n6.退出\n\n";
        cout << "请选择所需功能【输入所需功能前的数字】:";
        getline(cin, DemicalCalcChoice);
        DemicalCalcOp = DemicalCalcChoice[0];
        if (!(DemicalCalcOp >= '1' && DemicalCalcOp <= '6' && DemicalCalcChoice.length() == 1)) { DemicalMoudle++; cout << "输入错误！\n"; }
        if (DemicalMoudle == 0)
        {
            if (DemicalCalcOp == '6') { DemicalMoudle = 0; break; }
            else
            {
                if (DemicalCalcOp == '1') 
                {
                    string GetPlusnum, DecExit01, Plusnum1, Plusnum2; double plusnum1, plusnum2; char DecExitop1;
                    while (true)
                    {
                        int DecPlus = 0;
                        cout << "请输入两个小数，代表两个数据【范围：-1.79* (10^308)~1.79* (10^308)】，两个数据用一个空格隔开：";
                        getline(cin, GetPlusnum);
                        istringstream Getplus(GetPlusnum);
                        getline(Getplus, Plusnum1, ' ');
                        getline(Getplus, Plusnum2);
                        pair<bool, double> Getplusnum1 = VerifyDemicalValid(Plusnum1, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getplusnum1.first == 0) { DecPlus++; }
                        else { plusnum1 = Getplusnum1.second; }
                        pair<bool, double> Getplusnum2 = VerifyDemicalValid(Plusnum2, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getplusnum2.first == 0) { DecPlus++; }
                        else { plusnum2 = Getplusnum2.second; }
                        if (DecPlus != 0) { cout << "输入数据有误，请重新输入！\n"; }
                        if (DecPlus == 0)
                        {
                            cout << "如果结果过大，则结果将以\"inf\"或\"-inf\"呈现。" << endl;
                            cout<<"计算结果："<<plusnum1 + plusnum2<<endl;
                            DecExitop1 = Exitchoice(DecExit01);
                            if (DecExitop1 == '1') { DecPlus = 0;break; }
                        }
                    }
                }
                if (DemicalCalcOp == '2') 
                {
                    string GetMinusnum, DecExit02, Minusnum1, Minusnum2; double minusnum1, minusnum2; char DecExitop2;
                    while (true)
                    {
                        int DecMinus = 0;
                        cout << "请输入两个小数，代表两个数据【范围：-1.79* (10^308)~1.79* (10^308)】，两个数据用一个空格隔开：";
                        getline(cin, GetMinusnum);
                        istringstream Getminus(GetMinusnum);
                        getline(Getminus, Minusnum1, ' ');
                        getline(Getminus, Minusnum2);
                        pair<bool, double> Getminusnum1 = VerifyDemicalValid(Minusnum1, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getminusnum1.first == 0) { DecMinus++; }
                        else { minusnum1 = Getminusnum1.second; }
                        pair<bool, double> Getminusnum2 = VerifyDemicalValid(Minusnum2, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getminusnum2.first == 0) { DecMinus++; }
                        else { minusnum2 = Getminusnum2.second; }
                        if (DecMinus != 0) { cout << "输入数据有误，请重新输入！\n"; }
                        if (DecMinus == 0)
                        {
                            cout << "如果结果过大，则结果将以\"inf\"或\"-inf\"呈现。" << endl;
                            cout << "计算结果：" << minusnum1-minusnum2<<endl;
                            DecExitop2 = Exitchoice(DecExit02);
                            if (DecExitop2 == '1') { DecMinus = 0; break; }
                        }
                    }
                }
                if (DemicalCalcOp == '3') 
                {
                    string GetMultinum, DecExit03, Multinum1, Multinum2; double multinum1, multinum2; char DecExitop3;
                    while (true)
                    {
                        int DecMulti = 0;
                        cout << "请输入两个小数，代表两个数据【范围：-1.79*（10^308)~1.79*(10^308)】，两个数据用一个空格隔开：";
                        getline(cin, GetMultinum);
                        istringstream Getmultiply(GetMultinum);
                        getline(Getmultiply, Multinum1, ' ');
                        getline(Getmultiply, Multinum2);
                        pair<bool, double> Getmultinum1 = VerifyDemicalValid(Multinum1, -( 1.79* pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getmultinum1.first == 0) { DecMulti++; }
                        else { multinum1 = Getmultinum1.second; }
                        pair<bool, double> Getmultinum2 = VerifyDemicalValid(Multinum2, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getmultinum2.first == 0) { DecMulti++; }
                        else { multinum2 = Getmultinum2.second; }
                        if (DecMulti != 0) { cout << "输入数据有误，请重新输入！\n"; }
                        if (DecMulti == 0)
                        {
                            cout << "如果结果过大，则结果将以\"inf\"或\"-inf\"呈现。" << endl;
                            cout << "计算结果：" << multinum1 * multinum2<<endl;
                            DecExitop3 = Exitchoice(DecExit03);
                            if (DecExitop3 == '1') { DecMulti = 0; break; }
                        }
                    }
                }
                if (DemicalCalcOp == '4') 
                {
                    string GetDivnum, DecExit04, Divnum1, Divnum2; double divnum1, divnum2; char DecExitop4;
                    while (true)
                    {
                        int DecDivision = 0;
                        cout << "请输入两个小数，代表两个数据【范围：-1.79* (10^308)~1.79* (10^308)】，两个数据用一个空格隔开：";
                        getline(cin, GetDivnum);
                        istringstream GetDicvision(GetDivnum);
                        getline(GetDicvision, Divnum1, ' ');
                        getline(GetDicvision, Divnum2);
                        pair<bool, double> Getdivnum1 = VerifyDemicalValid(Divnum1, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getdivnum1.first == 0) { DecDivision++; }
                        else { divnum1 = Getdivnum1.second; }
                        pair<bool, double> Getdivnum2 = VerifyDemicalValid(Divnum2, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getdivnum2.first == 0 || Getdivnum2.second == 0) { DecDivision++; }
                        else { divnum2 = Getdivnum2.second; }
                        if (DecDivision != 0) { cout << "输入数据有误，请重新输入！\n"; }
                        if (DecDivision == 0)
                        {
                            cout << "如果结果过大，则结果将以\"inf\"或\"-inf\"呈现。" << endl;
                            cout << "计算结果：" << divnum1 / divnum2<<endl;
                            DecExitop4 = Exitchoice(DecExit04);
                            if (DecExitop4 == '1') { DecDivision = 0; break; }
                        }
                    }
                }
                if (DemicalCalcOp == '5') 
                {
                    string GetPointnum, DecExit05; double Pointnum; char DecExitop5;
                    while (true)
                    {
                        int DecExp = 0;
                        cout << "请输入一个小数【范围：-1.79* (10^308)~1.79* (10^308)】：";
                        getline(cin, GetPointnum);
                        pair<bool, double> Getexpnum = VerifyDemicalValid(GetPointnum, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                        if (Getexpnum.first == 0) { DecExp++; }
                        else { Pointnum = Getexpnum.second; }
                        if (DecExp != 0) { cout << "输入数据有误，请重新输入！\n"; }
                        if (DecExp == 0)
                        {
                            cout << "如果结果过大，则结果将以\"inf\"或\"-inf\"呈现。"<<endl;
                            cout << "计算结果：" << exp(Pointnum)<<endl;
                            DecExitop5 = Exitchoice(DecExit05);
                            if (DecExitop5 == '1') { DecExp = 0; break; }
                        }
                    }
                }
            }
        }
    }
    calculator_page(Userlabel);
}
void TriFunctionCalc(string Userlabel)//三角函数运算
{
    string TriMoudleChoice; char TriMoudleOp;
    while (true)
    {
        int Tri = 0;
        cout << "---------- 三角函数模块 ----------\n";
        cout << "功能菜单：\n1.三角函数\n2.反三角函数\n3.退出该模块\n\n";
        cout << "请输入所需功能【键入功能前的数字】:";
        getline(cin, TriMoudleChoice);
        TriMoudleOp = TriMoudleChoice[0];
        if (!('1' <= TriMoudleOp && TriMoudleOp <= '3' && TriMoudleChoice.length() == 1))
        {
            Tri++; cout << "输入错误,请重新输入!\n\n";
        }
        if (Tri == 0)
        {
            if (TriMoudleOp == '3') { Tri = 0; cout << "正在退出该模块!\n\n";break; }
            else
            {
                if(TriMoudleOp=='1'){ TriFunc(Userlabel); Tri = 1;}
                if (TriMoudleOp == '2'){ InverseTriFunc(Userlabel); Tri = 1; }
            }
        }
    }
    calculator_page(Userlabel);
}
void LogExpCalc(string Userlabel)//对数指数运算
{
    string LogExpChoice; char LogExpOp;
    while (true)
    {
        int LogExp = 0;
        cout << "---------- 对数指数模块 ----------\n";
        cout << "功能菜单：\n1.以2为底\n2.以e为底\n3.以10为底\n4.以其他大于0的数为底\n5.退出此模块\n\n";
        cout << "请输入所需功能【键入功能前的数字】:";
        getline(cin, LogExpChoice);
        LogExpOp = LogExpChoice[0];
        if (!('1' <= LogExpOp && LogExpOp <= '5' && LogExpChoice.length() == 1))
        {
            LogExp++; cout << "输入错误,请重新输入!\n\n";
        }
        if (LogExp == 0)
        {
            if (LogExpOp == '5') { LogExp = 0; cout << "正在退出该模块!\n\n"; break; }
            else
            {
                if (LogExpOp == '1') 
                {
                    while (true)
                    {
                        int LogExp1 = 0; string Logexit1; char Logexit1op;
                        string Log2num; long double LOG2Originnum;
                        cout << "请输入一个正数【范围：0~1.79*(10^308)】：";
                        getline(cin, Log2num);
                        pair<bool, long double> GetLog2num = VerifyDemicalValid(Log2num, 0, 1.79 * pow(10, 308));
                        if (GetLog2num.first == 0||GetLog2num.second==0) { LogExp1++; cout << "输入数据有误，请重新输入！\n\n"; }
                        else { LOG2Originnum = GetLog2num.second; }
                        if (LogExp1 == 0)
                        {
                            double Log2Calcnum = log2(LOG2Originnum);
                            printf("log2(%Lf)=%Lf\n", LOG2Originnum, Log2Calcnum);
                            Logexit1op = Exitchoice(Logexit1);
                            if (Logexit1op == '1') { LogExp1 = 0; }
                            else { LogExp1 = 1; }
                        }
                        if (LogExp1 == 0) { LogExp = 1; break; }
                    }
                }
                if (LogExpOp == '2') 
                {
                    while (true)
                    {
                        int LogExp2 = 0; string Logexit2; char Logexit2op;
                        string lnnum; long double lnOriginnum;
                        cout << "请输入一个正数【范围：0~1.79*(10^308)】：";
                        getline(cin, lnnum);
                        pair<bool, long double> Getlnnum = VerifyDemicalValid(lnnum, 0, 1.79 * pow(10, 308));
                        if (Getlnnum.first == 0 || Getlnnum.second == 0) { LogExp2++; cout << "输入数据有误，请重新输入！\n\n"; }
                        else { lnOriginnum = Getlnnum.second; }
                        if (LogExp2 == 0)
                        {
                            double lnCalcnum = log(lnOriginnum);
                            printf("ln(%Lf)=%Lf\n", lnOriginnum, lnCalcnum);
                            Logexit2op = Exitchoice(Logexit2);
                            if (Logexit2op == '1') { LogExp2 = 0; }
                            else { LogExp2 = 1; }
                        }
                        if (LogExp2 == 0) { LogExp = 1; break; }
                    }
                }
                if (LogExpOp == '3')
                {
                    while (true)
                    {
                        int LogExp3 = 0; string Logexit3; char Logexit3op;
                        string lgnum; long double lgOriginnum;
                        cout << "请输入一个正数【范围：0~1.79*(10^308)】：";
                        getline(cin, lgnum);
                        pair<bool, long double> Getlgnum = VerifyDemicalValid(lgnum, 0, 1.79 * pow(10, 308));
                        if (Getlgnum.first == 0 || Getlgnum.second == 0) { LogExp3++; cout << "输入数据有误，请重新输入！\n\n"; }
                        else { lgOriginnum = Getlgnum.second; }
                        if (LogExp3 == 0)
                        {
                            double Log2Calcnum = log10(lgOriginnum);
                            printf("log2(%Lf)=%Lf\n", lgOriginnum, Log2Calcnum);
                            Logexit3op = Exitchoice(Logexit3);
                            if (Logexit3op == '1') { LogExp3 = 0; }
                            else { LogExp3 = 1; }
                        }
                        if (LogExp3 == 0) { LogExp = 1; break; }
                    }
                }
                if (LogExpOp == '4')
                {
                    while (true)
                    {
                        int LogExp4 = 0; string Logexit4; char Logexit4op;
                        string LogOther,Logbase,Logreal; long double LogBaseNum,LogRealNum;
                        cout << "请以正小数的形式输入分别两个数据，代表对数的底数【范围：0~1.79*(10^308)(不包含1)】和真数【范围：0~1.79*(10^308)】：";
                        getline(cin, LogOther); 
                        istringstream isss(LogOther);
                        getline(isss, Logbase,' ');
                        getline(isss, Logreal);
                        pair<bool, long double> GetBasenum = VerifyDemicalValid(Logbase, 0, 1.79 * pow(10, 308));
                        if (GetBasenum.first == 0 || GetBasenum.second == 0||GetBasenum.second==1) { LogExp4++;  }
                        else { LogBaseNum = GetBasenum.second; }
                        pair<bool, long double> GetRealnum = VerifyDemicalValid(Logreal, 0, 1.79 * pow(10, 308));
                        if (GetRealnum.first == 0 || GetRealnum.second == 0) { LogExp4++; }
                        else { LogRealNum = GetRealnum.second; }
                        if (LogExp4 != 0) { cout << "输入数据有误！\n"; }
                        if (LogExp4 == 0)
                        {
                            long double LogCalcnum = log(LogRealNum)/log(LogBaseNum);
                            printf("log(%Lf,%Lf)=%Lf\n", LogBaseNum, LogRealNum,LogCalcnum);
                            Logexit4op = Exitchoice(Logexit4);
                            if (Logexit4op == '1') { LogExp4 = 0; }
                            else { LogExp4 = 1; }
                        }
                        if (LogExp4 == 0) { LogExp = 1; break; }
                    }
                }
            }
        }
    }
    calculator_page(Userlabel);
}
void PrimeMoudle(string Userlabel)
{
    string PrimeTypeInput; char PrimeTypeChoice;
    while (true)
    {
        int p_exit = 0;
        cout << "素数模块功能菜单:\n1.素数判断\n2.指定区间内素数判断\n3.退出素数模块\n\n";
        cout << "请选择所需功能【输入1、2、3】：";
        getline(cin, PrimeTypeInput);
        PrimeTypeChoice = PrimeTypeInput[0];
        if (!('1' <= PrimeTypeChoice && PrimeTypeChoice <= '3' && PrimeTypeInput.length() == 1)) { p_exit++; cout << "输入错误，请重新输入!\n"; }
        if (PrimeTypeChoice == '3') { p_exit = 0; cout << "正在退出素数模块！"; OtherCalculationPage(Userlabel); }
        else
        { 
            if (p_exit == 0) 
            {
                if (PrimeTypeChoice == '1')
                {
                    while(true)
                    {
                        ull num0=0; string numinput;
                        string Exitchoice_1; char Choice_1;
                        int Continue_0 = 1;
                        cout << "请输入一个不超过19位的非负整数:";
                        getline(cin, numinput);
                        while (true)
                        {   
                            bool anly000 = true;
                            if (numinput.length() > 19 || numinput.length() == 0) { anly000 = false; }
                            else
                            {
                                for (int i = 0; i < numinput.length(); i++)
                                {
                                    if (isdigit(numinput[i]) == false) { anly000 = false; break; }
                                }
                            }
                            if (anly000) { break; }
                            else 
                            { 
                                cout << "输入的数字超出范围,或输入的内容中含有非数字字符\n请重新输入一个不超过19位的正整数:"; 
                                cin >> numinput;
                            }
                        }
                        for (int i = 0; i <= numinput.length()-1; i++){num0 += (numinput[i] - '0') * ull(pow(10, numinput.length() - 1 - i));}
                        if (prime(num0)) { printf("%llu是素数!\n", num0); }
                        else { printf("%llu不是素数！\n", num0); }
                        Choice_1=Exitchoice(Exitchoice_1);
                        if (Choice_1 == '1') { Continue_0 = 0;}
                        else if(Choice_1 == '2') { Continue_0 = 1; }
                        if (Continue_0 == 0) { p_exit = 1; break; }
                    }
                }
            }
            if (PrimeTypeChoice == '2')
            {
                while (true)
                {
                    ull lnum0=0, rnum0=0;
                    string Exitchoice_2,Getnum; char Choice_2;
                    int Continue_0 = 2;
                    string l0, r0;
                    cout << "请输入两个不超过19位的非负整数,作为素数的范围【第一个数前不要输入空格,两个整数之间用一个空格隔开（每个整数前键入的多余的空格将算入其后输入整数的位数中!)】:"; 
                    getline(cin, Getnum);
                    while (true)
                    {
                       
                        istringstream iss000(Getnum);
                        getline(iss000, l0, ' ');
                        getline(iss000, r0);
                        int out000 = 0;
                        if (l0.length() > 19 || l0.length() == 0) { out000++; }
                        else
                        {
                            for (int i = 0; i < l0.length(); i++)
                            {
                                if (isdigit(l0[i]) == false) { out000++; break; }
                            }
                        }                       
                        if (r0.length() > 19 || r0.length() == 0) { out000++; }
                        else
                        {
                            for (int i = 0; i < r0.length(); i++)
                            {
                                if (isdigit(r0[i]) == false) { out000++;break; }
                            }
                        }                       
                        if (out000==0) { break; }
                        else
                        {
                            cout << "输入的数字超出范围,或输入的内容中含有非数字字符\n请重新两个不超过19位的非负整数，作为素数的范围:";
                            getline(cin, Getnum);
                        }
                    }
                    cout << "如数据较大，计算时间可能稍久，请耐心等待！\n";
                    for (int i = 0; i <= l0.length() - 1; i++) { lnum0 += (l0[i] - '0') * ull(pow(10, l0.length() - 1 - i)); }
                    for (int i = 0; i <= r0.length() - 1; i++) { rnum0 += (r0[i] - '0') * ull(pow(10, r0.length() - 1 - i)); }
                    ull countprime=0;
                    vector<ull> primelist;
                    for (ull i = lnum0; i <= rnum0; i++)
                    {
                        if (prime(i)) { printf("%llu ", i); countprime++; }
                    }
                    if(countprime) { printf("\n%llu~%llu范围内共有%llu个素数", lnum0, rnum0,countprime); }
                    else{ printf("\n%llu~%llu范围内没有素数。", lnum0, rnum0); }
                    Choice_2 = Exitchoice(Exitchoice_2);
                    if (Choice_2 == '1') { Continue_0 = 0; }
                    else if (Choice_2 == '2') { Continue_0 = 1; }
                    if (Continue_0 == 0) { p_exit = 1; vector<ull>().swap(primelist); break; }
                }
            }
        }
        if (p_exit == 0) { break;}
    }
}
void ShapeCalc(string Userlabel)//平面图形计算
{
    string ShapeTypeInput; char ShapeTypeChoice;
    while (true)
    {
        int s_exit = 0;
        cout << "---------- 平面图形模块 ----------\n";
        cout << "平面图形模块功能菜单:\n1.三角形\n2.圆形\n3.圆环\n4.梯形\n5.平行四边形\n6.长方形\n7.正方形\n8.退出此模块\n\n";
        cout << "请选择功能【输入1~8】:";
        getline(cin, ShapeTypeInput);
        ShapeTypeChoice = ShapeTypeInput[0];
        if (!((ShapeTypeChoice >= '1' || ShapeTypeChoice <= '8') && ShapeTypeInput.length() == 1)) { s_exit++; cout << "输入错误，请重新输入！\n\n"; }
        else
        {
            if (ShapeTypeChoice == '8') { cout << "正在退出模块！\n\n"; OtherCalculationPage(Userlabel); s_exit = 0; }
            else
            {
                if (ShapeTypeChoice == '1')
                {
                    while (true)
                    {
                        int s_exit01 = 0; string ExitChoice4; char Choice4; int ContinueOp4 = 2;
                        string Tridata, side1, side2, side3;
                        double side1_data = 0, side2_data = 0, side3_data = 0;
                        cout << "请输入以正小数的形式分别输入三个数据，代表三条边的边长(单位:m)【范围0~1.34*10^154】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Tridata);
                        while (true)
                        {
                            int s_exit01_1 = 0;
                            istringstream s1(Tridata);
                            getline(s1, side1, ' ');
                            getline(s1, side2, ' ');
                            getline(s1, side3);
                            s1.str("");
                            pair<bool, double> side1length = VerifyDemicalValid(side1, 0, 1.34 * pow(10, 154));
                            if (side1length.first == 0 || side1length.second == 0) { s_exit01_1++; }
                            else { side1_data = side1length.second; }
                            pair<bool, double> side2length = VerifyDemicalValid(side2, 0, 1.34 * pow(10, 154));
                            if (side2length.first == 0 || side2length.second == 0) { s_exit01_1++; }
                            else { side2_data = side2length.second; }
                            pair<bool, double> side3length = VerifyDemicalValid(side3, 0, 1.34 * pow(10, 154));
                            if (side3length.first == 0 || side3length.second == 0) { s_exit01_1++; }
                            else { side3_data = side3length.second; }
                            if (s_exit01_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入三个数据，代表三条边的边长(单位:m)【范围0~1.34*10^154】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Tridata);
                            }
                            Triangle tri(side1_data, side2_data, side3_data);
                            if (s_exit01_1 == 0)
                            {
                                if (tri.IsTriangle() == false)
                                {
                                    s_exit01_1++; cout << "边长不能构成三角形！\n请输入以正小数的形式分别输入三个数据，代表三条边的边长(单位:m)【范围0~1.34*10^154】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                    getline(cin, Tridata);
                                }
                            }
                            if (s_exit01_1 == 0)
                            {
                                printf("三角形周长：%lf m\n", tri.Preimeter());
                                printf("三角形面积：%lf ㎡\n", tri.Area());
                                break;
                            }
                        }
                        Choice4 = Exitchoice(ExitChoice4);
                        if (Choice4 == '1') { ContinueOp4 = 0; }
                        else if (Choice4 == '2') { ContinueOp4 = 1; }
                        if (ContinueOp4 == 0) { s_exit++; s_exit01 = 0; }
                        else { s_exit01 = 1; }
                        if (s_exit01 == 0) { break; }
                    }
                }
                if (ShapeTypeChoice == '2')
                {
                    while (true)
                    {
                        int s_exit02 = 0; string ExitChoice5; char Choice5; int ContinueOp5 = 2;
                        string Cirdata, radius_data;
                        double radius = 0;
                        cout << "请输入以正小数的形式分别输入一个数据，代表圆的半径【范围0~1.34*10^154】(单位:m)(数据前请勿输入空格!)：";
                        getline(cin, Cirdata);
                        while (true)
                        {
                            int s_exit02_1 = 0;
                            istringstream s2(Cirdata);
                            getline(s2, radius_data);
                            s2.str("");
                            pair<bool, double> Getradius = VerifyDemicalValid(radius_data, 0, 1.34 * pow(10, 154));
                            if (Getradius.first == 0 || Getradius.second == 0) { s_exit02_1++; }
                            else { radius = Getradius.second; }
                            if (s_exit02_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入一个数据，代表圆的半径(单位:m)【范围0~1.34*10^154】(数据前请勿输入空格!)：";
                                getline(cin, Cirdata);
                            }
                            Circle c1(radius);
                            if (s_exit02_1 == 0)
                            {
                                printf("圆的周长：%lf m\n", c1.Preimeter());
                                printf("圆的面积：%lf ㎡\n", c1.Area());
                                break;
                            }
                        }
                        Choice5 = Exitchoice(ExitChoice5);
                        if (Choice5 == '1') { ContinueOp5 = 0; }
                        else if (Choice5 == '2') { ContinueOp5 = 1; }
                        if (ContinueOp5 == 0) { s_exit++; s_exit02 = 0; }
                        else { s_exit02 = 1; }
                        if (s_exit02 == 0) { break; }
                    }
                }
                if (ShapeTypeChoice == '3')
                {
                    while (true)
                    {
                        int s_exit03 = 0; string ExitChoice6; char Choice6; int ContinueOp6 = 2;
                        string CirRingdata, radius1_data, radius2_data;
                        double radius1 = 0, radius2 = 0;
                        cout << "请输入以正小数的形式分别输入两个数据，代表两个圆圆的半径(单位:m)【范围0~6.67*10^153】,数据之间用一个空格隔开(数据前请勿输入空格!)：";
                        getline(cin, CirRingdata);
                        while (true)
                        {
                            int s_exit03_1 = 0;
                            istringstream s3(CirRingdata);
                            getline(s3, radius1_data, ' ');
                            getline(s3, radius2_data);
                            s3.str("");
                            pair<bool, double> Getradius1 = VerifyDemicalValid(radius1_data, 0, 6.67 * pow(10, 153));
                            if (Getradius1.first == 0 || Getradius1.second == 0) { s_exit03_1++; }
                            else { radius1 = Getradius1.second; }
                            pair<bool, double> Getradius2 = VerifyDemicalValid(radius2_data, 0, 6.67 * pow(10, 153));
                            if (Getradius2.first == 0 || Getradius2.second == 0) { s_exit03_1++; }
                            else { radius2 = Getradius2.second; }
                            if (s_exit03_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入两个数据，代表两个圆圆的半径(单位:m)【范围0~6.67*10^153】，数据之间用一个空格隔开(数据前请勿输入空格!)：";
                                getline(cin, CirRingdata);
                            }
                            CircluarRing cr1(radius1, radius2, 0.0);
                            if (s_exit03_1 == 0)
                            {
                                printf("圆环的周长：%lf m\n", cr1.Preimeter());
                                printf("圆环的面积：%lf ㎡\n", cr1.Area());
                                break;
                            }
                        }
                        Choice6 = Exitchoice(ExitChoice6);
                        if (Choice6 == '1') { ContinueOp6 = 0; }
                        else if (Choice6 == '2') { ContinueOp6 = 1; }
                        if (ContinueOp6 == 0) { s_exit++; s_exit03 = 0; }
                        else { s_exit03 = 1; }
                        if (s_exit03 == 0) { break; }
                    }
                }
                if (ShapeTypeChoice == '4')
                {
                    while (true)
                    {
                        int s_exit04 = 0; string ExitChoice7; char Choice7; int ContinueOp7 = 2;
                        string Trapdata, s1_data, s2_data, s3_data, s4_data, distance_h;
                        double s1d = 0, s2d = 0, s3d = 0, s4d = 0, h = 0;
                        cout << "请输入以正小数的形式分别输入五个数据，代表梯形两条平行边、两条腰、和两条平行边之间的距离(单位:m)【范围0~3.345*10^153】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Trapdata);
                        while (true)
                        {
                            int s_exit04_1 = 0;
                            istringstream s4(Trapdata);
                            getline(s4, s1_data, ' ');
                            getline(s4, s2_data, ' ');
                            getline(s4, s3_data, ' ');
                            getline(s4, s4_data, ' ');
                            getline(s4, distance_h);
                            s4.str("");
                            pair<bool, double> Getd1 = VerifyDemicalValid(s1_data, 0, 3.345 * pow(10, 153));
                            if (Getd1.first == 0 || Getd1.second == 0) { s_exit04_1++; }
                            else { s1d = Getd1.second; }
                            pair<bool, double> Getd2 = VerifyDemicalValid(s2_data, 0, 3.345 * pow(10, 153));
                            if (Getd2.first == 0 || Getd2.second == 0) { s_exit04_1++; }
                            else { s2d = Getd2.second; }
                            pair<bool, double> Getd3 = VerifyDemicalValid(s3_data, 0, 3.345 * pow(10, 153));
                            if (Getd3.first == 0 || Getd3.second == 0) { s_exit04_1++; }
                            else { s3d = Getd3.second; }
                            pair<bool, double> Getd4 = VerifyDemicalValid(s4_data, 0, 3.345 * pow(10, 153));
                            if (Getd4.first == 0 || Getd4.second == 0) { s_exit04_1++; }
                            else { s4d = Getd4.second; }
                            pair<bool, double> Getd5 = VerifyDemicalValid(distance_h, 0, 3.345 * pow(10, 153));
                            if (Getd5.first == 0 || Getd5.second == 0) { s_exit04_1++; }
                            else { h = Getd5.second; }
                            if (s_exit04_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入五个数据，代表梯形两条平行边、两条腰、和两条平行边之间的距离(单位:m)【范围0~3.345*10^153】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Trapdata);
                            }
                            Trapezoid trape1(s1d, s2d, s3d, s4d, h);
                            if (s_exit04_1 == 0)
                            {
                                printf("梯形的周长：%lf m\n", trape1.Preimeter());
                                printf("梯形的面积：%lf ㎡\n", trape1.Area());
                                break;
                            }
                        }
                        Choice7 = Exitchoice(ExitChoice7);
                        if (Choice7 == '1') { ContinueOp7 = 0; }
                        else if (Choice7 == '2') { ContinueOp7 = 1; }
                        if (ContinueOp7 == 0) { s_exit++; s_exit04 = 0; }
                        else { s_exit04 = 1; }
                        if (s_exit04 == 0) { break; }
                    }
                }
                if (ShapeTypeChoice == '5')
                {
                    while (true)
                    {
                        int s_exit05 = 0; string ExitChoice8; char Choice8; int ContinueOp8 = 2;
                        string Palldata, s1_length, s2_length, s1_h;
                        double s1l = 0, s2l = 0, s1_hd = 0;
                        cout << "请输入以正小数的形式分别输入三个数据，代表每队平行边的边长、和一对平行边之间的距离(单位:m)【范围0~1.34*10^154】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Palldata);
                        while (true)
                        {
                            int s_exit05_1 = 0;
                            istringstream s5(Palldata);
                            getline(s5, s1_length, ' ');
                            getline(s5, s2_length, ' ');
                            getline(s5, s1_h);
                            s5.str("");
                            pair<bool, double> Getd01 = VerifyDemicalValid(s1_length, 0, 1.34 * pow(10, 154));
                            if (Getd01.first == 0 || Getd01.second == 0) { s_exit05_1++; }
                            else { s1l = Getd01.second; }
                            pair<bool, double> Getd02 = VerifyDemicalValid(s2_length, 0, 1.34 * pow(10, 154));
                            if (Getd02.first == 0 || Getd02.second == 0) { s_exit05_1++; }
                            else { s2l = Getd02.second; }
                            pair<bool, double> Getd03 = VerifyDemicalValid(s1_h, 0, 1.34 * pow(10, 154));
                            if (Getd03.first == 0 || Getd03.second == 0) { s_exit05_1++; }
                            else { s1_hd = Getd03.second; }
                            if (s_exit05_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入三个数据，代表每对平行边的边长、和一对平行边之间的距离(单位:m)【范围0~1.34*10^154】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Palldata);
                            }
                            Parallelogram parall(s1l, s2l, s1_hd);
                            if (s_exit05_1 == 0)
                            {
                                printf("平行四边形的周长：%lf m\n", parall.Preimeter());
                                printf("平行四边形的面积：%lf ㎡\n", parall.Area());
                                break;
                            }
                        }
                        Choice8 = Exitchoice(ExitChoice8);
                        if (Choice8 == '1') { ContinueOp8 = 0; }
                        else if (Choice8 == '2') { ContinueOp8 = 1; }
                        if (ContinueOp8 == 0) { s_exit++; s_exit05 = 0; }
                        else { s_exit05 = 1; }
                        if (s_exit05 == 0) { break; }
                    }
                }
                if (ShapeTypeChoice == '6')
                {
                    while (true)
                    {
                        int s_exit06 = 0; string ExitChoice9; char Choice9; int ContinueOp9 = 2;
                        string Rectdata, l, w;
                        double length = 0, width = 0;
                        cout << "请输入以正小数的形式分别输入两个数据，代表长方形的长和宽(单位:m)【范围0~1.34*10^154】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Rectdata);
                        while (true)
                        {
                            int s_exit06_1 = 0;
                            istringstream s6(Rectdata);
                            getline(s6, l, ' ');
                            getline(s6, w);
                            s6.str("");
                            pair<bool, double> Getl = VerifyDemicalValid(l, 0, 1.34 * pow(10, 154));
                            if (Getl.first == 0 || Getl.second == 0) { s_exit06_1++; }
                            else { length = Getl.second; }
                            pair<bool, double> Getw = VerifyDemicalValid(w, 0, 3.35 * pow(10, 153));
                            if (Getw.first == 0 || Getw.second == 0) { s_exit06_1++; }
                            else { width = Getw.second; }
                            if (s_exit06_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入两个数据，代表长方形的长和宽(单位:m)【范围0~1.34*10^154】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Rectdata);
                            }
                            class Rectangle rect(length, width, 0, 0, 0);
                            if (s_exit06_1 == 0)
                            {
                                printf("长方形的周长：%lf m\n", rect.Preimeter());
                                printf("长方形的面积：%lf ㎡\n", rect.Area());
                                break;
                            }
                        }
                        Choice9 = Exitchoice(ExitChoice9);
                        if (Choice9 == '1') { ContinueOp9 = 0; }
                        else if (Choice9 == '2') { ContinueOp9 = 1; }
                        if (ContinueOp9 == 0) { s_exit++; s_exit06 = 0; }
                        else { s_exit06 = 1; }
                        if (s_exit06 == 0) { break; }
                    }
                }
                if (ShapeTypeChoice == '7')
                {
                    while (true)
                    {
                        int s_exit07 = 0; string ExitChoice10; char Choice10; int ContinueOp10 = 2;
                        string Sqdata, sl;
                        double sidelength = 0;
                        cout << "请输入以正小数的形式输入一个数据，代表正方形的边长(单位:m)【范围0~1.34*10^154】(第一个数据前请勿输入空格!)：";
                        getline(cin, Sqdata);
                        while (true)
                        {
                            int s_exit07_1 = 0;
                            istringstream s7(Sqdata);
                            getline(s7, sl);
                            s7.str("");
                            pair<bool, double> Getsl = VerifyDemicalValid(sl, 0, 1.34 * pow(10, 154));
                            if (Getsl.first == 0 || Getsl.second == 0) { s_exit07_1++; }
                            else { sidelength = Getsl.second; }
                            if (s_exit07_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式输入一个数据，代表正方形的边长(单位:m)【范围0~1.34*10^154】(第一个数据前请勿输入空格!)：";
                                getline(cin, Sqdata);
                            }
                            Square Sq(sidelength, 0, 0, 0, 0, 0);
                            if (s_exit07_1 == 0)
                            {
                                printf("正方形的周长：%lf m\n", Sq.Preimeter());
                                printf("正方形的面积：%lf ㎡\n", Sq.Area());
                                break;
                            }
                        }
                        Choice10 = Exitchoice(ExitChoice10);
                        if (Choice10 == '1') { ContinueOp10 = 0; }
                        else if (Choice10 == '2') { ContinueOp10 = 1; }
                        if (ContinueOp10 == 0) { s_exit++; s_exit07 = 0; }
                        else { s_exit07 = 1; }
                        if (s_exit07 == 0) { break; }
                        }
                    }
            }
        }
        if (s_exit == 0) { break; }
    }
}
void GeoSolidCalc(string Userlabel)
{
    string GeoSolidTypeInput; char GeoSolidTypeChoice;
    while (true)
    {
        int g_exit = 0;
        cout << "---------- 立体图形模块 ----------\n";
        cout << "立体图形模块功能菜单:\n1.长方体\n2.正方体\n3.圆柱\n4.圆锥\n5.圆台\n6.球\n7.退出此模块\n\n";
        cout << "请选择功能【输入1~7】:";
        getline(cin, GeoSolidTypeInput);
        GeoSolidTypeChoice = GeoSolidTypeInput[0];
        if (!((GeoSolidTypeChoice >= '1' || GeoSolidTypeChoice <= '7') && GeoSolidTypeInput.length() == 1)) { g_exit++; cout << "输入错误，请重新输入！\n\n"; }
        else
        {
            if (GeoSolidTypeChoice == '7') { cout << "正在退出模块！\n\n"; OtherCalculationPage(Userlabel); g_exit = 0; }
            else
            {
                if (GeoSolidTypeChoice == '1')
                {
                    int g_exit01 = 0;
                    while (true)
                    {
                        g_exit01 = 0; string Exit10; char Option01; int ContinueChoice01 = 2;
                        string Cuboiddata, l_d, w_d, h_d;
                        double Length = 0, Width = 0, Heigth = 0;
                        cout << "请输入以正小数的形式分别输入三个数据，代表长方体的长、宽、高(单位:m)【范围0~5.64*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Cuboiddata);
                        while (true)
                        {
                            int g_exit01_1 = 0;
                            istringstream sss1(Cuboiddata);
                            getline(sss1, l_d, ' ');
                            getline(sss1, w_d, ' ');
                            getline(sss1, h_d);
                            sss1.str("");
                            pair<bool, double> pair_length = VerifyDemicalValid(l_d, 0, 5.64 * pow(10, 102));
                            if (pair_length.first == 0 || pair_length.second == 0) { g_exit01_1++; }
                            else { Length = pair_length.second; }
                            pair<bool, double> pair_width = VerifyDemicalValid(w_d, 0, 5.64 * pow(10, 102));
                            if (pair_width.first == 0 || pair_width.second == 0) { g_exit01_1++; }
                            else { Width = pair_width.second; }
                            pair<bool, double> Pair_heigth = VerifyDemicalValid(h_d, 0, 5.64 * pow(10, 102));
                            if (Pair_heigth.first == 0 || Pair_heigth.second == 0) { g_exit01_1++; }
                            else { Heigth = Pair_heigth.second; }
                            if (g_exit01_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入三个数据，代表长方体的长、宽、高【范围0~5.64*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Cuboiddata);
                            }
                            Cuboid cuboid(Length, Width, Heigth);
                            if (g_exit01_1 == 0)
                            {
                                printf("长方体表面积：%lf ㎡\n", cuboid.SurfaceArea());
                                printf("长方体体积：%lf 立方米\n", cuboid.Volume());
                                break;
                            }
                        }
                        Option01 = Exitchoice(Exit10);
                        if (Option01 == '1') { ContinueChoice01 = 0; }
                        else if (Option01 == '2') { ContinueChoice01 = 1; }
                        if (ContinueChoice01 == 0) { g_exit++; g_exit01 = 0; }
                        else { g_exit01 = 1; }
                        if (g_exit01 == 0) { break; }
                    }
                }
                if (GeoSolidTypeChoice == '2')
                {
                    int g_exit02 = 0;
                    while (true)
                    {
                        g_exit02 = 0; string Exit11; char Option02; int ContinueChoice02 = 2;
                        string Cubedata, Sl_d;
                        double SideLength = 0;
                        cout << "请输入以正小数的形式分别输入一个数据，代表正方体的边长(单位:m)【范围0~5.64*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Cubedata);
                        while (true)
                        {
                            int g_exit02_1 = 0;
                            istringstream sss2(Cubedata);
                            getline(sss2, Sl_d, ' ');
                            sss2.str("");
                            pair<bool, double> pair_Sidelength = VerifyDemicalValid(Sl_d, 0, 5.64 * pow(10, 102));
                            if (pair_Sidelength.first == 0 || pair_Sidelength.second == 0) { g_exit02_1++; }
                            else { SideLength = pair_Sidelength.second; }
                            if (g_exit02_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入一个数据，代表正方体的边长(单位:m)【范围0~5.64*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Cubedata);
                            }
                            Cube cube(SideLength, 0, 0, 0);
                            if (g_exit02_1 == 0)
                            {
                                printf("正方体表面积：%lf ㎡\n", cube.SurfaceArea());
                                printf("正方体体积：%lf 立方米\n", cube.Volume());
                                break;
                            }
                        }
                        Option02 = Exitchoice(Exit11);
                        if (Option02 == '1') { ContinueChoice02 = 0; }
                        else if (Option02 == '2') { ContinueChoice02 = 1; }
                        if (ContinueChoice02 == 0) { g_exit++; g_exit02 = 0; }
                        else { g_exit02 = 1; }
                        if (g_exit02 == 0) { break; }
                    }
                }
                if (GeoSolidTypeChoice == '3')
                {
                    int g_exit03 = 0;
                    while (true)
                    {
                        g_exit03 = 0; string Exit12; char Option03; int ContinueChoice03 = 2;
                        string Cylinderdata, Cyr_d, Cyh_d;
                        double BaseRadius = 0, CylinderHeigth = 0;
                        cout << "请输入以正小数的形式分别输入两个数据，代表圆柱底面圆的半径(单位:m)【范围0~1.79*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Cylinderdata);
                        while (true)
                        {
                            int g_exit03_1 = 0;
                            istringstream sss1(Cylinderdata);
                            getline(sss1, Cyr_d, ' ');
                            getline(sss1, Cyh_d, ' ');
                            sss1.str("");
                            pair<bool, double> pair_BaseRadius = VerifyDemicalValid(Cyr_d, 0, 1.79 * pow(10, 102));
                            if (pair_BaseRadius.first == 0 || pair_BaseRadius.second == 0) { g_exit03_1++; }
                            else { BaseRadius = pair_BaseRadius.second; }
                            pair<bool, double> pair_CylinderHeigth = VerifyDemicalValid(Cyh_d, 0, 1.79 * pow(10, 102));
                            if (pair_CylinderHeigth.first == 0 || pair_CylinderHeigth.second == 0) { g_exit03_1++; }
                            else { CylinderHeigth = pair_CylinderHeigth.second; }
                            if (g_exit03_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入两个数据，代表圆柱底面圆的半径(单位:m)【范围0~1.79*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Cylinderdata);
                            }
                            Cylinder cylinder(BaseRadius, CylinderHeigth);
                            if (g_exit03_1 == 0)
                            {
                                printf("圆柱表面积：%lf ㎡\n", cylinder.SurfaceArea());
                                printf("圆柱体积：%lf 立方米\n", cylinder.Volume());
                                break;
                            }
                        }
                        Option03 = Exitchoice(Exit12);
                        if (Option03 == '1') { ContinueChoice03 = 0; }
                        else if (Option03 == '2') { ContinueChoice03 = 1; }
                        if (ContinueChoice03 == 0) { g_exit++; g_exit03 = 0; }
                        else { g_exit03 = 1; }
                        if (g_exit03 == 0) { break; }
                    }
                }
                if (GeoSolidTypeChoice == '4')
                {
                    int g_exit04 = 0;
                    while (true)
                    {
                        g_exit04 = 0; string Exit13; char Option04; int ContinueChoice04 = 2;
                        string Conedata, BaseR_D, ConeH_d, Genetrix_d;
                        double ConeBaseRadius = 0, ConeHeigth = 0, ConeGeneratrixLength = 0;
                        cout << "请输入以正小数的形式分别输入三个数据，代表圆锥底面圆的半径,圆锥高,圆锥母线长(单位:m)【范围0~1.79*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, Conedata);
                        while (true)
                        {
                            int g_exit04_1 = 0;
                            istringstream sss4(Conedata);
                            getline(sss4, BaseR_D, ' ');
                            getline(sss4, ConeH_d, ' ');
                            getline(sss4, Genetrix_d);
                            sss4.str("");
                            pair<bool, double> ConeRadius = VerifyDemicalValid(BaseR_D, 0, 1.79 * pow(10, 102));
                            if (ConeRadius.first == 0 || ConeRadius.second == 0) { g_exit04_1++; }
                            else { ConeBaseRadius = ConeRadius.second; }
                            pair<bool, double> ConeH = VerifyDemicalValid(ConeH_d, 0, 1.79 * pow(10, 102));
                            if (ConeH.first == 0 || ConeH.second == 0) { g_exit04_1++; }
                            else { ConeHeigth = ConeH.second; }
                            pair<bool, double> ConeGenetrix = VerifyDemicalValid(Genetrix_d, 0, 1.79 * pow(10, 102));
                            if (ConeGenetrix.first == 0 || ConeGenetrix.second == 0) { g_exit04_1++; }
                            else { ConeGeneratrixLength = ConeGenetrix.second; }
                            if (g_exit04_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入三个数据，代表圆锥底面圆的半径,圆锥高,圆锥母线长(单位:m)【范围0~1.79*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, Conedata);
                            }
                            Cone cone(ConeBaseRadius, ConeHeigth, ConeGeneratrixLength);
                            if (g_exit04_1 == 0)
                            {
                                printf("圆锥表面积：%lf ㎡\n", cone.SurfaceArea());
                                printf("圆锥体积：%lf 立方米\n", cone.Volume());
                                break;
                            }
                        }
                        Option04 = Exitchoice(Exit13);
                        if (Option04 == '1') { ContinueChoice04 = 0; }
                        else if (Option04 == '2') { ContinueChoice04 = 1; }
                        if (ContinueChoice04 == 0) { g_exit++; g_exit04 = 0; }
                        else { g_exit04 = 1; }
                        if (g_exit04 == 0) { break; }
                    }
                }
                if (GeoSolidTypeChoice == '5')
                {
                    int g_exit05 = 0;
                    while (true)
                    {
                        g_exit05 = 0; string Exit14; char Option05; int ContinueChoice05 = 2;
                        string CirTruncConedata, BaseCirR_D, TopCirR_D, CirTrunc_H, CirTruncConeGenetrix_d;
                        double ConeBaseRadius = 0, ConeTopRadius = 0, TruncConeHeigth = 0, ConeGeneratrixLength = 0;
                        cout << "请输入以正小数的形式分别输入四个数据，代表圆台上下底面圆的半径(上下底面圆的半径不能相等),圆台的高,圆台母线长(单位:m)【范围0~1.79*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, CirTruncConedata);
                        while (true)
                        {
                            int g_exit04_1 = 0;
                            istringstream sss4(CirTruncConedata);
                            getline(sss4, BaseCirR_D, ' ');
                            getline(sss4, TopCirR_D, ' ');
                            getline(sss4, CirTrunc_H, ' ');
                            getline(sss4, CirTruncConeGenetrix_d);
                            sss4.str("");
                            pair<bool, double> BaseRadius = VerifyDemicalValid(BaseCirR_D, 0, 1.79 * pow(10, 102));
                            if (BaseRadius.first == 0 || BaseRadius.second == 0) { g_exit04_1++; }
                            else { ConeBaseRadius = BaseRadius.second; }
                            pair<bool, double> TopRadius = VerifyDemicalValid(TopCirR_D, 0, 1.79 * pow(10, 102));
                            if (TopRadius.first == 0 || TopRadius.second == 0 || TopRadius.second == ConeBaseRadius) { g_exit04_1++; }
                            else { ConeTopRadius = TopRadius.second; }
                            pair<bool, double> TruncConeheigth = VerifyDemicalValid(TopCirR_D, 0, 1.79 * pow(10, 102));
                            if (TruncConeheigth.first == 0 || TruncConeheigth.second == 0) { g_exit04_1++; }
                            else { TruncConeHeigth = TruncConeheigth.second; }
                            pair<bool, double> TruncConeGenetrix = VerifyDemicalValid(CirTruncConeGenetrix_d, 0, 1.79 * pow(10, 102));
                            if (TruncConeGenetrix.first == 0 || TruncConeGenetrix.second == 0) { g_exit04_1++; }
                            else { ConeGeneratrixLength = TruncConeGenetrix.second; }
                            if (g_exit04_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入四个数据，代表圆台上下底面圆的半径(上下底面圆的半径不能相等),圆台的高,圆台母线长(单位:m)【范围0~1.79*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, CirTruncConedata);
                            }
                            CircularTruncatedCone cirTruncCone(ConeBaseRadius, ConeTopRadius, TruncConeHeigth, ConeGeneratrixLength);
                            if (g_exit04_1 == 0)
                            {
                                printf("圆台表面积：%lf ㎡\n", cirTruncCone.SurfaceArea());
                                printf("圆台体积：%lf 立方米\n", cirTruncCone.Volume());
                                break;
                            }
                        }
                        Option05 = Exitchoice(Exit14);
                        if (Option05 == '1') { ContinueChoice05 = 0; }
                        else if (Option05 == '2') { ContinueChoice05 = 1; }
                        if (ContinueChoice05 == 0) { g_exit++; g_exit05 = 0; }
                        else { g_exit05 = 1; }
                        if (g_exit05 == 0) { break; }
                    }
                }
                if (GeoSolidTypeChoice == '6') 
                {
                    int g_exit06 = 0;
                    while (true)
                    {
                        g_exit06 = 0; string Exit15; char Option06; int ContinueChoice06 = 2;
                        string SphereData, SphereRadius_d;
                        double SphereRadius = 0;
                        cout << "请输入以正小数的形式分别输入一个数据，代表球的半径(单位:m)【范围0~4.23*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, SphereData);
                        while (true)
                        {
                            int g_exit06_1 = 0;
                            istringstream sss6(SphereData);
                            getline(sss6, SphereRadius_d, ' ');
                            sss6.str("");
                            pair<bool, double> pair_Spherelength = VerifyDemicalValid(SphereRadius_d, 0, 4.23 * pow(10, 102));
                            if (pair_Spherelength.first == 0 || pair_Spherelength.second == 0) { g_exit06_1++; }
                            else { SphereRadius = pair_Spherelength.second; }
                            if (g_exit06_1 != 0)
                            {
                                cout << "数据输入有误!\n请输入以正小数的形式分别输入一个数据，代表球的半径(单位:m)【范围0~4.23*10^102】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, SphereData);
                            }
                            Sphere sphere(SphereRadius);
                            if (g_exit06_1 == 0)
                            {
                                printf("球的表面积：%lf ㎡\n", sphere.SurfaceArea());
                                printf("球的体积：%lf 立方米\n", sphere.Volume());
                                break;
                            }
                        }
                        Option06 = Exitchoice(Exit15);
                        if (Option06 == '1') { ContinueChoice06 = 0; }
                        else if (Option06 == '2') { ContinueChoice06 = 1; }
                        if (ContinueChoice06 == 0) { g_exit++; g_exit06 = 0; }
                        else { g_exit06 = 1; }
                        if (g_exit06 == 0) { break; }
                    }
                }
            }
        }
        if (g_exit == 0) { break; }
    }
}
void BMICalc( string Userlabel) 
{
    string BMIModuleOp; char BMIMoudleChoice;
    while(true)
    {
        int exit01=0;
        cout << "---------- BMI模块 ----------\n";
        cout << "本模块结果解释：偏瘦（BMI<18.5)、正常（18.5~25.0)、过重（25.0~30.0)、肥胖(>30.0)\n";
        cout << "BMI模块功能菜单:\n1.BMI计算\n2.退出BMI模块\n";
        cout << "请选择功能【输入1或2】:";
        getline(cin, BMIModuleOp);
        BMIMoudleChoice = BMIModuleOp[0];
        if (!((BMIMoudleChoice == '1' || BMIMoudleChoice == '2') && BMIModuleOp.length() == 1)) { exit01++; cout << "输入错误，请重新输入！\n\n"; }
        else
        {
            if (BMIMoudleChoice == '2') { exit01 = 0; cout << "--------- 正在退出BMI模块! ----------"; OtherCalculationPage(Userlabel);  }
            else
            {
                if (BMIMoudleChoice == '1')
                {
                    while (true)
                    {
                        int exit01_1 = 0;
                        string Exitchoice3; char Choice3; int  ContinueOp3=2;
                        string GetUserdata; string weigth, heigth;
                        double heigth_data, weigth_data, BMI;
                        cout << "请输入以小数的形式分别输入两个数据，代表身高（cm）【范围：0~300cm】和体重（kg）【范围：0~200kg】,数与数之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                        getline(cin, GetUserdata);
                        while (true)
                        {
                            int exit01_2 = 0;
                            istringstream s1(GetUserdata);
                            getline(s1, heigth, ' ');
                            getline(s1, weigth);
                            s1.str("");
                            pair<bool, double> pair_heigth = VerifyDemicalValid(heigth, 0, 300);
                            if (pair_heigth.first == 0 || pair_heigth.second == 0) { exit01_2++; }
                            else { heigth_data = pair_heigth.second / 100.0; }
                            pair<bool, double> pair_weigth = VerifyDemicalValid(weigth, 0, 200);
                            if (pair_weigth.first == 0 || pair_weigth.second == 0) { exit01_2++; }
                            else { weigth_data = pair_weigth.second; }
                            if (exit01_2 != 0)
                            {
                                cout << "身高或体重输入有误!\n请以正小数形式分别输入两个数据，代表身高（cm）【范围：0~300cm】和体重（kg）【范围：0~200kg】,数据之间用一个空格隔开(第一个数据前请勿输入空格!)：";
                                getline(cin, GetUserdata);
                            }
                            if (exit01_2 == 0)
                            {
                                BMI = weigth_data / (heigth_data * heigth_data);
                                if (0 <= BMI && BMI < 18.5) { printf("您的BMI值:%.1f\n结果:偏瘦\n\n", BMI); }
                                else if (18.5 <= BMI && BMI < 25) { printf("您的BMI值:%.1f\n结果:正常\n\n", BMI); }
                                else if (25 <= BMI && BMI < 30) { printf("您的BMI值:%.1f\n结果:过重\n\n", BMI); }
                                else if (BMI >= 30) { printf("您的BMI值:%.1f\n结果:肥胖\n\n", BMI); }
                                break;
                            }
                        }
                        Choice3 = Exitchoice(Exitchoice3);
                        if (Choice3 == '1') { ContinueOp3 = 0; }
                        else if (Choice3 == '2') { ContinueOp3 = 1; }
                        if (ContinueOp3 == 0) { exit01++; exit01_1 = 0; }
                        else { exit01_1 = 1; }
                        if (exit01_1 == 0) { break; }
                    }
                }   
            }
        }
        if (exit01 == 0) {break;}     
    }    
}
void TriFunc(string Userlabel)
{
    string TriFuncChoice; char TriFuncOp;
    while (true)
    {
        int Tri1 = 0;
        cout << "---------- 三角函数计算 ----------\n";
        cout << "提示：若想计算某一角度的三角函数，请先将该角度转化为弧度，再以小数输入所需计算的弧度值！\n";
        cout << "功能菜单:\n1.sin\n2.cos\n3.tan\n4.退出\n\n";
        cout << "请输入所需功能【键入功能前的数字】:";
        getline(cin, TriFuncChoice);
        TriFuncOp = TriFuncChoice[0];
        if (!(TriFuncOp >= '1' && TriFuncOp <= 's4' && TriFuncChoice.length() == 1)) { Tri1++; cout << "输入错误,请重新输入!\n\n"; }
        if (TriFuncOp == '4') { Tri1 = 0; break; }
        else
        {
            if (TriFuncOp == '1') 
            {
                while (true)
                {
                    int Tri1_1 = 0; string Triexit1_1; char Triexit1_1op;
                    string sinnum; long double sinOriginnum;
                    cout << "请输入一个数【范围：-1.79*(10^308)~1.79*(10^308)】（输入的数将以弧度制进行计算）：";
                    getline(cin, sinnum);
                    pair<bool, long double> Getsinnum = VerifyDemicalValid(sinnum, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                    if (Getsinnum.first == 0) { Tri1_1++; cout << "输入数据有误，请重新输入！\n\n"; }
                    else { sinOriginnum = Getsinnum.second; }
                    if (Tri1_1 == 0)
                    {
                        double sinCalcnum = sin(sinOriginnum);
                        printf("sin(%lf)=%lf\n", sinOriginnum, sinCalcnum);
                        Triexit1_1op = Exitchoice(Triexit1_1);
                        if (Triexit1_1op == '1') { Tri1_1 = 0;}
                        else { Tri1_1 = 1; }
                    }
                    if (Tri1_1 == 0) { Tri1 = 1; break; }
                }
            }
            if (TriFuncOp == '2') 
            {
                while(true)
                {
                    int Tri1_2 = 0; string Triexit1_2; char Triexit1_2op;
                    string cosnum; double cosOriginnum;
                    cout << "请输入一个数【范围：-1.79*(10^308)~1.79*(10^308)】（输入的数将以弧度制进行计算）：";
                    getline(cin, cosnum);
                    pair<bool, double> Getcosnum = VerifyDemicalValid(cosnum, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                    if (Getcosnum.first == 0) { Tri1_2++; cout << "输入数据有误，请重新输入！\n\n"; }
                    else { cosOriginnum = Getcosnum.second; }
                    if (Tri1_2 == 0)
                    {
                        double cosCalcnum = cos(cosOriginnum);
                        printf("cos(%lf)=%lf\n", cosOriginnum, cosCalcnum);
                        Triexit1_2op = Exitchoice(Triexit1_2);
                        if (Triexit1_2op == '1') { Tri1_2 = 0; }
                        else { Tri1_2 = 1; }
                    }
                    if (Tri1_2 == 0) { Tri1 = 1; break; }
                }
            }
            if (TriFuncOp == '3') 
            {
                while(true)
                {
                    int Tri1_3 = 0; string Triexit1_3; char Triexit1_3op;
                    string tannum; double tanOriginnum;
                    cout << "请输入一个数【范围：-1.570796~1.570796】（输入的数将以弧度制进行计算）：";
                    getline(cin, tannum);
                    pair<bool, double> Gettannum = VerifyDemicalValid(tannum, -1.570796, 1.570796);
                    if (Gettannum.first == 0) { Tri1_3++; cout << "输入数据有误，请重新输入！\n\n"; }
                    else 
                    { 
                        tanOriginnum = Gettannum.second; 
                    }
                    if (Tri1_3 == 0)
                    {
                        double tanCalcnum = tan(tanOriginnum);
                        printf("tan(%lf)=%lf\n", tanOriginnum, tanCalcnum);
                        Triexit1_3op = Exitchoice(Triexit1_3);
                        if (Triexit1_3op == '1') { Tri1_3 = 0; }
                        else { Tri1_3 = 1; }
                    }
                    if (Tri1_3 == 0) { Tri1 = 1; break; }
                }
            }
        }
    }
    TriFunctionCalc(Userlabel);
}
void InverseTriFunc(string Userlabel)
{
    string InverseTriFuncChoice; char InverseTriFuncOp;
    while (true)
    {
        int Tri2 = 0;
        cout << "---------- 反三角函数计算 ----------\n";
        cout << "提示：若想计算某一角度的反三角函数，请先将该角度转化为弧度，再以小数输入所需计算的弧度值！\n";
        cout << "功能菜单:\n1.arcsin\n2.arccos\n3.arctan\n4.退出\n\n";
        cout << "请输入所需功能【键入功能前的数字】:";
        getline(cin, InverseTriFuncChoice);
        InverseTriFuncOp = InverseTriFuncChoice[0];
        if (!(InverseTriFuncOp >= '1' && InverseTriFuncOp <= '4' && InverseTriFuncChoice.length() == 1)) { Tri2++; cout << "输入错误,请重新输入!\n\n"; }
        if (InverseTriFuncOp == '4') { Tri2 = 0; }
        else
        {
            if (InverseTriFuncOp == '1') 
            {
                while (true)
                {
                    int Tri2_1 = 0; string Triexit2_1; char Triexit2_1op;
                    string asinnum; long double asinOriginnum;
                    cout << "请输入一个数【范围：-1~1】（输入的数将以弧度制进行计算）：";
                    getline(cin, asinnum);
                    pair<bool, long double> Getasinnum = VerifyDemicalValid(asinnum, -1, 1);
                    if (Getasinnum.first == 0) { Tri2_1++; cout << "输入数据有误，请重新输入！\n\n"; }
                    else { asinOriginnum = Getasinnum.second; }
                    if (Tri2_1 == 0)
                    {
                        double asinCalcnum = asin(asinOriginnum);
                        printf("arcsin(%lf)=%lf\n", asinOriginnum, asinCalcnum);
                        Triexit2_1op = Exitchoice(Triexit2_1);
                        if (Triexit2_1op == '1') { Tri2_1 = 0; }
                        else { Tri2_1 = 1; }
                    }
                    if (Tri2_1 == 0) { Tri2 = 1; break; }
                }
            }
            if (InverseTriFuncOp == '2') 
            {
                while (true)
                {
                    int Tri2_2 = 0; string Triexit2_2; char Triexit2_2op;
                    string acosnum; long double acosOriginnum;
                    cout << "请输入一个数【范围：-1~1】（输入的数将以弧度制进行计算）：";
                    getline(cin, acosnum);
                    pair<bool, long double> Getacosnum = VerifyDemicalValid(acosnum, -1, 1);
                    if (Getacosnum.first == 0) { Tri2_2++; cout << "输入数据有误，请重新输入！\n\n"; }
                    else { acosOriginnum = Getacosnum.second; }
                    if (Tri2_2 == 0)
                    {
                        double asinCalcnum = acos(acosOriginnum);
                        printf("arcsin(%lf)=%lf\n", acosOriginnum, asinCalcnum);
                        Triexit2_2op = Exitchoice(Triexit2_2);
                        if (Triexit2_2op == '1') { Tri2_2 = 0; }
                        else { Tri2_2 = 1; }
                    }
                    if (Tri2_2 == 0) { Tri2 = 1; break; }
                }
            }
            if (InverseTriFuncOp == '3') 
            {
                while (true)
                {
                    int Tri2_3 = 0; string Triexit2_3; char Triexit2_3op;
                    string atannum; long double ataniginnum;
                    cout << "请输入一个数【范围：-1.79*(10^308)~1.79*(10^308)】（输入的数将以弧度制进行计算）：";
                    getline(cin, atannum);
                    pair<bool, long double> Getatannum = VerifyDemicalValid(atannum, -(1.79 * pow(10, 308)), 1.79 * pow(10, 308));
                    if (Getatannum.first == 0) { Tri2_3++; cout << "输入数据有误，请重新输入！\n\n"; }
                    else { ataniginnum = Getatannum.second; }
                    if (Tri2_3 == 0)
                    {
                        double atanCalcnum = atan(ataniginnum);
                        printf("arctan(%lf)=%lf\n", ataniginnum, atanCalcnum);
                        Triexit2_3op = Exitchoice(Triexit2_3);
                        if (Triexit2_3op == '1') { Tri2_3 = 0; }
                        else { Tri2_3 = 1; }
                    }
                    if (Tri2_3 == 0) { Tri2 = 1; break; }
                }
            }
        }
        if (Tri2 == 0) { break; }
    }
    TriFunctionCalc(Userlabel);
}
void HighIntPlus(string Userlabel)
{
    while (true)
    {
        int HighPlusInErr = 0; string E1; char E1op;
        int plusnum1[50000]{ 0 }, plusnum2[50000]{ 0 }, sum[50005]{ 0 };
        string  n1, n2;
        cout << "请输入一个50000位内的正整数:";
        getline(cin, n1);
        for (ull i = 0; i < n1.size(); i++) { if (isdigit(n1[i]) == false) { HighPlusInErr++; break; } }
        cout << "请再输入一个50000位内的正整数:";
        getline(cin, n2);
        for (ull i = 0; i < n2.size(); i++) { if (isdigit(n2[i]) == false) { HighPlusInErr++; break; } }
        if (HighPlusInErr) { cout << "输入数据有误!请重新输入!\n"; }
        if (HighPlusInErr == 0)
        {
            int length = max(n1.size(), n2.size());
            for (int i = n1.size() - 1, j = 1; i >= 0; i--, j++) { plusnum1[j] = n1[i] - '0'; }
            for (int i = n2.size() - 1, j = 1; i >= 0; i--, j++) { plusnum2[j] = n2[i] - '0'; }
            for (int i = 1; i <= length; i++)
            {
                sum[i] += (plusnum1[i] + plusnum2[i]);
                if (sum[i] >= 10) { sum[i + 1] = sum[i] / 10; sum[i] %= 10; }
            }
            if (sum[length + 1] ) { length++; }
            cout << "\n计算结果:";
            for (int i = length; i >= 1; i--) { cout << sum[i]; }
        }
        E1op = Exitchoice(E1);
        if (E1op == '1') { break; }
    }
}
void HighIntMinus(string Userlabel)
{
    while(true)
    {
        int HighMinusErr = 0;
        bool flag = 1;//判断结果是否为负
        string subnum1, subnum2, E3; char E3op;
        int num1[50000]{ 0 }, num2[50000]{ 0 }, subres[50000]{ 0 };
        cout << "请输入被减数:";
        getline(cin, subnum1);
        for (int i = 0; i < subnum1.size(); i++) { if (isdigit(subnum1[i]) == false) { HighMinusErr++; break; } }
        cout << "请输入减数:";
        getline(cin, subnum2);
        for (int i = 0; i < subnum2.size(); i++) { if (isdigit(subnum2[i]) == false) { HighMinusErr++; break; } }
        if (HighMinusErr) { cout << "输入错误,请重新输入!"; }
        else
        {
            if (cmpnum(subnum1, subnum2) == 0) { swap(subnum1, subnum2); flag = 0; }
            for (int i = subnum1.size()-1, j = 1; i >= 0; i--, j++) { num1[j] = int(subnum1[i] - '0'); }
            for (int i = subnum2.size()-1, j = 1; i >= 0; i--, j++) { num2[j] = int(subnum2[i] - '0'); }
            int length = subnum1.size();
            for (int i = 1; i <= length; i++)
            {
                if (num1[i] < num2[i]) { subres[i] += (num1[i] + 10 - num2[i]); subres[i + 1] = -1; }
                else { subres[i] += (num1[i] - num2[i]); subres[i + 1] = 0; }
            }
            if (flag == 0)
            {
                cout << "计算结果: -";
                for (int i = length; i >= 1; i--)
                {
                    if (i == length) { if (subres[i]) { cout << subres[i]; } }
                    else { cout << subres[i]; }
                }
            }
            else
            {
                cout << "计算结果:";
                for (int i = length; i >= 1; i--)
                {
                    if (i == length) { if (subres[i]) {cout << subres[i]; }}
                    else  { cout << subres[i]; }
                }
            }
        }
        E3op = Exitchoice(E3);
        if (E3op == '1') { break; }
    }
}
void HighIntMultiply(string Userlabel)
{
    while (true)
    {
        string mulnum1, mulnum2; string E2; char E2op;
        int num1[25000]{ 0 }, num2[25000]{ 0 }, mulres[50005]{ 0 },HighMulErr=0;
        cout << "请输入乘数1:";
        getline(cin, mulnum1);
        for (ull i = 0; i < mulnum1.size(); i++) { if (isdigit(mulnum1[i]) == false) { HighMulErr++; break; } }
        cout << "请输入乘数2:";
        getline(cin, mulnum2);
        for (ull i = 0; i < mulnum2.size(); i++) { if (isdigit(mulnum2[i]) == false) { HighMulErr++; break; } }
        if (HighMulErr) { cout << "输入数据有误!请重新输入!\n"; }
        if (HighMulErr == 0)
        {
            int totallen = mulnum1.size() + mulnum2.size();
            for (int i = mulnum1.size() - 1; i >= 0; i--) { num1[mulnum1.size() - i] = int(mulnum1[i] - '0'); }
            for (int i = mulnum2.size() - 1; i >= 0; i--) { num2[mulnum2.size() - i] = int(mulnum2[i] - '0'); }
            for (int i = 1; i <= mulnum1.size(); i++)
            {
                for (int j = 1; j <= mulnum2.size(); j++)
                {
                    mulres[i + j - 1] += (num1[i] * num2[j]);
                }
            }
            for (int i = 1; i <= totallen; i++)
            {
                if (mulres[i] >= 10) { mulres[i + 1] = mulres[i] / 10; mulres[i] %= 10; }
            }
            for (; !mulres[totallen];) { totallen--; }
            cout << "\n计算结果: ";
            for (int i = max(1,totallen); i >= 1; i--)
            {
                cout << mulres[i];
            }
            E2op = Exitchoice(E2);
            if (E2op == '1') { break; }
        }

    }
}
void HighIntDivide(string Userlabel)
{
    while(true)
    {
        int HighIntErr4 = 0; bool cmpres = true;
        string Divnum1, Divnum2, E4; char E4op;
        int num1[50000]{ 0 }, num2[50000]{ 0 }, divres[50000]{ 0 }, temp[50000]{ 0 };
        cout << "请输入被除数:";
        getline(cin, Divnum1);
        for (int i = 0; i < Divnum1.length(); i++) { if (isdigit(Divnum1[i]) == false) { HighIntErr4++; break; } }
        cout << "请输入除数:";
        getline(cin, Divnum2);
        for (int i = 0; i < Divnum2.length(); i++)
        {
            if (Divnum2[0] == '0') { HighIntErr4++; break; }
            else { if (isdigit(Divnum2[i]) == false) { HighIntErr4++; break; } }
        }
        if (HighIntErr4) { cout << "输入中含有非数字字符或除数为0,请重新输入!\n\n"; }
        else
        {
            divres[0] = Divnum1.length() - Divnum2.length() + 1;
            if (cmpnum(Divnum1, Divnum2) == 0)
            { 
                cmpres = false; 
                cout << "商:0\n" << "余数:" << Divnum2;
            }//判断被除数与除数大小关系
            else
            {
                num1[0] = Divnum1.length(); num2[0] = Divnum2.length();
                for (int i = Divnum1.length() - 1; i >= 0; i--) { num1[Divnum1.length() - i] = Divnum1[i] - '0'; }
                for (int i = Divnum2.length() - 1; i >= 0; i--) { num2[Divnum2.length() - i] = Divnum2[i] - '0'; }
                for (int i = divres[0]; i >= 1; i--)
                {
                    memset(temp, 0, sizeof(temp));
                    numcpy(num2, temp, i);
                    while (cmp(num1, temp) >= 0)
                    {
                        divres[i]++;
                        minu(num1, temp);
                    }
                }
                while (divres[divres[0]] == 0 && divres[0] > 0) { divres[0]--; }
                cout << "商:";
                print(divres);
                cout << "\n余数:";
                print(num1);
            }
        }
        E4op = Exitchoice(E4);
        if (E4op == '1') { break; }
    }
}
void HighIntMod(string Userlabel)
{
    while (true)
    {
        int HighIntErr5 = 0; bool cmpres = true;
        string Divnum1, Divnum2, E5; char E5op;
        int num1[50000]{ 0 }, num2[50000]{ 0 }, divres[50000]{ 0 }, temp[50000]{ 0 };
        cout << "请输入被除数:";
        getline(cin, Divnum1);
        for (int i = 0; i < Divnum1.length(); i++) { if (isdigit(Divnum1[i]) == false) { HighIntErr5++; break; } }
        cout << "请输入除数:";
        getline(cin, Divnum2);
        for (int i = 0; i < Divnum2.length(); i++)
        {
            if (Divnum2[0] == '0') { HighIntErr5++; break; }
            else { if (isdigit(Divnum2[i]) == false) { HighIntErr5++; break; } }
        }
        if (HighIntErr5) { cout << "输入中含有非数字字符 或 除数为0 ,请重新输入!\n\n"; }
        else
        {
            divres[0] = Divnum1.length() - Divnum2.length() + 1;
            if (cmpnum(Divnum1, Divnum2) == 0)
            {
                cmpres = false;
                cout << Divnum1 <<" mod "<< Divnum2 <<" = "<<Divnum2;
            }//判断被除数与除数大小关系
            else
            {
                num1[0] = Divnum1.length(); num2[0] = Divnum2.length();
                for (int i = Divnum1.length() - 1; i >= 0; i--) { num1[Divnum1.length() - i] = Divnum1[i] - '0'; }
                for (int i = Divnum2.length() - 1; i >= 0; i--) { num2[Divnum2.length() - i] = Divnum2[i] - '0'; }
                for (int i = divres[0]; i >= 1; i--)
                {
                    memset(temp, 0, sizeof(temp));
                    numcpy(num2, temp, i);
                    while (cmp(num1, temp) >= 0)
                    {
                        divres[i]++;
                        minu(num1, temp);
                    }
                }
                while (divres[divres[0]] == 0 && divres[0] > 0) { divres[0]--; }
                cout << Divnum1 << " mod " << Divnum2 << " = ";
                print(num1);
            }
            E5op = Exitchoice(E5);
            if (E5op == '1') { break; }
        }   
    }
}
void HighFactorialCalc(string Userlabel)
{
    while(true)
    {
        int HighIntErr6 = 0,length=1,Originnum=0;
        string num, factnum, E6; char E6op;
        memset(factorres,0 ,sizeof(factorres));
        factorres[0] = 1;
        cout << "请输入一个不超过 100,0000 的正整数:";
        getline(cin, num);
        if (num.length() == 0 || num.length() > 6&&num!="1000000") { HighIntErr6++; }
        for (int i = 0; i < num.length(); i++) {if (!isdigit(num[i])) { HighIntErr6++; break; } }
        if (HighIntErr6) { cout << "数据输入有误!\n"; }
        else
        {
            clock_t start = clock();
            for (int i = 0; i <= num.size(); i++) { Originnum += (num[i] - '0') * int(pow(10, num.size() - 1 - i)); }
            for (int i = 1; i <= Originnum; i++)
            {
                int position = 0,move=0;
                while (true)
                {
                    int mid_num = factorres[position] * i + move;
                    factorres[position] = mid_num % 10;
                    move = mid_num / 10;
                    position++;
                    if (factorres[position] == 0 && move == 0 && position >= length) { break; }
                }
                length = position;
            }
            printf("%d 的阶乘结果:\n", Originnum);
            for (int i = length - 1; i >= 0; i--) { cout << factorres[i]; }
            clock_t end = clock();
            printf("\n(阶乘结果位数 : %d ,计算用时: %lf s)\n", length,(double)(end-start)/CLOCKS_PER_SEC);
            
            E6op = Exitchoice(E6);
            if (E6op == '1') { break; }
        }
    }
}
//其他函数
bool CheckInput(string input_string)//检查格式是否正确
{
    bool flag2 = true;
    if (0<=input_string.length()&&input_string.length() < 6) { flag2 = false; return flag2; }
    else
    {
        for (int i = 0; i < input_string.length(); i++)
        {
            char x = input_string[i]; 
            if (isalnum(x) || x == '_') { continue; }
            else { flag2 = false; return flag2; }
        }
        return flag2;
    }
}
void ShowSystemTime()//显示时间
{
    SYSTEMTIME time0;
    GetLocalTime(&time0);
    int Dayofweek = time0.wDayOfWeek;
    string dayofweek;
    switch (Dayofweek)
    {
        case 1:dayofweek = "一"; break;
        case 2:dayofweek = "二"; break;
        case 3:dayofweek = "三"; break;
        case 4:dayofweek = "四"; break;
        case 5:dayofweek = "五"; break;
        case 6:dayofweek = "六"; break;
        case 7:dayofweek = "日"; break;
        default:break;
    }
    for (int i = 0; i < 40; i++) { cout << "*"; } 
    cout << "\n*              时      间              *\n";
    printf("*  今天是 %4d 年 %2d 月 %2d 日 (星期", time0.wYear, time0.wMonth, time0.wDay);
    cout << dayofweek << ")  *\n";
    printf("* 现在是      %2d 时 %02d 分 %02d 秒        *\n", time0.wHour, time0.wMinute, time0.wSecond);
    for (int i = 0; i < 40; i++) { cout << "*"; } cout << endl;
}
void IfContainerEmpty()
{
    if (Usernamelist.empty() == false) { vector<string>().swap(Usernamelist); }
    if (Passwordlist.empty() == false) { vector<string>().swap(Passwordlist); }
    if (BlacklistUser.empty() == false) { vector<string>().swap(BlacklistUser); }
}
char Exitchoice(string ChoiceInput)
{
    char choice;
    while (true)
    {
        int exit000 = 0;
        cout << "\n是否退出当前功能？【请选择(1.是/2.否)】：";
        getline(cin, ChoiceInput);
        choice = ChoiceInput[0];
        if (!('1' <= choice && choice <= '2' && ChoiceInput.length() == 1)) { exit000++; cout << "输入错误！请重新输入\n\n"; }
        if (exit000 == 0) { break; }
    }
    return choice;
}
bool prime(ull num)
{
    bool flag = true;
    if (num == 1 || num == 0) { flag = false; }
    else if (num == 2 || num == 3) { flag = true; }
    else
    {
        if (num % 6 != 1 && num % 6 != 5) { flag = false; }
        else
        {
            for (ull i = 5; i <= sqrt(num); i+=6)
            {
                if (num % i == 0 || num % (i + 2) == 0) { flag = false; break; }
            }
        }
    }
    return flag;
}
pair<bool, double> VerifyDemicalValid(string demical, double l, double r)
{
    stringstream ss;
    double demicalnum = 0;
    bool anly = true;
    if ( count(demical.begin(), demical.end(), '.') >=2||count(demical.begin(),demical.end(),'-')>=2||demical.length()==0)
    { anly = false; demicalnum = -1; }
    if (anly == true)
    {
        for (int i = 0; i < demical.size(); i++)
        {
            if (!(isdigit(demical[i]) || demical[i] == '.' || demical[i] == '-')) { anly = false;  demicalnum = -1; break; }
        }
    }
    if (anly == true)
    {
        ss << demical;
        ss >> demicalnum;
    }
    if (!(l <= demicalnum && demicalnum <= r)) { anly = false; demicalnum = -1; }
    ss.str("");
    return make_pair(anly, demicalnum);
}
bool cmpnum(string a, string b)
{
    if (a.length() < b.length()) { return false; }
    else
    {
        if (a.length() == b.length())
        {
            for (int i = 0; i < a.size(); i++)
            {
                if (a[i] < b[i]) { return false; break; }
            }
        }
    }
    return true;
}
void readuserdata(string In_useraccountdata,string In_blacklistuser)
{
    string Getusername, Getuserpassword;
    ifstream R_useraccount(userinfoFile), R_blackfile(blacklistFile);
    //if (R_useraccount.is_open() == false) { cout << "File open failed!\n"; }
    //if(R_blackfile.is_open()==false){ cout << "File open failed!\n"; }
    while (getline(R_useraccount, In_useraccountdata)) 
    {  istringstream iss(In_useraccountdata);
        getline(iss, Getusername, ':');
        getline(iss, Getuserpassword);
        Usernamelist.push_back(Getusername);
        Passwordlist.push_back(Getuserpassword); 
    }
    while (getline(R_blackfile, In_blacklistuser)){BlacklistUser.push_back(In_blacklistuser);} 
    R_useraccount.close();    
    R_blackfile.close();
}
void numcpy(int p[], int q[], int times)
{
    for (int i = 1; i <= p[0]; i++) { q[i + times - 1] = p[i]; }
    q[0] = p[0] + times - 1;
}
void minu(int a[], int b[])
{
    for (int i = 1; i <= a[0]; i++)
    {
        if (a[i] < b[i]) { a[i + 1]--; a[i] += (10 - b[i]); }
        else { a[i] -= b[i]; }
    }
    while (a[a[0]] == 0 && a[0] > 0) { a[0]--; }
}
int cmp(int a[], int b[])
{
    if  (a[0] > b[0]) { return 1; }
    else if(a[0]<b[0]) { return -1; }
    for (int i = a[0]; i >= 1; i--)
    {
        if (a[i] < b[i]) { return -1; }
        if (a[i] > b[i]) { return 1; }
    }
    return 0;   
}
void print(int res[])
{
    if (res[0] == 0) { cout << "0";  }
    else
    {
        for (int i = res[0]; i >= 1; i--) { cout << res[i]; }
    }
}