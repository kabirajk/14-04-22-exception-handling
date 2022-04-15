#include <iostream>
#include <fstream>
// #include <cstdio>
using namespace std;

int main()
{   
    fstream input;
    try
    {   
        input.open("mytext.txt");
        if (!input.is_open())
            throw "File not found";
        {
            while (1)
            {
                try
                {
                    int c=input.get();
                    if (c>127)
                        throw "ooPs";
                    if (c==-1)
                        throw -1;
                    cout<<(char) c;

                }
                catch(int i)
                {
                    cout<<"\n#==end of file===#"<<endl;
                    break;
                }
                catch(...)
                {
                    cout<<"Beyond the ascii range values are here so use unicode";
                }
            }
            
        }
    }
    catch(const char * c)
    {
        cout<<c<<endl;
        cout<<"created an empty file"<<endl;
        ofstream create("mytext.txt");
    }
    catch(...)
    {
        cout<<"this the catch all block"<<endl;
    }
  
    try
    {
        if (input.get()==-1)
            throw "end of file";
    }
    catch(const char * c)
    {
        cerr<<c<<'\n';
        input.clear();
        input.seekg(0,ios::beg);
    }
    
    while (1)
    {
        try
        {
            int c=input.get();
            if (c>127)
                throw "ooPs";
            if (c==-1)
                throw -1;
            cout<<(char) c;

        }
        catch(int i)
        {
            cout<<"\n#==end of file===#"<<endl;
            break;
        }
    }
  return 0;
}
