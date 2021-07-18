#include <iostream>
#include <conio.h>
#include <windows.h>
#define Max 100000

using namespace std;


int main(){
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
			hit=getch(); 
			
			cout<<"Input: "<<(char)hit<<"\t"<<hit<<endl;
			
			if(hit == 'S' || hit == 's'){
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
	}
	
	return 0;
} 
