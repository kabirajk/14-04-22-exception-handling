#include <iostream>
#include <fstream>
using namespace std;
//check a file is present or not
int main () 
{
  fstream myfile;//input file stream
  try
  {
      myfile.open("mytext.txt");
      if (!myfile.is_open())
        throw "!File not found";//throwing string
  }
  catch(const char *c)
  {//
      cerr<<c;//"File not found";

      //output file stream
      ofstream myfile("mytext.txt");//ostream create afile named mytext if not found
  }
  
  myfile<<"//this text is insterted by using fstream";
  myfile<<"\n//this text is insterted by using fstream";
  myfile.close();

  ifstream input;
  try
  {
    input.open("mytext.txt");
    if(!input.is_open())
        throw "File not found istream";


    //this statement read the file char by char until the eof//end of file comes
  cout<<"\n#==============textfile================#"<<endl;
    while (!input.eof())
        {
          cout<<(char)input.get();
        }
  cout<<"\n#=======================================#"<<endl;
    
    //this satement read line by line so it neads a string to fold the line

    //!!!the charters are now get  from file object so use carfully
    //we need to re-position the the file to initital 
    //1. clear the flagtate
    input.clear();
    //2.by using seekg to get  the position
    input.seekg(0, ios::beg);
  cout<<"\n#==============textfile================#"<<endl;

    string line;//line holds the whole everyline
    while (getline(input,line))
        cout<<line<<endl;//a single is at a ones a time soline holds the last line after iterations
    //this reads until the last 
    //getline act as cin for reading the lines in text(file) so a string is needed to pass
    //now line has the whole files string in it
  cout<<"\n#=======================================#"<<endl;
  
    input.close();
  }
  catch(const char * c)
  {
    cerr<<c;
  }
  cout<<"\nend file closed"<<endl;
return 0;
}