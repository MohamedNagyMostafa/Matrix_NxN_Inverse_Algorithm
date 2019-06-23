#include <iostream>

using namespace std;

void toIdentity(float m2[100][100], int m1_size){
    for(int i =0; i < m1_size; i++){
        m2[i][i] = 1;
    }
}

void divideRowByNumber(float number, float m1[100][100], int m1_size, int row, float m2[100][100]){
    for(int i =0; i < m1_size; i++){
        m1[row][i] /= number;
        m2[row][i] /= number;
    }
}

void doOperation(float number, float m1[100][100], int m1_size, int col, int row, float m2[100][100]){
    for(int k=0; k < m1_size; k++){
        m1[row][k] -= number * m1[col][k];
        m2[row][k] -= number * m2[col][k];
    }
}


void inverse(float m1[100][100], float m2[100][100], int m1_size){
    float selector;

    toIdentity(m2, m1_size);
    for(int i =0; i < m1_size; i++){
        selector = m1[i][i];
        divideRowByNumber(selector, m1, m1_size, i, m2);
        for(int j = 0; j < m1_size; j++){
            if (j == i)
               continue;

            if(m1[j][i] != 0){
                doOperation(m1[j][i], m1, m1_size, i, j, m2);
            }
        }
    }
}

int main()
{
    float m1[100][100], m2[100][100]; int m1_size;

    m1_size = 3;

    for(int i =0; i<m1_size; i++){
            for(int j = 0; j < m1_size; j++){
                cin >> m1[i][j];
            }
    }

    inverse(m1, m2, m1_size);

    for(int i =0; i<m1_size; i++){
            for(int j = 0; j < m1_size; j++){
                cout << m2[i][j]<< " ";
            }
            cout <<endl;
    }
    return 0;
}
