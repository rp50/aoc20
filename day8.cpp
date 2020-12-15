#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <utility>

using namespace std;

int part2(vector<pair<string, bool>> inputs){
    int acc_total = 0;
    bool terminated = false;
    for(int i = 0; !terminated; i++){
        acc_total = 0;
        int nxt_jmp = 1;
        int cur_step = 0;
        vector<pair<string, bool>> local_inputs = inputs;
        for(auto cur = local_inputs.begin(); cur != local_inputs.end() && !cur->second; cur+=nxt_jmp){
            int val = stoi(cur->first.substr(4));
            if(cur->first.find("jmp") != -1){
                if(cur_step == i){
                    nxt_jmp = 1;
                    cur_step++;
                }
                else{
                    cur_step++;
                    nxt_jmp = val;
                }
            }
            else if(cur->first.find("nop") != -1){
                if(cur_step == i){
                    nxt_jmp = val;
                    cur_step++;
                }
                else{
                    cur_step++;
                    nxt_jmp = 1;
                }
                
            }
            else if(cur->first.find("acc") != -1){
                acc_total += val;
                nxt_jmp = 1;
            }
            cur->second = true;
            terminated = (cur+nxt_jmp == local_inputs.end());
        }
    }
    return acc_total;
 
}

int part1(vector<pair<string, bool>> inputs){
    int acc_total = 0;
    int nxt_jmp = 1;
    for(auto cur = inputs.begin(); cur != inputs.end() && !cur->second; cur+=nxt_jmp){
        int val = stoi(cur->first.substr(4));
        if(cur->first.find("jmp") != -1){
            nxt_jmp = val;
        }
        else{ 
            if(cur->first.find("acc") != -1){
                acc_total += val;
            }
            nxt_jmp = 1;
        }
        cur->second = true;
    }
    return acc_total;
}

int main(){
    ifstream input_file("inputs/d8.txt");
    vector<pair<string, bool>> inputs;
    string curr;
    while(getline(input_file, curr)){
        inputs.push_back(make_pair(curr, false));
    }
    cout << "Size of Input: " << inputs.size() << endl;
    cout << part1(inputs) << endl << part2(inputs) << endl;
    input_file.close();
}
