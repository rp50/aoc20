#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cmath>
#include <set>

using namespace std;

int binaryToBase10(long n){
    int a = 0, i = 0, remainder;
    while(n != 0){
        remainder = n%10;
        n = n/10;
        a += remainder*pow(2,i);
        i++;
    }
    return a;
}

int boardingPassCalc(string input){
    long row_binary = 0;
    int row = 0;
    long col_binary = 0;
    int col = 0;
    for(int i = 0; i < input.length(); i++){
        if(input[i] == 'F'){
            row_binary = row_binary*10;
        }
        else if(input[i] == 'B'){
            row_binary = row_binary*10+1;
        }
        else if(input[i] == 'L'){
            col_binary = col_binary*10;
        }
        else if(input[i] == 'R'){
            col_binary = col_binary*10+1;
        }
    }
    row = binaryToBase10(row_binary);
    col = binaryToBase10(col_binary);
    int pass_num = row * 8 + col;
    return pass_num;
    
}

int part2(vector<string> input){
    set<int, less<int>> passes;
    set<int, less<int>>::iterator itr;
    int pass_num = -1;
    for(int i = 0; i < input.size(); i++){
        passes.insert(boardingPassCalc(input[i]));
    }
    int prev_value = 0;
    for(itr = passes.begin(); itr != passes.end() && pass_num == -1; itr++){
        if(*itr == prev_value+2){             
            pass_num = prev_value+1;
        }
        else{
            prev_value = *itr;
        }
    }
    return pass_num;
}

int part1(vector<string> input){
    int largest_pass = boardingPassCalc(input[0]);
    for(int i = 1; i < input.size(); i++){
        int current_pass = boardingPassCalc(input[i]);
        if(largest_pass < current_pass){
            largest_pass = current_pass;
        }
    }
    return largest_pass;
}
int main(){
    ifstream input_file("inputs/d5.txt");
    vector<string> input;
    string curr;
    while(getline(input_file, curr)){
        input.push_back(curr);
    }
    cout << part1(input) << endl << part2(input) << endl;
    input_file.close();
}
