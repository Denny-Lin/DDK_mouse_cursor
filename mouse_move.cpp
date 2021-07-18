#include <iostream>
#include <conio.h>
#include <windows.h>
#define Max 100000

using namespace std;


int main(){
	char g = 0;
	int x = 0;
	int y = 0;
	POINT xypos;
	int array_x[Max]={0};	
	int array_y[Max]={0};	
	
	int i=0;
	int hit=0;
			
	while(1){
		
		cout<<"Waiting."<<endl;
		hit = kbhit();
		hit=0;
		
		if(!hit){ 
			g=(char)getch(); 
			
			cout<<"Input: "<<(int)g<<"\t"<<g<<endl;
			
			if(g == 'S' || g == 's'){
				cout<<"Recording."<<endl; 			
						
				while(!kbhit()){					
					GetCursorPos(&xypos);
					cout<<"X:"<<xypos.x<<"\tY:"<<xypos.y<<endl;
					
					array_x[i]=xypos.x;
					array_y[i]=xypos.y;
					i++;
					
					Sleep(100);

					if(i>=Max-1) break;	
				}
				
				i=0;
				cout<<"Stop recording."<<endl;	
			}
			else if(g == 'e' || g == 'E'){
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
				cout<<"Stop Moving."<<endl;	
			} 
		}	
	}
	
	return 0;
} 
