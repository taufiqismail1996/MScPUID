void MakeHistograms(){
//traditional method
  TFile*f = new TFile("inputForMVATraining_CHS.root");
  TTree* t;
  f->GetObject("t",t);
  
  TCanvas* c1 = new TCanvas("c1","Histogram");
  t->Draw("dR2Mean");
  }


/*  
//traditional method #2
  
  TCanvas *c1 = new TCanvas();
  TFile *input = new TFile("inputForMVATraining_CHS.root,"read");
                           TTree *tree = (TTree*)input->Get("tree");
                           double dR2Mean;
                           tree->setBranchAddress("dR2Mean", &dR2Mean);
                         
                           int entries = tree->GetEntries();
                           TH1F *hist = new TH1F("hist", "Histogram");
                           
                           for(int i=0; i<entries; i++)
                           {
                             tree->GetEntry(i);
                             hist->Fill(x);
                           }
                           hist->Draw;
                           
//using RDataFrame
df = RDataFrame("ntuple", "inputForMVATraining_CHS.root")
h1 = df.Define("dR2Mean")\
       .Histo1D(("dR2Mean", "dR2Mean;dR2Mean Graph;Number of Entries"), "dR2Mean")
h1.Draw()
}
*/
