#include <iostream>
#include "I:\c++\Text-editor\headers\utility.h"
//___________________________
using namespace std;

//__________________________
int main()
{
    bool program_running = true;
    string choice;
    fstream file;
    load_file(file);
    display_menu(choice, true);
    // while true
    while (program_running)
    {
        if (choice == "1")
        {
        }
        else if (choice == "6")
        {
        }
        else if (choice == "7")
        {
            count_words(file);
        }
        else if (choice == "8")
        {
            count_chars(file);
        }
        else if (choice == "9")
        {
            count_lines(file);
        }
        else if (choice == "10")
        {
            search_for_aword_in_file(file);
        }
        else if (choice == "16")
        {
            program_running = false;
            break;
        }
        else
        {
            cout << "#################" << endl;
            cout << "!! invalid !!" << endl;
            cout << "#################" << endl;
        }
        display_menu(choice, false);
    }
}