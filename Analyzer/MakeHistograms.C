void MakeHistograms(){
  from ROOT.ROOT import RDataFrame
df = RDataFrame("ntuple", "inputForMVATraining_CHS.root")
h2 = df.Filter("dR2Mean")\
       .Histo1D(("dR2Mean", "dR2Mean;dR2Mean Graph;Number of Entries"), "dR2Mean")
h2.Draw()
}
