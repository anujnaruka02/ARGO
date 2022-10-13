#include <iostream>
#include <mysql.h>  // These libraries were added by including folders to project options
#include <mysqld_error.h>  // and this particularly, when pasting the ".dll" to the project folder

using namespace std;

char HOST[] = "localhost";
char USER[] = "root";
char PASS[] = "1965";


int main() {
	
	MYSQL* obj;                      // One to manage MySQL session
	
	int S_No;
	char First_Name[20];
	char Last_Name[20];
	char Address[20];
	char Contact_No[20];
	char Type_Of_Vehicle[20];
	char Availability[20];
    char Name_Of_Seller[20];
    char Duration[20];
    char Billable_Amount[20];
		
	bool ProgramIsOpened = true;
	int answer;                     // These are for keeping the program opened
	
	char* consult;
	char* sentence;
	string sentence_aux;           // These are to add data to the table
	
//------------------------------------
// Connection
    if(!(obj = mysql_init(0)))
	{
    	cout << "ERROR: MySQL object could not be created." << endl;
	}
	else
	{
		if(!mysql_real_connect(obj, HOST, USER, PASS, "MINPROJ", 3306, NULL, 0))
		{
			cout << "ERROR: Some database info is wrong or do not exist." << endl;
			cout << mysql_error(obj) << endl;
		}
		else
		{
			cout << "Logged in." << endl << endl;
			
			while(ProgramIsOpened)
			{
				cout << "S_No: ";
				cin>> S_No;
				cin.ignore(100, '\n'); //Remember to clean your buffer after using cin for int, float and double.
				
				cout << "First Name: ";
				cin.getline(First_Name, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
				
				cout << "Last Name: ";
				cin.getline(Last_Name, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
				
				cout << "Address: ";
				cin.getline(Address, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
                
				cout << "Contact No: ";
				cin.getline(Contact_No, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
                
				cout << "Vehicle Type : ";
				cin.getline(Type_Of_Vehicle, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.				
				
				cout << "Availability : ";
				cin.getline(Availability, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
				
				cout << "Seller's Name : ";
				cin.getline(Name_Of_Seller, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
				
				cout << "Duration : ";
				cin.getline(Duration, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
				cout << endl;
                
                
				cout << "Billable Amount : ";
				cin.getline(Billable_Amount, 100, '\n'); // We don't use cin >> NAME because it doesn't read spaces.
				cout << endl;				
				
				
				// Setting our update
				
				sentence_aux = "INSERT INTO MAIN_SERVER(S_No, First_Name,Last_Name,Address,Contact_No, Type_Of_Vehicle, Availability, Name_Of_Seller, Duration, Billable_Amount) VALUES('%d', '%s', '%s','%s','%s','%s','%s','%s', '%s','%s')";
				sentence = new char[sentence_aux.length()+1];
				strcpy(sentence, sentence_aux.c_str());  // We copy our string statement into a *char.
				
				consult = new char[strlen(sentence) + sizeof(int) + strlen(First_Name)+ strlen(First_Name)+ strlen(Address)+ strlen(Type_Of_Vehicle)+ strlen(Availability)+ strlen(Name_Of_Seller)+ strlen(Duration)+ strlen(Billable_Amount)];
				sprintf(consult, sentence, S_No, First_Name,Last_Name,Address,Contact_No,Type_Of_Vehicle,Availability,Name_Of_Seller,Duration, Billable_Amount);  // Substitutes %d... for actual values.
				
				// Make our attempt.
				
				if(mysql_ping(obj))
				{
					cout << "ERROR: Impossible to connect." << endl;
					cout << mysql_error(obj) << endl;
				}
				
				if(mysql_query(obj, consult))
				{
					cout << "ERROR: " << mysql_error(obj) << endl;
					rewind(stdin);
					getchar();
				}
				else
				{
					cout << "Info added correctly." << endl;
				}
				mysql_store_result(obj);
				
				cout << endl << "Another?" << endl;
				cout << "[1]: Yes" << endl;
				cout << "[0]: No" << endl;
				cout << "Answer: ";
				cin>>answer;
				cin.ignore(100, '\n');
				if(answer == 0)
				{
					ProgramIsOpened = false;
				}
				cout << endl;
			}
		}
	}
	
	cout << "THANK YOU" << endl;
	
	return 0;
}
