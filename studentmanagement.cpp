#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
class management
{
    int id;
    int r_no;
    char name[20];
    int ds,dbms,maths,dsa;//subjects
    int tm;//total marks
    char grade;
    float per;
public:
    void enter();
    void s_earch(int rl);
    void calcu();
    void disp()
    {
        cout<<setw(2)<<id<<setw(10)<<r_no<<setw(23)<<name<<setw(10)<<ds<<setw(10)<<dbms<<setw(8)<<maths<<setw(9)<<dsa<<setw(10)<<tm<<setw(13)<<grade;
        cout<<"\n";
    }
    int getroll_no()
    {
        return r_no;
    }
    void d_elete();
    void update(int r);
}m;
void management::enter()
{
    cout<<" ENTER ID OF STUDENT";
    cin>>id;
    cout<<" ENTER ROLL NO OF STUDENT";
    cin>>r_no;
    fflush(stdin);
    cout<<" ENTER NAME OF STUDENT";
    gets(name);
    cout<<" ENTER MARKS OF STUDENT";
    cout<<"\n ENTER MARKS OF DISCRETE STRUCTURE";
    cin>>ds;
    cout<<" ENTER MARKS OF DBMS";
    cin>>dbms;
    cout<<" ENTER MARKS OF MATHEMATICS";
    cin>>maths;
    cout<<" ENTER MARKS OF DATA STRUCTURES AND ALGORITHMS";
    cin>>dsa;
    calcu();
}
void management::d_elete()
{
    fstream file,file1;
    file.open("management.dat",ios::in);
    file1.open("temp.dat",ios::out);
    int roll,flag=0;
    cout<<"\n ENTER THE ROLL.NO WHOSE RECORD IS TO BE DELETED";
    cin>>roll;
    while(file.read((char*)&m,sizeof(m)))
    {
        if(roll!=m.getroll_no())
        {
            file1.write((char*)&m,sizeof(m));
            flag=1;
        }
    }
    if(flag==0)
    {
        cout<<"\n RECORD NOT FOUND";
    }
    file.close();
    file1.close();
    remove("management.dat");
    rename("temp.dat","management.dat");
}
void management::calcu()
{
    tm=ds+dbms+maths+dsa;
    per=(tm/4.0);
    if(per>85)
    {
        grade='A';
    }
    else if(per>60)
    {
        grade='B';
    }
    else if(per>40)
    {
        grade='C';
    }
    else
    {
        grade='D';
    }

}
void display()
{
    fstream file;
    cout<<"\n...ID...|...ROLL NO...|.......NAME.......|..DS..|..DBMS..|..MATHS..|..DSA..|..TOTAL MARKS..|..GRADE..|\n";
    cout<<"\n--------|-------------|------------------|------|--------|---------|-------|---------------|---------|\n";
    file.open("management.dat",ios::in);
    while(file.read((char*)&m,sizeof(m)))
    {
       m.disp();
    }
    file.close();
}
void s_earch(int rl)
{
    fstream file;
    file.open("management.dat",ios::in);
    int flag=0;
    while(file.read((char*)&m,sizeof(m)))
    {
        if(rl==m.getroll_no())
        {
             cout<<"\n...ID...|...ROLL NO...|.......NAME.......|..DS..|..DBMS..|..MATHS..|..DSA..|..TOTAL MARKS..|..GRADE..|\n";
             cout<<"\n--------|-------------|------------------|------|--------|---------|-------|---------------|---------|\n";
             m.disp();
             flag=1;
             break;
        }
    }
    if(flag==0)
        cout<<"\n RECORD FOR THE GIVEN ROLL.NO NOT FOUND";
    file.close();
}
void update(int r)
{
    fstream file;
    file.open("management.dat",ios::in|ios::out);
    long pos=file.tellg();
    while(file.read((char*)&m,sizeof(m)))
    {
        if(r==m.getroll_no())
        {
            cout<<"\n...ID...|...ROLL NO...|.......NAME.......|..DS..|..DBMS..|..MATHS..|..DSA..|..TOTAL MARKS..|..GRADE..|\n";
            cout<<"\n--------|-------------|------------------|------|--------|---------|-------|---------------|---------|\n";
            m.disp();
            m.enter();
            file.seekg(pos,ios::beg);
            file.write((char*)&m,sizeof(m));
            break;
        }
        pos=file.tellg();
    }
  file.close();
}
void getdata()
{
    fstream file;
    file.open("management.dat",ios::app);
    int ans=0;
    while(ans==0)
    {
        m.enter();
        file.write((char*)&m,sizeof(m));
        cout<<" DO YOU WANT TO ENTER MORE RECORDS PRESS(0/1)";
        cin>>ans;
    }
    file.close();
}
main()
{
    int rl,r,opn;
    cout<<"\n..............................................LAKSHMI NARAYAN COLLEGE OF TECHNOLOGY...................................................";
    cout<<"\n                                                   STUDENT RECORD MANAGEMENT                                                         ";
    do
    {
        cout<<"\n PRESS";
        cout<<"\n 1.ENTER RECORDS OF STUDENT";
        cout<<"\n 2.DISPLAY THE RECORDS";
        cout<<"\n 3.SEARCH A RECORD";
        cout<<"\n 4.UPDATE THE GIVEN RECORD";
        cout<<"\n 5.DELETE THE GIVEN RECORD";
        cout<<"\n 6.EXIT";
        cout<<"\n ENTER YOUR OPTION";
        cin>>opn;
        switch(opn)
        {
        case 1:
            getdata();
            break;
        case 2:
            display();
            break;
        case 3:
            cout<<"\n ENTER THE ROLL NO TO BE SEARCHED";
            cin>>rl;
            s_earch(rl);
            break;
        case 4:
            cout<<"\n ENTER THE ROLL.NO WHOSE RECORDS ARE TO BE UPDATED";
            cin>>r;
            update(r);
            break;
        case 5:
            m.d_elete();
            break;
        case 6:
            exit;
        }
    }while(opn!=6);
}
