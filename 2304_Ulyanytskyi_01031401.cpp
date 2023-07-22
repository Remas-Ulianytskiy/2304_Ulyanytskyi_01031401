#include <iostream>
#include <vector>
#include <string>

using namespace std;

template <typename type>
type get_user_input()
{
    type input;
    cin >> input;
    return input;
}

template <typename type>
vector<vector<type>> solution(unsigned size, type above, type diagonal, type below)
{
    vector<vector<type>> result;

    for (unsigned i = 0; i < size; ++i)
    {
        vector<type> temp;
        for (unsigned j = 0; j < size; ++j)
        {
            if (i == j)
                temp.push_back(diagonal);
            else if (j > i)
                temp.push_back(above);
            else
                temp.push_back(below);
        }
        result.push_back(temp);
    }

    return result;
}

template <typename type>
void reverse_solution(vector<vector<type>>& matrix)
{
    unsigned size = matrix.size();

    for (unsigned i = 0; i < size; ++i)
    {
        for (unsigned j = 0; j < size; ++j)
        {
            type temp;
            if (i == j)
                continue;
            else if (j > i)
            {
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
}

template <typename type>
void display_matrix(vector<vector<type>>& matrix)
{
    unsigned matrix_size = matrix.size();
    for (unsigned i = 0; i < matrix_size; ++i)
    {
        for (unsigned j = 0; j < matrix_size; ++j)
            cout << matrix[i][j] << ' ';
        cout << endl;
    }
}

int main()
{
    string user_input;
    vector<vector<char>> table;

    const unsigned MIN_MATRIX_SIZE = 3;
    const unsigned MAX_MATRIX_SIZE = 10;

    cout << "Simple matrix system\n";
    cout << "For exit, type \"Exit\" or \"exit\"\n";

    while (true)
    {
        int size;

        table.clear();

        cout << "Enter matrix size. Size must be: >= " ;
        cout << MIN_MATRIX_SIZE << ", <= " << MAX_MATRIX_SIZE;
        cout << "\nEnter: ";

        user_input = get_user_input<string>();

        if (user_input == "Exit" || user_input == "exit")
        {
            cout << "Exit!\n";
            break;
        }

        size = stoi(user_input);

        if (size >= MIN_MATRIX_SIZE && size <= MAX_MATRIX_SIZE)
        {
            cout << "\nMatrix with size " << size << ":\n";
            vector<vector<char>> table = solution(size, 'x', '-', 'o');
            display_matrix(table);

            cout << "Revers martix:\n";
            reverse_solution(table);
            display_matrix(table);
        }
        else
        {
            cout << "Invalid input!\n";
        }

        cout << endl;
    }

    return 0;
}