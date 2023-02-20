#include "knight.h"

void display(int HP, int level, int remedy, int maidenkiss, int phoenixdown, int rescue) {
    cout << "HP=" << HP
        << ", level=" << level
        << ", remedy=" << remedy
        << ", maidenkiss=" << maidenkiss
        << ", phoenixdown=" << phoenixdown
        << ", rescue=" << rescue << endl;
}

void adventureToKoopa(string file_input, int & HP, int & level, int & remedy, int & maidenkiss, int & phoenixdown, int & rescue) {
    fstream f;
    char hang1[15];
    f.open(file_input);
    f.getline(hang1, 15);
    int a = 0;

    //input hang1 (kieu so)
    //gan chi so HP
        while(hang1[a] != ' ')
    {
        if(a == 0)
        HP = hang1[a] - '0';
        else 
        HP = HP*10 + (hang1[a] - '0'); 
        a++;
    }
    int MaxHP = HP;//gan HP input la chi so HP cao nhat
    a++;
    int a1 = 0; //tao bien de chuyen char thanh int
    //gan chi so level
    while(hang1[a] != ' ')
    {
        if(a1 == 0)
        {
        level = hang1[a] - '0';
        a1++;
        }
        else
        level = level*10 + (hang1[a] - '0'); 
        a++;
    }
    a++;
    //gan chi so remedy
     while(hang1[a] != ' ')
    {
        if(a1 == 1)
        {
        remedy = hang1[a] - '0';
        a1++;
        }
        else
        remedy = remedy*10 + (hang1[a] - '0'); 
        a++;
    }
    a++;
    //gan chi so maidenkiss
     while(hang1[a] != ' ')
    {
        if(a1 == 2)
        {
        maidenkiss = hang1[a] - '0';
        a1++;
        }
        else
        maidenkiss = maidenkiss*10 + (hang1[a] - '0'); 
        a++;
    }
    a++;
    // gan chi so phoenixdown
     while((hang1[a] != '\n') && (hang1[a] != '\0'))
    {
         if(a1 == 3)
        {
        phoenixdown = hang1[a] - '0';
        a1++;
        }
        else
        phoenixdown = phoenixdown*10 + (hang1[a] - '0'); 
        a++;
    }
    rescue = -1; //hanh trinh chua ket thuc rescue = -1

//input hang2 (kieu ki tu)
char hang2[100];
f.getline(hang2, 100);//chuoi su kien o dang ki tu
int j = 0;
int k = 0; //ket thuc su kien chua?

int sk = 1; //(bien su kien)
int sukien[100];

//bien chuoi su kien thanh kieu int
while(hang2[j] != '\0')
{
if((hang2[j] != ' ') && (k == 0))
{
    sukien[sk] = hang2[j] - '0';
    k++;
}  
else if((hang2[j] != ' ') && (k != 0)) 
{
    sukien[sk] = sukien[sk]*10 + (hang2[j] - '0');
}  
else if(hang2[j] == ' ')
{
sk++;
k--;
}
j++;
}

int damage;
float baseDamage;
int i = 1;
int tihon = 0;
bool is_tihon = false;
int ech = 0;
bool is_ech = false;
int insLevel;
for(i; i <= sk; i++){
    int b = i%10;
    int levelO = i > 6?(b > 5?b : 5) : b;
    if(sukien[i] == 0){
        rescue = 1;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        cout << "Victory!";
        return;
    }
    if(level > levelO){ //qua ai va tang 1 level
        if((sukien[i] == 6) || (sukien[i] == 7)){
        level = level + 2;    
        }
        if(level >= 10) // max level la 10
        level = 10;
        else
        level++;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    else if(level == levelO){ //qua ai va ko tang level
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    else if(level < levelO){ //chien dau voi ke dich
        if(sukien[i] == 1){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            baseDamage = 1; //MadBear
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 2){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            baseDamage = 1.5; //Bandit
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 3){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            baseDamage = 4.5; //LordLupin
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 4){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            baseDamage = 7.5; //Elf
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 5){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            baseDamage = 9.5; //Troll
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 6){//phu thuy Shaman
            if((ech == 1)||(tihon == 1)){
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                continue;
            }
            else if(remedy >= 1)
            {
                HP /= 5;
                HP *= 5;
                remedy--;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
            else{
                if(HP <= 5)
                    HP = 1;
                else 
                    HP /= 5;
                tihon =  3;
                is_tihon = true;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
        }
        else if(sukien[i] == 7){//Siren Vajsh
            if((ech == 1)||(tihon == 1)){
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                continue;
            }
            else if(maidenkiss >= 1)
            {
                maidenkiss--;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
            else{
                insLevel = level;
                level = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
        }
        else if(sukien[i] == 11){//nam tang luc MushMario
            int n1 = ((level + phoenixdown)%5 + 1) * 3 ;
            int s1 = 99; // tong
            int s0; // bien
            int s = 0;
            for(s; s<n1; s++){ // vidu n = 2 thi s1 = 99 + 97
                if(s == 1){
                    s0 = s1; //  bien = 99
                }
                else{
                    s0 = s0 -2; // bien -2
                    s1 = s1 + s0; // tong = tongcu + bien moi
                }
            }
            HP = HP + (s1%100);
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 12){//nam Fibonacci MushFibo 
            int fibot = 0; //so trc = 0
            int fibos;
            int fibott;
            while(1) // tao day si Fibonacci vo tan co dk de break
            {
                if(fibot == 0) // tong dau tien
                {
                    fibot = 1; 
                    fibos = 2;
                }
                else{ // bat dau tu tong thu 2
                    fibott = fibot; // dat so trc cu vao bien nho
                    fibot = fibos; // trc moi = sau cu
                    fibos = fibos + fibott; // moi sau = moi cu + trc cu
                }
                if(HP == 1){
                    display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                    break;
                }
                else if(HP < fibos){
                    HP = fibot;
                    display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                break;
                }
            }
        }
        else if(sukien[i] > 130){//nam ma MushGhost  //se la 13***
        int dayGhost = 0;
        int n = 2;
        int mu;
        for(n; dayGhost >= 0; n++){ //de lay so sau 13
            mu = pow(10,n);
            dayGhost = sukien[i] - mu*13; //neu am thoat vong lap
        }
        n = n - 2; //giam so mu xuong 2 chu so do nhan 13(da co 10^1)
        mu = pow(10,n);
        dayGhost = sukien[i] - mu*13; //se ra day so sau 13
        }
    }
    if (HP <= 0){
        if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
            HP = MaxHP;
            phoenixdown--;
            tihon = 0;
            continue;
        }
        else{
            rescue = 0;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            cout << "Dead!";
            return;
        }
    }
    if((tihon == 0)&&(is_tihon == true))
    {
        HP = HP*5;
        is_tihon == false;
    }
}
rescue = 1;
display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
cout << "Victory!";
}