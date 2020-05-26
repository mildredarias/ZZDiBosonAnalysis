//////////////////////////////////////////////////////////
#ifndef ZZDiBosonAnalysis_h
#define ZZDiBosonAnalysis_h
//ENCABEZADOS NECESARIOS PARA ESTE SELECTOR PARTICULAR

/*El objeto TROOT es el punto de entrada al sistema ROOT.Se puede acceder a la instancia única de TROOT a través del gROOT global.
Usando el puntero gROOT uno tiene acceso a básicamente cada objeto creado en un programa basado en ROOT. El objeto TROOT es esencialmente un "despachador" con varias listas que apuntan a los objetos principales ROOT.*/
#include "TROOT.h"

//Una cadena es una colección de archivos que contienen objetos TTree. Un TChain es una colección de objetos TFile. El primer parámetro "nombre" es el nombre del objeto TTree en los archivos agregados
#include "TChain.h"

//Abre o crea un archivo ROOT local. Un archivo ROOT es un conjunto de registros de datos consecutivos con un formato bien definido.
#include "TFile.h"

// Una clase de utilidad para las selecciones de árboles.
#include "TSelector.h"

//Clases de Histogramas 
#include "TH1.h"

// Headers needed by this particular selector
#include "vector"

class ZZDiBosonAnalysis : public TSelector {
  public :
  TTree          *fChain;   //!pointer to the analyzed TTree or TChain

  //////////////////////////////////////////////////////////
  // histograms

  // Global variables histograms(Variables globales histogramas)
  //Es un puntero que me va a guardar la direccion de memoria de una variable hist_vxp_z.Variable de tipo puntero: me guarda o direcciona a la variable hist_vxp_z (guarda la direccion de memoria)
  TH1F *hist_vxp_z        = 0;
  TH1F *hist_pvxp_n       = 0;
  TH1F *hist_mLL1         = 0;
  TH1F *hist_mLL2         = 0;

  TH1F *hist_fourlepsys_pt = 0;
  TH1F *hist_fourlepsys_y  = 0;
  TH1F *hist_fourlepsys_m  = 0;


  // Leading Lepton histograms (Principales histogramas de Lepton)
  TH1F *hist_fourleptpt   = 0;
  TH1F *hist_fourlepteta  = 0;
  TH1F *hist_fourleptE    = 0;
  TH1F *hist_fourleptphi  = 0;
  TH1F *hist_fourleptch   = 0;
  TH1F *hist_fourleptID   = 0;
  TH1F *hist_fourlept_ptc = 0;
  TH1F *hist_fourleptetc  = 0;
  TH1F *hist_fourlepz0    = 0;
  TH1F *hist_fourlepd0    = 0;


  ////DECLARACION DE TIPOS(Definiendo las Variables)
  // Declaration of leaf types
   Int_t           runNumber;//
   Int_t           eventNumber;//
   Int_t           channelNumber;//
   Float_t         mcWeight;
   Float_t         scaleFactor_PILEUP;
   Float_t         scaleFactor_ELE;
   Float_t         scaleFactor_MUON;
   Float_t         scaleFactor_PHOTON;//
   Float_t         scaleFactor_TAU;//
   Float_t         scaleFactor_BTAG;//
   Float_t         scaleFactor_LepTRIGGER;
   Float_t         scaleFactor_PhotonTRIGGER;//
   Float_t         scaleFactor_TauTRIGGER;//
   Float_t         scaleFactor_DiTauTRIGGER;//
   Bool_t          trigE;
   Bool_t          trigM;
   Bool_t          trigP;//
   Bool_t          trigT;//
   Bool_t          trigDT;//
   UInt_t          lep_n;  
   vector<bool>    *lep_truthMatched;// //Esta es una versión especializada de vector , que se utiliza para elementos de tipo bool y optimiza el espacio.
   vector<bool>    *lep_trigMatched;//
   vector<float>   *lep_pt;
   vector<float>   *lep_eta;
   vector<float>   *lep_phi;
   vector<float>   *lep_E;
   vector<float>   *lep_z0;
   vector<int>     *lep_charge;
   vector<unsigned int> *lep_type;
   vector<bool>    *lep_isTightID;
   vector<float>   *lep_ptcone30;
   vector<float>   *lep_etcone20;
   vector<float>   *lep_trackd0pvunbiased;
   vector<float>   *lep_tracksigd0pvunbiased;
   Float_t         met_et;//
   Float_t         met_phi;//
   UInt_t          jet_n;//
   vector<float>   *jet_pt;//
   vector<float>   *jet_eta;//
   vector<float>   *jet_phi;//
   vector<float>   *jet_E;//
   vector<float>   *jet_jvt;//
   vector<int>     *jet_trueflav;//
   vector<bool>    *jet_truthMatched;//
   vector<float>   *jet_MV2c10;//
   UInt_t          photon_n;//
   vector<bool>    *photon_truthMatched;//
   vector<bool>    *photon_trigMatched;//
   vector<float>   *photon_pt;//
   vector<float>   *photon_eta;//
   vector<float>   *photon_phi;//
   vector<float>   *photon_E;//
   vector<bool>    *photon_isTightID;//
   vector<float>   *photon_ptcone30;//
   vector<float>   *photon_etcone20;//
   UInt_t          largeRjet_n;//
   vector<float>   *largeRjet_pt;//
   vector<float>   *largeRjet_eta;//
   vector<float>   *largeRjet_phi;//
   vector<float>   *largeRjet_E;//
   vector<float>   *largeRjet_m;//
   vector<int>     *largeRjet_truthMatched;//
   vector<float>   *largeRjet_D2;//
   vector<float>   *largeRjet_tau32;//
   UInt_t          tau_n;//
   vector<float>   *tau_pt;//
   vector<float>   *tau_eta;//
   vector<float>   *tau_phi;//
   vector<float>   *tau_E;//
   vector<bool>    *tau_isTightID;//
   vector<bool>    *tau_truthMatched;//
   vector<bool>    *tau_trigMatched;//
   vector<int>     *tau_nTracks;//
   vector<float>   *tau_BDTid;//
   Float_t         ditau_m;//
   vector<float>   *truth_pt;//
   vector<float>   *truth_eta;//
   vector<float>   *truth_phi;//
   vector<float>   *truth_E;//
   vector<int>     *truth_pdgid;//
   vector<float>   *lep_pt_syst;//
   Float_t         met_et_syst;//
   vector<float>   *jet_pt_syst;//
   vector<float>   *photon_pt_syst;//
   vector<float>   *largeRjet_pt_syst;//
   vector<float>   *tau_pt_syst;//


  // List of branches

   TBranch        *b_runNumber;   //!
   TBranch        *b_eventNumber;   //!
   TBranch        *b_channelNumber;   //!
   TBranch        *b_mcWeight;   //!
   TBranch        *b_scaleFactor_PILEUP;   //!
   TBranch        *b_scaleFactor_ELE;   //!
   TBranch        *b_scaleFactor_MUON;   //!
   TBranch        *b_scaleFactor_PHOTON;   //!
   TBranch        *b_scaleFactor_TAU;   //!
   TBranch        *b_scaleFactor_BTAG;   //!
   TBranch        *b_scaleFactor_LepTRIGGER;   //!
   TBranch        *b_scaleFactor_PhotonTRIGGER;   //!
   TBranch        *b_scaleFactor_TauTRIGGER;   //!
   TBranch        *b_scaleFactor_DiTauTRIGGER;   //!
   TBranch        *b_trigE;   //!
   TBranch        *b_trigM;   //!
   TBranch        *b_trigP;   //!
   TBranch        *b_trigT;   //!
   TBranch        *b_trigDT;   //!
   TBranch        *b_lep_n;   //!
   TBranch        *b_lep_truthMatched;   //!
   TBranch        *b_lep_trigMatched;   //!
   TBranch        *b_lep_pt;   //!
   TBranch        *b_lep_eta;   //!
   TBranch        *b_lep_phi;   //!
   TBranch        *b_lep_E;   //!
   TBranch        *b_lep_z0;   //!
   TBranch        *b_lep_charge;   //!
   TBranch        *b_lep_type;   //!
   TBranch        *b_lep_isTightID;   //!
   TBranch        *b_lep_ptcone30;   //!
   TBranch        *b_lep_etcone20;   //!
   TBranch        *b_lep_trackd0pvunbiased;   //!
   TBranch        *b_lep_tracksigd0pvunbiased;   //!
   TBranch        *b_met_et;   //!
   TBranch        *b_met_phi;   //!
   TBranch        *b_jet_n;   //!
   TBranch        *b_jet_pt;   //!
   TBranch        *b_jet_eta;   //!
   TBranch        *b_jet_phi;   //!
   TBranch        *b_jet_E;   //!
   TBranch        *b_jet_jvt;   //!
   TBranch        *b_jet_trueflav;   //!
   TBranch        *b_jet_truthMatched;   //!
   TBranch        *b_jet_MV2c10;   //!
   TBranch        *b_photon_n;   //!
   TBranch        *b_photon_truthMatched;   //!
   TBranch        *b_photon_trigMatched;   //!
   TBranch        *b_photon_pt;   //!
   TBranch        *b_photon_eta;   //!
   TBranch        *b_photon_phi;   //!
   TBranch        *b_photon_E;   //!
   TBranch        *b_photon_isTightID;   //!
   TBranch        *b_photon_ptcone30;   //!
   TBranch        *b_photon_etcone20;   //!
   TBranch        *b_largeRjet_n;   //!
   TBranch        *b_largeRjet_pt;   //!
   TBranch        *b_largeRjet_eta;   //!
   TBranch        *b_largeRjet_phi;   //!
   TBranch        *b_largeRjet_E;   //!
   TBranch        *b_largeRjet_m;   //!
   TBranch        *b_largeRjet_truthMatched;   //!
   TBranch        *b_largeRjet_D2;   //!
   TBranch        *b_largeRjet_tau32;   //!
   TBranch        *b_tau_n;   //!
   TBranch        *b_tau_pt;   //!
   TBranch        *b_tau_eta;   //!
   TBranch        *b_tau_phi;   //!
   TBranch        *b_tau_E;   //!
   TBranch        *b_tau_isTightID;   //!
   TBranch        *b_tau_truthMatched;   //!
   TBranch        *b_tau_trigMatched;   //!
   TBranch        *b_tau_nTracks;   //!
   TBranch        *b_tau_BDTid;   //!
   TBranch        *b_ditau_m;   //!
   TBranch        *b_truth_pt;   //!
   TBranch        *b_truth_eta;   //!
   TBranch        *b_truth_phi;   //!
   TBranch        *b_truth_E;   //!
   TBranch        *b_truth_pdgid;   //!
   TBranch        *b_lep_pt_syst;   //!
   TBranch        *b_met_et_syst;   //!
   TBranch        *b_jet_pt_syst;   //!
   TBranch        *b_photon_pt_syst;   //!
   TBranch        *b_largeRjet_pt_syst;   //!
   TBranch        *b_tau_pt_syst;   //!


  ZZDiBosonAnalysis(TTree * =0) : fChain(0) { }
  virtual ~ZZDiBosonAnalysis() { }
  virtual Int_t   Version() const { return 2; }
  virtual void    Begin(TTree *tree);
  virtual void    SlaveBegin(TTree *tree);
  virtual void    Init(TTree *tree);
  virtual Bool_t  Notify();

  virtual Bool_t  Process(Long64_t entry);
  virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
  virtual void    SetOption(const char *option) { fOption = option; }
  virtual void    SetObject(TObject *obj) { fObject = obj; }
  virtual void    SetInputList(TList *input) { fInput = input; }
  virtual void    FillHistogramsGlobal( double m, float w , TString s);
  virtual void    FillHistogramsLeadlept( double m, float w , TString s);

  // Get Output List t osave our histograms in the output file
 //(Obtener lista de salida para guardar nuestros histogramas en el archivo de salida)
  virtual TList  *GetOutputList() const { return fOutput; }
  //
  virtual void    define_histograms();
  //
  virtual void    FillOutputList();
  //
  virtual void    WriteHistograms();

  virtual void    SlaveTerminate();
  virtual void    Terminate();


  int nEvents;


  ClassDef(ZZDiBosonAnalysis,0);
};

#endif

#ifdef ZZDiBosonAnalysis_cxx
void ZZDiBosonAnalysis::Init(TTree *tree)
{
  

   lep_truthMatched = 0;
   lep_trigMatched = 0;
   lep_pt = 0;
   lep_eta = 0;
   lep_phi = 0;
   lep_E = 0;
   lep_z0 = 0;
   lep_charge = 0;
   lep_type = 0;
   lep_isTightID = 0;
   lep_ptcone30 = 0;
   lep_etcone20 = 0;
   lep_trackd0pvunbiased = 0;
   lep_tracksigd0pvunbiased = 0;
   jet_pt = 0;
   jet_eta = 0;
   jet_phi = 0;
   jet_E = 0;
   jet_jvt = 0;
   jet_trueflav = 0;
   jet_truthMatched = 0;
   jet_MV2c10 = 0;
   photon_truthMatched = 0;
   photon_trigMatched = 0;
   photon_pt = 0;
   photon_eta = 0;
   photon_phi = 0;
   photon_E = 0;
   photon_isTightID = 0;
   photon_ptcone30 = 0;
   photon_etcone20 = 0;
   largeRjet_pt = 0;
   largeRjet_eta = 0;
   largeRjet_phi = 0;
   largeRjet_E = 0;
   largeRjet_m = 0;
   largeRjet_truthMatched = 0;
   largeRjet_D2 = 0;
   largeRjet_tau32 = 0;
   tau_pt = 0;
   tau_eta = 0;
   tau_phi = 0;
   tau_E = 0;
   tau_isTightID = 0;
   tau_truthMatched = 0;
   tau_trigMatched = 0;
   tau_nTracks = 0;
   tau_BDTid = 0;
   truth_pt = 0;
   truth_eta = 0;
   truth_phi = 0;
   truth_E = 0;
   truth_pdgid = 0;
   lep_pt_syst = 0;
   jet_pt_syst = 0;
   photon_pt_syst = 0;
   largeRjet_pt_syst = 0;
   tau_pt_syst = 0;

   
  // Set branch addresses and branch pointers
  if (!tree) return;
  fChain = tree;
  fChain->SetMakeClass(1);

   fChain->SetBranchAddress("runNumber", &runNumber, &b_runNumber);
   fChain->SetBranchAddress("eventNumber", &eventNumber, &b_eventNumber);
   fChain->SetBranchAddress("channelNumber", &channelNumber, &b_channelNumber);
   fChain->SetBranchAddress("mcWeight", &mcWeight, &b_mcWeight);
   fChain->SetBranchAddress("scaleFactor_PILEUP", &scaleFactor_PILEUP, &b_scaleFactor_PILEUP);
   fChain->SetBranchAddress("scaleFactor_ELE", &scaleFactor_ELE, &b_scaleFactor_ELE);
   fChain->SetBranchAddress("scaleFactor_MUON", &scaleFactor_MUON, &b_scaleFactor_MUON);
   fChain->SetBranchAddress("scaleFactor_PHOTON", &scaleFactor_PHOTON, &b_scaleFactor_PHOTON);
   fChain->SetBranchAddress("scaleFactor_TAU", &scaleFactor_TAU, &b_scaleFactor_TAU);
   fChain->SetBranchAddress("scaleFactor_BTAG", &scaleFactor_BTAG, &b_scaleFactor_BTAG);
   fChain->SetBranchAddress("scaleFactor_LepTRIGGER", &scaleFactor_LepTRIGGER, &b_scaleFactor_LepTRIGGER);
   fChain->SetBranchAddress("scaleFactor_PhotonTRIGGER", &scaleFactor_PhotonTRIGGER, &b_scaleFactor_PhotonTRIGGER);
   fChain->SetBranchAddress("scaleFactor_TauTRIGGER", &scaleFactor_TauTRIGGER, &b_scaleFactor_TauTRIGGER);
   fChain->SetBranchAddress("scaleFactor_DiTauTRIGGER", &scaleFactor_DiTauTRIGGER, &b_scaleFactor_DiTauTRIGGER);
   fChain->SetBranchAddress("trigE", &trigE, &b_trigE);
   fChain->SetBranchAddress("trigM", &trigM, &b_trigM);
   fChain->SetBranchAddress("trigP", &trigP, &b_trigP);
   fChain->SetBranchAddress("trigT", &trigT, &b_trigT);
   fChain->SetBranchAddress("trigDT", &trigDT, &b_trigDT);
   fChain->SetBranchAddress("lep_n", &lep_n, &b_lep_n);
   fChain->SetBranchAddress("lep_truthMatched", &lep_truthMatched, &b_lep_truthMatched);
   fChain->SetBranchAddress("lep_trigMatched", &lep_trigMatched, &b_lep_trigMatched);
   fChain->SetBranchAddress("lep_pt", &lep_pt, &b_lep_pt);
   fChain->SetBranchAddress("lep_eta", &lep_eta, &b_lep_eta);
   fChain->SetBranchAddress("lep_phi", &lep_phi, &b_lep_phi);
   fChain->SetBranchAddress("lep_E", &lep_E, &b_lep_E);
   fChain->SetBranchAddress("lep_z0", &lep_z0, &b_lep_z0);
   fChain->SetBranchAddress("lep_charge", &lep_charge, &b_lep_charge);
   fChain->SetBranchAddress("lep_type", &lep_type, &b_lep_type);
   fChain->SetBranchAddress("lep_isTightID", &lep_isTightID, &b_lep_isTightID);
   fChain->SetBranchAddress("lep_ptcone30", &lep_ptcone30, &b_lep_ptcone30);
   fChain->SetBranchAddress("lep_etcone20", &lep_etcone20, &b_lep_etcone20);
   fChain->SetBranchAddress("lep_trackd0pvunbiased", &lep_trackd0pvunbiased, &b_lep_trackd0pvunbiased);
   fChain->SetBranchAddress("lep_tracksigd0pvunbiased", &lep_tracksigd0pvunbiased, &b_lep_tracksigd0pvunbiased);
   fChain->SetBranchAddress("met_et", &met_et, &b_met_et);
   fChain->SetBranchAddress("met_phi", &met_phi, &b_met_phi);
   fChain->SetBranchAddress("jet_n", &jet_n, &b_jet_n);
   fChain->SetBranchAddress("jet_pt", &jet_pt, &b_jet_pt);
   fChain->SetBranchAddress("jet_eta", &jet_eta, &b_jet_eta);
   fChain->SetBranchAddress("jet_phi", &jet_phi, &b_jet_phi);
   fChain->SetBranchAddress("jet_E", &jet_E, &b_jet_E);
   fChain->SetBranchAddress("jet_jvt", &jet_jvt, &b_jet_jvt);
   fChain->SetBranchAddress("jet_trueflav", &jet_trueflav, &b_jet_trueflav);
   fChain->SetBranchAddress("jet_truthMatched", &jet_truthMatched, &b_jet_truthMatched);
   fChain->SetBranchAddress("jet_MV2c10", &jet_MV2c10, &b_jet_MV2c10);
   fChain->SetBranchAddress("photon_n", &photon_n, &b_photon_n);
   fChain->SetBranchAddress("photon_truthMatched", &photon_truthMatched, &b_photon_truthMatched);
   fChain->SetBranchAddress("photon_trigMatched", &photon_trigMatched, &b_photon_trigMatched);
   fChain->SetBranchAddress("photon_pt", &photon_pt, &b_photon_pt);
   fChain->SetBranchAddress("photon_eta", &photon_eta, &b_photon_eta);
   fChain->SetBranchAddress("photon_phi", &photon_phi, &b_photon_phi);
   fChain->SetBranchAddress("photon_E", &photon_E, &b_photon_E);
   fChain->SetBranchAddress("photon_isTightID", &photon_isTightID, &b_photon_isTightID);
   fChain->SetBranchAddress("photon_ptcone30", &photon_ptcone30, &b_photon_ptcone30);
   fChain->SetBranchAddress("photon_etcone20", &photon_etcone20, &b_photon_etcone20);
   fChain->SetBranchAddress("largeRjet_n", &largeRjet_n, &b_largeRjet_n);
   fChain->SetBranchAddress("largeRjet_pt", &largeRjet_pt, &b_largeRjet_pt);
   fChain->SetBranchAddress("largeRjet_eta", &largeRjet_eta, &b_largeRjet_eta);
   fChain->SetBranchAddress("largeRjet_phi", &largeRjet_phi, &b_largeRjet_phi);
   fChain->SetBranchAddress("largeRjet_E", &largeRjet_E, &b_largeRjet_E);
   fChain->SetBranchAddress("largeRjet_m", &largeRjet_m, &b_largeRjet_m);
   fChain->SetBranchAddress("largeRjet_truthMatched", &largeRjet_truthMatched, &b_largeRjet_truthMatched);
   fChain->SetBranchAddress("largeRjet_D2", &largeRjet_D2, &b_largeRjet_D2);
   fChain->SetBranchAddress("largeRjet_tau32", &largeRjet_tau32, &b_largeRjet_tau32);
   fChain->SetBranchAddress("tau_n", &tau_n, &b_tau_n);
   fChain->SetBranchAddress("tau_pt", &tau_pt, &b_tau_pt);
   fChain->SetBranchAddress("tau_eta", &tau_eta, &b_tau_eta);
   fChain->SetBranchAddress("tau_phi", &tau_phi, &b_tau_phi);
   fChain->SetBranchAddress("tau_E", &tau_E, &b_tau_E);
   fChain->SetBranchAddress("tau_isTightID", &tau_isTightID, &b_tau_isTightID);
   fChain->SetBranchAddress("tau_truthMatched", &tau_truthMatched, &b_tau_truthMatched);
   fChain->SetBranchAddress("tau_trigMatched", &tau_trigMatched, &b_tau_trigMatched);
   fChain->SetBranchAddress("tau_nTracks", &tau_nTracks, &b_tau_nTracks);
   fChain->SetBranchAddress("tau_BDTid", &tau_BDTid, &b_tau_BDTid);
   fChain->SetBranchAddress("ditau_m", &ditau_m, &b_ditau_m);
   fChain->SetBranchAddress("truth_pt", &truth_pt, &b_truth_pt);
   fChain->SetBranchAddress("truth_eta", &truth_eta, &b_truth_eta);
   fChain->SetBranchAddress("truth_phi", &truth_phi, &b_truth_phi);
   fChain->SetBranchAddress("truth_E", &truth_E, &b_truth_E);
   fChain->SetBranchAddress("truth_pdgid", &truth_pdgid, &b_truth_pdgid);
   fChain->SetBranchAddress("lep_pt_syst", &lep_pt_syst, &b_lep_pt_syst);
   fChain->SetBranchAddress("met_et_syst", &met_et_syst, &b_met_et_syst);
   fChain->SetBranchAddress("jet_pt_syst", &jet_pt_syst, &b_jet_pt_syst);
   fChain->SetBranchAddress("photon_pt_syst", &photon_pt_syst, &b_photon_pt_syst);
   fChain->SetBranchAddress("largeRjet_pt_syst", &largeRjet_pt_syst, &b_largeRjet_pt_syst);
   fChain->SetBranchAddress("tau_pt_syst", &tau_pt_syst, &b_tau_pt_syst);

}

Bool_t ZZDiBosonAnalysis::Notify()
{
  // The Notify() function is called when a new file is opened. This
  // can be either for a new TTree in a TChain or when when a new TTree
  // is started when using PROOF. It is normally not necessary to make changes
  // to the generated code, but the routine can be extended by the
  // user if needed. The return value is currently not used.
  
    // (La función Notify () se llama cuando se abre un nuevo archivo. Esta
  // puede ser para un nuevo TTree en un TChain o cuando un nuevo TTree
  // se inicia cuando se utiliza PROOF. Normalmente no es necesario hacer cambios
  // al código generado, pero la rutina puede ser extendida por el
  // usuario si es necesario. El valor de retorno no se utiliza actualmente.)

  return kTRUE;
}

#endif // #ifdef ZZDiBosonAnalysis_cxx
