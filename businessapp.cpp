#include<iostream>
#include<conio.h>
#include<windows.h>
using namespace std;
int salarycalculate(int employeeapply1);
void adminmainmenu();
void gotoxy(int x,int y);
void choices();
void printmenu();
void postajob();
void seealljobs();
void findjobname(string prefer1);
void findjoblocation(string prefer1);
void findjobposition(string prefer1);
void findjobtype(string prefer1);
void findjobsalary(int prefer2);
void printspecificjob(int employeeapply1);
void adminmainmenu();
void printyourjob();
string signin(string signup1,string signup2);
string validity1(string username);
string validity2(string password);
string validity3(string lusername);
string validity4(string lpassword);
string compare(string username,string password,string lusername,string lpassword,string login1,string login2);
int x,y;
int maxsize=10;
string employee[13];
string employer[8];
string companynames[11]={"Programmers","FZ-Studios","Miniclip","Gamezone","Youtube","Youtube","Miniclip","Youtube","RH-Creators"};
string companylocation[11]={"Lahore","Karachi","Lahore","Lahore","Multan","Lahore","Pindi","Quetta","Lahore"};
string jobtype[11]={"remote","onsite","remote","hybrid","remote","remote","onsite","hybrid","remote"};
string requiredposition[11]={"Web-Developer","Game-Developer","MERN-Developer","Web-Developer","Video-Editor","Video-Editor","Game-Designer","Graphic-Designer","Video-Editor"};
int salaryperhour[10]={1500,500,300,250,500,300,750,450,400};
int main()
{
    system("color 70");
    int choice;
    string edu,edu1,edu2,we,prefer,prefer1,employeeapply,employeecalculate,employeeapply2;
    string updation,overwrite;
    int salarychange,delindex,findindex,prefer2,employeeupdate,employeeapply1,employerupdate,salarypermonth;
    int choice1,choice2,choice3,choice4,choice5;
    string sign,signup1,signup2;
    string login,login1,login2;
    string check,status,logout="false";
    string username,password,lusername,lpassword;
    while(choice!=3)
    {
        while(check!="Login Successfully...")
        {
            Sleep(200);
            system("cls");
            printmenu();
            choices();
            x=67,y=20;
            gotoxy(x,y);
            cout<<"Enter your choice: ";
            cin>>choice;
            if(choice==1)
            {
                Sleep(100);
                system("cls");
                printmenu();
                x=30,y=12;
                gotoxy(x,y);
                cout<<"(Username will contain only alphabets and Password will contain only numbers)";
                x=58,y=16;
                gotoxy(x,y);
                cout<<"Enter your Username: ";
                cin>>username;
                gotoxy(x+35,y);
                signup1=validity1(username);
                cout<<"("<<signup1<<")";
                gotoxy(x+5,y+3);
                cout<<"Choose Password: ";
                cin>>password;
                signup2=validity2(password);
                gotoxy(x+45,y+3);
                cout<<"("<<signup2<<")";
                sign=signin(signup1,signup2);
                gotoxy(x+6,y+6);
                Sleep(100);
                cout<<sign;
            }
            else if(choice==2)
            {
                Sleep(100);
                system("cls");
                printmenu();
                x=30,y=12;
                gotoxy(x,y);
                cout<<"(Username will contain only alphabets and Password will contain only numbers)";
                x=58,y=16;
                gotoxy(x,y);
                cout<<"Enter your username to login: ";
                cin>>lusername;
                login1=validity3(lusername);
                gotoxy(x+45,y);
                cout<<"("<<login1<<")";
                gotoxy(x+3,y+3);
                cout<<"Enter your password: ";
                cin>>lpassword;
                login2=validity4(lpassword);
                gotoxy(x+45,y+3);
                cout<<"("<<login2<<")";
                if(lusername!="admin" && sign=="Account Created!")
                {
                    check=compare(username,password,lusername,lpassword,login1,login2);
                    gotoxy(x+4,y+7);
                    cout<<check;
                    Sleep(200);
                }
                else if(lusername=="admin")
                {
                    check=compare(username,password,lusername,lpassword,login1,login2);
                    gotoxy(x+4,y+7);
                    cout<<check;
                    Sleep(200);
                }
            }
            else if(choice!=3)
            {
                gotoxy(x+3,y+3);
                cout<<"Invalid Input!";
                Sleep(200);
            }
            else if(choice==3)
            {
                return 0;
            }
        }
        check=" ";
        if(lusername=="admin")
        {
            while(choice1!=5)
            {
                system("cls");
                printmenu();
                adminmainmenu();
                cout<<"Enter your choice: ";
                cin>>choice1;
                if(choice1==1)
                {
                    system("cls");
                    printmenu();
                    postajob();
                    cout<<"Press Any Key To Continue:";
                    getch();
                }        
                else if(choice1==2)
                {
                    system("cls");
                    printmenu();
                    seealljobs();
                    cout<<"Press Any Key To Continue:";
                    getch();
                }
                else if(choice1==3)
                {
                    system("cls");
                    printmenu();
                    seealljobs();
                    cout<<"Which one you want to update: ";
                    cin>>choice4;
                    cout<<"What you want to update: ";
                    cin>>updation;
                    if(updation=="salary-per-hour" || updation=="Salary-per-hour")
                    {
                        cout<<"New "<<updation<<": ";
                        cin>>salarychange;
                    }
                    else
                    {
                        cout<<"New "<<updation<<": ";
                        cin>>overwrite;
                    }
                    if(updation=="company's-name" || updation=="Company's-Name")
                    {
                        companynames[choice4-1]=overwrite;
                    }
                    else if(updation=="company's-location" || updation=="Company's-Location")
                    {
                        companylocation[choice4-1]=overwrite;
                    }
                    else if(updation=="job-type" || updation=="Job-Type")
                    {
                        jobtype[choice4-1]=overwrite;
                    }
                    else if(updation=="required-position" || updation=="Required-Position")
                    {
                        requiredposition[choice4-1]=overwrite;
                    }
                    else if(updation=="salary-per-hour" || updation=="Salary-per-hour")
                    {
                        salaryperhour[choice4-1]=salarychange;
                    }
                    cout<<"Press Any Key To Continue:";
                    getch();
                }
                else if(choice1==4)
                {
                    system("cls");
                    printmenu();
                    seealljobs();
                    cout<<"Which one you want to delete: ";
                    cin>>choice5;
                    delindex=choice5-1;
                    companynames[delindex]='\0';
                    companylocation[delindex]='\0';
                    requiredposition[delindex]='\0';
                    jobtype[delindex]='\0';
                    salaryperhour[delindex]='\0';
                    cout<<"Press Any Key To Continue:";
                    getch();
                }
                else if(choice1==5)
                {
                    logout="true";
                }
            }
        }
        else
        {
            system("cls");
            printmenu();
            cout<<"Are you an Employee OR Employer??: ";
            cin>>status;
            if(status=="Employee" || status=="employee")
            {
                system("cls");
                printmenu();
                cout<<"User Information:"<<endl;
                cout<<"Enter your name: ";
                cin>>employee[0];
                cout<<"Enter your age: ";
                cin>>employee[1];
                cout<<"Enter your city: ";
                cin>>employee[2];
                cout<<"Education:"<<endl;
                cout<<"Matric(yes/no): ";
                cin>>edu;
                if(edu=="yes")
                {
                    cout<<"Your School Name: ";
                    cin>>employee[3];
                    cout<<"Grade: ";
                    cin>>employee[4];
                    cout<<"Inter(yes/no): ";
                    cin>>edu1;
                    if(edu1=="yes")
                    {
                        cout<<"Your College Name: ";
                        cin>>employee[5];
                        cout<<"Grade: ";
                        cin>>employee[6];
                        cout<<"Bachelors(yes/no): ";
                        cin>>edu2;
                        if(edu2=="yes")
                        {
                            cout<<"Your University Name: ";
                            cin>>employee[7];
                            cout<<"CGPA: ";
                            cin>>employee[8];
                        }
                    }
                }
                cout<<"Do You Have Any Work Experience(yes/no): ";
                cin>>we;
                if(we=="yes")
                {
                    cout<<"Name of your Previous Company: ";
                    cin>>employee[9];
                    cout<<"Your position in that Company: ";
                    cin>>employee[10];
                    cout<<"For how long you were in that company: ";
                    cin>>employee[11];
                }
                while(choice2!=3)
                {
                    system("cls");
                    printmenu();
                    cout<<"Welcome, "<<employee[0]<<endl;
                    cout<<"1.Find a Job"<<endl;
                    cout<<"2.Update Your Profile"<<endl;
                    cout<<"3.Exit"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>choice2;
                    if(choice2==1)
                    {
                        system("cls");
                        printmenu();
                        cout<<"Preferences(Name/Location/Type/Position/Salary): ";
                        cin>>prefer;
                        if(prefer=="Name" || prefer=="name")
                        {
                            cout<<"Enter Company Name: ";
                            cin>>prefer1;
                            findjobname(prefer1);
                        }
                        else if(prefer=="Location" || prefer=="location")
                        {
                            cout<<"Enter Location: ";
                            cin>>prefer1;
                            findjoblocation(prefer1);
                        }
                        else if(prefer=="Type" || prefer=="type")
                        {
                            cout<<"Enter Job type(remote/hybrid/onsite): ";
                            cin>>prefer1;
                            findjobtype(prefer1);
                        }
                        else if(prefer=="Position" || prefer=="position")
                        {
                            cout<<"Enter Interested Position: ";
                            cin>>prefer1;
                            findjobposition(prefer1);
                        }
                        else if(prefer=="Salary" || prefer=="salary")
                        {
                            cout<<"Enter Preferred Salary Per Hour: ";
                            cin>>prefer2;
                            findjobsalary(prefer2);
                        }
                        else
                        {
                            cout<<"Invalid Input!";
                        }
                        cout<<"Do you want to apply?(yes/no): ";
                        cin>>employeeapply;
                        if(employeeapply=="yes")
                        {
                            cout<<"Enter in which you want to apply: ";
                            cin>>employeeapply1;
                            system("cls");
                            printmenu();
                            printspecificjob(employeeapply1);
                            cout<<"Calculate Monthly Salary(yes/no): ";
                            cin>>employeecalculate;
                            if(employeecalculate=="yes")
                            {
                                salarypermonth=salarycalculate(employeeapply1);
                                cout<<"Salary Per Month: Rs."<<salarypermonth<<endl;
                                cout<<"APPLY(yes/no)??:";
                                cin>>employeeapply2;
                                if(employeeapply2=="yes")
                                {
                                    cout<<"THANKS FOR APPLYING! YOUR APPLICATION HAS BEEN SENT."<<endl;
                                }
                            }
                        }
                        cout<<"Press Any Key to Continue:";
                        getch();
                    }
                    else if(choice2==2)
                    {
                        system("cls");
                        printmenu();
                        for(int i=0;i<12;i++)
                        {
                            cout<<i+1<<"."<<employee[i]<<endl;
                        }
                        cout<<"What you want to update: ";
                        cin>>employeeupdate;
                        cout<<"Press Any Key to Continue:";
                        getch();
                    }
                    else if(choice2==3)
                    {
                        logout="true";
                    }
                }
            }
            else if(status=="Employer" || status=="employer")
            {

                system("cls");
                printmenu();
                cout<<"User Information:"<<endl;
                cout<<"Enter your name: ";
                cin>>employer[0];
                cout<<"Enter your age: ";
                cin>>employer[1];
                cout<<"Enter your city: ";
                cin>>employer[2];
                cout<<"Company Information:"<<endl;
                cout<<"Enter your Company Name: ";
                cin>>employer[3];
                cout<<"Enter your Company Location: ";
                cin>>employer[4];
                cout<<"Company Experience: ";
                cin>>employer[5];
                cout<<"Enter Job types you're offering: ";
                cin>>employer[6];
                while(choice3!=3)
                {
                    system("cls");
                    printmenu();
                    cout<<"Welcome, "<<employer[0]<<endl;
                    cout<<"1.Post a Job"<<endl;
                    cout<<"2.Update Your Job"<<endl;
                    cout<<"3.Exit"<<endl;
                    cout<<"Enter your choice: ";
                    cin>>choice3;
                    if(choice3==1)
                    {
                        system("cls");
                        printmenu();
                        postajob();
                        cout<<"You Posted a Job!"<<endl;
                        cout<<"Press Any Key to Continue:";
                        getch();
                    }
                    else if(choice3==2)
                    {
                        system("cls");
                        printmenu();
                        printyourjob();
                        cout<<"\nWhat you want to update: ";
                        cin>>employerupdate;
                        cout<<"Press Any Key to Continue:";
                        getch();
                    }
                    else if(choice3==3)
                    {
                        logout="true";
                    }
                }
            } 
            else
            {
                cout<<"Invalid Input!";
            }
        }
    }
}

string signin(string signup1,string signup2)
{
    string output;
    if(signup1=="Valid Username!" && signup2=="Valid Password!")
    {
        output="Account Created!";
    }
    else
    {
        output="Invalid Credentials!";
    }
    return output;
}

string validity3(string lusername)
{
    string output;
    for(int i=0;lusername[i]!='\0';i++)
    {
        if(lusername[i]!='a' && lusername[i]!='b' && lusername[i]!='c' && lusername[i]!='d' && lusername[i]!='e' && lusername[i]!='f' && lusername[i]!='g' && lusername[i]!='h' && lusername[i]!='i' && lusername[i]!='j' && lusername[i]!='k' && lusername[i]!='l' && lusername[i]!='m' && lusername[i]!='n' && lusername[i]!='o' && lusername[i]!='p' && lusername[i]!='q' && lusername[i]!='r' && lusername[i]!='s' && lusername[i]!='t' && lusername[i]!='u' && lusername[i]!='v' && lusername[i]!='w' && lusername[i]!='x' && lusername[i]!='y' && lusername[i]!='z')
        {
            output="Invalid Username!";
        }
        else
        {
            output="Valid Username!";
        }
    }
    return output;
}

void printspecificjob(int employeeapply1)
{
    int index;
    index=employeeapply1-1;
    cout<<"Company Name: "<<companynames[index]<<"\nLocation: "<<companylocation[index]<<"\nRequired Position: "<<requiredposition[index]<<"\nJob Type: "<<jobtype[index]<<"\nSalary Per Hour: "<<salaryperhour[index];
    cout<<"\nDescription: "<<companynames[index]<<" is offering "<<jobtype[index]<<" Jobs. They are looking for a dedicated "<<requiredposition[index]<<" present in "<<companylocation[index]<<" or surroundings.\nThey are offering "<<salaryperhour[index]<<" Rs. base salary per hour."<<endl;
}

int salarycalculate(int employeeapply1)
{
    int salaryph=salaryperhour[employeeapply1];
    int salarypw=(salaryph*6)*6;
    int salarypy=salarypw*52;
    int salarypm=salarypy/12;
    return salarypm;

}

void seealljobs()
{
    cout<<"Company Name\t\tLocation      Required Position        Job Type         Salary Per Hour"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        cout<<i+1<<"."<<companynames[i]<<"\t\t"<<companylocation[i]<<"\t\t"<<requiredposition[i]<<"\t\t"<<jobtype[i]<<"\t\t"<<salaryperhour[i]<<endl;
    }
}

void printyourjob()
{
    cout<<"Company Name: "<<companynames[9]<<"\nLocation: "<<companylocation[9]<<"\nRequired Position: "<<requiredposition[9]<<"\nJob Type: "<<jobtype[9]<<"\nSalary Per Hour: "<<salaryperhour[9];
}

void postajob()
{
    cout<<"POST A NEW JOB:"<<endl;
    cout<<"Enter Company Name: ";
    cin>>companynames[9];
    cout<<"Company Location: ";
    cin>>companylocation[9];
    cout<<"Required Position: ";
    cin>>requiredposition[9];
    cout<<"Job Type: ";
    cin>>jobtype[9];
    cout<<"Salary Per Hour: ";
    cin>>salaryperhour[9];
}

void findjobname(string prefer1)
{
    bool checking=false;
    int order=1;
    cout<<"Company Name\t\tLocation      Required Position        Job Type         Salary Per Hour"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        if(prefer1==companynames[i])
        {
            checking=true;
            cout<<order<<"."<<companynames[i]<<"\t\t"<<companylocation[i]<<"\t\t"<<requiredposition[i]<<"\t\t"<<jobtype[i]<<"\t\t"<<salaryperhour[i]<<endl;
            order++;
        }
    }
    if(checking=false)
    {
        cout<<"NONE\t\t     NONE            NONE                  NONE                 NONE"<<endl;
    }
}

void findjoblocation(string prefer1)
{
    bool checking=false;
    int order=1;
    cout<<"Company Name\t\tLocation      Required Position        Job Type         Salary Per Hour"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        if(prefer1==companylocation[i])
        {
            checking=true;
            cout<<order<<"."<<companynames[i]<<"\t\t"<<companylocation[i]<<"\t\t"<<requiredposition[i]<<"\t\t"<<jobtype[i]<<"\t\t"<<salaryperhour[i]<<endl;
            order++;
        }
    }
    if(checking=false)
    {
        cout<<"NONE\t\t     NONE            NONE                  NONE                 NONE"<<endl;
    }
}

void findjobposition(string prefer1)
{
    bool checking=false;
    int order=1;
    cout<<"Company Name\t\tLocation      Required Position        Job Type         Salary Per Hour"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        if(prefer1==requiredposition[i])
        {
            checking=true;
            cout<<order<<"."<<companynames[i]<<"\t\t"<<companylocation[i]<<"\t\t"<<requiredposition[i]<<"\t\t"<<jobtype[i]<<"\t\t"<<salaryperhour[i]<<endl;
            order++;
        }
    }
    if(checking=false)
    {
        cout<<"NONE\t\t     NONE            NONE                  NONE                 NONE"<<endl;
    }
}

void findjobtype(string prefer1)
{
    bool checking=false;
    int order=1;
    cout<<"Company Name\t\tLocation      Required Position        Job Type         Salary Per Hour"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        if(prefer1==jobtype[i])
        {
            checking=true;
            cout<<order<<"."<<companynames[i]<<"\t\t"<<companylocation[i]<<"\t\t"<<requiredposition[i]<<"\t\t"<<jobtype[i]<<"\t\t"<<salaryperhour[i]<<endl;
            order++;
        }
    }
    if(checking=false)
    {
        cout<<"NONE\t\t     NONE            NONE                  NONE                 NONE"<<endl;
    }
}

void findjobsalary(int prefer2)
{
    bool checking=false;
    int order=1;
    cout<<"Company Name\t\tLocation      Required Position        Job Type         Salary Per Hour"<<endl;
    for(int i=0;i<maxsize;i++)
    {
        if(prefer2==salaryperhour[i])
        {
            checking=true;
            cout<<order<<"."<<companynames[i]<<"\t\t"<<companylocation[i]<<"\t\t"<<requiredposition[i]<<"\t\t"<<jobtype[i]<<"\t\t"<<salaryperhour[i]<<endl;
            order++;
        }
    }
    if(checking=false)
    {
        cout<<"NONE\t\t     NONE            NONE                  NONE                 NONE"<<endl;
    }
}

string validity1(string username)
{
    string output;
    for(int i=0;username[i]!='\0';i++)
    {
        if(username[i]!='a' && username[i]!='b' && username[i]!='c' && username[i]!='d' && username[i]!='e' && username[i]!='f' && username[i]!='g' && username[i]!='h' && username[i]!='i' && username[i]!='j' && username[i]!='k' && username[i]!='l' && username[i]!='m' && username[i]!='n' && username[i]!='o' && username[i]!='p' && username[i]!='q' && username[i]!='r' && username[i]!='s' && username[i]!='t' && username[i]!='u' && username[i]!='v' && username[i]!='w' && username[i]!='x' && username[i]!='y' && username[i]!='z')
        {
            output="Invalid Username!";
        }
        else
        {
            output="Valid Username!";
        }
    }
    return output;
}

string validity4(string lpassword)
{
    string output;
    for(int i=0;lpassword[i]!='\0';i++)
    {
        if(lpassword[i]!='0' && lpassword[i]!='1' && lpassword[i]!='2' && lpassword[i]!='3' && lpassword[i]!='4' && lpassword[i]!='5' && lpassword[i]!='6' && lpassword[i]!='7' && lpassword[i]!='8' && lpassword[i]!='9')
        {
            output="Invalid Password!";
        }
        else
        {
            output="Valid Password!";
        }
    }
    return output;
}


string validity2(string password)
{
    string output;
    for(int i=0;password[i]!='\0';i++)
    {
        if(password[i]!='0' && password[i]!='1' && password[i]!='2' && password[i]!='3' && password[i]!='4' && password[i]!='5' && password[i]!='6' && password[i]!='7' && password[i]!='8' && password[i]!='9')
        {
            output="Invalid Password!";
        }
        else
        {
            output="Valid Password!";
        }
    }
    return output;
}

void adminmainmenu()
{
   system("cls");
   printmenu();
   cout<<"Welcome, Admin!"<<endl;
   cout<<"1.Post a Job"<<endl;
   cout<<"2.See all Jobs"<<endl;
   cout<<"3.Update a Job"<<endl;
   cout<<"4.Delete a Job"<<endl;
   cout<<"5.Exit"<<endl;
}

string compare(string username,string password,string lusername,string lpassword,string login1,string login2)
{
    string output;
    if((lusername==username && lpassword==password)||(lusername=="admin" && lpassword=="123")&&(login1=="Valid Username!" && login2=="Valid Password!"))
    {
        output="Login Successfully...";
    }
    else
    {
        output="Invalid Credentials!";  
    }
    return output;
}

void gotoxy(int x,int y)
{
   COORD coordinates;
   coordinates.X=x;
   coordinates.Y=y;
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coordinates);
}



void choices()
{
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                                                                       1.SIGN UP                                                          "<<endl;
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                                                                        2.LOGIN                                                           "<<endl;
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                                                                         3.EXIT                                                           "<<endl; 
}

void printmenu()
{
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                                                                                                                                          "<<endl;
    cout<<"                ************************************************************************************************************************* "<<endl;
    cout<<"                **  ######   #####   ######  ####### ####### ######      ######  #####  ###     ## ###     ## #######  ###### ######## ** "<<endl;                                                                                             
    cout<<"                ** ##       ##   ##  ##   ## ##      ##      ##   ##    ##      ##   ## ####    ## ####    ## ##      ##         ##    ** "<<endl;
    cout<<"                ** ##       ##   ##  ##   ## ##      ##      ##   ##    ##      ##   ## ## ##   ## ## ##   ## ##      ##         ##    ** "<<endl;
    cout<<"                ** ##       #######  ######  #####   #####   ######     ##      ##   ## ##  ##  ## ##  ##  ## #####   ##         ##    ** "<<endl;
    cout<<"                ** ##       ##   ##  ## ##   ##      ##      ## ##      ##      ##   ## ##   ## ## ##   ## ## ##      ##         ##    ** "<<endl;
    cout<<"                ** ##       ##   ##  ##  ##  ##      ##      ##  ##     ##      ##   ## ##    #### ##    #### ##      ##         ##    ** "<<endl;
    cout<<"                **  ######  ##   ##  ##   ## ####### ####### ##   ##     ######  #####  ##     ### ##     ### #######  ######    ##    ** "<<endl;
    cout<<"                ************************************************************************************************************************* "<<endl;
}

