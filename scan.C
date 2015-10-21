#pragma GCC diagnostic ignored "-Wsign-compare"
#include "../software/dataMCplotMaker/dataMCplotMaker.h"

//Regular includes
#include "TFile.h"
#include "TTree.h"
#include "TCut.h"
#include "TColor.h"
#include "TCanvas.h"
#include "TH2F.h"
#include "TH1.h"
#include "TChain.h"

//Class files
#include "../classFiles/v4.00/SS.h"

#include "utils.C"
#include "../CORE/SSSelections.h"
#include "../CORE/Tools/dorky/dorky.cc"

using namespace std;
using namespace duplicate_removal;

int scan(){
    TChain *ch = new TChain("t");
    std::vector<std::string> titles;

    TString tag = "v4.01";
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"/TTBAR.root");  titles.push_back("tt");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"/DY*.root");    titles.push_back("DY");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"/TTZ*.root");    titles.push_back("ttZ");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"/WJets*.root"); titles.push_back("WJets");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"/ZZ.root");     titles.push_back("ZZ");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"/WZ3LNU.root");     titles.push_back("WZ");

    ch->Add("/nfs-7/userdata/ss2015/ssBabies/"+tag+"-data848p7ipb/Data*.root");


    int nEventsTotal = 0;
    int nEventsChain = ch->GetEntries();
    int nGoodEvents = 0;
    int nGoodEventsData = 0;
    float nGoodEventsWeighted = 0;
    float luminosity = 0.8487-0.016;

    TFile *currentFile = 0;
    TObjArray *listOfFiles = ch->GetListOfFiles();
    TIter fileIter(listOfFiles);

    vector<TH1F*> h1D_njets_vec;
    vector<TH1F*> h1D_ht_vec;
    vector<TH1F*> h1D_met_vec;
    vector<TH1F*> h1D_mt_vec;
    vector<TH1F*> h1D_zmass_vec;
    vector<TH1F*> h1D_hyp_class_vec;
    vector<TH1F*> h1D_nbtags_vec;
    vector<TH1F*> h1D_mtmin_vec;

    vector<TH1F*> h1D_lep1pt_vec;
    vector<TH1F*> h1D_lep2pt_vec;

    vector<TH1F*> h1D_yields_HH_vec;
    vector<TH1F*> h1D_yields_HL_vec;
    vector<TH1F*> h1D_yields_LL_vec;

    TH2F* h2D_met_mtmin_wz = new TH2F("met_mtmin", "", 20, 0, 300, 20, 0, 300); 
    TH2F* h2D_njets_nbtags_wz = new TH2F("njets_nbtags", "", 7,0,7, 7,0,7);
    TH2F* h2D_ptlep1_ptlep2_wz = new TH2F("ptlep1_ptlep2", "", 40,0,400, 40,0,400);
    TH2F* h2D_ht_njets_wz = new TH2F("ht_njets_wz", "", 20,0,1000, 7,0,7);
    TH2F* h2D_ht_sumleppt_wz = new TH2F("ht_sumleppt_wz", "", 20,0,1000, 40,0,400);

    vector<TString> files = {"TTBAR","DY","TTZ","WJets","ZZ","WZ","Data"}; 
    for(int i = 0; i < files.size(); i++) {

        TH1F* h1D_njets_file = new TH1F("njets"+files.at(i), "Njets;;Entries", 10, 0, 10);
        TH1F* h1D_ht_file = new TH1F("ht"+files.at(i), "H_{T};GeV;Entries", 20, 0, 1000); 
        TH1F* h1D_met_file = new TH1F("met"+files.at(i), "#slash{E}_{T};GeV;Entries", 20, 0, 300); 
        TH1F* h1D_mt_file = new TH1F("mt"+files.at(i), "M_{T};GeV;Entries", 20, 0, 450); 
        TH1F* h1D_zmass_file = new TH1F("zmass"+files.at(i), "Z Mass;GeV;Entries", 42, 70, 112); 
        TH1F* h1D_hyp_class_file = new TH1F("hypclass"+files.at(i), "hyp_class;ID;Entries", 7, 0, 7); 
        TH1F* h1D_nbtags_file = new TH1F("nbtags"+files.at(i), "Nbtags;nbtags;Entries", 4, 0, 4); 
        TH1F* h1D_mtmin_file = new TH1F("mtmin"+files.at(i), "mtmin;mtmin;Entries", 20, 0, 200); 

        TH1F* h1D_lep1pt_file = new TH1F("lep1pt"+files.at(i), "lep1pt;lep1pt;Entries", 40, 0, 400); 
        TH1F* h1D_lep2pt_file = new TH1F("lep2pt"+files.at(i), "lep2pt;lep2pt;Entries", 40, 0, 400); 

        TH1F* h1D_yields_HH_file = new TH1F("h1D_yields_HH"+files.at(i), "", 32, 1, 33); 
        TH1F* h1D_yields_HL_file = new TH1F("h1D_yields_HL"+files.at(i), "", 26, 1, 27); 
        TH1F* h1D_yields_LL_file = new TH1F("h1D_yields_LL"+files.at(i), "", 8, 1, 9); 

        h1D_njets_vec.push_back(h1D_njets_file); 
        h1D_ht_vec.push_back(h1D_ht_file); 
        h1D_met_vec.push_back(h1D_met_file); 
        h1D_mt_vec.push_back(h1D_mt_file); 
        h1D_mtmin_vec.push_back(h1D_mtmin_file); 
        h1D_zmass_vec.push_back(h1D_zmass_file); 
        h1D_hyp_class_vec.push_back(h1D_hyp_class_file); 
        h1D_nbtags_vec.push_back(h1D_nbtags_file); 
        h1D_lep1pt_vec.push_back(h1D_lep1pt_file); 
        h1D_lep2pt_vec.push_back(h1D_lep2pt_file); 

        h1D_yields_HH_vec.push_back(h1D_yields_HH_file);
        h1D_yields_HL_vec.push_back(h1D_yields_HL_file);
        h1D_yields_LL_vec.push_back(h1D_yields_LL_file);

    }

    initCounter();
    // File Loop
    while ( (currentFile = (TFile*)fileIter.Next()) ) { 

        // Get File Content
        TFile *file = new TFile( currentFile->GetTitle() );
        TTree *tree = (TTree*)file->Get("t");
        samesign.Init(tree);

        TString filename(currentFile->GetTitle());

        int iSample = -1;

        if(filename.Contains("TTBAR"))      { filename = "TTBAR"; iSample = 0; }
        else if(filename.Contains("DY"))    { filename = "DY";    iSample = 1; }
        else if(filename.Contains("TTZ"))   { filename = "TTZ";   iSample = 2; }
        else if(filename.Contains("WJets")) { filename = "WJets"; iSample = 3; }
        else if(filename.Contains("ZZ"))  { filename = "ZZ";    iSample = 4; }
        else if(filename.Contains("WZ3L"))    { filename = "WZ";    iSample = 5; }
        else if(filename.Contains("data"))  { filename = "Data";  iSample = 6; }
        else { std::cout << "ERROR: I don't know what " << filename << " is! Skipping file " << filename << std::endl; continue; }

        // Loop over Events in current file
        for( unsigned int event = 0; event < tree->GetEntriesFast(); ++event) {

            // Get Event Content
            samesign.GetEntry(event);
            nEventsTotal++;

            //Progress
            SSAG::progress(nEventsTotal, nEventsChain);

            float scale = 1.0;
            if(!ss::is_real_data()) {
                scale = ss::scale1fb() * luminosity;
            } else {
                DorkyEventIdentifier id(ss::run(), ss::event(), ss::lumi());
                if (is_duplicate(id) ) continue;
            }

            // fill these before making cuts
            fill(h1D_hyp_class_vec.at(iSample), ss::hyp_class(), scale);

            // this guarantees that the third lepton makes a Z with one of the first two leptons
            // if( ! (ss::hyp_class() == 6 && ss::madeExtraZ()) ) continue;
            if( ! (ss::hyp_class() == 6) ) continue;

            if( !(ss::lep1_passes_id() && 
                  ss::lep2_passes_id() && 
                  // ss::lep3_veto()     ) ) continue; // looser selection for third lepton
                  ss::lep3_passes_id()) ) continue;

            // figure out which pair has inv mass closest to Z
            float zmass23 = ss::lep2_id() == -ss::lep3_id() ? (ss::lep2_p4()+ss::lep3_p4()).mass() : -1.0;
            float zmass31 = ss::lep3_id() == -ss::lep1_id() ? (ss::lep3_p4()+ss::lep1_p4()).mass() : -1.0;

            float zmass;
            if( fabs(zmass31 - 91.2) < fabs(zmass23 - 91.2) ) zmass = zmass31;
            else zmass = zmass23;

            // require a Z
            if (fabs(zmass-91.2) > 15.0) continue;


            if(ss::met() < 50.0) continue;
            // if MET < 30 or Njets <= 2 then we don't care about considering it at all, even in the N-1 plots, so exclude it
            // if(ss::met() < 30.0) continue;
            // if(ss::njets() < 2) continue;

            // all 4 of these define the CR
            bool goodBtags = ss::nbtags() < 1;
            bool goodNjets = ss::njets() < 5;
            bool goodMet = ss::met() < 200.0;
            bool goodHH = ss::lep1_p4().pt() > 25.0 && ss::lep2_p4().pt() > 25.0;
            bool goodMtmin = ss::mtmin() < 120;

            // Actually ignore the MET and MTMIN boundaries for more statistics
            goodMet = true;
            goodMtmin = true;

            if(filename.Contains("WZ"))    {
                h2D_ptlep1_ptlep2_wz->Fill(ss::lep2_p4().pt(),ss::lep1_p4().pt());
                h2D_ht_njets_wz->Fill(ss::ht(),ss::njets());
                h2D_ht_sumleppt_wz->Fill( ss::ht(), ss::lep2_p4().pt()+ss::lep1_p4().pt() );
                h2D_njets_nbtags_wz->Fill(ss::nbtags(),ss::njets());
                h2D_met_mtmin_wz->Fill(ss::mtmin(),ss::met());
            }

            if(goodNjets && goodMet && goodHH && goodMtmin)  {
                if(ss::nbtags() < 1)  addToCounter("2:nbtags<1_" +filename,scale);
                if(ss::nbtags() >= 1) addToCounter("2:nbtags>=1_"+filename,scale);
                fill(h1D_nbtags_vec.at(iSample), ss::nbtags(), scale);
            }


            if(goodBtags && goodNjets && goodMet && goodMtmin)  {
                anal_type_t categ = analysisCategory(ss::lep1_p4().pt(), ss::lep2_p4().pt());  
                if(categ == HighHigh) addToCounter("6:HH_" +filename,scale);
                if(categ == HighLow)  addToCounter("6:HL_" +filename,scale);
                fill(h1D_lep1pt_vec.at(iSample),ss::lep1_p4().pt(), scale);
                fill(h1D_lep2pt_vec.at(iSample),ss::lep2_p4().pt(), scale);
            }

            if(goodBtags && goodNjets && goodMet && goodHH)  {
                if(ss::mtmin() < 120)  addToCounter("5:mtmin<120_" +filename,scale);
                if(ss::mtmin() >= 120) addToCounter("5:mtmin>=120_"+filename,scale);
                fill(h1D_mtmin_vec.at(iSample),ss::mtmin(), scale);
            }


            if(goodBtags && goodMet && goodHH && goodMtmin)  {
                if(ss::njets() < 5)  addToCounter("1:njets<5_" +filename,scale);
                if(ss::njets() >= 5) addToCounter("1:njets>=5_"+filename,scale);
                fill(h1D_njets_vec.at(iSample),ss::njets(), scale);
            }

            if(goodBtags && goodNjets && goodHH && goodMtmin)  {
                if(ss::met() < 200)  addToCounter("3:met<200_" +filename,scale);
                if(ss::met() >= 200) addToCounter("3:met>=200_"+filename,scale);
                fill(h1D_met_vec.at(iSample),ss::met(), scale);
            }


            if(! (goodBtags && goodNjets && goodMet && goodHH && goodMtmin) ) continue;
            // now we are in the CR
            //
            fill(h1D_zmass_vec.at(iSample),zmass, scale); 

            if(ss::ht() < 300)  addToCounter("4:ht<300_" +filename,scale);
            if(ss::ht() >= 300) addToCounter("4:ht>=300_"+filename,scale);
            fill(h1D_ht_vec.at(iSample),ss::ht(), scale);

            // fill(h1D_mt_vec.at(iSample),ss::mt(), scale);
            // fill(h1D_zmass_vec.at(iSample),zmass, scale); 


            addToCounter(filename, scale);
            if(!ss::is_real_data()) {
                nGoodEvents++;
                nGoodEventsWeighted+=scale;
            } else {
                nGoodEventsData++;
            }

        }//event loop

    }//file loop MCMC

    // nGoodEventsWeighted nGoodEvents nGoodEventsData nEventsTotal
    std::cout << " nGoodEventsWeighted: " << nGoodEventsWeighted << " nGoodEvents: " << nGoodEvents << " nGoodEventsData: " << nGoodEventsData << " nEventsTotal: " << nEventsTotal << std::endl;
    printCounter(true);

    // TH1F* null = new TH1F("","",1,0,1);
    TH1F* data;
    std::string com = " --errHistAtBottom --doCounts --colorTitle --lumi 832 --lumiUnit pb --percentageInBox --legendRight 0.05 --legendUp 0.05 --noDivisionLabel --noType --outputName pdfs/";
    std::string pct = " --showPercentage ";
    // std::string spec = "SR1-8";
    std::string spec = "";

    std::string HHbins = " --xAxisVerticalBinLabels --xAxisBinLabels 1A,2A,3A,4A,5A,6A,7A,8A,9A,10A,11A,12A,13A,14A,15A,16A,17A,18A,19A,20A,21A,22A,23A,24A,25A,26A,27A,28A,29A,30A,31A,32A";
    std::string HLbins = " --xAxisVerticalBinLabels --xAxisBinLabels 1B,2B,3B,4B,5B,6B,7B,8B,9B,10B,11B,12B,13B,14B,15B,16B,17B,18B,19B,20B,21B,22B,23B,24B,25B,26B";
    std::string LLbins = " --xAxisVerticalBinLabels --xAxisBinLabels 1C,2C,3C,4C,5C,6C,7C,8C";

    data = h1D_njets_vec.back(); h1D_njets_vec.pop_back(); dataMCplotMaker(data,h1D_njets_vec    ,titles,"Njets",spec,com+"h1D_njets.pdf           --isLinear --vLine 5 --xAxisOverride njets");
    // data = h1D_ht_vec.back(); h1D_ht_vec.pop_back(); dataMCplotMaker(data,h1D_ht_vec             ,titles,"H_{T}",spec,com+"h1D_ht.pdf              --isLinear --vLine 300 --xAxisOverride [GeV]");
    // data = h1D_mtmin_vec.back(); h1D_mtmin_vec.pop_back(); dataMCplotMaker(data,h1D_mtmin_vec    ,titles,"m_{T,min}",spec,com+"h1D_mtmin.pdf       --isLinear --vLine 120 --xAxisOverride [GeV]");
    // data = h1D_met_vec.back(); h1D_met_vec.pop_back(); dataMCplotMaker(data,h1D_met_vec          ,titles,"#slash{E}_{T}",spec,com+"h1D_met.pdf     --isLinear --vLine 200 --xAxisOverride [GeV]");
    data = h1D_ht_vec.back(); h1D_ht_vec.pop_back(); dataMCplotMaker(data,h1D_ht_vec             ,titles,"H_{T}",spec,com+"h1D_ht.pdf              --isLinear             --xAxisOverride [GeV]");
    data = h1D_mtmin_vec.back(); h1D_mtmin_vec.pop_back(); dataMCplotMaker(data,h1D_mtmin_vec    ,titles,"m_{T,min}",spec,com+"h1D_mtmin.pdf       --isLinear             --xAxisOverride [GeV]");
    data = h1D_met_vec.back(); h1D_met_vec.pop_back(); dataMCplotMaker(data,h1D_met_vec          ,titles,"#slash{E}_{T}",spec,com+"h1D_met.pdf     --isLinear             --xAxisOverride [GeV]");

    data = h1D_nbtags_vec.back(); h1D_nbtags_vec.pop_back(); dataMCplotMaker(data,h1D_nbtags_vec ,titles,"Nbtags",spec,com+"h1D_nbtags.pdf         --isLinear --vLine 1 --xAxisOverride n");
    data = h1D_lep1pt_vec.back(); h1D_lep1pt_vec.pop_back(); dataMCplotMaker(data,h1D_lep1pt_vec ,titles,"p_{T}(lep_{1})",spec,com+"h1D_lep1pt.pdf --isLinear --vLine 25 --xAxisOverride [GeV]");
    data = h1D_lep2pt_vec.back(); h1D_lep2pt_vec.pop_back(); dataMCplotMaker(data,h1D_lep2pt_vec ,titles,"p_{T}(lep_{2})",spec,com+"h1D_lep2pt.pdf --isLinear --vLine 25 --xAxisOverride [GeV]");


    drawHist2D(h2D_ht_sumleppt_wz , "pdfs/h2D_ht_sumleppt_wz.pdf" , "--logscale --title WZ: p_{T}(lep_{1})+p_{T}(lep_{2}) vs H_{T} --xlabel  sum H_{T} --ylabel leppt");
    drawHist2D(h2D_ht_njets_wz , "pdfs/h2D_ht_njets_wz.pdf" , "--logscale --title WZ: Njets vs H_{T} --xlabel  H_{T} --ylabel Njets");
    drawHist2D(h2D_ptlep1_ptlep2_wz , "pdfs/h2D_ptlep1_ptlep2_wz.pdf" , "--logscale --title WZ: p_{T}(lep_{1}) vs p_{T}(lep_{2}) --xlabel  ptlep2 --ylabel ptlep1");
    drawHist2D(h2D_njets_nbtags_wz  , "pdfs/h2D_njets_nbtags_wz.pdf"  , "--logscale --title WZ: Njets vs Nbtags --xlabel  nbtags --ylabel njets");
    drawHist2D(h2D_met_mtmin_wz     , "pdfs/h2D_met_mtmin_wz.pdf"     , "--logscale --title WZ: #slash{E}_{T} vs m_{T,min} --xlabel  mtmin --ylabel met");

    // data = h1D_yields_HH_vec.back(); h1D_yields_HH_vec.pop_back();
    // dataMCplotMaker(data,h1D_yields_HH_vec ,titles,"HH yields",spec,com+"h1D_yields_HH.pdf --isLinear --xAxisOverride SR "+HHbins);

    // data = h1D_yields_HL_vec.back(); h1D_yields_HL_vec.pop_back();
    // dataMCplotMaker(data,h1D_yields_HL_vec ,titles,"HL yields",spec,com+"h1D_yields_HL.pdf --isLinear --xAxisOverride SR "+HLbins+pct);

    // data = h1D_yields_LL_vec.back(); h1D_yields_LL_vec.pop_back();
    // dataMCplotMaker(data,h1D_yields_LL_vec ,titles,"LL yields",spec,com+"h1D_yields_LL.pdf --isLinear --xAxisOverride SR "+LLbins);

    data = h1D_zmass_vec.back(); h1D_zmass_vec.pop_back();
    dataMCplotMaker(data,h1D_zmass_vec     ,titles,"m_{ll}",spec,com+"h1D_zmass.pdf                   --isLinear --xAxisOverride [GeV]");

    // dataMCplotMaker(null,h1D_hyp_class_vec ,titles,"hyp_class (no cuts)",spec,com+"h1D_hyp_class.pdf            --xAxisOverride id    "+pct);

    return 0;
}
