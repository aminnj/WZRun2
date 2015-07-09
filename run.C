{
    gROOT->ProcessLine(".L ../software/dataMCplotMaker/dataMCplotMaker.cc+");
    gROOT->ProcessLine(".L SS.cc+");
    gROOT->ProcessLine(".L scan.C+");
    //    njetsLow, njetsHigh,  btagCut, metLow, metHigh, htLow, htHigh, tag
    
    // scan(    0    ,   9999   ,   9999  ,   0   ,   9999 ,   0  ,  9999 , ""  );
    // scan(    0    ,   9999   ,   1  ,  30   ,   9999 ,   0  ,  9999 , ""  );

    scan(    0    ,   9999   ,   9999  ,  0   ,   9999 ,   0  ,  9999 , "_nocuts"  );
    scan(    0    ,   9999   ,   1  ,  30   ,   9999 ,   0  ,  9999 , "_bt1met30"  );
}
