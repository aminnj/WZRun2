// -*- C++ -*-
#ifndef SSAG_H
#define SSAG_H
#include "Math/LorentzVector.h"
#include "Math/Point3D.h"
#include "TMath.h"
#include "TBranch.h"
#include "TTree.h"
#include "TH1F.h"
#include "TFile.h"
#include "TBits.h"
#include <vector> 
#include <unistd.h> 
typedef ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > LorentzVector;

using namespace std; 
class SSAG {
private: 
protected: 
	unsigned int index;
	float	met_;
	TBranch *met_branch;
	bool met_isLoaded;
	float	metPhi_;
	TBranch *metPhi_branch;
	bool metPhi_isLoaded;
	int	event_;
	TBranch *event_branch;
	bool event_isLoaded;
	int	lumi_;
	TBranch *lumi_branch;
	bool lumi_isLoaded;
	int	run_;
	TBranch *run_branch;
	bool run_isLoaded;
	bool	filt_csc_;
	TBranch *filt_csc_branch;
	bool filt_csc_isLoaded;
	bool	filt_hbhe_;
	TBranch *filt_hbhe_branch;
	bool filt_hbhe_isLoaded;
	bool	filt_hcallaser_;
	TBranch *filt_hcallaser_branch;
	bool filt_hcallaser_isLoaded;
	bool	filt_ecaltp_;
	TBranch *filt_ecaltp_branch;
	bool filt_ecaltp_isLoaded;
	bool	filt_trkfail_;
	TBranch *filt_trkfail_branch;
	bool filt_trkfail_isLoaded;
	bool	filt_eebadsc_;
	TBranch *filt_eebadsc_branch;
	bool filt_eebadsc_isLoaded;
	bool	is_real_data_;
	TBranch *is_real_data_branch;
	bool is_real_data_isLoaded;
	float	scale1fb_;
	TBranch *scale1fb_branch;
	bool scale1fb_isLoaded;
	float	xsec_;
	TBranch *xsec_branch;
	bool xsec_isLoaded;
	float	kfactor_;
	TBranch *kfactor_branch;
	bool kfactor_isLoaded;
	float	gen_met_;
	TBranch *gen_met_branch;
	bool gen_met_isLoaded;
	float	gen_met_phi_;
	TBranch *gen_met_phi_branch;
	bool gen_met_phi_isLoaded;
	int	njets_;
	TBranch *njets_branch;
	bool njets_isLoaded;
	int	hyp_class_;
	TBranch *hyp_class_branch;
	bool hyp_class_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep1_p4_;
	TBranch *lep1_p4_branch;
	bool lep1_p4_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep2_p4_;
	TBranch *lep2_p4_branch;
	bool lep2_p4_isLoaded;
	float	ht_;
	TBranch *ht_branch;
	bool ht_isLoaded;
	int	lep1_motherID_;
	TBranch *lep1_motherID_branch;
	bool lep1_motherID_isLoaded;
	int	lep2_motherID_;
	TBranch *lep2_motherID_branch;
	bool lep2_motherID_isLoaded;
	int	lep1_mc_id_;
	TBranch *lep1_mc_id_branch;
	bool lep1_mc_id_isLoaded;
	int	lep2_mc_id_;
	TBranch *lep2_mc_id_branch;
	bool lep2_mc_id_isLoaded;
	int	lep1_id_;
	TBranch *lep1_id_branch;
	bool lep1_id_isLoaded;
	int	lep2_id_;
	TBranch *lep2_id_branch;
	bool lep2_id_isLoaded;
	int	lep1_idx_;
	TBranch *lep1_idx_branch;
	bool lep1_idx_isLoaded;
	int	lep2_idx_;
	TBranch *lep2_idx_branch;
	bool lep2_idx_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *jets_;
	TBranch *jets_branch;
	bool jets_isLoaded;
	vector<float> *btags_disc_;
	TBranch *btags_disc_branch;
	bool btags_disc_isLoaded;
	vector<float> *jets_disc_;
	TBranch *jets_disc_branch;
	bool jets_disc_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *btags_;
	TBranch *btags_branch;
	bool btags_isLoaded;
	int	nbtags_;
	TBranch *nbtags_branch;
	bool nbtags_isLoaded;
	float	sf_dilepTrig_hpt_;
	TBranch *sf_dilepTrig_hpt_branch;
	bool sf_dilepTrig_hpt_isLoaded;
	float	sf_dilepTrig_lpt_;
	TBranch *sf_dilepTrig_lpt_branch;
	bool sf_dilepTrig_lpt_isLoaded;
	float	sf_dilepTrig_vlpt_;
	TBranch *sf_dilepTrig_vlpt_branch;
	bool sf_dilepTrig_vlpt_isLoaded;
	int	hyp_type_;
	TBranch *hyp_type_branch;
	bool hyp_type_isLoaded;
	float	sf_dilep_eff_;
	TBranch *sf_dilep_eff_branch;
	bool sf_dilep_eff_isLoaded;
	float	mt_;
	TBranch *mt_branch;
	bool mt_isLoaded;
	float	mt_l2_;
	TBranch *mt_l2_branch;
	bool mt_l2_isLoaded;
	float	mt2_;
	TBranch *mt2_branch;
	bool mt2_isLoaded;
	float	mGluino_;
	TBranch *mGluino_branch;
	bool mGluino_isLoaded;
	float	mLSP_;
	TBranch *mLSP_branch;
	bool mLSP_isLoaded;
	float	mSbottom_;
	TBranch *mSbottom_branch;
	bool mSbottom_isLoaded;
	float	mChargino_;
	TBranch *mChargino_branch;
	bool mChargino_isLoaded;
	int	lep1_id_gen_;
	TBranch *lep1_id_gen_branch;
	bool lep1_id_gen_isLoaded;
	int	lep2_id_gen_;
	TBranch *lep2_id_gen_branch;
	bool lep2_id_gen_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep1_p4_gen_;
	TBranch *lep1_p4_gen_branch;
	bool lep1_p4_gen_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep2_p4_gen_;
	TBranch *lep2_p4_gen_branch;
	bool lep2_p4_gen_isLoaded;
	int	lep3_id_;
	TBranch *lep3_id_branch;
	bool lep3_id_isLoaded;
	int	lep3_idx_;
	TBranch *lep3_idx_branch;
	bool lep3_idx_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *lep3_p4_;
	TBranch *lep3_p4_branch;
	bool lep3_p4_isLoaded;
	int	lep3_quality_;
	TBranch *lep3_quality_branch;
	bool lep3_quality_isLoaded;
	float	lep1_iso_;
	TBranch *lep1_iso_branch;
	bool lep1_iso_isLoaded;
	float	lep2_iso_;
	TBranch *lep2_iso_branch;
	bool lep2_iso_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *dilep_p4_;
	TBranch *dilep_p4_branch;
	bool dilep_p4_isLoaded;
	vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > *genps_p4_;
	TBranch *genps_p4_branch;
	bool genps_p4_isLoaded;
	vector<int> *genps_id_;
	TBranch *genps_id_branch;
	bool genps_id_isLoaded;
	vector<int> *genps_id_mother_;
	TBranch *genps_id_mother_branch;
	bool genps_id_mother_isLoaded;
	vector<int> *genps_status_;
	TBranch *genps_status_branch;
	bool genps_status_isLoaded;
	vector<int> *genps_id_grandma_;
	TBranch *genps_id_grandma_branch;
	bool genps_id_grandma_isLoaded;
	bool	lep1_passes_id_;
	TBranch *lep1_passes_id_branch;
	bool lep1_passes_id_isLoaded;
	bool	lep2_passes_id_;
	TBranch *lep2_passes_id_branch;
	bool lep2_passes_id_isLoaded;
	float	lep1_dxyPV_;
	TBranch *lep1_dxyPV_branch;
	bool lep1_dxyPV_isLoaded;
	float	lep2_dxyPV_;
	TBranch *lep2_dxyPV_branch;
	bool lep2_dxyPV_isLoaded;
	float	lep1_dZ_;
	TBranch *lep1_dZ_branch;
	bool lep1_dZ_isLoaded;
	float	lep2_dZ_;
	TBranch *lep2_dZ_branch;
	bool lep2_dZ_isLoaded;
	float	lep1_d0_err_;
	TBranch *lep1_d0_err_branch;
	bool lep1_d0_err_isLoaded;
	float	lep2_d0_err_;
	TBranch *lep2_d0_err_branch;
	bool lep2_d0_err_isLoaded;
	float	lep1_ip3d_;
	TBranch *lep1_ip3d_branch;
	bool lep1_ip3d_isLoaded;
	float	lep2_ip3d_;
	TBranch *lep2_ip3d_branch;
	bool lep2_ip3d_isLoaded;
	float	lep1_ip3d_err_;
	TBranch *lep1_ip3d_err_branch;
	bool lep1_ip3d_err_isLoaded;
	float	lep2_ip3d_err_;
	TBranch *lep2_ip3d_err_branch;
	bool lep2_ip3d_err_isLoaded;
	int	nVetoElectrons7_;
	TBranch *nVetoElectrons7_branch;
	bool nVetoElectrons7_isLoaded;
	int	nVetoElectrons10_;
	TBranch *nVetoElectrons10_branch;
	bool nVetoElectrons10_isLoaded;
	int	nVetoElectrons25_;
	TBranch *nVetoElectrons25_branch;
	bool nVetoElectrons25_isLoaded;
	int	nVetoMuons5_;
	TBranch *nVetoMuons5_branch;
	bool nVetoMuons5_isLoaded;
	int	nVetoMuons10_;
	TBranch *nVetoMuons10_branch;
	bool nVetoMuons10_isLoaded;
	int	nVetoMuons25_;
	TBranch *nVetoMuons25_branch;
	bool nVetoMuons25_isLoaded;
	TString *filename_;
	TBranch *filename_branch;
	bool filename_isLoaded;
	float	lep1_ptrel_v0_;
	TBranch *lep1_ptrel_v0_branch;
	bool lep1_ptrel_v0_isLoaded;
	float	lep1_ptrel_v1_;
	TBranch *lep1_ptrel_v1_branch;
	bool lep1_ptrel_v1_isLoaded;
	float	lep2_ptrel_v0_;
	TBranch *lep2_ptrel_v0_branch;
	bool lep2_ptrel_v0_isLoaded;
	float	lep2_ptrel_v1_;
	TBranch *lep2_ptrel_v1_branch;
	bool lep2_ptrel_v1_isLoaded;
	float	lep1_miniIso_;
	TBranch *lep1_miniIso_branch;
	bool lep1_miniIso_isLoaded;
	float	lep2_miniIso_;
	TBranch *lep2_miniIso_branch;
	bool lep2_miniIso_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *jet_close_lep1_;
	TBranch *jet_close_lep1_branch;
	bool jet_close_lep1_isLoaded;
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > *jet_close_lep2_;
	TBranch *jet_close_lep2_branch;
	bool jet_close_lep2_isLoaded;
	vector<int> *eleID_kfhits_;
	TBranch *eleID_kfhits_branch;
	bool eleID_kfhits_isLoaded;
	vector<float> *eleID_oldsigmaietaieta_;
	TBranch *eleID_oldsigmaietaieta_branch;
	bool eleID_oldsigmaietaieta_isLoaded;
	vector<float> *eleID_oldsigmaiphiiphi_;
	TBranch *eleID_oldsigmaiphiiphi_branch;
	bool eleID_oldsigmaiphiiphi_isLoaded;
	vector<float> *eleID_oldcircularity_;
	TBranch *eleID_oldcircularity_branch;
	bool eleID_oldcircularity_isLoaded;
	vector<float> *eleID_oldr9_;
	TBranch *eleID_oldr9_branch;
	bool eleID_oldr9_isLoaded;
	vector<float> *eleID_scletawidth_;
	TBranch *eleID_scletawidth_branch;
	bool eleID_scletawidth_isLoaded;
	vector<float> *eleID_sclphiwidth_;
	TBranch *eleID_sclphiwidth_branch;
	bool eleID_sclphiwidth_isLoaded;
	vector<float> *eleID_he_;
	TBranch *eleID_he_branch;
	bool eleID_he_isLoaded;
	vector<float> *eleID_psEoverEraw_;
	TBranch *eleID_psEoverEraw_branch;
	bool eleID_psEoverEraw_isLoaded;
	vector<float> *eleID_kfchi2_;
	TBranch *eleID_kfchi2_branch;
	bool eleID_kfchi2_isLoaded;
	vector<float> *eleID_chi2_hits_;
	TBranch *eleID_chi2_hits_branch;
	bool eleID_chi2_hits_isLoaded;
	vector<float> *eleID_fbrem_;
	TBranch *eleID_fbrem_branch;
	bool eleID_fbrem_isLoaded;
	vector<float> *eleID_ep_;
	TBranch *eleID_ep_branch;
	bool eleID_ep_isLoaded;
	vector<float> *eleID_eelepout_;
	TBranch *eleID_eelepout_branch;
	bool eleID_eelepout_isLoaded;
	vector<float> *eleID_IoEmIop_;
	TBranch *eleID_IoEmIop_branch;
	bool eleID_IoEmIop_isLoaded;
	vector<float> *eleID_deltaetain_;
	TBranch *eleID_deltaetain_branch;
	bool eleID_deltaetain_isLoaded;
	vector<float> *eleID_deltaphiin_;
	TBranch *eleID_deltaphiin_branch;
	bool eleID_deltaphiin_isLoaded;
	vector<float> *eleID_deltaetaseed_;
	TBranch *eleID_deltaetaseed_branch;
	bool eleID_deltaetaseed_isLoaded;
	vector<float> *eleID_pT_;
	TBranch *eleID_pT_branch;
	bool eleID_pT_isLoaded;
	vector<bool> *eleID_isbarrel_;
	TBranch *eleID_isbarrel_branch;
	bool eleID_isbarrel_isLoaded;
	vector<bool> *eleID_isendcap_;
	TBranch *eleID_isendcap_branch;
	bool eleID_isendcap_isLoaded;
	vector<float> *eleID_scl_eta_;
	TBranch *eleID_scl_eta_branch;
	bool eleID_scl_eta_isLoaded;
	vector<float> *muID_dzPV_;
	TBranch *muID_dzPV_branch;
	bool muID_dzPV_isLoaded;
	vector<float> *muID_ptSig_;
	TBranch *muID_ptSig_branch;
	bool muID_ptSig_isLoaded;
	vector<float> *muID_ip3dSig_;
	TBranch *muID_ip3dSig_branch;
	bool muID_ip3dSig_isLoaded;
	vector<float> *muID_medMuonPOG_;
	TBranch *muID_medMuonPOG_branch;
	bool muID_medMuonPOG_isLoaded;
	vector<float> *muID_pt_;
	TBranch *muID_pt_branch;
	bool muID_pt_isLoaded;
	vector<float> *muID_eta_;
	TBranch *muID_eta_branch;
	bool muID_eta_isLoaded;
public: 
void Init(TTree *tree) {
	lep1_p4_branch = 0;
	if (tree->GetBranch("lep1_p4") != 0) {
		lep1_p4_branch = tree->GetBranch("lep1_p4");
		if (lep1_p4_branch) {lep1_p4_branch->SetAddress(&lep1_p4_);}
	}
	lep2_p4_branch = 0;
	if (tree->GetBranch("lep2_p4") != 0) {
		lep2_p4_branch = tree->GetBranch("lep2_p4");
		if (lep2_p4_branch) {lep2_p4_branch->SetAddress(&lep2_p4_);}
	}
	jets_branch = 0;
	if (tree->GetBranch("jets") != 0) {
		jets_branch = tree->GetBranch("jets");
		if (jets_branch) {jets_branch->SetAddress(&jets_);}
	}
	btags_branch = 0;
	if (tree->GetBranch("btags") != 0) {
		btags_branch = tree->GetBranch("btags");
		if (btags_branch) {btags_branch->SetAddress(&btags_);}
	}
	lep1_p4_gen_branch = 0;
	if (tree->GetBranch("lep1_p4_gen") != 0) {
		lep1_p4_gen_branch = tree->GetBranch("lep1_p4_gen");
		if (lep1_p4_gen_branch) {lep1_p4_gen_branch->SetAddress(&lep1_p4_gen_);}
	}
	lep2_p4_gen_branch = 0;
	if (tree->GetBranch("lep2_p4_gen") != 0) {
		lep2_p4_gen_branch = tree->GetBranch("lep2_p4_gen");
		if (lep2_p4_gen_branch) {lep2_p4_gen_branch->SetAddress(&lep2_p4_gen_);}
	}
	lep3_p4_branch = 0;
	if (tree->GetBranch("lep3_p4") != 0) {
		lep3_p4_branch = tree->GetBranch("lep3_p4");
		if (lep3_p4_branch) {lep3_p4_branch->SetAddress(&lep3_p4_);}
	}
	dilep_p4_branch = 0;
	if (tree->GetBranch("dilep_p4") != 0) {
		dilep_p4_branch = tree->GetBranch("dilep_p4");
		if (dilep_p4_branch) {dilep_p4_branch->SetAddress(&dilep_p4_);}
	}
	genps_p4_branch = 0;
	if (tree->GetBranch("genps_p4") != 0) {
		genps_p4_branch = tree->GetBranch("genps_p4");
		if (genps_p4_branch) {genps_p4_branch->SetAddress(&genps_p4_);}
	}
	jet_close_lep1_branch = 0;
	if (tree->GetBranch("jet_close_lep1") != 0) {
		jet_close_lep1_branch = tree->GetBranch("jet_close_lep1");
		if (jet_close_lep1_branch) {jet_close_lep1_branch->SetAddress(&jet_close_lep1_);}
	}
	jet_close_lep2_branch = 0;
	if (tree->GetBranch("jet_close_lep2") != 0) {
		jet_close_lep2_branch = tree->GetBranch("jet_close_lep2");
		if (jet_close_lep2_branch) {jet_close_lep2_branch->SetAddress(&jet_close_lep2_);}
	}
  tree->SetMakeClass(1);
	met_branch = 0;
	if (tree->GetBranch("met") != 0) {
		met_branch = tree->GetBranch("met");
		if (met_branch) {met_branch->SetAddress(&met_);}
	}
	metPhi_branch = 0;
	if (tree->GetBranch("metPhi") != 0) {
		metPhi_branch = tree->GetBranch("metPhi");
		if (metPhi_branch) {metPhi_branch->SetAddress(&metPhi_);}
	}
	event_branch = 0;
	if (tree->GetBranch("event") != 0) {
		event_branch = tree->GetBranch("event");
		if (event_branch) {event_branch->SetAddress(&event_);}
	}
	lumi_branch = 0;
	if (tree->GetBranch("lumi") != 0) {
		lumi_branch = tree->GetBranch("lumi");
		if (lumi_branch) {lumi_branch->SetAddress(&lumi_);}
	}
	run_branch = 0;
	if (tree->GetBranch("run") != 0) {
		run_branch = tree->GetBranch("run");
		if (run_branch) {run_branch->SetAddress(&run_);}
	}
	filt_csc_branch = 0;
	if (tree->GetBranch("filt_csc") != 0) {
		filt_csc_branch = tree->GetBranch("filt_csc");
		if (filt_csc_branch) {filt_csc_branch->SetAddress(&filt_csc_);}
	}
	filt_hbhe_branch = 0;
	if (tree->GetBranch("filt_hbhe") != 0) {
		filt_hbhe_branch = tree->GetBranch("filt_hbhe");
		if (filt_hbhe_branch) {filt_hbhe_branch->SetAddress(&filt_hbhe_);}
	}
	filt_hcallaser_branch = 0;
	if (tree->GetBranch("filt_hcallaser") != 0) {
		filt_hcallaser_branch = tree->GetBranch("filt_hcallaser");
		if (filt_hcallaser_branch) {filt_hcallaser_branch->SetAddress(&filt_hcallaser_);}
	}
	filt_ecaltp_branch = 0;
	if (tree->GetBranch("filt_ecaltp") != 0) {
		filt_ecaltp_branch = tree->GetBranch("filt_ecaltp");
		if (filt_ecaltp_branch) {filt_ecaltp_branch->SetAddress(&filt_ecaltp_);}
	}
	filt_trkfail_branch = 0;
	if (tree->GetBranch("filt_trkfail") != 0) {
		filt_trkfail_branch = tree->GetBranch("filt_trkfail");
		if (filt_trkfail_branch) {filt_trkfail_branch->SetAddress(&filt_trkfail_);}
	}
	filt_eebadsc_branch = 0;
	if (tree->GetBranch("filt_eebadsc") != 0) {
		filt_eebadsc_branch = tree->GetBranch("filt_eebadsc");
		if (filt_eebadsc_branch) {filt_eebadsc_branch->SetAddress(&filt_eebadsc_);}
	}
	is_real_data_branch = 0;
	if (tree->GetBranch("is_real_data") != 0) {
		is_real_data_branch = tree->GetBranch("is_real_data");
		if (is_real_data_branch) {is_real_data_branch->SetAddress(&is_real_data_);}
	}
	scale1fb_branch = 0;
	if (tree->GetBranch("scale1fb") != 0) {
		scale1fb_branch = tree->GetBranch("scale1fb");
		if (scale1fb_branch) {scale1fb_branch->SetAddress(&scale1fb_);}
	}
	xsec_branch = 0;
	if (tree->GetBranch("xsec") != 0) {
		xsec_branch = tree->GetBranch("xsec");
		if (xsec_branch) {xsec_branch->SetAddress(&xsec_);}
	}
	kfactor_branch = 0;
	if (tree->GetBranch("kfactor") != 0) {
		kfactor_branch = tree->GetBranch("kfactor");
		if (kfactor_branch) {kfactor_branch->SetAddress(&kfactor_);}
	}
	gen_met_branch = 0;
	if (tree->GetBranch("gen_met") != 0) {
		gen_met_branch = tree->GetBranch("gen_met");
		if (gen_met_branch) {gen_met_branch->SetAddress(&gen_met_);}
	}
	gen_met_phi_branch = 0;
	if (tree->GetBranch("gen_met_phi") != 0) {
		gen_met_phi_branch = tree->GetBranch("gen_met_phi");
		if (gen_met_phi_branch) {gen_met_phi_branch->SetAddress(&gen_met_phi_);}
	}
	njets_branch = 0;
	if (tree->GetBranch("njets") != 0) {
		njets_branch = tree->GetBranch("njets");
		if (njets_branch) {njets_branch->SetAddress(&njets_);}
	}
	hyp_class_branch = 0;
	if (tree->GetBranch("hyp_class") != 0) {
		hyp_class_branch = tree->GetBranch("hyp_class");
		if (hyp_class_branch) {hyp_class_branch->SetAddress(&hyp_class_);}
	}
	ht_branch = 0;
	if (tree->GetBranch("ht") != 0) {
		ht_branch = tree->GetBranch("ht");
		if (ht_branch) {ht_branch->SetAddress(&ht_);}
	}
	lep1_motherID_branch = 0;
	if (tree->GetBranch("lep1_motherID") != 0) {
		lep1_motherID_branch = tree->GetBranch("lep1_motherID");
		if (lep1_motherID_branch) {lep1_motherID_branch->SetAddress(&lep1_motherID_);}
	}
	lep2_motherID_branch = 0;
	if (tree->GetBranch("lep2_motherID") != 0) {
		lep2_motherID_branch = tree->GetBranch("lep2_motherID");
		if (lep2_motherID_branch) {lep2_motherID_branch->SetAddress(&lep2_motherID_);}
	}
	lep1_mc_id_branch = 0;
	if (tree->GetBranch("lep1_mc_id") != 0) {
		lep1_mc_id_branch = tree->GetBranch("lep1_mc_id");
		if (lep1_mc_id_branch) {lep1_mc_id_branch->SetAddress(&lep1_mc_id_);}
	}
	lep2_mc_id_branch = 0;
	if (tree->GetBranch("lep2_mc_id") != 0) {
		lep2_mc_id_branch = tree->GetBranch("lep2_mc_id");
		if (lep2_mc_id_branch) {lep2_mc_id_branch->SetAddress(&lep2_mc_id_);}
	}
	lep1_id_branch = 0;
	if (tree->GetBranch("lep1_id") != 0) {
		lep1_id_branch = tree->GetBranch("lep1_id");
		if (lep1_id_branch) {lep1_id_branch->SetAddress(&lep1_id_);}
	}
	lep2_id_branch = 0;
	if (tree->GetBranch("lep2_id") != 0) {
		lep2_id_branch = tree->GetBranch("lep2_id");
		if (lep2_id_branch) {lep2_id_branch->SetAddress(&lep2_id_);}
	}
	lep1_idx_branch = 0;
	if (tree->GetBranch("lep1_idx") != 0) {
		lep1_idx_branch = tree->GetBranch("lep1_idx");
		if (lep1_idx_branch) {lep1_idx_branch->SetAddress(&lep1_idx_);}
	}
	lep2_idx_branch = 0;
	if (tree->GetBranch("lep2_idx") != 0) {
		lep2_idx_branch = tree->GetBranch("lep2_idx");
		if (lep2_idx_branch) {lep2_idx_branch->SetAddress(&lep2_idx_);}
	}
	btags_disc_branch = 0;
	if (tree->GetBranch("btags_disc") != 0) {
		btags_disc_branch = tree->GetBranch("btags_disc");
		if (btags_disc_branch) {btags_disc_branch->SetAddress(&btags_disc_);}
	}
	jets_disc_branch = 0;
	if (tree->GetBranch("jets_disc") != 0) {
		jets_disc_branch = tree->GetBranch("jets_disc");
		if (jets_disc_branch) {jets_disc_branch->SetAddress(&jets_disc_);}
	}
	nbtags_branch = 0;
	if (tree->GetBranch("nbtags") != 0) {
		nbtags_branch = tree->GetBranch("nbtags");
		if (nbtags_branch) {nbtags_branch->SetAddress(&nbtags_);}
	}
	sf_dilepTrig_hpt_branch = 0;
	if (tree->GetBranch("sf_dilepTrig_hpt") != 0) {
		sf_dilepTrig_hpt_branch = tree->GetBranch("sf_dilepTrig_hpt");
		if (sf_dilepTrig_hpt_branch) {sf_dilepTrig_hpt_branch->SetAddress(&sf_dilepTrig_hpt_);}
	}
	sf_dilepTrig_lpt_branch = 0;
	if (tree->GetBranch("sf_dilepTrig_lpt") != 0) {
		sf_dilepTrig_lpt_branch = tree->GetBranch("sf_dilepTrig_lpt");
		if (sf_dilepTrig_lpt_branch) {sf_dilepTrig_lpt_branch->SetAddress(&sf_dilepTrig_lpt_);}
	}
	sf_dilepTrig_vlpt_branch = 0;
	if (tree->GetBranch("sf_dilepTrig_vlpt") != 0) {
		sf_dilepTrig_vlpt_branch = tree->GetBranch("sf_dilepTrig_vlpt");
		if (sf_dilepTrig_vlpt_branch) {sf_dilepTrig_vlpt_branch->SetAddress(&sf_dilepTrig_vlpt_);}
	}
	hyp_type_branch = 0;
	if (tree->GetBranch("hyp_type") != 0) {
		hyp_type_branch = tree->GetBranch("hyp_type");
		if (hyp_type_branch) {hyp_type_branch->SetAddress(&hyp_type_);}
	}
	sf_dilep_eff_branch = 0;
	if (tree->GetBranch("sf_dilep_eff") != 0) {
		sf_dilep_eff_branch = tree->GetBranch("sf_dilep_eff");
		if (sf_dilep_eff_branch) {sf_dilep_eff_branch->SetAddress(&sf_dilep_eff_);}
	}
	mt_branch = 0;
	if (tree->GetBranch("mt") != 0) {
		mt_branch = tree->GetBranch("mt");
		if (mt_branch) {mt_branch->SetAddress(&mt_);}
	}
	mt_l2_branch = 0;
	if (tree->GetBranch("mt_l2") != 0) {
		mt_l2_branch = tree->GetBranch("mt_l2");
		if (mt_l2_branch) {mt_l2_branch->SetAddress(&mt_l2_);}
	}
	mt2_branch = 0;
	if (tree->GetBranch("mt2") != 0) {
		mt2_branch = tree->GetBranch("mt2");
		if (mt2_branch) {mt2_branch->SetAddress(&mt2_);}
	}
	mGluino_branch = 0;
	if (tree->GetBranch("mGluino") != 0) {
		mGluino_branch = tree->GetBranch("mGluino");
		if (mGluino_branch) {mGluino_branch->SetAddress(&mGluino_);}
	}
	mLSP_branch = 0;
	if (tree->GetBranch("mLSP") != 0) {
		mLSP_branch = tree->GetBranch("mLSP");
		if (mLSP_branch) {mLSP_branch->SetAddress(&mLSP_);}
	}
	mSbottom_branch = 0;
	if (tree->GetBranch("mSbottom") != 0) {
		mSbottom_branch = tree->GetBranch("mSbottom");
		if (mSbottom_branch) {mSbottom_branch->SetAddress(&mSbottom_);}
	}
	mChargino_branch = 0;
	if (tree->GetBranch("mChargino") != 0) {
		mChargino_branch = tree->GetBranch("mChargino");
		if (mChargino_branch) {mChargino_branch->SetAddress(&mChargino_);}
	}
	lep1_id_gen_branch = 0;
	if (tree->GetBranch("lep1_id_gen") != 0) {
		lep1_id_gen_branch = tree->GetBranch("lep1_id_gen");
		if (lep1_id_gen_branch) {lep1_id_gen_branch->SetAddress(&lep1_id_gen_);}
	}
	lep2_id_gen_branch = 0;
	if (tree->GetBranch("lep2_id_gen") != 0) {
		lep2_id_gen_branch = tree->GetBranch("lep2_id_gen");
		if (lep2_id_gen_branch) {lep2_id_gen_branch->SetAddress(&lep2_id_gen_);}
	}
	lep3_id_branch = 0;
	if (tree->GetBranch("lep3_id") != 0) {
		lep3_id_branch = tree->GetBranch("lep3_id");
		if (lep3_id_branch) {lep3_id_branch->SetAddress(&lep3_id_);}
	}
	lep3_idx_branch = 0;
	if (tree->GetBranch("lep3_idx") != 0) {
		lep3_idx_branch = tree->GetBranch("lep3_idx");
		if (lep3_idx_branch) {lep3_idx_branch->SetAddress(&lep3_idx_);}
	}
	lep3_quality_branch = 0;
	if (tree->GetBranch("lep3_quality") != 0) {
		lep3_quality_branch = tree->GetBranch("lep3_quality");
		if (lep3_quality_branch) {lep3_quality_branch->SetAddress(&lep3_quality_);}
	}
	lep1_iso_branch = 0;
	if (tree->GetBranch("lep1_iso") != 0) {
		lep1_iso_branch = tree->GetBranch("lep1_iso");
		if (lep1_iso_branch) {lep1_iso_branch->SetAddress(&lep1_iso_);}
	}
	lep2_iso_branch = 0;
	if (tree->GetBranch("lep2_iso") != 0) {
		lep2_iso_branch = tree->GetBranch("lep2_iso");
		if (lep2_iso_branch) {lep2_iso_branch->SetAddress(&lep2_iso_);}
	}
	genps_id_branch = 0;
	if (tree->GetBranch("genps_id") != 0) {
		genps_id_branch = tree->GetBranch("genps_id");
		if (genps_id_branch) {genps_id_branch->SetAddress(&genps_id_);}
	}
	genps_id_mother_branch = 0;
	if (tree->GetBranch("genps_id_mother") != 0) {
		genps_id_mother_branch = tree->GetBranch("genps_id_mother");
		if (genps_id_mother_branch) {genps_id_mother_branch->SetAddress(&genps_id_mother_);}
	}
	genps_status_branch = 0;
	if (tree->GetBranch("genps_status") != 0) {
		genps_status_branch = tree->GetBranch("genps_status");
		if (genps_status_branch) {genps_status_branch->SetAddress(&genps_status_);}
	}
	genps_id_grandma_branch = 0;
	if (tree->GetBranch("genps_id_grandma") != 0) {
		genps_id_grandma_branch = tree->GetBranch("genps_id_grandma");
		if (genps_id_grandma_branch) {genps_id_grandma_branch->SetAddress(&genps_id_grandma_);}
	}
	lep1_passes_id_branch = 0;
	if (tree->GetBranch("lep1_passes_id") != 0) {
		lep1_passes_id_branch = tree->GetBranch("lep1_passes_id");
		if (lep1_passes_id_branch) {lep1_passes_id_branch->SetAddress(&lep1_passes_id_);}
	}
	lep2_passes_id_branch = 0;
	if (tree->GetBranch("lep2_passes_id") != 0) {
		lep2_passes_id_branch = tree->GetBranch("lep2_passes_id");
		if (lep2_passes_id_branch) {lep2_passes_id_branch->SetAddress(&lep2_passes_id_);}
	}
	lep1_dxyPV_branch = 0;
	if (tree->GetBranch("lep1_dxyPV") != 0) {
		lep1_dxyPV_branch = tree->GetBranch("lep1_dxyPV");
		if (lep1_dxyPV_branch) {lep1_dxyPV_branch->SetAddress(&lep1_dxyPV_);}
	}
	lep2_dxyPV_branch = 0;
	if (tree->GetBranch("lep2_dxyPV") != 0) {
		lep2_dxyPV_branch = tree->GetBranch("lep2_dxyPV");
		if (lep2_dxyPV_branch) {lep2_dxyPV_branch->SetAddress(&lep2_dxyPV_);}
	}
	lep1_dZ_branch = 0;
	if (tree->GetBranch("lep1_dZ") != 0) {
		lep1_dZ_branch = tree->GetBranch("lep1_dZ");
		if (lep1_dZ_branch) {lep1_dZ_branch->SetAddress(&lep1_dZ_);}
	}
	lep2_dZ_branch = 0;
	if (tree->GetBranch("lep2_dZ") != 0) {
		lep2_dZ_branch = tree->GetBranch("lep2_dZ");
		if (lep2_dZ_branch) {lep2_dZ_branch->SetAddress(&lep2_dZ_);}
	}
	lep1_d0_err_branch = 0;
	if (tree->GetBranch("lep1_d0_err") != 0) {
		lep1_d0_err_branch = tree->GetBranch("lep1_d0_err");
		if (lep1_d0_err_branch) {lep1_d0_err_branch->SetAddress(&lep1_d0_err_);}
	}
	lep2_d0_err_branch = 0;
	if (tree->GetBranch("lep2_d0_err") != 0) {
		lep2_d0_err_branch = tree->GetBranch("lep2_d0_err");
		if (lep2_d0_err_branch) {lep2_d0_err_branch->SetAddress(&lep2_d0_err_);}
	}
	lep1_ip3d_branch = 0;
	if (tree->GetBranch("lep1_ip3d") != 0) {
		lep1_ip3d_branch = tree->GetBranch("lep1_ip3d");
		if (lep1_ip3d_branch) {lep1_ip3d_branch->SetAddress(&lep1_ip3d_);}
	}
	lep2_ip3d_branch = 0;
	if (tree->GetBranch("lep2_ip3d") != 0) {
		lep2_ip3d_branch = tree->GetBranch("lep2_ip3d");
		if (lep2_ip3d_branch) {lep2_ip3d_branch->SetAddress(&lep2_ip3d_);}
	}
	lep1_ip3d_err_branch = 0;
	if (tree->GetBranch("lep1_ip3d_err") != 0) {
		lep1_ip3d_err_branch = tree->GetBranch("lep1_ip3d_err");
		if (lep1_ip3d_err_branch) {lep1_ip3d_err_branch->SetAddress(&lep1_ip3d_err_);}
	}
	lep2_ip3d_err_branch = 0;
	if (tree->GetBranch("lep2_ip3d_err") != 0) {
		lep2_ip3d_err_branch = tree->GetBranch("lep2_ip3d_err");
		if (lep2_ip3d_err_branch) {lep2_ip3d_err_branch->SetAddress(&lep2_ip3d_err_);}
	}
	nVetoElectrons7_branch = 0;
	if (tree->GetBranch("nVetoElectrons7") != 0) {
		nVetoElectrons7_branch = tree->GetBranch("nVetoElectrons7");
		if (nVetoElectrons7_branch) {nVetoElectrons7_branch->SetAddress(&nVetoElectrons7_);}
	}
	nVetoElectrons10_branch = 0;
	if (tree->GetBranch("nVetoElectrons10") != 0) {
		nVetoElectrons10_branch = tree->GetBranch("nVetoElectrons10");
		if (nVetoElectrons10_branch) {nVetoElectrons10_branch->SetAddress(&nVetoElectrons10_);}
	}
	nVetoElectrons25_branch = 0;
	if (tree->GetBranch("nVetoElectrons25") != 0) {
		nVetoElectrons25_branch = tree->GetBranch("nVetoElectrons25");
		if (nVetoElectrons25_branch) {nVetoElectrons25_branch->SetAddress(&nVetoElectrons25_);}
	}
	nVetoMuons5_branch = 0;
	if (tree->GetBranch("nVetoMuons5") != 0) {
		nVetoMuons5_branch = tree->GetBranch("nVetoMuons5");
		if (nVetoMuons5_branch) {nVetoMuons5_branch->SetAddress(&nVetoMuons5_);}
	}
	nVetoMuons10_branch = 0;
	if (tree->GetBranch("nVetoMuons10") != 0) {
		nVetoMuons10_branch = tree->GetBranch("nVetoMuons10");
		if (nVetoMuons10_branch) {nVetoMuons10_branch->SetAddress(&nVetoMuons10_);}
	}
	nVetoMuons25_branch = 0;
	if (tree->GetBranch("nVetoMuons25") != 0) {
		nVetoMuons25_branch = tree->GetBranch("nVetoMuons25");
		if (nVetoMuons25_branch) {nVetoMuons25_branch->SetAddress(&nVetoMuons25_);}
	}
	filename_branch = 0;
	if (tree->GetBranch("filename") != 0) {
		filename_branch = tree->GetBranch("filename");
		if (filename_branch) {filename_branch->SetAddress(&filename_);}
	}
	lep1_ptrel_v0_branch = 0;
	if (tree->GetBranch("lep1_ptrel_v0") != 0) {
		lep1_ptrel_v0_branch = tree->GetBranch("lep1_ptrel_v0");
		if (lep1_ptrel_v0_branch) {lep1_ptrel_v0_branch->SetAddress(&lep1_ptrel_v0_);}
	}
	lep1_ptrel_v1_branch = 0;
	if (tree->GetBranch("lep1_ptrel_v1") != 0) {
		lep1_ptrel_v1_branch = tree->GetBranch("lep1_ptrel_v1");
		if (lep1_ptrel_v1_branch) {lep1_ptrel_v1_branch->SetAddress(&lep1_ptrel_v1_);}
	}
	lep2_ptrel_v0_branch = 0;
	if (tree->GetBranch("lep2_ptrel_v0") != 0) {
		lep2_ptrel_v0_branch = tree->GetBranch("lep2_ptrel_v0");
		if (lep2_ptrel_v0_branch) {lep2_ptrel_v0_branch->SetAddress(&lep2_ptrel_v0_);}
	}
	lep2_ptrel_v1_branch = 0;
	if (tree->GetBranch("lep2_ptrel_v1") != 0) {
		lep2_ptrel_v1_branch = tree->GetBranch("lep2_ptrel_v1");
		if (lep2_ptrel_v1_branch) {lep2_ptrel_v1_branch->SetAddress(&lep2_ptrel_v1_);}
	}
	lep1_miniIso_branch = 0;
	if (tree->GetBranch("lep1_miniIso") != 0) {
		lep1_miniIso_branch = tree->GetBranch("lep1_miniIso");
		if (lep1_miniIso_branch) {lep1_miniIso_branch->SetAddress(&lep1_miniIso_);}
	}
	lep2_miniIso_branch = 0;
	if (tree->GetBranch("lep2_miniIso") != 0) {
		lep2_miniIso_branch = tree->GetBranch("lep2_miniIso");
		if (lep2_miniIso_branch) {lep2_miniIso_branch->SetAddress(&lep2_miniIso_);}
	}
	eleID_kfhits_branch = 0;
	if (tree->GetBranch("eleID_kfhits") != 0) {
		eleID_kfhits_branch = tree->GetBranch("eleID_kfhits");
		if (eleID_kfhits_branch) {eleID_kfhits_branch->SetAddress(&eleID_kfhits_);}
	}
	eleID_oldsigmaietaieta_branch = 0;
	if (tree->GetBranch("eleID_oldsigmaietaieta") != 0) {
		eleID_oldsigmaietaieta_branch = tree->GetBranch("eleID_oldsigmaietaieta");
		if (eleID_oldsigmaietaieta_branch) {eleID_oldsigmaietaieta_branch->SetAddress(&eleID_oldsigmaietaieta_);}
	}
	eleID_oldsigmaiphiiphi_branch = 0;
	if (tree->GetBranch("eleID_oldsigmaiphiiphi") != 0) {
		eleID_oldsigmaiphiiphi_branch = tree->GetBranch("eleID_oldsigmaiphiiphi");
		if (eleID_oldsigmaiphiiphi_branch) {eleID_oldsigmaiphiiphi_branch->SetAddress(&eleID_oldsigmaiphiiphi_);}
	}
	eleID_oldcircularity_branch = 0;
	if (tree->GetBranch("eleID_oldcircularity") != 0) {
		eleID_oldcircularity_branch = tree->GetBranch("eleID_oldcircularity");
		if (eleID_oldcircularity_branch) {eleID_oldcircularity_branch->SetAddress(&eleID_oldcircularity_);}
	}
	eleID_oldr9_branch = 0;
	if (tree->GetBranch("eleID_oldr9") != 0) {
		eleID_oldr9_branch = tree->GetBranch("eleID_oldr9");
		if (eleID_oldr9_branch) {eleID_oldr9_branch->SetAddress(&eleID_oldr9_);}
	}
	eleID_scletawidth_branch = 0;
	if (tree->GetBranch("eleID_scletawidth") != 0) {
		eleID_scletawidth_branch = tree->GetBranch("eleID_scletawidth");
		if (eleID_scletawidth_branch) {eleID_scletawidth_branch->SetAddress(&eleID_scletawidth_);}
	}
	eleID_sclphiwidth_branch = 0;
	if (tree->GetBranch("eleID_sclphiwidth") != 0) {
		eleID_sclphiwidth_branch = tree->GetBranch("eleID_sclphiwidth");
		if (eleID_sclphiwidth_branch) {eleID_sclphiwidth_branch->SetAddress(&eleID_sclphiwidth_);}
	}
	eleID_he_branch = 0;
	if (tree->GetBranch("eleID_he") != 0) {
		eleID_he_branch = tree->GetBranch("eleID_he");
		if (eleID_he_branch) {eleID_he_branch->SetAddress(&eleID_he_);}
	}
	eleID_psEoverEraw_branch = 0;
	if (tree->GetBranch("eleID_psEoverEraw") != 0) {
		eleID_psEoverEraw_branch = tree->GetBranch("eleID_psEoverEraw");
		if (eleID_psEoverEraw_branch) {eleID_psEoverEraw_branch->SetAddress(&eleID_psEoverEraw_);}
	}
	eleID_kfchi2_branch = 0;
	if (tree->GetBranch("eleID_kfchi2   ") != 0) {
		eleID_kfchi2_branch = tree->GetBranch("eleID_kfchi2   ");
		if (eleID_kfchi2_branch) {eleID_kfchi2_branch->SetAddress(&eleID_kfchi2_);}
	}
	eleID_chi2_hits_branch = 0;
	if (tree->GetBranch("eleID_chi2_hits") != 0) {
		eleID_chi2_hits_branch = tree->GetBranch("eleID_chi2_hits");
		if (eleID_chi2_hits_branch) {eleID_chi2_hits_branch->SetAddress(&eleID_chi2_hits_);}
	}
	eleID_fbrem_branch = 0;
	if (tree->GetBranch("eleID_fbrem") != 0) {
		eleID_fbrem_branch = tree->GetBranch("eleID_fbrem");
		if (eleID_fbrem_branch) {eleID_fbrem_branch->SetAddress(&eleID_fbrem_);}
	}
	eleID_ep_branch = 0;
	if (tree->GetBranch("eleID_ep") != 0) {
		eleID_ep_branch = tree->GetBranch("eleID_ep");
		if (eleID_ep_branch) {eleID_ep_branch->SetAddress(&eleID_ep_);}
	}
	eleID_eelepout_branch = 0;
	if (tree->GetBranch("eleID_eelepout") != 0) {
		eleID_eelepout_branch = tree->GetBranch("eleID_eelepout");
		if (eleID_eelepout_branch) {eleID_eelepout_branch->SetAddress(&eleID_eelepout_);}
	}
	eleID_IoEmIop_branch = 0;
	if (tree->GetBranch("eleID_IoEmIop") != 0) {
		eleID_IoEmIop_branch = tree->GetBranch("eleID_IoEmIop");
		if (eleID_IoEmIop_branch) {eleID_IoEmIop_branch->SetAddress(&eleID_IoEmIop_);}
	}
	eleID_deltaetain_branch = 0;
	if (tree->GetBranch("eleID_deltaetain") != 0) {
		eleID_deltaetain_branch = tree->GetBranch("eleID_deltaetain");
		if (eleID_deltaetain_branch) {eleID_deltaetain_branch->SetAddress(&eleID_deltaetain_);}
	}
	eleID_deltaphiin_branch = 0;
	if (tree->GetBranch("eleID_deltaphiin") != 0) {
		eleID_deltaphiin_branch = tree->GetBranch("eleID_deltaphiin");
		if (eleID_deltaphiin_branch) {eleID_deltaphiin_branch->SetAddress(&eleID_deltaphiin_);}
	}
	eleID_deltaetaseed_branch = 0;
	if (tree->GetBranch("eleID_deltaetaseed") != 0) {
		eleID_deltaetaseed_branch = tree->GetBranch("eleID_deltaetaseed");
		if (eleID_deltaetaseed_branch) {eleID_deltaetaseed_branch->SetAddress(&eleID_deltaetaseed_);}
	}
	eleID_pT_branch = 0;
	if (tree->GetBranch("eleID_pT") != 0) {
		eleID_pT_branch = tree->GetBranch("eleID_pT");
		if (eleID_pT_branch) {eleID_pT_branch->SetAddress(&eleID_pT_);}
	}
	eleID_isbarrel_branch = 0;
	if (tree->GetBranch("eleID_isbarrel") != 0) {
		eleID_isbarrel_branch = tree->GetBranch("eleID_isbarrel");
		if (eleID_isbarrel_branch) {eleID_isbarrel_branch->SetAddress(&eleID_isbarrel_);}
	}
	eleID_isendcap_branch = 0;
	if (tree->GetBranch("eleID_isendcap") != 0) {
		eleID_isendcap_branch = tree->GetBranch("eleID_isendcap");
		if (eleID_isendcap_branch) {eleID_isendcap_branch->SetAddress(&eleID_isendcap_);}
	}
	eleID_scl_eta_branch = 0;
	if (tree->GetBranch("eleID_scl_eta") != 0) {
		eleID_scl_eta_branch = tree->GetBranch("eleID_scl_eta");
		if (eleID_scl_eta_branch) {eleID_scl_eta_branch->SetAddress(&eleID_scl_eta_);}
	}
	muID_dzPV_branch = 0;
	if (tree->GetBranch("muID_dzPV") != 0) {
		muID_dzPV_branch = tree->GetBranch("muID_dzPV");
		if (muID_dzPV_branch) {muID_dzPV_branch->SetAddress(&muID_dzPV_);}
	}
	muID_ptSig_branch = 0;
	if (tree->GetBranch("muID_ptSig") != 0) {
		muID_ptSig_branch = tree->GetBranch("muID_ptSig");
		if (muID_ptSig_branch) {muID_ptSig_branch->SetAddress(&muID_ptSig_);}
	}
	muID_ip3dSig_branch = 0;
	if (tree->GetBranch("muID_ip3dSig") != 0) {
		muID_ip3dSig_branch = tree->GetBranch("muID_ip3dSig");
		if (muID_ip3dSig_branch) {muID_ip3dSig_branch->SetAddress(&muID_ip3dSig_);}
	}
	muID_medMuonPOG_branch = 0;
	if (tree->GetBranch("muID_medMuonPOG") != 0) {
		muID_medMuonPOG_branch = tree->GetBranch("muID_medMuonPOG");
		if (muID_medMuonPOG_branch) {muID_medMuonPOG_branch->SetAddress(&muID_medMuonPOG_);}
	}
	muID_pt_branch = 0;
	if (tree->GetBranch("muID_pt") != 0) {
		muID_pt_branch = tree->GetBranch("muID_pt");
		if (muID_pt_branch) {muID_pt_branch->SetAddress(&muID_pt_);}
	}
	muID_eta_branch = 0;
	if (tree->GetBranch("muID_eta") != 0) {
		muID_eta_branch = tree->GetBranch("muID_eta");
		if (muID_eta_branch) {muID_eta_branch->SetAddress(&muID_eta_);}
	}
  tree->SetMakeClass(0);
}
void GetEntry(unsigned int idx) 
	// this only marks branches as not loaded, saving a lot of time
	{
		index = idx;
		met_isLoaded = false;
		metPhi_isLoaded = false;
		event_isLoaded = false;
		lumi_isLoaded = false;
		run_isLoaded = false;
		filt_csc_isLoaded = false;
		filt_hbhe_isLoaded = false;
		filt_hcallaser_isLoaded = false;
		filt_ecaltp_isLoaded = false;
		filt_trkfail_isLoaded = false;
		filt_eebadsc_isLoaded = false;
		is_real_data_isLoaded = false;
		scale1fb_isLoaded = false;
		xsec_isLoaded = false;
		kfactor_isLoaded = false;
		gen_met_isLoaded = false;
		gen_met_phi_isLoaded = false;
		njets_isLoaded = false;
		hyp_class_isLoaded = false;
		lep1_p4_isLoaded = false;
		lep2_p4_isLoaded = false;
		ht_isLoaded = false;
		lep1_motherID_isLoaded = false;
		lep2_motherID_isLoaded = false;
		lep1_mc_id_isLoaded = false;
		lep2_mc_id_isLoaded = false;
		lep1_id_isLoaded = false;
		lep2_id_isLoaded = false;
		lep1_idx_isLoaded = false;
		lep2_idx_isLoaded = false;
		jets_isLoaded = false;
		btags_disc_isLoaded = false;
		jets_disc_isLoaded = false;
		btags_isLoaded = false;
		nbtags_isLoaded = false;
		sf_dilepTrig_hpt_isLoaded = false;
		sf_dilepTrig_lpt_isLoaded = false;
		sf_dilepTrig_vlpt_isLoaded = false;
		hyp_type_isLoaded = false;
		sf_dilep_eff_isLoaded = false;
		mt_isLoaded = false;
		mt_l2_isLoaded = false;
		mt2_isLoaded = false;
		mGluino_isLoaded = false;
		mLSP_isLoaded = false;
		mSbottom_isLoaded = false;
		mChargino_isLoaded = false;
		lep1_id_gen_isLoaded = false;
		lep2_id_gen_isLoaded = false;
		lep1_p4_gen_isLoaded = false;
		lep2_p4_gen_isLoaded = false;
		lep3_id_isLoaded = false;
		lep3_idx_isLoaded = false;
		lep3_p4_isLoaded = false;
		lep3_quality_isLoaded = false;
		lep1_iso_isLoaded = false;
		lep2_iso_isLoaded = false;
		dilep_p4_isLoaded = false;
		genps_p4_isLoaded = false;
		genps_id_isLoaded = false;
		genps_id_mother_isLoaded = false;
		genps_status_isLoaded = false;
		genps_id_grandma_isLoaded = false;
		lep1_passes_id_isLoaded = false;
		lep2_passes_id_isLoaded = false;
		lep1_dxyPV_isLoaded = false;
		lep2_dxyPV_isLoaded = false;
		lep1_dZ_isLoaded = false;
		lep2_dZ_isLoaded = false;
		lep1_d0_err_isLoaded = false;
		lep2_d0_err_isLoaded = false;
		lep1_ip3d_isLoaded = false;
		lep2_ip3d_isLoaded = false;
		lep1_ip3d_err_isLoaded = false;
		lep2_ip3d_err_isLoaded = false;
		nVetoElectrons7_isLoaded = false;
		nVetoElectrons10_isLoaded = false;
		nVetoElectrons25_isLoaded = false;
		nVetoMuons5_isLoaded = false;
		nVetoMuons10_isLoaded = false;
		nVetoMuons25_isLoaded = false;
		filename_isLoaded = false;
		lep1_ptrel_v0_isLoaded = false;
		lep1_ptrel_v1_isLoaded = false;
		lep2_ptrel_v0_isLoaded = false;
		lep2_ptrel_v1_isLoaded = false;
		lep1_miniIso_isLoaded = false;
		lep2_miniIso_isLoaded = false;
		jet_close_lep1_isLoaded = false;
		jet_close_lep2_isLoaded = false;
		eleID_kfhits_isLoaded = false;
		eleID_oldsigmaietaieta_isLoaded = false;
		eleID_oldsigmaiphiiphi_isLoaded = false;
		eleID_oldcircularity_isLoaded = false;
		eleID_oldr9_isLoaded = false;
		eleID_scletawidth_isLoaded = false;
		eleID_sclphiwidth_isLoaded = false;
		eleID_he_isLoaded = false;
		eleID_psEoverEraw_isLoaded = false;
		eleID_kfchi2_isLoaded = false;
		eleID_chi2_hits_isLoaded = false;
		eleID_fbrem_isLoaded = false;
		eleID_ep_isLoaded = false;
		eleID_eelepout_isLoaded = false;
		eleID_IoEmIop_isLoaded = false;
		eleID_deltaetain_isLoaded = false;
		eleID_deltaphiin_isLoaded = false;
		eleID_deltaetaseed_isLoaded = false;
		eleID_pT_isLoaded = false;
		eleID_isbarrel_isLoaded = false;
		eleID_isendcap_isLoaded = false;
		eleID_scl_eta_isLoaded = false;
		muID_dzPV_isLoaded = false;
		muID_ptSig_isLoaded = false;
		muID_ip3dSig_isLoaded = false;
		muID_medMuonPOG_isLoaded = false;
		muID_pt_isLoaded = false;
		muID_eta_isLoaded = false;
	}

void LoadAllBranches() 
	// load all branches
{
	if (met_branch != 0) met();
	if (metPhi_branch != 0) metPhi();
	if (event_branch != 0) event();
	if (lumi_branch != 0) lumi();
	if (run_branch != 0) run();
	if (filt_csc_branch != 0) filt_csc();
	if (filt_hbhe_branch != 0) filt_hbhe();
	if (filt_hcallaser_branch != 0) filt_hcallaser();
	if (filt_ecaltp_branch != 0) filt_ecaltp();
	if (filt_trkfail_branch != 0) filt_trkfail();
	if (filt_eebadsc_branch != 0) filt_eebadsc();
	if (is_real_data_branch != 0) is_real_data();
	if (scale1fb_branch != 0) scale1fb();
	if (xsec_branch != 0) xsec();
	if (kfactor_branch != 0) kfactor();
	if (gen_met_branch != 0) gen_met();
	if (gen_met_phi_branch != 0) gen_met_phi();
	if (njets_branch != 0) njets();
	if (hyp_class_branch != 0) hyp_class();
	if (lep1_p4_branch != 0) lep1_p4();
	if (lep2_p4_branch != 0) lep2_p4();
	if (ht_branch != 0) ht();
	if (lep1_motherID_branch != 0) lep1_motherID();
	if (lep2_motherID_branch != 0) lep2_motherID();
	if (lep1_mc_id_branch != 0) lep1_mc_id();
	if (lep2_mc_id_branch != 0) lep2_mc_id();
	if (lep1_id_branch != 0) lep1_id();
	if (lep2_id_branch != 0) lep2_id();
	if (lep1_idx_branch != 0) lep1_idx();
	if (lep2_idx_branch != 0) lep2_idx();
	if (jets_branch != 0) jets();
	if (btags_disc_branch != 0) btags_disc();
	if (jets_disc_branch != 0) jets_disc();
	if (btags_branch != 0) btags();
	if (nbtags_branch != 0) nbtags();
	if (sf_dilepTrig_hpt_branch != 0) sf_dilepTrig_hpt();
	if (sf_dilepTrig_lpt_branch != 0) sf_dilepTrig_lpt();
	if (sf_dilepTrig_vlpt_branch != 0) sf_dilepTrig_vlpt();
	if (hyp_type_branch != 0) hyp_type();
	if (sf_dilep_eff_branch != 0) sf_dilep_eff();
	if (mt_branch != 0) mt();
	if (mt_l2_branch != 0) mt_l2();
	if (mt2_branch != 0) mt2();
	if (mGluino_branch != 0) mGluino();
	if (mLSP_branch != 0) mLSP();
	if (mSbottom_branch != 0) mSbottom();
	if (mChargino_branch != 0) mChargino();
	if (lep1_id_gen_branch != 0) lep1_id_gen();
	if (lep2_id_gen_branch != 0) lep2_id_gen();
	if (lep1_p4_gen_branch != 0) lep1_p4_gen();
	if (lep2_p4_gen_branch != 0) lep2_p4_gen();
	if (lep3_id_branch != 0) lep3_id();
	if (lep3_idx_branch != 0) lep3_idx();
	if (lep3_p4_branch != 0) lep3_p4();
	if (lep3_quality_branch != 0) lep3_quality();
	if (lep1_iso_branch != 0) lep1_iso();
	if (lep2_iso_branch != 0) lep2_iso();
	if (dilep_p4_branch != 0) dilep_p4();
	if (genps_p4_branch != 0) genps_p4();
	if (genps_id_branch != 0) genps_id();
	if (genps_id_mother_branch != 0) genps_id_mother();
	if (genps_status_branch != 0) genps_status();
	if (genps_id_grandma_branch != 0) genps_id_grandma();
	if (lep1_passes_id_branch != 0) lep1_passes_id();
	if (lep2_passes_id_branch != 0) lep2_passes_id();
	if (lep1_dxyPV_branch != 0) lep1_dxyPV();
	if (lep2_dxyPV_branch != 0) lep2_dxyPV();
	if (lep1_dZ_branch != 0) lep1_dZ();
	if (lep2_dZ_branch != 0) lep2_dZ();
	if (lep1_d0_err_branch != 0) lep1_d0_err();
	if (lep2_d0_err_branch != 0) lep2_d0_err();
	if (lep1_ip3d_branch != 0) lep1_ip3d();
	if (lep2_ip3d_branch != 0) lep2_ip3d();
	if (lep1_ip3d_err_branch != 0) lep1_ip3d_err();
	if (lep2_ip3d_err_branch != 0) lep2_ip3d_err();
	if (nVetoElectrons7_branch != 0) nVetoElectrons7();
	if (nVetoElectrons10_branch != 0) nVetoElectrons10();
	if (nVetoElectrons25_branch != 0) nVetoElectrons25();
	if (nVetoMuons5_branch != 0) nVetoMuons5();
	if (nVetoMuons10_branch != 0) nVetoMuons10();
	if (nVetoMuons25_branch != 0) nVetoMuons25();
	if (filename_branch != 0) filename();
	if (lep1_ptrel_v0_branch != 0) lep1_ptrel_v0();
	if (lep1_ptrel_v1_branch != 0) lep1_ptrel_v1();
	if (lep2_ptrel_v0_branch != 0) lep2_ptrel_v0();
	if (lep2_ptrel_v1_branch != 0) lep2_ptrel_v1();
	if (lep1_miniIso_branch != 0) lep1_miniIso();
	if (lep2_miniIso_branch != 0) lep2_miniIso();
	if (jet_close_lep1_branch != 0) jet_close_lep1();
	if (jet_close_lep2_branch != 0) jet_close_lep2();
	if (eleID_kfhits_branch != 0) eleID_kfhits();
	if (eleID_oldsigmaietaieta_branch != 0) eleID_oldsigmaietaieta();
	if (eleID_oldsigmaiphiiphi_branch != 0) eleID_oldsigmaiphiiphi();
	if (eleID_oldcircularity_branch != 0) eleID_oldcircularity();
	if (eleID_oldr9_branch != 0) eleID_oldr9();
	if (eleID_scletawidth_branch != 0) eleID_scletawidth();
	if (eleID_sclphiwidth_branch != 0) eleID_sclphiwidth();
	if (eleID_he_branch != 0) eleID_he();
	if (eleID_psEoverEraw_branch != 0) eleID_psEoverEraw();
	if (eleID_kfchi2_branch != 0) eleID_kfchi2();
	if (eleID_chi2_hits_branch != 0) eleID_chi2_hits();
	if (eleID_fbrem_branch != 0) eleID_fbrem();
	if (eleID_ep_branch != 0) eleID_ep();
	if (eleID_eelepout_branch != 0) eleID_eelepout();
	if (eleID_IoEmIop_branch != 0) eleID_IoEmIop();
	if (eleID_deltaetain_branch != 0) eleID_deltaetain();
	if (eleID_deltaphiin_branch != 0) eleID_deltaphiin();
	if (eleID_deltaetaseed_branch != 0) eleID_deltaetaseed();
	if (eleID_pT_branch != 0) eleID_pT();
	if (eleID_isbarrel_branch != 0) eleID_isbarrel();
	if (eleID_isendcap_branch != 0) eleID_isendcap();
	if (eleID_scl_eta_branch != 0) eleID_scl_eta();
	if (muID_dzPV_branch != 0) muID_dzPV();
	if (muID_ptSig_branch != 0) muID_ptSig();
	if (muID_ip3dSig_branch != 0) muID_ip3dSig();
	if (muID_medMuonPOG_branch != 0) muID_medMuonPOG();
	if (muID_pt_branch != 0) muID_pt();
	if (muID_eta_branch != 0) muID_eta();
}

	float &met()
	{
		if (not met_isLoaded) {
			if (met_branch != 0) {
				met_branch->GetEntry(index);
			} else { 
				printf("branch met_branch does not exist!\n");
				exit(1);
			}
			met_isLoaded = true;
		}
		return met_;
	}
	float &metPhi()
	{
		if (not metPhi_isLoaded) {
			if (metPhi_branch != 0) {
				metPhi_branch->GetEntry(index);
			} else { 
				printf("branch metPhi_branch does not exist!\n");
				exit(1);
			}
			metPhi_isLoaded = true;
		}
		return metPhi_;
	}
	int &event()
	{
		if (not event_isLoaded) {
			if (event_branch != 0) {
				event_branch->GetEntry(index);
			} else { 
				printf("branch event_branch does not exist!\n");
				exit(1);
			}
			event_isLoaded = true;
		}
		return event_;
	}
	int &lumi()
	{
		if (not lumi_isLoaded) {
			if (lumi_branch != 0) {
				lumi_branch->GetEntry(index);
			} else { 
				printf("branch lumi_branch does not exist!\n");
				exit(1);
			}
			lumi_isLoaded = true;
		}
		return lumi_;
	}
	int &run()
	{
		if (not run_isLoaded) {
			if (run_branch != 0) {
				run_branch->GetEntry(index);
			} else { 
				printf("branch run_branch does not exist!\n");
				exit(1);
			}
			run_isLoaded = true;
		}
		return run_;
	}
	bool &	filt_csc()
	{
		if (not filt_csc_isLoaded) {
			if (filt_csc_branch != 0) {
				filt_csc_branch->GetEntry(index);
			} else { 
				printf("branch filt_csc_branch does not exist!\n");
				exit(1);
			}
			filt_csc_isLoaded = true;
		}
		return filt_csc_;
	}
	bool &	filt_hbhe()
	{
		if (not filt_hbhe_isLoaded) {
			if (filt_hbhe_branch != 0) {
				filt_hbhe_branch->GetEntry(index);
			} else { 
				printf("branch filt_hbhe_branch does not exist!\n");
				exit(1);
			}
			filt_hbhe_isLoaded = true;
		}
		return filt_hbhe_;
	}
	bool &	filt_hcallaser()
	{
		if (not filt_hcallaser_isLoaded) {
			if (filt_hcallaser_branch != 0) {
				filt_hcallaser_branch->GetEntry(index);
			} else { 
				printf("branch filt_hcallaser_branch does not exist!\n");
				exit(1);
			}
			filt_hcallaser_isLoaded = true;
		}
		return filt_hcallaser_;
	}
	bool &	filt_ecaltp()
	{
		if (not filt_ecaltp_isLoaded) {
			if (filt_ecaltp_branch != 0) {
				filt_ecaltp_branch->GetEntry(index);
			} else { 
				printf("branch filt_ecaltp_branch does not exist!\n");
				exit(1);
			}
			filt_ecaltp_isLoaded = true;
		}
		return filt_ecaltp_;
	}
	bool &	filt_trkfail()
	{
		if (not filt_trkfail_isLoaded) {
			if (filt_trkfail_branch != 0) {
				filt_trkfail_branch->GetEntry(index);
			} else { 
				printf("branch filt_trkfail_branch does not exist!\n");
				exit(1);
			}
			filt_trkfail_isLoaded = true;
		}
		return filt_trkfail_;
	}
	bool &	filt_eebadsc()
	{
		if (not filt_eebadsc_isLoaded) {
			if (filt_eebadsc_branch != 0) {
				filt_eebadsc_branch->GetEntry(index);
			} else { 
				printf("branch filt_eebadsc_branch does not exist!\n");
				exit(1);
			}
			filt_eebadsc_isLoaded = true;
		}
		return filt_eebadsc_;
	}
	bool &	is_real_data()
	{
		if (not is_real_data_isLoaded) {
			if (is_real_data_branch != 0) {
				is_real_data_branch->GetEntry(index);
			} else { 
				printf("branch is_real_data_branch does not exist!\n");
				exit(1);
			}
			is_real_data_isLoaded = true;
		}
		return is_real_data_;
	}
	float &scale1fb()
	{
		if (not scale1fb_isLoaded) {
			if (scale1fb_branch != 0) {
				scale1fb_branch->GetEntry(index);
			} else { 
				printf("branch scale1fb_branch does not exist!\n");
				exit(1);
			}
			scale1fb_isLoaded = true;
		}
		return scale1fb_;
	}
	float &xsec()
	{
		if (not xsec_isLoaded) {
			if (xsec_branch != 0) {
				xsec_branch->GetEntry(index);
			} else { 
				printf("branch xsec_branch does not exist!\n");
				exit(1);
			}
			xsec_isLoaded = true;
		}
		return xsec_;
	}
	float &kfactor()
	{
		if (not kfactor_isLoaded) {
			if (kfactor_branch != 0) {
				kfactor_branch->GetEntry(index);
			} else { 
				printf("branch kfactor_branch does not exist!\n");
				exit(1);
			}
			kfactor_isLoaded = true;
		}
		return kfactor_;
	}
	float &gen_met()
	{
		if (not gen_met_isLoaded) {
			if (gen_met_branch != 0) {
				gen_met_branch->GetEntry(index);
			} else { 
				printf("branch gen_met_branch does not exist!\n");
				exit(1);
			}
			gen_met_isLoaded = true;
		}
		return gen_met_;
	}
	float &gen_met_phi()
	{
		if (not gen_met_phi_isLoaded) {
			if (gen_met_phi_branch != 0) {
				gen_met_phi_branch->GetEntry(index);
			} else { 
				printf("branch gen_met_phi_branch does not exist!\n");
				exit(1);
			}
			gen_met_phi_isLoaded = true;
		}
		return gen_met_phi_;
	}
	int &njets()
	{
		if (not njets_isLoaded) {
			if (njets_branch != 0) {
				njets_branch->GetEntry(index);
			} else { 
				printf("branch njets_branch does not exist!\n");
				exit(1);
			}
			njets_isLoaded = true;
		}
		return njets_;
	}
	int &hyp_class()
	{
		if (not hyp_class_isLoaded) {
			if (hyp_class_branch != 0) {
				hyp_class_branch->GetEntry(index);
			} else { 
				printf("branch hyp_class_branch does not exist!\n");
				exit(1);
			}
			hyp_class_isLoaded = true;
		}
		return hyp_class_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4()
	{
		if (not lep1_p4_isLoaded) {
			if (lep1_p4_branch != 0) {
				lep1_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep1_p4_branch does not exist!\n");
				exit(1);
			}
			lep1_p4_isLoaded = true;
		}
		return *lep1_p4_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4()
	{
		if (not lep2_p4_isLoaded) {
			if (lep2_p4_branch != 0) {
				lep2_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep2_p4_branch does not exist!\n");
				exit(1);
			}
			lep2_p4_isLoaded = true;
		}
		return *lep2_p4_;
	}
	float &ht()
	{
		if (not ht_isLoaded) {
			if (ht_branch != 0) {
				ht_branch->GetEntry(index);
			} else { 
				printf("branch ht_branch does not exist!\n");
				exit(1);
			}
			ht_isLoaded = true;
		}
		return ht_;
	}
	int &lep1_motherID()
	{
		if (not lep1_motherID_isLoaded) {
			if (lep1_motherID_branch != 0) {
				lep1_motherID_branch->GetEntry(index);
			} else { 
				printf("branch lep1_motherID_branch does not exist!\n");
				exit(1);
			}
			lep1_motherID_isLoaded = true;
		}
		return lep1_motherID_;
	}
	int &lep2_motherID()
	{
		if (not lep2_motherID_isLoaded) {
			if (lep2_motherID_branch != 0) {
				lep2_motherID_branch->GetEntry(index);
			} else { 
				printf("branch lep2_motherID_branch does not exist!\n");
				exit(1);
			}
			lep2_motherID_isLoaded = true;
		}
		return lep2_motherID_;
	}
	int &lep1_mc_id()
	{
		if (not lep1_mc_id_isLoaded) {
			if (lep1_mc_id_branch != 0) {
				lep1_mc_id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_mc_id_branch does not exist!\n");
				exit(1);
			}
			lep1_mc_id_isLoaded = true;
		}
		return lep1_mc_id_;
	}
	int &lep2_mc_id()
	{
		if (not lep2_mc_id_isLoaded) {
			if (lep2_mc_id_branch != 0) {
				lep2_mc_id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_mc_id_branch does not exist!\n");
				exit(1);
			}
			lep2_mc_id_isLoaded = true;
		}
		return lep2_mc_id_;
	}
	int &lep1_id()
	{
		if (not lep1_id_isLoaded) {
			if (lep1_id_branch != 0) {
				lep1_id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_id_branch does not exist!\n");
				exit(1);
			}
			lep1_id_isLoaded = true;
		}
		return lep1_id_;
	}
	int &lep2_id()
	{
		if (not lep2_id_isLoaded) {
			if (lep2_id_branch != 0) {
				lep2_id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_id_branch does not exist!\n");
				exit(1);
			}
			lep2_id_isLoaded = true;
		}
		return lep2_id_;
	}
	int &lep1_idx()
	{
		if (not lep1_idx_isLoaded) {
			if (lep1_idx_branch != 0) {
				lep1_idx_branch->GetEntry(index);
			} else { 
				printf("branch lep1_idx_branch does not exist!\n");
				exit(1);
			}
			lep1_idx_isLoaded = true;
		}
		return lep1_idx_;
	}
	int &lep2_idx()
	{
		if (not lep2_idx_isLoaded) {
			if (lep2_idx_branch != 0) {
				lep2_idx_branch->GetEntry(index);
			} else { 
				printf("branch lep2_idx_branch does not exist!\n");
				exit(1);
			}
			lep2_idx_isLoaded = true;
		}
		return lep2_idx_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets()
	{
		if (not jets_isLoaded) {
			if (jets_branch != 0) {
				jets_branch->GetEntry(index);
			} else { 
				printf("branch jets_branch does not exist!\n");
				exit(1);
			}
			jets_isLoaded = true;
		}
		return *jets_;
	}
	const vector<float> &btags_disc()
	{
		if (not btags_disc_isLoaded) {
			if (btags_disc_branch != 0) {
				btags_disc_branch->GetEntry(index);
			} else { 
				printf("branch btags_disc_branch does not exist!\n");
				exit(1);
			}
			btags_disc_isLoaded = true;
		}
		return *btags_disc_;
	}
	const vector<float> &jets_disc()
	{
		if (not jets_disc_isLoaded) {
			if (jets_disc_branch != 0) {
				jets_disc_branch->GetEntry(index);
			} else { 
				printf("branch jets_disc_branch does not exist!\n");
				exit(1);
			}
			jets_disc_isLoaded = true;
		}
		return *jets_disc_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &btags()
	{
		if (not btags_isLoaded) {
			if (btags_branch != 0) {
				btags_branch->GetEntry(index);
			} else { 
				printf("branch btags_branch does not exist!\n");
				exit(1);
			}
			btags_isLoaded = true;
		}
		return *btags_;
	}
	int &nbtags()
	{
		if (not nbtags_isLoaded) {
			if (nbtags_branch != 0) {
				nbtags_branch->GetEntry(index);
			} else { 
				printf("branch nbtags_branch does not exist!\n");
				exit(1);
			}
			nbtags_isLoaded = true;
		}
		return nbtags_;
	}
	float &sf_dilepTrig_hpt()
	{
		if (not sf_dilepTrig_hpt_isLoaded) {
			if (sf_dilepTrig_hpt_branch != 0) {
				sf_dilepTrig_hpt_branch->GetEntry(index);
			} else { 
				printf("branch sf_dilepTrig_hpt_branch does not exist!\n");
				exit(1);
			}
			sf_dilepTrig_hpt_isLoaded = true;
		}
		return sf_dilepTrig_hpt_;
	}
	float &sf_dilepTrig_lpt()
	{
		if (not sf_dilepTrig_lpt_isLoaded) {
			if (sf_dilepTrig_lpt_branch != 0) {
				sf_dilepTrig_lpt_branch->GetEntry(index);
			} else { 
				printf("branch sf_dilepTrig_lpt_branch does not exist!\n");
				exit(1);
			}
			sf_dilepTrig_lpt_isLoaded = true;
		}
		return sf_dilepTrig_lpt_;
	}
	float &sf_dilepTrig_vlpt()
	{
		if (not sf_dilepTrig_vlpt_isLoaded) {
			if (sf_dilepTrig_vlpt_branch != 0) {
				sf_dilepTrig_vlpt_branch->GetEntry(index);
			} else { 
				printf("branch sf_dilepTrig_vlpt_branch does not exist!\n");
				exit(1);
			}
			sf_dilepTrig_vlpt_isLoaded = true;
		}
		return sf_dilepTrig_vlpt_;
	}
	int &hyp_type()
	{
		if (not hyp_type_isLoaded) {
			if (hyp_type_branch != 0) {
				hyp_type_branch->GetEntry(index);
			} else { 
				printf("branch hyp_type_branch does not exist!\n");
				exit(1);
			}
			hyp_type_isLoaded = true;
		}
		return hyp_type_;
	}
	float &sf_dilep_eff()
	{
		if (not sf_dilep_eff_isLoaded) {
			if (sf_dilep_eff_branch != 0) {
				sf_dilep_eff_branch->GetEntry(index);
			} else { 
				printf("branch sf_dilep_eff_branch does not exist!\n");
				exit(1);
			}
			sf_dilep_eff_isLoaded = true;
		}
		return sf_dilep_eff_;
	}
	float &mt()
	{
		if (not mt_isLoaded) {
			if (mt_branch != 0) {
				mt_branch->GetEntry(index);
			} else { 
				printf("branch mt_branch does not exist!\n");
				exit(1);
			}
			mt_isLoaded = true;
		}
		return mt_;
	}
	float &mt_l2()
	{
		if (not mt_l2_isLoaded) {
			if (mt_l2_branch != 0) {
				mt_l2_branch->GetEntry(index);
			} else { 
				printf("branch mt_l2_branch does not exist!\n");
				exit(1);
			}
			mt_l2_isLoaded = true;
		}
		return mt_l2_;
	}
	float &mt2()
	{
		if (not mt2_isLoaded) {
			if (mt2_branch != 0) {
				mt2_branch->GetEntry(index);
			} else { 
				printf("branch mt2_branch does not exist!\n");
				exit(1);
			}
			mt2_isLoaded = true;
		}
		return mt2_;
	}
	float &mGluino()
	{
		if (not mGluino_isLoaded) {
			if (mGluino_branch != 0) {
				mGluino_branch->GetEntry(index);
			} else { 
				printf("branch mGluino_branch does not exist!\n");
				exit(1);
			}
			mGluino_isLoaded = true;
		}
		return mGluino_;
	}
	float &mLSP()
	{
		if (not mLSP_isLoaded) {
			if (mLSP_branch != 0) {
				mLSP_branch->GetEntry(index);
			} else { 
				printf("branch mLSP_branch does not exist!\n");
				exit(1);
			}
			mLSP_isLoaded = true;
		}
		return mLSP_;
	}
	float &mSbottom()
	{
		if (not mSbottom_isLoaded) {
			if (mSbottom_branch != 0) {
				mSbottom_branch->GetEntry(index);
			} else { 
				printf("branch mSbottom_branch does not exist!\n");
				exit(1);
			}
			mSbottom_isLoaded = true;
		}
		return mSbottom_;
	}
	float &mChargino()
	{
		if (not mChargino_isLoaded) {
			if (mChargino_branch != 0) {
				mChargino_branch->GetEntry(index);
			} else { 
				printf("branch mChargino_branch does not exist!\n");
				exit(1);
			}
			mChargino_isLoaded = true;
		}
		return mChargino_;
	}
	int &lep1_id_gen()
	{
		if (not lep1_id_gen_isLoaded) {
			if (lep1_id_gen_branch != 0) {
				lep1_id_gen_branch->GetEntry(index);
			} else { 
				printf("branch lep1_id_gen_branch does not exist!\n");
				exit(1);
			}
			lep1_id_gen_isLoaded = true;
		}
		return lep1_id_gen_;
	}
	int &lep2_id_gen()
	{
		if (not lep2_id_gen_isLoaded) {
			if (lep2_id_gen_branch != 0) {
				lep2_id_gen_branch->GetEntry(index);
			} else { 
				printf("branch lep2_id_gen_branch does not exist!\n");
				exit(1);
			}
			lep2_id_gen_isLoaded = true;
		}
		return lep2_id_gen_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4_gen()
	{
		if (not lep1_p4_gen_isLoaded) {
			if (lep1_p4_gen_branch != 0) {
				lep1_p4_gen_branch->GetEntry(index);
			} else { 
				printf("branch lep1_p4_gen_branch does not exist!\n");
				exit(1);
			}
			lep1_p4_gen_isLoaded = true;
		}
		return *lep1_p4_gen_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4_gen()
	{
		if (not lep2_p4_gen_isLoaded) {
			if (lep2_p4_gen_branch != 0) {
				lep2_p4_gen_branch->GetEntry(index);
			} else { 
				printf("branch lep2_p4_gen_branch does not exist!\n");
				exit(1);
			}
			lep2_p4_gen_isLoaded = true;
		}
		return *lep2_p4_gen_;
	}
	int &lep3_id()
	{
		if (not lep3_id_isLoaded) {
			if (lep3_id_branch != 0) {
				lep3_id_branch->GetEntry(index);
			} else { 
				printf("branch lep3_id_branch does not exist!\n");
				exit(1);
			}
			lep3_id_isLoaded = true;
		}
		return lep3_id_;
	}
	int &lep3_idx()
	{
		if (not lep3_idx_isLoaded) {
			if (lep3_idx_branch != 0) {
				lep3_idx_branch->GetEntry(index);
			} else { 
				printf("branch lep3_idx_branch does not exist!\n");
				exit(1);
			}
			lep3_idx_isLoaded = true;
		}
		return lep3_idx_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep3_p4()
	{
		if (not lep3_p4_isLoaded) {
			if (lep3_p4_branch != 0) {
				lep3_p4_branch->GetEntry(index);
			} else { 
				printf("branch lep3_p4_branch does not exist!\n");
				exit(1);
			}
			lep3_p4_isLoaded = true;
		}
		return *lep3_p4_;
	}
	int &lep3_quality()
	{
		if (not lep3_quality_isLoaded) {
			if (lep3_quality_branch != 0) {
				lep3_quality_branch->GetEntry(index);
			} else { 
				printf("branch lep3_quality_branch does not exist!\n");
				exit(1);
			}
			lep3_quality_isLoaded = true;
		}
		return lep3_quality_;
	}
	float &lep1_iso()
	{
		if (not lep1_iso_isLoaded) {
			if (lep1_iso_branch != 0) {
				lep1_iso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_iso_branch does not exist!\n");
				exit(1);
			}
			lep1_iso_isLoaded = true;
		}
		return lep1_iso_;
	}
	float &lep2_iso()
	{
		if (not lep2_iso_isLoaded) {
			if (lep2_iso_branch != 0) {
				lep2_iso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_iso_branch does not exist!\n");
				exit(1);
			}
			lep2_iso_isLoaded = true;
		}
		return lep2_iso_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &dilep_p4()
	{
		if (not dilep_p4_isLoaded) {
			if (dilep_p4_branch != 0) {
				dilep_p4_branch->GetEntry(index);
			} else { 
				printf("branch dilep_p4_branch does not exist!\n");
				exit(1);
			}
			dilep_p4_isLoaded = true;
		}
		return *dilep_p4_;
	}
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4()
	{
		if (not genps_p4_isLoaded) {
			if (genps_p4_branch != 0) {
				genps_p4_branch->GetEntry(index);
			} else { 
				printf("branch genps_p4_branch does not exist!\n");
				exit(1);
			}
			genps_p4_isLoaded = true;
		}
		return *genps_p4_;
	}
	const vector<int> &genps_id()
	{
		if (not genps_id_isLoaded) {
			if (genps_id_branch != 0) {
				genps_id_branch->GetEntry(index);
			} else { 
				printf("branch genps_id_branch does not exist!\n");
				exit(1);
			}
			genps_id_isLoaded = true;
		}
		return *genps_id_;
	}
	const vector<int> &genps_id_mother()
	{
		if (not genps_id_mother_isLoaded) {
			if (genps_id_mother_branch != 0) {
				genps_id_mother_branch->GetEntry(index);
			} else { 
				printf("branch genps_id_mother_branch does not exist!\n");
				exit(1);
			}
			genps_id_mother_isLoaded = true;
		}
		return *genps_id_mother_;
	}
	const vector<int> &genps_status()
	{
		if (not genps_status_isLoaded) {
			if (genps_status_branch != 0) {
				genps_status_branch->GetEntry(index);
			} else { 
				printf("branch genps_status_branch does not exist!\n");
				exit(1);
			}
			genps_status_isLoaded = true;
		}
		return *genps_status_;
	}
	const vector<int> &genps_id_grandma()
	{
		if (not genps_id_grandma_isLoaded) {
			if (genps_id_grandma_branch != 0) {
				genps_id_grandma_branch->GetEntry(index);
			} else { 
				printf("branch genps_id_grandma_branch does not exist!\n");
				exit(1);
			}
			genps_id_grandma_isLoaded = true;
		}
		return *genps_id_grandma_;
	}
	bool &	lep1_passes_id()
	{
		if (not lep1_passes_id_isLoaded) {
			if (lep1_passes_id_branch != 0) {
				lep1_passes_id_branch->GetEntry(index);
			} else { 
				printf("branch lep1_passes_id_branch does not exist!\n");
				exit(1);
			}
			lep1_passes_id_isLoaded = true;
		}
		return lep1_passes_id_;
	}
	bool &	lep2_passes_id()
	{
		if (not lep2_passes_id_isLoaded) {
			if (lep2_passes_id_branch != 0) {
				lep2_passes_id_branch->GetEntry(index);
			} else { 
				printf("branch lep2_passes_id_branch does not exist!\n");
				exit(1);
			}
			lep2_passes_id_isLoaded = true;
		}
		return lep2_passes_id_;
	}
	float &lep1_dxyPV()
	{
		if (not lep1_dxyPV_isLoaded) {
			if (lep1_dxyPV_branch != 0) {
				lep1_dxyPV_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dxyPV_branch does not exist!\n");
				exit(1);
			}
			lep1_dxyPV_isLoaded = true;
		}
		return lep1_dxyPV_;
	}
	float &lep2_dxyPV()
	{
		if (not lep2_dxyPV_isLoaded) {
			if (lep2_dxyPV_branch != 0) {
				lep2_dxyPV_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dxyPV_branch does not exist!\n");
				exit(1);
			}
			lep2_dxyPV_isLoaded = true;
		}
		return lep2_dxyPV_;
	}
	float &lep1_dZ()
	{
		if (not lep1_dZ_isLoaded) {
			if (lep1_dZ_branch != 0) {
				lep1_dZ_branch->GetEntry(index);
			} else { 
				printf("branch lep1_dZ_branch does not exist!\n");
				exit(1);
			}
			lep1_dZ_isLoaded = true;
		}
		return lep1_dZ_;
	}
	float &lep2_dZ()
	{
		if (not lep2_dZ_isLoaded) {
			if (lep2_dZ_branch != 0) {
				lep2_dZ_branch->GetEntry(index);
			} else { 
				printf("branch lep2_dZ_branch does not exist!\n");
				exit(1);
			}
			lep2_dZ_isLoaded = true;
		}
		return lep2_dZ_;
	}
	float &lep1_d0_err()
	{
		if (not lep1_d0_err_isLoaded) {
			if (lep1_d0_err_branch != 0) {
				lep1_d0_err_branch->GetEntry(index);
			} else { 
				printf("branch lep1_d0_err_branch does not exist!\n");
				exit(1);
			}
			lep1_d0_err_isLoaded = true;
		}
		return lep1_d0_err_;
	}
	float &lep2_d0_err()
	{
		if (not lep2_d0_err_isLoaded) {
			if (lep2_d0_err_branch != 0) {
				lep2_d0_err_branch->GetEntry(index);
			} else { 
				printf("branch lep2_d0_err_branch does not exist!\n");
				exit(1);
			}
			lep2_d0_err_isLoaded = true;
		}
		return lep2_d0_err_;
	}
	float &lep1_ip3d()
	{
		if (not lep1_ip3d_isLoaded) {
			if (lep1_ip3d_branch != 0) {
				lep1_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep1_ip3d_isLoaded = true;
		}
		return lep1_ip3d_;
	}
	float &lep2_ip3d()
	{
		if (not lep2_ip3d_isLoaded) {
			if (lep2_ip3d_branch != 0) {
				lep2_ip3d_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ip3d_branch does not exist!\n");
				exit(1);
			}
			lep2_ip3d_isLoaded = true;
		}
		return lep2_ip3d_;
	}
	float &lep1_ip3d_err()
	{
		if (not lep1_ip3d_err_isLoaded) {
			if (lep1_ip3d_err_branch != 0) {
				lep1_ip3d_err_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ip3d_err_branch does not exist!\n");
				exit(1);
			}
			lep1_ip3d_err_isLoaded = true;
		}
		return lep1_ip3d_err_;
	}
	float &lep2_ip3d_err()
	{
		if (not lep2_ip3d_err_isLoaded) {
			if (lep2_ip3d_err_branch != 0) {
				lep2_ip3d_err_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ip3d_err_branch does not exist!\n");
				exit(1);
			}
			lep2_ip3d_err_isLoaded = true;
		}
		return lep2_ip3d_err_;
	}
	int &nVetoElectrons7()
	{
		if (not nVetoElectrons7_isLoaded) {
			if (nVetoElectrons7_branch != 0) {
				nVetoElectrons7_branch->GetEntry(index);
			} else { 
				printf("branch nVetoElectrons7_branch does not exist!\n");
				exit(1);
			}
			nVetoElectrons7_isLoaded = true;
		}
		return nVetoElectrons7_;
	}
	int &nVetoElectrons10()
	{
		if (not nVetoElectrons10_isLoaded) {
			if (nVetoElectrons10_branch != 0) {
				nVetoElectrons10_branch->GetEntry(index);
			} else { 
				printf("branch nVetoElectrons10_branch does not exist!\n");
				exit(1);
			}
			nVetoElectrons10_isLoaded = true;
		}
		return nVetoElectrons10_;
	}
	int &nVetoElectrons25()
	{
		if (not nVetoElectrons25_isLoaded) {
			if (nVetoElectrons25_branch != 0) {
				nVetoElectrons25_branch->GetEntry(index);
			} else { 
				printf("branch nVetoElectrons25_branch does not exist!\n");
				exit(1);
			}
			nVetoElectrons25_isLoaded = true;
		}
		return nVetoElectrons25_;
	}
	int &nVetoMuons5()
	{
		if (not nVetoMuons5_isLoaded) {
			if (nVetoMuons5_branch != 0) {
				nVetoMuons5_branch->GetEntry(index);
			} else { 
				printf("branch nVetoMuons5_branch does not exist!\n");
				exit(1);
			}
			nVetoMuons5_isLoaded = true;
		}
		return nVetoMuons5_;
	}
	int &nVetoMuons10()
	{
		if (not nVetoMuons10_isLoaded) {
			if (nVetoMuons10_branch != 0) {
				nVetoMuons10_branch->GetEntry(index);
			} else { 
				printf("branch nVetoMuons10_branch does not exist!\n");
				exit(1);
			}
			nVetoMuons10_isLoaded = true;
		}
		return nVetoMuons10_;
	}
	int &nVetoMuons25()
	{
		if (not nVetoMuons25_isLoaded) {
			if (nVetoMuons25_branch != 0) {
				nVetoMuons25_branch->GetEntry(index);
			} else { 
				printf("branch nVetoMuons25_branch does not exist!\n");
				exit(1);
			}
			nVetoMuons25_isLoaded = true;
		}
		return nVetoMuons25_;
	}
	TString &filename()
	{
		if (not filename_isLoaded) {
			if (filename_branch != 0) {
				filename_branch->GetEntry(index);
			} else { 
				printf("branch filename_branch does not exist!\n");
				exit(1);
			}
			filename_isLoaded = true;
		}
		return *filename_;
	}
	float &lep1_ptrel_v0()
	{
		if (not lep1_ptrel_v0_isLoaded) {
			if (lep1_ptrel_v0_branch != 0) {
				lep1_ptrel_v0_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ptrel_v0_branch does not exist!\n");
				exit(1);
			}
			lep1_ptrel_v0_isLoaded = true;
		}
		return lep1_ptrel_v0_;
	}
	float &lep1_ptrel_v1()
	{
		if (not lep1_ptrel_v1_isLoaded) {
			if (lep1_ptrel_v1_branch != 0) {
				lep1_ptrel_v1_branch->GetEntry(index);
			} else { 
				printf("branch lep1_ptrel_v1_branch does not exist!\n");
				exit(1);
			}
			lep1_ptrel_v1_isLoaded = true;
		}
		return lep1_ptrel_v1_;
	}
	float &lep2_ptrel_v0()
	{
		if (not lep2_ptrel_v0_isLoaded) {
			if (lep2_ptrel_v0_branch != 0) {
				lep2_ptrel_v0_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ptrel_v0_branch does not exist!\n");
				exit(1);
			}
			lep2_ptrel_v0_isLoaded = true;
		}
		return lep2_ptrel_v0_;
	}
	float &lep2_ptrel_v1()
	{
		if (not lep2_ptrel_v1_isLoaded) {
			if (lep2_ptrel_v1_branch != 0) {
				lep2_ptrel_v1_branch->GetEntry(index);
			} else { 
				printf("branch lep2_ptrel_v1_branch does not exist!\n");
				exit(1);
			}
			lep2_ptrel_v1_isLoaded = true;
		}
		return lep2_ptrel_v1_;
	}
	float &lep1_miniIso()
	{
		if (not lep1_miniIso_isLoaded) {
			if (lep1_miniIso_branch != 0) {
				lep1_miniIso_branch->GetEntry(index);
			} else { 
				printf("branch lep1_miniIso_branch does not exist!\n");
				exit(1);
			}
			lep1_miniIso_isLoaded = true;
		}
		return lep1_miniIso_;
	}
	float &lep2_miniIso()
	{
		if (not lep2_miniIso_isLoaded) {
			if (lep2_miniIso_branch != 0) {
				lep2_miniIso_branch->GetEntry(index);
			} else { 
				printf("branch lep2_miniIso_branch does not exist!\n");
				exit(1);
			}
			lep2_miniIso_isLoaded = true;
		}
		return lep2_miniIso_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep1()
	{
		if (not jet_close_lep1_isLoaded) {
			if (jet_close_lep1_branch != 0) {
				jet_close_lep1_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_lep1_branch does not exist!\n");
				exit(1);
			}
			jet_close_lep1_isLoaded = true;
		}
		return *jet_close_lep1_;
	}
	ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep2()
	{
		if (not jet_close_lep2_isLoaded) {
			if (jet_close_lep2_branch != 0) {
				jet_close_lep2_branch->GetEntry(index);
			} else { 
				printf("branch jet_close_lep2_branch does not exist!\n");
				exit(1);
			}
			jet_close_lep2_isLoaded = true;
		}
		return *jet_close_lep2_;
	}
	const vector<int> &eleID_kfhits()
	{
		if (not eleID_kfhits_isLoaded) {
			if (eleID_kfhits_branch != 0) {
				eleID_kfhits_branch->GetEntry(index);
			} else { 
				printf("branch eleID_kfhits_branch does not exist!\n");
				exit(1);
			}
			eleID_kfhits_isLoaded = true;
		}
		return *eleID_kfhits_;
	}
	const vector<float> &eleID_oldsigmaietaieta()
	{
		if (not eleID_oldsigmaietaieta_isLoaded) {
			if (eleID_oldsigmaietaieta_branch != 0) {
				eleID_oldsigmaietaieta_branch->GetEntry(index);
			} else { 
				printf("branch eleID_oldsigmaietaieta_branch does not exist!\n");
				exit(1);
			}
			eleID_oldsigmaietaieta_isLoaded = true;
		}
		return *eleID_oldsigmaietaieta_;
	}
	const vector<float> &eleID_oldsigmaiphiiphi()
	{
		if (not eleID_oldsigmaiphiiphi_isLoaded) {
			if (eleID_oldsigmaiphiiphi_branch != 0) {
				eleID_oldsigmaiphiiphi_branch->GetEntry(index);
			} else { 
				printf("branch eleID_oldsigmaiphiiphi_branch does not exist!\n");
				exit(1);
			}
			eleID_oldsigmaiphiiphi_isLoaded = true;
		}
		return *eleID_oldsigmaiphiiphi_;
	}
	const vector<float> &eleID_oldcircularity()
	{
		if (not eleID_oldcircularity_isLoaded) {
			if (eleID_oldcircularity_branch != 0) {
				eleID_oldcircularity_branch->GetEntry(index);
			} else { 
				printf("branch eleID_oldcircularity_branch does not exist!\n");
				exit(1);
			}
			eleID_oldcircularity_isLoaded = true;
		}
		return *eleID_oldcircularity_;
	}
	const vector<float> &eleID_oldr9()
	{
		if (not eleID_oldr9_isLoaded) {
			if (eleID_oldr9_branch != 0) {
				eleID_oldr9_branch->GetEntry(index);
			} else { 
				printf("branch eleID_oldr9_branch does not exist!\n");
				exit(1);
			}
			eleID_oldr9_isLoaded = true;
		}
		return *eleID_oldr9_;
	}
	const vector<float> &eleID_scletawidth()
	{
		if (not eleID_scletawidth_isLoaded) {
			if (eleID_scletawidth_branch != 0) {
				eleID_scletawidth_branch->GetEntry(index);
			} else { 
				printf("branch eleID_scletawidth_branch does not exist!\n");
				exit(1);
			}
			eleID_scletawidth_isLoaded = true;
		}
		return *eleID_scletawidth_;
	}
	const vector<float> &eleID_sclphiwidth()
	{
		if (not eleID_sclphiwidth_isLoaded) {
			if (eleID_sclphiwidth_branch != 0) {
				eleID_sclphiwidth_branch->GetEntry(index);
			} else { 
				printf("branch eleID_sclphiwidth_branch does not exist!\n");
				exit(1);
			}
			eleID_sclphiwidth_isLoaded = true;
		}
		return *eleID_sclphiwidth_;
	}
	const vector<float> &eleID_he()
	{
		if (not eleID_he_isLoaded) {
			if (eleID_he_branch != 0) {
				eleID_he_branch->GetEntry(index);
			} else { 
				printf("branch eleID_he_branch does not exist!\n");
				exit(1);
			}
			eleID_he_isLoaded = true;
		}
		return *eleID_he_;
	}
	const vector<float> &eleID_psEoverEraw()
	{
		if (not eleID_psEoverEraw_isLoaded) {
			if (eleID_psEoverEraw_branch != 0) {
				eleID_psEoverEraw_branch->GetEntry(index);
			} else { 
				printf("branch eleID_psEoverEraw_branch does not exist!\n");
				exit(1);
			}
			eleID_psEoverEraw_isLoaded = true;
		}
		return *eleID_psEoverEraw_;
	}
	const vector<float> &eleID_kfchi2()
	{
		if (not eleID_kfchi2_isLoaded) {
			if (eleID_kfchi2_branch != 0) {
				eleID_kfchi2_branch->GetEntry(index);
			} else { 
				printf("branch eleID_kfchi2_branch does not exist!\n");
				exit(1);
			}
			eleID_kfchi2_isLoaded = true;
		}
		return *eleID_kfchi2_;
	}
	const vector<float> &eleID_chi2_hits()
	{
		if (not eleID_chi2_hits_isLoaded) {
			if (eleID_chi2_hits_branch != 0) {
				eleID_chi2_hits_branch->GetEntry(index);
			} else { 
				printf("branch eleID_chi2_hits_branch does not exist!\n");
				exit(1);
			}
			eleID_chi2_hits_isLoaded = true;
		}
		return *eleID_chi2_hits_;
	}
	const vector<float> &eleID_fbrem()
	{
		if (not eleID_fbrem_isLoaded) {
			if (eleID_fbrem_branch != 0) {
				eleID_fbrem_branch->GetEntry(index);
			} else { 
				printf("branch eleID_fbrem_branch does not exist!\n");
				exit(1);
			}
			eleID_fbrem_isLoaded = true;
		}
		return *eleID_fbrem_;
	}
	const vector<float> &eleID_ep()
	{
		if (not eleID_ep_isLoaded) {
			if (eleID_ep_branch != 0) {
				eleID_ep_branch->GetEntry(index);
			} else { 
				printf("branch eleID_ep_branch does not exist!\n");
				exit(1);
			}
			eleID_ep_isLoaded = true;
		}
		return *eleID_ep_;
	}
	const vector<float> &eleID_eelepout()
	{
		if (not eleID_eelepout_isLoaded) {
			if (eleID_eelepout_branch != 0) {
				eleID_eelepout_branch->GetEntry(index);
			} else { 
				printf("branch eleID_eelepout_branch does not exist!\n");
				exit(1);
			}
			eleID_eelepout_isLoaded = true;
		}
		return *eleID_eelepout_;
	}
	const vector<float> &eleID_IoEmIop()
	{
		if (not eleID_IoEmIop_isLoaded) {
			if (eleID_IoEmIop_branch != 0) {
				eleID_IoEmIop_branch->GetEntry(index);
			} else { 
				printf("branch eleID_IoEmIop_branch does not exist!\n");
				exit(1);
			}
			eleID_IoEmIop_isLoaded = true;
		}
		return *eleID_IoEmIop_;
	}
	const vector<float> &eleID_deltaetain()
	{
		if (not eleID_deltaetain_isLoaded) {
			if (eleID_deltaetain_branch != 0) {
				eleID_deltaetain_branch->GetEntry(index);
			} else { 
				printf("branch eleID_deltaetain_branch does not exist!\n");
				exit(1);
			}
			eleID_deltaetain_isLoaded = true;
		}
		return *eleID_deltaetain_;
	}
	const vector<float> &eleID_deltaphiin()
	{
		if (not eleID_deltaphiin_isLoaded) {
			if (eleID_deltaphiin_branch != 0) {
				eleID_deltaphiin_branch->GetEntry(index);
			} else { 
				printf("branch eleID_deltaphiin_branch does not exist!\n");
				exit(1);
			}
			eleID_deltaphiin_isLoaded = true;
		}
		return *eleID_deltaphiin_;
	}
	const vector<float> &eleID_deltaetaseed()
	{
		if (not eleID_deltaetaseed_isLoaded) {
			if (eleID_deltaetaseed_branch != 0) {
				eleID_deltaetaseed_branch->GetEntry(index);
			} else { 
				printf("branch eleID_deltaetaseed_branch does not exist!\n");
				exit(1);
			}
			eleID_deltaetaseed_isLoaded = true;
		}
		return *eleID_deltaetaseed_;
	}
	const vector<float> &eleID_pT()
	{
		if (not eleID_pT_isLoaded) {
			if (eleID_pT_branch != 0) {
				eleID_pT_branch->GetEntry(index);
			} else { 
				printf("branch eleID_pT_branch does not exist!\n");
				exit(1);
			}
			eleID_pT_isLoaded = true;
		}
		return *eleID_pT_;
	}
	const vector<bool> &eleID_isbarrel()
	{
		if (not eleID_isbarrel_isLoaded) {
			if (eleID_isbarrel_branch != 0) {
				eleID_isbarrel_branch->GetEntry(index);
			} else { 
				printf("branch eleID_isbarrel_branch does not exist!\n");
				exit(1);
			}
			eleID_isbarrel_isLoaded = true;
		}
		return *eleID_isbarrel_;
	}
	const vector<bool> &eleID_isendcap()
	{
		if (not eleID_isendcap_isLoaded) {
			if (eleID_isendcap_branch != 0) {
				eleID_isendcap_branch->GetEntry(index);
			} else { 
				printf("branch eleID_isendcap_branch does not exist!\n");
				exit(1);
			}
			eleID_isendcap_isLoaded = true;
		}
		return *eleID_isendcap_;
	}
	const vector<float> &eleID_scl_eta()
	{
		if (not eleID_scl_eta_isLoaded) {
			if (eleID_scl_eta_branch != 0) {
				eleID_scl_eta_branch->GetEntry(index);
			} else { 
				printf("branch eleID_scl_eta_branch does not exist!\n");
				exit(1);
			}
			eleID_scl_eta_isLoaded = true;
		}
		return *eleID_scl_eta_;
	}
	const vector<float> &muID_dzPV()
	{
		if (not muID_dzPV_isLoaded) {
			if (muID_dzPV_branch != 0) {
				muID_dzPV_branch->GetEntry(index);
			} else { 
				printf("branch muID_dzPV_branch does not exist!\n");
				exit(1);
			}
			muID_dzPV_isLoaded = true;
		}
		return *muID_dzPV_;
	}
	const vector<float> &muID_ptSig()
	{
		if (not muID_ptSig_isLoaded) {
			if (muID_ptSig_branch != 0) {
				muID_ptSig_branch->GetEntry(index);
			} else { 
				printf("branch muID_ptSig_branch does not exist!\n");
				exit(1);
			}
			muID_ptSig_isLoaded = true;
		}
		return *muID_ptSig_;
	}
	const vector<float> &muID_ip3dSig()
	{
		if (not muID_ip3dSig_isLoaded) {
			if (muID_ip3dSig_branch != 0) {
				muID_ip3dSig_branch->GetEntry(index);
			} else { 
				printf("branch muID_ip3dSig_branch does not exist!\n");
				exit(1);
			}
			muID_ip3dSig_isLoaded = true;
		}
		return *muID_ip3dSig_;
	}
	const vector<float> &muID_medMuonPOG()
	{
		if (not muID_medMuonPOG_isLoaded) {
			if (muID_medMuonPOG_branch != 0) {
				muID_medMuonPOG_branch->GetEntry(index);
			} else { 
				printf("branch muID_medMuonPOG_branch does not exist!\n");
				exit(1);
			}
			muID_medMuonPOG_isLoaded = true;
		}
		return *muID_medMuonPOG_;
	}
	const vector<float> &muID_pt()
	{
		if (not muID_pt_isLoaded) {
			if (muID_pt_branch != 0) {
				muID_pt_branch->GetEntry(index);
			} else { 
				printf("branch muID_pt_branch does not exist!\n");
				exit(1);
			}
			muID_pt_isLoaded = true;
		}
		return *muID_pt_;
	}
	const vector<float> &muID_eta()
	{
		if (not muID_eta_isLoaded) {
			if (muID_eta_branch != 0) {
				muID_eta_branch->GetEntry(index);
			} else { 
				printf("branch muID_eta_branch does not exist!\n");
				exit(1);
			}
			muID_eta_isLoaded = true;
		}
		return *muID_eta_;
	}

  static void progress( int nEventsTotal, int nEventsChain ){
    int period = 1000;
    if(nEventsTotal%1000 == 0) {
      // xterm magic from L. Vacavant and A. Cerri
      if (isatty(1)) {
        if( ( nEventsChain - nEventsTotal ) > period ){
          float frac = (float)nEventsTotal/(nEventsChain*0.01);
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
               "\033[0m\033[32m <---\033[0m\015", frac);
          fflush(stdout);
        }
        else {
          printf("\015\033[32m ---> \033[1m\033[31m%4.1f%%"
                 "\033[0m\033[32m <---\033[0m\015", 100.);
          cout << endl;
        }
      }
    }
  }
  
};

#ifndef __CINT__
extern SSAG samesign;
#endif

namespace ss {
	const float &met();
	const float &metPhi();
	const int &event();
	const int &lumi();
	const int &run();
	const bool &filt_csc();
	const bool &filt_hbhe();
	const bool &filt_hcallaser();
	const bool &filt_ecaltp();
	const bool &filt_trkfail();
	const bool &filt_eebadsc();
	const bool &is_real_data();
	const float &scale1fb();
	const float &xsec();
	const float &kfactor();
	const float &gen_met();
	const float &gen_met_phi();
	const int &njets();
	const int &hyp_class();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4();
	const float &ht();
	const int &lep1_motherID();
	const int &lep2_motherID();
	const int &lep1_mc_id();
	const int &lep2_mc_id();
	const int &lep1_id();
	const int &lep2_id();
	const int &lep1_idx();
	const int &lep2_idx();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &jets();
	const vector<float> &btags_disc();
	const vector<float> &jets_disc();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &btags();
	const int &nbtags();
	const float &sf_dilepTrig_hpt();
	const float &sf_dilepTrig_lpt();
	const float &sf_dilepTrig_vlpt();
	const int &hyp_type();
	const float &sf_dilep_eff();
	const float &mt();
	const float &mt_l2();
	const float &mt2();
	const float &mGluino();
	const float &mLSP();
	const float &mSbottom();
	const float &mChargino();
	const int &lep1_id_gen();
	const int &lep2_id_gen();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep1_p4_gen();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep2_p4_gen();
	const int &lep3_id();
	const int &lep3_idx();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &lep3_p4();
	const int &lep3_quality();
	const float &lep1_iso();
	const float &lep2_iso();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &dilep_p4();
	const vector<ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > > &genps_p4();
	const vector<int> &genps_id();
	const vector<int> &genps_id_mother();
	const vector<int> &genps_status();
	const vector<int> &genps_id_grandma();
	const bool &lep1_passes_id();
	const bool &lep2_passes_id();
	const float &lep1_dxyPV();
	const float &lep2_dxyPV();
	const float &lep1_dZ();
	const float &lep2_dZ();
	const float &lep1_d0_err();
	const float &lep2_d0_err();
	const float &lep1_ip3d();
	const float &lep2_ip3d();
	const float &lep1_ip3d_err();
	const float &lep2_ip3d_err();
	const int &nVetoElectrons7();
	const int &nVetoElectrons10();
	const int &nVetoElectrons25();
	const int &nVetoMuons5();
	const int &nVetoMuons10();
	const int &nVetoMuons25();
	const TString &filename();
	const float &lep1_ptrel_v0();
	const float &lep1_ptrel_v1();
	const float &lep2_ptrel_v0();
	const float &lep2_ptrel_v1();
	const float &lep1_miniIso();
	const float &lep2_miniIso();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep1();
	const ROOT::Math::LorentzVector<ROOT::Math::PxPyPzE4D<float> > &jet_close_lep2();
	const vector<int> &eleID_kfhits();
	const vector<float> &eleID_oldsigmaietaieta();
	const vector<float> &eleID_oldsigmaiphiiphi();
	const vector<float> &eleID_oldcircularity();
	const vector<float> &eleID_oldr9();
	const vector<float> &eleID_scletawidth();
	const vector<float> &eleID_sclphiwidth();
	const vector<float> &eleID_he();
	const vector<float> &eleID_psEoverEraw();
	const vector<float> &eleID_kfchi2();
	const vector<float> &eleID_chi2_hits();
	const vector<float> &eleID_fbrem();
	const vector<float> &eleID_ep();
	const vector<float> &eleID_eelepout();
	const vector<float> &eleID_IoEmIop();
	const vector<float> &eleID_deltaetain();
	const vector<float> &eleID_deltaphiin();
	const vector<float> &eleID_deltaetaseed();
	const vector<float> &eleID_pT();
	const vector<bool> &eleID_isbarrel();
	const vector<bool> &eleID_isendcap();
	const vector<float> &eleID_scl_eta();
	const vector<float> &muID_dzPV();
	const vector<float> &muID_ptSig();
	const vector<float> &muID_ip3dSig();
	const vector<float> &muID_medMuonPOG();
	const vector<float> &muID_pt();
	const vector<float> &muID_eta();
}
#endif
