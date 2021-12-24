#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<string>
using std::ifstream;
using std::istringstream;
using std::vector;
using std::string;
using std::cout;

enum class State {KEmpty, KObsteacle};

// reading the content of a line to the int vector 
vector<State> ParseLine(string line){
    istringstream sline(line);
    int n;
    char c;
    vector<State> row;

    while(sline>>n>>c && c==','){
        if (n==0)
        {
            row.push_back(State::KEmpty);
        }
        else{
            row.push_back(State::KObsteacle);
        }
            
    }
    return row;
}

vector<vector<State>> ReadBoardFile(string path)
{
    ifstream myfile(path);
    vector<vector<State>> board{};
    if(myfile)
    {
        string line;
        while(getline(myfile,line))
        {
            vector<State> row = ParseLine(line);
            board.push_back(row);
        }
    }
    return board;
}

string CellString(State cell){
    switch(cell)
    {
        case State::KEmpty: return "0   "; 
        case State::KObsteacle: return "⛰️   "; 
    }
}

void PrintBoard(const vector<vector<State>> board){
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){

            cout<<CellString(board[i][j]);
        }
        cout<<"\n";
    }    
}

int main()
{
      auto board = ReadBoardFile("1.board");
      PrintBoard(board); 

}