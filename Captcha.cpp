#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool CheckCaptcha(string& captcha, string& user_captcha)
{
    return captcha.compare(user_captcha)==0;
}
string generateCaptcha(int n)
{
    time_t t;
    srand((unsigned)time(&t));
    string chrs = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    string captcha = " ";
    while(n--)
        captcha.push_back(chrs[rand()%62]);
    return captcha;
}
int main()
{
    string captcha = generateCaptcha(9);
    cout<< captcha <<endl;
    string usr_captcha;
    cout<<"Enter Captcha: "<<endl;
    cin>> usr_captcha;
    if(CheckCaptcha(captcha, usr_captcha))
        cout<<"Captcha Matched"<<endl;
    else
        cout<<"Captcha Not Matched"<<endl;

    return 0;
}