#include <iostream>
#include <conio.h>
#include <windows.h>
#define Max 60000

using namespace std;


int main(){
	POINT xypos;
	int array_x[Max]={0};	
	int array_y[Max]={0};	
	
	int i=0;
	int hit=0;//press from keyboard
			
	while(1){		
		cout<<"Please input 's'(start recording) or 'e'(execute recording):"<<endl;
		
		hit = getch();
							
		cout<<"Input: "<<(char)hit<<"\t"<<hit<<endl;
		
		if(hit == 's' || hit == 'S'){
			cout<<"Recording."<<endl; 			
			cout<<"Press 'c' to stop."<<endl; 
					
			while(1){					
				GetCursorPos(&xypos);
				cout<<i<<":\t"<<"X:"<<xypos.x<<"\tY:"<<xypos.y<<endl;
				
				array_x[i]=xypos.x;
				array_y[i]=xypos.y;
				i++;
				
				Sleep(100);
				
				if(kbhit()) hit=getch();
				if(hit == 'c' || hit == 'C') break;
				if(i>=Max-1) break;	
			}
			
			i=0;
			cout<<"Stop recording."<<endl;	
		}
		else if(hit == 'e' || hit == 'E'){
			cout<<"Moving."<<endl;
						
			while(!kbhit()){						
				SetCursorPos(array_x[i],array_y[i]);
				cout<<i<<":\t"<<"X:"<<array_x[i]<<"\tY:"<<array_y[i]<<endl;
				
				i++;
				
				Sleep(100);
				
				if(array_x[i] == 0 && array_y[i] == 0) break;	
				
				if(i>=Max-1) break;			
			}
			
			i=0;
			cout<<"Stop moving."<<endl;	
		} 
	}
	
	return 0;
} 
