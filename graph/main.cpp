#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ifstream fin("Input_1.inp");
    ofstream fout("Output.out");

    int N, M, T;
    fin >> N >> M >> T;

    vector<vector<int>> adjMatrix(N, vector<int>(N, 0));

    if (T == 0 || T == 2)
    {

        for (int i = 0; i < M; ++i)
        {
            int A, B;
            fin >> A >> B;
            A--;
            B--;
            adjMatrix[A][B] = 1;
            if (T == 0)
            {
                adjMatrix[B][A] = 1;
            }
        }
    }
    else if (T == 1 || T == 3)
    {

        for (int i = 0; i < M; ++i)
        {
            int A, B, W;
            fin >> A >> B >> W;
            A--;
            B--;

            if (max(A, B) >= N)
            {
                int newSize = max(A, B) + 1;
                adjMatrix.resize(newSize, vector<int>(newSize, 0));
                N = newSize;
            }

            adjMatrix[A][B] = W;
            if (T == 1)
            {
                adjMatrix[B][A] = W;
            }
        }
    }

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            fout << adjMatrix[i][j];
            if (j < N - 1)
                fout << " ";
        }
        fout << endl;
    }

    fin.close();
    fout.close();

    return 0;
}
