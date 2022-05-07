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

    cout << "1. Add new text to the end of the file\n2. Display the content of the file\n3. Empty the file\n4. Encrypt the file content \n5. Decrypt the file content\n6. Merge another file\n7. Count the number of words in the file.\n8. Count the number of characters in the file\n9. Count the number of lines in the file\n10. Search for a word in the file\n11. Count the number of times a word exists in the file\n12. Turn the file content to upper case.\n13. Turn the file content to lower case.\n14. Turn file content to 1st caps (1st char of each word is capital) \n15. Save\n16. Exit " << endl;
    // take the user desire
    cout << "Your choice: ";
    cin >> ws >> choice;
}
