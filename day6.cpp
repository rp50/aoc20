#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>


using namespace std;

const vector<char> ALPHABET{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};

int part1(vector<string> input){
    int total_sum = 0;
    for(string group : input){
        int group_sum = 0;
        unordered_set<char> common_questions;
        for(char letter : group){
            if(common_questions.empty() || common_questions.find(letter) == common_questions.end()){
                common_questions.insert(letter);
                group_sum++;
            }
        }
        total_sum += group_sum;
    }
    return total_sum;
}

int part2(vector<string> input, vector<int> group_sizes){
    int total_sum = 0;
    for(int i = 0; i < input.size(); i++){
        unordered_map<char, int> common_question_count({{'a', 0}, {'b', 0}, {'c', 0}, {'d', 0}, {'e', 0}, {'f', 0}, {'g', 0}, {'h', 0}, {'i', 0}, {'j', 0}, {'k', 0}, {'l',0}, {'m', 0}, {'n', 0}, {'o', 0}, {'p', 0}, {'q', 0}, {'r',0}, {'s', 0}, {'t', 0}, {'u', 0}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0}, {'z', 0}});
        int group_sum = 0;
        for(char letter : input[i]){
            common_question_count[letter] += 1;
        }
        for(auto itr = common_question_count.begin(); itr != common_question_count.end(); itr++){
            if(itr->second == group_sizes[i]){
                group_sum++;
            }
        }
        total_sum += group_sum;
    }
    return total_sum;
}

int main(){
    ifstream input_file("inputs/d6.txt");
    vector<string> input;
    vector<int> group_sizes;
    string current_person;
    string current_group = "";
    int current_group_size = 0;
    while(getline(input_file, current_person)){
        if(current_person.length() != 0){
            current_group += current_person;
            current_group_size++;
        }
        else{
            input.push_back(current_group);
            group_sizes.push_back(current_group_size);
            current_group = "";
            current_group_size = 0;
        }
    }
    input.push_back(current_group);
    group_sizes.push_back(current_group_size);
    cout << part1(input) << endl << part2(input, group_sizes) << endl;
    input_file.close();
}
