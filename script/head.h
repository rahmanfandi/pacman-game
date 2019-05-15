

BITMAP *kuning[5];
BITMAP *kuningh;

//BITMAP *kuningl;

BITMAP *hantuh;
BITMAP *hantu[5];

void mumet()
{
kuning[1] = load_bitmap("pic/kuningl.bmp", NULL);
kuning[2] = load_bitmap("pic/kuningr.bmp", NULL);
kuning[3] = load_bitmap("pic/kuningu.bmp", NULL);
kuning[4] = load_bitmap("pic/kuningd.bmp", NULL);
kuningh = create_bitmap(40,40);       

hantuh  = load_bitmap("pic/mus.bmp",NULL);
hantu[1] = create_bitmap(40,40); 
hantu[2] = create_bitmap(40,40); 
hantu[3] = create_bitmap(40,40); 
hantu[4] = create_bitmap(40,40); 
clear_to_color(hantu[1],makecol(255,0,255));
clear_to_color(hantu[2],makecol(255,0,255));
clear_to_color(hantu[3],makecol(255,0,255));
clear_to_color(hantu[4],makecol(255,0,255));

}    

void gico(int b,int hdp)
{

//
if(b <= 10)         {blit(kuning[hdp],kuningh,0,0,0,0,41,41);}
if(b > 10 && b<=20) {blit(kuning[hdp],kuningh,40,0,0,0,41,41);}
if(b > 20 && b<=30) {blit(kuning[hdp],kuningh,80,0,0,0,41,41);}
if(b > 30 && b<=40) {blit(kuning[hdp],kuningh,120,0,0,0,41,41);}            
if(b > 40 && b<=50) {blit(kuning[hdp],kuningh,160,0,0,0,41,41);}

if(b > 50 && b<=60) {blit(kuning[hdp],kuningh,120,0,0,0,41,41);}             
if(b > 60 && b<= 70){blit(kuning[hdp],kuningh,80,0,0,0,41,41);}          
if(b > 70 && b<= 80){blit(kuning[hdp],kuningh,40,0,0,0,41,41);}
if(b > 80)          {blit(kuning[hdp],kuningh,0,0,0,0,41,41);}

}


void musuh1(int hb,int hdp,int musu) 
{int mus;
mus = musu -1;
if (hb <= 40 && hdp == 1){blit(hantuh,hantu[musu],0+(mus*80),3,2,3,40,40);} 
if (hb > 40 && hdp == 1){blit(hantuh,hantu[musu],41+(mus*80),3,2,3,40,40);}     

if (hb <= 40 && hdp == 2){blit(hantuh,hantu[musu],0+(mus*80),40,2,3,40,40);} 
if (hb > 40 && hdp == 2){blit(hantuh,hantu[musu],41+(mus*80),40,2,3,40,40);}     

if (hb <= 40 && hdp == 3){blit(hantuh,hantu[musu],0+(mus*80),80,2,3,40,40);} 
if (hb > 40 && hdp == 3){blit(hantuh,hantu[musu],41+(mus*80),80,2,3,40,40);}     

if (hb <= 40 && hdp == 4){blit(hantuh,hantu[musu],0+(mus*80),120,2,3,40,40);} 
if (hb > 40 && hdp == 4){blit(hantuh,hantu[musu],41+(mus*80),120,2,3,40,40);}     


}

