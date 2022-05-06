#include <iostream>

//____________________
using namespace std;

//___________________
void display_menu(string &choice, bool first_time)
{
    if (first_time)
    {
        cout << "!! Welcome !!" << endl;
    }

    cout << "" << endl;

    // take the user desire
    cout << "Your choice: ";
    cin >> ws >> choice;
}
