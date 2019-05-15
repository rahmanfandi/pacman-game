
#define i  (p.v/25)             //**kumpulan fungsi agar hantu bergerak mengejar.
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


//musuh
struct{
int h;
int v;
int hdp,tem;
int dirv,dirh;
int r;
int cabang;
}M[5];

//pacman
struct{
int h;
int v;
int hdp,tem;
int dirv,dirh;
//int cabang;
}p;

int penjaga_jalur_musuh(int mus){
if (pet[mvd][mt] !=1 && pet[mvd][mt] !=3)M[mus].dirv=0;
if (pet[mvu][mt] !=1 && pet[mvu][mt] !=3)M[mus].dirv=0;
if (pet[mi][mhd] !=1 && pet[mi][mhd] !=3)M[mus].dirh=0;
if (pet[mi][mhu] !=1 && pet[mi][mhu] !=3)M[mus].dirh=0;
}

int hitung_percabangan(int mus){
M[mus].cabang = 0;
if (pet[mi][mt+1] ==1 )M[mus].cabang++;
if (pet[mi][mt-1] ==1 )M[mus].cabang++;
if (pet[mi-1][mt] ==1 )M[mus].cabang++;
if (pet[mi+1][mt] ==1 )M[mus].cabang++;

if(M[mus].h == (mt*25) +12 && M[mus].cabang > 2){M[mus].dirh=0;M[mus].dirv=0;}
if(M[mus].v == (mi*25) +12 && M[mus].cabang > 2){M[mus].dirv=0;M[mus].dirh=0;}
}

int simpan_arah_terakir(int mus){
if ( M[mus].dirv !=0 || M[mus].dirh !=0)
M[mus].tem = M[mus].hdp;
if (M[mus].cabang == 1)M[mus].tem=0;
}

int random_arah(int mus){
if ( M[mus].dirv==0 && M[mus].dirh==0)
M[mus].r = (rand()%4)+1; 
} 

int pengatur_arah(int mus){
if(M[mus].tem != 2 && M[mus].r == 1 && pet[mi][mt-1] != 2 )
{M[mus].hdp=1;M[mus].dirh=1;M[mus].dirv=0;}
if(M[mus].tem != 1 && M[mus].r == 2 && pet[mi][mt+1] != 2 )
{M[mus].hdp=2;M[mus].dirh=2;M[mus].dirv=0;}
if(M[mus].tem != 4 && M[mus].r == 3 && pet[mi-1][mt] != 2 )
{M[mus].hdp=3;M[mus].dirv=1;M[mus].dirh=0;}
if(M[mus].tem != 3 && M[mus].r == 4 && pet[mi+1][mt] != 2 )
{M[mus].hdp=4;M[mus].dirv=2;M[mus].dirh=0;}    
}



int kejar(int mus){
if ( M[mus].dirv==0 && M[mus].dirh==0){

     if (M[mus].tem != 4 && pet[mi-1][mt] != 2 && i < mi )M[mus].r=3;
else if (M[mus].tem != 3 && pet[mi+1][mt] != 2 && i > mi )M[mus].r=4;
else if (M[mus].tem != 2 && pet[mi][mt-1] != 2 && t < mt )M[mus].r=1;
else if (M[mus].tem != 1 && pet[mi][mt+1] != 2 && t > mt )M[mus].r=2;
else random_arah(mus);
}    
    
}


int kejar_alternatif(){
for(int mus = 1;mus<5;mus++){
if(M[mus].h < 0    )M[mus].h=499;                                                        
if(M[mus].h > 500  )M[mus].h=1; 
penjaga_jalur_musuh(mus);
hitung_percabangan(mus);    
simpan_arah_terakir(mus);
kejar(mus);
pengatur_arah(mus);
}

}

