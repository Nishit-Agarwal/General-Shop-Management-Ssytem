#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
#include<iostream>

using namespace std;

struct pd
{char pnm[15];
 float prc;
 char com[15];
 long int pn;
};


void add()
{ofstream A("prd.dat",ios::binary|ios::app);
 pd e;
 int n,i;
 cout<<"\n Enter number of products to be entered "<<endl;
 cin>>n;

 for(i=1;i<=n;i++)
 {cout<<"\n Enter product name, price, company and no of items "<<endl;
  gets(e.pnm);
  cin>>e.prc;
  gets(e.com);
  cin>>e.pn;
  A.write((char*)&e,sizeof(e));
 }
 A.close();
}


void modpnm()
{fstream a("prd.dat",ios::binary|ios::in|ios::out);
 int z=0;
 pd e;
 char nm[15];
 cout<<"\n Enter the product name you want to modify ";
 gets(nm);
 a.read((char *)&e,sizeof(e));
 while(!a.eof())
 {if(strcmpi(e.pnm,nm)==0)
    {cout<<"\n Enter the new product name ";
     gets(e.pnm);
     int t=a.tellg();
     a.seekp(t-sizeof(e));
     a.write((char *)&e,sizeof(e));
     z++;
    }
  a.read((char *)&e,sizeof(e));
 }
 a.close();
if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No product name found "<<nm;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++";
    }
}


void modprc()
{fstream a("prd.dat",ios::binary|ios::in|ios::out);
 int z=0;
 pd e;
 char nm[15];
 cout<<"\n Enter the product name you want to modify ";
 gets(nm);
 a.read((char *)&e,sizeof(e));
 while(!a.eof())
 {if(strcmpi(e.pnm,nm)==0)
    {cout<<"\n Enter the new price of product ";
     cin>>e.prc;
     int t=a.tellg();
     a.seekp(t-sizeof(e));
     a.write((char *)&e,sizeof(e));
     z++;
    }
  a.read((char *)&e,sizeof(e));
 }
 a.close();
if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No product name found "<<nm;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++";
    }
}


void modpn()
{fstream a("prd.dat",ios::binary|ios::in|ios::out);
 int z=0;
 pd e;
 char nm[15];
 cout<<"\n Enter the product name you want to modify ";
 gets(nm);
 a.read((char *)&e,sizeof(e));
 while(!a.eof())
 {if(strcmpi(e.pnm,nm)==0)
    {cout<<"\n Enter the new no of items in stock ";
     cin>>e.pn;
     int t=a.tellg();
     a.seekp(t-sizeof(e));
     a.write((char *)&e,sizeof(e));
     z++;
    }
  a.read((char *)&e,sizeof(e));
 }
 a.close();
if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No product name found "<<nm;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++"<<endl;
    }
}


void modcom()
{fstream a("prd.dat",ios::binary|ios::in|ios::out);
 int z=0;
 pd e;
 char nm[15];
 cout<<"\n Enter the product name you want to modify "<<endl;
 gets(nm);
 a.read((char *)&e,sizeof(e));
 while(!a.eof())
 {if(strcmpi(e.pnm,nm)==0)
    {cout<<"\n Enter the new company of product "<<endl;
     gets(e.com);
     int t=a.tellg();
     a.seekp(t-sizeof(e));
     a.write((char *)&e,sizeof(e));
     z++;
    }
  a.read((char *)&e,sizeof(e));
 }
 a.close();
if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No product name found "<<nm;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++"<<endl;
    }
}


void mod()
{fstream a("prd.dat",ios::binary|ios::in|ios::out);
 int z=0;
 pd e;
 char nm[15];
 cout<<"\n Enter the product name you want to modify "<<endl;
 gets(nm);
 a.read((char *)&e,sizeof(e));
 while(!a.eof())
 {if(strcmpi(e.pnm,nm)==0)
    {cout<<"\n Enter the new product name, price, company and no. of items in stock "<<endl;
     gets(e.pnm);
     cin>>e.prc;
     gets(e.com);
     cin>>e.pn;
     int t=a.tellg();
     a.seekp(t-sizeof(e));
     a.write((char *)&e,sizeof(e));
     z++;
    }
  a.read((char *)&e,sizeof(e));
 }
 a.close();
if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No product name found "<<nm;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++"<<endl;
    }
}


void del()
{char a[15];
 pd e;
 ifstream A("prd.dat",ios::binary);
 ofstream B("tmp.dat",ios::binary);
 cout<<"\n Enter the Product name to be deleted ";
 gets(a);
 while(!A.eof())
 {A.read((char *)&e,sizeof(e));
  if(strcmpi(a,e.pnm)!=0)
  {B.write((char *)&e,sizeof(e));
  }
 }
 A.close();
 B.close();
 remove("prd.dat");
 rename("tmp.dat","prd.dat");
 getch();
}


void spnm()
{char ch;
 int z=0;
 ch='y';
 while(ch=='y'||ch=='Y')
 {
 cout<<"\n______________________________________________________________________________";
 cout<<"\n****************************** Searching is done *****************************";
 cout<<"\n------------------------------------------------------------------------------";
 ifstream A("prd.dat",ios::binary);
 pd e;
 char n[15];
 cout<<"\n Enter the name of the product to be search "<<endl;
 gets(n);
 A.read((char *)&e,sizeof(e));
 while(!A.eof())
 {if(strcmpi(n,e.pnm)==0)
  {cout<<"\n Price of product is "<<e.prc<<endl;
   cout<<"\n Company of product is "<<e.com<<endl;
   cout<<"\n No. of items in stock is "<<e.pn<<endl<<endl;
   z++;
  }
  A.read((char *)&e,sizeof(e));
 }
 A.close();
 if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No product name found "<<n;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++";
    }
 cout<<"\n==============================";
 cout<<"\n You want to search again Y/N ";
 cout<<"\n++++++++++++++++++++++++++++++"<<endl;
 cin>>ch;
 }
}


void spcom()
{char ch;
 int z=0;
 ch='y';
 while(ch=='y'||ch=='Y')
 {
 cout<<"\n______________________________________________________________________________";
 cout<<"\n****************************** Searching is done *****************************";
 cout<<"\n------------------------------------------------------------------------------";
 ifstream A("prd.dat",ios::binary);
 pd e;
 char n[15];
 cout<<"\n Enter the company to be search "<<endl;
 gets(n);
 A.read((char *)&e,sizeof(e));
 while(!A.eof())
 {if(strcmpi(n,e.com)==0)
  {cout<<"\n Name of product is "<<e.pnm<<endl;
   cout<<"\n Price of product is "<<e.prc<<endl;
   cout<<"\n No. of items in stock is "<<e.pn<<endl<<endl;
   z++;
  }
  A.read((char *)&e,sizeof(e));
 }
 A.close();
 if(z==0)
    {cout<<"\n================================";
     cout<<"\n No company found "<<n;
     cout<<"\n++++++++++++++++++++++++++++++++";
    }
 cout<<"\n==============================";
 cout<<"\n You want to search again Y/N ";
 cout<<"\n++++++++++++++++++++++++++++++"<<endl;
 cin>>ch;
 }
}

void spprc()
{char ch;
 ch='y';
 while(ch=='y'||ch=='Y')
 {
  cout<<"\n______________________________________________________________________________";
  cout<<"\n****************************** Searching is done *****************************";
  cout<<"\n------------------------------------------------------------------------------";
  ifstream A("prd.dat",ios::binary);
  pd e;
  int b=0,l=0,z=0;
  cout<<"\n Enter the range of the price of the product to be searched "<<endl;
  cin>>b>>l;
  A.read((char *)&e,sizeof(e));
  while(!A.eof())
  {if(e.prc>=b&&e.prc<=l)
     {cout<<"\n Name of product is "<<e.pnm<<endl;
      cout<<"\n Price of product is "<<e.prc<<endl;
      cout<<"\n No. of items in stock is "<<e.pn<<endl;
      cout<<"\n Name of company is "<<e.com<<endl<<endl;
      z++;
     }
   A.read((char *)&e,sizeof(e));
  }
  A.close();
  if(z==0)
    {cout<<"\n=======================================";
     cout<<"\n No item found between the range "<<b<<" and "<<l;
     cout<<"\n+++++++++++++++++++++++++++++++++++++++";
    }
 cout<<"\n==============================";
 cout<<"\n You want to search again Y/N ";
 cout<<"\n++++++++++++++++++++++++++++++"<<endl;
 cin>>ch;
 }
}


void fpd()
{int t=0;
 ifstream A("prd.dat",ios::binary);
 pd e;
 A.read((char *)&e,sizeof(e));
 while(!A.eof())
 {if(e.pn<=10)
  {cout<<"\n Name of product is "<<e.pnm<<endl;
   cout<<"\n Price of product is "<<e.prc<<endl;
   cout<<"\n Company of product is "<<e.com<<endl;
   cout<<"\n No. of items in stock is "<<e.pn<<endl;
   t++;
  }
  A.read((char *)&e,sizeof(e));
 }
 A.close();
 if(t==0)
 {cout<<"\n========================================================";
  cout<<"\n No Product found having stock less than or equal to 10 ";
  cout<<"\n++++++++++++++++++++++++++++++++++++++++++++++++++++++++";
 }
getch();
}


void bill()
{char chr[15],i='y',k='y';
 float tprc=0;
 int amt,h=0;
 fstream A("prd.dat",ios::binary|ios::in|ios::out);
 pd e,t[50];
 while(i=='y'||i=='Y')
 {
   cout<<"\n______________________________________________________________________________";
   cout<<"\n*************************** Bill of purchased items **************************";
   cout<<"\n------------------------------------------------------------------------------";
   cout<<"\n\n Enter the product name and quantity you want to buy ";
   cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
   gets(chr);
   cin>>amt;
   A.read((char *)&e,sizeof(e));
   while(!A.eof())
   {if(strcmpi(chr,e.pnm)==0)
      {cout<<"\n Product name "<<e.pnm;
       cout<<"\n Product price "<<e.prc;
       cout<<"\n Product Company "<<e.com;
       xyz:
       if(amt<=e.pn)
	{cout<<"\n You want to buy this item Y/N ";
	 cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	 cin>>k;
	  if(k=='y'||k=='Y')
	    {tprc=tprc+(e.prc*amt);
	     strcpy(t[h].pnm,e.pnm);
	     t[h].prc=e.prc;
	     strcpy(t[h].com,e.com);
	     t[h].pn=amt;
	     h++;
	     e.pn=e.pn-amt;
	     int w=A.tellg();
	     A.seekp(w-sizeof(e));
	     A.write((char *)&e,sizeof(e));
	    }
	}
	else
	{cout<<"\n\n=================================";
	 cout<<"\n Out of stock !!!!!!! ";
	 cout<<"\n items available are "<<e.pn;
	 cout<<"\n want to buy "<<e.pn<<" items";
	 cout<<"\n+++++++++++++++++++++++++++++++";
	 amt=e.pn;
	 goto xyz;
	}
      }
    A.read((char *)&e,sizeof(e));
   }
  A.close();
  cout<<"\n Want to buy more items Y/N ";
  cout<<"\n^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
  cin>>i;
 }

 cout<<"\n______________________________________________________________________________";
 cout<<"\n****************************** Your bill is **********************************";
 cout<<"\n------------------------------------------------------------------------------";
 cout<<"\n\n     Product name  ::  Company  ::  Price  ::  No. of items ";
 for(int r=0;r<h;r++)
 {cout<<"\n"<<r+1<<".   "<<t[r].pnm<<"          "<<t[r].com<<"      "<<t[r].prc<<"          "<<t[r].pn;
 }
 cout<<"\n\n========================";
 cout<<"\n TOTAL PRICE IS "<<tprc;
 cout<<"\n++++++++++++++++++++++++";
 getch();
}


int main()
{
 char nm[15],pw[15];
 cout<<"##############################################################################";
 cout<<"\n##############################################################################";
 cout<<"\n\n  Enter User name : ";
 gets(nm);
 cout<<"\n  Enter password : ";
 gets(pw);
 if(strcmpi(nm,"nishit")==0 && strcmpi(pw,"agarwal")==0)
   {
    cout<<"\n  Right Enries press any key to continue....... ";
    getch();
    int n;
    pd e;
    while(n!=7)
     {

      cout<<"\n******************************************************************************";
      cout<<"\n************************** WELCOME TO GENERAL STORE **************************";
      cout<<"\n******************************************************************************";
      cout<<"\n\n  MAIN MENU"<<endl;
      cout<<"1.Add a Product"<<endl;
      cout<<"2.Modify a Product"<<endl;
      cout<<"3.Delete a Product"<<endl;
      cout<<"4.Search a Product "<<endl;
      cout<<"5.Finishing products "<<endl;
      cout<<"6.Make a Bill "<<endl;
      cout<<"7.Close a program"<<endl;
      cout<<"\n\n\n\n\n\n\n";
      cout<<"\n                                             --Made by NISHIT AGARWAL";
      cout<<"\n                                                          XII - A";
      cout<<"\n                                                             18"<<endl;
      cin>>n;

      switch(n)
	{case 1:
		 cout<<"\n______________________________________________________________________________";
		 cout<<"\n***************************** Adding a new item ******************************";
		 cout<<"\n------------------------------------------------------------------------------";
		 add();
		 break;
	 case 2:
		 int n;
		 cout<<"\n_____________________________________________________________________________";
		 cout<<"\n************* Enter the type of the modification you want to do *************";
		 cout<<"\n-----------------------------------------------------------------------------";
		 cout<<"\n\n 1.Product name ";
		 cout<<"\n 2.Product price ";
		 cout<<"\n 3.No. of items in stock ";
		 cout<<"\n 4.Company of product ";
		 cout<<"\n 5.Whole record "<<endl;
		 cin>>n;
		 switch(n)
		 {case 1:
			 modpnm();
			 break;
		  case 2:
			 modprc();
			 break;
		  case 3:
			 modpn();
			 break;
		  case 4:
			 modcom();
			 break;
		  case 5:
			 mod();
			 break;
		  default:
			 cout<<"\n=====================";
			 cout<<"\n Wrong choice !!!!!!!";
			 cout<<"\n+++++++++++++++++++++";
		 }
		 break;
	 case 3:
		 cout<<"\n______________________________________________________________________________";
		 cout<<"\n****************************** Deleting a item *******************************";
		 cout<<"\n------------------------------------------------------------------------------";
		 del();
		 break;
	 case 4:
		 int a;
		 cout<<"\n______________________________________________________________________________";
		 cout<<"\n**********************Enter the searching you want to do *********************";
		 cout<<"\n------------------------------------------------------------------------------";
		 cout<<"\n 1.Search by name of product ";
		 cout<<"\n 2.Seacrh by company of product ";
		 cout<<"\n 3.Search by price of product "<<endl;
		 cin>>a;
		 switch(a)
		   {case 1:
			    spnm();
			    break;
		    case 2:
			    spcom();
			    break;
		    case 3:
			    spprc();
			    break;
		    default :
			     cout<<"\n=====================";
			     cout<<"\n Wrong choice !!!!!! ";
			     cout<<"\n+++++++++++++++++++++";
		   }
		 break;
	 case 5:
		 cout<<"\n______________________________________________________________________________";
		 cout<<"\n********************************* Finishing items ****************************";
		 cout<<"\n------------------------------------------------------------------------------";
		 fpd();
		 break;
	 case 6:
		 bill();
		 break;
	 case 7:
		 cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n=========================";
		 cout<<"\n Bye Take care.......... ";
		 cout<<"\n+++++++++++++++++++++++++";
		 break;
	 default :
		  cout<<"\n=====================";
		  cout<<"\n Wrong Choice !!!!! ";
		  cout<<"\n+++++++++++++++++++++";
	}
      }
   }
 else
 {cout<<"\n===================================";
  cout<<"\n Wrong user name and password !!!!!";
  cout<<"\n+++++++++++++++++++++++++++++++++++";
 }
 getch();
 return 0;
}
