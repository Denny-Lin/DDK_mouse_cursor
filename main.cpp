#include <iostream>
#include <conio.h>
#include <windows.h>

using namespace std;

int main(){
	
	while(1){
		char g = 0;
		int x = 0;
		int y = 0;
		POINT xypos;
		
		g = getch();
		
		if(g == 'S' || g == 's'){
			cout<<"Enter the new position:"<<endl;
			
			cin>>x>>y;
			
			SetCursorPos(x,y);
		}
		else if(g == 'g' || g == 'G'){
			GetCursorPos(&xypos);
			
			cout<<"X:"<<xypos.x<<"\tY:"<<xypos.y<<endl;
		}	
	}
	
	return 0;
} 
