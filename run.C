{
    gROOT->ProcessLine(".L ../software/dataMCplotMaker/dataMCplotMaker.cc+");
    gROOT->ProcessLine(".L SS.cc+");
    gROOT->ProcessLine(".L scan.C+");
    //njetsLow, njetsHigh, btagCut, metLow, metHigh, htLow, htHigh, tag
    scan(    0    ,   9999   ,   1  ,   30  ,   9999 ,   0  ,  9999 , ""  );
    // scan(    0    ,   9999   ,   999  ,   30  ,   9999 ,   0  ,  9999 , "_test"  );
    // scan(    0    ,   9999   ,   999  ,   30  ,   9999 ,   0  ,  9999 , "unscaled"    );
    // scan(    2    ,   9999   ,   1  ,   30  ,   9999 ,  80  ,  9999 , "SR0bj0" );
    // scan(    2    ,   9999   ,   999  ,   30  ,   9999 ,  80  ,  9999 , "SR0" );
    // scan(    2    ,     3    ,    1   ,   50  ,   120  , 200  ,  400  , "SR1" );
    // scan(    2    ,     3    ,    1   ,   50  ,   120  , 400  ,  9999 , "SR2" );
    // scan(    4    ,   9999   ,    1   ,   50  ,   120  , 200  ,  400  , "SR3" );
    // scan(    4    ,   9999   ,    1   ,   50  ,   120  , 400  ,  9999 , "SR4" );
    // scan(    2    ,     3    ,    1   ,  120  ,   9999 , 200  ,  400  , "SR5" );
    // scan(    2    ,     3    ,    1   ,  120  ,   9999 , 400  ,  9999 , "SR6" );
    // scan(    4    ,   9999   ,    1   ,  120  ,   9999 , 200  ,  400  , "SR7" );
    // scan(    4    ,   9999   ,    1   ,  120  ,   9999 , 400  ,  9999 , "SR8" );
}
