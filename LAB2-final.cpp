#include<iostream>
#include<string>
#include<fstream>
#include<sstream>
#include<cstdlib>
#include<vector>
using namespace std;
string keyword[32]={
    "auto","break","case","char","const","continue","default","do","double","else","enum","extern","float","for",	"goto",
	"if","int","long","register","return","short","signed",	"sizeof","static","struct",	"switch","typedef","union",	"unsigned",	
	"void","volatile", "while"
	};
	vector<int>countcase;
	vector<int>count;	
	int countkeyword=0;
	int countswitch=0;
	int a=0;
	int i=0;
	int countifelse=0;
	int countif=0;
	int main ()
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
		int level;					
		cout<<"Enter the level:"<<endl;
		cin>>level;
		
		int check1(string str,string substr);
		int check2(string str,string substr);	
		void counttotal(string str);			
		void countsc(string str2);			
		void countiee(string str3);		
		 
		while(getline(inFile,line))			
		{
			if(level>=3)
				countiee(line);           
			if(level>=1)
				counttotal(line);
			if(level>=2)
				countsc(line);
		}
		if(level>=1)
			cout<<"total num: "<<countkeyword<<endl;
		if(level>=2)
		{
			cout<<"switch num: "<<countswitch<<endl;
			cout<<"case num: ";
			for(int j=0;j<i;j++)
			cout<<countcase[j]<<" ";
			cout<<endl;
				
		}
		if(level>=3)
		{
			for(int k=0;k<count.size();k++)
			{
				if(count[k]==1)
				{
					countif++;
					if(count[k+1]==3)
					{
						countifelse++;
					}
				}
			}
			cout<<"if-else num: "<<countifelse<<endl;
		}
		if(level>=4)
		{
			cout<<"if-elseif-else num: "<<countif-countifelse<<endl;
		}
	}
	
	int check1(string str,string substr)	
	{
		int index=str.find(substr,0);
		int len=substr.length();
		if(index!=string::npos)
		{
			if(index==0)
			{
				if(isalpha(str[index+len])==0)
					return 1;
				else 
					return 0;
			}
			else
			{
				if(isalpha(str[index-1])==0&&isalpha(str[index+len])==0)
					return 1;
				else
					return 0;
			}
		}
		return 0;
	}
	int check2(string str,string substr)	
	{
		int index=str.find(substr,0);
		int len=substr.length();
		if(index!=string::npos)
		{
			if(str[index]==char('i')&&str[index-2]==char('e'))return 0;
			if(str[index]==char('e')&&str[index+5]==char('i')&&len==4)return 0;
			if(index==0)
			{
				if(isalpha(str[index+len])==0)
					return 1;
				else 
					return 0;
			}
			else
			{
				if(isalpha(str[index-1])==0&&isalpha(str[index+len])==0)
					return 1;
				else
					return 0;
			}
		}
		return 0;
	}
	void counttotal(string str)		
	{
		for(int i=0;i<32;i++)			
		{
			if(check1(str,keyword[i])==1)
			{
				countkeyword++;
			}
		}
	}		
	void countsc(string str2)		
	{
		int a=0; 
		if(check1(str2,"switch")==1)
		{
			countswitch++;
			a=1;				
		}
		if(a==1)
		{
			i++;
		}
		if(check1(str2,"case")==1)
			{
				countcase.push_back(0);
				countcase[i-1]++;				
			}	
	}
	
	void countiee(string str3)		
	{
        if(check2(str3, "if"))
		{
            count.push_back(1);
        } 	
		if(check2(str3, "else if"))
		{
        	count.push_back(2);
     	}
     	if(check2(str3, "else"))
        {
        	count.push_back(3);
		}
	}
