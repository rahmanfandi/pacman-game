#include <allegro.h>        //**berisi layar2 tampilan awal dan lingker**
#include <iostream>
using namespace std;
#include <head.h>
#include <peta.h>
#include <move.h>
#include <tullisan.h>

#define i  (p.v/25)
#define t  (p.h/25)
#define vd ((p.v+12)/25)
#define vu ((p.v-12)/25)
#define hd ((p.h+12)/25)
#define hu ((p.h-12)/25)

#define mi  (M[mus].v/25)
#define mt  (M[mus].h/25)
#define mvd ((M[mus].v+12)/25)
#define mvu ((M[mus].v-12)/25)
#define mhd ((M[mus].h+12)/25)
#define mhu ((M[mus].h-12)/25)
#define mbx mouse_x 
#define mby mouse_y 


#define disain_grafis             frengky(0);
#define disain_pemrograman        frengky(0);
#define disain_AI                 frengky(0);
#define disain_soundtrack         frengky(0);
#define disain_permainan          frengky(0);
#define XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX frengky(0);
#define geser  while(pos[4]>=0-500){pos[4]-=1;masked_blit(menu,screen,0,0,0+pos[4],100,500,253);}
#define gser1 play_sample(pnlopn, 255, 0, 1000, 0);
#define gser2 play_sample(pnlcls, 255, 0, 1000, 0);
#define klikk play_sample(klik, 255, 0, 1000, 0);
#define XX  frengky(0);
#define TERSANGKA int anggota(){

int fengky_arga_pratama (int c){}             
int frengky            (int c){}        
int fandisya_rahman    (int c){}            
int failla_fuadi      (int c){} 
int ahaddin_gani        (int c){}     


SAMPLE *dead;
SAMPLE *suling; 
SAMPLE *klik;
SAMPLE *klikover;
SAMPLE *panel;
SAMPLE *menangg;
SAMPLE *gemover;
SAMPLE *pnlopn;
SAMPLE *pnlcls;
MIDI *music;
    

BITMAP *buffer; 
BITMAP *pesanfull;

void game();
void menu();

void load_suara()
{
pnlopn = load_sample("son/openpanel.wav");
pnlcls = load_sample("son/closepanel.wav");
klik = load_sample("son/klick.wav");
gemover = load_sample("son/gameover.wav");
}


void buyar(){
BITMAP *gameover;   
int R=0,in;
play_sample(gemover, 255, 0, 1000, 0);
gameover = load_bitmap("pic/gameover.bmp",NULL); 

while(!key[KEY_SPACE]){
if (R >= 255)in=0;
if (R <=  0)in=1;  
if (in == 0)R-=1;
if (in == 1)R+=1;  
masked_blit(gameover,buffer,0,0,0,0,500,500);
blit(buffer,screen,0,0,0,0,500,500);
clear_to_color(buffer,makecol(R,0,0));
}

}






int nyawa=3;
void mati()
{int D=20;
play_sample(dead, 255, 0, 1000, 0);
while(D > 0){      
clear_to_color(kuningh,makecol(255,0,255));
D--;
blit(maze,buffer,0,0,0,0,500,500);
circlefill(kuningh,20,20,D,makecol(255,255,0));
draw_sprite(buffer,kuningh,p.h-20,p.v-20);
for(int mus = 1;mus<5;mus++)
{draw_sprite(buffer,hantu[mus],M[mus].h-20,M[mus].v-20);} 
blit(buffer, screen, 0,0,0,0,500,500);
clear_bitmap(buffer);
rest(40);
}
nyawa --;
if (nyawa < 1)buyar();
while(!key[KEY_SPACE]){}
      
p.dirv=0;                                                              
p.dirh=0;
p.h=275-10;                                                                 
p.v=325-10;                                                                 
p.hdp=1;                                                                    
    M[1].h=9*25;                                                               
    M[1].v=7*25 ;                                                                
    M[2].h=10*25;                                                               
    M[2].v=8*25 ;                                                                
    M[3].h=11*25;                                                               
    M[3].v=7*25 ;                                                                
    M[4].h=12*25;                                                               
    M[4].v=8*25 ;                                                                
    for(int mus = 1;mus<5;mus++){                                                 
    M[mus].dirv=0;                                                                
    M[mus].dirh=0;                                                               
    M[mus].hdp=3; 

}


    

}

void menang()
{}

///////////////////////////////////////////////////////////////////////////////

    

void masuk(){



BITMAP *logo=load_bitmap("pic/logo.bmp",NULL);
masked_blit(logo,screen,0,0,50,30,500,500);
rest(3000);

destroy_bitmap(logo);
//readkey();


}
void masuk2()
{

BITMAP *nama=load_bitmap("pic/menu.bmp",NULL);

mumet();


int hb=0;
int b[5];
p.v=360,p.h=520;
for(int mus = 1;mus<5;mus++){M[mus].v=100+mus*50; M[mus].h=520;b[mus]=0;}
b[0]=0;
while(!key[KEY_SPACE]){rest(10);
hb+=5;if(hb > 80)hb= 0;  


     if (M[1].h>330  )M[1].h-=2;        
else if (M[2].h>330  ){b[1]=1;M[2].h-=2;}
else if (M[3].h>330  ){b[2]=1;M[3].h-=2;}
else if (M[4].h>330  ){b[3]=1;M[4].h-=2;}
else if (p.h>330     ){b[4]=1;p.h-=1;}
else {b[5]=1;b[0]++;}


if (b[1]==1)blit(nama,buffer,12,402,200,150,119,30);
if (b[2]==1)blit(nama,buffer,12,431,200,200,119,30);
if (b[3]==1)blit(nama,buffer,12,462,200,250,119,30);
if (b[4]==1)blit(nama,buffer,12,495,200,300,119,30);
if (b[5]==1)blit(nama,buffer,12,526,200,350,119,30);
if(b[0]>100){b[0]++; break;}

for(int mus = 1;mus<5;mus++){musuh1(hb,1,mus);}                    
for(int mus = 1;mus<5;mus++){draw_sprite(buffer,hantu[mus],M[mus].h-20,M[mus].v-20);}

gico(hb,1);draw_sprite(buffer,kuningh,p.h-20,p.v-20);    
blit(buffer,screen,0,0,0,0,500,500);
clear_to_color(buffer,makecol(0,0,0));
}
}    


void profil(){
BITMAP *kayu=load_bitmap("pic/geni.bmp",NULL);
BITMAP *logo3=load_bitmap("pic/logo3.bmp",NULL);
BITMAP *cursor=load_bitmap("pic/cursor1.bmp",NULL);
BITMAP *menu=load_bitmap("pic/menu.bmp",NULL);
BITMAP *tombol;
tombol=create_bitmap(107,29);
int logox=0-500,logoy=90,logop=500,pos=0,b;
gser1;
while(1){
if(logox<50)logox++;
blit(kayu,buffer,0,0,0,0,500,500);

if(mbx > 62  && mbx < tombol->w+62 && 
   mby > 103 && mby < tombol->h+103){if(b==0)klikk;b=1;}
else b=0;

if(b==1){pos++;}if(pos > 300)pos=0;
if(pos > 0  && b==0 )pos=0;
if(b== 1 && (mouse_b & 1))break;

blit(menu,logo3,1+pos,347,13,122,105,26);
masked_blit(logo3,buffer,0,110,logox,logoy,500,logop);
draw_sprite(buffer,cursor,mouse_x,mouse_y);
blit(buffer,screen,0,0,0,0,500,500);
}     
gser2;
while(logox>0-500){
logox-=1;
blit(kayu,buffer,0,0,0,0,500,500);
masked_blit(logo3,buffer,0,110,logox,logoy,500,logop);
draw_sprite(buffer,cursor,mouse_x,mouse_y);
blit(buffer,screen,0,0,0,0,500,500);
}

}




void menu(){

BITMAP *cursor=load_bitmap("pic/cursor1.bmp",NULL);
BITMAP *cursor2=load_bitmap("pic/cursor21.bmp",NULL);
BITMAP *kayu=load_bitmap("pic/geni.bmp",NULL);
BITMAP *menu=load_bitmap("pic/menu.bmp",NULL);
BITMAP *tombol[4];
tombol[1]=create_bitmap(107,29);
tombol[2]=create_bitmap(107,29);
tombol[3]=create_bitmap(107,29);
struct{int x,y;}u[100];
int pos[5]={75,75,75,75};
int b[4],bx[4],by[4];
bx[1]=bx[2]=bx[3]=69;
by[1]=63;by[2]=98;by[3]=133;
int waktu;
for(int li=1;li<30;li++)u[li].x=u[li].y=400;
pos[4]=-500;
gser1;
while(1){
waktu++; if (waktu >1)waktu=0;

for(int li=1;li<4;li++){
if(mbx > bx[li] && mbx < tombol[li]->w+bx[li]  &&  
   mby > by[li]+100 && mby < tombol[li]->h+by[li]+100){if(b[li]==0)klikk;b[li]=1;}
else b[li]=0;
if(pos[li] > 0  && b[li]==1 ){ pos[li]--;}
if(pos[li] < 75 && b[li]==0 )pos[li]++;
}

if(b[1]== 1 && (mouse_b & 1)){gser2;geser;game();gser1}
if(b[2]== 1 && (mouse_b & 1)){gser2;geser;profil();gser1}
if(b[3]== 1 && (mouse_b & 1)){gser2;geser;break;}

if(pos[4]<=0)pos[4]+=2;

blit(menu,tombol[1],1+pos[1],254,0,0,104,30);
blit(menu,tombol[2],1+pos[2],285,0,0,104,30);
blit(menu,tombol[3],1+pos[3],316,0,0,104,30);

for(int li=1;li<4;li++)blit(tombol[li],menu,0,0,bx[li]-1,by[li],106,27);

if(waktu  < 1){
if(u[1].y < mby )u[1].y+=1;
else if(u[1].y > mby )u[1].y-=1;
else if(u[1].x < mbx )u[1].x+=1;
else if(u[1].x > mbx )u[1].x-=1;

for(int li=99;li>1;li--){
u[li].x=u[li-1].x;
u[li].y=u[li-1].y;
}}




blit(kayu,buffer,0,0,0,0,500,600);
masked_blit(menu,buffer,0,0,0+pos[4],100,500,253);



for(int li=1;li<100;li++)draw_sprite(buffer,cursor2,u[li].x-5,u[li].y-5);
draw_sprite(buffer,cursor,mbx-5,mby-5);
blit(buffer,screen,0,0,0,0,500,600);

}
}



void end()
{BITMAP *end=load_bitmap("pic/end.bmp",NULL);
blit(end,screen,0,0,0,0,500,500);

rest(10000);
readkey();}






void mulaii()
{int bb;
while(!key[KEY_SPACE]){bb++; if (bb>800)bb=0;
blit(maze, buffer, 0,0,0,0,500,500); 
draw_sprite(buffer,kuningh,p.h-20,p.v-20);                                                                                               
for(int mus = 1;mus<5;mus++)
draw_sprite(buffer,hantu[mus],M[mus].h-20,M[mus].v-20);                                
if(bb>400)blit(pesanfull,buffer,0,0,200,130,140,20);
blit(buffer, screen, 0,0,0,0,500,550); 
}
}

