#include <iostream>
#include <iomanip>		//2 decimal number
#include <string>
#include <windows.h>	//sleep(delay the output) and colour
#include <ctime>		//time
using namespace std;

	//For using colour text 
	HANDLE h= GetStdHandle(STD_OUTPUT_HANDLE);
	
	//function prototype
	void header(); 														//void function without parameter
	void moneyChange(double, double);									//void function with parameter
	float price(float total); //totalprice (listed items in receipt)	  return function with parameter
	int adminchoice();													//return function without parameter
	
	//Products Name
	char burger1[]="Chicken burger", burger2[]="Cheeseburger", burger3[]="Spicy Chicken Burger", burger4[]="Double Chicken burger", burger5[]="Double Cheeseburger", burger6[]="Double Spicy Chicken Burger";
	char drinks1[]="Chocolate",drinks2[]="Strawberry",drinks3[]="Grape",drinks4[]="Lemonade";
	char sided1[]="French Fries", sided2[]="Mashed Potatoes", sided3[]="Coleslaw",sided4[]="Twister Fries";
	
	//declare variable
	float total=0,totaltax=0,grandTotal=0,profit;
	int choice=0,pchoice1,quantity,customercounter=0,i=0,a=0,totalquantity[100],limit=0,choiceadmin,back;
	string allorder[100],price1[100],restart;
	double aftertax,pay,change=0,totalorder[100];
	char name[100];

int main()
{	
	//Start of while loop at started program(Sentinel)
	while(restart!="-1")
	{
	//do..while loop
		do{
		//Main menu
		system("CLS");
			header();
			cout<<"					        MAIN MENU\n\n";
			cout<<"					    1)Make an order\n";
			cout<<"					    2)Daily report sales\n";
			cout<<"					    3)Exit program\n\n\n\t\t\t\t\tPlease Enter Input : ";
			choiceadmin = adminchoice();			//take value from return function adminchoice()
			//validation check
			while(choiceadmin>3||choiceadmin<1)
			{
				cout<<"\t\t\t\t\tPlease Enter Correct Input: ";
				cin>>choiceadmin;
			}
			// Multiple Ways Selection 
			if(choiceadmin==1)
				goto main;						//go to make order menu
			else if(choiceadmin==2)				//go to daily report sales
			{		
				cout << "\n\n\n\n\n\n		       Calculating Today Sales ";
				for ( a = 1; a <= 2; a ++)		//for loop
				{
					Sleep(1100);				//Delay Today Sales for a second (ms) Output
					cout << "...";
				}
			system("CLS");
			
				//calculation for profit
				profit = grandTotal - totaltax;
					
				header();
				cout<<"	 			        Today Amount of customer : "<<customercounter<<"\n\n\n";
				cout<<"					 Grand Total: RM "<<fixed<<setprecision(2)<<grandTotal<<"\n\n\n";
				cout<<"					 Tax Total: RM "<<fixed<<setprecision(2)<<totaltax<<"\n\n\n";
				cout<<"					 Profit: RM "<<fixed<<setprecision(2)<<profit<<"\n\n\n";
				cout<<"\t\t\tBack[0]";
				cin>>back;
				//validation check
				while(back!=0)
				{
					cout<<"\t\t\t\t\tPlease Enter Correct Input: ";
					cin>>back;
				}
			}
			else if(choiceadmin==3)
			{
				cout <<"\n	   	------------------------------------------------------------------------------\n";
				cout<<"\n			    THANK YOU FOR USING THIS SYSTEM AND PLEASE COME AGAIN!\n";
				cout <<"\n	   	------------------------------------------------------------------------------";
				return 0;			//End the system
			}
		} while(back==0);
	
	//Make an order menu
	main:
system("CLS");
	header();
	cout<<"\t\t\t\t\tPlease Enter Your Name: ";
	fflush(stdin);	
	cin.getline(name,100);			//input name with space
	customercounter++;				//Total Customer of the day
	
	// Nested while loop if customers want to add more orders(SENTINEL)
	while(restart!="n")
	{
	limit++; 		//array builder in main				counter
	i++; 			//array builder in main	
	//Order menu
system("CLS");
	header();
	cout<<"\t\t\t\t\t       Hello "<<name<<"\n\n\t\t\t\t\tWhat would you like to order?\n\n\n";
	cout<<"\t\t\t\t\t1) Burger\n\t\t\t\t\t2) Drinks\n\t\t\t\t\t3) Side Dish";
	cout<<"\n\n\t\t\t\t\tPlease Enter your Choice: ";
		cin>>choice;
		//validation check
		while(choice>3)
		{
			cout<<"\t\t\t\t\tPlease Enter Correct Input: ";
			cin>>choice;
		}
	// Main System 
system("CLS"); 
	if(choice==1)	//Burger Menu
	{
	header();
	cout << "\n\t        		-----------------------------------------------"<<endl;
	cout << "\t       			|                BURGER -MENU                 |"<<endl;
	cout << "\t        		-----------------------------------------------\n"<<endl;
	cout<<"\n\t\t\t\t   1) "<<burger1<<"\t		RM 16.18"<<"\n";
	cout<<"\t\t\t\t   2) "<<burger2<<"\t		RM 15.18"<<"\n";
	cout<<"\t\t\t\t   3) "<<burger3<<"\t	RM 17.18"<<"\n";
	cout<<"\t\t\t\t   4) "<<burger4<<"\t	RM 26.18"<<"\n";
	cout<<"\t\t\t\t   5) "<<burger5<<"\t	RM 25.18"<<"\n";
	cout<<"\t\t\t\t   6) "<<burger6<<"	RM 27.18"<<"\n\n";
	cout<<"\t\t\t\t   Which one do you want?:";
		cin>>pchoice1;
		//validation check
		while(pchoice1>6 || pchoice1<1)
		{
			cout<<"\t\t\t\t\tPlease Enter Correct Input?:";
			cin>>pchoice1;
		}
		cout<<"\t\t\t\t   Please Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1:                         
				allorder	  [i] = "\t\tChicken burger";		//allorder, price1, totalquantity and totalorder will add in [i] with is i++
				price1		  [i] = "   \t\t\t    RM 16.18";	//everytime customer want to add more orders
				totalquantity [i] =     quantity;
				totalorder    [i] = 16.18*quantity;
				break;
			case 2:                    
				allorder	  [i] = "\t\tCheese Burger";
				price1		  [i] = "   \t\t\t    RM 15.18 ";
				totalquantity [i] =     quantity;
				totalorder    [i] = 15.18*quantity;
				break;
			case 3:			                                          
				allorder	  [i] = "\t\tSpicy Chicken Burger";
				price1		  [i] = "   \t\t\t    RM 17.18 ";
				totalquantity [i] =     quantity;
				totalorder    [i] = 17.18*quantity;
				break;
			case 4:                           
				allorder	  [i] = "\t\tDouble Chicken burger";
				price1		  [i] = "   \t\t    RM 26.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 26.18*quantity;
				break;
			case 5:                           
				allorder	  [i] = "\t\tDouble Cheeseburger";
				price1		  [i] = "   \t\t\t    RM 25.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 25.18*quantity;
				break;	    	
			case 6:                           
				allorder	  [i] = "\t\tDouble Spicy Chicken Burger";
				price1		  [i] = "   \t\t    RM 27.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 27.18*quantity;
				break;
			}		    	
	}
	else if(choice==2)	//Drink menu
	{
	header();
	cout << "\n\t        		-----------------------------------------------"<<endl;
	cout << "\t       			|               BEVERAGES-MENU                |"<<endl;
	cout << "\t        		-----------------------------------------------\n"<<endl;
	cout<<"\n\t\t\t\t\t1) "<<drinks1<<"		RM 8.18"<<"\n";
	cout<<"\t\t\t\t\t2) "<<drinks2<<"		RM 6.18"<<"\n";
	cout<<"\t\t\t\t\t3) "<<drinks3<<"	    	RM 5.18"<<"\n";
	cout<<"\t\t\t\t\t4) "<<drinks4<<"		RM 7.18"<<"\n\n";
	cout<<"\t\t\t\t\tWhich one do you want?:";
		cin>>pchoice1;
		//validation check
		while(pchoice1>4 || pchoice1<1)
		{
			cout<<"\t\t\t\t\tPlease Enter Correct Input?:";
			cin>>pchoice1;
		}
		cout<<"\t\t\t\t\tPlease Enter Quantity: ";
			cin>>quantity;
		switch(pchoice1)
			{
			case 1:                           
				allorder	  [i] = "\t\tChocolate";
				price1		  [i] = "   \t\t\t\t    RM 8.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 8.18*quantity;
				break;
			case 2:                    
				allorder	  [i] = "\t\tStrawberry";
				price1		  [i] = "   \t\t\t\t    RM 6.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 6.18*quantity;
				break;
			case 3:			                                          
				allorder	  [i] = "\t\tGrape";
				price1		  [i] = "   \t\t\t\t    RM 5.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 5.18*quantity;
				break;
			case 4:                           
				allorder	  [i] = "\t\tLemonade";
				price1		  [i] = "   \t\t\t\t    RM 7.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 7.18*quantity;
				break;
			}		    	
	}
	else if(choice==3)	//Side Dish Menu
	{
	header();
	cout << "\n\t        		-----------------------------------------------"<<endl;
	cout << "\t       			|              SIDE DISH -MENU                |"<<endl;
	cout << "\t        		-----------------------------------------------\n"<<endl;
	cout<<"\n\t\t\t\t   1) "<<sided1<<"		RM 6.18"<<"\n";
	cout<<"\t\t\t\t   2) "<<sided2<<"		RM 5.18"<<"\n";
	cout<<"\t\t\t\t   3) "<<sided3<<"\t		RM 4.18"<<"\n";
	cout<<"\t\t\t\t   4) "<<sided4<<"\t	RM 8.18"<<"\n\n";
	cout<<"\t\t\t\t   Which one do you want?:";
		cin>>pchoice1;
		//validation check
		while(pchoice1>4 || pchoice1<1)
		{
			cout<<"\t\t\t\t\tPlease Enter Correct Input?:";
			cin>>pchoice1;
		}
		cout<<"\t\t\t\t   Please Enter Quantity: ";
			cin>>quantity;
			switch(pchoice1)
			{
			case 1:                       
				allorder	  [i] = "\t\tFrench Fries";
				price1		  [i] = "   \t\t\t\t    RM 6.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 6.18*quantity;
				break;
			case 2:                    
				allorder	  [i] = "\t\tMashed Potatoes";
				price1		  [i] = "   \t\t\t    RM 5.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 5.18*quantity;
				break;
			case 3:			                                          
				allorder	  [i] = "\t\tColeslaw";
				price1		  [i] = "   \t\t\t\t    RM 4.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 4.18*quantity;
				break;
			case 4:                           
				allorder	  [i] = "\t\tTwister Fries";
				price1		  [i] = "   \t\t\t    RM 8.18";
				totalquantity [i] =     quantity;
				totalorder    [i] = 8.18*quantity;
				break;
			}		    	
	}
	
	//Loop if customer want to add more orders
	cout<<"\n				Would you like to make another other? y/n: ";
	cin>>restart;
	}
	//Finalizing Customer Order
	cout << "\n\n				Finalizing Order";
		for ( a = 1; a <= 2; a ++)
		{
			Sleep(1200);		//Delay Receipt for a second (ms) Output
			cout << "...";
		}
	//List Of Customer Order
system("CLS");
	header();
	cout << "\n  					     You have ordered: \n";
	cout <<"		 ------------------------------------------------------------------------------\n";	
	cout <<"		"<<"  QUANTITY |\tITEM\t\t\t\t\t| UNIT PRICE |\tTOTAL\n";
	cout <<"		 ------------------------------------------------------------------------------\n";	
	
		//will display quantity, item name, unit price and total in loop of [i] until there is no order
		for(i=1;i<=limit;i++)
			cout <<"\t\t     "<<totalquantity[i] <<allorder[i] <<price1[i]<<"\tRM"  <<fixed<<setprecision(2)<<totalorder[i] <<"\n";
				
	cout <<"		 ------------------------------------------------------------------------------\n";
	cout <<"							    TOTAL WITH TAX (18%) :    RM "<<fixed<<setprecision(2)<<price(total)*1.18<<endl;
	cout <<"		 ------------------------------------------------------------------------------\n\n";
	//User Enter Amount Of Cash
	SetConsoleTextAttribute(h,2); //green
	cout <<"                                       ¦¦  ¦¦                                        \n";
	cout <<"                                       ¦¦  ¦¦                                        \n";
	cout <<"                                   ¦¦¦¦¦¦¦¦¦¦¦¦                                      \n";
	cout <<"                                 ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                    \n";
	cout <<"                               ¦¦¦¦    ¦¦  ¦¦  ¦¦¦¦                                  \n";
	cout <<"                               ¦¦¦¦    ¦¦  ¦¦  ¦¦¦¦                                  \n";
	cout <<"                               ¦¦¦¦    ¦¦  ¦¦                                        \n";
	cout <<"                                  ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                     \n";
	cout <<"                                   ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                    \n";
	cout <<"                                       ¦¦  ¦¦  ¦¦¦¦                                  \n";
	cout <<"                               ¦¦¦¦    ¦¦  ¦¦  ¦¦¦¦                                  \n";
	cout <<"                               ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                    \n";
	cout <<"                                 ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                                      \n";
	cout <<"                                       ¦¦  ¦¦                                        \n"; 
	cout <<"                                       ¦¦  ¦¦             ";
	SetConsoleTextAttribute(h,15);
	cout << "Please Insert Your Cash : RM ";
	cin>> pay;
	
		aftertax=price(total)*1.18;	//FORMULA FOR PRICE AFTER TAX
		
			//check if amount of money is enough
			while(pay < aftertax)
			{
				cout<< "\n		 ------------------------------------------------------------------------------\n";
				cout<<"\t\t\t                     INSUFFICIENT AMOUNT  ";
				cout<< "\n		 ------------------------------------------------------------------------------\n";
				cout<<"\t\t\t\tPlease Insert Your Cash     : RM "; 
				cin>> pay;
			}
	//Generate Receipt
	cout << "\n\n";
	cout << "		  Generating your Receipt ";
			for ( a = 1; a <= 2; a ++)
			{
				Sleep(1200);			//Delay Receipt for a second (ms) Output
				cout << "...";
			}
		cout << "\n\n\n";	
	//RECEIPT	
system("CLS");
	header();
	cout << "\t\t\t\t\t\tRECEIPT\n";
		//Date
		time_t now = time(0);
   		tm *ltm = localtime(&now);
  		cout << "		  Date: "<<  ltm->tm_mday <<" / ";
 		cout << 1 + ltm->tm_mon <<" / ";
 		cout << 1900 + ltm->tm_year << "\t\t\t\t\t\t";
 		//Time
  		cout << "Time: "<< ltm->tm_hour << ":";
   		cout <<  ltm->tm_min << ":";
 		cout << ltm->tm_sec << "\n";
		cout << "		  Customer name    : " <<name<<endl;
		cout << "		  Order number     : PT" <<customercounter<<endl;		//the number of customer
	cout <<"		 ------------------------------------------------------------------------------\n";	
	cout <<"		"<<"  QUANTITY |\tITEM\t\t\t\t\t| UNIT PRICE |\tTOTAL\n";
	cout <<"		 ------------------------------------------------------------------------------\n";	
				
		//will display quantity, item name, unit price and total in loop of [i] until there is no order
		for(i=1;i<=limit;i++)
		cout <<"\t\t     "<<totalquantity[i] <<allorder[i] <<price1[i]<<"\tRM "  <<fixed<<setprecision(2)<<totalorder[i] <<"\n";
	
	//total tax and grand total will be added
	grandTotal += price(total)*1.18;	//grandTotal = grandTotal + price(total)*1.18;
	totaltax += price(total)*0.18;
	
	cout <<"\n\t\t  Subtotal\t\t\t\t\t\t\t\tRM "<<fixed<<setprecision(2)<<price(total)<<endl;
	cout <<"\t\t  Total Tax (18%)\t\t\t\t\t\t\tRM "<<fixed<<setprecision(2)<<price(total)*0.18<<endl;
	cout <<"\t\t  Total After Tax\t\t\t\t\t\t\tRM "<<fixed<<setprecision(2)<<price(total)*1.18<<endl;
	cout <<"\t\t  Cash Tendered\t\t\t\t\t\t\t\tRM "<<fixed<<setprecision(2)<<pay<<endl;
	moneyChange(pay,aftertax);
	cout <<"		 ------------------------------------------------------------------------------";
	cout<<"\n			    THANK YOU FOR YOUR PURCHASE AND PLEASE COME AGAIN!";
	cout<<"\n\t\t\t\tPLEASE ENTER ANY INPUT TO GO TO MAIN MENU.\n";
	cout <<"		 ------------------------------------------------------------------------------\n";
	cout<<"						Back[0]";
	limit=0;	//Reset Order
	i=0;    	//Reset Array Builder
	cin>>restart;	//Loop System For New Customer
	}
	//End of loop
}

//header display
void header(){																//void function without parameter
		SetConsoleTextAttribute(h,6); 			//colour brown
		cout << "\t\t\t      ¦¦¦¦¦¦¦¦¦¦                             \n";
		cout << "\t\t\t    ¦¦          ¦¦                           \n";
		cout << "\t\t\t   ¦¦            ¦¦                          \n";
		SetConsoleTextAttribute(h,2); 			//colour green
		cout << "\t\t\t ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                BURGER'S\n";
		SetConsoleTextAttribute(h,4); 			//colour red
		cout << "\t\t\t ¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦                HOUSE   \n";
		SetConsoleTextAttribute(h,6); 			//colour brown
		cout << "\t\t\t  ¦¦              ¦¦                         \n";
		cout << "\t\t\t    ¦¦¦¦¦¦¦¦¦¦¦¦¦¦                           \n";
		SetConsoleTextAttribute(h,15);			//colour white
		cout <<"\t\t=============================================================================\n\n";
		
}

//money change calculation (function definition)
void moneyChange(double cash, double totalWithTax){									//void function with parameter
	change = cash-totalWithTax;	//FORMULA FOR Changed with Tax
	cout <<"\t\t  Change\t\t\t\t\t\t\t\tRM "<<fixed<<setprecision(2)<<change<<endl;
}

//Price calculation (function definition)
float price(float total){															//return function with parameter
		for(i = 1; i <= limit; i++)
	{
		total = total + totalorder[i];
	}
		return total;
}

//to get input from user and return value
int adminchoice(){																	//return function without parameter
	int adminchoice;
	cin>>adminchoice;
	while(adminchoice>3||adminchoice<1)
		{
			cout<<"\t\t\t\t\tPlease Enter Correct Input: ";
			cin>>adminchoice;
		}
	return adminchoice;
}
