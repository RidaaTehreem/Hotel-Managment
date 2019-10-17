#include<iostream>
#include<string.h>
#include<fstream>
using namespace std;

string name;
string sname;
string phone_no;
string cnic;
string booking_from_date;
string booking_to_date;

char address[60];
fstream booking_record;
fstream check_in_record;
fstream check_out_record;
void booking();
void Record_Check_In();
void check_out_record1();
void check_in_summary();
void check_out_summary();
void booking_summary();
int main()
{  
	int a;
	char ch;
	int choice;
	cout<<"================================================================================"<<endl;
	cout<<"                           Hotel Management System"<<endl;
	cout<<"================================================================================"<<endl<<endl;
	do
	{
	cout<<"Select one of the following options:-"<<endl;
	cout<<"1: Booking"<<endl;
	cout<<"2: Check in record"<<endl;
	cout<<"3: Print bill"<<endl;
	cout<<"4: Print summary"<<endl;
	cout<<"5: Exit "<<endl;
	cout<<"Enter your choice: ";
	cin>>choice;
	switch(choice)
	{
		case 1:
			{
				booking();
   			    break;		
			}
		case 2:
		    {
			   	Record_Check_In();
			   	break;
			}	
		case 3:
		    {
				check_out_record1();//and bill print
				break;
			}	
		case 4:
			{ 
			 cout<<"Enter '7' for booking  summary"<<endl;
			 cout<<"Enter '8' for check in summary"<<endl;
			 cout<<"Enter '9' for check out summary"<<endl;
			 cin>>a;
			 if(a==7)
			 	{
				 	booking_summary();
			 	}
			 else if(a==8)
				 {	check_in_summary();
			 	  
			 	}
			 else if(a==9)
			 {
			  check_out_summary();
			 }
			 else
			{
				cout<<"Invalid input"<<endl;
			}	
			break;	
			}	
			case 5:
				{
					break;
				}
		default:
		    {
				cout<<"Invalid input"<<endl;
				break;
			}		
	  }	
	  	cout<<"======================================="<<endl;
		cout<<"Do you want to continue program? "<<endl;
	    cout<<"Press \'Y\' to continue"<<endl;
	    cout<<"Press \'any key\' to exit"<<endl;
	    cin>>ch;
	    cout<<"======================================="<<endl;
    }  
    while(ch=='Y'||ch=='y');
    
	return 0;
}


void booking()
{ 
	char ch;
	booking_record.open("Booking record.txt",ios::app);
	
	do
   	{	
 		cout<<"Enter CNIC: "<<endl;
		cin>>cnic;
		int x=cnic.length();
		if (x!=13)
		{
			cout<<"Wrong input!"<<endl;
			break;
		}
		 else
		 {
	  
		cout<< "Enter first name of guest: "<<endl;
	
		{
		
		cout<<"Anum"<<endl;
	} 
	
	{ cout<<name<<endl;
	}
		cout<<"Enter second name of guest: "<<endl;
		cin>>sname;
		cout<<"Enter phone number: "<<endl;
		cin>>phone_no;
		cout<<"Enter address: "<<endl;
		cin>>address;
		cout<<"Enter booking from date: "<<endl;
		cin>>booking_from_date;
		cout<<"Enter booking to date: "<<endl;
		cin>>booking_to_date;	
	    booking_record<<name<<"\t"<<sname<<"\t"<<cnic<<"\t"<<phone_no<<"\t"<<address<<"\t"<<booking_from_date<<"\t"<<booking_to_date<<endl;
	    cout<<"**********************************"<<endl;
		cout<<"Do you want to enter again? "<<endl;
	    cout<<"Press \'Y\' to enter a new record"<<endl;
	    cout<<"Press \any key\' to exit"<<endl;
	    cin>>ch;
	    cout<<"THANK YOU!";
	    cout<<"**********************************"<<endl;
    }
}
    while(ch=='Y'||ch=='y');
  		cout<<"Records have been saved successfully..."<<endl;
  		booking_record.close();
	
}


void Record_Check_In()
{
	string booking_to;
    string booking_from;
	string cnic;
	string name;
	string sname;
	string check_in_date;
	string CNIC;
	string address;
	string phone;
	float advance;
	char choice;
	cout<<"Do you have booking in hotel ?"<<endl;
	cout<<"Press \'Y\' for YES"<<endl;
	cout<<"Press \'N\' for NO"<<endl;
	cin>>choice;
	if(choice=='y'||choice=='Y')
	{
		cout << "Enter guest CNIC" <<endl;
		cin >> cnic;
		int a=cnic.length();
		if(a=13)
		{
		
		booking_record.open("Booking record.txt",ios::in);
		while (booking_record>>name>>sname>>CNIC>>phone_no>>address>>booking_from>>booking_to) 
		{	
	        if (cnic==CNIC)
	 		{	
			 	cout<<"Already booking in hotel"<<endl;
	            cout<<"Enter check in date: "<<endl;
	            cin>>check_in_date;
	            cout << "Enter advance payment: " <<endl;
	            cin>>advance;
	            fstream check_in_record;
	    		check_in_record.open("Check_In_Record.txt",ios::app); 
	   		    check_in_record<<name<<"\t"<<sname<<"\t"<<cnic<<"\t"<<phone_no<<"\t"<<address<<"\t"<<check_in_date<<"\t"<<advance<<endl;
				check_in_record.close();
				booking_record.close();
				cout << "Guest's check in record maintained successfully..." <<endl;
	  		}
		}
		
	  		if(cnic!=CNIC)
	  		{
			  cout<<"Record not found..."<<endl;
			}
		}
		else
		{
			cout<<"Wrong input"<<endl;
		}
	}
       	else if(choice=='n'||choice=='N')
       {
        
        	cout<<"Enter new record..." << endl;
        	cout<<"Enter CNIC: "<<endl;
			cin>>cnic;
			int a=cnic.length();
		if(a=13)
		{
			cout<<"Enter the name of guest: "<<endl;
			cin>>name;
			cout<<"Enter second name: "<<endl;
			cin>>sname;
			
			cout<<"Enter phone number: "<<endl;
			cin>>phone_no;
			cout<<"Enter address: "<<endl;
			cin>>address;
            cout<<"Enter check in date: "<<endl;
            cin>>check_in_date;
            cout << "Enter advance payment: " <<endl;
            cin >>advance;
            fstream check_in_record;
    		check_in_record.open("Check_In_record.txt",ios::app); 
            check_in_record<<name<<"   "<<sname<<"   "<<cnic<<"   "<<phone_no<<"   "<<address<<"   "<<check_in_date<<"   "<<advance<<endl;
			check_in_record.close();
			cout << "Guest's check in record maintained successfully..." <<endl;
	}
   }
   else
   		{
   			cout<<"Invalid choice..."<<endl;
		   }
        	
}


void check_out_record1()
 { 
    string cnic;
	string name;
	string sname;
	string check_In_date;
	string check_out_date;
	string check_in_date;
	string address;
	string phone;
	string CNIC;
	float advance,n;
	double payable_bill;
	int per_day_rent,c=0;
	int no_days;
	double tBill;
	check_in_record.open("check_In_record.txt",ios::in);
	cout << "Enter guest CNIC to check out and print bill " <<endl;
	cin >> cnic;
	int a=cnic.length();
		if(a=13)
		{
	cout<<"Enter check out date: "<<endl;
	cin>>check_out_date;
	 while (check_in_record>>name>>sname>>CNIC>>phone>>address>>check_in_date>>advance) 
	{
	if(CNIC==cnic) 
		{
			
			cout<<"\t\t**************************"<<endl;
		    cout<<"\t\t   customer Bill"<<endl;
			cout<<"\t\t**************************"<<endl;
            cout<<"Enter the no of days stayed in the hotel: "<<endl;
			cin>>no_days;
			cout<<"Enter the rent per day: "<<endl;
			cin>>per_day_rent;
			n=no_days*per_day_rent;
			tBill=((n)-(advance));
			if((n)<advance)
	  		   	{   cout<<"Guest name: "<<name<<" "<<sname<<endl;
					cout<<"Address: "<<address<<endl;  
					cout<<"Phone no: "<<phone<<endl;		
					cout<<"No of days stayed in the hotel: "<<no_days<<endl;
					cout<<"Total bill due: "<<n<<endl;
					cout<<"Advance paid: "<<advance<<endl;
					cout<<"==============================================="<<endl;
					cout<<"Payable bill is: RS 0"<<endl;
					cout<<"Customer's remaining balance is: RS "<<(-1)*tBill<<endl;
					cout<<"==============================================="<<endl;
            	 }
			else
				{ 	
					cout<<"========================================"<<endl;
				    cout<<"Guest name: "<<name<<" "<<
					sname<<endl;
					cout<<"Address: "<<address<<endl;  
					cout<<"Phone no: "<<phone<<endl;	
					cout<<"No of days stayed in the hotel:  "<<no_days<<endl;
					cout<<"Advance paid: RS "<<advance<<endl;
					cout<<"Total bill due: "<<n<<endl;
					cout<<"========================================="<<endl;
					cout<<"Payable bill is: RS "<<tBill<<endl;
					cout<<"========================================="<<endl;
				}
				c++;
		}
   	}
     	//while (check_in_record>>name>>sname>>CNIC>>phone>>address>>check_in_date>>advance) 
     	{
		 if(c==0)
	        {
	        	cout << cnic << "Record not found!!!!..........." << endl;
			}
}
        }
check_in_record.close();
	fstream temp;
	check_out_record.open("check_out_record.txt",ios::app);
	temp.open("Temp.txt",ios::out);
	check_in_record.open("check_In_record.txt",ios::in);
	while (check_in_record>>name>>sname>>CNIC>>phone>>address>>check_In_date>>advance ) 
    
	{  if(cnic==CNIC)
	    {
	  	check_out_record<<name<<"\t"<<sname<<"\t"<<CNIC<<"\t"<<phone<<"\t"<<address<<"\t"<<check_out_date<<"\t"<<no_days<<"\t"<<n<<"\t"<<tBill<<endl;
		}
		
		else
		{
			temp<<name<<"\t"<<sname<<"\t"<<CNIC<<"\t"<<phone<<"\t"<<address<<"\t"<<check_In_date<<"\t"<<advance<<endl;
		}
	}
    check_out_record.close();   
    temp.close();
    check_in_record.close();
    check_in_record.open("check_In_record.txt",ios::out);
    temp.open("Temp.txt",ios::in);
    
   	while (temp>>name>>sname>>CNIC>>phone>>address>>check_In_date>>advance)	   
	{
	check_in_record<<name<<"\t"<<sname<<"\t"<<CNIC<<"\t"<<phone<<"\t"<<address<<"\t"<<check_In_date<<"\t"<<advance<<endl;
    }   
	   
	   temp.close();
    check_in_record.close();  
	}
    

void check_out_summary()
{
	check_out_record.open("check_out_record.txt",ios::in);
	string line;	
	        cout<<"\t\t**************************"<<endl;
		    cout<<"\t\t   Check_out_record"<<endl;
			cout<<"\t\t**************************"<<endl;
	
			cout<<"NM:for name\tsNm:for sname  \t id:for CNIC\tph:for Phone no\tAd for address\tco:for check out date\tNd:for no of days\tTb:for total bill \t Pb:paid bill"<<endl;
	        cout<<"=================================================================================================================================================================="<<endl;
            cout<<"NM"<<"\t"<<"sNm"<<"\t"<<"id"<<"\t"<<"Ph"<<"\t"<<"Ad"<<"\t"<<"co "<<"\t"<<"Nd "<<"\t"<<"Tb"<<"\t"<<"Pb"<<endl;
			cout<<"=================================================================================================================================================================="<<endl;	
   
	
	      while (getline(check_out_record, line)) 
	    	{
			cout<<line<<endl;
	    }
   check_out_record.close();			
}


void booking_summary()
{
	booking_record.open("Booking record.txt",ios::in);
	string line;
	
	        cout<<"\t\t**************************"<<endl;
		    cout<<"\t\t   booking_record"<<endl;
			cout<<"\t\t**************************"<<endl;
     		cout<<"NM:for name\tsNm:for sname  \t id:for CNIC\tph:for Phone no\tAd for address\tBD:for Booking to date"<<endl;
	        cout<<"=================================================================================================================================================================="<<endl;
            cout<<"NM"<<"\t"<<"sNm"<<"\t"<<"id"<<"\t"<<"Ph"<<"\t"<<"Ad"<<"\t"<<"BD "<<"\t"<<"BT "<<endl;
			cout<<"=================================================================================================================================================================="<<endl;	
   
		   	 while (getline(booking_record, line)) 
				{		
					cout<<line<<endl;  
				}
				booking_record.close();
}


void check_in_summary()
{
	check_in_record.open("Check_In_Record.txt",ios::in);
	string line;
	
	        cout<<"\t\t**************************"<<endl;
		    cout<<"\t\t   Check_in_record"<<endl;
		
			cout<<"\t\t**************************"<<endl;
	     	cout<<"NM:for name\tsNm:for sname  \t id:for CNIC\tph:for Phone no\tAd for address\tci:for check in date\tAd:for advance"<<endl;
	        cout<<"=================================================================================================================================================================="<<endl;
            cout<<"NM"<<"\t"<<"sNm"<<"\t"<<"id"<<"\t"<<"Ph"<<"\t"<<"Ad"<<"\t"<<"ci "<<"\t"<<"Ad "<<endl;
			cout<<"=================================================================================================================================================================="<<endl;	
          cout<<"sdfghjdewrdiuwqhdsoiq";
  
	  while (getline(check_in_record, line)) 
	{	
	  	cout<<line<<endl;
    
	}
	check_in_record.close();	
			
}



