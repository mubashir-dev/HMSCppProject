//@uthor MUBASHIR ALI //
//@Develpoing Fourm TECHABBOTT//
//***************************************************************
//                   HEADER FILES USED IN PROJECT
//****************************************************************
#include<iostream>
#include<fstream>
#include<string.h>
#include<iomanip>
#include<conio.h>
#include<stdio.h>
#include<windows.h>
using namespace std;
//**********************************************************************************************//
//****************************gotoxyFUnction***************************************************//
//**********************************************************************************************//
void gotoxy(int x,int y)
{
COORD c;
c.X=x;
c.Y=y;
SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);	
};
//--------------------------------CASSES USED IN THIS PROJECT-------------------------------------------------->
class Patiensts;
class Other_Staff;
class Medical_Staff
{
protected:
char Name[20];
char Emp_Number[15];
char C_Dept[20];
char Education[15];
int Serves;
long double Pay;
char Rank[20];
char Nic[20];
char Contact_nO[18];
char Speclization[20];
char blood_group[15];
char Contact_No[20];
char Address[35];
/*
<------------------------------------------------------------------------------->
*/
public:
Medical_Staff()
{
	strcpy(Name,"None");
	strcpy(Emp_Number,"None");
	strcpy(Speclization,"None");
	strcpy(Contact_No,"None");
	strcpy(Address,"None");
	strcpy(C_Dept,"None");
	strcpy(Nic,"None");
	strcpy(Rank,"None");
	strcpy(Education,"None");
	strcpy(blood_group,"None");
	Serves=0;
	Pay=0.0;
	strcpy(Contact_No,"None");	
}
void Getting_Information();
void Display_Information();
int Chacker(char*);
int ChackerNic(char*);
int Store_Data();
void Show_All();
void Search_Name(char*);
void Search_Emp(char*);
void Delete_Data(char*);
void Update(char*);
char* get_Emp_Id()
{
	return Emp_Number;
}
char * get_nic()
{
	return Nic;
}
char *  get_name()
{
//	if((Name=='A'&&Name=='Z') ||(Name=='a'&& Name=='z'))
//	{
	return Name;	
//	}
	
}
};
//-------------------------------------------------------------------------------//
//--------------------------Global Objects---------------------------------------//
Medical_Staff S1;
//-------------------------------------------------------------------------------//
void Medical_Staff::Getting_Information()
{	One:
	int C;
	int N;
	system("cls");
	system("color 2F");
	cout<<"\t\t\t     -----------------------"<<endl;
	cout<<"\t\t\t         INPUT DATA STAGE   "<<endl;
	cout<<"\t\t\t     -----------------------"<<endl;
	cout<<"\n\t ENTER YOUR EMPOLYEE NUMBER:          "; 
	cin.getline(Emp_Number,14);
	C=S1.Chacker(Emp_Number);
	if(C==0)
	{
		cout<<"\t\t\tSorry Already Registre"<<endl;
		getch();
		goto One;
	}
	cout<<"\n\t ENTER YOUR NIC:                      "; 
	cin.getline(Nic,19);
	N=S1.ChackerNic(Nic);
	if(N==0)
	{
		cout<<"\nNIC ALREADY REGISTRED"<<endl;
		goto One;
	}
	cout<<"\n\t ENTER YOUR CURRENT WORKING DEPT:     "; cin.getline(C_Dept,19);
	cout<<"\n\t ENTER YOUR NAME :                    "; cin.getline(Name,19);
	cout<<"\n\t ENTER YOUR EDUCATION QUALIFICATION:  "; cin.getline(Education,14);
	cout<<"\n\t ENTER YOUR YEAR OF SERVERS:          "; cin>>Serves;
	cout<<"\n\t ENTER YOUR CURRENT PAY:              "; cin>>Pay;
	cin.ignore();
	cout<<"\n\t ENTER YOUR RANK IN HOSIPITAL:        "; cin.getline(Rank,19);
	cout<<"\n\t ENTER YOUR MEDICAL SPECLIZATION:     "; cin.getline(Speclization,19);
	cout<<"\n\t ENTER  YOUR BLOOD GROUP:             "; cin.getline(blood_group,15);
	cout<<"\n\t ENTER YOUR CONTACT NUMBER:           "; cin.getline(Contact_No,34);
	cout<<"\n\t ENETR YOUR CURRENT ADDRESS:          "; cin.getline(Address,34);
	cout<<"\n"<<endl;
	cout<<"\t\t=============================================="<<endl;
}
void Medical_Staff::Display_Information()
{ 
system("cls");
cout<<"\n\n";
cout<<"\t\t\t----------------------------"<<endl;
cout<<"\t\t\t MEDIACAL STAFF INFORMATION "<<endl;
cout<<"\t\t\t----------------------------"<<endl;
cout<<"\n\n";
cout<<"\t\tNAME:                "<<setw(25)<<Name<<endl;
cout<<"\t\tEMPOLYEE NUMBER:     "<<setw(25)<<Emp_Number<<endl;
cout<<"\t\tDEPARTMENT:          "<<setw(25)<<C_Dept<<endl;
cout<<"\t\tEDUCATION:           "<<setw(25)<<Education<<endl;
cout<<"\t\tSERVERS:             "<<setw(19)<<Serves<<"-YEARS"<<endl;
cout<<"\t\tPAY:                 "<<setw(19)<<"PKR-"<<Pay<<endl;
cout<<"\t\tNIC                  "<<setw(25)<<Nic<<endl;
cout<<"\t\tRANK:                "<<setw(25)<<Rank<<endl;
cout<<"\t\tSPECILIXATION:       "<<setw(25)<<Speclization<<endl;
cout<<"\t\tBLOOD GROUP:         "<<setw(25)<<blood_group<<endl;
cout<<"\t\tCONTACT NUMBER:      "<<setw(25)<<Contact_No<<endl;
cout<<"\t\tADDRESS:             "<<setw(25)<<Address<<endl;
cout<<"\n\n";
cout<<"\t\t=============================================="<<endl;

}
int Medical_Staff::Store_Data()
{
ofstream fin;
fin.open("Medical_Staff.dat",ios::app|ios::binary);
if(Serves==0 && Pay==0.0)
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\4NOT SAVING \4"<<endl;
	return 0;
}
else
{
	fin.write((char*) this ,sizeof(*this));
	return 1;
getch();
cout<<"\n\n\n\n\n\n\n\n"<<endl;
cout<<"\t\t\t---------------------------------------------"<<endl;
cout<<"\t\t\t"<<" Record Store Successfully into Database"<<endl;
cout<<"\t\t\t---------------------------------------------"<<endl;	
}
fin.close();
getch();	
}
void Medical_Staff::Show_All()
{
ifstream fout;
fout.open("Medical_Staff.dat",ios::in|ios::binary);
if(!fout)
{
cout<<"\t\t\t\tFILE DOESNT EXIST"<<endl;	
}	
while(fout.read((char*) this ,sizeof(*this)))
{
	Display_Information();
	getch();
}
fout.close();	
}
int Medical_Staff::Chacker(char*C)
{
	fstream file;
	file.open("Medical_StAff.dat",ios::ate|ios::in|ios::out|ios::binary);
	if(!file)
	{
		cout<<"\t\t\tFILE DOESNT EXIST"<<endl;
		return 0;
	}
	file.seekg(0,ios::beg);
	while(!file.eof())
	{	file.read((char*) this ,sizeof(*this));
		if(strcmp(S1.get_Emp_Id(),C)==0)
		{
			return 0;
		}
	}
	file.read((char*) this ,sizeof(*this));
	return 1;
	file .close();
}
int Medical_Staff::ChackerNic(char* C)
{
	fstream file;
	file.open("Medical_StAff.dat",ios::ate|ios::in|ios::out|ios::binary);
	if(!file)
	{
		system("cls");
		cout<<"\n\n\n\n\n\n";
		cout<<"\t\t\t\tFILE NOT FOUND"<<endl;
	}
	file.seekg(0,ios::beg);
	while(!file.eof())
	{
		
		file.read((char*) this ,sizeof(*this));
		if(!strcmp(S1.get_nic(),C))
		{
			return 0;
		}
		return 1;
		
	}
	file.close();
	
	
}
void Medical_Staff::Search_Name(char *N)
{	int Flag=0;
	ifstream fout;
	fout.open("Medical_Staff.dat",ios::in|ios::binary);
	if(!fout)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
		
		
	}
	while(!fout.eof())
	{
	fout.read((char*) this ,sizeof(*this));
	if(strcmp(get_name(),N)==0)	
	{
		Display_Information();
		Flag++;
		getch();
	}
//	fout.read((char*) this ,sizeof(*this));
	}
	if(Flag==0)
	{	system("color 1F");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
	}
	
	fout.close();
	
	
	
	
	
}
void Medical_Staff::Search_Emp(char *N)
{	int flag=0;
	ifstream fout;
	fout.open("Medical_Staff.dat",ios::in|ios::binary);
	if(!fout)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
	}
	while(!fout.eof())
	{
	fout.read((char*) this ,sizeof(*this));
	if(strcmp(get_Emp_Id(),N)==0)
	{
		Display_Information();
		getch();
		flag++;
	}
	//fout.read((char*) this ,sizeof(*this));
	}
	if(flag==0)
	{
		system("color 1F");
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\n\n\n\n\n\n";
	}
	fout.close();
	
	
}
void Medical_Staff::Delete_Data(char *D)
{
int Flag=0;
ifstream fin;
ofstream fout;
fin.open("Medical_Staff.dat",ios::in|ios::binary);
if(!fin)
{

	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\t\tFILE NOT FOUND"<<endl;
	cout<<"\n\n\n\n\n\n\n";

}	
else
{
fout.open("TEMPFILE.dat",ios::out|ios::binary);
fin.read((char*) this ,sizeof(*this));
while(!fin.eof())
{
if(strcmp(get_Emp_Id(),D))
fout.write((char*) this ,sizeof(*this));	
fin.read((char *) this, sizeof(*this));
Flag++;
}	
fin.close();
fout.close();
remove("Medical_Staff.dat");
rename("TEMPFILE.dat","Medical_Staff.dat");		
}
if(Flag==1)
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRECORD DELETE SUCCESSFULLY"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		}
		else
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t------------------"<<endl;
		cout<<"\t\t\t\t RECORD NOT FOUND "<<endl;
		cout<<"\t\t\t\t------------------"<<endl;
		}
		getche();	
	
	
	
	
}
void Medical_Staff::Update(char *M)
{
int Option;
int flag;
fstream file;
file.open("Medical_Staff.dat",ios::in|ios::out|ios::ate|ios::binary);
if(!file)
{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
}	
else
{
file.seekg(0);
file.read((char*) this ,sizeof(*this));
while(!file.eof())
{
file.read((char*) this ,sizeof(*this));
if(strcmp(get_Emp_Id(),M)==0)
{   Getting_Information();
	file.seekp(file.tellp()-sizeof(*this));
	file.write((char*) this ,sizeof(*this));
	flag=1;
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRECORD UPDATE SUCCESSFULLY"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
	}
}	
}	
}		
file.close();		
if(flag==0)
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t------------------"<<endl;
		cout<<"\t\t\t\t RECORD NOT UPDATED "<<endl;
		cout<<"\t\t\t\t------------------"<<endl;
		}
		getche();
}
//<----------------------------------------------------->
//-----------------OTHER_SATFF ------------------------->
//<----------------------------------------------------->
class Other_Staff:public Medical_Staff
{
public:
void Collect_Info();
void Collect_Display();
int Store_Data();
void Show_ALL();
int O_S_Chacker(char*);
int O_S_ChahkerNic(char*);
void Search_Nic(char*);
void Search_Name(char*);
void OS_update(char*);
void OS_Delete(char*);
};
//<-------------------------------------------------------->
Other_Staff O_S;
//<-------------------------------------------------------->
void Other_Staff::Collect_Info()
{
One:
	int C;
	int N;
	system("cls");
	system("color 5F");
	cout<<"\t\t\t     -----------------------"<<endl;
	cout<<"\t\t\t         INPUT DATA STAGE   "<<endl;
	cout<<"\t\t\t     -----------------------"<<endl;
	cout<<"\n\t ENTER YOUR EMPOLYEE NUMBER:          "; 
	cin.getline(Emp_Number,14);
	C=O_S.O_S_Chacker(Emp_Number);
	if(C==0)
	{
		cout<<"\t\t\tSorry Already Registre"<<endl;
		getch();
		goto One;
	}
	cout<<"\n\t ENTER YOUR NIC:                      "; 
	cin.getline(Nic,19);
	N=O_S.O_S_ChahkerNic(Nic);
	if(N==0)
	{
		cout<<"\nNIC ALREADY REGISTRED"<<endl;
		goto One;
	}
	cout<<"\n\t ENTER YOUR CURRENT WORKING DEPT:     "; cin.getline(C_Dept,19);
	cout<<"\n\t ENTER YOUR NAME :                    "; cin.getline(Name,19);
	cout<<"\n\t ENTER YOUR EDUCATION QUALIFICATION:  "; cin.getline(Education,14);
	cout<<"\n\t ENTER YOUR YEAR OF SERVERS:          "; cin>>Serves;
	cout<<"\n\t ENTER YOUR CURRENT PAY:              "; cin>>Pay;
	cin.ignore();
	cout<<"\n\t ENTER YOUR RANK IN HOSIPITAL:        "; cin.getline(Rank,19);
	cout<<"\n\t ENTER  YOUR BLOOD GROUP:             "; cin.getline(blood_group,15);
	cout<<"\n\t ENTER YOUR CONTACT NUMBER:           "; cin.getline(Contact_No,34);
	cout<<"\n\t ENETR YOUR CURRENT ADDRESS:          "; cin.getline(Address,34);
	cout<<"\n"<<endl;
	cout<<"\t\t=============================================="<<endl;
	
	
	
	
}
void Other_Staff::Collect_Display()
{
system("cls");
cout<<"\n\n";
cout<<"\t\t\t  --------------------------"<<endl;
cout<<"\t\t\t   OTHER STAFF INFORMATION  "<<endl;
cout<<"\t\t\t  --------------------------"<<endl;
cout<<"\n\n";
cout<<"\t\tNAME:                "<<setw(25)<<Name<<endl;
cout<<"\t\tEMPOLYEE NUMBER:     "<<setw(25)<<Emp_Number<<endl;
cout<<"\t\tDEPARTMENT:          "<<setw(25)<<C_Dept<<endl;
cout<<"\t\tEDUCATION:           "<<setw(25)<<Education<<endl;
cout<<"\t\tSERVERS:             "<<setw(19)<<Serves<<"-YEARS"<<endl;
cout<<"\t\tPAY:                 "<<setw(19)<<"PKR-"<<Pay<<endl;
cout<<"\t\tNIC                  "<<setw(25)<<Nic<<endl;
cout<<"\t\tRANK:                "<<setw(25)<<Rank<<endl;
cout<<"\t\tBLOOD GROUP:         "<<setw(25)<<blood_group<<endl;
cout<<"\t\tCONTACT NUMBER:      "<<setw(25)<<Contact_No<<endl;
cout<<"\t\tADDRESS:             "<<setw(25)<<Address<<endl;
cout<<"\n\n";
cout<<"\t\t=============================================="<<endl;

}
int Other_Staff::Store_Data()
{
ofstream fin;
fin.open("Other_Staff.dat",ios::app|ios::binary);
if(Pay==0.0 && Serves==0)
{
cout<<"\n\n\n\n\n\n\n\n";
cout<<"\t\t\tDATA IS  NOT INTITILIZED"<<endl;
return 0;	
}	
else
{

fin.write((char*) this ,sizeof(*this));
return 1;
getch();
cout<<"\n\n\n\n\n\n\n\n"<<endl;
cout<<"\t\t\t---------------------------------------------"<<endl;
cout<<"\t\t\t"<<"RECORD SUCCESSFULLY ADDED INTO THE DATABASE"<<endl;
cout<<"\t\t\t---------------------------------------------"<<endl;		
}	
fin.close();
}
void Other_Staff::Show_ALL()
{
ifstream fout;
fout.open("Other_Staff.dat",ios::in|ios::binary);
if(!fout)
{
	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\tFILE NOT FOUND"<<endl;
	
}
else
{
	
	while(!fout.eof())
	{
		fout.read((char *) this ,sizeof(*this));
		
		Collect_Display();
		getch();		
		
	}
//	fout.read((char*) this ,sizeof(*this));	
fout.close();

}
getch();
}
int Other_Staff::O_S_Chacker(char* C)
{
ifstream fout;
fout.open("Other_Staff.dat",ios::in|ios::binary);
if(!fout)
{
cout<<"\t\t\tFILE NOT FOUND";	
}	
else
{
while(!fout.eof())
{
	fout.read((char*) this ,sizeof(*this));
	if(strcmp(get_Emp_Id(),C)==0)
	{
		return 0;
	}
	return 1;	
}
fout.close();	
}	
}
int Other_Staff::O_S_ChahkerNic(char *N)
{
ifstream fout;
fout.open("Other_Staff.dat",ios::in|ios::binary);
if(!fout)
{
//	cout<<"\n\n\n\n\n\n\n";
	cout<<"\t\t\t\tFILE NOT FOUND";
	//return 0;
}
else
{
	fout.read((char*) this ,sizeof(*this));
while(!fout.eof())	
{
	fout.read((char*) this ,sizeof(*this));
	if(strcmp( get_nic(),N)==0)
	{
		return 0;
	}
	return 1;	
}
}
fout.close();	
}
void Other_Staff::Search_Nic(char* N)
{
	int flag=0;
	ifstream fout;
	fout.open("Other_Staff.dat",ios::in|ios::binary);
	if(!fout)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
	}
	while(!fout.eof())
	{
	fout.read((char*) this ,sizeof(*this));
	if(strcmp(get_Emp_Id(),N)==0)
	{
		Display_Information();
		getch();
		flag++;
	}
	//fout.read((char*) this ,sizeof(*this));
	}
	if(flag==0)
	{
		system("color 1F");
		cout<<"\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\n\n\n\n\n\n";
	}
	fout.close();
	
	
}
void Other_Staff::Search_Name(char *N)
{
int Flag=0;
	ifstream fout;
	fout.open("Other_Staff.dat",ios::in|ios::binary);
	if(!fout)
	{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
		
		
	}
	while(!fout.eof())
	{
	fout.read((char*) this ,sizeof(*this));
	if(strcmp(get_name(),N)==0)	
	{
		Display_Information();
		Flag++;
		getch();
	}
//	fout.read((char*) this ,sizeof(*this));
	}
	if(Flag==0)
	{	system("color 1F");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\tRECORD NOT FOUND"<<endl;
		cout<<"\t\t\t\t----------------"<<endl;
	}
	
	fout.close();
		
}
void Other_Staff::OS_update(char *U)
{
int flag;
fstream file;
file.open("Other_Staff.dat",ios::in|ios::out|ios::ate|ios::binary);
if(!file)
{
	cout<<"\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\tFILE NOT FOUND";
	
}
else
{
file.seekg(0);
file.read((char*) this ,sizeof(*this));
while(!file.eof())
{
if(strcmp(get_Emp_Id(),U)==0)
{   Collect_Info();
	file.seekp(file.tellp()-sizeof(*this));
	file.write((char*) this ,sizeof(*this));
	flag++;

}	
file.read((char*) this ,sizeof(*this));
}	
file.close();
if(flag>=1)
		{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRECORD UPDATE SUCCESSFULLY"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		}
		else
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t------------------"<<endl;
		cout<<"\t\t\t\t RECORD NOT UPDATED "<<endl;
		cout<<"\t\t\t\t------------------"<<endl;
		}
		getche();
}
}
void Other_Staff::OS_Delete(char *D)
{
int flag=0;
ofstream fout;
ifstream fin;
fin.open("Other_Staff.dat",ios::in|ios::binary);
if(!fin)
{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t----------------"<<endl;
		cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
		cout<<"\t\t\t\t----------------"<<endl;

}
else
{
fout.open("Tempfile.dat",ios::out|ios::binary);
fin.read((char*) this ,sizeof(*this));
while(!fin.eof())
{
if(strcmp(get_Emp_Id(),D))
fout.write((char*) this ,sizeof(*this));
fin.read((char*) this ,sizeof(*this));	
flag=1;
}
}		
fin.close();
fout.close();
remove("Other_Staff.dat");
rename("Tempfile.dat","Other_Staff.dat");

if(flag==1)
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRECORD DELETE SUCCESSFULLY"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		}
		else
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t------------------"<<endl;
		cout<<"\t\t\t\t RECORD NOT FOUND "<<endl;
		cout<<"\t\t\t\t------------------"<<endl;
		}
		getche();	
}
//--------------------------------------------------->
//-----------------Other_Staff_Class_End_Here-------->
//--------------------------------------------------->
class Patients:public Medical_Staff
{
private:
char Patient_Id[15];
char Served[20];
char Medicines[35];
char Diseased_Dignose[35]; 
int Age;
static int Patient_Counter;

public:
Patients()
{
	strcpy(Patient_Id,"None");
	strcpy(Served,"None");
	strcpy(Medicines,"None");
	strcpy(Diseased_Dignose,"None");
	Age=0;
}
void Patient_Information();
void Patient_Dispaly();
static void Counter_Display();
int Patient_Store();
void Patient_Show_All();
int Patient_Chacker(char*);
int Patient_Nic_Chechk(char*);
void Pateint_Search_Nic(char*);
void Pateint_Search_Id(char*);
void Patient_Update(char*);
void Patint_Delete(char *);
char * Get_Patient_Id()
{
	return Patient_Id;
}
};
//-------------------------------------------------//
//-----------------GLOBAL OBJJECT-----------------//
	Patients P1;
/////////////////////////////////////////////
/*int Patients::Patient_Counter=0001;
void Patients::Counter_Display()
{
	cout<<"Patient Token:"<<Patient_Counter<<endl;
	Patient_Counter++;
}*/
void Patients::Patient_Information()
{
One:
	int C;
	int N;
	system("cls");
	cout<<"\t\t\t     -----------------------"<<endl;
	cout<<"\t\t\t         DATA ENTRY DESK    "<<endl;
	cout<<"\t\t\t     -----------------------"<<endl;
	cout<<"\t ENTER YOUR PATIENT ID :              "; 
	cin.getline(Patient_Id,14);
	C=P1.Patient_Chacker(Patient_Id);
	if(C==0)
	{
		cout<<"\t\t\tSorry Already Registre"<<endl;
		getch();
		goto One;
	}
	cout<<"\n\t ENTER YOUR NIC:                     "; 
	cin.getline(Nic,19);
	N=P1.Patient_Nic_Chechk(Nic);
	if(N==0)
	{
		cout<<"\nNIC ALREADY REGISTRED"<<endl;
		goto One;
	}
	cout<<"\n\t ENTER THE NAME OF  CHACKUP  DEPT:        "; cin.getline(C_Dept,19);
	cout<<"\n\t ENTER THE PATIENT NAME :                 "; cin.getline(Name,19);
	cout<<"\n\t ENTER THE AGE OF PATIENT:                "; cin>>Age;
	cin.ignore();
	cout<<"\n\t ENTER THE NAME OF DIAGNOSED DEASES:       "; cin.getline(Diseased_Dignose,34);
	cout<<"\n\t ENTER THE PESCRIBE MEDICINES:            "; cin.getline(Medicines,34);
	cout<<"\n\t ENTER THE DOCTOR WHO SERVED:             "; cin.getline(Served,19);
	cout<<"\n\t ENTER PATIENT GENDER:                    "; cin.getline(Rank,19);
	cout<<"\n\t ENTER  PATIENT BLOOD GROUP:              "; cin.getline(blood_group,15);
	cout<<"\n\t ENTER PATIENT CONTACT NUMBER:            "; cin.getline(Contact_No,34);
	cout<<"\n\t ENETR PATIENT CURRENT ADDRESS:           "; cin.getline(Address,34);
	cout<<"\n"<<endl;
	cout<<"\t\t=============================================="<<endl;		
}
void Patients::Patient_Dispaly()
{
system("cls");
cout<<"\n\n";
cout<<"\t\t\t   ----------------------------"<<endl;
cout<<"\t\t\t      PATIENT  INFORMATION     "<<endl;
cout<<"\t\t\t   ----------------------------"<<endl;
cout<<"\n";
cout<<"\t\tNAME:                "<<setw(30)<<Name<<endl;
cout<<"\t\tPATIENT ID:          "<<setw(30)<<Patient_Id<<endl;
//cout<<"\t\tPATIENT TOKEN        "<<setw(30)<<Patients::Patient_Counter<<endl;
cout<<"\t\tCHECKUP DEPARTMENT:  "<<setw(30)<<C_Dept<<endl;
cout<<"\t\tSERVEF BY:           "<<setw(30)<<Served<<endl;
cout<<"\t\tAGE:                 "<<setw(24)<<Age<<"-YEARS"<<endl;
cout<<"\t\tNIC                  "<<setw(30)<<Nic<<endl;
cout<<"\t\tDIAGNOSE DISEASE:     "<<setw(30)<<Diseased_Dignose<<endl;
cout<<"\t\tPESCRIBE MEDICINES:  "<<setw(30)<<Medicines<<endl;
cout<<"\t\tBLOOD GROUP:         "<<setw(30)<<blood_group<<endl;
cout<<"\t\tCONTACT NUMBER:      "<<setw(30)<<Contact_No<<endl;
cout<<"\t\tADDRESS:             "<<setw(30)<<Address<<endl;
cout<<"\n";
cout<<"\t\t  =============================================="<<endl;	
	
}
int Patients::Patient_Store()
{
system("cls");
ofstream fout;
fout.open("Patient_File.dat",ios::app|ios::binary);
if(Age==0 && Name=="None")
{
	system("cls");
	cout<<"\t\t\t\tSORRY TRY AGAIN"<<endl;
	return 0;
}
else
{
	fout.write((char*) this ,sizeof(*this));
	return 0;	
}		getch();
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\tRECORD UPDATE SUCCESSFULLY"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		getch();
	fout.close();	
}
void Patients::Patient_Show_All()
{	system("cls");
	ifstream fin;
	fin.open("Patient_File.dat",ios::in|ios::binary);
	if(!fin)
	{
		system("cls");
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\t FILE NOT FOUND           "<<endl;
		cout<<"\t\t\t--------------------------"<<endl;	
	}
	else
	{
	while(!fin.eof())
	{
	fin.read((char*) this ,sizeof(*this));
	Patient_Dispaly();
	getch();
	}	
	}
	fin.close();}
	
	int Patients::Patient_Chacker(char*C)
	{
	system("cls");
	ifstream file;
	file.open("Patient_File.dat",ios::in|ios::binary);
	if(!file)
	{
	cout<<"\t\t\tFILE NOT FOUND"<<endl;
	}	
	else
	{
	file.read((char*) this ,sizeof(*this));
	while(!file.eof())	
	{
	file.read((char*) this ,sizeof(*this));
	if(!strcmp(P1.Get_Patient_Id(),C))
		return 0;
	}
	return 1;
	file.close();	
	}
}
	
	int Patients::Patient_Nic_Chechk(char*N)
	{
	int Flag=0;	
	ifstream file;
	file.open("Patient_File.dat",ios::in|ios::binary);
	if(!file)
	{
	cout<<"\t\t\tFILE NOT FOUND"<<endl;
	}	
	else
	{
	while(!file.eof())	
	{
	file.read((char*) this ,sizeof(*this));
	if(!strcmp(P1.get_nic(),N))
		return 0;
	}
	}
	return 1;
	file.close();
	}
	void Patients::Pateint_Search_Id(char*N)
	{
	int flag=0;
	system("color 7");
	ifstream fout;
	fout.open("Patient_File.dat",ios::in|ios::binary);
	if(!fout)
	{
	cout<<"\t\t\t\tFILE NOT FOUND"<<endl;	
	}	
	else
	{
	while(!fout.eof())	
	{
	fout.read((char*) this ,sizeof(*this));	
	if(!strcmp(Get_Patient_Id(),N))
	{
		Patient_Dispaly();
		flag++;
		getch();
	}		
	fout.read((char*) this ,sizeof(*this));	
	}	
	if(flag==0)
	{
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t------------------"<<endl;
		cout<<"\t\t\t\t RECORD NOT FOUND "<<endl;
		cout<<"\t\t\t\t------------------"<<endl;
		
	}
	fout.close();
	getch();	
	}
}
void Patients::Pateint_Search_Nic(char*N)
{	system("cls");
	int Flag=0;
	ifstream fout;
	fout.open("Patient_File.dat",ios::in|ios::binary);
	if(!fout)
	{
	cout<<"\t\t\t\tFILE NOT FOUND"<<endl;	
	}	
	else
	{
	fout.seekg(0,ios::beg);
	fout.read((char*) this ,sizeof(*this));
	while(!fout.eof())	
	{
	fout.read((char*) this ,sizeof(*this));	
	if(strcmp(get_nic(),N)==0)
	{
		Patient_Dispaly();
		Flag++;
		getch();
	}		
	fout.read((char*) this ,sizeof(*this));	
	}	
	if(Flag==0)
	{
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t\t------------------"<<endl;
		cout<<"\t\t\t\t RECORD NOT FOUND "<<endl;
		cout<<"\t\t\t\t------------------"<<endl;
		
	}
	fout.close();
	getch();	
	}		
}
void Patients::Patient_Update(char *u)
{
system("cls");
int flag=0;
fstream file;
file.open("Patient_File.dat",ios::in|ios::out|ios::ate|ios::binary);
if(!file)
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
	cout<<"\t\t\t\t------------------"<<endl;
	getch();
	system("cls");	
}	

file.seekg(0);
file.read((char*) this ,sizeof(*this));
while(!file.eof())
{
if(!strcmp(get_nic(),u))
{
Patient_Information();
file.seekp(file.tellp()-sizeof(*this));
file.write((char*) this ,sizeof(*this));	
getch();
flag++;	
}
file.read((char*) this ,sizeof(*this));
}		
if(flag==0)
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t RECORED NOT FOUND "<<endl;
	cout<<"\t\t\t\t------------------"<<endl;
	getch();	
}
if(flag==1)
{
	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t RECORED UPDATE SUCCESSFULLY "<<endl;
	cout<<"\t\t\t\t------------------"<<endl;	
}
file.close();	
}
void Patients::Patint_Delete(char *D)
{
system("cls");
int flag=0;
ifstream fin;
fstream fout;
fin.open("Patient_File.dat",ios::in|ios::binary);
if(!fin)
{

	cout<<"\n\n\n\n\n\n\n\n\n\n\n\n\n";
	cout<<"\t\t\t\t------------------"<<endl;
	cout<<"\t\t\t\t FILE NOT FOUND "<<endl;
	cout<<"\t\t\t\t------------------"<<endl;
	getch();
	system("cls");		

}
else
{		
fout.open("Temp_File.dat",ios::out|ios::binary);
fin.read((char*) this ,sizeof(*this));
while(!fin.eof())
{
if(strcmp(get_nic(),D))
{
fout.write((char*) this ,sizeof(*this));
fin.read((char*) this ,sizeof(*this));
flag++;	
}	
	
	
fin.read((char*) this ,sizeof(*this));	
}
fin.close();
fout.close();
remove("Patient_File.dat");
rename("Temp_File.dat","Patient_File.dat");
}
if(flag==1)
		{
		cout<<"\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------------"<<endl;
		cout<<"\t\t\t RECORED DELETE SUCCESSFULLY"<<endl;
		cout<<"\t\t\t--------------------------"<<endl;
		}
		else
		{
		
		cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
		cout<<"\t\t\t--------------------"<<endl;
		cout<<"\t\t\tRECRED DOESN,T EXITS"<<endl;
		cout<<"\t\t\t--------------------"<<endl;
		}
		getche();		
}
//------------------------------How To Use--------------------------------------//
void Instructions()
{
		char CLine[]="\t\4 THIS PROJECT IS COMPLETED  UNDER SUPERVISION  OF TECHABBOTT  FOR\n\n\t\tGOVT DESTRICT  HEADQUARTER HOSPIATL  ABBOTTABAD \4";
	int i=0;
	int size;
	size=strlen(CLine);
	system("color 2");
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\4TECHABBOTT\4"<<endl;
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\n\n\n\n\n\n\n\n";
	Sleep(500);
	for(i=0;i<size;i++)
	{	Sleep(20);
		cout<<CLine[i];
	}
	getch();
	system("cls");
	system("color 2");
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\4TECHABBOTT\4"<<endl;
	cout<<"\t\t\t\t-----------"<<endl;
	int I=0;
	int siZE;	
	char Inst[]="\tPLEASE FOLLOW THESE INSTRUCTION FOR USING THIS PROJECT \n\n \t1:-Please Make Sure to keep Patient Id As Unique Id Of Patient\n \t2:-We Proposed You To Use this Formate For Roll Numberng\n \t3:-Roll Formate:-RollNo-Class-Section\n \t4:-EI=8TH,SE=7TH,SI=6TH As Class Code\n \t5:-Sections Code Are Here.......... \n \t6:-Green=G,Yellow=Y;Blue=B,Pink=P\n \t7:-RollNo Example:1-EI-G\n \t8:-Above Statment Means That a Student having\n  \t9:-RollNo 1 From Class 8th And his Section is Greem\n \t10:-Fail Subject Is Treated as Fail And Not Count in Total Marks\n \t11:-Use UpperCase Letters";
	siZE=strlen(Inst);
	for(I=0;I<siZE;I++)
	{
		Sleep(10);
		cout<<Inst[I];
	}
	cout<<"\n";
																							cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
																							cout<<"\t\t\t\t\t\t\t\t   ADMIN   "<<endl;
																							cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
	cout<<"----------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	getch();
	system("cls");
}
//-----------------------------------EndFunction------------------------------------------------------------------------//
void EndFunction()
{
		
char Main_Logo[]="\n\n\n\n\n\n\n\n\t\t\t\t-----------------\n\t\t\t\t  \4THANK YOU\4\n\t\t\t\t-----------------\n\n\n\n\n\n\t\t\t\t\t------------------------------------\n\t\t\t\t\t   FOR USING THIS APPLICATION\n\t\t\t\t\t------------------------------------\n";
int size=strlen(Main_Logo);
int i;
for(i=0;i<size;i++)
{
	Sleep(10);
	cout<<Main_Logo[i];
}
	getche();
	system("cls");	
}
//-------------------------------------------------------------//
void Medical_Panel()
{
int choice;
system("cls");
cout<<"\n\n";
cout<<"\t\t\t-----------------------"<<endl;
cout<<"\t\t\t    MEDICAL STAFF      "<<endl;
cout<<"\t\t\t-----------------------"<<endl;
cout<<"\n";
cout<<"\t\t\t1:DISPLAY ALL RECOREDS"<<endl;
cout<<"\n\t\t\t2:SEARCH A  RECOREDS  BY NAME"<<endl;
cout<<"\n\t\t\t3:SEARCH RECORED BY NIC"<<endl;
cout<<"\n\t\t\t4:UPDATE A RECORED "<<endl;
cout<<"\n\t\t\t5:DELETE A RECORED"<<endl;
cout<<"\n\t\t\t6:BACK TO MAIN MENU"<<endl;
cout<<"\n\t\t\tPLEASE ENTER YOUR CHOICE(1-6)"<<endl;
gotoxy(24,19);
cin>>choice;
switch(choice)
{
case 1:
		{
		system("cls");
		S1.Show_All();
		break;
		}	
case 2:
		{
		char name[20];
		cout<<"\t\t\tENTER NAME FOR SEARCHING"<<endl;
		gotoxy(24,21);
		cin.getline(name,19);
		cin.ignore();
		S1.Search_Name(name);
		system("cls");
		break;
		}
case 3:
	    {
	    char nic[20];
		 cout<<"\t\t\tENTER THE EMPOLYEE NUMBER FOR SEARCHING"<<endl;
		 gotoxy(24,20);
		 cin.getline(nic,19);
		 S1.Search_Emp(nic);
		system("cls");	
	   	break;	
		}
case 4:
		{
		char EmN[20];
		cout<<"\t\t\tENTER THR EMPOLYEE NUMBER FOR UPDATING:"<<endl;
		gotoxy(24,22);
		cin.getline(EmN,19);
		S1.Update(EmN);	
		system("cls");
		break;
		}
case 5:
	{
	char EmN[20];
	cout<<"\t\t\tENTER THE EMPOLYEE NUMBER FOR DELETING:"<<endl;
	gotoxy(24,20);
	cin.getline(EmN,19);	
	S1.Delete_Data(EmN);	
	break;		
	}
case 6:
	return;
	default:
		cout<<"\t\t\tINVALID CHOICE"<<endl;
}
 Medical_Panel();
}
void NonMEDICAL_Panel()
{
int choice;
system("cls");
cout<<"\n\n";
cout<<"\t\t\t-----------------------"<<endl;
cout<<"\t\t\t    OTHER STAFF      "<<endl;
cout<<"\t\t\t-----------------------"<<endl;
cout<<"\n";
cout<<"\t\t\t1:DISPLAY ALL RECOREDS"<<endl;
cout<<"\n\t\t\t2:SEARCH A  RECOREDS  BY NIC"<<endl;
cout<<"\n\t\t\t3:SEARCH RECORED BY NAME"<<endl;
cout<<"\n\t\t\t4:UPDATE A RECORED "<<endl;
cout<<"\n\t\t\t5:DELETE A RECORED"<<endl;
cout<<"\n\t\t\tPLEASE ENTER YOUR CHOICE(1-6)"<<endl;
gotoxy(24,18);
cin>>choice;
switch(choice)
{
	case 1:
 	{
	 system("cls");
	O_S.Show_ALL();
	 break;
	}
 case 2:
 	{
 	char id[20];	
 	cout<<"\t\t\tENTER THE NIC FOR SEARCHING"<<endl;
	gotoxy(24,20);
	cin.getline(id,19);
	cin.ignore();
	O_S.Search_Nic(id);
	getch();	
 	break;	
	}
 case 3:
 	{
 	char name[20];
	cout<<"\t\t\tENTER THE NAME FOR SEARCHING"<<endl;
	gotoxy(24,20);
	cin.getline(name,19);
	cin.ignore();
	O_S.Search_Name(name);
	break;	
	}
  case 4:
  	{
  	char Update[20];
	 cout<<"\t\t\tENTER THE NIC FOR UPDATE THE RECORED"<<endl;
	 gotoxy(24,20);
	cin.ignore();
	 cin.getline(Update,19);
	 O_S.OS_update(Update);
	 break;
	}
  case 5:
  	{
  	char Delete[20];
	 cout<<"\t\t\tENTER THE NIC FOR DELETE THE RECORED:"<<endl;
	 gotoxy(24,20);
	cin.ignore();
	 cin.getline(Delete,19);
	 O_S.OS_Delete(Delete);
	 break;	
	}
 case 6:
 	return;
 default:
 	cout<<"\n\n\n\n\t\t\tINVALID CHOICE"<<endl;
}
NonMEDICAL_Panel();	
}
void Pateints_PANEL()
{
int choice;
system("cls");
cout<<"\n\n";
cout<<"\t\t\t-----------------------"<<endl;
cout<<"\t\t\t    PATIENTS RECORED   "<<endl;
cout<<"\t\t\t-----------------------"<<endl;
cout<<"\n";
cout<<"\t\t\t1:DISPLAY ALL RECOREDS"<<endl;
cout<<"\n\t\t\t2:SEARCH A  RECOREDS  BY NIC"<<endl;
cout<<"\n\t\t\t3:SEARCH RECORED BY ID"<<endl;
cout<<"\n\t\t\t4:UPDATE A RECORED "<<endl;
cout<<"\n\t\t\t5:DELETE A RECORED"<<endl;
cout<<"\n\t\t\t6:BACK TO MAIN MENU"<<endl;
cout<<"\n\t\t\tPLEASE ENTER YOUR CHOICE(1-6)"<<endl;
gotoxy(24,19);
cin>>choice;
switch(choice)
{
 case 1:
 	{
	 system("cls");
	 P1.Patient_Show_All();
	 break;
	}
 case 2:
 	{
 	char id[20];	
 	cout<<"\t\t\tENTER THE NIC FOR SEARCHING"<<endl;
	gotoxy(24,20);
	cin.ignore();
	cin.getline(id,19);
	P1.Pateint_Search_Nic(id);	
 	break;	
	}
 case 3:
 	{
 	char nic[20];
	 cout<<"\t\t\tENTER THE ID FOR SEARCHING"<<endl;
	 gotoxy(24,20);
	cin.ignore();
	 cin.getline(nic,19);
	 P1.Pateint_Search_Id(nic);
	 break;	
	}
  case 4:
  	{
  	char Update[20];
	 cout<<"\t\t\tENTER THE NIC FOR UPDATE THE RECORED"<<endl;
	 gotoxy(24,20);
	cin.ignore();
	 cin.getline(Update,19);
	 P1.Patient_Update(Update);
	 break;
	}
  case 5:
  	{
  	char Delete[20];
	 cout<<"\t\t\tENTER THE NIC FOR DELETE THE RECORED:"<<endl;
	 gotoxy(24,20);
	cin.ignore();
	 cin.getline(Delete,19);
	 P1.Patint_Delete(Delete);
	 break;	
	}
 case 6:
 	return;
 default:
 	cout<<"\n\n\n\n\t\t\tINVALID CHOICE"<<endl;
}
Pateints_PANEL();
}
//
void instructions()
{
	char CLine[]="\t\4 THIS PROJECT IS COMPLETED  UNDER SUPERVISION  OF TECHABBOTT  FOR\n\n\t\t\tDISTRIC HEADQUARTER HOSIPITAL ABBOTTABAD \4";
	int i=0;
	int size;
	size=strlen(CLine);
	system("color 2");
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\4TECHABBOTT\4"<<endl;
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\n\n\n\n\n\n\n\n";
	Sleep(500);
	for(i=0;i<size;i++)
	{	Sleep(20);
		cout<<CLine[i];
	}
	getch();
	system("cls");
	system("color 2");
	cout<<"\t\t\t\t-----------"<<endl;
	cout<<"\t\t\t\t\4TECHABBOTT\4"<<endl;
	cout<<"\t\t\t\t-----------"<<endl;
	int I=0;
	int siZE;	
	char Inst[]="\tPLEASE FOLLOW THESE INSTRUCTION FOR USING THIS PROJECT \n\n \t1:-Please Make Sure to keep RollNo As Unique Id Of Student\n \t2:-We Proposed You To Use this Formate For Roll Numberng\n \t3:-Roll Formate:-RollNo-Class-Section\n \t4:-EI=8TH,SE=7TH,SI=6TH As Class Code\n \t5:-Sections Code Are Here.......... \n \t6:-Green=G,Yellow=Y;Blue=B,Pink=P\n \t7:-RollNo Example:1-EI-G\n \t8:-Above Statment Means That a Student having\n  \t9:-RollNo 1 From Class 8th And his Section is Greem\n \t10:-Fail Subject Is Treated as Fail And Not Count in Total Marks\n \t11:-Use UpperCase Letters";
	siZE=strlen(Inst);
	for(I=0;I<siZE;I++)
	{
		Sleep(10);
		cout<<Inst[I];
	}
	cout<<"\n";
																							cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
																							cout<<"\t\t\t\t\t\t\t\t   ADMIN   "<<endl;
																							cout<<"\t\t\t\t\t\t\t\t-----------"<<endl;
	cout<<"------------------------------------------------------------------------------------------------------------"<<endl;
	cout<<endl;
	getch();
	system("cls");
	
}
//------------------------Last Function--------------------------->
//<-------------------------------------------->
//<------------	Patients P1,P2;----->
//--------------------------------------------->
int main ()
{
	SetConsoleTitle("--HOSIPITAL MANAGEMENT SYSTEM BY TECHABBOTT--");
	
	system("color 1F");
//	P1.Patient_Information();
//	O_S.Collect_Info();

//	S1.Getting_Information();	
//	O_S.Collect_Info();
instructions();
	system("cls");
while(1)
{	
	int i =0;
	int size=0;
	char Heading[]="\t\t\t\t   MAIN MENU   ";
	size=strlen(Heading);
	system("cls");
	{
	}
	cout<<"\n\t\t\t    -----------------------"<<endl;
	for(i=0;i<=size;i++)
	{
		Sleep(10);
		cout<<Heading[i];
		system("color 2f");
		
	}
	cout<<"\n";
	cout<<"\t\t\t    -----------------------"<<endl;
	int Choice;
	cout<<"\n\t\t\t   1:CREATE MEDICAL STAFF RECORED"<<endl;
	cout<<"\n\t\t\t   2:CREATE NON MEDICAL STAFF RECORED"<<endl;
	cout<<"\n\t\t\t   3:CREATE PATIENT RECORED"<<endl;
	cout<<"\n\t\t\t   4:MEDICAL STAFF"<<endl;
	cout<<"\n\t\t\t   5:OTHER STAFF"<<endl;
	cout<<"\n\t\t\t   6:PATIENST SECTION"<<endl;
	cout<<"\n\t\t\t   7:HOW TO USE "<<endl;
	cout<<"\n\t\t\t   8:EXIT"<<endl;
	cout<<"\n\t\t\t   ENTER YOUR CHOICE(1-3)"<<endl;
	gotoxy(27,22);
	cin>>Choice;
	switch(Choice)
	{
	case 1:
	{
	system("cls");
	S1.Getting_Information();	
	S1.Display_Information();
	S1.Store_Data();
	break;
	}
	case 2:
	{
	system("cls");
	O_S.Collect_Info();
    O_S.Collect_Display();
  	O_S.Store_Data();
	break;		
	}
	case 3:
	{
	system("cls");
	P1.Patient_Information();
	P1.Patient_Dispaly();
	P1.Patient_Store();
	break;
	}	
	case 4:
	{
	system("cls");
	Medical_Panel();
	break;
	}	
	case 5:
	{
	system("cls");		
	NonMEDICAL_Panel();
	}
	case 6:
	{
	system("cls");
	Pateints_PANEL();
	break;		
	}
	case 7:
	{
	system("cls");
	Instructions();
	break;	
	}
	case 8:
	{
	system("cls");
	EndFunction();
	exit(0);		
	}
	default:
		{
			cout<<"\n\n\n\n\n\t\t\tINVALID CHOICE";
		}
	}
}
system("color CF");
getch();
	return 0;
	
	
	
}
