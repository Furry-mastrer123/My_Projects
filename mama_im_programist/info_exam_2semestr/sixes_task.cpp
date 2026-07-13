#include <fstream>
#include <string>
#include <iostream>
#include <map>


using namespace std;

int main(int argc, char* argvp[])
{
    fstream f;
    f.open("textt.txt", ios::in);
    string text;
    if (f.is_open()) {                  //proverka na !f.si_aopen() bila nevernoy
    getline(f, text);
                     }

    
    cout << text;

    
    string word;
    cin >> word;



    std::map <char, int> Word;



    for(int a = 0; a <word.size(); a++)
    {
        Word.insert(make_pair(word.at(a), 0));              //bila oshibka - zapisival Word.at(a) < no eto map tam eshe pusto
    }


    for(int a =0; a< text.size(); a++)
    {
        if(Word.find(text.at(a)) != Word.end())
        {
        auto it = Word.find(text.at(a));
        it->second++;
        }
    }

    for(int a = 0; a <word.size(); a++)
    {
        cout << Word[word.at(a)] <<  std::endl; 
    }



    f.close();
    int on; 
    cin >> on;
    return 0;
}