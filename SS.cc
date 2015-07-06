#include "SS.h"
#ifdef __MAKECINT__ 
#pragma link C++ class ROOT::Math::PxPyPzE4D<float>+; 
#pragma link C++ class ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> >+;
#endif 
SSAG samesign;
namespace ss {
	const float &met() { return samesign.met(); }
	const float &metPhi() { return samesign.metPhi(); }
	const int &event() { return samesign.event(); }
	const int &lumi() { return samesign.lumi(); }
	const int &run() { return samesign.run(); }
	const bool &filt_csc() { return samesign.filt_csc(); }
	const bool &filt_hbhe() { return samesign.filt_hbhe(); }
	const bool &filt_hcallaser() { return samesign.filt_hcallaser(); }
	const bool &filt_ecaltp() { return samesign.filt_ecaltp(); }
	const bool &filt_trkfail() { return samesign.filt_trkfail(); }
	const bool &filt_eebadsc() { return samesign.filt_eebadsc(); }
	const bool &is_real_data() { return samesign.is_real_data(); }
	const float &scale1fb() { return samesign.scale1fb(); }
	const float &xsec() { return samesign.xsec(); }
	const float &kfactor() { return samesign.kfactor(); }
	const float &gen_met() { return samesign.gen_met(); }
	const float &gen_met_phi() { return samesign.gen_met_phi(); }
	const int &njets() { return samesign.njets(); }
	const int &hyp_class() { return samesign.hyp_class(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4() { return samesign.lep1_p4(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4() { return samesign.lep2_p4(); }
	const float &ht() { return samesign.ht(); }
	const int &lep1_motherID() { return samesign.lep1_motherID(); }
	const int &lep2_motherID() { return samesign.lep2_motherID(); }
	const int &lep1_mc_id() { return samesign.lep1_mc_id(); }
	const int &lep2_mc_id() { return samesign.lep2_mc_id(); }
	const int &lep1_id() { return samesign.lep1_id(); }
	const int &lep2_id() { return samesign.lep2_id(); }
	const float &lep1_coneCorrPt() { return samesign.lep1_coneCorrPt(); }
	const float &lep2_coneCorrPt() { return samesign.lep2_coneCorrPt(); }
	const int &lep1_idx() { return samesign.lep1_idx(); }
	const int &lep2_idx() { return samesign.lep2_idx(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets() { return samesign.jets(); }
	const vector<float> &btags_disc() { return samesign.btags_disc(); }
	const vector<float> &jets_disc() { return samesign.jets_disc(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &btags() { return samesign.btags(); }
	const int &nbtags() { return samesign.nbtags(); }
	const float &sf_dilepTrig_hpt() { return samesign.sf_dilepTrig_hpt(); }
	const float &sf_dilepTrig_lpt() { return samesign.sf_dilepTrig_lpt(); }
	const float &sf_dilepTrig_vlpt() { return samesign.sf_dilepTrig_vlpt(); }
	const int &hyp_type() { return samesign.hyp_type(); }
	const float &sf_dilep_eff() { return samesign.sf_dilep_eff(); }
	const float &mt() { return samesign.mt(); }
	const float &mt_l2() { return samesign.mt_l2(); }
	const float &mt2() { return samesign.mt2(); }
	const float &mtmin() { return samesign.mtmin(); }
	const float &mGluino() { return samesign.mGluino(); }
	const float &mLSP() { return samesign.mLSP(); }
	const float &mSbottom() { return samesign.mSbottom(); }
	const float &mChargino() { return samesign.mChargino(); }
	const int &lep1_id_gen() { return samesign.lep1_id_gen(); }
	const int &lep2_id_gen() { return samesign.lep2_id_gen(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4_gen() { return samesign.lep1_p4_gen(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4_gen() { return samesign.lep2_p4_gen(); }
	const int &lep3_id() { return samesign.lep3_id(); }
	const int &lep3_idx() { return samesign.lep3_idx(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep3_p4() { return samesign.lep3_p4(); }
	const int &lep3_quality() { return samesign.lep3_quality(); }
	const float &lep1_iso() { return samesign.lep1_iso(); }
	const float &lep2_iso() { return samesign.lep2_iso(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &dilep_p4() { return samesign.dilep_p4(); }
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4() { return samesign.genps_p4(); }
	const vector<int> &genps_id() { return samesign.genps_id(); }
	const vector<int> &genps_id_mother() { return samesign.genps_id_mother(); }
	const vector<int> &genps_status() { return samesign.genps_status(); }
	const vector<int> &genps_id_grandma() { return samesign.genps_id_grandma(); }
	const bool &lep1_passes_id() { return samesign.lep1_passes_id(); }
	const bool &lep2_passes_id() { return samesign.lep2_passes_id(); }
	const bool &lep3_passes_id() { return samesign.lep3_passes_id(); }
	const bool &lep3_tight() { return samesign.lep3_tight(); }
	const bool &lep3_veto() { return samesign.lep3_veto(); }
	const bool &lep3_fo() { return samesign.lep3_fo(); }
	const float &lep1_dxyPV() { return samesign.lep1_dxyPV(); }
	const float &lep2_dxyPV() { return samesign.lep2_dxyPV(); }
	const float &lep1_dZ() { return samesign.lep1_dZ(); }
	const float &lep2_dZ() { return samesign.lep2_dZ(); }
	const float &lep1_d0_err() { return samesign.lep1_d0_err(); }
	const float &lep2_d0_err() { return samesign.lep2_d0_err(); }
	const float &lep1_ip3d() { return samesign.lep1_ip3d(); }
	const float &lep2_ip3d() { return samesign.lep2_ip3d(); }
	const float &lep1_MVA() { return samesign.lep1_MVA(); }
	const float &lep2_MVA() { return samesign.lep2_MVA(); }
	const float &lep1_ip3d_err() { return samesign.lep1_ip3d_err(); }
	const float &lep2_ip3d_err() { return samesign.lep2_ip3d_err(); }
	const int &nVetoElectrons7() { return samesign.nVetoElectrons7(); }
	const int &nVetoElectrons10() { return samesign.nVetoElectrons10(); }
	const int &nVetoElectrons25() { return samesign.nVetoElectrons25(); }
	const int &nVetoMuons5() { return samesign.nVetoMuons5(); }
	const int &nVetoMuons10() { return samesign.nVetoMuons10(); }
	const int &nVetoMuons25() { return samesign.nVetoMuons25(); }
	const TString &filename() { return samesign.filename(); }
	const float &lep1_ptrel_v0() { return samesign.lep1_ptrel_v0(); }
	const float &lep1_ptrel_v1() { return samesign.lep1_ptrel_v1(); }
	const float &lep2_ptrel_v0() { return samesign.lep2_ptrel_v0(); }
	const float &lep2_ptrel_v1() { return samesign.lep2_ptrel_v1(); }
	const float &lep1_miniIso() { return samesign.lep1_miniIso(); }
	const float &lep2_miniIso() { return samesign.lep2_miniIso(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep1() { return samesign.jet_close_lep1(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep2() { return samesign.jet_close_lep2(); }
	const vector<int> &eleID_kfhits() { return samesign.eleID_kfhits(); }
	const vector<float> &eleID_oldsigmaietaieta() { return samesign.eleID_oldsigmaietaieta(); }
	const vector<float> &eleID_oldsigmaiphiiphi() { return samesign.eleID_oldsigmaiphiiphi(); }
	const vector<float> &eleID_oldcircularity() { return samesign.eleID_oldcircularity(); }
	const vector<float> &eleID_oldr9() { return samesign.eleID_oldr9(); }
	const vector<float> &eleID_scletawidth() { return samesign.eleID_scletawidth(); }
	const vector<float> &eleID_sclphiwidth() { return samesign.eleID_sclphiwidth(); }
	const vector<float> &eleID_he() { return samesign.eleID_he(); }
	const vector<float> &eleID_psEoverEraw() { return samesign.eleID_psEoverEraw(); }
	const vector<float> &eleID_kfchi2() { return samesign.eleID_kfchi2(); }
	const vector<float> &eleID_chi2_hits() { return samesign.eleID_chi2_hits(); }
	const vector<float> &eleID_fbrem() { return samesign.eleID_fbrem(); }
	const vector<float> &eleID_ep() { return samesign.eleID_ep(); }
	const vector<float> &eleID_eelepout() { return samesign.eleID_eelepout(); }
	const vector<float> &eleID_IoEmIop() { return samesign.eleID_IoEmIop(); }
	const vector<float> &eleID_deltaetain() { return samesign.eleID_deltaetain(); }
	const vector<float> &eleID_deltaphiin() { return samesign.eleID_deltaphiin(); }
	const vector<float> &eleID_deltaetaseed() { return samesign.eleID_deltaetaseed(); }
	const vector<float> &eleID_pT() { return samesign.eleID_pT(); }
	const vector<bool> &eleID_isbarrel() { return samesign.eleID_isbarrel(); }
	const vector<bool> &eleID_isendcap() { return samesign.eleID_isendcap(); }
	const vector<float> &eleID_scl_eta() { return samesign.eleID_scl_eta(); }
	const vector<float> &muID_dzPV() { return samesign.muID_dzPV(); }
	const vector<float> &muID_ptSig() { return samesign.muID_ptSig(); }
	const vector<float> &muID_ip3dSig() { return samesign.muID_ip3dSig(); }
	const vector<float> &muID_medMuonPOG() { return samesign.muID_medMuonPOG(); }
	const vector<float> &muID_pt() { return samesign.muID_pt(); }
	const vector<float> &muID_eta() { return samesign.muID_eta(); }
	const vector<float> &trueNumInt() { return samesign.trueNumInt(); }
	const vector<int> &nPUvertices() { return samesign.nPUvertices(); }
	const int &nGoodVertices() { return samesign.nGoodVertices(); }
	const bool &lep1_isGoodLeg() { return samesign.lep1_isGoodLeg(); }
	const bool &lep2_isGoodLeg() { return samesign.lep2_isGoodLeg(); }
	const bool &lep1_isFakeLeg() { return samesign.lep1_isFakeLeg(); }
	const bool &lep2_isFakeLeg() { return samesign.lep2_isFakeLeg(); }
	const bool &lep1_multiIso() { return samesign.lep1_multiIso(); }
	const bool &lep2_multiIso() { return samesign.lep2_multiIso(); }
	const float &lep1_sip() { return samesign.lep1_sip(); }
	const float &lep2_sip() { return samesign.lep2_sip(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_closeJet() { return samesign.lep1_closeJet(); }
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_closeJet() { return samesign.lep2_closeJet(); }
	const bool &passed_id_inSituFR_lep1() { return samesign.passed_id_inSituFR_lep1(); }
	const bool &passed_id_inSituFR_lep2() { return samesign.passed_id_inSituFR_lep2(); }
}
