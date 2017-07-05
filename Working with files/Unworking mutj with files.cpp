#include <bits/stdc++.h>
using namespace std;
struct element
	{
	int value;
	int x;
	int y;
	};
int MaxThree(int First, int Second, int Third)	{return max(max(First, 0), max(Second, Third));}
int Check(int FirstSymbol, int SecondSymbol)
	{
	if(FirstSymbol==SecondSymbol) return 1;
	else return -1;
	}
int main()
{
string RefName;
string ReadName;
string ReadQuality;
string ReadUselessLine;
element Maximal;
Maximal.value=0;
Maximal.x=0;
Maximal.y=0;
int x, y, i;
int S;
freopen("result.txt", "w", stdout);
freopen("small_ref.fa", "r", stdin);
string L1, L2;
cin >> RefName >> L1;
freopen("small.fastq", "r", stdin);
cin >> ReadName;
do
	{
	cin >> L2;
	cin >> ReadQuality;
	cin >> ReadQuality;
	int Al[L1.length()+1][L2.length()+1] {0};
	for(i=1;i<=L1.length();i++)	Al[i][0]=0;
	for(i=1;i<=L2.length();i++)	Al[0][i]=0;
	for(x=1;x<=L1.length();x++)	
		for(y=1;y<=L2.length();y++)	
			{
			Al[x][y]=MaxThree(Al[x-1][y-1]+Check(L1[x-1],L2[y-1]), Al[x-1][y]+Check(L1[x-1],'-'), Al[x][y-1]+Check('-',L2[y-1]));
			if(Al[x][y]>=Maximal.value)
				{
				Maximal.value=Al[x][y];
				Maximal.x=x;
				Maximal.y=y;
				}
			}
	int R1=Maximal.x-1, R2=Maximal.y-1;
	stack <char> Result2;
	stack <char> Result1;
	x=Maximal.x;
	y=Maximal.y;
	while(Al[x][y]!=0)
			{
			if(x>0 && y>0 && Al[x][y]==Al[x-1][y-1]+Check(L1[x-1],L2[y-1]))
				{
				x--;
				y--;
				Result1.push(L1[R1]);
				Result2.push(L2[R2]); R1--; R2--;
				}
			if(x>0 && Al[x][y]==Al[x-1][y]+Check(L1[x-1],'-'))
				{
				x--;
				Result1.push(L1[R1]);
				Result2.push('-');
				R1--;
				}
			if(y > 0 && Al[x][y]==Al[x][y-1]+Check('-',L2[y-1]))	
				{
				y--;
				Result1.push('-');
				Result2.push(L2[R2]);
				R2--;
				}
			}
		cout << ReadName << "	" << RefName << "	" << y  << "	" << L2 << "	" << ReadQuality << "\n";
		ReadName.clear();
		cin >> ReadName;
	}
while(ReadName.length()!=0);
return 0;
}
