
 #include <intro.h>

  TERSANGKA                                             //KELAS F
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
XX  OLEH:                                                       XX
XX   fengky_arga_pratama (910680060);   disain_grafis           XX
XX   frengky             (910680080);   disain_permainan        XX
XX   fandisya_rahman     (910683043);   disain_pemrograman      XX
XX   failla_fuadi        (910680042);   disain_AI               XX
XX   ahaddin_gani        (910680003);   disain_soundtrack       XX    
XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX
}

                                                                                                                                                                
   volatile long speed_counter = 0;                                               
   void increment_speed_counter()                                                 
   {speed_counter++; }                                                            
   END_OF_FUNCTION(increment_speed_counter);                                      
                                                                                                                                                                  
void game();    

int main(int argc, char *argv[])
   {                                                                            

  	allegro_init();                                                              
  	install_keyboard();                                                          
  	install_mouse();
    install_timer();                                                             
  	LOCK_VARIABLE(speed_counter);                                                
  	LOCK_FUNCTION(increment_speed_counter);                                      
           
  	set_color_depth(32);                                                         
  	set_gfx_mode(GFX_AUTODETECT, 500,550,0,0);                                   
    install_sound(DIGI_AUTODETECT, MIDI_AUTODETECT, NULL);
    set_volume(255,255);
                                                                                                                                                               
    settulisan();
    set_map();
    mulai_game:                                                                                 
    buffer = create_bitmap(500,550);                                              
    cout<<"tugas proyek pemrograman lanjut kelas F";                               
    load_suara();                                                                        
    
    
    huruf();
    masuk();                                                                                                                                                                
    masuk2();
    menu();                                      
    destroy_bitmap(buffer);   
    bersihkanMemory();
    
    return 0;                                         
   }                                                                              
   END_OF_MAIN();                                                                  
  	                                      
                                                                                                                                                                

void game()
{
 BITMAP *mlebu=load_bitmap("pic/wait.bmp",NULL);
 SAMPLE *intromusik = load_sample("son/intro.wav");
 pesanfull=load_bitmap("pic/pesan.bmp",NULL);
 SAMPLE *makan = load_sample("son/pacdot0.wav");
 SAMPLE *siren = load_sample("son/siren0.wav");
 dead = load_sample("son/dead.wav");
 blit(mlebu,screen,0,0,0,0,500,500);
 install_int_ex(increment_speed_counter, BPS_TO_TIMER(120));            
 rest(2000);
 play_sample(intromusik, 255, 0, 1000, 0);
 srand(time(NULL));	                                                         
 mumet();                                                                      
 peta();     
    
    
 int wait = 0;
 int b;                                                                       
 int hb;                                                                      
 int nilai=0;                                                                 
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
 M[mus].hdp=3;}                                                          
 nyawa = 3;                                                                    

 int ks;



 while(!key[KEY_ESC])                                                          
 { 

   if(wait == 0){mulaii();wait=1;speed_counter=0;}
                                                                             
   if (isipeta[i][t] == 1){isipeta[i][t]=0;nilai++;play_sample(makan, 255, 0, 1000, 0);}        
   if (nilai >= skor_menang-1){end();break;}//kondisi jika menang 1 level                                                  
   cout<<nilai<<" : "<<skor_menang<<endl;             
   
   //supaya tidak menembus tembok                                                                               
   if (pet[vd][t] !=1 )p.dirv=0;   //bawah                                               
   if (pet[vu][t] !=1 )p.dirv=0;   //atas                                               
   if (pet[i][hd] !=1 )p.dirh=0;   //kanan                                               
   if (pet[i][hu] !=1 )p.dirh=0;   //kiri                                               
   
   //jalan pintas
   if(p.h < 0    )p.h=499;                                                       
   if(p.h > 500  )p.h=1;                                                                             
   
   //tombol---------                                                                               
   if(key[KEY_LEFT] && pet[i][t-1] == 1 ){p.hdp=1;p.dirh=1;p.dirv=0;}//kiri            
   if(key[KEY_RIGHT]&& pet[i][t+1] == 1 ){p.hdp=2;p.dirh=2;p.dirv=0;}//kanan            
   if(key[KEY_UP]   && pet[i-1][t] == 1 ){p.hdp=3;p.dirv=1;p.dirh=0;}//atas            
   if(key[KEY_DOWN] && pet[i+1][t] == 1 ){p.hdp=4;p.dirv=2;p.dirh=0;}//bawah            
                 
                                                                                  
   while(speed_counter > 0)
   {                                                                                                                                                              

    speed_counter --;                                                      
    if(b > 90)b=0;hb+=5;                                                                         
    if(hb > 80)hb=0;                                                              
    kejar_alternatif();//<--fungsi musuh berjalan     
                                                                                                                                                                 
    ///gerak berjalan pacman-------------------------                                                             
    gico(b,p.hdp);//<--fungsi gerakan mulut pacman                                                           
    switch(p.dirh){                                                                           
                   case 1:p.h-=1;b+=4;break;//naik                                                    
                   case 2:p.h+=1;b+=4;break;//turun
                  }                                                                            
    switch(p.dirv){ 
                    case 1:p.v-=1;b+=4;break;//kiri                                                    
                    case 2:p.v+=1;b+=4;break;//kanan
                  }                                                   
                                                                                                                                                                    
    //gerak berjalan musuh----------------------------                                                                                                                                                                                                                                 
    for(int mus = 1;mus<5;mus++)
            {                                                  
             musuh1(hb,M[mus].hdp,mus);//<--                                                     
             switch(M[mus].dirh)                                                            
             {                                                                              
              case 1:M[mus].h-=1;break;                                                      
              case 2:M[mus].h+=1;break;                                                      
             }                                                                              
                                                                                  
             switch(M[mus].dirv)                                                            
             {                                                                              
              case 1:M[mus].v-=1;break;                                                      
              case 2:M[mus].v+=1;break;
             }                                                                              
            }                                                                              
    //----------------------------------------

//**perintah menggambar objek**********************************************                                                                      
    circlefill(maze,t*25+12,i*25+12,2,makecol(0,0,0));                            
    draw_sprite(buffer,maze,0,0);                                                  
    blit(pesanfull,buffer,0,88,340,508,45+(nyawa*29),50);
    blit(pesanfull,buffer,0,49,30,520,55,20);
    angka(nilai*10,buffer,95,520);
    draw_sprite(buffer,kuningh,p.h-20,p.v-20);                                                                                          
    for(int mus = 1;mus<5;mus++)
    {
     draw_sprite(buffer,hantu[mus],M[mus].h-20,M[mus].v-20);                                 
     if (mi ==i && mt == t){
                           mati();
                           speed_counter=0;
                          }
    }
    
    if(nyawa<1)break;                                    
    blit(buffer, screen, 0,0,0,0,500,550);                                                          
//***********************************************************************

    if(key[KEY_ENTER]){wait=0;rest(200);}
    clear_bitmap(buffer);
   }//<---------------------------batas while timer                                                                
   if(nyawa<1)break;   
 }//<-----------------------------bater while utama                       
}//<------------------------------batas fungsi game
                                                                                                                                                                



/*
kurang
.suara<selesai
.teks [integer]<selesai
      [string]<<sparo
.load/save skor dan nama
.tembok peta jelek
.gmbar pac
.pacman miring
.screen menang<selesai
.peta editor
*/
