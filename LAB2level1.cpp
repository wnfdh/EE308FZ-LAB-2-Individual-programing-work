#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
using namespace std;
int main()
{
	string filename = "test.txt";
	string line;
	ifstream inFile;
	inFile.open(filename.c_str());
	if(inFile.fail())
	{
		cout<<"file was not successfully opened";
		exit(1);
	}
	int count=0;
	int countdouble=0;
	int index=0;
	string substr[32]=
	{"auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for",	"goto",
	"if","int","long","register","return","short","signed",	"sizeof","static","struct",	"switch","typedef","union",	"unsigned",	"void","volatile",	"while"
	};
	while(getline(inFile,line))
	{
		cout<<line<<endl;
		for(int j=0;j<32;j++)
		{
			index=0; 
			while((index=line.find(substr[j],index))!= line.npos)//find（str,int i）从第i个字符找出现的字符 找不到返回npos转为int型为-1 
			{
				if(line[index+2]==char('u'))
				{
					cout<<"detect"<<endl;
					countdouble++;
				}
				count++;
				index++;				
			}
		}
	}
	cout<<count-countdouble+1;
	inFile.close(); 
	return 0;
}
