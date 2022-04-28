#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <cstring>
#include<vector>
#include<sstream>
#include"CS112-203-2nd-S1-20210049-20210067-20210133-A4-TextEditorFunc.h"
using namespace std;
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
        if(vector_file[i]=='z'){file<<'a';}
        else if(vector_file[i]=='Z'){file<<'A';}
        else{file << (char)(vector_file[i]+1);} // shifting every character except z
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
        if(vectorFile[i]=='a'){file<<'z';}
        else if(vectorFile[i]=='A'){file<<'Z';}
        else{file << (char)(vectorFile[i]-1);}
    }

    cout << "file decrypted succesfully"<<endl;
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
void merge()
{
    file.open(fileName,ios::app | ios::out);
    fstream file1;
    string file1name;
    cout << "enter the second file name (.txt) : ";
    cin.ignore();
    getline(cin,file1name);
    file1.open(file1name,ios::in);
    while(!file1)
    {
        cout <<"Invalid File Name\n";
        cout << "enter the second file name (.txt) : ";
        getline(cin,file1name);
        file1.open(file1name,ios::in);
    }
    string line;
    while(getline(file1,line))
    {
        file << line << endl;
    }
    file1.close();
    file.close();
    cout << "\nDONE\n";
}
void count_words()
{
    file.open(fileName,ios::in);
    string word;
    int counter=0;
    while(file >> word)
    {
        counter++;
    }
    file.close();
    cout << "The number of words in the file = " << counter<<endl;
}
void count_chars()
{
    file.open(fileName,ios::in);
    string word;
    int counter=0;
    while(file >> word)
    {
        counter++;
    }
    file.close();
    file.open(fileName,ios::in);
    int i=0;
    string arr[counter];
    while(file >> word)
    {
        arr[i]=word;
        i++;
    }
    file.close();
    int num=0;
    for(int j=0;j<counter;j++)
    {
        num=num+arr[j].size();
    }
    cout << "the number of chars = " << num+counter-1 << endl;
}

void count_lines()
{
    file.open(fileName,ios::in);
    string line;
    int counter=0;
    while(getline(file,line))
    {
        counter++;
    }
    file.close();
    cout << "The number of lines in the file = " << counter<<endl;
}
void search_word()
{
    cin.ignore();
    string input;
    cout << "Enter a word to search for : ";
    cin >> input;
    for_each(input.begin(), input.end(), [](char & c){c = toupper(c);});
    file.open(fileName,ios::in);
    string word;
    bool flag=true;
    while(file >> word)
    {
        for_each(word.begin(), word.end(), [](char & c){c = toupper(c);});
        if(word == input)
        {
            cout << "Word was found in the file " << char(1)<<endl;
            flag=true;
            break;
        }
        else
        {
            flag=false;
        }
    }
    if(flag==false)
    {
        cout << "Word was not found in the file" << endl;
    }
    file.close();}


