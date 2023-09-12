#include<iostream>
#include<math.h>
using namespace std;
add()
{
    int a[10],n,i,sum=0;
    cout<<"\n ENTER TOTAL NO OF DIGITS TO BE ADDED";
    cin>>n;
    cout<<"\n ENTER THE DIGITS \n";
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(i=0;i<n;i++)
    {
        sum=sum+a[i];
    }
    cout<<"...............";
    cout<<"\n SUM = "<<sum;
}
sub()
{
    int n,i,b[10];
    cout<<"\n ENTER THE NO OF DIGITS TO BE SUBTRACTED";
     cin>>n;
    cout<<"\n ENTER THE DIGITS \n";
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    int ans=b[0];
    for(i=1;i<n;i++)
    {
        ans=ans-b[i];
    }
    cout<<"......................";
    cout<<"\n SUBTRACTION = "<<ans;
}
mullti()
{
    int n,i,b[10];
    float mull=1;
    cout<<"\n ENTER THE NO DIGITS TO BE MULTIPLIED";
     cin>>n;
    cout<<"\n ENTER THE DIGITS \n";
    for(i=0;i<n;i++)
    {
        cin>>b[i];
    }
    for(i=0;i<n;i++)
    {
        mull=mull*b[i];
    }
    cout<<"..........................";
    cout<<"\n MULTIPLICATION = "<<mull;
}
division()
{
    float num,den,div;
    cout<<"\n ENTER THE VALUE OF NUMERATOR";
    cin>>num;
    cout<<"\n ENTER THE VALUE OF DENOMINATOR";
    cin>>den;
    if(den==0)
    {
        cout<<"\n DENOMINATOR CAN'T BE ZERO";
        cout<<"\n CAN'T DIVIDE BY ZERO \n";
    }
    else
    {
        div=num/den;
        cout<<"..................";
        cout<<"\n DIVISION ="<<div;
    }
}
factorial()
{
    int i,n,fac=1;
    cout<<"\n ENTER THE NO";
    cin>>n;
    for(i=1;i<=n;i++)
    {
        fac=fac*i;
    }
    cout<<"....................";
    cout<<"\n FACTORIAL = "<<fac;
}
pow()
{
    int x,y;
    cout<<"\n ENTER THE BASE VALUE";
    cin>>x;
    cout<<"\n ENTER THE EXPONENT VALUE";
    cin>>y;
    int p = pow(x,y);
    cout<<"............................";
    cout<<"\n  EXPONENTIAL VALUE = "<<p;
}
percent()
{
  float n,t;
  float per;
  cout<<"\n ENTER THE NO OF PARTS"; //NO OF DIVISIONS
  cin>>n;
  cout<<"\n ENTER TOTAL NO OF PARTS";//TOTAL PART
  cin>>t;
  per=(n/t)*100;
  cout<<"............................";
  cout<<"\n PERCENTAGE  = "<<per<<"%";
}
sqroot()
{
    int n;
    cout<<"\n ENTER THE NO";
    cin>>n;
    float sq=sqrt(n);
    cout<<".....................";
    cout<<"\n SQUARE ROOT = "<<sq;
}
curoot()
{
    int n;
    float c;
    cout<<"\n ENTER THE NO";
    cin>>n;
    c=cbrt(n);
    cout<<"............................";
    cout<<"\n CUBE ROOT  = "<<c;
}
co_s()
{
    float n,x;
    cout<<"\n ENTER VALUE OF X";
    cin>>x;
    n=cos(x);
    cout<<"\n............................";
    cout<<"\nCOSx"<<" "<<n;
}
si_n()
{
    float n,x;
    cout<<"\n ENTER VALUE OF X";
    cin>>x;
    n=sin(x);
    cout<<"\n............................";
    cout<<"\nSINx"<<" "<<n;
}
ta_n()
{
    float n,x;
    cout<<"\n ENTER VALUE OF X";
    cin>>x;
    n=tan(x);
    cout<<"\n............................";
    cout<<"\n TANx"<<" "<<n;
}
trigno()
{
    int opn;
    do
    {
     cout<<"\n \n PRESS.";
     cout<<"\n 1. SQUARE ROOT";
     cout<<"\n 2. CUBE ROOT";
     cout<<"\n 3. COS x";
     cout<<"\n 4. SIN x";
     cout<<"\n 5. TAN x";
     cout<<"\n 6. EXIT";
     cout<<"\n ENTER YOUR CHOICE";
     cin>>opn;
     switch(opn)
     {
     case 1:
        sqroot();
        break;
     case 2:
        curoot();
        break;
     case 3:
        co_s();
        break;
     case 4:
        si_n();
        break;
     case 5:
        ta_n();
        break;
     case 6:
        exit;
     }
    }while(opn!=6);
}
main()
{
    int opn;
    cout<<"--------------------------";
    cout<<"\n DIGITAL CALCULATOR   \n";
    cout<<"--------------------------";
    cout<<"\n OPERATIONS PERFORMED ";
    do
    {
        cout<<"\n \n 1.ADDITION";
        cout<<"\n 2.SUBTRACTION";
        cout<<"\n 3.MULTIPLICATION";
        cout<<"\n 4.DIVISION";
        cout<<"\n 5.FACTORIAL";
        cout<<"\n 6.TRIGNOMETRIC FUNCTIONS";
        cout<<"\n 7.EXPONENT";
        cout<<"\n 8.PERCENTAGE";
        cout<<"\n 9.EXIT ";
        cout<<"\n PRESS";
        cout<<"\n ENTER YOUR CHOICE";
        cin>>opn;
        switch(opn)
        {
        case 1:
            add();
            break;
        case 2:
            sub();
            break;
        case 3:
            mullti();
            break;
        case 4:
            division();
            break;
        case 5:
            factorial();
            break;
        case 6:
            trigno();
            break;
        case 7:
              pow();
            break;
        case 8:
             percent();
            break;
        case 9:
             exit;
        default:
            cout<<"\n INVALID CHOICE";
        }
    }while(opn!=9);
}
