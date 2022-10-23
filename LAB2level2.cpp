#include<iostream>
#include<fstream>
#include<cstdlib>
#include<string>
#include<vector>
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
	int countswitch=0;
	int index=0;
	vector<int>countcase;	
	int a=0;
	int i=0;
	string substr[2]={"switch","case"};
	while(getline(inFile,line))
	{
		int a=0;
		index=0; 
		while((index=line.find(substr[0],index))!= line.npos)
		{
			countswitch++;
			index++;
			a=1;				
		}
		int index2=0;
		if(a==1)
		{
			i++;
		}
		while((index2=line.find(substr[1],index2))!= line.npos)
			{
				countcase.push_back(0);
				countcase[i-1]++;
				index2++;				
			}	
	}
	cout<<"switch num: "<<countswitch<<endl;
	cout<<"case num: ";
	for(int j=0;j<i;j++)
	{
		cout<<countcase[j]<<" ";
	}
	return 0;
}
