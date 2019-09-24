// Kevin Murillo
//Project1 Contact Managemente application in c++
// 2018/03/03
//Version 1.1


#include<iostream>
#include<string>
#include <ostream>
#include <istream>
using namespace std;

struct Meeting {
	int month, date, year;
};
struct Address_Contact
{
	string street_number;
	string street_name;
	string city;
	string province;
	string postal_code;
	string country;
};
struct Phone_Contact
{
	char inter_code[1];
	char country_code[3];
	char city_code[3];
	char cell_code[7];

};
struct Contact {
	int contactID;
	string first_name;
	string last_name;
	string company_name;
	Phone_Contact phone;
	Address_Contact address;
	Meeting date;
};

void load_Contacts(Contact *pf, Contact *pl);
void load_Contacts(Contact Contact_array[], const int MAX_SIZE);
void disp_Contacts(Contact[], const int);
void disp_Contacts(Contact *, Contact *);
/*int search_number(Contact[], int, int);
void sort_number(Contact[], int);
*/

istream & operator >> (istream & imp_stream, Contact & a_contact)
{
	cout << "Contact number: ";
	imp_stream >> a_contact.contactID;
	cout << "First Name: ";
	imp_stream >> a_contact.first_name;
	cout << "Family Name: ";
	imp_stream >> a_contact.last_name;
	cout << "Company Name: ";
	imp_stream >> a_contact.company_name;
	cout << "Contact Phone (Example x-xxx-xxx-xxx-xxxxxxx) : ";
	imp_stream >> a_contact.phone.inter_code;
	imp_stream >> a_contact.phone.country_code;
	imp_stream >> a_contact.phone.city_code;
	imp_stream >> a_contact.phone.cell_code;
	cout << "*Contact Address________ " << endl;
	cout << "Street Number: ";
	imp_stream >> a_contact.address.street_number;
	cout << "Street Name: ";
	imp_stream >> a_contact.address.street_name;
	cout << "City: ";
	imp_stream >> a_contact.address.city;
	cout << "Province: ";
	imp_stream >> a_contact.address.province;
	cout << "Postal Code: ";
	imp_stream >> a_contact.address.postal_code;
	cout << "Country: ";
	imp_stream >> a_contact.address.country;
	cout << "Meeting Date (Please enter date by day/month/year) : ";
	imp_stream >> a_contact.date.date; cout << " / ";
	imp_stream >> a_contact.date.month; cout << " / ";
	imp_stream >> a_contact.date.year; cout << " / ";
	system("cls");
	return imp_stream;
}
ostream & operator << (ostream & out_stream, Contact & b_contact)
{
	out_stream << "\nContact Number: " << b_contact.contactID << "\nFirst Name: " << b_contact.first_name << "\nLast Name: " << b_contact.last_name <<
		"\nCompany Name : " << b_contact.company_name << "\nContact Phone #: " << b_contact.phone.inter_code << " - " << b_contact.phone.country_code << " - "
		<< b_contact.phone.city_code << " - " << b_contact.phone.cell_code << "\nAddress: " << "\nStreet Number: " << b_contact.address.street_number << "\nStreet Name: " << b_contact.address.street_name <<
		"\nCity: " << b_contact.address.city << "\nProvince: " << b_contact.address.province << "\nPostal Code: " << b_contact.address.postal_code <<
		"\nCountry: " << b_contact.address.country << "\nMeeting date(day / month / year): " << b_contact.date.date << "/" << b_contact.date.month << "/" << b_contact.date.year << endl;
	return out_stream;
}


int main() {
	char ans2;
	int choice;
	// static array or array created during compile-time
	//const int MAX_SIZE=4; 	Student student_array[MAX_SIZE];
	do {
		int max;
		cout << "How many Contacts? : "; cin >> max;
		Contact * Contact_array = new Contact[max];
		Contact *pf, *pl;
		pf = &Contact_array[0];
		pl = &Contact_array[max - 1];
		cout << "\n\t1.Load by reference";
		cout << "\n\t2.Load by pointer";
		cout << "\n\tEnter your choice : ";
		cin >> choice;
		system("cls");
		switch (choice) {
		case 1://the beggining of the case 1
		{			int selection;
		char ans = 'y';
		do {

			cout << "_____________________ Contacts Management Application_____________________\n";
			cout << "	(1) Create and add a contacs.\n";
			cout << "	(2) Search for a contacs by number\n";
			cout << "	(3) Display the contacs list\n";
			cout << "	(4) Exit the application\n";

			cin >> selection;
			system("cls");
			switch (selection)
			{
			case 1: //the beggining of the case 1
			{
				do {

					load_Contacts(Contact_array, max);	//Function Load
					cout << "Do you want to repeat this? (Press Y) ->";
					cin >> ans;
				} while (ans == 'Y' || ans == 'y');
			}//End of the case 1

			break;
			case 2:
			{
				do {
					load_Contacts(Contact_array, max);   //function display all the contacts
					cout << "Do you want to display all the contacts again? (Press Y) ->";
					cin >> ans;
				} while (ans == 'Y' || ans == 'y');
			}//End of the case 2
			break;
			case 3:
			{
				do {      //function search 
					cout << "Do you want to search another contact? (Press Y) ->";
					cin >> ans;
				} while (ans == 'Y' || ans == 'y');
			}//End of the case 3
			break;
			case 4:
			{
				do {      //function search 
					cout << "Do you want to select what kind of sort you want to choose? (Press Y) ->";
					cin >> ans;
				} while (ans == 'Y' || ans == 'y');
			}//End of the case 4
			break;
			case 5: //the beggining of the case 5
			{return 0;
			}// end of case 5
			default:
				return 0;
			}//end of switch 
			cout << " \n";
			cout << " If you want to do another option , press Y \n";
			cin >> ans;
		}//end of the first do
		while (ans == 'y' || ans == 'Y');
		cout << "Do you want to go back to the main menu? (Press Y) ->";
		cin >> ans;
		} while (ans2 == 'Y' || ans2 == 'y'); //end of the first switch case 1
		break;
		case 2:
		{int selection;
		char ans = 'y';
		do {
			cout << " \n";
			cout << " If you want to do another option , press Y \n";
			cin >> ans;
		}//end of the first do
		while (ans == 'y' || ans == 'Y');

		} cout << "Do you want to go back to the main menu? (Press Y) ->";
		cin >> ans2;
		}
	} while (ans2 == 'Y' || ans2 == 'y');


	system("pause");
	return 0;
}



void load_Contacts(Contact Contact_array[], int MAX_SIZE) {
	//system("cls");
	cout << "\nLoad students using reference..." << endl;
	cout << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		//system("cls");
		cin >> Contact_array[MAX_SIZE];
	}
}

void load_Contacts(Contact *pf, Contact *pl)
{
	//system("cls");
	cout << "\nLoad students using pointers..." << endl;
	for (Contact * ptr = pf; ptr <= pl; ptr++)
	{
		//system("cls");
		cout << "\n\tContact number: ";
		cin >> ptr->contactID;
		cout << "\n\tFirst Name: ";
		cin >> ptr->first_name;
		cout << "\n\tFamily Name: ";
		cin >> ptr->last_name;
		cout << "\n\tCompany Name: ";
		cin >> ptr->company_name;
		cout << "\n\tContact Phone# (Please enter phone by format X XXX XXX XXXXXXX) : ";
		cin >> ptr->phone.inter_code; cout << " - ";
		cin >> ptr->phone.country_code; cout << " - ";
		cin >> ptr->phone.city_code; cout << " - ";
		cin >> ptr->phone.cell_code;
		cout << "\n\tContact Address: " << endl;
		cout << "\n\tStreet Number: ";
		cin >> ptr->address.street_number;
		cout << "\n\tStreet Name: ";
		cin >> ptr->address.street_name;
		cout << "\n\tCity: ";
		cin >> ptr->address.city;
		cout << "\n\tProvince: ";
		cin >> ptr->address.province;
		cout << "\n\tPostal Code: ";
		cin >> ptr->address.postal_code;
		cout << "\n\tCountry: ";
		cin >> ptr->address.country;
		cout << "\n\tMeeting Date (Please enter date by day/month/year) : ";
		cin >> ptr->date.date; cout << " / ";
		cin >> ptr->date.month; cout << " / ";
		cin >> ptr->date.year; cout << " / ";
		//system("cls");

	}
}

void disp_Contacts(Contact Contacts_array[], int MAX_SIZE) {
	//system("cls");
	cout << "\nDispaly students using reference..." << endl;
	cout << endl;
	for (int i = 0; i < MAX_SIZE; i++)
	{
		cout << Contacts_array[i];
	}
}

void disp_Contacts(Contact *pf, Contact *pl) {
	//system("cls");
	cout << "\nDispaly Contacts using pointers..." << endl;
	for (Contact * ptr = pf; ptr <= pl; ptr++)
	{
		cout << "\nContact Number: " << ptr->contactID;
		cin.ignore();
		cout << "\nFirst Name: " << ptr->first_name << "\nLast Name: " << ptr->last_name <<
			"\nCompany Name : " << ptr->company_name << "\nContact Phone #: " << ptr->phone.inter_code << " - " << ptr->phone.country_code << " - "
			<< ptr->phone.city_code << " - " << ptr->phone.cell_code << "\nAddress: " << "\nStreet Number: " << ptr->address.street_number << "\nStreet Name: " << ptr->address.street_name <<
			"\nCity: " << ptr->address.city << "\nProvince: " << ptr->address.province << "\nPostal Code: " << ptr->address.postal_code <<
			"\nCountry: " << ptr->address.country << "\nMeeting date(day / month / year): " << ptr->date.date << "/" << ptr->date.month << "/" << ptr->date.year << endl;

	}
}