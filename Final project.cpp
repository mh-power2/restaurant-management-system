#include <iostream>
#include <string>
#include<stdlib.h>
using namespace std;


struct client 	 //obviously the client's data.
{
	string mobile;
	string name;
	string address,d;
};


client read_return (client& c) 	//reads the client's data
{
	cout << "Enter mobile\n";
	cin >> c.mobile;
	system("CLS");
	cin.ignore();
	cout << "Enter name\n";
	getline(cin, c.name);
	system("CLS");
	cout << "Enter address\n";
	getline(cin, c.address);
	system("CLS");

	return c;
}


struct employee		//employee's data.
{
	int id = 0;
	double salary = 0;
	string name;
};


string password;	 //global variable for password

int n,i=0;		//n is the number of employees 	// i is the counter for the loop which adds employees, why?	because if I didn't make it global it will overwrite existing employees when you try to increase the existing employees. 

int* Num = &n;  //I don't even remember what is this for.

bool firsttime = true;  //cheaks if it is first time we add employee 	//used in add employee function. 

employee* temp; //a pointer which we will use to create a dynamic array in the add employee function

employee* R;  //a pointer which we will use to create a dynamic array // needed in the remove employee function



void mainmenu(); //the main menu of the program

void login();  //the login function used for the management section

void managment();	//the management section

void ReadMenu(); 	//the client section

void password1();  //used to read password

void welcome();   //used to show the "buger king" ASCII art

void addemp();    // used to add employees

void showemp();  // used to show employees

void modemp();   //used to modifiy existing employees

void removeemp();  //used to fire existing employees





int main()  // the main function
{
	welcome();  //here we call the welcome screen
	mainmenu(); // now we call the main menu
	
	return 0;
}




void welcome() //the function used for welcome
{
	system("Color 0E"); //the console colour // 0 is black // E is yellow
	
	cout << R"(
 ________  ___  ___  ________  ________  _______   ________          ___  __    ___  ________   ________
|\   __  \|\  \|\  \|\   __  \|\   ____\|\  ___ \ |\   __  \        |\  \|\  \ |\  \|\   ___  \|\   ____\
\ \  \|\ /\ \  \\\  \ \  \|\  \ \  \___|\ \   __/|\ \  \|\  \       \ \  \/  /|\ \  \ \  \\ \  \ \  \___|
 \ \   __  \ \  \\\  \ \   _  _\ \  \  __\ \  \_|/_\ \   _  _\       \ \   ___  \ \  \ \  \\ \  \ \  \  ___
  \ \  \|\  \ \  \\\  \ \  \\  \\ \  \|\  \ \  \_|\ \ \  \\  \|       \ \  \\ \  \ \  \ \  \\ \  \ \  \|\  \
   \ \_______\ \_______\ \__\\ _\\ \_______\ \_______\ \__\\ _\        \ \__\\ \__\ \__\ \__\\ \__\ \_______\
    \|_______|\|_______|\|__|\|__|\|_______|\|_______|\|__|\|__|        \|__| \|__|\|__|\|__| \|__|\|_______|



)" << '\n' << endl << "Welcome to Burger King!\n\n";

}




void managment() // the management menu

{
	cout << "\n1-Add employee\n";
	cout << "2-Show employee\n";
	cout << "3-Modify information\n";
	cout << "4-Fire employee.\n";
	cout << "5-Return to main menu.\n";

q:

	int c;
	cin >> c;

	if (cin.fail())  //checks if the entered value is an integer number or not
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer next time.\n" << endl;
		goto q;
	}

	system("CLS"); //clears screen

	switch (c)  //for the choice entered
	{
	case 1:
		addemp();
		break;
	case 2:
		showemp();
		break;
	case 3:
		modemp();
		break;
	case 4:
		removeemp();
		break;
	case 5:
        welcome();
		mainmenu();
		break;
	default:
		cout << "error";
		managment();
		break;
	}
}




void login()  //the login screen for management
{
	string username;
	cout << "Enter username and password\n";
	do
	{
		cout << "Username: ";  
		cin >> username;		//reads the username
		system("CLS");			
		if (username == "admin")	//checks the username
		{
			password1();  			//read the password
			if (password == "admin")  //checks the password
			{
				cout << "Access Granted...";
				managment();
				break;
			}


			if (password != "admin")   //if he enterd password wrong two times more he will return to the main menu
			{

				for (int i = 0; i < 3; i++)
				{
					if (i <= 1)
					{
						cout << "Access Denied.....Invalid Password:\n";
						password1();
						if (password == "admin")
						{
							cout << "Access Granted...";
							managment();
							break;
						}
					}
					else
					{
						mainmenu();
					}
				}
				break;
			}
		}
		else
		{
			for (int i = 0; i < 3; i++)  // if he entered the username wrong two times more he will be returned to the main screen
			{
				if (i <= 1)
				{
					cout << "wrong username\n";
					cout << "username : ";
					cin >> username;
					system("CLS");
					if (username == "admin")
					{
						password1();
						if (password == "admin")
						{
							cout << "Access Granted...";
							managment();
							break;
						}
						if (password != "admin")
						{
							for (int i = 0; i < 3; i++)
							{
								if (i <= 1)
								{
									cout << "Access Denied.....Invalid Password:\n";
									password1();
									if (password == "admin")
									{
										cout << "Access Granted...";
										managment();
										break;
									}
								}
								else
								{
									mainmenu();
								}
							}
							break;
						}
					}
				}
				else
				{
					mainmenu();
				}
			}
			break;
		}
	} while (username == "admin");
}





void mainmenu() // the main menu
{
	w:
	cout << "1-Client mode          2-Management mode    3-Exit\n\n";
	cout << "Please Choose: \n";
	int choice;
	cin >> choice;

	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer next time.\n" << endl;
		goto w;
	}

	system("CLS");
	switch (choice)
	{
	case 1:
		ReadMenu();
		break;
	case 2:
		login();
		break;
	case 3:
		break;
	default:
		cout << "Error !!...enter another valid number \n";
		mainmenu();
		break;
	}
}




void ReadMenu() //the client menu
{
	string food[] =
	{" 1) Pizza freeska 100 L.E",  " 2) Pizza margarita 60 L.E",  " 3) Pizza sea food 80 L.E"
		," 4) Pizaa tona 55 L.E",   " 5) Pizza salami 48 L.E",   " 6) Pizaa chichen carry 60 L.E"
		," 7) Pizza meat 60 L.E",   " 8) Pizza mix cheese 50 L.E",   " 9) Prange juice 15 L.E"
		," 10) Coffee 12 L.E",   " 11) Soda 10 L.E",   " 12) Leamon 15 L.E",   " 13) Water 5 L.E"
	}; 		//the food menu

	int price[] = { 100,60,80,55,48,60,60,50,15,12,10,15,5 }; //an array which contains the price
	
	int sum = 0; //will be used to calculate the price for the order

	cout << "\nEnter the order: \n" << endl;

	cout << "1) Pizza freeska  100 L.E             2) Pizza margarita  60 L.E         3) Pizza sea food 80 L.E\n\n4) Pizaa tona 55 L.E                  5) Pizza salami 48 L.E              6) Pizaa chichen carry 60 L.E\n\n7) pizza meat 60 L.E                  8) Pizza mix cheese 50 L.E          9) orange juice 15 L.E\n\n10) coffee 12 L.E                     11) soda 10 L.E                     12) leamon 15 L.E\n\n13) water 5 L.E  \n\n0) Finish your order.\n" << endl;

	for (size_t i = 0; i < 15; i++)
	{
	V:

		cin >> i;

		if (i == 0)
		{
			break;
		}
		else

			if (i > 13 || i < 0) //error if the client enters a number outside the range of the menu
			{
				cout << "\nError\n";
				goto V;
			}


			else
			{
				cout << food[i - 1] << "    " << "price = " << price[i - 1] << endl; 	//tells him his choice after choosing 
			}

		sum = sum + price[i - 1];  // calculate the total cost of the order

	}
	
    system("CLS");
	
	cout << "total cost = " << sum << endl; //print the total cost
	cout << endl;
	l:
	int choice;
	cout << "Choose number,please? \n";
	cout << "1) Takeaway          2) Delivery\n";

	cin >> choice;
	client c;
    system("CLS");
	switch (choice)
	{

	case 1:
		cout << "Thank you for visiting our restaurant!!!\n\n";
		mainmenu();
		break;
	case 2:
		read_return(c);
		cout << "\nThank you for visiting our restaurant!!!\n";
		mainmenu();
		break;

	default:
		cout << "error";
		goto l;
		break;
	}

}




void password1() //used to read password
{
	cout << "password : ";
	cin >> password;   // password is global string
	system("CLS");
}



void addemp() //used to add employees
{
	int x,r,h;
	
	h = n;

	cout << "\nNote:If you have did this this step before you will have to increase the number of employees.\n Current employees number: "<<n<<"\n\n\nEnter the number of emplyees: \n";
	
	cin >> r; //temporary variable used to check if the number entered is rational or not, then assign it as the current employee's number // needed when you want to add employees again

	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer: \n" << endl;
		addemp();
	}

	system("CLS");

	if (r <= n)
	{
		cout << "Please use a larger number: \n";
		addemp();
	}

	else
	{
		n = r;  //assign it as the number of new employees // 
	}

	if (firsttime == true)  // checks if this is the first time he adds employees
	{

		temp = new employee[n]; //create a dynamic array whic will store employees
		
		int tempid;
		bool exist = false; //will be used in line 455 to check if the ID entered is already used by another employee

		for (i; i < n; i++) // enters the number of employee // the i is global 
		{

		m:
			cout << "Enter the emplyee number: " << i + 1 << " ID: ";
			
			cin >> tempid;

			if (cin.fail())
			{

				cin.clear();
				cin.ignore(256, '\n');

				cout << "ERROR: Invalid input. Please enter an integer: \n" << endl;
				goto m;
			}

			int k = 0;
			exist = false;
			while (exist == false && k < n) //Checks if the ID already exists.
			{
				if (tempid == temp[k].id)
				{
					exist = true;
					cout << "\nThe ID already exist, please try again: \n";
					goto m;
				}
				k++;

			}

			temp[i].id = tempid;

			cout << "Enter the emplyee number " << i + 1 << " name: ";

		u:
			cin.ignore();
			
			getline(cin, temp[i].name);
			
			if (temp[i].name > "z" || temp[i].name < "A") //only allows alphabet to be entered
			{

				cout << "The name is not valid enter another name : ";
				goto u;

			}

			h:

			cout << "Enter the emplyee number " << i + 1 << "  salary: ";
			
			cin >> temp[i].salary;

			if (cin.fail())
			{

				cin.clear();
				cin.ignore(256, '\n');

				cout << "ERROR: Invalid input. Please enter an integer: \n" << endl;
				goto h;
			}
			system("CLS");
		}

	}

	else //this works when you want to add another employees a second time or more
	{
		{
			int tempid;
			bool exist=false;//line 535

			employee* v = new employee[n];	//temporary array
			
			std::copy(temp, temp + h, v);	//copy the old array to the new array of larger size
			
			delete[] temp;	//delete the old array
			
			temp = v;	//make the old array points to the new array

			for (i; i < n; i++) //enter the employees' data
			{
			g:

				cout << "Enter the emplyee number " << i + 1 << " ID: ";
				cin >> tempid;

				if (cin.fail())
				{

					cin.clear();
					cin.ignore(256, '\n');

					cout << "ERROR: Invalid input. Please enter an integer: \n" << endl;
					goto g;
				}

				int k = 0;
				exist = false;
				while (exist == false && k < n) //checks if the ID already used
				{
					if (tempid == temp[k].id)
					{
						exist = true;
						cout << "\nThe ID already exist, please try again: \n";
						goto g;
					}
					k++;

				}

				temp[i].id = tempid;
				cout << "Enter the emplyee number " << i + 1 << " name: ";
			Y:
				cin.ignore();
				getline(cin, temp[i].name);

				if (temp[i].name > "z" || temp[i].name < "A") //checks if the name is alphabet
				{

					cout << "The name is not valid enter another name : ";
					goto Y;

				}

			l:

				cout << "Enter the emplyee number " << i + 1 << "  salary: ";
				cin >> temp[i].salary;

				if (cin.fail())
				{

					cin.clear();
					cin.ignore(256, '\n');

					cout << "ERROR: Invalid input. Please enter an integer next time.\n" << endl;
					goto l;
				}
				system("CLS");

			}

		}
	}


	firsttime = false; //line428
	
	h = n; //used in line 513 for copying the old array to a new array of larager size

x:

	cout << "\n1-Return to main menu.\n";
	cout << "2-Add emplyee.\n";
	cout << "3-Return to management menu.\n";
	cin >> x;

	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer next time.\n" << endl;
		goto x;
	}

	system("CLS");


	switch (x)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		addemp();
		break;
	case 3:
		managment();
		break;

	default :
		cout << "Error, Please enter again: \n";
		goto x;
	}



}




void showemp() //shows the existing employees' data
{
	if (n == 0) //if there is no employees
	{
		cout << "There is no employees.\n";
	}
	else
	{
		for (int i =0; i < n; i++) // print the employees' date
		{
			cout << "\nThe name of employee " << i + 1 << " is: " << temp[i].name;
			cout << "\nThe ID of employee " << i + 1 << " is: " << temp[i].id;
			cout << "\nThe salary of employee " << i + 1 << " is: " << temp[i].salary<<endl;

		}


	}


	cout<<"\n\n1-Return to main menu\t2-Return to management menu\n";

s:

	int f;
	cin>>f;

	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer:\n" << endl;
		goto s;
	}
    system("CLS");

	switch (f)
	{
	case 1:
		mainmenu();
		break;

	case 2:
		managment();
		break;
	default:
		cout << "Error,please try again.";
		goto s;
		break;
	}

}





void modemp() 	//modifiy existing employee
{
	int Id, h=0;

	cout << "\nEnter the employee ID to be modified: ";
	cin >> Id;

	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer ID: \n" << endl;
		modemp();
	}
	system("CLS");


	int i = 0;
	
	while (i < n)
	{
		if (Id == temp[i].id) //searchs for the employee using ID // if found he will be able to change the name and salary
		{
			cout << "Please enter the employee's new name: ";
		Y:
			cin.ignore();
			getline(cin, temp[i].name);

			if (temp[i].name > "z" || temp[i].name < "A") //checks if the input is alphabet
			{

				cout << "The name is not valid enter another name : ";
				goto Y;

			}
t:
			cout << "\nEnter the employee's new salary: ";
			
			cin >> temp[i].salary;

			if (cin.fail())
			{

				cin.clear();
				cin.ignore(256, '\n');

				cout << "ERROR: Invalid input. Please enter an integer next time.\n" << endl;
				goto t;
			}

			system("CLS");
			cout << "The modifications has been done successfully !!\n";
			managment();
			break;
		}

		i++;

	}
	
	if (i >= n) //if the loop and the value of is n, then it mean's that the ID doesn't exist
	{
		cout << "Employee's ID doesn't exits.\n";
		managment();

	}

}


void removeemp() //it's used to fire an existing employee
{

kk:

	R = new employee[n];  //will be used and explained in line 810
	
	int ID; //the ID of the employee to be fired

	cout << "\nPlease enter the ID of the employee to be removed.\n";

	cin >> ID;

	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer: \n" << endl;

		goto kk;
	}

	system("CLS");

	int k = 0; 

	while (k < n)
	{
		if (ID==temp[k].id)
		{
  			cout << "The employee has been fired !!\n";

			break;
		}
		k++;

	}
	
	if (k >= n)
	{
		cout << "\nThe ID doesn't exist.\n";
		managment();
	}

	for (int i = 0,j=0; i < n; i++)  	//we will copy the old array to a new array, both of the same size, but we will skip the employee which will be fired, so the last element in the new array will be zero (empty)
	{
		if (temp[i].id != ID)
		{
			R[j].id = temp[i].id;
			R[j].name = temp[i].name;
			R[j].salary = temp[i].salary;

			j++;

		}


	}

	n--; //reduce the number of existing employees by one
	
	i--; //used in adding employees

	for (int i = 0; i < n; i++) //the temp array now has a [n-1] elements // we will copy the new array back to the temp array and since the temp is smaller the new by one, the last element in the new array which is zero(empty) will be ignored
	{
		temp[i] = R[i];
    }
	delete[] R;

G:
	int G;
	cout << "\n1-Return to main menu.\n";
	cout << "2-Return to management menu.\n";
	cin >> G;


	if (cin.fail())
	{

		cin.clear();
		cin.ignore(256, '\n');

		cout << "ERROR: Invalid input. Please enter an integer next time.\n" << endl;
		goto G;
	}

	system("CLS");

	switch (G)
	{
	case 1:
		mainmenu();
		break;
	case 2:
		managment();
		break;

	default:
		cout << "Error, Please enter again: \n";
		goto G;
	}


}

