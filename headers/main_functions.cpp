#include <iostream>
#include <fstream>
#include <string>
#include <filesystem>
#include <cctype>

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
    cout << "\nYour choice: ";
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
        cout << "#################" << endl;
        cout << "This File Already Exits" << endl;
        cout << "#################" << endl;
    }
    else if (!filesystem::exists(file_path))
    {
        cout << "#################" << endl;
        cout << "This A new file, I Created For You" << endl;
        cout << "#################" << endl;
    }

    // open the file
    file_to_load_content_in.open(file_path, ios::in | ios::app);

    // if the file isn't open
    if (!file_to_load_content_in.is_open())
    {
        cout << "#################" << endl;
        cout << "!! Can't open " << file_path << " !!" << endl;
        cout << "#################" << endl;
    }
}

// _______Smallest_id_functions______________

//____________Middle_id_functions____________

// return the pointer again to the begging of the file >> to make the file modifyable (readable) again
void restore_pointer(fstream &file_to_restore_its_pointer)
{
    file_to_restore_its_pointer.clear();
    file_to_restore_its_pointer.seekg(0, file_to_restore_its_pointer.beg);
}

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
    cout << "#################" << endl;
    cout << "No.words: " << count_of_words << endl;
    cout << "#################" << endl;

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_count_its_words);
}

//________________________________________________
void count_lines(fstream &file_to_count_its_lines)
{

    string line;
    int count_of_lines = 0;
    while (getline(file_to_count_its_lines, line))
    {
        count_of_lines += 1;
    }
    cout << "#################" << endl;
    cout << "No.lines: " << count_of_lines << endl;
    cout << "#################" << endl;

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_count_its_lines);
}

//_________________________________________________
void count_chars(fstream &file_to_count_its_chars)
{
    char ch;
    int count_of_chars_without_spaces = 0;
    int count_of_chars_with_spaces = 0;

    if (file_to_count_its_chars.is_open())
    {
        while (file_to_count_its_chars.get(ch))
        {
            if (isalpha(ch))
            {
                count_of_chars_without_spaces += 1;
                count_of_chars_with_spaces += 1;
            }

            else if (isspace(ch))
            {
                count_of_chars_with_spaces += 1;
            }
        }
    }
    cout << "#################" << endl;
    cout << "no.chars_without_spaces: " << count_of_chars_without_spaces << endl;
    cout << "no.char_with_spaces: " << count_of_chars_with_spaces << endl;
    cout << "#################" << endl;

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_count_its_chars);
}

//___________________________________
void search_for_aword_in_file(fstream &file)
{
    // take the word to seek from the uesr
    cout << "#################" << endl;
    cout << "Word to search: ";
    string word_to_search;
    cin >> ws >> word_to_search;

    // word to match
    string word_to_match;
    bool infile = false;
    if (file.is_open())
    {
        while (file >> word_to_match)
        {
            if (word_to_match == word_to_search)
            {
                cout << "#################" << endl;
                cout << "!! " << word_to_search << " in the file !!" << endl;
                cout << "#################" << endl;
                infile = true;
            }
        }
    }

    if (!infile)
    {
        cout << "#################" << endl;
        cout << "!! " << word_to_search << " was not found in the file !!" << endl;
        cout << "#################" << endl;
    }

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file);
}

//___________________________
// merge two files functions
void merge(fstream &file_to_fill)
{
    // declare a varible of fstream data type to store data in it
    fstream file_to_be_merged;
    load_file(file_to_be_merged);

    // significant assets
    string line;
    string word;

    // show the original file
    cout << "----------------------------------- Original File ------------------------------" << endl;
    while (getline(file_to_fill, line))
    {
        cout << line << endl;
    }

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_fill);

    // show the new file to merge
    cout << "--------------------------- The New File to Merge--------------------------" << endl;
    while (getline(file_to_be_merged, line))
    {
        cout << line << endl;
    }

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_be_merged);

    // merge the two files
    while (getline(file_to_be_merged, line))
    {
        file_to_fill << line << endl;
    }

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_fill);

    cout << "-------------------------- Original File after Merge ------------------------" << endl;
    while (getline(file_to_fill, line))
    {
        cout << line << endl;
    }
    cout << "------------------------------------------------------------------------------" << endl;

    // return the pointer again to the begging of the file >> to make the file modifyable (readable) again
    restore_pointer(file_to_fill);
}