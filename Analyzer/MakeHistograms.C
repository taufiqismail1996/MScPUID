void MakeHistograms(){
  //traditional method
  
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
                           
 
//using RDataFrama  
  from ROOT.ROOT import RDataFrame
df = RDataFrame("ntuple", "inputForMVATraining_CHS.root")
h2 = df.Filter("dR2Mean")\
       .Histo1D(("dR2Mean", "dR2Mean;dR2Mean Graph;Number of Entries"), "dR2Mean")
c.cd(2)
h2.Draw()
}
