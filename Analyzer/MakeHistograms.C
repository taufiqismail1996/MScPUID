void MakeHistograms(){
  //traditional method
  
  /*
  TFile*f = new TFile("inputForMVATraining_CHS.root");
  TTree* t;
  f->GetObject("t",t);
  
  TCanvas* c1 = new TCanvas("c1","Histogram");
  c1->Divide(1,3);
  
  c1->cd(1); t->Draw("dR2Mean");
  c1->cd(2); t->Draw("majW");
  c1->cd(3); t->Draw("minW");
  
  
  
  //traditional method #2
  /*
  TCanvas *c1 = new TCanvas();
  TFile *input = new TFile("inputForMVATraining_CHS.root,"read");
                           TTree *tree = (TTree*)input->Get("tree");
                           double dR2Mean, majW, min W;
                           tree->setBranchAddress("dR2Mean", &dR2Mean);
                           tree->setBranchAddress("majW",&majW);
                           tree->setBranchAddress("minW",&minW);
                           
                           int entries = tree->GetEntries();
                           TH1F *hist = new TH1F("hist", "Histogram");
                           
                           for(int i=0; i<entries; i++)
                           {
                             tree->GetEntry(i);
                             hist->Fill(x);
                           }
                           hist->Draw;
                           
 */
 
//using RDataFrame
df = RDataFrame("ntuple", "inputForMVATraining_CHS.root")
h2 = df.Filter("dR2Mean")\
       .Histo1D(("dR2Mean", "dR2Mean;dR2Mean Graph;Number of Entries"), "dR2Mean")
h2.Draw()
}
