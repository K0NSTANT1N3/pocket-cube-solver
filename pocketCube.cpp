#include<iostream>
#include<vector>
#include<set>
using namespace std;

const string solvedComb = "YYYYGGRRBBOOGGRBOOWWW";

void moveR(string& scramb);

void moveF(string& scramb);

void moveU(string& scramb);


bool solveCube(string& scramb, int depth, string& ans, string rep, set<string> stor);

int main(){
    cout << 1 << ' ';
    string ans = "";
    string scramb = "ROBYWYBYRGRGWGWGOOBOY";
    set <string> sor;

    solveCube(scramb, 0, ans, ans, sor);
    cout << " answer is " << ans;

}

bool solveCube(string& scramb, int depth, string& ans, string rep, set <string> sor){
    //base case
    if(scramb == solvedComb)return true;

    if(depth >= 14){
        return scramb == solvedComb? true: false;
    }

    int lastSz = sor.size();
    sor.insert(scramb);
    if(lastSz == sor.size())return false;
    
    // main case
    
    if(rep[0] != 'R' || rep.size() < 3){
        if(rep[0] != 'R') rep = "R";
        else if(rep[0] == 'R')rep.push_back('R');

        ans.push_back('R');
        moveR(scramb);

        if(solveCube(scramb, depth + 1, ans, rep, sor))return true;

        moveR(scramb); moveR(scramb); moveR(scramb);
        ans = ans.substr(0, ans.size() - 1);
    }

    if(rep[0] != 'U' || rep.size() < 3){
        if(rep[0] != 'U') rep = "U";
        else if(rep[0] == 'U')rep.push_back('U');

        ans.push_back('U');
        moveU(scramb);

        if(solveCube(scramb, depth + 1, ans, rep, sor))return true;

        moveU(scramb); moveU(scramb); moveU(scramb);
        ans = ans.substr(0, ans.size() - 1);
    }

    if(rep[0] != 'F' || rep.size() < 3){
        if(rep[0] != 'F') rep = "F";
        else if(rep[0] == 'F')rep.push_back('F');

        ans.push_back('F');
        moveF(scramb);

        if(solveCube(scramb, depth + 1, ans, rep, sor))return true;

        moveF(scramb); moveF(scramb); moveF(scramb);
        ans = ans.substr(0, ans.size() - 1);
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
