#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

struct Node
{
    int code;
    int score;
    Node *next;
};

const int TABLE_SIZE = 10007;

class HashTable
{
private:
    vector<Node *> table;

public:
    HashTable()
    {
        table.resize(TABLE_SIZE, nullptr);
    }

    int hashFunction(int code)
    {
        return code % TABLE_SIZE;
    }

    void insert(int code, int score)
    {
        int index = hashFunction(code);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->code == code)
            {
                current->score += score;
                return;
            }
            current = current->next;
        }

        Node *newNode = new Node{code, score, table[index]};
        table[index] = newNode;
    }

    int getScore(int code)
    {
        int index = hashFunction(code);
        Node *current = table[index];

        while (current != nullptr)
        {
            if (current->code == code)
            {
                return current->score;
            }
            current = current->next;
        }
        return 0;
    }
};

int main()
{
    ifstream fin("Prog.inp");
    ofstream fout("Prog.out");

    if (!fin)
    {
        cout << "Không thể mở tệp đầu vào!" << endl;
        return 1;
    }

    int N;
    fin >> N;

    HashTable scores;
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
            scores.insert(C, P);

            int currentScore = scores.getScore(C);

            if (currentScore > maxScore)
            {
                maxScore = currentScore;
                maxCode = C;
            }
        }
    }

    fin.close();
    fout.close();

    return 0;
}
