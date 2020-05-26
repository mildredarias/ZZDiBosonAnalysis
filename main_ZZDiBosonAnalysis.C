//////////////////////////////////////////////////////////////////////////////////////////
// Creates a TChain to be used by the Analysis.C class
#include "TROOT.h"
#include "TChain.h"
#include "TFile.h"
#include "TProof.h"
#include "TString.h"

void main_ZZDiBosonAnalysis(int proof, TString s)
{
  // path to your local directory *or* URL, please change the default one!
  /* Local path example */
  //TString path  = "/eos/project/a/atlas-outreach/projects/open-data/OpenDataTuples/renamedLargeRJets/4lep/";
  //TString path2 = "/eos/project/a/atlas-outreach/projects/open-data/OpenDataTuples/renamedLargeRJets/2lep/";
    TString path  = "4lep/";
    TString path2 = "/media/sf_VM/2lep/";
  /* The URL to the ATLAS Open Data website repository */
  //TString path  = "http://www.universidad.ch/ATLAS/outreach/open-data-2020/4lep/";
  //TString path2 = "http://www.universidad.ch/ATLAS/outreach/open-data-2020/2lep/";
 
  TChain *cont = new TChain("mini"); //se creo una TChain para guardar las carpetas donde estan contenido los archivos root, dependiendo de la opcion.
    
  if (proof == 1)  TProof::Open("");
  //option=1 || 0
  if (s.Contains("data")){
    TChain* chain_data = new TChain("mini");//Esta TChain guarda los archivos root que se agregaron en el chain_data
    chain_data->AddFile(path+"Data/data_A.4lep.root");
    chain_data->AddFile(path+"Data/data_B.4lep.root");
    chain_data->AddFile(path+"Data/data_C.4lep.root");
    chain_data->AddFile(path+"Data/data_D.4lep.root");
    if (proof == 1)  chain_data->SetProof();
    chain_data->Process("ZZDiBosonAnalysis.C+","data");
   
    cont=chain_data;//guarda los archivos root contenido en chain_data.
  }
    
  //y asi sucesivamente..... 
  
  //////////////////////  MC samples
  //option=2 || 0
  if (s.Contains("ZqqZll"))   {
    
    // diboson
    TChain* chain_ZqqZll = new TChain("mini");
    chain_ZqqZll->AddFile(path+"MC/mc_363356.ZqqZll.4lep.root");
    if (proof == 1)  chain_ZqqZll->SetProof();
    chain_ZqqZll->Process("ZZDiBosonAnalysis.C+","ZqqZll");
    
    cont=chain_ZqqZll;
  }
   
  if (s.Contains("WqqZll"))   {   
    TChain* chain_WqqZll = new TChain("mini");
    chain_WqqZll->AddFile(path2+"MC/mc_363358.WqqZll.2lep.root");
    if (proof == 1)  chain_WqqZll->SetProof();
    chain_WqqZll->Process("ZZDiBosonAnalysis.C+","WqqZll");
      
    cont=chain_WqqZll;
  }
    
  if (s.Contains("WpqqWmlv"))   { 
    TChain* chain_WpqqWmlv = new TChain("mini");
    chain_WpqqWmlv->AddFile(path2+"MC/mc_363359.WpqqWmlv.2lep.root");
    if (proof == 1)  chain_WpqqWmlv->SetProof();
    chain_WpqqWmlv->Process("ZZDiBosonAnalysis.C+","WpqqWmlv");
      
    cont=chain_WpqqWmlv;
  }
    
  if (s.Contains("WplvWmqq"))   { 
    TChain* chain_WplvWmqq = new TChain("mini");
    chain_WplvWmqq->AddFile(path2+"MC/mc_363360.WplvWmqq.2lep.root");
    if (proof == 1)  chain_WplvWmqq->SetProof();
    chain_WplvWmqq->Process("ZZDiBosonAnalysis.C+","WplvWmqq");
      
    cont=chain_WplvWmqq;
  }
    
   if (s.Contains("WlvZqq"))   {  
    TChain* chain_WlvZqq = new TChain("mini");
    chain_WlvZqq->AddFile(path2+"MC/mc_363489.WlvZqq.2lep.root");
    if (proof == 1)  chain_WlvZqq->SetProof();
    chain_WlvZqq->Process("ZZDiBosonAnalysis.C+","WlvZqq");
       
    cont=chain_WlvZqq;  
   }
    
   if (s.Contains("llll"))   {  
    TChain* chain_llll = new TChain("mini");
    chain_llll->AddFile(path+"MC/mc_363490.llll.4lep.root");
    if (proof == 1)  chain_llll->SetProof();
    chain_llll->Process("ZZDiBosonAnalysis.C+","llll");
       
    cont=chain_llll;  
   }
    
   if (s.Contains("lllv"))   {  
    TChain* chain_lllv = new TChain("mini");
    chain_lllv->AddFile(path+"MC/mc_363491.lllv.4lep.root");
    if (proof == 1)  chain_lllv->SetProof();
    chain_lllv->Process("ZZDiBosonAnalysis.C+","lllv");
    
    cont=chain_lllv;   
   }
    
   if (s.Contains("llvv"))   {  
    TChain* chain_llvv = new TChain("mini");
    chain_llvv->AddFile(path+"MC/mc_363492.llvv.4lep.root");
    if (proof == 1)  chain_llvv->SetProof();
    chain_llvv->Process("ZZDiBosonAnalysis.C+","llvv");
       
    cont=chain_llvv;   
   }
    
   if (s.Contains("lvvv"))   {  
    TChain* chain_lvvv = new TChain("mini");
    chain_lvvv->AddFile(path2+"MC/mc_363493.lvvv.2lep.root");
    if (proof == 1)  chain_lvvv->SetProof();
    chain_lvvv->Process("ZZDiBosonAnalysis.C+","lvvv");
       
    cont=chain_lvvv;   
   }
    
   if (s.Contains("Zee"))   { 
    // Z+jets inclusive
    TChain* chain_Zee = new TChain("mini");
    chain_Zee->AddFile(path+"MC/mc_361106.Zee.4lep.root");
    if (proof == 1)  chain_Zee->SetProof();
    chain_Zee->Process("ZZDiBosonAnalysis.C+","Zee");
       
    cont=chain_Zee;  
   }
    
   if (s.Contains("Zmumu"))   {  
    TChain* chain_Zmumu = new TChain("mini");
    chain_Zmumu->AddFile(path+"MC/mc_361107.Zmumu.4lep.root");
    if (proof == 1)  chain_Zmumu->SetProof();
    chain_Zmumu->Process("ZZDiBosonAnalysis.C+","Zmumu");
       
    cont=chain_Zmumu;   
   }
    
   if (s.Contains("Ztautau"))   {  
    TChain* chain_Ztautau = new TChain("mini");
    chain_Ztautau->AddFile(path+"MC/mc_361108.Ztautau.4lep.root");
    if (proof == 1)  chain_Ztautau->SetProof();
    chain_Ztautau->Process("ZZDiBosonAnalysis.C+","Ztautau");
       
    cont=chain_Ztautau;   
   }
  
    //option=3 || 0
    
   if (s.Contains("single_top_tchan")){
    //single top
    TChain* chain_single_top_tchan = new TChain("mini");
    chain_single_top_tchan->AddFile(path+"MC/mc_410011.single_top_tchan.4lep.root");
    if (proof == 1)  chain_single_top_tchan->SetProof();
    chain_single_top_tchan->Process("ZZDiBosonAnalysis.C+","single_top_tchan");
      
    cont=chain_single_top_tchan; 
  }
      
  if (s.Contains("single_antitop_tchan"))   {    
    TChain* chain_single_antitop_tchan = new TChain("mini");
    chain_single_antitop_tchan->AddFile(path+"MC/mc_410012.single_antitop_tchan.4lep.root");
    if (proof == 1)  chain_single_antitop_tchan->SetProof();
    chain_single_antitop_tchan->Process("ZZDiBosonAnalysis.C+","single_antitop_tchan");
      
    cont=chain_single_antitop_tchan;  
  }
      
  if (s.Contains("single_top_schan"))   {    
    TChain* chain_single_top_schan = new TChain("mini");
    chain_single_top_schan->AddFile(path+"MC/mc_410025.single_top_schan.4lep.root");
    if (proof == 1)  chain_single_top_schan->SetProof();
    chain_single_top_schan->Process("ZZDiBosonAnalysis.C+","single_top_schan");
      
    cont=chain_single_top_schan;  
  }
      
  if (s.Contains("single_antitop_schan"))   {     
    TChain* chain_single_antitop_schan = new TChain("mini");
    chain_single_antitop_schan->AddFile(path+"MC/mc_410026.single_antitop_schan.4lep.root");
    if (proof == 1)  chain_single_antitop_schan->SetProof();
    chain_single_antitop_schan->Process("ZZDiBosonAnalysis.C+","single_antitop_schan");
      
    cont=chain_single_antitop_schan;  
  }
      
  if (s.Contains("single_top_wtchan"))   {     
    TChain* chain_single_top_wtchan = new TChain("mini");
    chain_single_top_wtchan->AddFile(path+"MC/mc_410013.single_top_wtchan.4lep.root");
    if (proof == 1)  chain_single_top_wtchan->SetProof();
    chain_single_top_wtchan->Process("ZZDiBosonAnalysis.C+","single_top_wtchan");
      
    cont=chain_single_top_wtchan;  
  }
      
  if (s.Contains("single_antitop_wtchan"))   {     
    TChain* chain_single_antitop_wtchan = new TChain("mini");
    chain_single_antitop_wtchan->AddFile(path+"MC/mc_410014.single_antitop_wtchan.4lep.root");
    if (proof == 1)  chain_single_antitop_wtchan->SetProof();
    chain_single_antitop_wtchan->Process("ZZDiBosonAnalysis.C+","single_antitop_wtchan");
      
    cont=chain_single_antitop_wtchan;  
  }
      
  if (s.Contains("ttbar_lep"))   {     
    //ttbar
    TChain* chain_ttbar_lep = new TChain("mini");
    chain_ttbar_lep->AddFile(path+"MC/mc_410000.ttbar_lep.4lep.root");
    if (proof == 1)  chain_ttbar_lep->SetProof();
    chain_ttbar_lep->Process("ZZDiBosonAnalysis.C+","ttbar_lep");
      
    cont=chain_ttbar_lep;  
  }
      
  if (s.Contains("Wplusenu"))   {    
    // W+jets inclusive
    TChain* chain_Wplusenu = new TChain("mini");
    chain_Wplusenu->AddFile(path2+"MC/mc_361100.Wplusenu.2lep.root");
    if (proof == 1)  chain_Wplusenu->SetProof();
    chain_Wplusenu->Process("ZZDiBosonAnalysis.C+","Wplusenu");
      
    cont=chain_Wplusenu;  
  }
      
  if (s.Contains("Wplusmunu"))   {    
    TChain* chain_Wplusmunu = new TChain("mini");
    chain_Wplusmunu->AddFile(path2+"MC/mc_361101.Wplusmunu.2lep.root");
    if (proof == 1)  chain_Wplusmunu->SetProof();
    chain_Wplusmunu->Process("ZZDiBosonAnalysis.C+","Wplusmunu");
      
    cont=chain_Wplusmunu;  
  }
      
  if (s.Contains("Wplustaunu"))   {    
    TChain* chain_Wplustaunu = new TChain("mini");
    chain_Wplustaunu->AddFile(path2+"MC/mc_361102.Wplustaunu.2lep.root");
    if (proof == 1)  chain_Wplustaunu->SetProof();
    chain_Wplustaunu->Process("ZZDiBosonAnalysis.C+","Wplustaunu");
      
    cont=chain_Wplustaunu;  
  }
      
  if (s.Contains("Wminusenu"))   {    
    TChain* chain_Wminusenu = new TChain("mini");
    chain_Wminusenu->AddFile(path2+"MC/mc_361103.Wminusenu.2lep.root");
    if (proof == 1)  chain_Wminusenu->SetProof();
    chain_Wminusenu->Process("ZZDiBosonAnalysis.C+","Wminusenu");
      
    cont=chain_Wminusenu;  
  }
      
  if (s.Contains("Wminusmunu"))   {     
    TChain* chain_Wminusmunu = new TChain("mini");
    chain_Wminusmunu->AddFile(path2+"MC/mc_361104.Wminusmunu.2lep.root");
    if (proof == 1)  chain_Wminusmunu->SetProof();
    chain_Wminusmunu->Process("ZZDiBosonAnalysis.C+","Wminusmunu");
      
    cont=chain_Wminusmunu;  
  }
      
  if (s.Contains("Wminustaunu"))   {     
    TChain* chain_Wminustaunu = new TChain("mini");
    chain_Wminustaunu->AddFile(path2+"MC/mc_361105.Wminustaunu.2lep.root");
    if (proof == 1)  chain_Wminustaunu->SetProof();
    chain_Wminustaunu->Process("ZZDiBosonAnalysis.C+","Wminustaunu");
      
    cont=chain_Wminustaunu;  
  } 
  return cont;//retorna las carpetas donde esta contenido los archivos root, dependiendo de las opciones que tomo. 
}
