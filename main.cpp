#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>
#include <windows.h>


using namespace std;

void display_seats(int seatingArray[][8], int col);

bool check_seating(int seatingArray[][8], int& userRow, int& userCol);

bool verify_SoldOut(int seatingArray[][8]);


int main()
{

    int userRow, userCol;

    int row = 9;

    int col = 8;

    bool seatsAvailable = false;

    int seatingArray[9][8] =
        {
            { 40, 50, 50, 50, 50, 50, 50, 40 },
            { 30, 30, 40, 50, 50, 40, 30, 30 },
            { 20, 30, 30, 40, 40, 30, 30, 20 },
            { 10, 20, 20, 20, 20, 20, 20, 10 },
            { 10, 20, 20, 20, 20, 20, 20, 10 },
            { 10, 20, 20, 20, 20, 20, 20, 10 },
            { 10, 10, 10, 10, 10, 10, 10, 10 },
            { 10, 10, 10, 10, 10, 10, 10, 10 },
            { 10, 10, 10, 10, 10, 10, 10, 10 }
        };

while (verify_SoldOut(seatingArray) == false)
    {
        display_seats(seatingArray, col);

        check_seating(seatingArray, userRow, userCol);

        verify_SoldOut(seatingArray);
    }

    cout << endl <<"THE THEATER HAS BEEN SOLD OUT!!!" << endl;


	return 0;
}


void display_seats(int seatingArray[][8], int col)
    {
        cout <<  endl << setw(33) << "Available Theater Seating" << endl << endl;

        for (int i = 8; i >= 0; i--)
            {
               for (int j = 0; j < col; j++)
                    {
                        if ((seatingArray[i][j]) == -1)
                            {
                                cout << setw(5) << "X";
                            }
                        else
                            {
                                cout << setw(3) << "$" << seatingArray[i][j];
                            }
                    }
                cout << endl;
            }

        cout << endl << setw(22) << "STAGE" << endl;
    }


bool check_seating(int seatingArray[][8], int& userRow, int& userCol)
    {
        int col = 8;
        int seatCount = 0;
        bool available = false;
        bool full = false;

        cout << endl << setw(37) << "Please select a Theater Seat Row: ";
        cin >> userRow;
        cout << endl << setw(40) << "Please select a Theater Seat Column: ";
        cin >> userCol;

        if (userRow > 0 && userRow < 10 && userCol > 0 && userCol < 9)
            {
                available = true;

            }


        while (available == false)
            {
                cout << endl << "ATTENTION: The seat selected: " << userRow << ":" << userCol << " Does not Exist." << endl;
                cout << endl << setw(37) << "Please select a Theater Seat Row : ";
                cin>>userRow;
                cout << endl << setw(40) << "Please select a Theater Seat Column : ";
                cin>>userCol;

                if (userRow > 0 && userRow < 10 && userCol > 0 && userCol < 9)
                    {
                        available = true;
                    }
            }


                if (seatingArray[userRow -1][userCol -1] == -1)
                    {
                        cout << endl << "ATTENTION: That seat has already been sold" << endl;
                        cout << setw(32) << endl << "Please choose another" << endl;
                    }
                else
                    {
                        cout << endl << endl << setw(33) << "Thank you for choosing seat # " << userRow << ":" << userCol << endl;
                        cout << setw(26) << "Your ticket price is: $" << seatingArray[userRow - 1][userCol - 1] << endl;

                        available = false;
                        Sleep(1500);
                        seatingArray[userRow - 1][userCol - 1] = -1;
                        seatCount++;
                        system("CLS");
                        display_seats(seatingArray, col);

                        if (seatCount == 72)
                            {
                                cout << "ATTENTION: THE THEATER HAS BEEN SOLD OUT!" << endl;
                                Sleep(3000);
                            }
                    }

            system("CLS");

    }


bool verify_SoldOut(int seatingArray[][8])
    {
        bool full = true;
            for (int i = 8; i >= 0; i--)            //8 is the total column numbers
                {
                    for (int j = 0; j < 8; j++)
                        {
                            if ((seatingArray[i][j]) != -1)
                            {
                                full = false;
                                return (full);
                            }
                        }
                }
        return (full);
    }
