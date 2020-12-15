#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

long part1(vector<long> input){
    long invalid = -1;
    for(auto cur = input.begin()+25; cur != input.end(); cur++){
        long cur_l = *cur;
        bool found = false;
        for(auto outer = cur-25; outer != cur && !found; outer++){
            for(auto inner = outer+1; inner != cur && !found; inner++){
                found = (cur_l == *outer + *inner);
            }
        }
        if(!found && cur_l){
            invalid = cur_l;
            break;
        }
    }
    return invalid;
}

long part2(vector<long> input){
    long smallest=0, largest=0;
    long target = part1(input);
    for(int i = 2; i < input.size(); i++){
        for(auto cur = input.begin(); cur != input.end(); cur++){
            long loc_total = 0, loc_sm = *cur, loc_lg = *cur; 
            for(int j = 0; j < i; j++){
                loc_total += *(cur+j);
                if(loc_sm > *(cur+j)){
                    loc_sm = *(cur+j);
                }
                else if(loc_lg < *(cur+j)){
                    loc_lg = *(cur+j);
                }
            }
            if(loc_total == target){
                largest = loc_lg;
                smallest = loc_sm;
                break;
            }
        }
        if(smallest != 0){
            break;
        }
    }
    return smallest+largest;
}

int main(){
    ifstream input_file("inputs/d9.txt");
    vector<long> input;
    string curr;
    int i = 0;
    while(getline(input_file, curr)){
        long cur_l = stol(curr);
        input.push_back(cur_l);
    }
    cout << part1(input) << endl << part2(input) << endl;
    input_file.close();
}
