#include <iostream>
#include "io_utils.hpp"
#include <vector>
#include <string>
#include <boost/algorithm/string.hpp>
#include "treeutils/lisp.h"
#include "dependencyutils/TokenDictionary.h"
#include "dependencyutils/DependencyDictionary.h"
#include "dependencyutils/DependencyReader.h"
#include "dependencyutils/DependencyWriter.h"
#include <glog/logging.h>
#include <gflags/gflags.h>

using namespace std;


void dependency_prepare(){
    // Given the file path
    string file_name = "/home/lingpenk/Data/PTB/PTB_330/dev";
    // Create a Token Dictionary, which is necessary for the Dependency Dictionary
    TokenDictionary* token_dictionary = new TokenDictionary(file_name);
    // Create a Dependency Dictionary, and associate the Token Dictionary with it
    DependencyDictionary* dependency_dictionary = new DependencyDictionary(file_name);
    dependency_dictionary->SetTokenDictionary(token_dictionary);

    // Using a dependency reader to initialize the two dictionaries
    DependencyReader* reader = new DependencyReader;
    token_dictionary->InitializeFromDependencyReader(reader);
    dependency_dictionary->CreateLabelDictionary(reader);

    // Do whatever you like here, token dictionary and dependeny dictionary have been built
    cout << token_dictionary->GetNumForms() << endl;

    string outputf = "/dev/stdout";

    DependencyWriter* writer = new DependencyWriter;
    writer->Open(outputf);

    reader->Open(file_name);
    
    DependencyInstance* instance = static_cast<DependencyInstance*> (reader->GetNext());
    writer->Write(instance);


    reader->Close();
    writer->Close();
}

int main(int argc, char** argv)
{   
    // export LD_LIBRARY_PATH="$LD_LIBRARY_PATH:`pwd;`/usr/local/lib:"
    // if google libs are installed in local lib path
    google::InitGoogleLogging(argv[0]);
    google::ParseCommandLineFlags(&argc, &argv, true);
    google::LogToStderr();
    // LispTree lt;
    // string s = "(S (NP (NP (NNP Burmah)) (, ,) (SBAR (WHNP (WDT which)) (S (VP (VBZ owns) (NP (NP (DT the) (NNP Castrol) (NN brand)) (PP (IN of) (NP (JJ lubricant) (NNS oils))))))) (, ,)) (VP (VBD reported) (NP (NP (DT a) (ADJP (CD 17) (NN %)) (NN rise)) (PP (IN in) (NP (JJ net) (NN income))) (PP (TO to) (NP (NP (QP (# #) (CD 43.5) (CD million))) (PRN (-LRB- -LRB-) (NP (QP ($ $) (CD 68.3) (CD million))) (-RRB- -RRB-)))) (PP (IN in) (NP (DT the) (JJ first) (NN half))))) (. .))";
    // lt.read_from_string(s);
    // lt.print();

    // string file_name = "/home/lingpenk/Data/CTB/ctb_7/data/utf-8/segmented/chtb_0111.nw.seg";
    // vector<string> lines;
    // read_lines_into_vector(file_name, back_inserter(lines));
    // boost::trim(lines[8]);
    // cout << lines[8] << endl;
    // cout << lines[8].size() << endl;
    // cout << lines[8].size() << endl;
    // cout << (lines[8].substr(lines[8].size() -3, 3))<< endl;

    // string chinese = 
    // cout << chinese.size() << endl;
    // cout << chinese.substr(chinese.size()-3, 3) << endl;
    // string file_name = "/home/lingpenk/Data/PTB/penn_tb_3.0_preprocessed/dev.1.notraces";

    // vector<string> lines;
    // read_lines_into_vector(file_name, back_inserter(lines));

    // for(int i = 0; i < lines.size(); ++i){
    //     LispTree lt;
    //     boost::trim(lines[i]);
    //     if(lines[i].compare("")==0) continue;
    //     // cout << lines[i] << endl;
    //     lt.read_from_string(lines[i]);
    //     cout << lt.to_string() << endl;
    // }

    dependency_prepare();

}


void read_by_line(){
    string file_name = "/home/lingpenk/Data/PTB/PTB_330/dev";
    vector<string> lines;

    read_lines_into_vector(file_name, back_inserter(lines));

    for (unsigned int i = 0; i < lines.size(); i++){
        // cout << lines[i] << endl;
        boost::trim(lines[i]);
        if(lines[i].compare("") == 0){
            cout << endl;
            continue;
        }
        vector<string> strs;
        boost::split(strs, lines[i], boost::is_any_of("\t"));
        for (unsigned int j = 0; j < strs.size(); j++){
            cout << strs[j] << " ";
        }
        cout << endl;
    }
}
