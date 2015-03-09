#include <iostream>
#include "io_utils.hpp"
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "lisp.h"

using namespace std;

int main()
{   
    // LispTree lt;
    // string s = "(S (NP (NP (NNP Burmah)) (, ,) (SBAR (WHNP (WDT which)) (S (VP (VBZ owns) (NP (NP (DT the) (NNP Castrol) (NN brand)) (PP (IN of) (NP (JJ lubricant) (NNS oils))))))) (, ,)) (VP (VBD reported) (NP (NP (DT a) (ADJP (CD 17) (NN %)) (NN rise)) (PP (IN in) (NP (JJ net) (NN income))) (PP (TO to) (NP (NP (QP (# #) (CD 43.5) (CD million))) (PRN (-LRB- -LRB-) (NP (QP ($ $) (CD 68.3) (CD million))) (-RRB- -RRB-)))) (PP (IN in) (NP (DT the) (JJ first) (NN half))))) (. .))";
    // lt.read_from_string(s);
    // lt.print();

    string file_name = "/home/lingpenk/Data/PTB/penn_tb_3.0_preprocessed/dev.1.notraces";

    vector<string> lines;
    read_lines_into_vector(file_name, back_inserter(lines));

    for(int i = 0; i < lines.size(); ++i){
        LispTree lt;
        boost::trim(lines[i]);
        if(lines[i].compare("")==0) continue;
        // cout << lines[i] << endl;
        lt.read_from_string(lines[i]);
        cout << lt.to_string() << endl;
    }
}

void read_by_line(){
    string file_name = "/home/lingpenk/Data/PTB/PTB_330/dev";
    vector<string> lines;

    read_lines_into_vector(file_name, back_inserter(lines));

    for (int i = 0; i < lines.size(); i++){
        // cout << lines[i] << endl;
        boost::trim(lines[i]);
        if(lines[i].compare("") == 0){
            cout << endl;
            continue;
        }
        vector<string> strs;
        boost::split(strs, lines[i], boost::is_any_of("\t"));
        for (int j = 0; j < strs.size(); j++){
            cout << strs[j] << " ";
        }
        cout << endl;
    }
}