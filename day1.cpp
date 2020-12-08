#include <iostream>
#include <fstream>

using namespace std;

const int INPUT_LENGTH = 200;

int part2(int *input){
    int ans = -1;
    for(int i = 0; i < INPUT_LENGTH && ans == -1; i++){
        for(int j = i; j < INPUT_LENGTH && ans == -1; j++){
            for(int k = j; k < INPUT_LENGTH && ans == -1; k++){
                if(*(input+k) + *(input+i) + *(input+j) == 2020){
                    ans =(*(input+i))*(*(input+j))*(*(input+k));
                }
            }
        }

    }
    return ans;
}

int part1(int *input){
    int ans = -1;
    for(int i = 0; i < INPUT_LENGTH && ans == -1; i++){
        for(int j = i+1; j < INPUT_LENGTH && ans == -1; j++){
            if((*(input+i))+(*(input+j)) == 2020){
                ans =(*(input+i))*(*(input+j));
            }
        }
    }
    return ans;
}

int main(){
    ifstream input_file("./inputs/d1.txt");
    int input[INPUT_LENGTH];
    for(int i = 0; i < INPUT_LENGTH; i++){
        input_file >> *(input+i);
    }
    cout << part1(input) << endl << part2(input) << endl;
}
