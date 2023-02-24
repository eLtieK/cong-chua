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
    f.open(file_input, ios::in);
    string hang1;
    getline(f, hang1);
    stringstream hhang1(hang1);
    hhang1 >> HP >> level >> remedy >> maidenkiss >> phoenixdown;
    int MaxHP = HP;
    rescue = -1; //hanh trinh chua ket thuc rescue = -1

    string hang2;
    getline(f, hang2);

    string file_mush_ghost;
    getline(f, file_mush_ghost, ',');

    string file_asclepius_pack;
    getline(f, file_asclepius_pack, ',');

    string file_merlin_pack;
    getline(f, file_merlin_pack);
    
    int kk = 0;
    int khoangtrang; 
    int sk = 0;
    while(1)
    {
        khoangtrang = hang2.find(" ", kk);
        if (khoangtrang == -1)
        break;
        sk ++;
        kk = khoangtrang + 2;
    }
    sk++;
    int sukien[sk+1];
    int j = 1;
    stringstream hhang2(hang2);
    for(j; j <= sk; j++)
    {
        hhang2 >> sukien[j];
    }

int damage;
float baseDamage;
int i = 1;
int tihon = 0;
bool is_tihon = false;
int ech = 0;
bool is_ech = false;
int insLevel;
bool is_thuoc = false;
bool is_Arthur = false;
bool is_Lancelot = false;
if(MaxHP == 999)
is_Arthur = true;
int uoc = 2;
for(uoc; uoc < MaxHP; uoc++)
{
    if(MaxHP == uoc)
    is_Lancelot = true;
    if(MaxHP % uoc == 0)
    break;
}
for(i; i <= sk; i++){
    int b = i%10;
    int levelO = i > 6?(b > 5?b : 5) : b;
    if(sukien[i] == 0){
        rescue = 1;
        if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
        if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
        if((tihon == 0)&&(is_tihon == true))
        {
            HP = HP*5;
            is_tihon = false;
        }
        if((ech == 0)&&(is_ech == true))
        {
            level = insLevel;
            is_ech = false;
        }
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        return;
    }
    if(sukien[i] == 99){
        if(is_Arthur == true)
        {
            level = 10;
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            continue;
        }
        else if((is_Lancelot == true) && (level >= 8)){
            level = 10;
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            continue;
        }
        else if(level == 10){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            continue;
        }
        else
        {
        rescue = 0;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        return;
        }
    }
    if(sukien[i] == 15){// ++remedy
        remedy++;
        if(remedy > 99)
        remedy = 99;
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
        if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
        if((tihon == 0)&&(is_tihon == true))
        {
            HP = HP*5;
            is_tihon = false;
        }
        if((ech == 0)&&(is_ech == true))
        {
            level = insLevel;
            is_ech = false;
        }
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    if(sukien[i] == 16){// ++maidenkiss
        maidenkiss++;
        if(maidenkiss > 99)
        maidenkiss = 99;
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
        if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
        if((tihon == 0)&&(is_tihon == true))
        {
            HP = HP*5;
            is_tihon = false;
        }
        if((ech == 0)&&(is_ech == true))
        {
            level = insLevel;
            is_ech = false;
        }
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    if(sukien[i] == 17){// ++phoneixdown
        phoenixdown++;
        if(phoenixdown > 99)
        phoenixdown= 99;
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
        if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
        if((tihon == 0)&&(is_tihon == true))
        {
            HP = HP*5;
            is_tihon = false;
        }
        if((ech == 0)&&(is_ech == true))
        {
            level = insLevel;
            is_ech = false;
        }
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    if(sukien[i] == 11){//nam tang luc MushMario
        int n1 = ((level + phoenixdown)%5 + 1) * 3 ;
        int s1 = 99; // tong
        int s0; // bien
        int s = 0;
        if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
        if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
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
        if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
        if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
        if((i == sk) && (HP > 0))
            rescue = 1;
        if(HP > MaxHP)
        HP = MaxHP;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    if(sukien[i] == 12){//nam Fibonacci MushFibo 
        int fibot = 0; //so trc = 0
        int fibos;
        int fibott;
        if((tihon == 0)&&(is_tihon == true))
        {
            HP = HP*5;
            is_tihon = false;
        }
        if((ech == 0)&&(is_ech == true))
        {
            level = insLevel;
            is_ech = false;
        }
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
                if((i == sk) && (HP > 0))
                    rescue = 1;
                if((tihon == 0)&&(is_tihon == true))
                {
                    HP = HP*5;
                    is_tihon = false;
                }
                if((ech == 0)&&(is_ech == true))
                {
                    level = insLevel;
                    is_ech = false;
                }   
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                break;
                }
                else if(HP < fibos){
                    HP = fibot;
                    if((i == sk) && (HP > 0))
                        rescue = 1;
                    if((tihon == 0)&&(is_tihon == true))
                    {
                        HP = HP*5;
                        is_tihon = false;
                    }
                    if((ech == 0)&&(is_ech == true))
                    {
                        level = insLevel;
                        is_ech = false;
                    }  
                    display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                break;
                }
            }
        }
    if(sukien[i] > 130){//nam ma MushGhost  //se la 13***
            int dayGhost = 0;
            int n = 2;
            int mu;
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            for(n; dayGhost >= 0; n++){ //de lay so sau 13
                mu = pow(10,n);
                dayGhost = sukien[i] - mu*13; //neu am thoat vong lap
            }
            n = n - 2; //giam so mu xuong 2 chu so do nhan 13(da co 10^1)
            mu = pow(10,n);
            dayGhost = sukien[i] - mu*13; //se ra day so sau 13
            //tao dayGhost nghich dao
            int phandu;
            int ivDayGhost = 0;
            while (dayGhost != 0)
            {
                phandu = dayGhost % 10;              
                dayGhost = dayGhost / 10;            
                ivDayGhost = ivDayGhost*10 + phandu ;  
            }

            // mo  file mush_ghost
            fstream mg;
            mg.open(file_mush_ghost, ios::in);
            string dong1_mush_ghost;
            string dong2_mush_ghost;
            getline(mg, dong1_mush_ghost);
            getline(mg, dong2_mush_ghost);
            stringstream dong1(dong1_mush_ghost);
            int soAn;
            dong1 >> soAn; //gan va doi sang kieu int
            int ss = 0;
            int dauphay;
            while(1){
            dauphay = dong2_mush_ghost.find(',',ss);
            if(dauphay == -1)
            break;
            dong2_mush_ghost.replace(dauphay,1," ");
            ss = dauphay + 1;
            }
            int an[soAn];
            ss = 0; //vi tri
            stringstream dong2(dong2_mush_ghost);
            for(ss; ss < soAn; ss++)
            {
                dong2 >> an[ss];
            }
            
            //phan loai MushGhost
            int loaiNam;
            while(ivDayGhost != 0)
            {
                loaiNam = ivDayGhost % 10;
                ivDayGhost = ivDayGhost / 10;
                if(loaiNam == 1)
                {
                    int k1 = 0;
                    int max; //gtri max
                    int min; //gtri min
                    int maxi = 0;//vitri max
                    int mini = 0;//vitri min
                    for(k1; k1 < soAn; k1++){   
                        if(k1 == 0)
                        {   
                            max = an[k1];
                            min = an[k1];
                            continue;
                        }
                        if(an[k1] >= max )
                        {
                            max = an[k1];
                            maxi = k1;
                        }
                        if(an[k1] <= min )
                        {
                            min = an[k1];
                            mini = k1;
                        }
                    }
                    HP = HP - (maxi + mini);
                    if(HP > MaxHP)
                        HP = MaxHP;
                    if (HP <= 0){
                        if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                            HP = MaxHP;
                            phoenixdown--;
                            tihon = 0;
                        }
                        else{
                            rescue = 0;
                            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                            return;
                        }
                    }
                }
            
                else if(loaiNam == 2)
                {
                    int k2 = 0;
                    bool is_tang = false;
                    bool is_giam = false;
                    int maxx = 0; //ktra tang ngat
                    int minx = 0; //ktra giam ngat
                    int mtx = -2; //gtri dinh nui
                    int mti = -3; //vi tri dinh nui
                    for(k2; k2 < soAn; k2++)
                    {
                        if(k2 == 0)
                        continue;
                        if( (k2 == 1) && ( an[k2] > an[k2-1]))
                        {
                            is_tang = true;
                            maxx = an[k2];
                            continue;
                        }
                        if(is_tang == true)
                        {
                            if( an[k2] > maxx)
                            {
                                maxx = an[k2];
                                continue;
                            }
                            else
                            {
                                is_tang = false;
                                break;
                            }
                        }
                        if( (k2 == 1) && ( an[k2] < an[k2-1]))
                        {
                            is_giam = true;
                            minx = an[k2];
                            continue;
                        }
                        if(is_giam == true)
                        {
                            if( an[k2] < minx)
                            {
                                minx = an[k2];
                                continue;
                            }
                            else
                            {
                                is_giam = false;
                                break;
                            }
                        }
                    }
                    if (k2 == soAn)
                    {
                        if (is_tang == true)
                        {
                            mtx = an[k2-1];
                            mti = k2 - 1;
                        }
                        else if(is_giam == true)
                        {
                            mtx = an[0];
                            mti = 0;
                        }
                    }
                    HP = HP - (mtx + mti);
                    if(HP > MaxHP)
                        HP = MaxHP;
                    if (HP <= 0){
                        if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                            HP = MaxHP;
                            phoenixdown--;
                            tihon = 0;
                        }
                        else{
                            rescue = 0;
                            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                            return;
                        }
                    }

                }
                else if(loaiNam == 3)
                {
                    int anMoi[soAn];
                    int maxi2 = 0;
                    int mini2 = 0;
                    int maxxx = 0;
                    int minxx = 0;
                    int k3 = 0;
                    for(k3; k3 < soAn;k3++)
                    {
                        if (an[k3] < 0)
                        anMoi[k3] = -an[k3];
                        else 
                        anMoi[k3] = (17*an[k3]+9) % 257;
                    }
                    k3 = 0;
                    for(k3; k3 < soAn; k3++){   
                        if(k3 == 0)
                        {   
                            maxxx = anMoi[k3];
                            minxx = anMoi[k3];
                            continue;
                        }
                        if(anMoi[k3] > maxxx )
                        {
                            maxxx = anMoi[k3];
                            maxi2 = k3;
                        }
                        if(anMoi[k3] < minxx )
                        {
                            minxx = anMoi[k3];
                            mini2 = k3;
                        }
                    }
                    HP = HP - (maxi2 + mini2);
                    if(HP > MaxHP)
                        HP = MaxHP;
                    if (HP <= 0){
                        if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                            HP = MaxHP;
                            phoenixdown--;
                            tihon = 0;
                        }
                        else{
                            rescue = 0;
                            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                            return;
                        }
                    }
                }
                else if(loaiNam == 4)
                {
                    int anMoi2[soAn];
                    int k4 = 0;
                    for(k4 ; k4 < soAn;k4++)
                    {
                        if (an[k4] < 0)
                        anMoi2[k4] = -an[k4];
                        else 
                        anMoi2[k4] = (17*an[k4]+9) % 257;
                    }
                    int max2_3x = -5; //gia tri lon nhat thu 2
                    int max2_3i = -7; // vi tri lon nhat thu 2
                    int maxthu2;
                    int maxlon;
                    int solonthu2 = 0;
                    int solon = 0;
                    if((anMoi2[0] == anMoi2[1]) && (anMoi2[1] == anMoi2[2]))
                    ;
                    else if((anMoi2[0] >= anMoi2[1]) && (anMoi2[1] >= anMoi2[2]))
                    {
                    max2_3x = anMoi2[1];
                    max2_3i = 1;
                    }
                    else if((anMoi2[0] <= anMoi2[1]) && (anMoi2[1] <= anMoi2[2]))
                    {
                    max2_3x = anMoi2[1];
                    max2_3i = 1;
                    }
                    else if((anMoi2[0] <= anMoi2[1]) && (anMoi2[1] >= anMoi2[2]))
                    {
                        if(anMoi2[0] >= anMoi2[2])
                        {
                        max2_3x = anMoi2[2];
                        max2_3i = 2;
                        }
                        else if(anMoi2[0] < anMoi2[2])
                        {
                        max2_3x = anMoi2[0];
                        max2_3i = 0;
                        }
                    }
                    else if((anMoi2[0] > anMoi2[1]) && (anMoi2[1] < anMoi2[2]))
                    {
                        if(anMoi2[0] >= anMoi2[2])
                        {
                        max2_3x = anMoi2[2];
                        max2_3i = 2;
                        }
                        else if(anMoi2[0] < anMoi2[2])
                        {
                        max2_3x = anMoi2[0];
                        max2_3i = 0;
                        }
                    }
                    HP = HP - (max2_3x + max2_3i);
                    if(HP > MaxHP)
                        HP = MaxHP;
                    if (HP <= 0){
                        if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                            HP = MaxHP;
                            phoenixdown--;
                            tihon = 0;
                        }
                        else{
                            rescue = 0;
                            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                            return;
                        }
                    }
                } 
            }
        if((tihon == 0)&&(is_tihon == true))
        {
            HP = HP*5;
            is_tihon = false;
        }
        if((ech == 0)&&(is_ech == true))
        {
            level = insLevel;
            is_ech = false;
        }
        if (HP <= 0){
            if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                HP = MaxHP;
                phoenixdown--;
                tihon = 0;
            }
            else{
                rescue = 0;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                return;
            }
        }
        if((i == sk) && (HP > 0))
            rescue = 1;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    if(sukien[i] == 19){//vi than thuoc Asclepius
    if((i == sk) && (HP > 0))
        rescue = 1;
    if((is_tihon == true) && (tihon != 0))
        {
            tihon--;
        }
    if((is_ech == true) && (ech != 0))
        {
            ech--;
        }
    fstream As;
    As.open(file_asclepius_pack,ios::in);
    string dong1_aclepius; //r1 dong
    getline(As, dong1_aclepius);
    stringstream lline1(dong1_aclepius);
    int line1;
    lline1 >> line1;
    
    string dong2_aclepius; //c1 so
    getline(As,dong2_aclepius);
    stringstream lline2(dong2_aclepius);
    int line2;
    lline2 >> line2;

    string dong_i_aclepius; // dong thu ri
    int sodong = 0;
    for(sodong; sodong < line1;sodong++)
    {
        getline(As, dong_i_aclepius);
        stringstream line_i(dong_i_aclepius);
        int soHang = 0;
        int val[line2];
        int lay_thuoc = 0;
        for(soHang; soHang < line2;soHang++)
        {
            line_i >> val[soHang];
            if(lay_thuoc == 3)
            {
                lay_thuoc = 0;
                break;
            }
            if(val[soHang] == 16)
            {
                remedy++;
                lay_thuoc++;
            }
            else if(val[soHang] == 17)
            {
                maidenkiss++;
                lay_thuoc++;
            }
            else if(val[soHang] == 18)
            {
                phoenixdown++;
                lay_thuoc++;
            }
        }
        continue;
    }
    is_thuoc = true;
    if((remedy >= 1) && (is_tihon) == true) 
    {
        HP *= 5;
        remedy--;
        tihon = 0;
        is_tihon = false;
    }
    if((maidenkiss >= 1) && (is_ech == true))
    {
        level = insLevel;
        maidenkiss--;
        ech = 0;
        is_ech = false;
    }
    if((tihon == 0)&&(is_tihon == true))
    {
        HP = HP*5;
        is_tihon = false;
    }
    if((ech == 0)&&(is_ech == true))
    {
        level = insLevel;
        is_ech = false;
    }
    if(remedy > 99)
    remedy = 99;
    if(maidenkiss > 99)
    maidenkiss = 99;
    if(phoenixdown > 99)
    phoenixdown = 99;
    display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
    continue;
    }
    if(sukien[i] == 18){//phu thuy merlin
    if((i == sk) && (HP > 0))
        rescue = 1;
    if((is_tihon == true) && (tihon != 0))
        {
            tihon--;
        }
    if((is_ech == true) && (ech != 0))
        {
            ech--;
        }
    fstream mer;
    mer.open(file_merlin_pack, ios::in);
    string dong1_merlin_pack;
    string dongi_merlin_pack;
    getline(mer,dong1_merlin_pack);
    int soDong;
    stringstream dong11(dong1_merlin_pack);
    dong11 >> soDong;

    int p = 0;
    int vitri;
    int vitriTh;
    int vitriHoa;
    for(p; p < soDong; p++)
    {
        getline(mer, dongi_merlin_pack);
        vitri = dongi_merlin_pack.find("Merlin",0);
        if(vitri != -1)
        {
            HP = HP + 3;   
            continue;
        }
        vitri = dongi_merlin_pack.find("merlin");
        if(vitri != -1)
        {
            HP = HP + 3;   
            continue;
        }
        vitriTh = dongi_merlin_pack.find("m");
        vitriHoa = dongi_merlin_pack.find("M");
        if((vitriTh != -1) || (vitriHoa!= -1))
        {
            vitriTh = dongi_merlin_pack.find("e");
            vitriHoa = dongi_merlin_pack.find("E");
            if((vitriTh != -1) || (vitriHoa!= -1))
            {
                vitriTh = dongi_merlin_pack.find("r");
                vitriHoa = dongi_merlin_pack.find("R");
                if((vitriTh != -1) || (vitriHoa!= -1))
                {
                    vitriTh = dongi_merlin_pack.find("l");
                    vitriHoa = dongi_merlin_pack.find("L");
                    if((vitriTh != -1) || (vitriHoa!= -1))
                    {
                        vitriTh = dongi_merlin_pack.find("i");
                        vitriHoa = dongi_merlin_pack.find("I");
                        if((vitriTh != -1) || (vitriHoa!= -1))
                        {
                            vitriTh = dongi_merlin_pack.find("n");
                            vitriHoa = dongi_merlin_pack.find("N");
                            if((vitriTh != -1) || (vitriHoa!= -1))
                            {
                                HP = HP + 2;
                            }
                            else
                            continue;

                        }
                        else
                        continue;
                    }
                    else
                    continue;
                }
                else
                continue;
            }
            else
            continue;
        }
        else
        continue;
    }
    if(HP > MaxHP)
    HP = MaxHP;
    if((tihon == 0)&&(is_tihon == true))
    {
        HP = HP*5;
        is_tihon = false;
    }
    if((ech == 0)&&(is_ech == true))
    {
        level = insLevel;
        is_ech = false;
    }
    display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
    continue;
    }
    if(level > levelO){ //qua ai va tang 1 level
        if((sukien[i] == 6) || (sukien[i] == 7)){
            level = level + 2;
            if(level >= 10)
                level = 10;
        }
        else
            level++;
            if(level >= 10)
                level = 10;
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
        if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
        if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
        if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    else if(level == levelO){ //qua ai va ko tang level
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((is_Arthur == true) || (is_Lancelot == true))
        {
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((sukien[i] == 6) || (sukien[i] == 7))
            level = level + 2;
        else{
            level++;
        }
        if(level >= 10)
            level = 10;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
        }
        if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
        if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
        if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
        if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
    }
    else if(level < levelO){ //chien dau voi ke dich
        if((is_Arthur == true) || (is_Lancelot == true))
        {
        if((i == sk) && (HP > 0))
            rescue = 1;
        if((sukien[i] == 6) || (sukien[i] == 7))
            level = level + 2;
        else{
            level++;
        }
        if(level >= 10)
            level = 10;
        display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        continue;
        }
        if(sukien[i] == 1){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            baseDamage = 1; //MadBear
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if (HP <= 0){
                if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                    HP = MaxHP;
                    phoenixdown--;
                    tihon = 0;
                }
                else{
                rescue = 0;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                return;
                }
            }
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 2){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            baseDamage = 1.5; //Bandit
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if (HP <= 0){
                if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                    HP = MaxHP;
                    phoenixdown--;
                    tihon = 0;
                }
                else{
                rescue = 0;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                return;
                }
            }
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 3){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            baseDamage = 4.5; //LordLupin
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if (HP <= 0){
                if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                    HP = MaxHP;
                    phoenixdown--;
                    tihon = 0;
                }
                else{
                rescue = 0;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                return;
                }
            }
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 4){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            baseDamage = 7.5; //Elf
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if (HP <= 0){
                if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                    HP = MaxHP;
                    phoenixdown--;
                    tihon = 0;
                }
                else{
                rescue = 0;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                return;
                }
            }
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 5){
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            baseDamage = 9.5; //Troll
            damage = baseDamage * levelO * 10;
            HP = HP - damage;
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if (HP <= 0){
                if(phoenixdown >= 1){ //tang den chi so HP cao nhat tu input
                    HP = MaxHP;
                    phoenixdown--;
                    tihon = 0;
                }
                else{
                rescue = 0;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                return;
                }
            }
            if((i == sk) && (HP > 0))
                rescue = 1;
            display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
        }
        else if(sukien[i] == 6){//phu thuy Shaman
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if((ech != 0)||(tihon != 0)){
                if((i == sk) && (HP > 0))
                    rescue = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                continue;
            }
            else if(remedy >= 1)
            {
                HP /= 5;
                HP *= 5;
                remedy--;
                if((i == sk) && (HP > 0))
                    rescue = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
            else{
                if(HP <= 5)
                    HP = 1;
                else 
                    HP /= 5;
                tihon =  3;
                is_tihon = true;
                if((i == sk) && (HP > 0))
                    rescue = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
        }
        else if(sukien[i] == 7){//Siren Vajsh
            if((is_tihon == true) && (tihon != 0))
            {
                tihon--;
            }
            if((is_ech == true) && (ech != 0))
            {
                ech--;
            }
            if((tihon == 0)&&(is_tihon == true))
            {
                HP = HP*5;
                is_tihon = false;
            }
            if((ech == 0)&&(is_ech == true))
            {
                level = insLevel;
                is_ech = false;
            }
            if((ech != 0)||(tihon != 0)){
                if((i == sk) && (HP > 0))
                    rescue = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
                continue;
            }
            else if(maidenkiss >= 1)
            {
                maidenkiss--;
                if((i == sk) && (HP > 0))
                    rescue = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
            else{
                insLevel = level;
                level = 1;
                ech = 3;
                is_ech = true;
                if((i == sk) && (HP > 0))
                    rescue = 1;
                display(HP, level,remedy,maidenkiss,phoenixdown,rescue);
            }
        }
    }
}     
}