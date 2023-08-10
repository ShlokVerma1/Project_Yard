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
            cout<< "Enter the User Name: ";
            cin>>username;
            cout<<"Enter Password: ";
            cin>>password;

            User newUser(username,password);
            users.push_back(newUser);

            cout<<"   User Register Successfully  "<<endl;
        }
        bool loginUser(string name, string pass)
        {
            for(int i=0; i<users.size(); i++)
            {
                if (users[i].getUsername() == name && users[i].getPassword() == pass)
                {
                    cout<<"   Login Sucessfull "<<endl;
                    return true;
                } 
            }
            cout<<"  Invalid UserName or Password "<<endl;
            return false;
        }
        void ShowUser()
        {
            cout<<"    User List : "<<endl;
            for (int i=0; i<users.size(); i++)
            {
                cout<<"  "<<users[i].getUsername()<<endl;
            }
        }
        void SearchUser(string username)
        {
            for(int i=0; i<users.size(); i++)
            {
               if(users[i].getUsername() == username)
               {
                cout<<"  User Found. "<<endl;
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
                    cout<<"   User Removed Sucessfully.  "<<endl;
                }
            }
            
        }
};
 main()
{
    UserManager usermanage;

    int op;
    char Select;
    do{
    system("cls");
    cout<<"\n\n  1. Register User "<<endl;
    cout<<"  2. Login "<<endl;
    cout<<"  3. Show User List"<<endl;
    cout<<"  4. Search User"<<endl;
    cout<<"  5. Delete User"<<endl;
    cout<<"  6. exit"<<endl;
    cout<<"   Enter Your Selection : ";
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
            cout<<"  Enter User Name: ";
            cin>>username;
            cout<<"  Enter PAssword: ";
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
            cout<<"  Enter User Name: ";
            cin>>username;
            usermanage.SearchUser(username);
            break;
        }
        case 5:
        {
            string username;
           cout<<"  Enter USer Name: ";
           cin>>username;
           usermanage.deleteUser(username);
           break;
        }
        case 6:
        {
            exit(1);
        }
       
    }
    cout<<"  Do You Want to Continue [Yes/No]?";
    cin>>Select;
    } 
    while(Select =='y'|| Select == 'n');

}
