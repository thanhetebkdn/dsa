#include <iostream>
#include <fstream>
#include <math.h>
using namespace std;

const int MAX_CONTESTANTS = 100000;

int main()
{
    ifstream fin("Input_1.inp");
    ofstream fout("Output.out");
    if (!fin)
    {
        cout << "Không thể mở tệp đầu vào!" << endl;
        return 1;
    }
    int N;
    fin >> N;
    int scores[MAX_CONTESTANTS] = {0};
    int maxCode = -1;
    int maxScore = -1;

    for (int i = 0; i < N; i++)
    {
        int C, P;
        fin >> C >> P;

        if (C == 0 && P == 0)
        {

            fout << maxCode << endl;
        }
        else
        {

            scores[C] += P;

            if (scores[C] > maxScore)
            {
                maxScore = scores[C];
                maxCode = C;
            }
        }
    }
    fin.close();
    fout.close();

    return 0;
}
