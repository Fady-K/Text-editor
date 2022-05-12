
#include <iostream>
#include <fstream>
#include <cctype>
#include<vector>
#include<string>

using namespace std;
char fileName[100];
fstream sourceFile;
fstream& convertToLower();
fstream& convertToUpper();
fstream& convertFToUpper();
fstream& loadFile(fstream& sourceFile);
fstream& count();
fstream& save();

int main()
{
    convertToLower();
}
    
fstream& loadFile(fstream& sourceFile)
{
    cout<<"Enter File Name: ";
    cin >> fileName;//physical name
    sourceFile.open (fileName, ios::in);
   
    if (sourceFile.fail())
    {
        cout<<"the file does not exist.\n I will create it for you.";
        sourceFile.open (fileName, ios::in);
 
    }
    else
    {
        cout<<"the file opened successfully."<<endl;
    }

    return sourceFile;

}
fstream& convertToLower()
{
    loadFile(sourceFile);
    vector<string> vect ;
    string ch;
    
    
        while(!sourceFile.eof())
        {
            getline(sourceFile, ch);
            vect.push_back(ch);
            if(sourceFile.eof())
            {
                break;
            }
        }
        
        for (int i = 0; i < vect.size(); i++)     
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                vect[i][j] = tolower(vect[i][j]);
            }
        } 
        sourceFile.close();
        sourceFile.open (fileName, ios::out);
        for (int i = 0; i < vect.size(); i++)     
        {
                sourceFile<<vect[i]<<endl;
        }  
    
    sourceFile.close();
    return sourceFile;   
}

fstream& convertToUpper()
{
    loadFile(sourceFile);
    vector<string> vect ;
    string ch;
    
    
        while(!sourceFile.eof())
        {
            getline(sourceFile, ch);
            vect.push_back(ch);
            if(sourceFile.eof())
            {
                break;
            }
        }
        
        for (int i = 0; i < vect.size(); i++)     
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                vect[i][j] = toupper(vect[i][j]);
            }
        } 
        sourceFile.close();
        sourceFile.open (fileName, ios::out);
        for (int i = 0; i < vect.size(); i++)     
        {
                sourceFile<<vect[i]<<endl;
        }   
    
    sourceFile.close();
    return sourceFile;   
}


fstream& convertFToUpper()
{
    loadFile(sourceFile);
    vector<string> vect ;
    string ch;
        while(!sourceFile.eof())
        {
            getline(sourceFile, ch);
            vect.push_back(ch);
            if(sourceFile.eof())
            {
                break;
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
                if((vect[i][j] == ' '))
                {
                    vect[i][j+1] = toupper(vect[i][j+1]);
                }
                else
                {
                    vect[i][j+1] = tolower(vect[i][j+1]);
                    
                }
            }
        } 
        sourceFile.close();
        sourceFile.open (fileName, ios::out);
        for (int i = 0; i < vect.size(); i++)     
        {
                sourceFile<<vect[i]<<endl;
        }   
    sourceFile.close();  
    return sourceFile; 
}

fstream& count()
{
    int counter = 0;
    string word;
    loadFile(sourceFile);
    vector<string> vect ;
    string ch;
    
    
        while(!sourceFile.eof())
        {
            sourceFile>> ch;
            vect.push_back(ch);
            vect.push_back(" ");
            if(sourceFile.eof())
            {
                break;
            }
        }
        for (int i = 0; i < vect.size(); i++)     
        {
            for (int j = 0; j < vect[i].size(); j++)
            {
                vect[i][j] = tolower(vect[i][j]);
            }
        } 
        sourceFile.close();
        cout<<"Enter a word to search for: ";
        cin>>word;
        for (int i = 0; i < word.size(); i++)
        {
            word[i] = tolower (word[i]);
        }
        for (int i = 0; i < vect.size(); i++)     
        {
           if(vect[i]== word) 
           {
               counter += 1;
           }
        }
        cout << counter<<"\n";  
        return sourceFile; 
}
fstream&save()
{ 
    cout<<"Enter File Name: ";
    cin >> fileName;
    sourceFile.open(fileName, ios::app);
    char option;
    char newName[100];
    cout<<"Do you want to change the name of file?\npress\'y\' if YES or \'n\' if NO: ";
    cin>>option;
    if(option == 'y')
    {
        cout<<"Enter the new name: ";
        cin>>newName;
    }
    rename(fileName, newName);
    sourceFile.close();
}