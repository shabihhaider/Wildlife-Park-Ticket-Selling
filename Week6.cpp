#include<iostream>
#include<string>
#include<iomanip> //For output formatting
#include<vector>
using namespace std;

const int SIZE = 5;
const int ESIZE = 3;

class WildlifePark
{
public:
    float costForOneDay[SIZE];
    float costForTwoDay[SIZE];
    float costPerPerson[ESIZE];
    vector<float> totalCost;
    vector<int> bookingID;
    WildLifePark()
    {}

    void task1()
    {
        costForOneDay[0] = 20.00;
        costForOneDay[1] = 12.00;
        costForOneDay[2] = 16.00;
        costForOneDay[3] = 60.00;
        costForOneDay[4] = 15.00;

        costForTwoDay[0] = 30.00;
        costForTwoDay[1] = 18.00;
        costForTwoDay[2] = 24.00;
        costForTwoDay[3] = 90.00;
        costForTwoDay[4] = 22.50;

        costPerPerson[0] = 2.50;
        costPerPerson[1] = 2.00;
        costPerPerson[2] = 5.00;


    }

    void task2()
    {
        //input tickets and extra attraction required, total cost of booking
        //unique booking number
        //display booking details (total cost, unique booking number)
        //Task 2
        int input = 0, i=0, j=1000, yes =0;
        float sum = 0;
        int input2;
start:
        cout << "<<<<< Input Tickets >>>>>\n\n";
        cin >> input;

        while(true)
        {
        	if(input == 0)
        	{
        		break;
			}
			
            if(input == 1)
            {
yes1:
                cout << "1) For One Day? \n2)For Two Days?";
                cin >> yes;
                if(yes == 1)
                {
                    sum += costForOneDay[0];
                }
                else if(yes == 2) {
                    sum += costForTwoDay[0];
                } else {
                    cout << "Invalid Input!\n";
                    goto yes1;
                }
                
            }
            else if(input == 2)
            {
yes2:
                cout << "1) For One Day? \n2)For Two Days?";
                cin >> yes;
                if(yes == 1)
                {
                    sum += costForOneDay[1];
                }
                else if(yes == 2) {
                    sum += costForTwoDay[1];
                } else {
                    cout << "Invalid Input!\n";
                    goto yes2;
                }
                
            }
            else if(input == 3)
            {
yes3:
                cout << "1) For One Day? \n2)For Two Days?";
                cin >> yes;
                if(yes == 1)
                {
                    sum += costForOneDay[2];
                }
                else if(yes == 2) {
                    sum += costForTwoDay[2];
                } else {
                    cout << "Invalid Input!\n";
                    goto yes3;
                }
                
            }
            else if(input == 4)
            {
yes4:
                cout << "1) For One Day? \n2)For Two Days?";
                cin >> yes;
                if(yes == 1)
                {
                    sum += costForOneDay[3];
                }
                else if(yes == 2) {
                    sum += costForTwoDay[3];
                } else {
                    cout << "Invalid Input!\n";
                    goto yes4;
                }
                
            }
            else if(input == 5)
            {
yes5:
                cout << "1) For One Day? \n2)For Two Days?";
                cin >> yes;
                if(yes == 1)
                {
                    sum += costForOneDay[4];
                }
                else if(yes == 2) {
                    sum += costForTwoDay[4];
                } else {
                    cout << "Invalid Input!\n";
                    goto yes5;
                }
                
            }
            else
            {
                cout << "\nInvalid Input!	(First Enter Ticket Type)\n";
                goto start;
            }
        

        while(true)
        {

input2:
            cout << "\n<<<<< Extra Attraction Required? (Press 0 to exit)>>>>>\n\n";
            cin >> input;
            if(input == 0) {
            	break;
			}
            switch (input)
            {
            case 6:
                sum += costPerPerson[0];
                break;
            case 7:
                sum += costPerPerson[1];
                break;
            case 8:
                sum += costPerPerson[2];
                break;
            default:
                cout << "Invalid Input!\n";
                goto input2;
                break;
            }

            //total cost
            cout << "Total cost is: $" << sum << endl;
	        }
        totalCost.push_back(sum);
            bookingID.push_back(j++);
            i++;
            sum = 0; // Reset sum for next booking
            cout << "\n** For Next Booking, Enter Tickets (0 to exit): **\n";
            cin >> input;
	}
//Booking Details
		cout << "\n** Booking Details: **\n";
        for(int k = 0; k<totalCost.size(); k++)
        {
            cout << "Booking ID: " << bookingID[k] << "\t\tTotal Cost: $" << totalCost[k] << endl;
        }
    }
    
    void task3() 
	{
    for (int i = 0; i < totalCost.size(); i++) 
	{
        float currentBookingCost = totalCost[i];
        float bestAlternativeCost = currentBookingCost;

        for (int j = 0; j < totalCost.size(); j++) 
		{
            if (i != j) 
			{
                float alternativeCost = totalCost[i] + totalCost[j];

                if (alternativeCost < bestAlternativeCost) 
				{
                    bestAlternativeCost = alternativeCost;
                }
            }
        }

        // Display the best value option for each booking
        if (bestAlternativeCost < currentBookingCost) 
		{
            cout << "Booking ID " << bookingID[i] << ": Combine with another booking for a total cost of $" << bestAlternativeCost << endl;
        } 
		else 
		{
            cout << "Booking ID " << bookingID[i] << ": Current booking is the best value at a total cost of $" << currentBookingCost << endl;
        }
    }
}
};

int main()
{
    cout << "<<<<<<<< Welcome to 'WILDLIFE PARK' >>>>>>>>"<< endl;
    WildlifePark P;
    P.task1();
    //Task 1
    cout << fixed << setprecision(2);
    cout << "Ticket Type                    | Cost for One Day        | Cost for Two Days\n\n" << endl;
    cout << "1) One Adult                   |    $" << P.costForOneDay[0] << "|    $" << P.costForTwoDay[0] << endl;
    cout << "2) One Child (an Adult may bring upto two Children) |    $" << P.costForOneDay[1] << "|    $" << P.costForTwoDay[1] << endl;
    cout << "3) One Senior                  |    $" << P.costForOneDay[2] << "|    $" << P.costForTwoDay[2] << endl;
    cout << "4) Family Ticket (upto two Adults or Seniors, and three Children)     |    $" << P.costForOneDay[3] << "|    $" << P.costForTwoDay[3] << endl;
    cout << "5) Groups of six people or more, price per person    |    $" << P.costForOneDay[4] << "|    $" << P.costForTwoDay[4] << endl;
    cout << "\n\n";
    cout << "Extra Attraction        | Cost Per Person (After 'Input Tickets')\n\n";
    cout << "6) Lion Feeding         |    $" << P.costPerPerson[0] << endl;
    cout << "7) Penguin Feeding      |    $" << P.costPerPerson[1] << endl;
    cout << "8) Evening Barbecue (Two-Day Tickets only)    |    $" << P.costPerPerson[2] << endl;

    cout << "\n** Booking Available on: \n*) Thursday \n*) Friday \n\n";
    cout << "\n** For Exit Press 0 **\n" << endl;

    //Task 2
    P.task2();
    
    //Task3
cout << "\n** Checking for the best value **\n";
P.task3();
    return 0;
}
