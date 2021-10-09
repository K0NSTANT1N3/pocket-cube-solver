#include<iostream>
#include<vector>
#include<set>
using namespace std;

const string solvedComb = "YYYYGGRRBBOOGGRBOOWWW";

void moveR(string& scramb);

void moveF(string& scramb);

void moveU(string& scramb);

void moveR2(string& scramb);

void moveF2(string& scramb);

void moveU2(string& scramb);

void moveRprime(string& scramb);

void moveFprime(string& scramb);

void moveUprime(string& scramb);


bool solveCube(string& scramb, int depth, string ans, char rep, set<string>& stor, vector<string>& answers);

string shortestPath(vector<string> answers);

int main(){
    string ans = "";
    char rep;
    string scramb;
    // scramb = "YBGGOWOWRRYBGRYWOYOBG";
    cout << "Please enter your pocket cubes puzzle correctly <3" << endl;
    cin >> scramb;
    cout << endl;
    set <string> stor;
    vector<string> answers;

    solveCube(scramb, 0, ans, rep, stor, answers);
    string finalAns = shortestPath(answers);
    
    cout << "All possible solution under 12 moves are: " << endl;

    for(int i = 0; i < answers.size(); i++){
        cout << answers[i] << endl;
    }
     
    cout << endl <<" recomended answer is: "<< finalAns << endl;


}

bool solveCube(string& scramb, int depth, string ans, char rep, set <string>& stor, vector<string>& answers){
    //base case
    if(scramb == solvedComb){
        answers.push_back(ans);
        return true;
    }

    if(depth > 12){
        if(scramb == solvedComb){
            answers.push_back(ans);
            return true;
        }
        return false;
    }

    int lastSz = stor.size();
    stor.insert(scramb);
    if(lastSz == stor.size())return false;
    
    // main case


    //positive moves
    // Right move
    if(rep != 'R'){
        char last = rep;
        rep = 'R';
        
        ans.push_back('R');
        moveR(scramb);      
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveRprime(scramb);
        ans = ans.substr(0, ans.size() - 1);

        rep = last;
    }

    //Up move
    if(rep != 'U'){
        char last = rep;
        rep = 'U';

        ans.push_back('U');
        moveU(scramb);      
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveUprime(scramb);
        ans = ans.substr(0, ans.size() - 1);

        rep = last;
    }

    //Front move
    if(rep != 'F'){
        char last = rep;
        rep = 'F';

        ans.push_back('F');
        moveF(scramb);     
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveFprime(scramb);
        ans = ans.substr(0, ans.size() - 1);

        rep = last;
    }

    //double moves
    //Two Right move
    if(rep != 'R'){
        char last = rep;
        rep = 'R';

        ans.push_back('R'); ans.push_back('2');
        moveR2(scramb);  
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveR2(scramb);
        ans = ans.substr(0, ans.size() - 2);

        rep = last;
    }

    //Two Up move
    if(rep != 'U'){
        char last = rep;
        rep = 'U';

        ans.push_back('U'); ans.push_back('2');
        moveU2(scramb);  
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveU2(scramb);
        ans = ans.substr(0, ans.size() - 2);

        rep = last;
    }

    //Two Front move
    if(rep != 'F'){
        char last = rep;
        rep = 'F';

        ans.push_back('F'); ans.push_back('2');
        moveF2(scramb);
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveF2(scramb);
        ans = ans.substr(0, ans.size() - 2);

        rep = last;
    }

    //Negative moves
    //Right prime move
    if(rep != 'R'){
        char last = rep;
        rep = 'R';
        
        ans.push_back('R'); ans.push_back('*');
        moveRprime(scramb);
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveR(scramb);
        ans = ans.substr(0, ans.size() - 2);

        rep = last;        
    }

    //Up Prime move
    if(rep != 'U'){
        char last = rep;
        rep = 'U';

        ans.push_back('U'); ans.push_back('*');
        moveUprime(scramb); 
       solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveU(scramb);
        ans = ans.substr(0, ans.size() - 2);

        rep = last;
    }
    
    //Front Prime move
    if(rep != 'F'){
        char last = rep;
        rep = 'F';
        
        ans.push_back('F'); ans.push_back('*');
        moveFprime(scramb);
        solveCube(scramb, depth + 1, ans, rep, stor, answers);
        moveF(scramb);
        ans = ans.substr(0, ans.size() - 2);

        rep = last;
    }


    return false;

}

void moveR(string& scramb){
    string oldScramb = scramb;

    scramb[0] = oldScramb[12];      scramb[3] = oldScramb[4];
    scramb[12] = oldScramb[20];     scramb[4] = oldScramb[18];
    scramb[20] = oldScramb[9];      scramb[18] = oldScramb[15];
    scramb[9] = oldScramb[0];       scramb[15] = oldScramb[3];

    scramb[11] = oldScramb[17];     scramb[17] = oldScramb[16];
    scramb[16] = oldScramb[10];     scramb[10] = oldScramb[11];
}

void moveF(string& scramb){
    string oldScramb = scramb;

    scramb[1] = oldScramb[14];       scramb[0] = oldScramb[6];
    scramb[14] = oldScramb[18];      scramb[6] = oldScramb[19];
    scramb[18] = oldScramb[11];      scramb[19] = oldScramb[17];
    scramb[11] = oldScramb[1];       scramb[17] = oldScramb[0];

    scramb[5] = oldScramb[13];      scramb[13] = oldScramb[12];
    scramb[12] = oldScramb[4];      scramb[4] = oldScramb[5];
}

void moveU(string& scramb){
    string oldScramb = scramb;

    scramb[4] = oldScramb[10];       scramb[5] = oldScramb[11];
    scramb[10] = oldScramb[8];       scramb[11] = oldScramb[9];
    scramb[8] = oldScramb[6];        scramb[9] = oldScramb[7];
    scramb[6] = oldScramb[4];        scramb[7] = oldScramb[5];

    scramb[0] = oldScramb[3];      scramb[3] = oldScramb[2];
    scramb[2] = oldScramb[1];      scramb[1] = oldScramb[0];
}

void moveR2(string& scramb){
    string oldScramb = scramb;

    scramb[0] = oldScramb[20];      scramb[20] = oldScramb[0];
    scramb[3] = oldScramb[18];     scramb[18] = oldScramb[3];
    scramb[9] = oldScramb[12];      scramb[12] = oldScramb[9];
    scramb[15] = oldScramb[4];       scramb[4] = oldScramb[15];

    scramb[11] = oldScramb[16];     scramb[17] = oldScramb[10];
    scramb[16] = oldScramb[11];     scramb[10] = oldScramb[17];
}

void moveF2(string& scramb){
    string oldScramb = scramb;

    scramb[0] = oldScramb[19];        scramb[19] = oldScramb[0];
    scramb[1] = oldScramb[18];        scramb[18] = oldScramb[1];
    scramb[6] = oldScramb[17];        scramb[17] = oldScramb[6];
    scramb[14] = oldScramb[11];       scramb[11] = oldScramb[14];

    scramb[5] = oldScramb[12];      scramb[13] = oldScramb[4];
    scramb[12] = oldScramb[5];      scramb[4] = oldScramb[13];
}

void moveU2(string& scramb){
    string oldScramb = scramb;

    scramb[4] = oldScramb[8];        scramb[8] = oldScramb[4];
    scramb[5] = oldScramb[9];        scramb[9] = oldScramb[5];
    scramb[6] = oldScramb[10];       scramb[10] = oldScramb[6];
    scramb[7] = oldScramb[11];       scramb[11] = oldScramb[7];

    scramb[0] = oldScramb[2];      scramb[3] = oldScramb[1];
    scramb[2] = oldScramb[0];      scramb[1] = oldScramb[3];

}

void moveRprime(string& scramb){
    string oldScramb = scramb;

    scramb[12] = oldScramb[0];      scramb[4] = oldScramb[3];
    scramb[20] = oldScramb[12];     scramb[18] = oldScramb[4];
    scramb[9] = oldScramb[20];      scramb[15] = oldScramb[18];
    scramb[0] = oldScramb[9];       scramb[3] = oldScramb[15];

    scramb[17] = oldScramb[11];     scramb[16] = oldScramb[17];
    scramb[10] = oldScramb[16];     scramb[11] = oldScramb[10];
}

void moveFprime(string& scramb){
    string oldScramb = scramb;

    scramb[14] = oldScramb[1];       scramb[6] = oldScramb[0];
    scramb[18] = oldScramb[14];      scramb[19] = oldScramb[6];
    scramb[11] = oldScramb[18];      scramb[17] = oldScramb[19];
    scramb[1] = oldScramb[11];       scramb[0] = oldScramb[17];

    scramb[13] = oldScramb[5];      scramb[12] = oldScramb[13];
    scramb[4] = oldScramb[12];      scramb[5] = oldScramb[4];
}

void moveUprime(string& scramb){
    string oldScramb = scramb;

    scramb[10] = oldScramb[4];       scramb[11] = oldScramb[5];
    scramb[8] = oldScramb[10];       scramb[9] = oldScramb[11];
    scramb[6] = oldScramb[8];        scramb[7] = oldScramb[9];
    scramb[4] = oldScramb[6];        scramb[5] = oldScramb[7];

    scramb[3] = oldScramb[0];      scramb[2] = oldScramb[3];
    scramb[1] = oldScramb[2];      scramb[0] = oldScramb[1];
}

string shortestPath(vector<string> answers){

    string finalAns = answers[0];     int sz = 0;

    for(int i = 0; i < finalAns.size(); i++){
        if(finalAns[i] == 'R' || finalAns[i] == 'U' || finalAns[i] == 'F')sz++;
    }

    for(int i = 1; i < answers.size(); i++){
        string tmpAns = answers[i];

        for(int j = 0; j < tmpAns.size(); j++){

            int tmpSz = 0;

            if(tmpAns[j] == 'R' || tmpAns[j] == 'U' || tmpAns[j] == 'F')tmpSz++;
            if(sz < tmpSz){
                finalAns = answers[i];
            }
        }
    }
    return finalAns;
}

