#include <iostream>
using namespace std;

void go(int &n, int a)
{
	int k = 1;
	int x=0, y=0;
	while(true) {
		
	if(x<n-1 && y<n-1 && a[x][y+1]==0) {
		a[x][++y]=k; ++k;
		continue;
	}
	else if(x<n-1 && y<n-1 && a[x+1][y]==0) {
		a[++x][y]=k; ++k;
		continue;
	}
	else if(x<n-1 && y<n-1 && a[x][y-1]==0) {
		a[x][--y]=k; ++k;
		continue;
	}
	else if(x<n-1 && y<n-1 && a[x-1][y]==0) {
		a[--x][y]=k; ++k;
		continue;
	}
	break;
	
	}
}

int main()
{
	int n;
	while(cin>>n, n!=0)
	{
		int a[20][20] = {0};
		go( n, a);
		for(int i=0; i<n; ++i)
		{
			for(int j=0; j<n; ++j)
			{
				cout << a[i][j] << "  ";
			}
			cout << endl;
		}
	}
}
