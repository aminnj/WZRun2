{
    gROOT->ProcessLine(".L ~/Software/dataMCplotMaker/dataMCplotMaker.cc+");
    gSystem->Load("../CORE/CMS3_CORE.so");
    gROOT->ProcessLine(".L ../classFiles/v4.00/SS.cc+");

    gROOT->ProcessLine(".L scan.C+");
    scan();

    // gROOT->ProcessLine(".L srscan.C+");
    // srscan();

}
