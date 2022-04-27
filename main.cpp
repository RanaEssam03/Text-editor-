#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include<vector>
#include<sstream>
using namespace std;
void countWord( fstream & file);
void appendText(fstream &file);
void Displaycontent(fstream&file);
void empty_file(fstream&file);
void encrypt(fstream&file);
void decrypt(fstream&file);
void upperCase(fstream &file);
void lowerCase(fstream &file);
void firstIsUpper (fstream & file);
void save();

char fileName[81];
fstream file;



int main(){
   cout << "Please enter the file name (.txt):  ";
   cin.getline(fileName,81);
   file.open(fileName, ios:: in); //opened the file to read only to check if it exits or not
    if (file.fail()){
        file.open(fileName, ios:: in | ios:: out | ios :: app);
        cout << "This is a new file. I created it for you " << char(1);
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
    file.open(fileName,ios::app); // opening file in append mode
    char text[81];
    cout << "enter text you want to append:";
    cin.ignore();
    cin.getline(text,81);
    file << text; // appending text to the end of the file

}
void Displaycontent(fstream & file){
    file.open(fileName,ios::in); // opening the file in read mode
    char ch;
    cout << endl; //flush
    cout << file.rdbuf(); //displaying the buffer
}
void empty_file(fstream & file){
    file.open(fileName,ios::out|ios::trunc); // deleting content in the file
    file << "";
   cout << "done"<<endl;
}
void encrypt(fstream & file) {
    file.open(fileName,ios::in|ios::out); // read and write mode
    vector<char> vector_file;// a vector to store all the characters from the file and then shift them
    char ch;
    cout << endl;
    while (!file.eof()) {
        file.get(ch);
        vector_file.push_back(ch); //storing the file characters in the vector
    }
    file.close();
    file.open(fileName,ios::out|ios::trunc); // deleting the file content
    file.close();
    file.open(fileName,ios::out); //opening the file in write mode to write shifted characters in it
    for(int i =0;i<vector_file.size()-1;i++){
        file << (char)(vector_file[i]+1); // shifting every character except z
    }
    cout << "file encrypted succefully"<<endl;
}
void decrypt(fstream&file){
    file.open(fileName,ios::in|ios::out);
    vector<char>vectorFile;
    char ch;
    while(!file.eof()){
        file.get(ch);
        vectorFile.push_back(ch);
    }
    file.close();
    file.open(fileName,ios::in|ios::out);
    file.close();
    file.open(fileName,ios::out);
    for(int i =0;i<vectorFile.size()-1;i++){
            file << (char)(vectorFile[i]-1);
    }

    cout << "file decrypted succesfully"<<endl;
}

void upperCase(fstream & file) {

    string str =""; //string to copy all the txt in it including spaces
    while (not file.eof()) {
        string str1;
        getline(file, str1); //to read all the file content including spaces
        str +=str1; //to store all the file content in a one string
    }

    transform(str.begin(), str.end(), str.begin(), ::toupper); //to convert all the txt to upper case
    file.close(); //close the file to open it again in  write mood so all its content all be deleted
    file.open(fileName, ios:: out);
    file << str;  // write the txt after editing in the main file


}

void lowerCase (fstream & file) {
    string str ="";
    while (not file.eof()) {
        string str1;
        getline(file, str1);
        str +=str1;
    }

    transform(str.begin(), str.end(), str.begin(), ::tolower);
    file.close();
    file.open(fileName, ios:: out);
    file << str;
}

void firstIsUpper(fstream & file) {

    string str =""; //string to copy all the txt in it
    while (not file.eof()) {
        string str1;
        getline(file, str1); //get all the content including spaces
        str +=str1;
    }

    transform(str.begin(), str.end(), str.begin(), ::tolower); //convert all the txt to lower case

    int length = str.size(); //get the txt size to loop on it

    for (int i = 0 ; i < length; i++){
        if(i == 0){
            str[i] = toupper(str[i]); //special case to convert the first character to upper case
        }
        else if (str [i-1] == ' '){  //check if the previous character is space so the current character is the first of the word
            str[i] = toupper(str[i]); //convert the first character to upper case
        }
    }
    cout << str;
    file.close(); //close the file to open it again in  write mood so all its content all be deleted
    file.open(fileName, ios:: out);
    file << str; // write the txt after editing in the main file

}

void save(){
    char o;
    cout << "Do you want to save in the (S)ame file or in a (N)ew file ?  ";
    cin >> o;
    if (o == 's'){
       file.close();
    }
    else if (o == 'N'){
        string name;
        ofstream newFile ;
        cout << "What 's the new file name?  ";
        cin.get();
        file.close(); //close the file and open it again to be sure it is on read mood
        file.open(fileName, ios :: in);
        getline(cin , name);
        newFile.open(name);
        newFile << file.rdbuf();
        newFile.close();
        file.close();
    }
}



