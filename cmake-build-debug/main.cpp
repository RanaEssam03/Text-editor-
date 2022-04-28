#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include<vector>
#include"CS112-203-2nd-S1-20210049-20210067-20210133-A4-TextEditorFunc.h"
#include "CS112-203-2nd-S1-20210049-20210067-20210133-A4-TextEditorFunc.cpp"

using namespace std;

int main(){
    cout << "Please enter the file name (.txt):  ";
    cin.getline(fileName,81);
    file.open(fileName, ios:: in); //opened the file to read only to check if it exits or not
    if (file.fail()){
        file.open(fileName, ios :: app);
        cout << "This is a new file. I created it for you" << char(1);
    }
    else {
        cout << "This File Already Exists";
    }
    file.close(); //close the file to open it again but in various moods


    while (true)
    {
        cout << "\n\t\tPlease pick one option ";
        cout << "\n1. Add new text to the end of the file \n";
        cout << "2. Display the content of the file\n";
        cout << "3. Empty the file\n";
        cout << "4. Encrypt the file content \n";
        cout << "5. Decrypt the file content\n";
        cout << "6. Merge another file\n";
        cout << "7. Count the number of words in the file.\n";
        cout << "8. Count the number of characters in the file\n";
        cout << "9. Count the number of lines in the file\n";
        cout << "10. Search for a word in the file\n";
        cout << "11. Count the number of times a word exists in the file\n";
        cout << "12. Turn the file content to upper case.\n";
        cout << "13. Turn the file content to lower case.\n";
        cout << "14. Turn file content to 1st caps (1st char of each word is capital) \n";
        cout << "15. Save\n16. Exit";
        cout << "\n--> ";
        int option;
        cin >> option;
        if(option == 1){
            appendText(file);
        }
        else if (option == 2){
            Displaycontent(file);
        }
        else if(option == 3){
            empty_file(file);
        }
        else if (option == 4){
            encrypt(file);
        }
        else if(option == 5){
            decrypt(file);
        }

        else if(option == 6) merge();
        else if(option == 7) count_words();
        else if(option == 8) count_chars();
        else if(option == 9) count_lines();
        else if(option == 10) search_word();

        else if (option == 11){
            file.open(fileName,ios::in);
            countWord(file);
        }
        else if (option == 12){
            file.open(fileName);
            upperCase(file);
        }
        else if (option == 13){
            file.open(fileName);
            lowerCase(file);
        }
        else if (option == 14){
            file.open(fileName);
            firstIsUpper(file);
        }
        else if (option == 15)
        {
            save();
        }
        else if (option==16){
            break;
        }
    }
}


