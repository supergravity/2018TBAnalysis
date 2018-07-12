#include "TH1.h"
#include "TH2.h"

void makeClass(){
  gROOT->Reset();
  gROOT->SetStyle("Plain");
  TApplication *a = new TApplication("a", 0, 0);
    TFile f("output_root/MC_100GeV_Ele.root");
    TTree *tt = (TTree *) f.Get("hits");
    TTree *tt2 = (TTree *) f.Get("impactPoints");
    TTree *tt3 = (TTree *) f.Get("rechit_var");
    
    tt->MakeClass("rechit");
    tt2->MakeClass("trackimpact");
    tt3->MakeClass("rechit_var");    
}
