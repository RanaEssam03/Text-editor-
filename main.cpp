#include <iostream>
#include <fstream>
using namespace std;
int main(){
    string fileName;
   cout << "Please enter the file name (.txt):  ";
   cin >> fileName;
   fstream file;
   file.open(fileName, ios:: in); //opened the file to read only to check if it exits or not
    if (file.fail()){
        cout << "This is a new file. I created it for you " << char(1);
    }
    else {
        cout << "This File Already Exists";
    }
    file.close(); //close the file to open it again but in various moods

   file.open(fileName, ios:: in | ios:: out | ios :: app);
   while (true) {
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

      if (option==16)
          break;
   }




file.close();
}

