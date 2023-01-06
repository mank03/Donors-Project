#include <iostream>
#include <vector>
#include <iomanip>
#include <stdlib.h>
using namespace std;
struct Donors
{
    string name;
    int number;
    int amount;
};

double average(vector <Donors> & a)
{
    double total = 0;

    for(int i=0; i<3; i++)
    {
        total = total + a[i].amount;
    }
    double average = total/3;
    return average;

}

void sort_array(vector <Donors> &a)
{
	Donors temp;
	for (int i=0; i<a.size()-1; i++)
	{
		for (int j=i+1; j<a.size(); j++)
		{
			if (a[i].amount < a[j].amount)
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
}

void sortlist(vector <Donors> &a)
{
    cout << "Donations from greatest to least:" << endl;

    for (int i=0; i<3; i++)     // for loop to output all sorted array values
    {
        cout<<i+1 << ". $"<<fixed<<showpoint<< setprecision(2)<< a[i].amount;   // amount donated
        cout<<", donated by "<< a[i].name<<endl;      // donated by who
    }
}

void print(vector <Donors> &a)
{

    if (a[0].amount > a[1].amount) //if greatest value is greater than 2nd value to ensure nobody entered same amount
    {
        cout<< "Thank you to "<<a[0].name<<" for the largest donation with: $"<< fixed<<showpoint<<setprecision(2)<<a[0].amount<<endl;
    }
    else if ((a[0].amount = a[1].amount) && (a[0].amount > a[2].amount)) //if two people entered same amount
    {
        cout << "Thank you to " << a[0].amount << " & " << a[1].amount << " for the largest donation of: $"<<fixed<<showpoint<<setprecision(2)<<a[0].amount<<endl;
    }
    else if ((a[0].amount = a[1].amount) && (a[0].amount = a[2].amount)) //if all 3 donors entered same amount
    {
        cout<<"\nCONGRATULATIONS TO... wait! A 3-way tie from all 3 donors FOR THE LARGEST DONATION WITH: $"<<fixed<<showpoint<<setprecision(2)<<a[0].amount<<endl;
    }
}



int main()
{
    vector<Donors> a(3);

    cout << "Thank you for Donating to All Creatures Big and Small, Inc." << endl;

    for(int i=0; i<3; i++)
    {
        cout << "Please enter name of Donor #" << i+1 <<": ";
        cin >> a[i].name;
        cout << "Please enter telephone number of Donor : ";
        cin >> a[i].number;
        cin.ignore();
        cout << "Please enter the amount the Donor contributed : ";
        cin >> a[i].amount;
        cout << "\n" << endl;
    }

    sort_array(a);
    sortlist(a);

    print(a);

    average(a);
    cout << "The average of all the donations is: " << average(a) << endl;
    cout << "\n\n" << endl;


    return 0;
}


