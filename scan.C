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
#include "SS.h"

#include "/home/users/namin/macros/utils.C"
#include "../CORE/SSSelections.h"

using namespace std;

int scan(unsigned int njetsLow=0, unsigned int njetsHigh=9999, int btagCut=9999, int metLow=0, int metHigh=9999, int htLow=0, int htHigh=9999, std::string tag=""){
    //njetsLow, njetsHigh, btagCut, metLow, metHigh, htLow, htHigh, tag, manualScale

    float zmassCut = 15; // line 212 of AN

    TChain *ch = new TChain("t");
    std::vector<std::string> titles;


    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.26/TTBAR_0.root");   titles.push_back("tt");

    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/TTBAR_0.root");   titles.push_back("tt");
    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/DY1_0.root");     titles.push_back("DY");
    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/TTW_0.root");     titles.push_back("ttW");
    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/TTZ_0.root");     titles.push_back("ttZ");
    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/WJets1_0.root");  titles.push_back("WJets");
    // ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/WZ_0.root");      titles.push_back("WZ");

    ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/TTBAR_0.root");   titles.push_back("tt");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/DY1_0.root");     titles.push_back("DY");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/TTW_0.root");     titles.push_back("ttW");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/TTZ_0.root");     titles.push_back("ttZ");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/WJets1_0.root");  titles.push_back("WJets");
    ch->Add("/nfs-7/userdata/ss2015/ssBabies/v1.27/WZ_0.root");      titles.push_back("WZ");

    int nEventsTotal = 0;
    int nEventsChain = ch->GetEntries();
    int nGoodEvents = 0;
    float nGoodEventsWeighted = 0;
    float luminosity = 10.0;

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
    vector<TH1F*> h1D_btagval_vec;
    vector<TH1F*> h1D_mtmin_vec;

    TString prevFilename = "";
    initCounter();
    // File Loop
    while ( (currentFile = (TFile*)fileIter.Next()) ) { 

        // Get File Content
        TFile *file = new TFile( currentFile->GetTitle() );
        TTree *tree = (TTree*)file->Get("t");
        samesign.Init(tree);

        TString filename(currentFile->GetTitle());
        if(filename != prevFilename) {
            std::cout << filename << std::endl;
            prevFilename = filename;
        }

        if(filename.Contains("TTBAR")) filename = "TTBAR";
        else if(filename.Contains("DY")) filename = "DY";
        else if(filename.Contains("TTW")) filename = "TTW";
        else if(filename.Contains("TTZ")) filename = "TTZ";
        else if(filename.Contains("WJets")) filename = "WJets";
        else if(filename.Contains("WZ")) filename = "WZ";
        else {
            std::cout << "I don't know what " << filename << " is!" << std::endl;
            std::cout << "I don't know what " << filename << " is!" << std::endl;
        }


        // TObjArray *tx = filename.Tokenize("_");
        // filename = ((TObjString *)(tx->At(0)))->String();

        TH1F* h1D_njets_file = new TH1F("njets"+filename, "Njets;;Entries", 15, 0, 15); h1D_njets_file->Sumw2();
        TH1F* h1D_ht_file = new TH1F("ht"+filename, "H_{T};GeV;Entries", 20, 0, 600); 
        TH1F* h1D_met_file = new TH1F("met"+filename, "#slash{E}_{T};GeV;Entries", 20, 0, 300); 
        TH1F* h1D_mt_file = new TH1F("mt"+filename, "M_{T};GeV;Entries", 20, 0, 400); 
        TH1F* h1D_zmass_file = new TH1F("zmass"+filename, "Z Mass;GeV;Entries", 42, 70, 112); 
        TH1F* h1D_hyp_class_file = new TH1F("hypclass"+filename, "hyp_class;ID;Entries", 7, 0, 7); 
        TH1F* h1D_nbtags_file = new TH1F("nbtags"+filename, "Nbtags;nbtags;Entries", 7, 0, 7); 
        TH1F* h1D_nbtagval_file = new TH1F("btagval"+filename, "Btag;Btag;Entries", 30, 0, 1.0); 
        TH1F* h1D_mtmin_file = new TH1F("mtmin"+filename, "mtmin;mtmin;Entries", 20, 0, 400); 

        h1D_njets_vec.push_back(h1D_njets_file); 
        h1D_ht_vec.push_back(h1D_ht_file); 
        h1D_met_vec.push_back(h1D_met_file); 
        h1D_mt_vec.push_back(h1D_mt_file); 
        h1D_mtmin_vec.push_back(h1D_mtmin_file); 
        h1D_zmass_vec.push_back(h1D_zmass_file); 
        h1D_hyp_class_vec.push_back(h1D_hyp_class_file); 
        h1D_nbtags_vec.push_back(h1D_nbtags_file); 
        h1D_btagval_vec.push_back(h1D_nbtagval_file); 

        // Loop over Events in current file
        for( unsigned int event = 0; event < tree->GetEntriesFast(); ++event) {

            // Get Event Content
            samesign.GetEntry(event);
            nEventsTotal++;

            //Progress
            SSAG::progress(nEventsTotal, nEventsChain);

            float scale = ss::scale1fb()  * luminosity;

            // fill these before making cuts
            fill(h1D_hyp_class_file, ss::hyp_class(), scale);

            // this guarantees that the third lepton makes a Z with one of the first two leptons
            if(ss::hyp_class() != 6) continue;



            // require that leptons have pt>20 and |eta|<2.4 ("loose requirements")
            if( ss::lep1_p4().pt() < 20.0 || ss::lep2_p4().pt() < 20.0 || ss::lep3_p4().pt() < 20.0 ) continue;
            if( fabs(ss::lep1_p4().eta()) > 2.4 || fabs(ss::lep2_p4().eta()) > 2.4 || fabs(ss::lep3_p4().eta()) > 2.4 ) continue;

            // did lep1 and lep3 come from a Z?
            bool lep1FromZ;
            // figure out which pair has inv mass closest to Z
            float zmass23 = ss::lep2_id() == -ss::lep3_id() ? (ss::lep2_p4()+ss::lep3_p4()).mass() : -1.0;
            float zmass31 = ss::lep3_id() == -ss::lep1_id() ? (ss::lep3_p4()+ss::lep1_p4()).mass() : -1.0;

            float zmass;
            if( fabs(zmass31 - 91.2) < fabs(zmass23 - 91.2) ) {
                zmass = zmass31;
                lep1FromZ = true;
            } else {
                zmass = zmass23;
                lep1FromZ = false;
            }

            // now we impose a tighter requirement on the lepton from the W
            if( lep1FromZ ) {
                if( !ss::lep2_passes_id() ) continue;
            } else {
                if( !ss::lep1_passes_id() ) continue;
            }
            if( !ss::lep3_passes_id() ) continue;
            // if( !ss::lep3_tight() ) continue;
            // if( !ss::lep3_veto() ) continue;
            // if( !ss::lep3_fo() ) continue;

            if(ss::met() < metLow || ss::met() > metHigh) continue;
            if(fabs(zmass - 91.2) > zmassCut) continue;
            if(ss::ht() < htLow || ss::ht() > htHigh) continue;
            if(ss::njets() < njetsLow || ss::njets() > njetsHigh) continue;

            // We are now in the region of interest


            fill(h1D_nbtags_file, ss::nbtags(), scale);
            if(ss::nbtags() >= btagCut) continue;

            for(int iJet = 0; iJet < ss::jets().size(); iJet++) {
                fill(h1D_nbtagval_file, ss::jets_disc().at(iJet),scale);
            }
            fill(h1D_mt_file,ss::mt(), scale);
            fill(h1D_mtmin_file,ss::mtmin(), scale);
            fill(h1D_zmass_file,zmass, scale); 
            fill(h1D_njets_file,ss::njets(), scale);
            fill(h1D_ht_file,ss::ht(), scale);
            fill(h1D_met_file,ss::met(), scale);

            nGoodEvents++;
            nGoodEventsWeighted+=scale;
            addToCounter(filename, scale);



        }//event loop

    }//file loop MCMC

    std::cout << "nGoodEventsWeighted: " << nGoodEventsWeighted << " nGoodEvents: " << nGoodEvents << " nEventsTotal: " << nEventsTotal << std::endl;
    printCounter();

    TH1F* null = new TH1F("","",1,0,1);
    // std::string com = "--preserveBackgroundOrder --showPercentage --outputName pdfs"+tag+"/";
    std::string com = "--noDivisionLabel --showPercentage --outputName pdfs"+tag+"/";

    dataMCplotMaker(null,h1D_njets_vec     ,titles,"Njets","",com+"h1D_njets.pdf                   --isLinear --xAxisOverride njets ");
    dataMCplotMaker(null,h1D_ht_vec        ,titles,"H_{T}","",com+"h1D_ht.pdf                      --isLinear --xAxisOverride [GeV] ");
    dataMCplotMaker(null,h1D_mt_vec        ,titles,"m_{T}","",com+"h1D_mt.pdf                      --isLinear --xAxisOverride [GeV] ");
    dataMCplotMaker(null,h1D_mtmin_vec     ,titles,"m_{T,min}","",com+"h1D_mtmin.pdf               --isLinear --xAxisOverride [GeV] ");
    dataMCplotMaker(null,h1D_met_vec       ,titles,"#slash{E}_{T}","",com+"h1D_met.pdf             --isLinear --xAxisOverride [GeV] ");
    dataMCplotMaker(null,h1D_zmass_vec     ,titles,"m_{Z}","",com+"h1D_zmass.pdf                   --isLinear --xAxisOverride [GeV] ");
    dataMCplotMaker(null,h1D_hyp_class_vec ,titles,"hyp_class (no cuts)","",com+"h1D_hyp_class.pdf            --xAxisOverride id    ");
    dataMCplotMaker(null,h1D_nbtags_vec    ,titles,"Nbtags (no cuts)","",com+"h1D_nbtags.pdf                  --xAxisOverride n     ");
    dataMCplotMaker(null,h1D_btagval_vec   ,titles,"Btag disc","",com+"h1D_btagval.pdf             --isLinear --xAxisOverride disc  ");

    return 0;
}
