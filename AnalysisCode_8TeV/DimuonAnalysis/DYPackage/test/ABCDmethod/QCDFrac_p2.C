void QCDFrac_p2(const char* ISO, const char* REGION) {

  // directory with data
  TString protocol = "file://";
  TString dirname = "/scratch/scratch95/a/asvyatko/DY2013/rootfiles/";

//   DY
  TFileCollection* c2a = new TFileCollection("DYM1020","DYM1020");
  c2a->Add(protocol+dirname+"DYM1020_PU"+"/*.root");

  TFileCollection* c2b = new TFileCollection("DYM20","DYM20");
  c2b->Add(protocol+dirname+"DYM20_PU"+"/*.root");

  TFileCollection* c2c = new TFileCollection("DYM200","DYM200");
  c2c->Add(protocol+dirname+"DYM200_PU"+"/*.root");

  TFileCollection* c2d = new TFileCollection("DYM400","DYM400");
  c2d->Add(protocol+dirname+"DYM400_PU"+"/*.root");

  TFileCollection* c2e = new TFileCollection("DYM500","DYM500");
  c2e->Add(protocol+dirname+"DYM500_PU"+"/*.root");

  TFileCollection* c2f = new TFileCollection("DYM700","DYM700");
  c2f->Add(protocol+dirname+"DYM700_PU"+"/*.root");

  TFileCollection* c2g = new TFileCollection("DYM800","DYM800");
  c2g->Add(protocol+dirname+"DYM800_PU"+"/*.root");

  TFileCollection* c2h = new TFileCollection("DYM1000","DYM1000");
  c2h->Add(protocol+dirname+"DYM1000_PU"+"/*.root");

//DYtau
  TFileCollection* c5a = new TFileCollection("DYtautau1020","DYtautau1020");
  c5a->Add(protocol+dirname+"DYtautau1020_PU"+"/*.root");

  TFileCollection* c5b = new TFileCollection("DYtautau20","DYtautau20");
  c5b->Add(protocol+dirname+"DYtautau20_PU"+"/*.root");

  gEnv->SetValue("ProofLite.Sandbox", "/home/asvyatko/DYStudy/CMSSW_5_3_3_patch2/src/DimuonAnalysis/DYPackage/test/ABCDmethod/proofbox_p2/");
  TProof* p = TProof::Open("workers=20");
  p->RegisterDataSet("DYM1020", c2a,"OV");
  p->RegisterDataSet("DYM20", c2b,"OV");
  p->RegisterDataSet("DYM200", c2c,"OV");
  p->RegisterDataSet("DYM400", c2d,"OV");
  p->RegisterDataSet("DYM500", c2e,"OV");
  p->RegisterDataSet("DYM700", c2f,"OV");
  p->RegisterDataSet("DYM800", c2g,"OV");
  p->RegisterDataSet("DYM1000", c2h,"OV");
  p->RegisterDataSet("DYtautau1020", c5a,"OV");
  p->RegisterDataSet("DYtautau20", c5b,"OV");

  p->ShowDataSets();

  TObjString* useNtupleWeightFlag = new TObjString("False");
  p->AddInput(new TNamed("useNtupleWeightFlag","False"));
  TObjString* iso = new TObjString(ISO);
  p->AddInput(new TNamed("iso",ISO));
  TObjString* region = new TObjString(REGION);
  p->AddInput(new TNamed("region",REGION));

  gROOT->Time();
  p->SetParameter("PROOF_LookupOpt", "all");
  p->Process("DYM1020#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM20#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM200#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM400#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM500#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM700#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM800#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYM1000#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYtautau1020#/recoTree/DiMuonTree","EventSelector_Bkg.C+");
  p->Process("DYtautau20#/recoTree/DiMuonTree","EventSelector_Bkg.C+");

}
