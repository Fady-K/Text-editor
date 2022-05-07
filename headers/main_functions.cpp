#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
//____________________
using namespace std;

//___________________
void display_menu(string &choice, bool first_time)
{
    if (first_time)
    {
        cout << "!! Welcome !!" << endl;
    }

    cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content \n5. Decrypt the file content\n6. Merge another file\n7. Count the number of words in the file.\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital) \n15. Save\n16. Exit " << endl;
    // take the user desire
    cout << "Your choice: ";
    cin >> ws >> choice;
}

//___________________________
// load file function
void load_file(fstream &file_to_load_content_in)
{
    // take the file path
    cout << "Enter file name: ";
    string file_path;
    getline(cin >> ws, file_path);
    file_path += ".txt";

    // check if the file exists or not
    if (filesystem::exists(file_path))
    {
        cout << "This File Already Exits" << endl;
    }
    else if (!filesystem::exists(file_path))
    {
        cout << "This A new file, I Created For You" << endl;
    }

    // open the file
    file_to_load_content_in.open(file_path);

    // if the file isn't open
    if (!file_to_load_content_in.is_open())
    {
        cout << "!! Can't open " << file_path << " !!" << endl;
    }
}

// _______Smallest_id_functions_________

//____________Middle_id_functions____________

void count_words(fstream &file_to_count_its_words)
{
    string word;

    int count_of_words = 0;

    while (file_to_count_its_words >> word)
    {
        if (word.size() > 1)
        {
            count_of_words++;
        }
    }

    cout << "No.words: " << count_of_words << endl;
}
