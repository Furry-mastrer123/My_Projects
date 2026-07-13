#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	string buff;
	map<string, int> dictionary;
	ifstream ifs("readme.txt");


	if (!ifs.is_open())
	{
		cerr << "Error, couldn`t open file";
		return 0;
	}


	while (!ifs.eof())
	{
		std::getline(ifs, buff);
		string buff_2 = "";
		for (auto it : buff)
		{
			if (it != ' ' && it != ',' && it != '.' && it != '/n')
			{
				char MMM = tolower(it);
				buff_2 += MMM;
			}
			else
			{
				if (it == ' ' || it == '.' || it == '/n' || it == ',')
				{
					if(!buff_2.empty())
					{
						if (dictionary[buff_2] == 0)
						{
							dictionary[buff_2] = 1;
							buff_2 = "";
						}
						else
						{
							dictionary.at(buff_2) += 1;
							buff_2 = "";
						}
					}
				}

			}
		}
	}


	ifs.close();

	ofstream ofs("word_freq.txt");


	if (!ofs.is_open())
	{
		cerr << "there`s no ability to open file now";
		return 0;
	}

	auto it = dictionary.begin();

	while (it != dictionary.end())
	{
		ofs << "word " << it->first << " is met " << it->second << " times" << endl;
		cout << setw(15) << it->first<< " " << it->second << endl;
		it++;
	}

	ofs.close();

	return 0;
}