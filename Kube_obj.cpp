#include <iostream>

using namespace std;

class Kube (N)
{
public:
    int size = N;
    int * Kube_ptr;
    int temperature;



    int * generate_Kube(){
        int table [size][6*size];
        for(int face=0;face<6;face++){
            for (int j=face; j < size+face;j++){
                for(int i=0;i<size;i++){
                    table[i][j] = face+1;
                }
            }
        }
        cout<<table;
        return table;
}


};
int * generate_Kube();

int main() {
    Kube kube;
    kube.size = 3;
    kube.generate_Kube()}
