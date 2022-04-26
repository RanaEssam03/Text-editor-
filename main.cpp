#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
void countWord( fstream & file);
void appendText(fstream &file);
void Displaycontent(fstream&file);
void empty_file(fstream&file);
void encrypt(fstream&file);
void decrypt(fstream&file);

char fileName[81];


int main(){
    char fileName[81];
   cout << "Please enter the file name (.txt):  ";
   cin.getline(fileName,81);
   fstream file;
   file.open(fileName, ios:: in); //opened the file to read only to check if it exits or not
    if (file.fail()){
        file.open(fileName, ios:: in | ios:: out | ios :: app);
        cout << "This is a new file. I created it for you " << char(1);
    }
    else {
        cout << "This File Already Exists";
    }
    file.close(); //close the file to open it again but in various moods

   //file.open(fileName, ios:: in | ios:: out | ios :: app);
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
           file.open(fileName,ios::app);
           appendText(file);
       }
       else if (option == 2){
           file.open(fileName,ios::in);
           Displaycontent(file);
       }
       else if(option == 3){
           file.open(fileName,ios::out|ios::trunc);
           empty_file(file);
       }
       else if (option == 4){
           file.open(fileName,ios::in|ios::out);
           encrypt(file);
       }
        else if (option == 11){
            countWord(file);
        }
        else if (option == 15)
        {
            file.close();
            break;
        }
        else if (option==16){
            break;
        }

   }

}

void countWord( fstream & file){
    int c= 0; //start the counting
    string countedWord;
    cout << "Please enter the word: ";
    cin >> countedWord ;  //get the required word from the user
    transform(countedWord.begin(), countedWord.end(),countedWord.begin(),:: tolower);       //convert the counted word to lower case so the counting will be insensitive
    while(not file.eof()){                                 //to continue to check and count to the end of the file
        string word;
        file >> word ;   //get word by word from the file's buffer
        transform(word.begin(), word.end(),word.begin(), :: tolower); //to void sensitive search
        if (word == countedWord){                    //compare the counted word by each word in the buffer
            c++ ;                            //increase the counter by one if the counted word is fond
        }
    }
    cout <<countedWord <<" is repeated "<< c << " times."; //printing the final counter of the required word
    cout << "\n__________________________________________________________________\n";

}
void appendText(fstream & file){
    char text[81];
    cout << "enter text you want to append:";
    cin.ignore();
    cin.getline(text,81);
    file << text;

}
void Displaycontent(fstream & file){
    char ch;
    cout << endl; //flush
    while(!file.eof()){
    cout << file.rdbuf();
    break;
    }



}
void empty_file(fstream & file){
   file << "";
   cout << "done"<<endl;
}
void encrypt(fstream & file){
    string word;
    char ch;
    while(!file.eof()){
        file.get(ch);

    if(ch == 'z'){
        file.put('a');
    }
    else if(ch=='Z'){
        file.put('A');
    }
    else{file<<(char)ch+1;

    }

    }
    cout << "encryption done"<<endl;



}


