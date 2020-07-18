/*
Name: Kyle Suarez
Date: Feb 1, 2019
Class: Data Structures (COP4530)
Project 1: Word, Number, and Character Usage Statistics
*/
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
using std::setw;

int main() {
  ifstream fin;
  ofstream fout;

  string Filename;

  // Reads in file for analysis
  do {
    cout << "Please enter the name of file to be read:\n";
    getline(cin, Filename, '\n');

    fin.open(Filename.c_str());
    if (!fin)
      cout << "Please try again." << endl;

  } while (!fin);

  // Extract file contents
  string fcontents;
  char datagrab;
  while (fin.get(datagrab)) {
    fcontents += datagrab;
  }

  string worddata;

  worddata = fcontents; // creates a copy of the data to be used when analyzing
                        // for mostUsedWords

  sort(fcontents.begin(), fcontents.end());

  // Tallying up all characters in file

  int ctrack;
  string characters;
  int ctotal[128];

  for (int i = 0; i < 128; i++) {
    ctotal[i] = 0;
  }

  ctrack = 0;
  ctotal[ctrack] = 1;

  for (int i = 0; i < fcontents.length(); i++) {
    if (fcontents[i] == fcontents[i + 1]) // checks to see if the next character
                                          // is still the same
    {
      ctotal[ctrack] = ctotal[ctrack] + 1;
    } else {
      characters[ctrack] = fcontents[i];
      ctrack++;
      ctotal[ctrack] = 1;
    }
  }

  // Organize characters from most used to least used
  int ntemp;
  char ctemp;
  int i, j, flag = 1; // set flag to 1 to start first pass
  int numLength = 128;
  for (i = 1; (i <= numLength) && flag; i++) {
    flag = 0;
    for (j = 0; j < (numLength - 1); j++) {
      if (ctotal[j + 1] > ctotal[j]) // ascending order simply changes to <
      {
        ntemp = ctotal[j];
        ctotal[j] = ctotal[j + 1];
        ctotal[j + 1] = ntemp;
        flag = 1; // indicates that a swap occurred.
        ctemp = characters[j];
        characters[j] = characters[j + 1];
        characters[j + 1] = ctemp;
      }
    }
  }
  int ccount = ctrack; // used for printing

  // Tallying up words in the File
  int wflag = 0;
  int wtrack = 0;
  int cword = 0;
  string words[10000];
  int wtotal[10000];

  while (cword < worddata.length() + 1) {
    if (worddata[cword] > 96 && worddata[cword] < 123) {
      words[wtrack] += worddata[cword];
      wflag = 0;
    } else if (worddata[cword] > 64 && worddata[cword] < 91) {
      words[wtrack] += (worddata[cword] + 32);
      wflag = 0;
    } else {
      if (wflag == 0) {
        for (int i = 0; i < wtrack; i++) {
          if (words[i] == words[wtrack]) {
            words[wtrack] = "";
            wtotal[i]++;
            wtotal[wtrack] = 0;
            wtrack--;
          }
        }
        wtrack++;
        wflag = 1;
      }
    }
    cword++;
  }

  // Sorting words by how often they appear
  string wtemp;
  i = j = flag = 1; // set flag to 1 to start first pass
  numLength = 10000;
  for (i = 1; (i <= numLength) && flag; i++) {
    flag = 0;
    for (j = 0; j < (numLength - 1); j++) {
      if (wtotal[j + 1] > wtotal[j]) // ascending order simply changes to <
      {
        ntemp = wtotal[j];
        wtotal[j] = wtotal[j + 1];
        wtotal[j + 1] = ntemp;
        flag = 1; // indicates that a swap occurred.
        wtemp = words[j];
        words[j] = words[j + 1];
        words[j + 1] = wtemp;
      }
    }
  }
  int wcount = wtrack; // used for printing

  // Tallying up all numbers in the file
  int nflag = 1;
  int ntrack = 0;
  int ndigit = 0;
  string numbers[10000];
  int ntotal[10000];

  while (ndigit < worddata.length()) {
    if (worddata[ndigit] > 47 && worddata[ndigit] < 58) {
      numbers[ntrack] += worddata[ndigit];
      nflag = 0;
    } else {
      if (nflag == 0) {
        for (int i = 0; i < ntrack; i++) {
          if (numbers[i] == numbers[ntrack]) {
            numbers[ntrack] = "";
            ntotal[i]++;
            ntotal[ntrack] = 0;
            ntrack--;
          }
        }
        ntrack++;
        nflag = 1;
      }
    }
    ndigit++;
  }

  // Sorting numbers by how often they appear
  string dtemp;
  i = j = flag = 1; // set flag to 1 to start first pass
  numLength = 10000;
  for (i = 1; (i <= numLength) && flag; i++) {
    flag = 0;
    for (j = 0; j < (numLength - 1); j++) {
      if (ntotal[j + 1] > ntotal[j]) // ascending order simply changes to <
      {
        ntemp = ntotal[j];
        ntotal[j] = ntotal[j + 1];
        ntotal[j + 1] = ntemp;
        flag = 1; // indicates that a swap occurred.
        dtemp = numbers[j];
        numbers[j] = numbers[j + 1];
        numbers[j + 1] = dtemp;
      }
    }
  }
  int ncount = ntrack; // used for printing

  // The print out of results

  // Character Results
  int cprint;
  cout << "Total " << ccount << " different characters, ";
  if (ccount < 10) {
    cprint = ccount;
    cout << ccount;
  } else {
    cout << "10";
    cprint = 10;
  }
  cout << " most used characters:\n";
  for (int i = 0; i < cprint; i++) {
    cout << "No." << i << ": ";
    if (characters[i] == 10)
      cout << "\\n";
    else
      cout << characters[i] << "     ";
    cout << "     " << ctotal[i] << endl;
  }

  // Word Results
  int wprint;
  int longestword = 0;

  cout << "Total " << wcount << " different words, ";
  if (wcount < 10) {
    wprint = wcount;
    cout << wcount;
  } else {
    cout << "10";
    wprint = 10;
  }
  cout << " most used words:\n";

  for(int i = 0; i < wprint; i++)
  {
    if(longestword < words[i].length())
      longestword = words[i].length();
  }
  for (int i = 0; i < wprint; i++) {
    cout << "No." << i << ": " << words[i] << setw(longestword + 5 - words[i].length())
         << wtotal[i] + 1 << endl;
  }

  // Number Results
  int nprint;
  int longestnumber = 0;

  cout << "Total " << ncount << " different numbers, ";
  if (ncount < 10) {
    cout << ncount;
    nprint = ncount;
  } else {
    cout << "10";
    nprint = 10;
  }
  cout << " most used numbers:\n";

  for(int i = 0; i < nprint; i++)
  {
    if(longestnumber < numbers[i].length())
      longestnumber = numbers[i].length();
  }
  
  for (int i = 0; i < nprint; i++) {
    cout << "No." << i << ": " << numbers[i] << setw(longestnumber + 5 - numbers[i].length())
         << ntotal[i] + 1 << endl;
  }

  fin.close();

  return 0;
}
