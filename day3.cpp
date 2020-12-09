#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int toboggon_sim(vector<string>input, int rise, int run){
    int trees = 0;
    int x = 0;
    int y = 0;
    while(y < input.size()){
        if(input[y][x] == '#'){
            trees++;
        }
        x = (x+run < input[y].length() ? x + run : (x + run - input[y].length()));
        y = y + rise;
    }
    return trees;

}

long part2(vector<string> input){
    long product;  
    long one_one = toboggon_sim(input, 1, 1);
    long one_three = toboggon_sim(input, 1, 3);
    long one_five = toboggon_sim(input, 1, 5);
    long one_seven = toboggon_sim(input, 1, 7);
    long two_one = toboggon_sim(input, 2, 1);
    product = one_one * one_three * one_five * one_seven * two_one;
    return product;
}

int part1(vector<string> input){
    return toboggon_sim(input, 1, 3);
}
int main(){
    ifstream input_file("inputs/d3.txt");
    vector<string> input;
    string curr;
    while(getline(input_file, curr)){
        input.push_back(curr);
    }
    cout << toboggon_sim(input, 1, 3) << endl << part2(input) << endl;
    input_file.close();
}
