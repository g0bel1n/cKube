#include <iostream>
#include <cmath>
#include </Users/g0bel1n/CLionProjects/cKube/Kube.h>
using namespace std;

void solver(Kube kube){
    float temp = 1000;
    float cooling_rate = 0.0005;
    //long double kb = 1.38064852*pow(10,-23); //Boltzmann Constant

    int score = kube.get_cost_func_OF();
    int i =0; // Number of iterations
    int moves =0; // Number of validated moves
    int frozen_since=0; //Number of iterations where the score is not altered
    int pass_prob=0; // Number of states accepted because of probability acceptance
    while (temp>1 && score != 0 && frozen_since<1000){
            vector<vector<int>> saved_array = kube.m_array;
            kube.make_random_move(i);
            //kube.make_move(1+(i%18));
            //cout << 1+(i%18)<<"\n";
            float n_score = kube.get_cost_func_OF();
            float delta = n_score - score;
            if (delta <= 0) { score = n_score; moves++;frozen_since=0;}
            if(delta>0){
                srand((unsigned )time(nullptr)+i);
                float U =0;
                U = rand()%1000/1000.0;
                if (U< exp(-(delta*1e3)/(temp))){score = n_score; moves++;pass_prob++;frozen_since=0;}
                else {kube.m_array = saved_array; frozen_since++;}


        }
        temp*=(1-cooling_rate);
        i++;

    }
    cout <<"iter = "<< i<<"\n";
    cout <<"moves = "<< moves<<"\n";
    cout <<"passprob = "<< pass_prob<<"\n";
    cout << "final cost =" << kube.get_cost_func_OF()<< '\n';
}

int main() {
    Kube kube(3);
    kube.shuffle(
            20
            );
    float init_cost = kube.get_cost_func_OF();
    solver(kube);
    cout << "init cost =" << init_cost<< '\n';
}

