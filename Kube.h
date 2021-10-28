//
// Created by g0bel1n on 27/10/2021.
//


#include <iostream>
#include <vector>
#ifndef CKUBE_KUBE_H
#define CKUBE_KUBE_H


class Kube {

    typedef void (Kube::*Func)();

public:
    Kube(int);
    void fill();
    void shuffle(int);
    void show(int, int);
    int get_cost_func(); // For all faces
    int get_cost_func_OF(); //For one face
    char make_random_move(int i);
    char make_move(int i);
    void UC();
    void LC();
    void FC();
    void RC();
    void BC();
    void DC();
    void MV();
    void MH();
    void MC();
    std::vector<std::vector<int>> m_array;


private:
    int m_size;

};


#endif //CKUBE_KUBE_H
