#include <iostream>
#include <conio.h>
#include <windows.h>
#include <ctime> 
#define Max 60000

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1:0) 

using namespace std;

typedef struct mouse{
	POINT xypos;
	struct cursor* cursor;
	int i=0;
	int kb_hit=0;//press from keyboard	
} mouse_t;


typedef struct cursor{
	int x;
	int y;
	int click; //1=click, 0=unclick 
} cursor_t;

void Delay(int time){//time*1000¬°¬í¼Æ 
	clock_t now = clock(); 
	
	while(clock()-now<time); 
}

int main(){
	mouse_t mouse;
	mouse.cursor=(cursor_t*)calloc(Max,sizeof(cursor_t));
			
	while(1){		
		cout<<"Please input 's'(start recording) or 'e'(execute recording):"<<endl;
		
		mouse.kb_hit = getch();
							
		cout<<"Input: "<<(char)mouse.kb_hit<<"\t"<<mouse.kb_hit<<endl;
		
		if(mouse.kb_hit == 's' || mouse.kb_hit == 'S' || KEY_DOWN(VK_F1)){
			cout<<"Recording."<<endl; 			
			cout<<"Press 'c' to stop."<<endl; 
					
			while(1){					
				GetCursorPos(&mouse.xypos);
				cout<<mouse.i<<":\t"<<"X:"<<mouse.xypos.x<<"\tY:"<<mouse.xypos.y<<endl;
						
				mouse.cursor[mouse.i].x=mouse.xypos.x;
				mouse.cursor[mouse.i].y=mouse.xypos.y;

				if (KEY_DOWN(MOUSE_MOVED)){
            		printf("Mouse clicked.\n");
            		mouse.cursor[mouse.i].click=1;
        		}
        		else{
        			mouse.cursor[mouse.i].click=0;
				}
				
				mouse.i++;
				
				Delay(100);
				
				if(kbhit()) mouse.kb_hit=getch();
				if(mouse.kb_hit == 'c' || mouse.kb_hit == 'C' || KEY_DOWN(VK_F2)) break;
				if(mouse.i>=Max-1) break;	
			}
			
			mouse.i=0;
			cout<<"Stop recording."<<endl;	
		}
		else if(mouse.kb_hit == 'e' || mouse.kb_hit == 'E' || KEY_DOWN(VK_F3)){
			cout<<"Moving."<<endl;
						
			while(1){						
				SetCursorPos(mouse.cursor[mouse.i].x,mouse.cursor[mouse.i].y);
				cout<<mouse.i<<":\t"<<"X:"<<mouse.cursor[mouse.i].x<<"\tY:"<<mouse.cursor[mouse.i].y<<endl;

				if (mouse.cursor[mouse.i].click==1){
            		printf("Mouse clicked.\n");
            		mouse_event(MOUSEEVENTF_LEFTDOWN, 0, 0, 0, 0);   
					Delay(50);  
					mouse_event(MOUSEEVENTF_LEFTUP, 0, 0, 0, 0);  
					Delay(50); 	
        		}				
				
				mouse.i++;
				
				Delay(100);
				
				if(mouse.cursor[mouse.i].x == 0 && mouse.cursor[mouse.i].y == 0) break;	
				
				if(mouse.i>=Max-1) break;			
			}
			
			mouse.i=0;
			cout<<"Stop moving."<<endl;	
		} 
	}
	
	return 0;
} 
