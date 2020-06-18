#include <iostream>
#include <stdio.h>
using namespace std;
//Switch impide que se ejecuten todas las sentencias case
TString SelecEvent(int option,int &s_size,int &i,int size){
    TString aux; 
    switch(option){
        case 0: {
            TString sample[] ={"data","ZqqZll","WqqZll","WpqqWmlv","WplvWmqq","WlvZqq","llll","lllv","llvv","lvvv","Zee","Zmumu","Ztautau","single_top_tchan","single_antitop_tchan","single_top_schan","single_antitop_schan","single_top_wtchan","single_antitop_wtchan","ttbar_lep","Wplusenu","Wplusmunu","Wplustaunu","Wminusenu","Wminusmunu","Wminustaunu"};
                s_size = sizeof(sample)/sizeof(sample[0]);
                aux=sample[i];break;
                }
        case 1: { 
            TString sample[] = {"data"};
            s_size = sizeof(sample)/sizeof(sample[0]);
                aux=sample[i];break;
        }
        case 2: {
            TString sample[] = {"ZqqZll","WqqZll","WpqqWmlv","WplvWmqq","WlvZqq","llll","lllv","llvv","lvvv","Zee","Zmumu","Ztautau"};
            s_size = sizeof(sample)/sizeof(sample[0]);
            aux=sample[i];break;
        }
        case 3: {
            TString sample[] = {"single_top_tchan","single_antitop_tchan","single_top_schan","single_antitop_schan","single_top_wtchan","single_antitop_wtchan","ttbar_lep","Wplusenu","Wplusmunu","Wplustaunu","Wminusenu","Wminusmunu","Wminustaunu","ggH125_ZZ4lep","ZH125_ZZ4lep","WH125_ZZ4lep","VBF125_ZZ4lep"};
                s_size = sizeof(sample)/sizeof(sample[0]);
                aux=sample[i];break;
        }
    }
    return aux;
}
