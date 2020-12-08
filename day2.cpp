#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

const int INPUT_LENGTH = 1000;

bool passes_req_p2(string input){
    stringstream string_reader(input);
    bool ans = false;
    int pos1, pos2;
    char req_char;
    string pword;
    int matches = 0;
    string_reader >> pos1;
    string_reader.ignore(1, EOF);
    string_reader >> pos2;
    string_reader.ignore();
    string_reader >> req_char;
    string_reader.ignore();
    string_reader >> pword;
    pos1--;
    pos2--;
    if(((pword[pos1] == req_char) && !(pword[pos2] == req_char)) || (!(pword[pos1] == req_char) && (pword[pos2] == req_char))){
        ans = true;
    }
    return ans;
}

int part2(string *input){
    int ans = 0;
    for(int i = 0; i < INPUT_LENGTH; i++){
        if(passes_req_p2(*(input+i))){
            ans++;
        }
    }
    return ans;
}

bool passes_req_p1(string input){
    stringstream string_reader(input);
    bool ans = false;
    int min, max;
    char req_char;
    string pword;
    int matches = 0;
    string_reader >> min;
    string_reader.ignore(1, EOF);
    string_reader >> max;
    string_reader.ignore();
    string_reader >> req_char;
    string_reader.ignore();
    string_reader >> pword;
    for(int i = 0; i < pword.length(); i++){
        if(pword[i] == req_char){
            matches++;
        }
    }
    if(matches >= min && matches <= max){
        ans = true;
    }
    return ans;
}

int part1(string *input){
    int ans = 0;
    for(int i = 0; i < INPUT_LENGTH; i++){
        if(passes_req_p1(*(input+i))){
            ans++;
        }
    }
    return ans;
}

int main(){
    ifstream input_file("inputs/d2.txt");
    string input[INPUT_LENGTH];
    for(int i = 0; i < INPUT_LENGTH; i++){
        getline(input_file, *(input+i));
    }
    cout << part1(input) << endl << part2(input) << endl;
    input_file.close();
}
