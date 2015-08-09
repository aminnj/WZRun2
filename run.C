{
    gROOT->ProcessLine(".L ../software/dataMCplotMaker/dataMCplotMaker.cc+");
    gSystem->Load("../CORE/CMS3_CORE.so");
    gROOT->ProcessLine(".L SS.cc+");

    gROOT->ProcessLine(".L scan.C+");
    scan();

    // gROOT->ProcessLine(".L srscan.C+");
    // srscan();

}
