#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
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
// load file function  (this function loads the file in read and append mode)
string file_path; // declared it as global in order to use it again in another function (read-write)
void load_file_read_append(fstream &file_to_load_content_in)
{
    // take the file path, store in predecalred local variable file_path
    cout << "Enter file name: ";
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
        cout << "!! Can't open" << file_path << " !!" << endl;
        cout << "#################" << endl;
    }
}

//___________________________
// load file function  (this function loads the file in read and write mode)
void load_file_read_write(fstream &file_to_load_content_in)
{

    // open the file
    file_to_load_content_in.open(::file_path, ios::in | ios::out);

    // if the file isn't open
    if (!file_to_load_content_in.is_open())
    {
        cout << "#################" << endl;
        cout << "!! Can't open " << file_path << " !!" << endl;
        cout << "#################" << endl;
    }
}

//___________________________
// load file function  (this function loads the file write mode only)
void load_file_write_only(fstream &file_to_load_content_in)
{

    // open the file
    file_to_load_content_in.open(::file_path, ios::out);

    // if the file isn't open
    if (!file_to_load_content_in.is_open())
    {
        cout << "#################" << endl;
        cout << "!! Can't open " << file_path << " !!" << endl;
        cout << "#################" << endl;
    }
}

// return the pointer again to the begging of the file >> to make the file modifyable (readable) again
void restore_pointer(fstream &file_to_restore_its_pointer)
{
    file_to_restore_its_pointer.clear();
    file_to_restore_its_pointer.seekg(0, file_to_restore_its_pointer.beg);
}

// _______Smallest_id_functions______________

//___________________________________________
// dipslay function to display the all the content of the file
void display_the_content(fstream &sourceFile)
{

    // check if file is empty
    cout << "#################" << endl;
    string line;
    while (getline(sourceFile, line))
    {

        cout << line << endl;
    }

    cout << "#################" << endl;

    restore_pointer(sourceFile);
}

//___________________________________________
// Empty file to erase all the contents of the file
void Empty_the_file()
{
    fstream temp;
    temp.open(file_path, ios::out);
    if (temp.is_open())
    {
        temp << "";
        cout << "#################" << endl;
        cout << "!! Contents of file has been erased successfully !!" << endl;
        cout << "#################" << endl;
    }
    // note: in writing mode it's a must to close the file so as the changes be saved
    temp.close();
}

void add_text(fstream &sourceFile)
{
    // take text to append from the user
    cout << "Text to append: ";

    string line;
    getline(cin >> ws, line);
    sourceFile << line << endl;

    cout << "#################" << endl;
    cout << "!! Text has been added successfully !!" << endl;
    cout << "#################" << endl;

    restore_pointer(sourceFile);
}

//___________________________________________
void encrypt_file(fstream &sourceFile)
{
    fstream temp;
    string word;
    vector<string> encrypted_words;
    while (sourceFile >> word)
    {
        // encrypt tht word
        for (auto &c : word)
        {
            c = char(int(c) + 1);
        }
        word += " ";
        encrypted_words.push_back(word);
    }
    restore_pointer(sourceFile);

    temp.open(file_path, ios::out);

    for (int i = 0; i < encrypted_words.size(); ++i)
    {
        temp << encrypted_words[i];
    }
    temp.close();

    cout << "#################" << endl;
    cout << "!! File was encrypted succesfully !!" << endl;
    cout << "#################" << endl;
}

//_____________________________________________
void decrypt_file(fstream &sourceFile)
{
    fstream temp;
    string word;
    vector<string> decrypted_words;
    while (sourceFile >> word)
    {
        // encrypt tht word
        for (auto &c : word)
        {
            c = char(int(c) - 1);
        }
        word += " ";
        decrypted_words.push_back(word);
    }
    restore_pointer(sourceFile);

    temp.open(file_path, ios::out);

    for (int i = 0; i < decrypted_words.size(); ++i)
    {
        temp << decrypted_words[i];
    }
    temp.close();
    cout << "#################" << endl;
    cout << "!! File was decrypted succesfully !!" << endl;
    cout << "#################" << endl;
}

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
                break;
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
    load_file_read_append(file_to_be_merged);

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

//____________Largest_id_functions____________

//________________________
// convert all the content of file into lowercase
void convertToLower(fstream &sourceFile)
{
    vector<string> vect;
    string ch;

    while (sourceFile.is_open())
    {
        getline(sourceFile, ch);
        vect.push_back(ch);
        if (sourceFile.eof())
        {
            break;
        }
    }
    restore_pointer(sourceFile);

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            vect[i][j] = tolower(vect[i][j]);
        }
    }

    // using insertion operator(<<) to insert all string stored in vect to sourceFile
    for (int i = 0; i < vect.size(); i++)
    {
        sourceFile << vect[i];
        if (i < vect.size() - 1)
        {
            sourceFile << endl;
        }
    }

    cout << "#################" << endl;
    cout << "!! File was converted into LOWERCASE succesfully !!" << endl;
    cout << "#################" << endl;

    restore_pointer(sourceFile);
}

//_____________________________________
// convert all the words of the file into uppercase
void convertToUpper(fstream &sourceFile)
{
    vector<string> vect;
    string ch;

    while (sourceFile.is_open())
    {
        getline(sourceFile, ch);
        vect.push_back(ch);
        if (sourceFile.eof())
        {
            break;
        }
    }
    restore_pointer(sourceFile);

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            vect[i][j] = toupper(vect[i][j]);
        }
    }

    // using insertion operator(<<) to insert all string stored in vect to sourceFile
    for (int i = 0; i < vect.size(); i++)
    {
        sourceFile << vect[i];
        if (i < vect.size() - 1)
        {
            sourceFile << endl;
        }
    }
    cout << "#################" << endl;
    cout << "!! File was converted into UPPERCASE succesfully !!" << endl;
    cout << "#################" << endl;

    restore_pointer(sourceFile);
}

//_________________________________
// capitalize each word of the file
void convertFToUpper(fstream &sourceFile)
{
    vector<string> vect;
    string ch;

    while (sourceFile.is_open())
    {
        getline(sourceFile, ch);
        vect.push_back(ch);
        if (sourceFile.eof())
        {
            break;
        }
    }
    restore_pointer(sourceFile);

    // couvert all the file into lower case
    // iterte over each line in the vect
    for (int i = 0; i < vect.size(); ++i)
    {
        for (int j = 0; j < vect[i].size(); ++j)
        {
            // iterate over each char in the line and convert theat char into upper case
            char c = vect[i][j];
            c = tolower(c);
        }
    }

    for (int i = 0; i < vect.size(); i++)
    {
        vect[i][0] = toupper(vect[i][0]);
    }

    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 1; j < vect[i].size(); j++)
        {
            if (isspace(vect[i][j]))
            {
                vect[i][j+1] = toupper(vect[i][j+1]);
            }
        }
    }

    // using insertion operator(<<) to insert all string stored in vect to sourceFile
    for (int i = 0; i < vect.size(); i++)
    {
        sourceFile << vect[i];
        if (i < vect.size() - 1)
        {
            sourceFile << endl;
        }
    }

    cout << "#################" << endl;
    cout << "!! File was CAPITALIZED succesfully !!" << endl;
    cout << "#################" << endl;

    restore_pointer(sourceFile);
}

//___________________________
// take a word from user, return how many times it exits in the file
void count_n_of_word(fstream &sourceFile)
{
    int counter = 0;
    string word;
    vector<string> vect;
    string ch;

    while (sourceFile.is_open())
    {
        sourceFile >> ch;
        vect.push_back(ch);
        vect.push_back(" ");
        if (sourceFile.eof())
        {
            break;
        }
    }
    restore_pointer(sourceFile);
    for (int i = 0; i < vect.size(); i++)
    {
        for (int j = 0; j < vect[i].size(); j++)
        {
            vect[i][j] = tolower(vect[i][j]);
        }
    }
    cout << "#################" << endl;
    cout << "Enter a word to search for: ";
    cin >> word;
    for (int i = 0; i < word.size(); i++)
    {
        word[i] = tolower(word[i]);
    }

    for (int i = 0; i < vect.size(); i++)
    {
        if (vect[i] == word)
        {
            counter += 1;
        }
    }
    cout << "#################" << endl;
    cout << "Count of " << word << ": " << counter << endl;
    cout << "#################" << endl;
}

// save function to save the user file, in addition to rename the file feature
void save()
{
    // ask the user if he want's to change the password
    cout << "Change the file name before saving it?  (y/n): ";
    string answer;
    getline(cin >> ws, answer);

    // for (auto &c : answer)
    //     c = tolower(c);

    while (answer != "y")
    {
        cout << "#################" << endl;
        cout << "!! invalid !! " << endl;
        cout << "#################" << endl;
        cout << "Change the file name (y/n): ";
        getline(cin >> ws, answer);
    }

    // check the user's answer
    if ((answer == "y") || (answer == "Y"))
    {
        // take the new name from the user
        cout << "New name: ";
        string new_name;
        cin >> new_name;

        // add .txt to new_name
        new_name += ".txt";

        // rename the file
        // note: c_str() function convert string into const char* array
        rename(file_path.c_str(), new_name.c_str());

        // print !! saving is done!
        cout << "#################" << endl;
        cout << "!! " << new_name << " has been saved successfully !!" << endl;
        cout << "#################" << endl;
        file_path = new_name;
    }
    else if ((answer == "n") || (answer == "N"))
    {
        cout << "#################" << endl;
        cout << "!! " << file_path << " has been saved successfully !!" << endl;
        cout << "#################" << endl;
    }
}
