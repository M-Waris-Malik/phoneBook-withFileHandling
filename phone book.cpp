#include <iostream>
#include <fstream>
#include <sstream>
#include <windows.h>
using namespace std;

class PhoneBook{
private:
string Name, PhNo, Address;
public:
PhoneBook():Name(""), PhNo(""), Address(""){}

setName(string name){
Name = name;
}

setPhNo(string phNo){
 PhNo = phNo;
} 

setAddress(string address){
 Address = address;
}

string getName(){
 return Name;
}

string getPhNo(){
 return PhNo;
}

string getAddress(){
 return Address;
}
};

addNo(PhoneBook ph){
system("cls");
string name, phNo, address;

cout<<"\tEnter Name Of User: ";
cin>>name;
ph.setName(name);

 cout<<"\tEnter Phone Number: ";
 cin>>phNo;
 ph.setPhNo(phNo);
 
 cout<<"\tEnter Address Of User: ";
 cin>>address;
 ph.setAddress(address);
 
ofstream outfile("D:/PhoneBook.txt", ios::app);
if(!outfile){
cout<<"\tError: File Can't Open!"<<endl;
}
else{
outfile<<"\t"<<ph.getName()<<" : "<<ph.getPhNo()<<" : "<<ph.getAddress()<<endl<<endl;

}
outfile.close();
cout<<"\tPhone Number Added To Phone Book!";
Sleep(3000);
}

searchNo(){
	system("cls");
string name;
cout<<"\tEnter Name Of User: ";
cin>>name;

ifstream infile("D:/PhoneBook.txt");
if(!infile){
cout<<"\tError: File Can't Open!"<<endl;
}
else{
string line;
bool found = false;
while(getline(infile, line)){
stringstream ss;
ss<<line;
string userName, userPhNo, userAddress;
char delimiter;
ss>>userName>>delimiter>>userPhNo>>delimiter>>userAddress;

if(name == userName){
found = true;
cout<<"\t"<<userName<<"\t"<<userPhNo<<"\t"<<userAddress<<endl;	
}
}
if(!found){
cout<<"\tUser Not Found In Phone Book!"<<endl;
}
}
infile.close();
Sleep(5000);
}

int main(){
PhoneBook ph;

bool exit = false;
while(!exit){
system("cls");
int val;
cout<<"\tWelcome To Phone Book Management System"<<endl;
cout<<"\t***************************************"<<endl;
cout<<"\t1.Add Number."<<endl;
cout<<"\t2.Search Number."<<endl;
cout<<"\t3.Exit."<<endl;
cout<<"\tEnter Your Choice: ";
cin>>val;

if(val==1){
addNo(ph);	
}

else if (val==2){
searchNo();
}

else if(val==3){
system("cls");
exit = true;
cout<<"\tGood Luck!"<<endl;
Sleep(3000);
}
}	
}
