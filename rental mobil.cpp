#include<iostream>
#include<cstring>
#include<string.h>
#include<conio.h>
#include<Windows.h>

using namespace std;
//-----------------------R E N T A L  M O B I L----------------------------
enum Status {DISEWA,TERSEDIA,BERTUGAS};
typedef char Jml;
typedef struct
{
	Jml NomorTNKB[15];
	Jml Merk[25];
	Jml Warna[10];
	int tahun;
	int Tarif;
	Status status;	
}mobil; 
#define M 3
typedef int Adress;
typedef struct 
{
	mobil Ma[M];
	Adress Headmob;
	Adress Tailmob;
}QueueMobil;

//-----------------------------------D A T A  D R I V E R-------------------------
#define D 3
typedef char id;
typedef struct
{
	id ktp_driver[20];
	id nama_driver[25];
	id alamat[25];
	int usia;
	Status status;

}Driver;
typedef struct
{
	Driver Da[D];
	Adress HeadDr;
	Adress TailDr;
}QueueDriver;
typedef char tanpa;
typedef struct
{
	tanpa t[25];
}tanp;
typedef struct
{
	tanp Ta[1];
	Adress Headta;
	Adress Tailta;
}Queuetanpa;
//------------------------------------D A T A  K O N S U M E N-----------------------------------------
#define K 3
typedef char kon;
typedef struct
{
	kon ktp_konsumen[20];
	kon nama_konsumen[25];
	kon alamat[25];
}Konsumen;
typedef struct
{
	Konsumen ka[K];
	Adress HeadKon;
	Adress TailKon;
}QueueKonsumen;
//-------------------------------K E L O L A-------------------------------------------
#define kel 3
typedef int date;
typedef struct
{
	date tanggal;
	date bulan;
	date tahun;
	date ktanggal;
	date kbulan;
	date ktahun;
}kelola;
typedef struct
{
	kelola lol[kel];
	Adress Headkel;
	Adress Tailkel;
}QueueKelola;
void gotoxy(int x,int y);
void CreateEmpty(QueueMobil *Q);
void CreateEmpty(QueueDriver *Q);
void CreateEmpty(QueueKonsumen *Q);
void CreateEmpty(QueueKelola *Q);
void CreateEmpty(Queuetanpa *Q);
int IsEmpty(QueueMobil Q);
int IsEmpty(QueueDriver Q);
int IsEmpty(QueueKonsumen Q);
int IsEmpty(QueueKelola Q);
int IsEmpty(Queuetanpa Q);
int IsOneElmt(QueueMobil Q);
int IsOneElmt(QueueDriver Q);
int IsOneElmt(QueueKonsumen Q);
int IsOneElmt(QueueKelola Q);
int IsOneElmt(Queuetanpa Q);
int IsFull(QueueDriver Q);
int IsFull(QueueMobil Q);
int IsFull(QueueKonsumen Q);
int IsFull(Queuetanpa Q);
void showQueueMobil(QueueMobil Q);
void showQueueDriver(QueueDriver Q);
void showQueueKonsumen(QueueKonsumen Q);
void showQueueTanpa(Queuetanpa Q);
void setMobil(Jml *NomorTNKB,Jml *Merk,Jml *Warna,int tahun,int Tarif,Status status,QueueMobil *Q);
void setDriver(id *ktp_driver,id *nama_driver,id *alamat,int usia,Status status,QueueDriver *Q);
void setKonsumen(kon *ktp_konsumen,kon *nama_konsumen,kon *alamat,QueueKonsumen *Q);
void settgl(date tanggal,date bulan,date tahun,date ktanggal,date kbulan,date ktahun,QueueKelola *Q);
void settanpadriver(tanpa *tanpa,Queuetanpa *Q);
//----------------------------------------D A T A  Y G  T A M P I L--------------------------------------------
void showQueueKon(QueueKonsumen Q);
void showQueueMob(QueueMobil Q);
void showQueueDriv(QueueDriver Q);
//=================================
void gotoxy(int x,int y){
	COORD coord;
	coord.X=x;
	coord.Y=y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}
void CreateEmpty(QueueMobil *Q){
	(*Q).Headmob = (*Q).Tailmob = -1;
}
void CreateEmpty(QueueDriver *Q){
	(*Q).HeadDr = (*Q).TailDr = -1;
}
void CreateEmpty(QueueKonsumen *Q){
	(*Q).HeadKon = (*Q).TailKon = -1;
}
void CreateEmpty(QueueKelola *Q){
	(*Q).Headkel = (*Q).Tailkel = -1;
}
void CreateEmpty(Queuetanpa *Q){
	(*Q).Headta = (*Q).Tailta = -1;
}
int IsEmpty(QueueMobil Q)
{
	return(Q.Headmob == -1 && Q.Tailmob == -1);
}
int IsEmpty(QueueDriver Q)
{
	return(Q.HeadDr == -1 && Q.TailDr == -1);
}
int IsEmpty(QueueKonsumen Q)
{
	return(Q.HeadKon == -1 && Q.TailKon == -1);
}
int IsEmpty(QueueKelola Q)
{
	return(Q.Headkel == -1 && Q.Tailkel == -1);
}
int IsEmpty(Queuetanpa Q)
{
	return(Q.Headta == -1 && Q.Tailta == -1);
}
int IsOneElmt(QueueMobil Q)
{
	return(Q.Headmob == Q.Tailmob && Q.Headmob != -1);
}
int IsOneElmt(QueueDriver Q)
{
	return(Q.HeadDr == Q.TailDr && Q.HeadDr != -1);
}
int IsOneElmt(QueueKonsumen Q)
{
	return(Q.HeadKon == Q.TailKon && Q.HeadKon != -1);
}
int IsOneElmt(QueueKelola Q)
{
	return(Q.Headkel == Q.Tailkel && Q.Headkel != -1);
}
int IsOneElmt(Queuetanpa Q)
{
	return(Q.Headta == Q.Tailta && Q.Headta != -1);
}
int IsFull(QueueMobil Q)
{
	return(Q.Headmob<Q.Tailmob && Q.Tailmob - Q.Headmob == M - 1 ||
		Q.Headmob>Q.Tailmob && Q.Headmob - Q.Tailmob == 1);
}
int IsFull(QueueDriver Q)
{
	return(Q.HeadDr<Q.TailDr && Q.TailDr - Q.HeadDr == D - 1 ||
		Q.HeadDr>Q.TailDr && Q.HeadDr - Q.TailDr == 1);
}
int IsFull(QueueKonsumen Q)
{
	return(Q.HeadKon<Q.TailKon && Q.TailKon - Q.HeadKon == D - 1 ||
		Q.HeadKon>Q.TailKon && Q.HeadKon - Q.TailKon == 1);
}
int IsFull(QueueKelola Q)
{
	return(Q.Headkel<Q.Tailkel && Q.Tailkel - Q.Headkel == D - 1 ||
		Q.Headkel>Q.Tailkel && Q.Headkel - Q.Tailkel == 1);
}
int IsFull(Queuetanpa Q)
{
	return(Q.Headta<Q.Tailta && Q.Tailta - Q.Headta == D - 1 ||
		Q.Headta>Q.Tailta && Q.Headta - Q.Tailta == 1);
}
void setMobil(Jml *NomorTNKB,Jml *Merk,Jml *Warna,int tahun,int Tarif,Status status,QueueMobil *Q)
	{
		if (IsEmpty(*Q)){
			if (IsOneElmt(*Q))
			{
				CreateEmpty(&(*Q));
			}
			(*Q).Headmob=(*Q).Tailmob=0;
			strcpy((*Q).Ma[0].NomorTNKB,NomorTNKB);
			strcpy((*Q).Ma[0].Merk,Merk);
			strcpy((*Q).Ma[0].Warna,Warna);
			((*Q).Ma[0].tahun=tahun);
			((*Q).Ma[0].Tarif=Tarif);
			((*Q).Ma[0].status=status);
		}else
		{
			if (IsFull(*Q)!=1)
			{
				(*Q).Tailmob=(*Q).Tailmob+1;
				strcpy((*Q).Ma[(*Q).Tailmob].NomorTNKB,NomorTNKB);
				strcpy((*Q).Ma[(*Q).Tailmob].Merk,Merk);
				strcpy((*Q).Ma[(*Q).Tailmob].Warna,Warna);
				((*Q).Ma[(*Q).Tailmob].tahun=tahun);
				((*Q).Ma[(*Q).Tailmob].Tarif=Tarif);
				((*Q).Ma[(*Q).Tailmob].status=status);
			}else
			{
				printf("Queue Penuh\n");
			}
		}
}
void setDriver(id *ktp_driver,id *nama_driver,id *alamat,int usia,Status status,QueueDriver *Q)
{
	if (IsEmpty(*Q)==1){
		if (IsOneElmt(*Q))
		{
			CreateEmpty(&(*Q));
		}
		(*Q).HeadDr=(*Q).TailDr=0;
		strcpy((*Q).Da[0].ktp_driver,ktp_driver);
		strcpy((*Q).Da[0].nama_driver,nama_driver);
		strcpy((*Q).Da[0].alamat,alamat);
		(*Q).Da[0].usia=usia;
		(*Q).Da[0].status=status;
		switch (status)
				{
				case TERSEDIA:
					cout<<"TERSEDIA"<<endl;
					break;
				case BERTUGAS:
					cout<<"BERTUGAS"<<endl;
					break;
				default:
					break;
				}
	}else
	{
		if (IsFull(*Q)!=1){
			(*Q).TailDr=(*Q).TailDr+1;
			strcpy((*Q).Da[(*Q).TailDr].ktp_driver,ktp_driver);
			strcpy((*Q).Da[(*Q).TailDr].nama_driver,nama_driver);
			strcpy((*Q).Da[(*Q).TailDr].alamat,alamat);
			(*Q).Da[(*Q).TailDr].usia=usia;
			(*Q).Da[(*Q).TailDr].status=status;
		}else
		{
			printf("Queue Penuh\n");
		}
	}
}
void setKonsumen(kon *ktp_konsumen,kon *nama_konsumen,kon *alamat,QueueKonsumen *Q){
	if (IsEmpty(*Q)==1){
		if (IsOneElmt(*Q))
		{
			CreateEmpty(&(*Q));
		}
		(*Q).HeadKon=(*Q).TailKon=0;
		strcpy((*Q).ka[0].ktp_konsumen,ktp_konsumen);
		strcpy((*Q).ka[0].nama_konsumen,nama_konsumen);
		strcpy((*Q).ka[0].alamat,alamat);
	}else
	{
		if (IsFull(*Q)!=1){
			(*Q).TailKon=(*Q).TailKon+1;
			strcpy((*Q).ka[(*Q).TailKon].ktp_konsumen,ktp_konsumen);
			strcpy((*Q).ka[(*Q).TailKon].nama_konsumen,nama_konsumen);
			strcpy((*Q).ka[(*Q).TailKon].alamat,alamat);
		}else
		{
			cout<<"Queue Penuh"<<endl;
		}
	}
}
void settgl(date tanggal,date bulan,date tahun,date ktanggal,date kbulan,date ktahun,QueueKelola *Q){
		{
		cout<<"\n";
		(*Q).lol[0].tanggal=tanggal;
		cout<<"Tanggal pinjam	:"<<tanggal;
		
		(*Q).lol[0].bulan=bulan;
		cout<<"\nbulan pinjam	:"<<bulan;
		
		(*Q).lol[0].tahun=tahun;
		cout<<"\ntahun pinjam	:"<<tahun;
		
		(*Q).lol[0].ktanggal=ktanggal;
		cout<<"\nTanggal kembali	:"<<ktanggal;
		
		(*Q).lol[0].kbulan=kbulan;
		cout<<"\nbulan kembali	:"<<kbulan;
		
		(*Q).lol[0].ktahun=ktahun;
		cout<<"\ntahun kembali	:"<<ktahun;
		}
}
void settanpadriver(tanpa *tanpa,Queuetanpa *Q){
	if (IsEmpty(*Q)==1){
		if (IsOneElmt(*Q))
		{
			CreateEmpty(&(*Q));
		}
		(*Q).Headta=(*Q).Tailta=0;
		strcpy((*Q).Ta[0].t,tanpa);
	}else
	{
		if (IsFull(*Q)!=1){
			(*Q).Tailta=(*Q).Tailta+1;
			strcpy((*Q).Ta[(*Q).Tailta].t,tanpa);
		}else
		{
			cout<<"Queue Penuh"<<endl;
		}
	}
}
void showQueueMobil(QueueMobil Q)
{
		if (Q.Headmob!=-1){
			printf("\nIsi Queue Mobil\n");
			int i;
			for(i=Q.Tailmob;i>=Q.Headmob;i--){
				cout<<"\n======================================\n";
				cout<<"Element ke	:"<<i<<endl;
				cout<<"Nomor TNKB	:"<<Q.Ma[i].NomorTNKB<<endl;
				cout<<"Merek Mobil	:"<<Q.Ma[i].Merk<<endl;
				cout<<"Warna Mobil	:"<<Q.Ma[i].Warna<<endl;
				cout<<"Tahun Buat	:"<<Q.Ma[i].tahun<<endl;
				cout<<"Tarif		:"<<Q.Ma[i].Tarif<<endl;
				cout<<"Status		:"<<Q.Ma[i].status<<endl;
				switch (Q.Ma[i].status)
			{
			case 0:
				cout<<"DISEWA"<<endl;
				break;
			case 1:
				cout<<"TERSEDIA"<<endl;
				break;
			default:
				break;
			}
			}
		}
}
void showQueueDriver(QueueDriver Q){
	if(Q.HeadDr!=-1){
		printf("\nIsi Queue Driver\n");
		for (int i = Q.TailDr; i >=Q.HeadDr; i--)
		{
			cout<<"\n======================================\n";
			cout<<"Element ke	:"<<i<<endl;
			cout<<"Nomor Ktp	:"<<Q.Da[i].ktp_driver<<endl;
			cout<<"Nama Driver	:"<<Q.Da[i].nama_driver<<endl;
			cout<<"Alamat Driver	:"<<Q.Da[i].alamat<<endl;
			cout<<"Usia Driver	:"<<Q.Da[i].usia<<endl;
			cout<<"Status		:"<<Q.Da[i].status<<endl;
			switch (Q.Da[i].status)
			{
			case 1:
				cout<<"TERSEDIA"<<endl;
				break;
			case 2:
				cout<<"BERTUGAS"<<endl;
				break;
			default:
				break;
			}
		}
	}
}
void showQueueKonsumen(QueueKonsumen Q){
	if (Q.HeadKon!=-1){
		printf("\nIsi Queue Konsumen\n");
		for (int i = Q.TailKon; i >= Q.HeadKon; i--)
		{
			cout<<"\n======================================\n";
			cout<<"Element ke	:"<<i<<endl;
			cout<<"Nomor Ktp	:"<<Q.ka[i].ktp_konsumen<<endl;
			cout<<"Nama Konsumen	:"<<Q.ka[i].nama_konsumen<<endl;
			cout<<"Alamat Konsumen	:"<<Q.ka[i].alamat<<endl;
		}
	}
}
void showQueueTanpa(Queuetanpa Q){
	if (Q.Headta!=-1){
		for (int i = Q.Tailta; i >= Q.Headta; i--)
		{
			cout<<"\n";
			cout<<Q.Ta[i].t<<endl;
			cout<<"\n======================================\n";
		}
	}
}
//DATA TAMPIL
void showQueueKon(QueueKonsumen Q){
	if (Q.HeadKon!=-1){
		for (int i = Q.TailKon; i >= Q.HeadKon; i--)
		{
			cout<<"\n======================================\n";
			cout<<"Nama Konsumen	:"<<Q.ka[i].nama_konsumen<<endl;
			cout<<"Alamat Konsumen	:"<<Q.ka[i].alamat<<endl;
		}
	}
}
void showQueueMob(QueueMobil Q)
{
		if (Q.Headmob!=-1){
			int i;
			for(i=Q.Tailmob;i>=Q.Headmob;i--){
				cout<<"Nomor TNKB	:"<<Q.Ma[i].NomorTNKB<<endl;
			}
		}
}
void showQueueDriv(QueueDriver Q){
	if(Q.HeadDr!=-1){
		for (int i = Q.TailDr; i >=Q.HeadDr; i--)
		{
			cout<<"Nama Driver	:"<<Q.Da[i].nama_driver<<endl;
			cout<<"\n======================================\n";
		}
	}
}
void main(){
	QueueMobil m;
	QueueDriver n;
	QueueKonsumen o;
	Queuetanpa z;
	QueueKelola k;
	int a;
	CreateEmpty(&o);
	CreateEmpty(&m);
	CreateEmpty(&n);
	CreateEmpty(&z);
	CreateEmpty(&k);
	do
	{
		system("cls");
		cout<<"\n\t\tWelcome to the Simply Rent a Car"<<endl;
		cout<<"\n1. memilih konsumen yang akan menyewa"<<endl;
		cout<<"2. Data yang di sewa"<<endl;
		cout<<"3. Output yg diminta"<<endl;
		cout<<"4. Pengembalian"<<endl;
		cout<<"5. Exit"<<endl;
		cout<<"Masukan Pilihan untuk =";cin>>a;
	switch (a)
	{
	case 1:
		cout<<"====Pilih Konsumen===="<<endl;
		{
		setKonsumen("5140411222","Pras","Pangkalanbun",&o);
		system("cls");
		setKonsumen("5140411333","Tyo","Yogyakarta",&o);
		system("cls");
		setKonsumen("5140411293","Eko","Trini",&o);
		system("cls");
		showQueueKonsumen(o);
			gotoxy(55,10);cout<<"1. kosumen 'Pras'"<<endl;
			gotoxy(55,11);cout<<"2. kosumen 'Tyo'"<<endl;
			gotoxy(55,12);cout<<"3. kosumen 'Eko'"<<endl;
			gotoxy(55,13);cout<<"MASUKAN PILIHAN	=";cin>>a;
			system("cls");
			switch (a)
			{
			case 1:
				cout<<"Konsumen yang diPilih"<<endl;
				CreateEmpty(&o);
				setKonsumen("5140411222","Pras","Pangkalanbun",&o);
				showQueueKonsumen(o);
				break;
			case 2:
				CreateEmpty(&o);
				cout<<"Konsumen yang diPilih"<<endl;
				setKonsumen("5140411333","Tyo","Yogyakarta",&o);
				showQueueKonsumen(o);
				break;
			case 3:
				CreateEmpty(&o);
				cout<<"Konsumen yang diPilih"<<endl;
				setKonsumen("5140411293","Eko","Trini",&o);
				showQueueKonsumen(o);
				break;
			default:
				cout<<"Pilihan tidak ada";
				CreateEmpty(&o);
				break;
			}
			gotoxy(55,13);cout<<"Tekan 1 untuk memilih Mobil	=";cin>>a;
			cout<<"====Pilih Mobil===="<<endl;
		{
			setMobil("514","Ford Focus RS","biru",2017,600.000,TERSEDIA,&m);
			system("cls");
			setMobil("515","Mitsubishi Triton 2016","merah",2016,600.000,TERSEDIA,&m);
			system("cls");
			setMobil("516","Mazda CX-3","Silver",2017,600.000,TERSEDIA,&m);
			system("cls");
			showQueueMobil(m);
			gotoxy(55,10);cout<<"1. untuk Menyewa Mazda CX-3"<<endl;
			gotoxy(55,11);cout<<"2. untuk Menyewa Mitsubishi Triton 2016"<<endl;
			gotoxy(55,12);cout<<"3. untuk Menyewa Ford Focus RS"<<endl;
			gotoxy(55,13);cout<<"MASUKAN PILIHAN	=";cin>>a;
			system("cls");
			switch (a)
			{
			case 1:
			CreateEmpty(&m);
			cout<<"\nMobil yang siap untuk di sewa"<<endl;
			setMobil("514","Ford Focus RS","biru",2017,600.000,TERSEDIA,&m);
			setMobil("515","Mitsubishi Triton 2016","merah",2016,600.000,TERSEDIA,&m);
			showQueueMobil(m);
			CreateEmpty(&m);
			setMobil("516","Mazda CX-3","Silver",2017,600.000,DISEWA,&m);
			showQueueMobil(m);
			break;
			case 2:
			CreateEmpty(&m);
			cout<<"\nMobil yang siap untuk di sewa"<<endl;
			setMobil("516","Mazda CX-3","Silver",2017,600.000,TERSEDIA,&m);
			setMobil("514","Ford Focus RS","biru",2017,600.000,TERSEDIA,&m);
			showQueueMobil(m);
			CreateEmpty(&m);
			setMobil("515","Mitsubishi Triton 2016","merah",2016,600.000,DISEWA,&m);
			showQueueMobil(m);
			break;
			case 3:
				CreateEmpty(&m);
				cout<<"\nMobil yang siap untuk di sewa"<<endl;
				setMobil("515","Mitsubishi Triton 2016","merah",2016,600.000,TERSEDIA,&m);
				setMobil("516","Mazda CX-3","Silver",2017,600.000,TERSEDIA,&m);
				showQueueMobil(m);
				CreateEmpty(&m);
				setMobil("514","Ford Focus RS","biru",2017,600.000,DISEWA,&m);
				showQueueMobil(m);
				break;
			default:
				cout<<"Pilihan tidak ada"<<endl;
				CreateEmpty(&m);

				break;
			}
		}
		}
		gotoxy(55,13);cout<<"Tekan 1 untuk memilih Driver	=";cin>>a;
		{
			setDriver("6201062603960001","Tarjo","Yogyakarta",35,TERSEDIA,&n);
			system("cls");
			setDriver("6201212603960001","Hasim","Pangkalanbun",33,TERSEDIA,&n);
			system("cls");
			setDriver("6201062603960001","priyo","Palangkaraya",30,TERSEDIA,&n);
			system("cls");
			showQueueDriver(n);
			gotoxy(55,10);cout<<"1. Driver 'Tarjo'"<<endl;
			gotoxy(55,11);cout<<"2. Driver 'Hasim'"<<endl;
			gotoxy(55,12);cout<<"3. Driver 'priyo'"<<endl;
			gotoxy(55,13);cout<<"4. Tanpa Drver"<<endl;
			gotoxy(55,14);cout<<"MASUKAN PILIHAN	=";cin>>a;
			system("cls");
			switch (a)
			{
			case 1:
				CreateEmpty(&n);
				cout<<"1. Driver 'Tarjo'"<<endl;
				setDriver("6201212603960001","Hasim","Pangkalanbun",33,TERSEDIA,&n);
				setDriver("6201062603960001","priyo","Palangkaraya",30,TERSEDIA,&n);
				showQueueDriver(n);
				CreateEmpty(&n);
				setDriver("6201062603960001","Tarjo","Yogyakarta",35,BERTUGAS,&n);
				showQueueDriver(n);
				break;
			case 2:
				CreateEmpty(&n);
				cout<<"1. Driver 'Hasim'"<<endl;
				setDriver("6201062603960001","Tarjo","Yogyakarta",35,TERSEDIA,&n);
				setDriver("6201062603960001","priyo","Palangkaraya",30,TERSEDIA,&n);
				showQueueDriver(n);
				CreateEmpty(&n);
				setDriver("6201212603960001","Hasim","Pangkalanbun",33,BERTUGAS,&n);
				showQueueDriver(n);
				break;
			case 3:
				CreateEmpty(&n);
				cout<<"3. Driver 'priyo'"<<endl;
				setDriver("6201062603960001","Tarjo","Yogyakarta",35,TERSEDIA,&n);
				setDriver("6201212603960001","Hasim","Pangkalanbun",33,TERSEDIA,&n);
				showQueueDriver(n);
				CreateEmpty(&n);
				setDriver("6201062603960001","priyo","Palangkaraya",30,BERTUGAS,&n);
				showQueueDriver(n);
				break;
			case 4:
				CreateEmpty(&n);
				CreateEmpty(&z);
				cout<<"Tanpa Driver"<<endl;
				settanpadriver("Anda memilih Tanpa Driver",&z);
				showQueueTanpa(z);
				break;
			default:
				cout<<"Pilihan tidak ada"<<endl; 
				CreateEmpty(&n);
				break;
			}
		}
		gotoxy(55,13);cout<<"Tekan 1 untuk atur tanggal sewa	=";cin>>a;
		CreateEmpty(&k);
		system("cls");
		cout<<"Atur Date Sewa"<<endl;
		date b,c,d,e,f,g;
		cout<<"Tanggal pinjam	:";cin>>b;
		cout<<"bulan pinjam	:";cin>>c;
		cout<<"tahun pinjam	:";cin>>d;
		cout<<"Harus kembali pada	:"<<endl;
		e=b+1;//otomatis menampilkan sehari setelahnya
		cout<<"Tanggal kembali	:"<<e<<endl;
		f=c;
		cout<<"bulan kembali	:"<<f<<endl;
		g=d;
		cout<<"tahun kembali	:"<<g<<endl;
		cout<<"JIKA TELAT AKAN ADA DENDA :)!!!"<<endl;
		cout<<"Tekan Enter untuk kembali ke menu utama :)"<<endl;
		getch();
		continue;
	case 2:
		cout<<"Data Transaksi Peminjaman"<<endl;
		showQueueMobil(m);
		showQueueKonsumen(o);
		showQueueDriver(n);
		showQueueTanpa(z);
		settgl(b,c,d,e,f,g,&k);
		break;
	case 3:
		cout<<"Output yang di inginkan Dosen"<<endl;
		showQueueKon(o);
		showQueueMob(m);
		showQueueDriv(n);
		showQueueTanpa(z);
		settgl(b,c,d,e,f,g,&k);
		break;
	case 4:
		cout<<"Pengembalian Mobil yang di sewa"<<endl;
		date q,r,s,t;
		showQueueKon(o);
		showQueueMob(m);
		showQueueDriv(n);
		showQueueTanpa(z);
		cout<<"Tanggal pinjam	:"<<b<<endl;
		cout<<"bulan pinjam	:"<<c<<endl;
		cout<<"tahun pinjam	:"<<d<<endl;
		cout<<"kembali pada	:"<<endl;
		cout<<"Tanggal kembali	:";cin>>q;
		cout<<"bulan kembali	:";cin>>r;
		cout<<"tahun kembali	:";cin>>s;
		if (q>e||f>r||g>s)
		{
			cout<<"Anda kena denda"<<endl;
			cout<<"1. untuk pake driver"<<endl;
			cout<<"2. untuk tidak pake driver"<<endl;
			cout<<"Masukan pilihan	:";cin>>a;
			switch (a)
			{
			case 1:
				cout<<"Pake Driver"<<endl;
				t=600.000*(q-b)+600.000+200.000;//denda 600ribu
				cout<<"Total Biaya	:"<<t<<endl;
				break;
			case 2:
				cout<<"Tanpa Driver"<<endl;
				t=600.000*(q-b)+600.000;
				cout<<"Total Biaya	:"<<t<<endl;
				break;
			default:
				cout<<"Pilihan tidak ada"<<endl;
				break;
			}
		}else
		{
			cout<<"Anda tidak kena denda"<<endl;
			cout<<"1. untuk pake driver"<<endl;
			cout<<"2. untuk tidak"<<endl;
			cout<<"Masukan pilihan	:";cin>>a;
			switch (a)
			{
			case 1:
				cout<<"Pake Driver"<<endl;
				t=600.000*(q-b)+200.000;
				cout<<"Total Biaya	:"<<t<<endl;
				break;
			case 2:
				cout<<"Tanpa Driver"<<endl;
				t=600.000*(q-b);
				cout<<"Total Biaya	:"<<t<<endl;
				break;
			default:
				cout<<"Pilihan tidak ada"<<endl;
				break;
			}
		}
		break;
	case 5:
		exit(0);
		break;
	default:
		cout<<"Pilihan tidak ada"<<endl;
		break;
	}
	getch();
	} while (true);
}