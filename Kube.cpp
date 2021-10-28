//
// Created by g0bel1n on 27/10/2021.
//

#include "Kube.h"
#include <cstdlib>

using namespace std;

Kube::Kube(int size)
{
    m_size = size;
    vector<vector<int>> test(m_size, vector<int>(m_size*6));
    m_array = test;
    fill();
}
void Kube::show(int i, int j) {
    cout << m_array[i][j]<<'\n';
}

void Kube::fill(){
    int iter =0;
    for(int face=0;face<6;face++){
        for (int j=iter; j < m_size+iter;j++){
            for(int i=0;i<m_size;i++) {
                m_array[i][j] = face + 1;
            }
        }
        iter+=3;
    }
}
void Kube::shuffle(int N)
{
for (int i=0; i<N;i++){
    make_random_move(i);
}
}

char Kube::make_random_move(int i){
    srand((unsigned )time(nullptr)+i);
    int index;
    index = 1+ rand()%18;
    //cout<< index<<"\n";
    switch (index)
    {
        case 1: FC();return 'F';
        case 2: RC();return 'R';
        case 3: DC();return 'D';
        case 4: LC();return 'L';
        case 5: UC();return 'U';
        case 6: BC();return 'B';
        case 7: MH();return 'H';
        case 8: MV();return 'V';
        case 9: MC();return 'C';

        case 10: FC();FC();FC();return 'AF';
        case 11: RC();RC();RC();return 'AR';
        case 12: DC();DC();DC();return 'AD';
        case 13: LC();LC();LC();return 'AL';
        case 14: UC();UC();UC();return 'AU';
        case 15: BC();BC();BC();return 'AB';
        case 16: MH();MH();MH();return 'AH';
        case 17: MV();MV();MV();return 'AV';
        case 18: MC();MC();MC();return 'AC';
    }
    return 0;
}

char Kube::make_move(int i){
    //cout<< index<<"\n";
    switch (i)
    {
        case 1: FC();return 'F';
        case 2: RC();return 'R';
        case 3: DC();return 'D';
        case 4: LC();return 'L';
        case 5: UC();return 'U';
        case 6: BC();return 'B';
        case 7: MH();return 'H';
        case 8: MV();return 'V';
        case 9: MC();return 'C';

        case 10: FC();FC();FC();return 'AF';
        case 11: RC();RC();RC();return 'AR';
        case 12: DC();DC();DC();return 'AD';
        case 13: LC();LC();LC();return 'AL';
        case 14: UC();UC();UC();return 'AU';
        case 15: BC();BC();BC();return 'AB';
        case 16: MH();MH();MH();return 'AH';
        case 17: MV();MV();MV();return 'AV';
        case 18: MC();MC();MC();return 'AC';
    }
    return 0;
}

int Kube::get_cost_func(){
    int score=0;
    vector<vector<int>> centers{{1,7},{1,10},{1,13},{1,4},{1,1},{1,16}};
    for(const auto& center: centers) {
        int i = center[0];
        int j = center[1];
        int center_value = m_array[i][j];
        if (m_array[i+1][j]!=center_value){score++;}
        if (m_array[i-1][j]!=center_value){score++;}
        if (m_array[i+1][j+1]!=center_value){score++;}
        if (m_array[i+1][j-1]!=center_value){score++;}
        if (m_array[i-1][j+1]!=center_value){score++;}
        if (m_array[i-1][j-1]!=center_value){score++;}
        if (m_array[i][j+1]!=center_value){score++;}
        if (m_array[i][j-1]!=center_value){score++;}
    }
    return score;
}

int Kube::get_cost_func_OF(){
    int score=0;
    vector<vector<int>> centers{{1,7}};
    for(const auto& center: centers) {
        int i = center[0];
        int j = center[1];
        int center_value = m_array[i][j];
        if (m_array[i+1][j]!=center_value){score++;}
        if (m_array[i-1][j]!=center_value){score++;}
        if (m_array[i+1][j+1]!=center_value){score++;}
        if (m_array[i+1][j-1]!=center_value){score++;}
        if (m_array[i-1][j+1]!=center_value){score++;}
        if (m_array[i-1][j-1]!=center_value){score++;}
        if (m_array[i][j+1]!=center_value){score++;}
        if (m_array[i][j-1]!=center_value){score++;}
    }
    return score;
}

void Kube::FC(){
    int a=m_array[2][0];
    int b=m_array[2][1];
    int c=m_array[2][2];
    int d = m_array[0][7];
    //ext crown
    m_array[2][0]= m_array[2][5];
    m_array[2][1]=m_array[1][5];
    m_array[2][2]= m_array[0][5];
    m_array[0][5]= m_array[0][15];
    m_array[1][5]=m_array[0][16];
    m_array[2][5]=m_array[0][17];
    m_array[0][15]= m_array[2][9];
    m_array[0][16]=m_array[1][9];
    m_array[0][17]=m_array[0][9];
    m_array[0][9]=a;
    m_array[1][9]=b;
    m_array[2][9] =c;

    //face
    m_array[0][6]= m_array[2][6];
    m_array[0][7]=m_array[1][6];
    m_array[0][8]=m_array[0][6];
    m_array[2][8] =m_array[0][8];
    m_array[2][6]= m_array[2][8];
    m_array[1][6] =m_array[2][7];
    m_array[2][7]= m_array[1][8];
    m_array[1][8] = d;
}

void Kube::RC(){
    int a=m_array[2][2];
    int b=m_array[1][2];
    int c=m_array[0][2];
    int d = m_array[0][10];
    //ext crown
    m_array[2][2]=m_array[2][8];
    m_array[1][2]=m_array[1][8];
    m_array[0][2]=m_array[0][8];
    m_array[2][8]= m_array[2][17];
    m_array[1][8]=m_array[1][17];
    m_array[0][8]=m_array[0][17];
    m_array[2][17]= m_array[0][12];
    m_array[1][17]=m_array[1][12];
    m_array[0][17]= m_array[2][12];
    m_array[0][12]=a;
    m_array[1][12]=b;
    m_array[2][12] =c;

    //face
    m_array[0][9]= m_array[2][9];
    m_array[0][10]=m_array[1][9];
    m_array[0][11]=m_array[0][9];
    m_array[2][9]= m_array[2][11];
    m_array[1][9] = m_array[2][10];
    m_array[2][11]= m_array[0][11];
    m_array[2][10]= m_array[1][11];
    m_array[1][11] =d;
}

void Kube::LC(){
    int a=m_array[0][0];
    int b=m_array[1][0];
    int c=m_array[2][0];
    int d =m_array[0][4];
    //ext crown
    m_array[0][0] = m_array[2][14];
    m_array[1][0] = m_array[1][14];
    m_array[2][0] = m_array[0][14];
    m_array[2][14]= m_array[0][15];
    m_array[1][14] =m_array[1][15];
    m_array[0][14]= m_array[2][15];
    m_array[0][15]  = m_array[0][6];
    m_array[1][15]= m_array[1][6];
    m_array[2][15] = m_array[2][6];
    m_array[0][6]=a;
    m_array[1][6]=b;
    m_array[2][6] = c;

    //face
    m_array[0][3]= m_array[2][3];
    m_array[0][4]=m_array[1][3];
    m_array[0][5] =m_array[0][3];
    m_array[2][3]= m_array[2][5];
    m_array[1][3] = m_array[2][4];
    m_array[2][5]= m_array[0][5];
    m_array[2][4] = m_array[1][5];
    m_array[1][5] = d;
}

void Kube::UC(){
int a =  m_array[0][14];
int b = m_array[0][13];
int c = m_array[0][12];
int d = m_array[0][1];
//ext crown
    m_array[0][14]= m_array[0][5];
    m_array[0][13]=m_array[0][4];
    m_array[0][12]=m_array[0][3];
    m_array[0][3]= m_array[0][8];
    m_array[0][4]=m_array[0][7];
    m_array[0][5]=m_array[0][6];
    m_array[0][8]= m_array[0][11];
    m_array[0][7]=m_array[0][10];
    m_array[0][6]=m_array[0][9];
    m_array[0][11]= a;
    m_array[0][10]=b;
    m_array[0][9]=c;

    //face
    m_array[0][0]= m_array[0][2];
    m_array[0][1]=m_array[1][0];
    m_array[0][2]=m_array[0][0];
    m_array[2][0] = m_array[2][2];
    m_array[1][0]=m_array[2][1];
    m_array[2][2]= m_array[0][2];
    m_array[2][1]=m_array[1][2];
    m_array[1][2] = d;
}

void Kube::DC(){
    int a =  m_array[2][6];
    int b = m_array[2][7];
    int c = m_array[2][8];
    int d = m_array[0][16];
    //ext crown
    m_array[2][6]= m_array[2][3];
    m_array[2][7]=m_array[2][4];
    m_array[2][8]=m_array[2][5];
    m_array[2][3]= m_array[2][12];
    m_array[2][4]=m_array[2][13];
    m_array[2][5]=m_array[2][14];
    m_array[2][12]= m_array[2][9];
    m_array[2][13]=m_array[2][10];
    m_array[2][14]=m_array[2][11];
    m_array[2][9]= a;
    m_array[2][10]=b;
    m_array[2][11]=c;

    //face
    m_array[0][15]= m_array[2][15];
    m_array[0][16]=m_array[1][15];
    m_array[0][17]=m_array[0][15];
    m_array[2][15]= m_array[2][17];
    m_array[1][15]=m_array[2][16];
    m_array[2][17]= m_array[0][17];
    m_array[2][16]=m_array[1][17];
    m_array[1][17] = d;
}

void Kube::BC(){
    int a =  m_array[0][2];
    int b = m_array[0][1];
    int c = m_array[0][0];
    int d = m_array[0][13];
    //ext crown
    m_array[0][2]= m_array[2][11];
    m_array[0][1]=m_array[1][11];
    m_array[0][0]=m_array[0][11];
    m_array[2][11]= m_array[2][15];
    m_array[1][11]=m_array[2][16];
    m_array[0][11]=m_array[2][17];
    m_array[2][15]= m_array[0][3];
    m_array[2][16]=m_array[1][3];
    m_array[2][17]=m_array[2][3];
    m_array[0][3]= a;
    m_array[1][3]=b;
    m_array[2][3]=c;

    //face
    m_array[0][12]= m_array[2][12];
    m_array[0][13]=m_array[1][12];
    m_array[0][14]=m_array[0][12];
    m_array[2][12]= m_array[2][14];
    m_array[1][12]=m_array[2][13];
    m_array[2][14]= m_array[0][14];
    m_array[2][13]= m_array[1][14];
    m_array[1][14] = d;
}

void Kube::MV(){

    // Middle vertical, front face, up
    int a =m_array[2][7];
    int b=m_array[1][7];
    int c=m_array[0][7];

    m_array[2][7]=m_array[2][16];
    m_array[1][7]=m_array[1][16];
    m_array[0][7] = m_array[0][16];
    m_array[2][16]= m_array[0][13];
    m_array[1][16]=m_array[1][13];
    m_array[0][16]=m_array[2][13];
    m_array[0][13]= m_array[2][1];
    m_array[1][13]=m_array[1][1];
    m_array[2][13]=m_array[0][1];

    m_array[2][1]=a;
    m_array[1][1]=b;
    m_array[0][1] =c;
}

void Kube::MH(){
    // Middle Horizontal, front face, R

    int a = m_array[1][6];
    int b = m_array[1][7];
    int c = m_array[1][8];

    m_array[1][6]=m_array[1][3];
    m_array[1][7]=m_array[1][4];
    m_array[1][8]=m_array[1][5];
    m_array[1][3]= m_array[1][12];
    m_array[1][4]=m_array[1][13];
    m_array[1][5]=m_array[1][14];
    m_array[1][12]= m_array[1][9];
    m_array[1][13]=m_array[1][10];
    m_array[1][14]=m_array[1][11];
    m_array[1][9]= a;
    m_array[1][10]=b;
    m_array[1][11]=c;
}

void Kube:: MC(){
    // Middle clockwise, front face

    int a = m_array[1][0];
    int b = m_array[1][1];
    int c = m_array[1][2];

    m_array[1][0]= m_array[2][4];
    m_array[1][1]=m_array[1][4];
    m_array[1][2]=m_array[0][4];
    m_array[2][4]=m_array[1][17];
    m_array[1][4]=m_array[1][16];
    m_array[0][4] =m_array[1][15];
    m_array[1][17]= m_array[0][10];
    m_array[1][16]=m_array[1][10];
    m_array[1][15]=m_array[2][10];
    m_array[0][10] = a;
    m_array[1][10]=b;
    m_array[2][10] = c;
}