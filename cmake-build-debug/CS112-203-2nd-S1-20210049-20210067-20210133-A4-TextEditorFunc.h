//
// Created by hp on 4/28/2022.
//

#ifndef TEXT_EDITOR__CS112_203_2ND_S1_20210049_20210067_20210133_A4_TEXTEDITORFUNC_H
#define TEXT_EDITOR__CS112_203_2ND_S1_20210049_20210067_20210133_A4_TEXTEDITORFUNC_H
#include<fstream>
using namespace std;
char fileName[81];
fstream file;
void countWord( fstream & file);
void appendText(fstream &file);
void Displaycontent(fstream&file);
void empty_file(fstream&file);
void encrypt(fstream&file);

void merge();
void count_words();
void count_chars();
void count_lines();
void search_word();

void decrypt(fstream&file);
void upperCase(fstream &file);
void lowerCase(fstream &file);
void firstIsUpper (fstream & file);
void save();

#endif //TEXT_EDITOR__CS112_203_2ND_S1_20210049_20210067_20210133_A4_TEXTEDITORFUNC_H
