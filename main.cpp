#include <iostream>
#include "I:\c++\Text-editor\headers\utility.h"
//___________________________
using namespace std;

//__________________________
int main()
{
    bool program_running = true;
    string choice;
    fstream file_read_app, file_read_write;
    load_file_read_append(file_read_app);
    load_file_read_write(file_read_write);

    display_menu(choice, true);
    // while true
    while (program_running)
    {
        if (choice == "1")
        {
            add_text(file_read_app);
        }
        else if (choice == "2")
        {
            display_the_content(file_read_app);
        }
        else if (choice == "3")
        {
            Empty_the_file();
        }
        else if (choice == "4")
        {
            encrypt_file(file_read_write);
        }
        else if (choice == "5")
        {
            decrypt_file(file_read_write);
        }
        else if (choice == "6")
        {
            merge(file_read_app);
        }
        else if (choice == "7")
        {
            count_words(file_read_app);
        }
        else if (choice == "8")
        {
            count_chars(file_read_app);
        }
        else if (choice == "9")
        {
            count_lines(file_read_app);
        }
        else if (choice == "10")
        {
            search_for_aword_in_file(file_read_app);
        }
        else if (choice == "11")
        {
            count_n_of_word(file_read_app);
        }
        else if (choice == "12")
        {
            convertToUpper(file_read_write);
        }
        else if (choice == "13")
        {
            convertToLower(file_read_write);
        }
        else if (choice == "14")
        {
            convertFToUpper(file_read_write);
        }
        else if (choice == "15")
        {
            save();
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