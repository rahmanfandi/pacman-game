//#include <intro.h>





BITMAP *kar;
BITMAP tulis(char sra[30],BITMAP *tujuan,int x,int y)
{
int sr[30];
for(int f=0 ;f<30 ;f++)sr[f]=0;
for(int f=0 ;f<30 ;f++)sr[f]=sra[f]-96;
int re=0;
for(int f=0 ;f<30 ;f++)
{
masked_blit(kar,tujuan,(sr[f]-1)*15,17,x+re,y,16,25);
if     (sr[f]==13 || sr[f]==23) re=re+15;
else if(sr[f]==12 || sr[f]==9)  re=re+5;
else  if(sr[f] !=0)             re=re+11;
cout<<sra;
}
}


BITMAP *nomor;
BITMAP *tampilnomor;
BITMAP angka(int nilai,BITMAP *tujuan,int x,int y)
{
int ds[7],lii=1,icn=0;;
clear_to_color(tampilnomor,makecol(255,0,255));
while(icn<6){ds[icn]=(nilai/lii)-(nilai/(lii*10))*10;lii=lii*10;icn++;}
for(int li=0;li<6;li++)blit(nomor,tampilnomor,ds[li]*17,0,(5-li)*13,0,15,15);
draw_sprite(tujuan,tampilnomor,x,y);
}
void settulisan()
{
kar=load_bitmap("pic/nomer.bmp",NULL);     
tampilnomor=create_bitmap(100,25);
nomor=load_bitmap("pic/nomer.bmp",NULL);
}









void huruf()
{ 

char sra[50];
int  sr[50];
int pos=0,b=0,c=0;
int re=0;
int nilai;
BITMAP *karakter=load_bitmap("pic/nomer.bmp",NULL);
BITMAP *pesan=load_bitmap("pic/pesan.bmp",NULL);
BITMAP *kata=create_bitmap(400,25);
BITMAP *buff=create_bitmap(400,25);
SAMPLE *intromusik = load_sample("son/klick.wav");

clear_to_color(screen,makecol(0,0,0));

FILE *g;
for(int f=0 ;f<50 ;f++)sr[f]=0;
blit(pesan,buff,0,72,20,70,300,20);
char tt[20]="ketik nama         ";
tulis(tt,screen,70,100);
while(!key[59]){
if(b>0) b--;if(c<0)c=2000;c--;
for(int f=0 ;f<27 ;f++)
if(key[f]  && b<1){sr[pos]=f;pos++;b=1000;}
if(key[75] && b<1){sr[pos]=-96+95;pos++;b=1000;}
if(key[63] && b<1){pos--;sr[pos]=0;b=1000;}

re=0;
for(int f=0 ;f<30 ;f++){
masked_blit(karakter,kata,(sr[f]-1)*15,17,re,0,16,25);
if     (sr[f]==13 || sr[f]==23) re=re+15;
else if(sr[f]==12 || sr[f]==9)  re=re+5;
else  if(sr[f] !=0)             re=re+11;
}
if(c<1000)masked_blit(karakter,kata,26*15,17,re,0,16,25);





blit(kata,screen,0,0,70,130,300,40);
clear_to_color(kata,makecol(0,0,100));
if(key[67])break;



}
for(int f=0 ;f<30 ;f++)if(sr[f] != 0)sra[f]=sr[f]+96;
g=fopen("fafan.txt","w");//membuka file dan menulis
fprintf(g,"%s\n%d",sra,nilai*100);
fclose(g);
}














