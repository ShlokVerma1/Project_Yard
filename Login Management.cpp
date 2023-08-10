#include <iostream>
#include <string>
#include <vector>
using namespace std;

class User{
    private:
        string username, password;
    public:
        User(string name, string pass)
        {
            username =name;
            password =pass;
        }
        string getUsername()
        {
            return username;
        }
        string getPassword()
        {
            return password;
        }
};
class UserManager{
    private:
        vector<User> users;
    public:
        void RegiserUser()
        {
            string username,password;
            cout<< "Enter the User Name";
            cin>>username;
            cout<<"Enter Password";
            cin>>password;

            User newUser(username,password);
            users.push_back(newUser);

            cout<<"\t\t User Register Successfully "<<endl;
        }
        bool loginUser(string name, string pass)
        {
            for(int i=0; i<users.size(); i++)
            {
                if (users[i].getUsername() == name && users[i].getPassword() == pass)
                {
                    cout<<"\t\t Login Sucessfull "<<endl;
                    return true;
                } 
            }
            cout<<"\t\t Invalid UserName or Password "<<endl;
            return false;
        }
        void ShowUser()
        {
            cout<<"\t\t  User List : "<<endl;
            for (int i=0; i<users.size(); i++)
            {
                cout<<"\t "<<users[i].getUsername()<<endl;
            }
        }
        void SearchUser(string username)
        {
            for(int i=0; i<users.size(); i++)
            {
               if(users[i].getUsername() == username)
               {
                cout<<"\t User Found. "<<endl;
               }
            }
        }
        void deleteUser(string username)
        {
            for(int i=0; i<users.size(); i++)
            {
                 if(users[i].getUsername() == username)
                {
                    users.erase(users.begin() +i);
                    cout<<"\t\t User Removed Sucessfully.  "<<endl;
                }
            }
            
        }
};
 main()
{
    UserManager usermanage;

    int op;
    char choise;
    do{
    system("cls");
    cout<<"\n\n\t\t1. Register User "<<endl;
    cout<<"\t\t2. Login "<<endl;
    cout<<"\t\t3. Show User List"<<endl;
    cout<<"\t\t4. Search User"<<endl;
    cout<<"\t\t5. Delete User"<<endl;
    cout<<"\t\t6. exit"<<endl;
    cout<<"\t\t Enter Your Choice : ";
    cin>>op;
    switch(op)
    {
        case 1:
        {
             usermanage.RegiserUser();
        break;

        }
        case 2:
        {
            string username,password;
            cout<<"\t Enter User Name: ";
            cin>>username;
            cout<<"\t Enter PAssword: ";
            cin>>password;
            usermanage.loginUser(username,password);
            break;
        }
        case 3:
        {
            usermanage.ShowUser();
            break;
        }
        case 4:
        {
            string username;
            cout<<"\t Enter USer Name: ";
            cin>>username;
            usermanage.SearchUser(username);
            break;
        }
        case 5:
        {
            string username;
           cout<<"\t Enter USer Name: ";
           cin>>username;
           usermanage.deleteUser(username);
           break;
        }
        case 6:
        {
            exit(1);
        }
       
    }
    cout<<"\t Do You Want to Continue [Yes/No]?";
    cin>>choise;
    } 
    while(choise =='y'|| choise == 'n');

}