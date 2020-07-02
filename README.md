![Build](https://github.com/GaryHughes/stddecimal/workflows/Build/badge.svg)


# std::decimal

This is an implementation of the proposed C++ [ISO/IEC JTC1 SC22 WG21 N2849](http://www.open-std.org/JTC1/SC22/WG21/docs/papers/2009/n2849.pdf) std::decimal including the [ISO/IEC JTC1 SC22 WG21 N3871](http://open-std.org/JTC1/SC22/WG21/docs/papers/2014/n3871.html) revisions. It is built on the [Intel Floating Point Library](https://software.intel.com/content/www/us/en/develop/articles/pre-release-license-agreement-for-intel-decimal-floating-point-math-library.html) that does all the hard work.

# Intent

I've used [this implementation](https://sourceforge.net/p/stddecimal/code/HEAD/tree/trunk/) successfully in the past however I wanted build a modern version that relied on templates instead of macros to generate the numerous operators required.

# Testing

The library is validated using the [General Decimal Arithmetic Test Cases](http://speleotrove.com/decimal/dectest.html). Test cases that are not applicable or not yet supported will be explicitly skipped.
## Subset Arithmetic

|Type|Passed|Failed|Skipped|
|----|:----:|:----:|:-----:|
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs001
skipping: abs002
skipping: abs003
skipping: abs004
skipping: abs005
skipping: abs006
skipping: abs007
skipping: abs008
skipping: abs009
skipping: abs010
skipping: abs011
skipping: abs012
skipping: abs013
skipping: abs014
skipping: abs015
skipping: abs016
skipping: abs017
skipping: abs018
skipping: abs020
skipping: abs021
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs022
skipping: abs023
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs024
skipping: abs025
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs026
skipping: abs027
skipping: abs030
skipping: abs031
skipping: abs032
skipping: abs033
skipping: abs034
skipping: abs035
skipping: abs036
skipping: abs037
skipping: abs038
skipping: abs039
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs040
skipping: abs041
skipping: abs042
skipping: abs043
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs060
skipping: abs061
skipping: abs062
skipping: abs063
skipping: abs065
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: abs120
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs301
skipping: abs302
skipping: abs303
skipping: abs304
skipping: abs305
skipping: abs306
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: abs321
skipping: abs322
skipping: abs323
skipping: abs324
skipping: abs325
skipping: abs326
skipping: abs400
general_decimal_arithmetic/test_cases/subset_arithmetic/abs0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 1
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
general_decimal_arithmetic/test_cases/subset_arithmetic/add0.decTest
context {
    rounding     : 
    precision    : 15
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : 
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: bas001
skipping: bas002
skipping: bas003
skipping: bas004
skipping: bas005
skipping: bas006
skipping: bas007
skipping: bas008
skipping: bas009
skipping: bas010
skipping: bas011
skipping: bas012
skipping: bas013
skipping: bas014
skipping: bas015
skipping: bas016
skipping: bas021
skipping: bas022
skipping: bas023
skipping: bas024
skipping: bas025
skipping: bas026
skipping: bas027
skipping: bas030
skipping: bas031
skipping: bas032
skipping: bas033
skipping: bas034
skipping: bas035
skipping: bas036
skipping: bas037
skipping: bas038
skipping: bas101
skipping: bas102
skipping: bas103
skipping: bas104
skipping: bas105
skipping: bas106
skipping: bas107
skipping: bas108
skipping: bas109
skipping: bas110
skipping: bas111
skipping: bas112
skipping: bas113
skipping: bas114
skipping: bas115
skipping: bas116
skipping: bas117
skipping: bas118
skipping: bas119
skipping: bas120
skipping: bas121
skipping: bas122
skipping: bas123
skipping: bas124
skipping: bas125
skipping: bas126
skipping: bas130
skipping: bas131
skipping: bas132
skipping: bas133
skipping: bas134
skipping: bas135
skipping: bas136
skipping: bas137
skipping: bas138
skipping: bas139
skipping: bas140
skipping: bas141
skipping: bas142
skipping: bas143
skipping: bas144
skipping: bas145
skipping: bas146
skipping: bas147
skipping: bas148
skipping: bas149
skipping: bas150
skipping: bas151
skipping: bas152
skipping: bas153
skipping: bas154
skipping: bas155
skipping: bas156
skipping: bas157
skipping: bas158
skipping: bas159
skipping: bas160
skipping: bas161
skipping: bas162
skipping: bas163
skipping: bas164
skipping: bas165
skipping: bas166
skipping: bas167
skipping: bas168
skipping: bas169
skipping: bas170
skipping: bas171
skipping: bas172
skipping: bas173
skipping: bas174
skipping: bas175
skipping: bas176
skipping: bas177
skipping: bas178
skipping: bas179
skipping: bas180
skipping: bas181
skipping: bas182
skipping: bas183
skipping: bas190
skipping: bas191
skipping: bas192
skipping: bas193
skipping: bas194
skipping: bas195
skipping: bas196
skipping: bas197
skipping: bas198
skipping: bas199
skipping: bas200
skipping: bas201
skipping: bas202
skipping: bas203
skipping: bas210
skipping: bas211
skipping: bas212
skipping: bas213
skipping: bas214
skipping: bas215
skipping: bas216
skipping: bas217
skipping: bas218
skipping: bas219
skipping: bas220
skipping: bas221
skipping: bas222
skipping: bas223
skipping: bas230
skipping: bas231
skipping: bas232
skipping: bas233
skipping: bas234
skipping: bas235
skipping: bas236
skipping: bas237
skipping: bas238
skipping: bas239
skipping: bas240
skipping: bas241
skipping: bas242
skipping: bas243
skipping: bas250
skipping: bas251
skipping: bas252
skipping: bas253
skipping: bas254
skipping: bas255
skipping: bas256
skipping: bas257
skipping: bas258
skipping: bas259
skipping: bas260
skipping: bas261
skipping: bas262
skipping: bas263
skipping: bas270
skipping: bas271
skipping: bas272
skipping: bas273
skipping: bas274
skipping: bas275
skipping: bas276
skipping: bas277
skipping: bas279
skipping: bas280
skipping: bas281
skipping: bas282
skipping: bas283
skipping: bas284
skipping: bas301
skipping: bas302
skipping: bas303
skipping: bas304
skipping: bas305
skipping: bas306
skipping: bas307
skipping: bas308
skipping: bas309
skipping: bas310
skipping: bas311
skipping: bas312
skipping: bas313
skipping: bas314
skipping: bas315
skipping: bas316
skipping: bas317
skipping: bas318
skipping: bas319
skipping: bas320
skipping: bas321
skipping: bas322
skipping: bas323
skipping: bas324
skipping: bas325
skipping: bas326
skipping: bas327
skipping: bas328
skipping: bas329
skipping: bas330
skipping: bas331
skipping: bas332
skipping: bas333
skipping: bas334
skipping: bas335
skipping: bas336
skipping: bas337
skipping: bas338
skipping: bas339
skipping: bas340
skipping: bas341
skipping: bas342
skipping: bas343
skipping: bas344
skipping: bas345
skipping: bas346
skipping: bas347
skipping: bas348
skipping: bas349
skipping: bas350
skipping: bas351
skipping: bas352
skipping: bas361
skipping: bas362
skipping: bas363
skipping: bas364
skipping: bas365
skipping: bas366
skipping: bas367
skipping: bas368
skipping: bas369
skipping: bas370
skipping: bas371
skipping: bas372
skipping: bas373
skipping: bas374
skipping: bas375
skipping: bas376
skipping: bas377
skipping: bas378
skipping: bas379
skipping: bas380
skipping: bas381
skipping: bas382
skipping: bas383
skipping: bas384
skipping: bas385
skipping: bas386
skipping: bas387
skipping: bas388
skipping: bas389
skipping: bas390
skipping: bas391
skipping: bas392
skipping: bas393
skipping: bas394
skipping: bas395
skipping: bas396
skipping: bas397
skipping: bas398
skipping: bas399
skipping: bas400
skipping: bas401
skipping: bas402
skipping: bas403
skipping: bas404
skipping: bas405
skipping: bas406
skipping: bas407
skipping: bas408
skipping: bas409
skipping: bas410
skipping: bas411
skipping: bas412
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: bas420
skipping: bas421
skipping: bas422
skipping: bas423
skipping: bas424
skipping: bas425
skipping: bas426
skipping: bas427
skipping: bas428
skipping: bas429
skipping: bas430
skipping: bas431
skipping: bas432
skipping: bas433
skipping: bas434
skipping: bas435
skipping: bas436
skipping: bas437
skipping: bas438
skipping: bas439
skipping: bas440
skipping: bas441
skipping: bas442
skipping: bas443
skipping: bas444
skipping: bas445
skipping: bas446
skipping: bas447
skipping: bas448
skipping: bas449
skipping: bas500
skipping: bas501
skipping: bas502
skipping: bas503
skipping: bas504
skipping: bas505
skipping: bas506
skipping: bas507
skipping: bas508
skipping: bas509
skipping: bas510
skipping: bas511
skipping: bas512
skipping: bas513
skipping: bas514
skipping: bas515
skipping: bas516
skipping: bas517
skipping: bas518
skipping: bas519
skipping: bas520
skipping: bas521
skipping: bas522
skipping: bas523
skipping: bas524
skipping: bas525
skipping: bas526
skipping: bas527
skipping: bas528
skipping: bas529
skipping: bas530
skipping: bas531
skipping: bas532
skipping: bas533
skipping: bas534
skipping: bas535
skipping: bas536
skipping: bas537
skipping: bas538
skipping: bas539
skipping: bas540
skipping: bas541
skipping: bas542
skipping: bas543
skipping: bas544
skipping: bas545
skipping: bas546
skipping: bas547
skipping: bas548
skipping: bas549
skipping: bas550
skipping: bas551
skipping: bas552
skipping: bas553
skipping: bas554
skipping: bas555
skipping: bas556
skipping: bas557
skipping: bas558
skipping: bas559
skipping: bas560
skipping: bas561
skipping: bas562
skipping: bas563
skipping: bas564
skipping: bas565
skipping: bas566
skipping: bas567
skipping: bas570
skipping: bas571
skipping: bas572
skipping: bas573
skipping: bas574
skipping: bas575
skipping: bas576
skipping: bas577
skipping: bas578
skipping: bas579
skipping: bas580
skipping: bas581
skipping: bas582
skipping: bas583
skipping: bas584
skipping: bas585
skipping: bas586
skipping: bas587
skipping: bas588
skipping: bas589
skipping: bas590
skipping: bas591
skipping: bas592
skipping: bas593
skipping: bas700
skipping: bas701
skipping: bas702
skipping: bas703
skipping: bas704
skipping: bas705
skipping: bas706
skipping: bas708
skipping: bas709
skipping: bas710
skipping: bas711
skipping: bas712
skipping: bas713
skipping: bas714
skipping: bas715
skipping: bas716
skipping: bas717
skipping: bas718
skipping: bas719
skipping: bas720
skipping: bas721
skipping: bas601
skipping: bas602
skipping: bas603
skipping: bas604
skipping: bas605
skipping: bas606
skipping: bas607
skipping: bas608
skipping: bas609
skipping: bas610
skipping: bas611
skipping: bas612
skipping: bas613
skipping: bas614
skipping: bas615
skipping: bas616
skipping: bas617
skipping: bas618
skipping: bas619
skipping: bas620
skipping: bas621
skipping: bas622
skipping: bas630
skipping: bas631
skipping: bas632
skipping: bas633
skipping: bas634
skipping: bas635
skipping: bas636
skipping: bas637
skipping: bas638
skipping: bas639
skipping: bas640
skipping: bas641
skipping: bas642
skipping: bas643
skipping: bas644
skipping: bas645
skipping: bas646
skipping: bas647
skipping: bas648
skipping: bas649
skipping: bas650
skipping: bas651
skipping: bas652
skipping: bas653
skipping: bas654
skipping: bas655
skipping: bas656
skipping: bas657
skipping: bas658
skipping: bas659
skipping: bas660
skipping: bas661
skipping: bas662
skipping: bas663
skipping: bas664
skipping: bas665
skipping: bas666
skipping: bas667
skipping: bas668
skipping: bas669
skipping: bas670
skipping: bas671
skipping: bas672
skipping: bas673
skipping: bas674
skipping: bas675
skipping: bas676
skipping: bas677
skipping: bas678
skipping: bas679
skipping: bas801
skipping: bas802
skipping: bas803
skipping: bas804
skipping: bas805
skipping: bas806
skipping: bas807
skipping: bas808
skipping: bas809
skipping: bas810
skipping: bas811
skipping: bas812
skipping: bas813
skipping: bas814
skipping: bas815
skipping: bas816
skipping: bas817
skipping: bas818
skipping: bas819
skipping: bas820
skipping: bas821
skipping: bas822
skipping: bas830
skipping: bas831
skipping: bas832
skipping: bas833
skipping: bas834
skipping: bas835
skipping: bas836
skipping: bas837
skipping: bas838
skipping: bas839
skipping: bas840
skipping: bas841
skipping: bas842
skipping: bas843
skipping: bas844
skipping: bas845
skipping: bas846
skipping: bas847
skipping: bas848
skipping: bas849
skipping: bas850
skipping: bas851
skipping: bas852
skipping: bas853
skipping: bas854
skipping: bas855
skipping: bas856
skipping: bas857
skipping: bas858
skipping: bas859
skipping: bas860
skipping: bas861
skipping: bas862
skipping: bas863
skipping: bas864
skipping: bas865
skipping: bas866
skipping: bas867
skipping: bas868
skipping: bas869
skipping: bas870
skipping: bas871
skipping: bas872
skipping: bas873
skipping: bas874
skipping: bas875
skipping: bas876
skipping: bas877
skipping: bas878
skipping: bas879
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: bas951
skipping: bas952
skipping: bas953
skipping: bas954
skipping: bas955
skipping: bas956
skipping: bas957
skipping: bas958
skipping: bas959
skipping: bas960
skipping: bas961
skipping: bas962
skipping: bas963
skipping: bas964
skipping: bas965
skipping: bas966
skipping: bas967
skipping: bas968
skipping: bas969
skipping: bas970
skipping: bas971
skipping: bas972
skipping: bas973
skipping: bas974
skipping: bas975
skipping: bas976
skipping: bas977
skipping: bas978
skipping: bas979
skipping: bas980
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 0
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 0
    max exponent : 0
    clamp:       : 0
}
skipping: emax001
skipping: emax002
skipping: emax003
skipping: emax004
skipping: emax005
skipping: emax006
skipping: emax007
skipping: emax008
skipping: emax009
skipping: emax010
skipping: emax011
skipping: emax012
skipping: emax013
skipping: emax014
skipping: emax015
skipping: emax016
skipping: emax017
skipping: emax018
context {
    rounding     : 4
    precision    : 9
    min exponent : 0
    max exponent : 1
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -1
    max exponent : 1
    clamp:       : 0
}
skipping: emax100
skipping: emax101
skipping: emax102
skipping: emax103
skipping: emax104
skipping: emax105
skipping: emax106
skipping: emax107
skipping: emax108
skipping: emax109
skipping: emax110
skipping: emax111
skipping: emax112
skipping: emax113
skipping: emax114
skipping: emax115
skipping: emax116
skipping: emax117
skipping: emax118
skipping: emax119
skipping: emax120
context {
    rounding     : 4
    precision    : 9
    min exponent : -1
    max exponent : 2
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -2
    max exponent : 2
    clamp:       : 0
}
skipping: emax200
skipping: emax201
skipping: emax202
skipping: emax203
skipping: emax204
skipping: emax205
skipping: emax206
skipping: emax207
skipping: emax208
skipping: emax209
skipping: emax210
skipping: emax211
skipping: emax212
skipping: emax213
skipping: emax214
skipping: emax215
skipping: emax216
skipping: emax217
skipping: emax218
skipping: emax219
skipping: emax220
skipping: emax221
context {
    rounding     : 4
    precision    : 9
    min exponent : -2
    max exponent : 7
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -7
    max exponent : 7
    clamp:       : 0
}
skipping: emax231
skipping: emax232
skipping: emax233
skipping: emax234
skipping: emax235
skipping: emax236
skipping: emax237
skipping: emax238
context {
    rounding     : 4
    precision    : 9
    min exponent : -7
    max exponent : 9
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -9
    max exponent : 9
    clamp:       : 0
}
skipping: emax241
skipping: emax242
skipping: emax243
skipping: emax244
skipping: emax245
skipping: emax246
skipping: emax247
skipping: emax248
context {
    rounding     : 4
    precision    : 9
    min exponent : -9
    max exponent : 10
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -10
    max exponent : 10
    clamp:       : 0
}
skipping: emax251
skipping: emax252
skipping: emax253
skipping: emax254
skipping: emax255
skipping: emax256
skipping: emax257
skipping: emax258
skipping: emax261
skipping: emax262
skipping: emax263
skipping: emax264
skipping: emax265
skipping: emax266
skipping: emax267
skipping: emax268
skipping: emax271
skipping: emax272
skipping: emax273
skipping: emax274
skipping: emax275
skipping: emax276
skipping: emax277
skipping: emax278
context {
    rounding     : 4
    precision    : 9
    min exponent : -10
    max exponent : 99
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -99
    max exponent : 99
    clamp:       : 0
}
skipping: emax281
skipping: emax282
skipping: emax283
skipping: emax284
skipping: emax285
skipping: emax286
context {
    rounding     : 4
    precision    : 9
    min exponent : -99
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: emax291
skipping: emax292
skipping: emax293
skipping: emax294
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
skipping: emax301
skipping: emax302
skipping: emax303
skipping: emax304
context {
    rounding     : 4
    precision    : 9
    min exponent : -9999
    max exponent : 99999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -99999
    max exponent : 99999
    clamp:       : 0
}
skipping: emax311
skipping: emax312
skipping: emax313
skipping: emax314
context {
    rounding     : 4
    precision    : 9
    min exponent : -99999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: emax321
skipping: emax322
skipping: emax323
skipping: emax324
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 9999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -9999999
    max exponent : 9999999
    clamp:       : 0
}
skipping: emax331
skipping: emax332
skipping: emax333
skipping: emax334
context {
    rounding     : 4
    precision    : 9
    min exponent : -9999999
    max exponent : 99999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -99999999
    max exponent : 99999999
    clamp:       : 0
}
skipping: emax341
skipping: emax342
skipping: emax343
skipping: emax344
context {
    rounding     : 4
    precision    : 9
    min exponent : -99999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: emax351
skipping: emax352
skipping: emax353
skipping: emax354
skipping: emax355
skipping: emax356
skipping: emax357
skipping: emax358
skipping: emax359
skipping: emax360
skipping: emax361
skipping: emax362
skipping: emax363
skipping: emax364
skipping: emax365
skipping: emax366
skipping: emax367
skipping: emax368
skipping: emax369
skipping: emax370
skipping: emax371
skipping: emax372
skipping: emax373
skipping: emax374
skipping: emax375
skipping: emax376
skipping: emax377
skipping: emax378
skipping: emax379
skipping: emax380
skipping: emax381
skipping: emax382
skipping: emax383
skipping: emax384
skipping: emax385
skipping: emax386
skipping: emax387
skipping: emax388
skipping: emax389
skipping: emax390
general_decimal_arithmetic/test_cases/subset_arithmetic/base0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: com001
skipping: com002
skipping: com003
skipping: com004
skipping: com005
skipping: com006
skipping: com007
skipping: com008
skipping: com009
skipping: com010
skipping: com011
skipping: com012
skipping: com013
skipping: com014
skipping: com015
skipping: com016
skipping: com017
skipping: com018
skipping: com019
skipping: com020
skipping: com021
skipping: com022
skipping: com023
skipping: com025
skipping: com026
skipping: com031
skipping: com032
skipping: com033
skipping: com034
skipping: com035
skipping: com036
skipping: com037
skipping: com038
skipping: com039
skipping: com040
skipping: com041
skipping: com042
skipping: com043
skipping: com044
skipping: com045
skipping: com046
skipping: com047
skipping: com048
skipping: com049
skipping: com050
skipping: com051
skipping: com052
skipping: com053
skipping: com055
skipping: com056
skipping: com061
skipping: com062
skipping: com063
skipping: com064
skipping: com065
skipping: com066
skipping: com067
skipping: com068
skipping: com069
skipping: com070
skipping: com071
skipping: com072
skipping: com073
skipping: com074
skipping: com075
skipping: com076
skipping: com077
skipping: com078
skipping: com079
skipping: com080
skipping: com081
skipping: com082
skipping: com083
skipping: com085
skipping: com086
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: com100
skipping: com101
skipping: com102
skipping: com103
skipping: com104
skipping: com105
skipping: com106
skipping: com107
skipping: com108
skipping: com109
skipping: com110
skipping: com120
skipping: com121
skipping: com122
skipping: com123
skipping: com124
skipping: com125
skipping: com126
skipping: com127
skipping: com128
skipping: com129
skipping: com130
skipping: com140
skipping: com141
skipping: com142
skipping: com143
skipping: com144
skipping: com145
skipping: com146
skipping: com147
skipping: com148
skipping: com149
skipping: com150
skipping: com200
skipping: com201
skipping: com202
skipping: com203
skipping: com204
skipping: com205
skipping: com206
skipping: com207
skipping: com208
skipping: com209
skipping: com210
skipping: com220
skipping: com221
skipping: com222
skipping: com223
skipping: com224
skipping: com225
skipping: com226
skipping: com227
skipping: com228
skipping: com229
skipping: com230
skipping: com240
skipping: com241
skipping: com242
skipping: com243
skipping: com244
skipping: com245
skipping: com246
skipping: com247
skipping: com248
skipping: com249
skipping: com250
skipping: com300
skipping: com301
skipping: com302
skipping: com303
skipping: com304
skipping: com305
skipping: com306
skipping: com307
skipping: com308
skipping: com309
skipping: com310
skipping: com320
skipping: com321
skipping: com322
skipping: com323
skipping: com324
skipping: com325
skipping: com326
skipping: com327
skipping: com328
skipping: com329
skipping: com330
skipping: com340
skipping: com341
skipping: com342
skipping: com343
skipping: com344
skipping: com345
skipping: com346
skipping: com347
skipping: com348
skipping: com349
skipping: com350
skipping: com400
skipping: com401
skipping: com402
skipping: com403
skipping: com404
skipping: com405
skipping: com406
skipping: com407
skipping: com408
skipping: com409
skipping: com410
skipping: com420
skipping: com421
skipping: com422
skipping: com423
skipping: com424
skipping: com425
skipping: com426
skipping: com427
skipping: com428
skipping: com429
skipping: com430
skipping: com440
skipping: com441
skipping: com442
skipping: com443
skipping: com444
skipping: com445
skipping: com446
skipping: com447
skipping: com448
skipping: com449
skipping: com450
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: com460
skipping: com461
skipping: com462
skipping: com463
context {
    rounding     : 4
    precision    : 40
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: com470
skipping: com471
skipping: com472
skipping: com473
skipping: com474
skipping: com475
skipping: com476
skipping: com477
skipping: com478
skipping: com479
skipping: com480
skipping: com481
skipping: com482
skipping: com483
skipping: com484
skipping: com485
skipping: com486
skipping: com487
skipping: com488
skipping: com489
skipping: com490
skipping: com491
skipping: com492
skipping: com493
skipping: com494
skipping: com495
skipping: com496
skipping: com497
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: com500
skipping: com501
skipping: com502
skipping: com503
skipping: com504
skipping: com505
skipping: com506
skipping: com507
skipping: com508
skipping: com509
skipping: com510
skipping: com511
skipping: com512
skipping: com513
skipping: com514
skipping: com515
skipping: com516
skipping: com517
skipping: com518
skipping: com519
skipping: com521
skipping: com522
skipping: com523
skipping: com524
skipping: com525
skipping: com526
skipping: com527
skipping: com528
skipping: com529
skipping: com530
skipping: com531
skipping: com540
skipping: com541
skipping: com542
skipping: com543
skipping: com544
skipping: com545
skipping: com546
skipping: com547
skipping: com548
skipping: com549
skipping: com550
skipping: com551
skipping: com552
skipping: com553
skipping: com554
skipping: com555
skipping: com556
skipping: com557
skipping: com558
skipping: com559
skipping: com561
skipping: com562
skipping: com563
skipping: com564
skipping: com565
skipping: com566
skipping: com567
skipping: com568
skipping: com569
skipping: com570
skipping: com571
skipping: com580
skipping: com581
skipping: com582
skipping: com583
skipping: com584
skipping: com585
skipping: com586
skipping: com587
skipping: com588
skipping: com589
skipping: com590
skipping: com591
skipping: com592
skipping: com593
skipping: com594
skipping: com595
skipping: com596
skipping: com597
skipping: com598
skipping: com599
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: com600
skipping: com601
skipping: com602
skipping: com603
skipping: com604
skipping: com605
skipping: com606
skipping: com607
skipping: com608
skipping: com609
skipping: com610
skipping: com611
skipping: com612
skipping: com613
skipping: com614
skipping: com615
skipping: com616
skipping: com617
skipping: com618
skipping: com619
skipping: com620
skipping: com621
skipping: com622
skipping: com623
skipping: com624
skipping: com625
skipping: com626
skipping: com627
skipping: com628
skipping: com629
skipping: com630
skipping: com631
skipping: com632
skipping: com633
skipping: com634
skipping: com635
skipping: com636
skipping: com637
skipping: com638
skipping: com639
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: com680
skipping: com681
skipping: com682
skipping: com683
skipping: com684
skipping: com685
skipping: com686
skipping: com687
skipping: com688
skipping: com689
skipping: com690
skipping: com691
skipping: com692
skipping: com693
skipping: com694
skipping: com695
skipping: com696
skipping: com697
skipping: com698
skipping: com699
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 20
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: com701
skipping: com702
skipping: com703
skipping: com704
skipping: com705
skipping: com706
skipping: com707
skipping: com708
skipping: com709
skipping: com710
skipping: com711
skipping: com712
skipping: com713
skipping: com714
skipping: com715
skipping: com716
skipping: com717
skipping: com718
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: com741
skipping: com742
skipping: com743
skipping: com744
skipping: com745
skipping: com746
skipping: com747
skipping: com748
skipping: com749
skipping: com750
skipping: com751
skipping: com752
skipping: com900
skipping: com901
general_decimal_arithmetic/test_cases/subset_arithmetic/compare0.decTest
context {
    rounding     : 
    precision    : 16
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : 
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: cot001
skipping: cot002
skipping: cot003
skipping: cot004
skipping: cot005
skipping: cot006
skipping: cot007
skipping: cot008
skipping: cot009
skipping: cot010
skipping: cot011
skipping: cot012
skipping: cot013
skipping: cot014
skipping: cot015
skipping: cot016
skipping: cot017
skipping: cot018
skipping: cot019
skipping: cot020
skipping: cot021
skipping: cot022
skipping: cot023
skipping: cot025
skipping: cot026
skipping: cot031
skipping: cot032
skipping: cot033
skipping: cot034
skipping: cot035
skipping: cot036
skipping: cot037
skipping: cot038
skipping: cot039
skipping: cot040
skipping: cot041
skipping: cot042
skipping: cot043
skipping: cot044
skipping: cot045
skipping: cot046
skipping: cot047
skipping: cot048
skipping: cot049
skipping: cot050
skipping: cot051
skipping: cot052
skipping: cot053
skipping: cot055
skipping: cot056
skipping: cot061
skipping: cot062
skipping: cot063
skipping: cot064
skipping: cot065
skipping: cot066
skipping: cot067
skipping: cot068
skipping: cot069
skipping: cot070
skipping: cot071
skipping: cot072
skipping: cot073
skipping: cot074
skipping: cot075
skipping: cot076
skipping: cot077
skipping: cot078
skipping: cot079
skipping: cot080
skipping: cot081
skipping: cot082
skipping: cot083
skipping: cot085
skipping: cot086
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: cot090
skipping: cot091
skipping: cot092
skipping: cot093
skipping: cot100
skipping: cot101
skipping: cot102
skipping: cot103
skipping: cot104
skipping: cot105
skipping: cot106
skipping: cot107
skipping: cot108
skipping: cot109
skipping: cot110
skipping: cot120
skipping: cot121
skipping: cot122
skipping: cot123
skipping: cot124
skipping: cot125
skipping: cot126
skipping: cot127
skipping: cot128
skipping: cot129
skipping: cot130
skipping: cot140
skipping: cot141
skipping: cot142
skipping: cot143
skipping: cot144
skipping: cot145
skipping: cot146
skipping: cot147
skipping: cot148
skipping: cot149
skipping: cot150
skipping: cot200
skipping: cot201
skipping: cot202
skipping: cot203
skipping: cot204
skipping: cot205
skipping: cot206
skipping: cot207
skipping: cot208
skipping: cot209
skipping: cot210
skipping: cot220
skipping: cot221
skipping: cot222
skipping: cot223
skipping: cot224
skipping: cot225
skipping: cot226
skipping: cot227
skipping: cot228
skipping: cot229
skipping: cot230
skipping: cot240
skipping: cot241
skipping: cot242
skipping: cot243
skipping: cot244
skipping: cot245
skipping: cot246
skipping: cot247
skipping: cot248
skipping: cot249
skipping: cot250
skipping: cot300
skipping: cot301
skipping: cot302
skipping: cot303
skipping: cot304
skipping: cot305
skipping: cot306
skipping: cot307
skipping: cot308
skipping: cot309
skipping: cot310
skipping: cot320
skipping: cot321
skipping: cot322
skipping: cot323
skipping: cot324
skipping: cot325
skipping: cot326
skipping: cot327
skipping: cot328
skipping: cot329
skipping: cot330
skipping: cot340
skipping: cot341
skipping: cot342
skipping: cot343
skipping: cot344
skipping: cot345
skipping: cot346
skipping: cot347
skipping: cot348
skipping: cot349
skipping: cot350
skipping: cot400
skipping: cot401
skipping: cot402
skipping: cot403
skipping: cot404
skipping: cot405
skipping: cot406
skipping: cot407
skipping: cot408
skipping: cot409
skipping: cot410
skipping: cot420
skipping: cot421
skipping: cot422
skipping: cot423
skipping: cot424
skipping: cot425
skipping: cot426
skipping: cot427
skipping: cot428
skipping: cot429
skipping: cot430
skipping: cot440
skipping: cot441
skipping: cot442
skipping: cot443
skipping: cot444
skipping: cot445
skipping: cot446
skipping: cot447
skipping: cot448
skipping: cot449
skipping: cot450
context {
    rounding     : 4
    precision    : 40
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: cot470
skipping: cot471
skipping: cot472
skipping: cot473
skipping: cot474
skipping: cot475
skipping: cot476
skipping: cot477
skipping: cot478
skipping: cot479
skipping: cot480
skipping: cot481
skipping: cot482
skipping: cot483
skipping: cot484
skipping: cot485
skipping: cot486
skipping: cot487
skipping: cot488
skipping: cot489
skipping: cot490
skipping: cot491
skipping: cot492
skipping: cot493
skipping: cot494
skipping: cot495
skipping: cot496
skipping: cot497
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: cot500
skipping: cot501
skipping: cot502
skipping: cot503
skipping: cot504
skipping: cot505
skipping: cot506
skipping: cot507
skipping: cot508
skipping: cot509
skipping: cot510
skipping: cot511
skipping: cot512
skipping: cot513
skipping: cot514
skipping: cot515
skipping: cot516
skipping: cot517
skipping: cot518
skipping: cot519
skipping: cot521
skipping: cot522
skipping: cot523
skipping: cot524
skipping: cot525
skipping: cot526
skipping: cot527
skipping: cot528
skipping: cot529
skipping: cot530
skipping: cot531
skipping: cot540
skipping: cot541
skipping: cot542
skipping: cot543
skipping: cot544
skipping: cot545
skipping: cot546
skipping: cot547
skipping: cot548
skipping: cot549
skipping: cot550
skipping: cot551
skipping: cot552
skipping: cot553
skipping: cot554
skipping: cot555
skipping: cot556
skipping: cot557
skipping: cot558
skipping: cot559
skipping: cot561
skipping: cot562
skipping: cot563
skipping: cot564
skipping: cot565
skipping: cot566
skipping: cot567
skipping: cot568
skipping: cot569
skipping: cot570
skipping: cot571
skipping: cot580
skipping: cot581
skipping: cot582
skipping: cot583
skipping: cot584
skipping: cot585
skipping: cot586
skipping: cot587
skipping: cot588
skipping: cot589
skipping: cot590
skipping: cot591
skipping: cot592
skipping: cot593
skipping: cot594
skipping: cot595
skipping: cot596
skipping: cot597
skipping: cot598
skipping: cot599
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: cot600
skipping: cot601
skipping: cot602
skipping: cot603
skipping: cot604
skipping: cot605
skipping: cot606
skipping: cot607
skipping: cot608
skipping: cot609
skipping: cot610
skipping: cot611
skipping: cot612
skipping: cot613
skipping: cot614
skipping: cot615
skipping: cot616
skipping: cot617
skipping: cot618
skipping: cot619
skipping: cot620
skipping: cot621
skipping: cot622
skipping: cot623
skipping: cot624
skipping: cot625
skipping: cot626
skipping: cot627
skipping: cot628
skipping: cot629
skipping: cot630
skipping: cot631
skipping: cot632
skipping: cot633
skipping: cot634
skipping: cot635
skipping: cot636
skipping: cot637
skipping: cot638
skipping: cot639
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: cot680
skipping: cot681
skipping: cot682
skipping: cot683
skipping: cot684
skipping: cot685
skipping: cot686
skipping: cot687
skipping: cot688
skipping: cot689
skipping: cot690
skipping: cot691
skipping: cot692
skipping: cot693
skipping: cot694
skipping: cot695
skipping: cot696
skipping: cot697
skipping: cot698
skipping: cot699
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 20
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: cot701
skipping: cot702
skipping: cot703
skipping: cot704
skipping: cot705
skipping: cot706
skipping: cot707
skipping: cot708
skipping: cot709
skipping: cot710
skipping: cot711
skipping: cot712
skipping: cot713
skipping: cot714
skipping: cot715
skipping: cot716
skipping: cot717
skipping: cot718
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: cot721
skipping: cot722
skipping: cot723
skipping: cot724
skipping: cot725
skipping: cot726
skipping: cot727
skipping: cot728
skipping: cot729
skipping: cot730
skipping: cot731
skipping: cot732
context {
    rounding     : 4
    precision    : 5
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: cot740
skipping: cot741
skipping: cot742
skipping: cot743
skipping: cot744
skipping: cot745
skipping: cot746
skipping: cot750
skipping: cot751
skipping: cot752
skipping: cot753
skipping: cot754
skipping: cot755
skipping: cot756
context {
    rounding     : 4
    precision    : 5
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 5
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: cot1080
skipping: cot1081
skipping: cot1082
skipping: cot1083
skipping: cot1085
skipping: cot1086
skipping: cot1087
skipping: cot1088
skipping: cot1089
skipping: cot1090
skipping: cot1091
skipping: cot1092
skipping: cot1093
skipping: cot1094
skipping: cot1095
skipping: cot1096
skipping: cot1097
skipping: cot1098
skipping: cot1099
skipping: cot1100
skipping: cot1101
skipping: cot1102
skipping: cot1103
skipping: cot1104
skipping: cot1105
skipping: cot1106
skipping: cot1107
skipping: cot1108
skipping: cot9990
skipping: cot9991
general_decimal_arithmetic/test_cases/subset_arithmetic/comparetotal0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: div001
skipping: div002
skipping: div003
skipping: div004
skipping: div005
skipping: div006
skipping: div007
skipping: div008
skipping: div009
skipping: div010
skipping: div011
skipping: div012
skipping: div013
skipping: div014
skipping: div015
skipping: div016
skipping: div017
skipping: div018
skipping: div019
skipping: div020
skipping: div021
skipping: div022
skipping: div023
skipping: div024
skipping: div025
skipping: div026
skipping: div027
skipping: div028
skipping: div029
skipping: div030
skipping: div031
skipping: div032
skipping: div033
skipping: div034
skipping: div035
skipping: div040
skipping: div041
skipping: div042
skipping: div043
skipping: div044
skipping: div045
skipping: div050
skipping: div051
skipping: div052
skipping: div053
skipping: div054
skipping: div055
skipping: div060
skipping: div061
skipping: div062
skipping: div063
skipping: div064
skipping: div065
skipping: div070
skipping: div071
skipping: div072
skipping: div073
skipping: div074
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: div080
skipping: div081
skipping: div082
skipping: div083
skipping: div084
skipping: div085
skipping: div086
skipping: div087
skipping: div088
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: div090
skipping: div091
skipping: div092
skipping: div093
skipping: div094
skipping: div095
skipping: div096
skipping: div097
skipping: div098
skipping: div099
skipping: div100
skipping: div101
skipping: div102
skipping: div103
skipping: div104
skipping: div105
skipping: div106
skipping: div107
skipping: div108
skipping: div109
skipping: div110
skipping: div111
skipping: div112
skipping: div113
skipping: div114
skipping: div115
skipping: div116
skipping: div117
skipping: div118
skipping: div119
skipping: div130
skipping: div131
skipping: div132
skipping: div133
skipping: div134
skipping: div135
skipping: div136
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: div201
skipping: div202
skipping: div203
skipping: div204
skipping: div205
skipping: div206
skipping: div207
skipping: div208
skipping: div209
skipping: div210
skipping: div211
skipping: div220
skipping: div221
skipping: div222
skipping: div223
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: div270
skipping: div271
skipping: div272
skipping: div273
skipping: div274
skipping: div275
skipping: div276
skipping: div277
skipping: div280
skipping: div281
skipping: div282
skipping: div283
skipping: div284
skipping: div285
skipping: div286
skipping: div287
skipping: div288
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: div330
skipping: div331
skipping: div332
skipping: div333
skipping: div335
skipping: div336
skipping: div337
skipping: div338
skipping: div360
skipping: div361
skipping: div362
skipping: div363
skipping: div364
skipping: div365
skipping: div366
skipping: div367
skipping: div368
skipping: div369
skipping: div370
skipping: div371
skipping: div372
skipping: div373
skipping: div374
skipping: div375
skipping: div376
skipping: div377
skipping: div378
skipping: div379
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: div401
skipping: div402
skipping: div403
skipping: div404
skipping: div405
skipping: div406
skipping: div407
skipping: div408
skipping: div409
skipping: div410
skipping: div411
skipping: div412
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: div441
skipping: div442
skipping: div443
skipping: div444
skipping: div445
skipping: div446
skipping: div447
skipping: div448
skipping: div449
skipping: div450
skipping: div451
skipping: div452
skipping: div900
skipping: div901
general_decimal_arithmetic/test_cases/subset_arithmetic/divide0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: dvi001
skipping: dvi002
skipping: dvi003
skipping: dvi004
skipping: dvi005
skipping: dvi006
skipping: dvi007
skipping: dvi008
skipping: dvi009
skipping: dvi010
skipping: dvi011
skipping: dvi012
skipping: dvi013
skipping: dvi014
skipping: dvi015
skipping: dvi016
skipping: dvi017
skipping: dvi018
skipping: dvi019
skipping: dvi020
skipping: dvi021
skipping: dvi022
skipping: dvi023
skipping: dvi024
skipping: dvi025
skipping: dvi030
skipping: dvi031
skipping: dvi032
skipping: dvi033
skipping: dvi034
skipping: dvi035
skipping: dvi040
skipping: dvi041
skipping: dvi042
skipping: dvi043
skipping: dvi044
skipping: dvi045
skipping: dvi050
skipping: dvi051
skipping: dvi052
skipping: dvi053
skipping: dvi054
skipping: dvi055
skipping: dvi060
skipping: dvi061
skipping: dvi062
skipping: dvi063
skipping: dvi064
skipping: dvi065
skipping: dvi070
skipping: dvi071
skipping: dvi072
skipping: dvi073
skipping: dvi074
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: dvi080
skipping: dvi081
skipping: dvi082
skipping: dvi083
skipping: dvi084
skipping: dvi085
skipping: dvi086
skipping: dvi087
skipping: dvi088
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: dvi090
skipping: dvi091
skipping: dvi092
skipping: dvi093
skipping: dvi094
skipping: dvi100
skipping: dvi101
skipping: dvi102
skipping: dvi103
skipping: dvi104
skipping: dvi105
skipping: dvi106
skipping: dvi107
skipping: dvi108
skipping: dvi109
skipping: dvi110
skipping: dvi111
skipping: dvi112
skipping: dvi113
skipping: dvi114
skipping: dvi115
skipping: dvi116
skipping: dvi117
skipping: dvi118
skipping: dvi119
skipping: dvi131
skipping: dvi132
skipping: dvi133
skipping: dvi134
skipping: dvi135
skipping: dvi136
skipping: dvi137
skipping: dvi138
skipping: dvi139
skipping: dvi140
skipping: dvi141
skipping: dvi142
skipping: dvi143
skipping: dvi144
skipping: dvi145
skipping: dvi150
skipping: dvi151
skipping: dvi152
skipping: dvi153
skipping: dvi154
skipping: dvi155
skipping: dvi156
skipping: dvi157
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: dvi201
skipping: dvi202
skipping: dvi203
skipping: dvi204
skipping: dvi205
skipping: dvi206
skipping: dvi207
skipping: dvi208
skipping: dvi209
skipping: dvi210
skipping: dvi211
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: dvi270
skipping: dvi271
skipping: dvi272
skipping: dvi273
skipping: dvi274
skipping: dvi275
skipping: dvi276
skipping: dvi277
skipping: dvi280
skipping: dvi281
skipping: dvi282
skipping: dvi283
skipping: dvi284
skipping: dvi285
skipping: dvi286
skipping: dvi287
skipping: dvi288
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: dvi330
skipping: dvi331
skipping: dvi332
skipping: dvi333
skipping: dvi335
skipping: dvi336
skipping: dvi337
skipping: dvi338
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: dvi401
skipping: dvi402
skipping: dvi403
skipping: dvi404
skipping: dvi405
skipping: dvi406
skipping: dvi407
skipping: dvi408
skipping: dvi409
skipping: dvi410
skipping: dvi411
skipping: dvi412
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: dvi441
skipping: dvi442
skipping: dvi443
skipping: dvi444
skipping: dvi445
skipping: dvi446
skipping: dvi447
skipping: dvi448
skipping: dvi449
skipping: dvi450
skipping: dvi451
skipping: dvi452
skipping: dvi900
skipping: dvi901
general_decimal_arithmetic/test_cases/subset_arithmetic/divideint0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp002
skipping: exp003
skipping: exp004
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp021
skipping: exp022
skipping: exp023
skipping: exp024
skipping: exp025
skipping: exp026
skipping: exp027
skipping: exp028
skipping: exp029
skipping: exp030
skipping: exp031
skipping: exp032
skipping: exp033
skipping: exp034
skipping: exp035
skipping: exp036
skipping: exp037
skipping: exp038
skipping: exp039
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp041
skipping: exp042
skipping: exp043
skipping: exp044
skipping: exp045
skipping: exp046
skipping: exp047
skipping: exp048
skipping: exp049
skipping: exp050
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp101
context {
    rounding     : 4
    precision    : 31
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp102
context {
    rounding     : 4
    precision    : 30
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp103
context {
    rounding     : 4
    precision    : 29
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp104
context {
    rounding     : 4
    precision    : 28
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp105
context {
    rounding     : 4
    precision    : 27
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp106
context {
    rounding     : 4
    precision    : 26
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp107
context {
    rounding     : 4
    precision    : 25
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp108
context {
    rounding     : 4
    precision    : 24
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp109
context {
    rounding     : 4
    precision    : 23
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp110
context {
    rounding     : 4
    precision    : 22
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp111
context {
    rounding     : 4
    precision    : 21
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp112
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp113
context {
    rounding     : 4
    precision    : 19
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp114
context {
    rounding     : 4
    precision    : 18
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp115
context {
    rounding     : 4
    precision    : 17
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp116
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp117
context {
    rounding     : 4
    precision    : 15
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp118
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp119
context {
    rounding     : 4
    precision    : 13
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp120
context {
    rounding     : 4
    precision    : 12
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp121
context {
    rounding     : 4
    precision    : 11
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp122
context {
    rounding     : 4
    precision    : 10
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp123
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp124
context {
    rounding     : 4
    precision    : 8
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp125
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp126
context {
    rounding     : 4
    precision    : 6
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp127
context {
    rounding     : 4
    precision    : 5
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp128
context {
    rounding     : 4
    precision    : 4
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp129
context {
    rounding     : 4
    precision    : 3
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp130
context {
    rounding     : 4
    precision    : 2
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp131
context {
    rounding     : 4
    precision    : 1
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp132
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp210
skipping: exp211
skipping: exp212
skipping: exp213
skipping: exp214
skipping: exp215
skipping: exp216
skipping: exp217
skipping: exp218
skipping: exp219
skipping: exp220
skipping: exp221
skipping: exp222
skipping: exp223
skipping: exp224
skipping: exp225
skipping: exp226
skipping: exp227
skipping: exp228
skipping: exp233
skipping: exp234
skipping: exp235
skipping: exp236
skipping: exp237
skipping: exp238
skipping: exp239
skipping: exp240
skipping: exp241
skipping: exp242
skipping: exp243
skipping: exp244
skipping: exp245
skipping: exp246
skipping: exp247
skipping: exp248
skipping: exp249
skipping: exp250
skipping: exp251
context {
    rounding     : 4
    precision    : 30
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp320
skipping: exp321
skipping: exp322
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp323
skipping: exp324
skipping: exp325
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp326
skipping: exp327
skipping: exp328
context {
    rounding     : 4
    precision    : 30
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp340
skipping: exp341
skipping: exp342
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp343
skipping: exp344
skipping: exp345
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp346
skipping: exp347
skipping: exp348
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp401
skipping: exp402
skipping: exp403
skipping: exp404
skipping: exp405
skipping: exp406
skipping: exp407
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp411
skipping: exp412
skipping: exp413
skipping: exp414
skipping: exp415
skipping: exp416
skipping: exp417
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp704
skipping: exp705
skipping: exp706
skipping: exp707
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp725
skipping: exp726
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp754
skipping: exp755
skipping: exp756
skipping: exp757
skipping: exp759
skipping: exp760
skipping: exp761
skipping: exp762
skipping: exp763
skipping: exp764
skipping: exp765
skipping: exp766
skipping: exp769
skipping: exp770
skipping: exp771
skipping: exp772
skipping: exp773
skipping: exp774
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp900
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp1501
skipping: exp1502
skipping: exp1503
skipping: exp1504
skipping: exp1505
skipping: exp1506
skipping: exp1507
skipping: exp1508
skipping: exp1509
skipping: exp1510
skipping: exp1511
skipping: exp1512
skipping: exp1513
skipping: exp1514
skipping: exp1515
skipping: exp1516
skipping: exp1517
skipping: exp1518
skipping: exp1519
skipping: exp1520
skipping: exp1521
skipping: exp1522
skipping: exp1523
skipping: exp1524
skipping: exp1525
skipping: exp1526
skipping: exp1527
skipping: exp1528
skipping: exp1529
skipping: exp1530
skipping: exp1531
skipping: exp1532
skipping: exp1533
skipping: exp1534
skipping: exp1535
skipping: exp1536
skipping: exp1537
skipping: exp1538
skipping: exp1539
skipping: exp1540
context {
    rounding     : 4
    precision    : 34
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 34
    min exponent : -383
    max exponent : 6144
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 34
    min exponent : -6143
    max exponent : 6144
    clamp:       : 0
}
skipping: exp1201
skipping: exp1202
skipping: exp1203
skipping: exp1204
skipping: exp1205
skipping: exp1206
skipping: exp1207
skipping: exp1208
skipping: exp1209
skipping: exp1210
skipping: exp1211
skipping: exp1212
skipping: exp1213
skipping: exp1214
skipping: exp1215
skipping: exp1216
skipping: exp1217
skipping: exp1218
skipping: exp1219
skipping: exp1220
skipping: exp1221
skipping: exp1222
skipping: exp1223
skipping: exp1224
skipping: exp1225
skipping: exp1226
skipping: exp1227
skipping: exp1228
skipping: exp1229
skipping: exp1230
skipping: exp1231
skipping: exp1232
skipping: exp1233
skipping: exp1234
skipping: exp1235
skipping: exp1236
skipping: exp1237
skipping: exp1238
skipping: exp1239
skipping: exp1240
context {
    rounding     : 4
    precision    : 16
    min exponent : -6143
    max exponent : 6144
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -6143
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: exp1101
skipping: exp1102
skipping: exp1103
skipping: exp1104
skipping: exp1105
skipping: exp1106
skipping: exp1107
skipping: exp1108
skipping: exp1109
skipping: exp1110
skipping: exp1111
skipping: exp1112
skipping: exp1113
skipping: exp1114
skipping: exp1115
skipping: exp1116
skipping: exp1117
skipping: exp1118
skipping: exp1119
skipping: exp1120
skipping: exp1121
skipping: exp1122
skipping: exp1123
skipping: exp1124
skipping: exp1125
skipping: exp1126
skipping: exp1127
skipping: exp1128
skipping: exp1129
skipping: exp1130
skipping: exp1131
skipping: exp1132
skipping: exp1133
skipping: exp1134
skipping: exp1135
skipping: exp1136
skipping: exp1137
skipping: exp1138
skipping: exp1139
skipping: exp1140
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 96
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -95
    max exponent : 96
    clamp:       : 0
}
skipping: exp1001
skipping: exp1002
skipping: exp1003
skipping: exp1004
skipping: exp1005
skipping: exp1006
skipping: exp1007
skipping: exp1008
skipping: exp1009
skipping: exp1010
skipping: exp1011
skipping: exp1012
skipping: exp1013
skipping: exp1014
skipping: exp1015
skipping: exp1016
skipping: exp1017
skipping: exp1018
skipping: exp1019
skipping: exp1020
skipping: exp1021
skipping: exp1022
skipping: exp1023
skipping: exp1024
skipping: exp1025
skipping: exp1026
skipping: exp1027
skipping: exp1028
skipping: exp1029
skipping: exp1030
skipping: exp1031
skipping: exp1032
skipping: exp1033
skipping: exp1034
skipping: exp1035
skipping: exp1036
skipping: exp1037
skipping: exp1038
skipping: exp1039
skipping: exp1040
general_decimal_arithmetic/test_cases/subset_arithmetic/exp0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: fma0001
skipping: fma2021
skipping: fma2050
skipping: fma2051
skipping: fma2052
skipping: fma2053
skipping: fma2054
skipping: fma39990
skipping: fma39991
general_decimal_arithmetic/test_cases/subset_arithmetic/fma0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: inx101
skipping: inx102
skipping: inx103
skipping: inx104
skipping: inx105
skipping: inx106
skipping: inx107
skipping: inx108
skipping: inx109
context {
    rounding     : 4
    precision    : 4
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: inx201
skipping: inx202
skipping: inx203
skipping: inx204
skipping: inx205
skipping: inx206
skipping: inx207
skipping: inx208
skipping: inx209
skipping: inx210
skipping: inx211
skipping: inx220
skipping: inx221
skipping: inx222
skipping: inx223
skipping: inx224
skipping: inx225
skipping: inx226
skipping: inx227
context {
    rounding     : 4
    precision    : 4
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: inx301
skipping: inx302
skipping: inx303
skipping: inx304
skipping: inx305
context {
    rounding     : 4
    precision    : 4
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: inx401
skipping: inx402
skipping: inx403
skipping: inx404
skipping: inx405
skipping: inx406
skipping: inx407
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: inx801
skipping: inx802
skipping: inx803
skipping: inx804
skipping: inx805
skipping: inx806
general_decimal_arithmetic/test_cases/subset_arithmetic/inexact0.decTest
context {
    rounding     : 
    precision    : 16
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : 
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln0001
skipping: ln0002
skipping: ln0003
skipping: ln0004
skipping: ln0005
skipping: ln0006
skipping: ln0007
skipping: ln0008
skipping: ln0009
skipping: ln0010
skipping: ln0011
skipping: ln0012
skipping: ln0013
skipping: ln0014
skipping: ln0015
skipping: ln0016
skipping: ln0021
skipping: ln0022
skipping: ln0023
skipping: ln0024
skipping: ln0025
skipping: ln0026
skipping: ln0027
skipping: ln0029
skipping: ln0028
skipping: ln0030
skipping: ln0031
skipping: ln0032
skipping: ln0033
skipping: ln0034
skipping: ln0041
skipping: ln0042
skipping: ln0043
skipping: ln0050
skipping: ln0051
skipping: ln0052
skipping: ln0053
skipping: ln0054
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln0101
skipping: ln0102
skipping: ln0103
skipping: ln0104
skipping: ln0105
skipping: ln0106
skipping: ln0107
skipping: ln0108
skipping: ln0111
skipping: ln0112
skipping: ln0113
skipping: ln0114
skipping: ln0115
skipping: ln0116
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln0901
skipping: ln0902
skipping: ln0903
skipping: ln0904
skipping: ln0905
skipping: ln0906
skipping: ln0910
skipping: ln0911
skipping: ln0912
skipping: ln0913
skipping: ln0914
skipping: ln0915
skipping: ln0916
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln1501
skipping: ln1502
skipping: ln1503
skipping: ln1504
skipping: ln1505
skipping: ln1506
skipping: ln1507
skipping: ln1508
skipping: ln1509
skipping: ln1510
skipping: ln1511
skipping: ln1512
skipping: ln1513
skipping: ln1514
skipping: ln1515
skipping: ln1516
skipping: ln1517
skipping: ln1518
skipping: ln1519
skipping: ln1520
skipping: ln1521
skipping: ln1522
skipping: ln1523
skipping: ln1524
skipping: ln1525
skipping: ln1526
skipping: ln1527
skipping: ln1528
skipping: ln1529
skipping: ln1530
skipping: ln1531
skipping: ln1532
skipping: ln1533
skipping: ln1534
skipping: ln1535
skipping: ln1536
skipping: ln1537
skipping: ln1538
skipping: ln1539
skipping: ln1540
context {
    rounding     : 4
    precision    : 34
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln1201
skipping: ln1202
skipping: ln1203
skipping: ln1204
skipping: ln1205
skipping: ln1206
skipping: ln1207
skipping: ln1208
skipping: ln1209
skipping: ln1210
skipping: ln1211
skipping: ln1212
skipping: ln1213
skipping: ln1214
skipping: ln1215
skipping: ln1216
skipping: ln1217
skipping: ln1218
skipping: ln1219
skipping: ln1220
skipping: ln1221
skipping: ln1222
skipping: ln1223
skipping: ln1224
skipping: ln1225
skipping: ln1226
skipping: ln1227
skipping: ln1228
skipping: ln1229
skipping: ln1230
skipping: ln1231
skipping: ln1232
skipping: ln1233
skipping: ln1234
skipping: ln1235
skipping: ln1236
skipping: ln1237
skipping: ln1238
skipping: ln1239
skipping: ln1240
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln1101
skipping: ln1102
skipping: ln1103
skipping: ln1104
skipping: ln1105
skipping: ln1106
skipping: ln1107
skipping: ln1108
skipping: ln1109
skipping: ln1110
skipping: ln1111
skipping: ln1112
skipping: ln1113
skipping: ln1114
skipping: ln1115
skipping: ln1116
skipping: ln1117
skipping: ln1118
skipping: ln1119
skipping: ln1120
skipping: ln1121
skipping: ln1122
skipping: ln1123
skipping: ln1124
skipping: ln1125
skipping: ln1126
skipping: ln1127
skipping: ln1128
skipping: ln1129
skipping: ln1130
skipping: ln1131
skipping: ln1132
skipping: ln1133
skipping: ln1134
skipping: ln1135
skipping: ln1136
skipping: ln1137
skipping: ln1138
skipping: ln1139
skipping: ln1140
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln1001
skipping: ln1002
skipping: ln1003
skipping: ln1004
skipping: ln1005
skipping: ln1006
skipping: ln1007
skipping: ln1008
skipping: ln1009
skipping: ln1010
skipping: ln1011
skipping: ln1012
skipping: ln1013
skipping: ln1014
skipping: ln1015
skipping: ln1016
skipping: ln1017
skipping: ln1018
skipping: ln1019
skipping: ln1020
skipping: ln1021
skipping: ln1022
skipping: ln1023
skipping: ln1024
skipping: ln1025
skipping: ln1026
skipping: ln1027
skipping: ln1028
skipping: ln1029
skipping: ln1030
skipping: ln1031
skipping: ln1032
skipping: ln1033
skipping: ln1034
skipping: ln1035
skipping: ln1036
skipping: ln1037
skipping: ln1038
skipping: ln1039
skipping: ln1040
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln001
skipping: ln002
skipping: ln003
skipping: ln005
skipping: ln006
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln011
skipping: ln012
skipping: ln013
skipping: ln014
skipping: ln015
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln041
skipping: ln042
skipping: ln043
skipping: ln044
skipping: ln045
skipping: ln046
skipping: ln048
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln055
context {
    rounding     : 4
    precision    : 17
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln056
context {
    rounding     : 4
    precision    : 18
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln057
context {
    rounding     : 4
    precision    : 19
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln058
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln059
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln102
context {
    rounding     : 4
    precision    : 30
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln103
context {
    rounding     : 4
    precision    : 29
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln104
context {
    rounding     : 4
    precision    : 28
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln105
context {
    rounding     : 4
    precision    : 27
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln106
context {
    rounding     : 4
    precision    : 26
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln107
context {
    rounding     : 4
    precision    : 25
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln108
context {
    rounding     : 4
    precision    : 24
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln109
context {
    rounding     : 4
    precision    : 23
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln110
context {
    rounding     : 4
    precision    : 22
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln111
context {
    rounding     : 4
    precision    : 21
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln112
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln113
context {
    rounding     : 4
    precision    : 19
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln114
context {
    rounding     : 4
    precision    : 18
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln115
context {
    rounding     : 4
    precision    : 17
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln116
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln117
context {
    rounding     : 4
    precision    : 15
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln118
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln119
context {
    rounding     : 4
    precision    : 13
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln120
context {
    rounding     : 4
    precision    : 12
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln121
context {
    rounding     : 4
    precision    : 11
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln122
context {
    rounding     : 4
    precision    : 10
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln123
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln124
context {
    rounding     : 4
    precision    : 8
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln125
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln126
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln126b
context {
    rounding     : 4
    precision    : 6
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln127
context {
    rounding     : 4
    precision    : 5
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln128
context {
    rounding     : 4
    precision    : 4
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln129
context {
    rounding     : 4
    precision    : 3
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln130
context {
    rounding     : 4
    precision    : 2
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln131
context {
    rounding     : 4
    precision    : 1
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln132
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln401
skipping: ln402
skipping: ln403
skipping: ln404
skipping: ln405
skipping: ln406
skipping: ln407
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln411
skipping: ln413
skipping: ln416
skipping: ln417
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln709
skipping: ln711
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln722
skipping: ln724
skipping: ln726
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln751
skipping: ln758
skipping: ln759
skipping: ln760
skipping: ln761
skipping: ln762
skipping: ln763
skipping: ln764
skipping: ln765
skipping: ln766
skipping: ln774
context {
    rounding     : 4
    precision    : 100000000
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln901
context {
    rounding     : 4
    precision    : 99999999
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln902
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 1000000
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 1000000
    clamp:       : 0
}
skipping: ln903
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: ln904
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -1000000
    max exponent : 999999
    clamp:       : 0
}
skipping: ln905
context {
    rounding     : 4
    precision    : 9
    min exponent : -1000000
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999998
    max exponent : 999999
    clamp:       : 0
}
skipping: ln906
context {
    rounding     : 4
    precision    : 9
    min exponent : -999998
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: ln900
general_decimal_arithmetic/test_cases/subset_arithmetic/ln0.decTest
context {
    rounding     : 
    precision    : 16
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : 
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log0000
skipping: log0001
skipping: log0002
skipping: log0003
skipping: log0004
skipping: log0005
skipping: log0006
skipping: log0007
skipping: log0008
skipping: log0009
skipping: log0010
skipping: log0011
skipping: log0012
skipping: log0013
skipping: log0014
skipping: log0015
skipping: log0016
skipping: log0017
skipping: log0018
skipping: log0019
skipping: log0020
skipping: log0031
skipping: log0032
skipping: log0033
skipping: log0034
skipping: log0035
skipping: log0036
skipping: log0037
skipping: log0038
skipping: log0039
skipping: log0040
skipping: log0041
skipping: log0042
skipping: log0043
skipping: log0044
skipping: log0051
skipping: log0052
skipping: log0053
skipping: log0061
skipping: log0062
skipping: log0063
skipping: log0064
skipping: log1100
skipping: log1101
skipping: log1102
skipping: log1103
skipping: log1104
skipping: log1105
skipping: log1106
skipping: log1107
skipping: log1108
skipping: log1109
skipping: log1110
skipping: log1111
skipping: log1112
context {
    rounding     : 4
    precision    : 1
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1141
skipping: log1142
skipping: log1143
skipping: log1144
skipping: log1145
skipping: log1146
skipping: log1147
context {
    rounding     : 4
    precision    : 2
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1151
skipping: log1152
skipping: log1153
skipping: log1154
skipping: log1155
skipping: log1156
skipping: log1157
context {
    rounding     : 4
    precision    : 3
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1161
skipping: log1162
skipping: log1163
skipping: log1164
skipping: log1165
skipping: log1166
skipping: log1167
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1201
skipping: log1202
skipping: log1203
context {
    rounding     : 4
    precision    : 49
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1204
context {
    rounding     : 4
    precision    : 48
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1205
context {
    rounding     : 4
    precision    : 47
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1206
context {
    rounding     : 4
    precision    : 46
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1207
context {
    rounding     : 4
    precision    : 45
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1208
context {
    rounding     : 4
    precision    : 44
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1209
context {
    rounding     : 4
    precision    : 43
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1210
context {
    rounding     : 4
    precision    : 42
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1211
context {
    rounding     : 4
    precision    : 41
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1212
context {
    rounding     : 4
    precision    : 40
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1213
context {
    rounding     : 4
    precision    : 39
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1214
context {
    rounding     : 4
    precision    : 38
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1215
context {
    rounding     : 4
    precision    : 37
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1216
context {
    rounding     : 4
    precision    : 36
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1217
context {
    rounding     : 4
    precision    : 35
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1218
context {
    rounding     : 4
    precision    : 34
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1219
context {
    rounding     : 4
    precision    : 33
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1220
context {
    rounding     : 4
    precision    : 32
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1221
context {
    rounding     : 4
    precision    : 31
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1222
context {
    rounding     : 4
    precision    : 30
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1223
context {
    rounding     : 4
    precision    : 29
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1224
context {
    rounding     : 4
    precision    : 28
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1225
context {
    rounding     : 4
    precision    : 27
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1226
context {
    rounding     : 4
    precision    : 26
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1227
context {
    rounding     : 4
    precision    : 25
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1228
context {
    rounding     : 4
    precision    : 24
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1229
context {
    rounding     : 4
    precision    : 23
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1230
context {
    rounding     : 4
    precision    : 22
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1231
context {
    rounding     : 4
    precision    : 21
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1232
context {
    rounding     : 4
    precision    : 20
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1233
context {
    rounding     : 4
    precision    : 19
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1234
context {
    rounding     : 4
    precision    : 18
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1235
context {
    rounding     : 4
    precision    : 17
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1236
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1237
context {
    rounding     : 4
    precision    : 15
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1238
context {
    rounding     : 4
    precision    : 14
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1239
context {
    rounding     : 4
    precision    : 13
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1240
context {
    rounding     : 4
    precision    : 12
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1241
context {
    rounding     : 4
    precision    : 11
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1242
context {
    rounding     : 4
    precision    : 10
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1243
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1244
context {
    rounding     : 4
    precision    : 8
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1245
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1246
context {
    rounding     : 4
    precision    : 6
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1247
context {
    rounding     : 4
    precision    : 5
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1248
context {
    rounding     : 4
    precision    : 4
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1249
context {
    rounding     : 4
    precision    : 3
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1250
context {
    rounding     : 4
    precision    : 2
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1251
context {
    rounding     : 4
    precision    : 1
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1252
context {
    rounding     : 4
    precision    : 1
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 1
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 34
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1301
skipping: log1302
skipping: log1303
skipping: log1304
skipping: log1305
skipping: log1306
skipping: log1307
skipping: log1308
skipping: log1309
skipping: log1310
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log1320
skipping: log1321
skipping: log1322
skipping: log1323
skipping: log1324
skipping: log1325
skipping: log1326
skipping: log1327
context {
    rounding     : 4
    precision    : 50
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log2501
skipping: log2502
skipping: log2503
skipping: log2504
skipping: log2505
skipping: log2506
skipping: log2507
skipping: log2508
skipping: log2509
skipping: log2510
skipping: log2511
skipping: log2512
skipping: log2513
skipping: log2514
skipping: log2515
skipping: log2516
skipping: log2517
skipping: log2518
skipping: log2519
skipping: log2520
skipping: log2521
skipping: log2522
skipping: log2523
skipping: log2524
skipping: log2525
skipping: log2526
skipping: log2527
skipping: log2528
skipping: log2529
skipping: log2530
skipping: log2531
skipping: log2532
skipping: log2533
skipping: log2534
skipping: log2535
skipping: log2536
skipping: log2537
skipping: log2538
skipping: log2539
skipping: log2540
context {
    rounding     : 4
    precision    : 34
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log2201
skipping: log2202
skipping: log2203
skipping: log2204
skipping: log2205
skipping: log2206
skipping: log2207
skipping: log2208
skipping: log2209
skipping: log2210
skipping: log2211
skipping: log2212
skipping: log2213
skipping: log2214
skipping: log2215
skipping: log2216
skipping: log2217
skipping: log2218
skipping: log2219
skipping: log2220
skipping: log2221
skipping: log2222
skipping: log2223
skipping: log2224
skipping: log2225
skipping: log2226
skipping: log2227
skipping: log2228
skipping: log2229
skipping: log2230
skipping: log2231
skipping: log2232
skipping: log2233
skipping: log2234
skipping: log2235
skipping: log2236
skipping: log2237
skipping: log2238
skipping: log2239
skipping: log2240
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log2101
skipping: log2102
skipping: log2103
skipping: log2104
skipping: log2105
skipping: log2106
skipping: log2107
skipping: log2108
skipping: log2109
skipping: log2110
skipping: log2111
skipping: log2112
skipping: log2113
skipping: log2114
skipping: log2115
skipping: log2116
skipping: log2117
skipping: log2118
skipping: log2119
skipping: log2120
skipping: log2121
skipping: log2122
skipping: log2123
skipping: log2124
skipping: log2125
skipping: log2126
skipping: log2127
skipping: log2128
skipping: log2129
skipping: log2130
skipping: log2131
skipping: log2132
skipping: log2133
skipping: log2134
skipping: log2135
skipping: log2136
skipping: log2137
skipping: log2138
skipping: log2139
skipping: log2140
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log2001
skipping: log2002
skipping: log2003
skipping: log2004
skipping: log2005
skipping: log2006
skipping: log2007
skipping: log2008
skipping: log2009
skipping: log2010
skipping: log2011
skipping: log2012
skipping: log2013
skipping: log2014
skipping: log2015
skipping: log2016
skipping: log2017
skipping: log2018
skipping: log2019
skipping: log2020
skipping: log2021
skipping: log2022
skipping: log2023
skipping: log2024
skipping: log2025
skipping: log2026
skipping: log2027
skipping: log2028
skipping: log2029
skipping: log2030
skipping: log2031
skipping: log2032
skipping: log2033
skipping: log2034
skipping: log2035
skipping: log2036
skipping: log2037
skipping: log2038
skipping: log2039
skipping: log2040
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 100000000
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log901
context {
    rounding     : 4
    precision    : 99999999
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: log902
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 1000000
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 1000000
    clamp:       : 0
}
skipping: log903
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: log904
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -1000000
    max exponent : 999999
    clamp:       : 0
}
skipping: log905
context {
    rounding     : 4
    precision    : 9
    min exponent : -1000000
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999998
    max exponent : 999999
    clamp:       : 0
}
skipping: log906
skipping: log900
general_decimal_arithmetic/test_cases/subset_arithmetic/log100.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: max001
skipping: max002
skipping: max003
skipping: max004
skipping: max005
skipping: max006
skipping: max007
skipping: max008
skipping: max009
skipping: max010
skipping: max011
skipping: max012
skipping: max013
skipping: max014
skipping: max015
skipping: max016
skipping: max017
skipping: max018
skipping: max019
skipping: max020
skipping: max021
skipping: max022
skipping: max023
skipping: max025
skipping: max026
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: max101
skipping: max102
skipping: max103
skipping: max104
skipping: max105
skipping: max106
skipping: max107
skipping: max108
skipping: max109
skipping: max110
skipping: max111
skipping: max112
skipping: max113
skipping: max114
skipping: max115
skipping: max116
skipping: max117
skipping: max118
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: max121
skipping: max122
skipping: max123
skipping: max124
skipping: max125
skipping: max126
skipping: max127
skipping: max128
skipping: max129
skipping: max130
skipping: max131
skipping: max132
skipping: max133
skipping: max134
skipping: max135
skipping: max136
skipping: max137
skipping: max138
skipping: max180
skipping: max181
skipping: max182
skipping: max183
skipping: max900
skipping: max901
general_decimal_arithmetic/test_cases/subset_arithmetic/max0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mnm001
skipping: mnm002
skipping: mnm003
skipping: mnm004
skipping: mnm005
skipping: mnm006
skipping: mnm007
skipping: mnm008
skipping: mnm009
skipping: mnm010
skipping: mnm011
skipping: mnm012
skipping: mnm013
skipping: mnm014
skipping: mnm015
skipping: mnm016
skipping: mnm017
skipping: mnm018
skipping: mnm019
skipping: mnm020
skipping: mnm021
skipping: mnm022
skipping: mnm023
skipping: mnm025
skipping: mnm026
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mnm101
skipping: mnm102
skipping: mnm103
skipping: mnm104
skipping: mnm105
skipping: mnm106
skipping: mnm107
skipping: mnm108
skipping: mnm109
skipping: mnm110
skipping: mnm111
skipping: mnm112
skipping: mnm113
skipping: mnm114
skipping: mnm115
skipping: mnm116
skipping: mnm117
skipping: mnm118
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mnm121
skipping: mnm122
skipping: mnm123
skipping: mnm124
skipping: mnm125
skipping: mnm126
skipping: mnm127
skipping: mnm128
skipping: mnm129
skipping: mnm130
skipping: mnm131
skipping: mnm132
skipping: mnm133
skipping: mnm134
skipping: mnm135
skipping: mnm136
skipping: mnm137
skipping: mnm138
skipping: mnm180
skipping: mnm181
skipping: mnm182
skipping: mnm183
skipping: mnm900
skipping: mnm901
general_decimal_arithmetic/test_cases/subset_arithmetic/min0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min001
skipping: min002
skipping: min003
skipping: min004
skipping: min005
skipping: min006
skipping: min007
skipping: min008
skipping: min009
skipping: min010
skipping: min011
skipping: min012
skipping: min013
skipping: min014
skipping: min015
skipping: min016
skipping: min017
skipping: min018
skipping: min020
skipping: min021
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min022
skipping: min023
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min024
skipping: min025
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min026
skipping: min027
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min060
skipping: min061
skipping: min062
skipping: min063
skipping: min065
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: min120
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min301
skipping: min302
skipping: min303
skipping: min304
skipping: min305
skipping: min306
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: min321
skipping: min322
skipping: min323
skipping: min324
skipping: min325
skipping: min326
skipping: min400
general_decimal_arithmetic/test_cases/subset_arithmetic/minus0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul000
skipping: mul001
skipping: mul002
skipping: mul003
skipping: mul004
skipping: mul005
skipping: mul006
skipping: mul007
skipping: mul008
skipping: mul009
skipping: mul010
skipping: mul011
skipping: mul012
skipping: mul013
skipping: mul014
skipping: mul015
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul016
skipping: mul017
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul031
skipping: mul032
skipping: mul033
skipping: mul034
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul039
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul050
skipping: mul051
skipping: mul052
skipping: mul053
skipping: mul054
skipping: mul055
skipping: mul056
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul080
skipping: mul081
skipping: mul082
skipping: mul083
skipping: mul084
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul085
skipping: mul086
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul087
skipping: mul088
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul090
skipping: mul091
skipping: mul092
skipping: mul093
skipping: mul094
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul095
skipping: mul096
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul097
skipping: mul098
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 33
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
skipping: mul101
skipping: mul102
skipping: mul103
skipping: mul104
skipping: mul105
skipping: mul106
skipping: mul107
skipping: mul108
skipping: mul109
skipping: mul110
skipping: mul111
skipping: mul112
skipping: mul113
skipping: mul114
skipping: mul115
skipping: mul116
skipping: mul117
skipping: mul118
skipping: mul119
skipping: mul120
skipping: mul121
skipping: mul122
skipping: mul123
skipping: mul131
skipping: mul132
skipping: mul133
skipping: mul134
skipping: mul135
skipping: mul136
skipping: mul137
skipping: mul138
skipping: mul139
skipping: mul140
skipping: mul141
skipping: mul142
skipping: mul143
skipping: mul144
skipping: mul145
skipping: mul146
skipping: mul147
skipping: mul148
skipping: mul149
skipping: mul150
skipping: mul151
skipping: mul152
skipping: mul153
context {
    rounding     : 4
    precision    : 30
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
skipping: mul160
context {
    rounding     : 4
    precision    : 9
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -9999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: mul170
skipping: mul171
skipping: mul172
skipping: mul173
skipping: mul174
skipping: mul176
skipping: mul177
skipping: mul178
skipping: mul180
skipping: mul181
skipping: mul182
skipping: mul183
skipping: mul184
skipping: mul185
skipping: mul186
skipping: mul187
skipping: mul188
skipping: mul190
skipping: mul191
skipping: mul192
skipping: mul193
skipping: mul194
skipping: mul195
skipping: mul196
skipping: mul197
skipping: mul198
skipping: mul199
skipping: mul201
skipping: mul202
skipping: mul203
skipping: mul204
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: mul230
skipping: mul231
skipping: mul232
skipping: mul233
skipping: mul235
skipping: mul236
skipping: mul237
skipping: mul238
skipping: mul239
skipping: mul240
skipping: mul241
skipping: mul242
skipping: mul243
skipping: mul244
skipping: mul245
skipping: mul246
skipping: mul247
skipping: mul248
skipping: mul249
skipping: mul250
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: mul260
skipping: mul261
skipping: mul262
skipping: mul263
skipping: mul264
skipping: mul265
skipping: mul266
skipping: mul267
skipping: mul268
skipping: mul269
skipping: mul270
skipping: mul271
skipping: mul272
skipping: mul273
skipping: mul274
skipping: mul275
skipping: mul276
skipping: mul277
skipping: mul278
skipping: mul279
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul301
skipping: mul302
skipping: mul303
skipping: mul304
skipping: mul305
skipping: mul306
skipping: mul307
skipping: mul308
skipping: mul309
skipping: mul310
skipping: mul311
skipping: mul312
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: mul341
skipping: mul342
skipping: mul343
skipping: mul344
skipping: mul345
skipping: mul346
skipping: mul347
skipping: mul348
skipping: mul349
skipping: mul350
skipping: mul351
skipping: mul352
skipping: mul400
skipping: mul401
general_decimal_arithmetic/test_cases/subset_arithmetic/multiply0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu001
skipping: plu002
skipping: plu003
skipping: plu004
skipping: plu005
skipping: plu006
skipping: plu007
skipping: plu008
skipping: plu009
skipping: plu010
skipping: plu011
skipping: plu012
skipping: plu013
skipping: plu014
skipping: plu015
skipping: plu016
skipping: plu017
skipping: plu018
skipping: plu020
skipping: plu021
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu022
skipping: plu023
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu024
skipping: plu025
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu026
skipping: plu027
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu060
skipping: plu061
skipping: plu062
skipping: plu063
skipping: plu065
skipping: plu066
skipping: plu067
skipping: plu068
skipping: plu069
skipping: plu070
skipping: plu071
skipping: plu072
skipping: plu080
skipping: plu081
skipping: plu082
skipping: plu083
skipping: plu085
skipping: plu086
skipping: plu087
skipping: plu088
skipping: plu089
skipping: plu090
skipping: plu091
skipping: plu092
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: plu120
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu301
skipping: plu302
skipping: plu303
skipping: plu304
skipping: plu305
skipping: plu306
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: plu321
skipping: plu322
skipping: plu323
skipping: plu324
skipping: plu325
skipping: plu326
skipping: plu400
general_decimal_arithmetic/test_cases/subset_arithmetic/plus0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: pow001
skipping: pow002
skipping: pow003
skipping: pow004
skipping: pow005
skipping: pow006
skipping: pow010
skipping: pow011
skipping: pow012
skipping: pow013
skipping: pow014
skipping: pow015
skipping: pow016
skipping: pow017
skipping: pow018
skipping: pow019
skipping: pow020
skipping: pow021
skipping: pow022
skipping: pow023
skipping: pow024
skipping: pow025
skipping: pow026
context {
    rounding     : 4
    precision    : 10
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: pow027
skipping: pow028
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: pow030
skipping: pow031
skipping: pow032
skipping: pow033
skipping: pow034
skipping: pow035
skipping: pow036
skipping: pow037
skipping: pow038
skipping: pow039
skipping: pow040
skipping: pow041
skipping: pow042
skipping: pow043
skipping: pow044
skipping: pow050
skipping: pow051
skipping: pow052
skipping: pow053
skipping: pow054
skipping: pow055
skipping: pow056
skipping: pow057
skipping: pow058
skipping: pow059
skipping: pow060
skipping: pow061
skipping: pow062
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: pow063
skipping: pow064
skipping: pow065
skipping: pow066
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow070
skipping: pow071
skipping: pow072
skipping: pow073
skipping: pow074
skipping: pow075
skipping: pow076
skipping: pow077
skipping: pow080
skipping: pow081
skipping: pow082
skipping: pow083
skipping: pow084
skipping: pow085
skipping: pow086
skipping: pow087
skipping: pow088
skipping: pow089
skipping: pow090
skipping: pow091
skipping: pow092
skipping: pow093
skipping: pow094
skipping: pow095
skipping: pow100
skipping: pow101
skipping: pow102
skipping: pow103
skipping: pow104
skipping: pow105
skipping: pow106
skipping: pow108
skipping: pow110
skipping: pow111
skipping: pow112
skipping: pow113
skipping: pow114
skipping: pow115
skipping: pow116
skipping: pow117
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: pow118
skipping: pow119
skipping: pow120
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow121
skipping: pow122
skipping: pow123
skipping: pow124
skipping: pow125
skipping: pow126
skipping: pow127
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: pow181
skipping: pow182
skipping: pow183
skipping: pow184
skipping: pow186
skipping: pow187
skipping: pow189
skipping: pow190
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow200
skipping: pow201
skipping: pow202
skipping: pow203
skipping: pow204
skipping: pow205
skipping: pow206
skipping: pow207
skipping: pow208
skipping: pow209
skipping: pow210
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: pow215
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: pow216
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 20
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow220
context {
    rounding     : 4
    precision    : 5
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow240
skipping: pow241
skipping: pow242
skipping: pow243
skipping: pow244
context {
    rounding     : 4
    precision    : 999999999
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow250
context {
    rounding     : 4
    precision    : 999999998
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow251
context {
    rounding     : 4
    precision    : 999999997
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow252
context {
    rounding     : 4
    precision    : 999999996
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow253
context {
    rounding     : 4
    precision    : 999999995
    min exponent : -999999
    max exponent : 999999
    clamp:       : 0
}
skipping: pow254
context {
    rounding     : 4
    precision    : 999999995
    min exponent : -999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 999999995
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: pow260
skipping: pow261
skipping: pow262
skipping: pow263
skipping: pow264
skipping: pow265
skipping: pow266
skipping: pow267
skipping: pow268
skipping: pow269
skipping: pow270
skipping: pow271
skipping: pow272
skipping: pow273
skipping: pow274
skipping: pow275
skipping: pow277
skipping: pow278
skipping: pow279
skipping: pow310
skipping: pow311
skipping: pow312
skipping: pow313
skipping: pow314
skipping: pow315
skipping: pow316
skipping: pow317
skipping: pow318
skipping: pow319
skipping: pow320
skipping: pow321
skipping: pow322
skipping: pow323
skipping: pow324
skipping: pow325
skipping: pow327
skipping: pow328
skipping: pow329
skipping: pow330
skipping: pow331
skipping: pow332
skipping: pow333
skipping: pow334
skipping: pow335
skipping: pow336
skipping: pow337
skipping: pow338
skipping: pow339
skipping: pow340
skipping: pow341
skipping: pow342
skipping: pow343
skipping: pow344
skipping: pow345
skipping: pow347
skipping: pow348
skipping: pow349
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: pow401
skipping: pow402
skipping: pow403
skipping: pow404
skipping: pow405
skipping: pow406
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: pow441
skipping: pow442
skipping: pow443
skipping: pow444
skipping: pow445
skipping: pow446
skipping: pow447
skipping: pow448
skipping: pow449
skipping: pow440
skipping: pow500
skipping: pow501
context {
    rounding     : 4
    precision    : 16
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -999
    max exponent : 384
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 16
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: pow2000
skipping: pow2001
skipping: pow2002
skipping: pow2003
skipping: pow2004
skipping: pow2005
skipping: pow2006
skipping: pow2007
skipping: pow2008
skipping: pow2009
skipping: pow2010
skipping: pow2011
context {
    rounding     : 4
    precision    : 4
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: pow2012
context {
    rounding     : 4
    precision    : 3
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: pow2013
skipping: pow2014
skipping: pow2015
skipping: pow2016
skipping: pow2017
skipping: pow2018
skipping: pow2019
context {
    rounding     : 4
    precision    : 9
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: pow2030
skipping: pow2031
skipping: pow2032
skipping: pow2033
context {
    rounding     : 4
    precision    : 5
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: pow2034
skipping: pow2035
skipping: pow2036
skipping: pow2037
skipping: pow2038
context {
    rounding     : 4
    precision    : 15
    min exponent : -383
    max exponent : 384
    clamp:       : 0
}
skipping: pow2041
skipping: pow2042
skipping: pow2043
skipping: pow2044
skipping: pow2045
skipping: pow2046
skipping: pow2047
skipping: pow2048
skipping: pow2049
skipping: pow2051
skipping: pow2052
skipping: pow2053
skipping: pow2054
skipping: pow2055
skipping: pow2056
general_decimal_arithmetic/test_cases/subset_arithmetic/power0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua001
skipping: qua002
skipping: qua003
skipping: qua005
skipping: qua006
skipping: qua007
skipping: qua008
skipping: qua009
skipping: qua010
skipping: qua011
skipping: qua012
skipping: qua013
skipping: qua014
skipping: qua015
skipping: qua021
skipping: qua022
skipping: qua023
skipping: qua025
skipping: qua026
skipping: qua027
skipping: qua028
skipping: qua029
skipping: qua030
skipping: qua031
skipping: qua032
skipping: qua033
skipping: qua034
skipping: qua035
skipping: qua036
skipping: qua037
skipping: qua038
skipping: qua039
skipping: qua040
skipping: qua041
skipping: qua042
skipping: qua043
skipping: qua044
skipping: qua045
skipping: qua046
skipping: qua047
skipping: qua060
skipping: qua061
skipping: qua062
skipping: qua063
skipping: qua064
skipping: qua066
skipping: qua067
skipping: qua068
skipping: qua069
skipping: qua070
skipping: qua071
skipping: qua072
skipping: qua073
skipping: qua089
skipping: qua090
skipping: qua091
skipping: qua092
skipping: qua093
skipping: qua094
skipping: qua095
skipping: qua096
skipping: qua097
skipping: qua098
skipping: qua099
skipping: qua100
skipping: qua101
skipping: qua102
skipping: qua103
skipping: qua104
skipping: qua105
skipping: qua106
skipping: qua107
skipping: qua108
skipping: qua109
skipping: qua110
skipping: qua111
skipping: qua112
skipping: qua120
skipping: qua121
skipping: qua122
skipping: qua123
skipping: qua124
skipping: qua125
skipping: qua126
skipping: qua127
skipping: qua128
skipping: qua129
skipping: qua130
skipping: qua131
skipping: qua132
skipping: qua133
skipping: qua134
skipping: qua135
skipping: qua140
skipping: qua141
skipping: qua142
skipping: qua143
skipping: qua144
skipping: qua145
skipping: qua146
skipping: qua147
skipping: qua148
skipping: qua150
skipping: qua151
skipping: qua152
skipping: qua153
skipping: qua154
skipping: qua155
skipping: qua161
skipping: qua162
skipping: qua163
skipping: qua165
skipping: qua166
skipping: qua167
skipping: qua168
skipping: qua169
skipping: qua170
skipping: qua171
skipping: qua172
skipping: qua173
skipping: qua174
skipping: qua175
skipping: qua181
skipping: qua182
skipping: qua183
skipping: qua185
skipping: qua186
skipping: qua187
skipping: qua188
skipping: qua189
skipping: qua190
skipping: qua191
skipping: qua192
skipping: qua193
skipping: qua194
skipping: qua201
skipping: qua202
skipping: qua203
skipping: qua204
skipping: qua205
skipping: qua206
skipping: qua207
skipping: qua208
skipping: qua209
skipping: qua220
skipping: qua221
skipping: qua222
skipping: qua223
skipping: qua224
skipping: qua225
skipping: qua226
skipping: qua227
skipping: qua228
skipping: qua229
skipping: qua230
skipping: qua231
skipping: qua232
skipping: qua233
skipping: qua234
skipping: qua235
skipping: qua240
skipping: qua241
skipping: qua242
skipping: qua243
skipping: qua244
skipping: qua245
skipping: qua246
skipping: qua247
skipping: qua248
skipping: qua249
skipping: qua250
skipping: qua251
skipping: qua252
skipping: qua253
skipping: qua254
skipping: qua255
skipping: qua256
skipping: qua257
skipping: qua258
skipping: qua259
skipping: qua260
skipping: qua261
skipping: qua262
skipping: qua263
skipping: qua264
skipping: qua265
skipping: qua266
skipping: qua267
skipping: qua268
skipping: qua269
skipping: qua270
skipping: qua271
skipping: qua272
skipping: qua273
skipping: qua274
skipping: qua275
skipping: qua280
skipping: qua281
skipping: qua282
skipping: qua283
skipping: qua284
skipping: qua285
skipping: qua286
skipping: qua287
skipping: qua288
skipping: qua289
skipping: qua290
skipping: qua291
skipping: qua292
skipping: qua293
skipping: qua294
skipping: qua295
skipping: qua300
skipping: qua301
skipping: qua302
skipping: qua303
skipping: qua304
skipping: qua305
skipping: qua306
skipping: qua307
skipping: qua310
skipping: qua311
skipping: qua312
skipping: qua313
skipping: qua314
skipping: qua315
skipping: qua316
skipping: qua317
skipping: qua320
skipping: qua321
skipping: qua322
skipping: qua323
skipping: qua324
skipping: qua325
skipping: qua326
skipping: qua327
skipping: qua330
skipping: qua331
skipping: qua332
skipping: qua333
skipping: qua334
skipping: qua335
skipping: qua336
skipping: qua337
skipping: qua340
skipping: qua341
skipping: qua342
skipping: qua343
skipping: qua344
skipping: qua345
skipping: qua346
skipping: qua347
skipping: qua350
skipping: qua351
skipping: qua352
skipping: qua353
skipping: qua354
skipping: qua355
skipping: qua356
skipping: qua357
skipping: qua360
skipping: qua361
skipping: qua362
skipping: qua363
skipping: qua364
skipping: qua365
skipping: qua366
skipping: qua367
skipping: qua368
skipping: qua370
skipping: qua371
skipping: qua372
skipping: qua373
skipping: qua374
skipping: qua375
skipping: qua376
skipping: qua377
skipping: qua378
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua380
skipping: qua381
skipping: qua382
skipping: qua383
skipping: qua384
skipping: qua385
skipping: qua386
skipping: qua387
context {
    rounding     : 1
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua389
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua391
skipping: qua392
skipping: qua393
skipping: qua394
skipping: qua395
skipping: qua396
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua400
skipping: qua401
skipping: qua402
skipping: qua403
skipping: qua404
skipping: qua405
skipping: qua406
skipping: qua407
skipping: qua410
skipping: qua411
skipping: qua412
skipping: qua413
skipping: qua414
skipping: qua415
skipping: qua416
skipping: qua420
skipping: qua421
skipping: qua422
skipping: qua423
skipping: qua424
skipping: qua425
skipping: qua426
skipping: qua430
skipping: qua431
skipping: qua432
skipping: qua433
skipping: qua434
skipping: qua435
skipping: qua436
skipping: qua440
skipping: qua441
skipping: qua442
skipping: qua443
skipping: qua444
skipping: qua445
skipping: qua446
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua449
skipping: qua450
skipping: qua451
skipping: qua452
skipping: qua453
skipping: qua454
skipping: qua455
skipping: qua456
skipping: qua457
skipping: qua458
skipping: qua459
skipping: qua460
skipping: qua461
skipping: qua462
skipping: qua463
skipping: qua464
skipping: qua465
skipping: qua466
skipping: qua467
skipping: qua468
skipping: qua469
skipping: qua470
skipping: qua471
skipping: qua472
skipping: qua473
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua481
skipping: qua482
skipping: qua483
skipping: qua484
skipping: qua485
skipping: qua486
skipping: qua487
skipping: qua488
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua491
skipping: qua492
skipping: qua493
skipping: qua494
skipping: qua495
skipping: qua496
skipping: qua497
skipping: qua498
skipping: qua500
skipping: qua501
skipping: qua502
skipping: qua503
skipping: qua504
skipping: qua505
skipping: qua506
skipping: qua507
skipping: qua508
skipping: qua509
skipping: qua510
skipping: qua511
skipping: qua512
skipping: qua513
skipping: qua514
skipping: qua515
skipping: qua516
skipping: qua517
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: qua520
skipping: qua521
skipping: qua522
skipping: qua523
skipping: qua524
skipping: qua525
skipping: qua526
skipping: qua527
skipping: qua528
skipping: qua529
skipping: qua530
skipping: qua531
context {
    rounding     : 4
    precision    : 15
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua532
skipping: qua533
skipping: qua534
skipping: qua535
skipping: qua536
skipping: qua537
skipping: qua538
skipping: qua539
skipping: qua540
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: qua541
skipping: qua542
skipping: qua543
skipping: qua544
skipping: qua545
skipping: qua546
skipping: qua547
skipping: qua548
skipping: qua549
skipping: qua550
skipping: qua551
skipping: qua552
skipping: qua553
skipping: qua554
skipping: qua555
skipping: qua556
skipping: qua557
skipping: qua900
skipping: qua901
general_decimal_arithmetic/test_cases/subset_arithmetic/quantize0.decTest
context {
    rounding     : 
    precision    : 31
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 31
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 31
    min exponent : 
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 31
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
skipping: comr001
skipping: divr001
skipping: dvir001
skipping: mulr001
skipping: powr001
skipping: remr001
skipping: subr001
skipping: comr002
skipping: divr002
skipping: dvir002
skipping: mulr002
skipping: powr002
skipping: remr002
skipping: subr002
skipping: comr003
skipping: divr003
skipping: dvir003
skipping: mulr003
skipping: powr003
skipping: remr003
skipping: subr003
skipping: comr004
skipping: divr004
skipping: dvir004
skipping: mulr004
skipping: powr004
skipping: remr004
skipping: subr004
skipping: comr005
skipping: divr005
skipping: dvir005
skipping: mulr005
skipping: powr005
skipping: remr005
skipping: subr005
skipping: comr006
skipping: divr006
skipping: dvir006
skipping: mulr006
skipping: powr006
skipping: remr006
skipping: subr006
skipping: comr007
skipping: divr007
skipping: dvir007
skipping: mulr007
skipping: powr007
skipping: remr007
skipping: subr007
skipping: comr008
skipping: divr008
skipping: dvir008
skipping: mulr008
skipping: powr008
skipping: remr008
skipping: subr008
skipping: comr009
skipping: divr009
skipping: dvir009
skipping: mulr009
skipping: powr009
skipping: remr009
skipping: subr009
skipping: comr010
skipping: divr010
skipping: dvir010
skipping: mulr010
skipping: powr010
skipping: remr010
skipping: subr010
skipping: comr011
skipping: divr011
skipping: dvir011
skipping: mulr011
skipping: powr011
skipping: remr011
skipping: subr011
skipping: comr012
skipping: divr012
skipping: dvir012
skipping: mulr012
skipping: powr012
skipping: remr012
skipping: subr012
skipping: comr013
skipping: divr013
skipping: dvir013
skipping: mulr013
skipping: powr013
skipping: remr013
skipping: subr013
skipping: comr014
skipping: divr014
skipping: dvir014
skipping: mulr014
skipping: powr014
skipping: remr014
skipping: subr014
skipping: comr015
skipping: divr015
skipping: dvir015
skipping: mulr015
skipping: powr015
skipping: remr015
skipping: subr015
skipping: comr016
skipping: divr016
skipping: dvir016
skipping: mulr016
skipping: powr016
skipping: remr016
skipping: subr016
skipping: comr017
skipping: divr017
skipping: dvir017
skipping: mulr017
skipping: powr017
skipping: remr017
skipping: subr017
skipping: comr018
skipping: divr018
skipping: dvir018
skipping: mulr018
skipping: powr018
skipping: remr018
skipping: subr018
skipping: comr019
skipping: divr019
skipping: dvir019
skipping: mulr019
skipping: powr019
skipping: remr019
skipping: subr019
skipping: comr020
skipping: divr020
skipping: dvir020
skipping: mulr020
skipping: powr020
skipping: remr020
skipping: subr020
skipping: comr021
skipping: divr021
skipping: dvir021
skipping: mulr021
skipping: powr021
skipping: remr021
skipping: subr021
skipping: comr022
skipping: divr022
skipping: dvir022
skipping: mulr022
skipping: powr022
skipping: remr022
skipping: subr022
skipping: comr023
skipping: divr023
skipping: dvir023
skipping: mulr023
skipping: powr023
skipping: remr023
skipping: subr023
skipping: comr024
skipping: divr024
skipping: dvir024
skipping: mulr024
skipping: powr024
skipping: remr024
skipping: subr024
skipping: comr025
skipping: divr025
skipping: dvir025
skipping: mulr025
skipping: powr025
skipping: remr025
skipping: subr025
skipping: comr026
skipping: divr026
skipping: dvir026
skipping: mulr026
skipping: powr026
skipping: remr026
skipping: subr026
skipping: comr027
skipping: divr027
skipping: dvir027
skipping: mulr027
skipping: powr027
skipping: remr027
skipping: subr027
skipping: comr028
skipping: divr028
skipping: dvir028
skipping: mulr028
skipping: powr028
skipping: remr028
skipping: subr028
skipping: comr029
skipping: divr029
skipping: dvir029
skipping: mulr029
skipping: powr029
skipping: remr029
skipping: subr029
skipping: comr030
skipping: divr030
skipping: dvir030
skipping: mulr030
skipping: powr030
skipping: remr030
skipping: subr030
skipping: comr031
skipping: divr031
skipping: dvir031
skipping: mulr031
skipping: powr031
skipping: remr031
skipping: subr031
skipping: comr032
skipping: divr032
skipping: dvir032
skipping: mulr032
skipping: powr032
skipping: remr032
skipping: subr032
skipping: comr033
skipping: divr033
skipping: dvir033
skipping: mulr033
skipping: powr033
skipping: remr033
skipping: subr033
skipping: comr034
skipping: divr034
skipping: dvir034
skipping: mulr034
skipping: powr034
skipping: remr034
skipping: subr034
skipping: comr035
skipping: divr035
skipping: dvir035
skipping: mulr035
skipping: powr035
skipping: remr035
skipping: subr035
skipping: comr036
skipping: divr036
skipping: dvir036
skipping: mulr036
skipping: powr036
skipping: remr036
skipping: subr036
skipping: comr037
skipping: divr037
skipping: dvir037
skipping: mulr037
skipping: powr037
skipping: remr037
skipping: subr037
skipping: comr038
skipping: divr038
skipping: dvir038
skipping: mulr038
skipping: powr038
skipping: remr038
skipping: subr038
skipping: comr039
skipping: divr039
skipping: dvir039
skipping: mulr039
skipping: powr039
skipping: remr039
skipping: subr039
skipping: comr040
skipping: divr040
skipping: dvir040
skipping: mulr040
skipping: powr040
skipping: remr040
skipping: subr040
skipping: comr041
skipping: divr041
skipping: dvir041
skipping: mulr041
skipping: powr041
skipping: remr041
skipping: subr041
skipping: comr042
skipping: divr042
skipping: dvir042
skipping: mulr042
skipping: powr042
skipping: remr042
skipping: subr042
skipping: comr043
skipping: divr043
skipping: dvir043
skipping: mulr043
skipping: powr043
skipping: remr043
skipping: subr043
skipping: comr044
skipping: divr044
skipping: dvir044
skipping: mulr044
skipping: powr044
skipping: remr044
skipping: subr044
skipping: comr045
skipping: divr045
skipping: dvir045
skipping: mulr045
skipping: powr045
skipping: remr045
skipping: subr045
skipping: comr046
skipping: divr046
skipping: dvir046
skipping: mulr046
skipping: powr046
skipping: remr046
skipping: subr046
skipping: comr047
skipping: divr047
skipping: dvir047
skipping: mulr047
skipping: powr047
skipping: remr047
skipping: subr047
skipping: comr048
skipping: divr048
skipping: dvir048
skipping: mulr048
skipping: powr048
skipping: remr048
skipping: subr048
skipping: comr049
skipping: divr049
skipping: dvir049
skipping: mulr049
skipping: powr049
skipping: remr049
skipping: subr049
skipping: comr050
skipping: divr050
skipping: dvir050
skipping: mulr050
skipping: powr050
skipping: remr050
skipping: subr050
skipping: comr051
skipping: divr051
skipping: dvir051
skipping: mulr051
skipping: powr051
skipping: remr051
skipping: subr051
skipping: comr052
skipping: divr052
skipping: dvir052
skipping: mulr052
skipping: powr052
skipping: remr052
skipping: subr052
skipping: comr053
skipping: divr053
skipping: dvir053
skipping: mulr053
skipping: powr053
skipping: remr053
skipping: subr053
skipping: comr054
skipping: divr054
skipping: dvir054
skipping: mulr054
skipping: powr054
skipping: remr054
skipping: subr054
skipping: comr055
skipping: divr055
skipping: dvir055
skipping: mulr055
skipping: powr055
skipping: remr055
skipping: subr055
skipping: comr056
skipping: divr056
skipping: dvir056
skipping: mulr056
skipping: powr056
skipping: remr056
skipping: subr056
skipping: comr057
skipping: divr057
skipping: dvir057
skipping: mulr057
skipping: powr057
skipping: remr057
skipping: subr057
skipping: comr058
skipping: divr058
skipping: dvir058
skipping: mulr058
skipping: powr058
skipping: remr058
skipping: subr058
skipping: comr059
skipping: divr059
skipping: dvir059
skipping: mulr059
skipping: powr059
skipping: remr059
skipping: subr059
skipping: comr060
skipping: divr060
skipping: dvir060
skipping: mulr060
skipping: powr060
skipping: remr060
skipping: subr060
skipping: comr061
skipping: divr061
skipping: dvir061
skipping: mulr061
skipping: powr061
skipping: remr061
skipping: subr061
skipping: comr062
skipping: divr062
skipping: dvir062
skipping: mulr062
skipping: powr062
skipping: remr062
skipping: subr062
skipping: comr063
skipping: divr063
skipping: dvir063
skipping: mulr063
skipping: powr063
skipping: remr063
skipping: subr063
skipping: comr064
skipping: divr064
skipping: dvir064
skipping: mulr064
skipping: powr064
skipping: remr064
skipping: subr064
skipping: comr065
skipping: divr065
skipping: dvir065
skipping: mulr065
skipping: powr065
skipping: remr065
skipping: subr065
skipping: comr066
skipping: divr066
skipping: dvir066
skipping: mulr066
skipping: powr066
skipping: remr066
skipping: subr066
skipping: comr067
skipping: divr067
skipping: dvir067
skipping: mulr067
skipping: powr067
skipping: remr067
skipping: subr067
skipping: comr068
skipping: divr068
skipping: dvir068
skipping: mulr068
skipping: powr068
skipping: remr068
skipping: subr068
skipping: comr069
skipping: divr069
skipping: dvir069
skipping: mulr069
skipping: powr069
skipping: remr069
skipping: subr069
skipping: comr070
skipping: divr070
skipping: dvir070
skipping: mulr070
skipping: powr070
skipping: remr070
skipping: subr070
skipping: comr071
skipping: divr071
skipping: dvir071
skipping: mulr071
skipping: powr071
skipping: remr071
skipping: subr071
skipping: comr072
skipping: divr072
skipping: dvir072
skipping: mulr072
skipping: powr072
skipping: remr072
skipping: subr072
skipping: comr073
skipping: divr073
skipping: dvir073
skipping: mulr073
skipping: powr073
skipping: remr073
skipping: subr073
skipping: comr074
skipping: divr074
skipping: dvir074
skipping: mulr074
skipping: powr074
skipping: remr074
skipping: subr074
skipping: comr075
skipping: divr075
skipping: dvir075
skipping: mulr075
skipping: powr075
skipping: remr075
skipping: subr075
skipping: comr076
skipping: divr076
skipping: dvir076
skipping: mulr076
skipping: powr076
skipping: remr076
skipping: subr076
skipping: comr077
skipping: divr077
skipping: dvir077
skipping: mulr077
skipping: powr077
skipping: remr077
skipping: subr077
skipping: comr078
skipping: divr078
skipping: dvir078
skipping: mulr078
skipping: powr078
skipping: remr078
skipping: subr078
skipping: comr079
skipping: divr079
skipping: dvir079
skipping: mulr079
skipping: powr079
skipping: remr079
skipping: subr079
skipping: comr080
skipping: divr080
skipping: dvir080
skipping: mulr080
skipping: powr080
skipping: remr080
skipping: subr080
skipping: comr081
skipping: divr081
skipping: dvir081
skipping: mulr081
skipping: powr081
skipping: remr081
skipping: subr081
skipping: comr082
skipping: divr082
skipping: dvir082
skipping: mulr082
skipping: powr082
skipping: remr082
skipping: subr082
skipping: comr083
skipping: divr083
skipping: dvir083
skipping: mulr083
skipping: powr083
skipping: remr083
skipping: subr083
skipping: comr084
skipping: divr084
skipping: dvir084
skipping: mulr084
skipping: powr084
skipping: remr084
skipping: subr084
skipping: comr085
skipping: divr085
skipping: dvir085
skipping: mulr085
skipping: powr085
skipping: remr085
skipping: subr085
skipping: comr086
skipping: divr086
skipping: dvir086
skipping: mulr086
skipping: powr086
skipping: remr086
skipping: subr086
skipping: comr087
skipping: divr087
skipping: dvir087
skipping: mulr087
skipping: powr087
skipping: remr087
skipping: subr087
skipping: comr088
skipping: divr088
skipping: dvir088
skipping: mulr088
skipping: powr088
skipping: remr088
skipping: subr088
skipping: comr089
skipping: divr089
skipping: dvir089
skipping: mulr089
skipping: powr089
skipping: remr089
skipping: subr089
skipping: comr090
skipping: divr090
skipping: dvir090
skipping: mulr090
skipping: powr090
skipping: remr090
skipping: subr090
skipping: comr091
skipping: divr091
skipping: dvir091
skipping: mulr091
skipping: powr091
skipping: remr091
skipping: subr091
skipping: comr092
skipping: divr092
skipping: dvir092
skipping: mulr092
skipping: powr092
skipping: remr092
skipping: subr092
skipping: comr093
skipping: divr093
skipping: dvir093
skipping: mulr093
skipping: powr093
skipping: remr093
skipping: subr093
skipping: comr094
skipping: divr094
skipping: dvir094
skipping: mulr094
skipping: powr094
skipping: remr094
skipping: subr094
skipping: comr095
skipping: divr095
skipping: dvir095
skipping: mulr095
skipping: powr095
skipping: remr095
skipping: subr095
skipping: comr096
skipping: divr096
skipping: dvir096
skipping: mulr096
skipping: powr096
skipping: remr096
skipping: subr096
skipping: comr097
skipping: divr097
skipping: dvir097
skipping: mulr097
skipping: powr097
skipping: remr097
skipping: subr097
skipping: comr098
skipping: divr098
skipping: dvir098
skipping: mulr098
skipping: powr098
skipping: remr098
skipping: subr098
skipping: comr099
skipping: divr099
skipping: dvir099
skipping: mulr099
skipping: powr099
skipping: remr099
skipping: subr099
skipping: comr100
skipping: divr100
skipping: dvir100
skipping: mulr100
skipping: powr100
skipping: remr100
skipping: subr100
context {
    rounding     : 4
    precision    : 32
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 32
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 32
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
skipping: comr201
skipping: divr201
skipping: dvir201
skipping: mulr201
skipping: powr201
skipping: remr201
skipping: subr201
skipping: comr202
skipping: divr202
skipping: dvir202
skipping: mulr202
skipping: powr202
skipping: remr202
skipping: subr202
skipping: comr203
skipping: divr203
skipping: dvir203
skipping: mulr203
skipping: powr203
skipping: remr203
skipping: subr203
skipping: comr204
skipping: divr204
skipping: dvir204
skipping: mulr204
skipping: powr204
skipping: remr204
skipping: subr204
skipping: comr205
skipping: divr205
skipping: dvir205
skipping: mulr205
skipping: powr205
skipping: remr205
skipping: subr205
skipping: comr206
skipping: divr206
skipping: dvir206
skipping: mulr206
skipping: powr206
skipping: remr206
skipping: subr206
skipping: comr207
skipping: divr207
skipping: dvir207
skipping: mulr207
skipping: powr207
skipping: remr207
skipping: subr207
skipping: comr208
skipping: divr208
skipping: dvir208
skipping: mulr208
skipping: powr208
skipping: remr208
skipping: subr208
skipping: comr209
skipping: divr209
skipping: dvir209
skipping: mulr209
skipping: powr209
skipping: remr209
skipping: subr209
skipping: comr210
skipping: divr210
skipping: dvir210
skipping: mulr210
skipping: powr210
skipping: remr210
skipping: subr210
skipping: comr211
skipping: divr211
skipping: dvir211
skipping: mulr211
skipping: powr211
skipping: remr211
skipping: subr211
skipping: comr212
skipping: divr212
skipping: dvir212
skipping: mulr212
skipping: powr212
skipping: remr212
skipping: subr212
skipping: comr213
skipping: divr213
skipping: dvir213
skipping: mulr213
skipping: powr213
skipping: remr213
skipping: subr213
skipping: comr214
skipping: divr214
skipping: dvir214
skipping: mulr214
skipping: powr214
skipping: remr214
skipping: subr214
skipping: comr215
skipping: divr215
skipping: dvir215
skipping: mulr215
skipping: powr215
skipping: remr215
skipping: subr215
skipping: comr216
skipping: divr216
skipping: dvir216
skipping: mulr216
skipping: powr216
skipping: remr216
skipping: subr216
skipping: comr217
skipping: divr217
skipping: dvir217
skipping: mulr217
skipping: powr217
skipping: remr217
skipping: subr217
skipping: comr218
skipping: divr218
skipping: dvir218
skipping: mulr218
skipping: powr218
skipping: remr218
skipping: subr218
skipping: comr219
skipping: divr219
skipping: dvir219
skipping: mulr219
skipping: powr219
skipping: remr219
skipping: subr219
skipping: comr220
skipping: divr220
skipping: dvir220
skipping: mulr220
skipping: powr220
skipping: remr220
skipping: subr220
skipping: comr221
skipping: divr221
skipping: dvir221
skipping: mulr221
skipping: powr221
skipping: remr221
skipping: subr221
skipping: comr222
skipping: divr222
skipping: dvir222
skipping: mulr222
skipping: powr222
skipping: remr222
skipping: subr222
skipping: comr223
skipping: divr223
skipping: dvir223
skipping: mulr223
skipping: powr223
skipping: remr223
skipping: subr223
skipping: comr224
skipping: divr224
skipping: dvir224
skipping: mulr224
skipping: powr224
skipping: remr224
skipping: subr224
skipping: comr225
skipping: divr225
skipping: dvir225
skipping: mulr225
skipping: powr225
skipping: remr225
skipping: subr225
skipping: comr226
skipping: divr226
skipping: dvir226
skipping: mulr226
skipping: powr226
skipping: remr226
skipping: subr226
skipping: comr227
skipping: divr227
skipping: dvir227
skipping: mulr227
skipping: powr227
skipping: remr227
skipping: subr227
skipping: comr228
skipping: divr228
skipping: dvir228
skipping: mulr228
skipping: powr228
skipping: remr228
skipping: subr228
skipping: comr229
skipping: divr229
skipping: dvir229
skipping: mulr229
skipping: powr229
skipping: remr229
skipping: subr229
skipping: comr230
skipping: divr230
skipping: dvir230
skipping: mulr230
skipping: powr230
skipping: remr230
skipping: subr230
skipping: comr231
skipping: divr231
skipping: dvir231
skipping: mulr231
skipping: powr231
skipping: remr231
skipping: subr231
skipping: comr232
skipping: divr232
skipping: dvir232
skipping: mulr232
skipping: powr232
skipping: remr232
skipping: subr232
skipping: comr233
skipping: divr233
skipping: dvir233
skipping: mulr233
skipping: powr233
skipping: remr233
skipping: subr233
skipping: comr234
skipping: divr234
skipping: dvir234
skipping: mulr234
skipping: powr234
skipping: remr234
skipping: subr234
skipping: comr235
skipping: divr235
skipping: dvir235
skipping: mulr235
skipping: powr235
skipping: remr235
skipping: subr235
skipping: comr236
skipping: divr236
skipping: dvir236
skipping: mulr236
skipping: powr236
skipping: remr236
skipping: subr236
skipping: comr237
skipping: divr237
skipping: dvir237
skipping: mulr237
skipping: powr237
skipping: remr237
skipping: subr237
skipping: comr238
skipping: divr238
skipping: dvir238
skipping: mulr238
skipping: powr238
skipping: remr238
skipping: subr238
skipping: comr239
skipping: divr239
skipping: dvir239
skipping: mulr239
skipping: powr239
skipping: remr239
skipping: subr239
skipping: comr240
skipping: divr240
skipping: dvir240
skipping: mulr240
skipping: powr240
skipping: remr240
skipping: subr240
skipping: comr241
skipping: divr241
skipping: dvir241
skipping: mulr241
skipping: powr241
skipping: remr241
skipping: subr241
skipping: comr242
skipping: divr242
skipping: dvir242
skipping: mulr242
skipping: powr242
skipping: remr242
skipping: subr242
skipping: comr243
skipping: divr243
skipping: dvir243
skipping: mulr243
skipping: powr243
skipping: remr243
skipping: subr243
skipping: comr244
skipping: divr244
skipping: dvir244
skipping: mulr244
skipping: powr244
skipping: remr244
skipping: subr244
skipping: comr245
skipping: divr245
skipping: dvir245
skipping: mulr245
skipping: powr245
skipping: remr245
skipping: subr245
skipping: comr246
skipping: divr246
skipping: dvir246
skipping: mulr246
skipping: powr246
skipping: remr246
skipping: subr246
skipping: comr247
skipping: divr247
skipping: dvir247
skipping: mulr247
skipping: powr247
skipping: remr247
skipping: subr247
skipping: comr248
skipping: divr248
skipping: dvir248
skipping: mulr248
skipping: powr248
skipping: remr248
skipping: subr248
skipping: comr249
skipping: divr249
skipping: dvir249
skipping: mulr249
skipping: powr249
skipping: remr249
skipping: subr249
skipping: comr250
skipping: divr250
skipping: dvir250
skipping: mulr250
skipping: powr250
skipping: remr250
skipping: subr250
skipping: comr251
skipping: divr251
skipping: dvir251
skipping: mulr251
skipping: powr251
skipping: remr251
skipping: subr251
skipping: comr252
skipping: divr252
skipping: dvir252
skipping: mulr252
skipping: powr252
skipping: remr252
skipping: subr252
skipping: comr253
skipping: divr253
skipping: dvir253
skipping: mulr253
skipping: powr253
skipping: remr253
skipping: subr253
skipping: comr254
skipping: divr254
skipping: dvir254
skipping: mulr254
skipping: powr254
skipping: remr254
skipping: subr254
skipping: comr255
skipping: divr255
skipping: dvir255
skipping: mulr255
skipping: powr255
skipping: remr255
skipping: subr255
skipping: comr256
skipping: divr256
skipping: dvir256
skipping: mulr256
skipping: powr256
skipping: remr256
skipping: subr256
skipping: comr257
skipping: divr257
skipping: dvir257
skipping: mulr257
skipping: powr257
skipping: remr257
skipping: subr257
skipping: comr258
skipping: divr258
skipping: dvir258
skipping: mulr258
skipping: powr258
skipping: remr258
skipping: subr258
skipping: comr259
skipping: divr259
skipping: dvir259
skipping: mulr259
skipping: powr259
skipping: remr259
skipping: subr259
skipping: comr260
skipping: divr260
skipping: dvir260
skipping: mulr260
skipping: powr260
skipping: remr260
skipping: subr260
skipping: comr261
skipping: divr261
skipping: dvir261
skipping: mulr261
skipping: powr261
skipping: remr261
skipping: subr261
skipping: comr262
skipping: divr262
skipping: dvir262
skipping: mulr262
skipping: powr262
skipping: remr262
skipping: subr262
skipping: comr263
skipping: divr263
skipping: dvir263
skipping: mulr263
skipping: powr263
skipping: remr263
skipping: subr263
skipping: comr264
skipping: divr264
skipping: dvir264
skipping: mulr264
skipping: powr264
skipping: remr264
skipping: subr264
skipping: comr265
skipping: divr265
skipping: dvir265
skipping: mulr265
skipping: powr265
skipping: remr265
skipping: subr265
skipping: comr266
skipping: divr266
skipping: dvir266
skipping: mulr266
skipping: powr266
skipping: remr266
skipping: subr266
skipping: comr267
skipping: divr267
skipping: dvir267
skipping: mulr267
skipping: powr267
skipping: remr267
skipping: subr267
skipping: comr268
skipping: divr268
skipping: dvir268
skipping: mulr268
skipping: powr268
skipping: remr268
skipping: subr268
skipping: comr269
skipping: divr269
skipping: dvir269
skipping: mulr269
skipping: powr269
skipping: remr269
skipping: subr269
skipping: comr270
skipping: divr270
skipping: dvir270
skipping: mulr270
skipping: powr270
skipping: remr270
skipping: subr270
skipping: comr271
skipping: divr271
skipping: dvir271
skipping: mulr271
skipping: powr271
skipping: remr271
skipping: subr271
skipping: comr272
skipping: divr272
skipping: dvir272
skipping: mulr272
skipping: powr272
skipping: remr272
skipping: subr272
skipping: comr273
skipping: divr273
skipping: dvir273
skipping: mulr273
skipping: powr273
skipping: remr273
skipping: subr273
skipping: comr274
skipping: divr274
skipping: dvir274
skipping: mulr274
skipping: powr274
skipping: remr274
skipping: subr274
skipping: comr275
skipping: divr275
skipping: dvir275
skipping: mulr275
skipping: powr275
skipping: remr275
skipping: subr275
skipping: comr276
skipping: divr276
skipping: dvir276
skipping: mulr276
skipping: powr276
skipping: remr276
skipping: subr276
skipping: comr277
skipping: divr277
skipping: dvir277
skipping: mulr277
skipping: powr277
skipping: remr277
skipping: subr277
skipping: comr278
skipping: divr278
skipping: dvir278
skipping: mulr278
skipping: powr278
skipping: remr278
skipping: subr278
skipping: comr279
skipping: divr279
skipping: dvir279
skipping: mulr279
skipping: powr279
skipping: remr279
skipping: subr279
skipping: comr280
skipping: divr280
skipping: dvir280
skipping: mulr280
skipping: powr280
skipping: remr280
skipping: subr280
skipping: comr281
skipping: divr281
skipping: dvir281
skipping: mulr281
skipping: powr281
skipping: remr281
skipping: subr281
skipping: comr282
skipping: divr282
skipping: dvir282
skipping: mulr282
skipping: powr282
skipping: remr282
skipping: subr282
skipping: comr283
skipping: divr283
skipping: dvir283
skipping: mulr283
skipping: powr283
skipping: remr283
skipping: subr283
skipping: comr284
skipping: divr284
skipping: dvir284
skipping: mulr284
skipping: powr284
skipping: remr284
skipping: subr284
skipping: comr285
skipping: divr285
skipping: dvir285
skipping: mulr285
skipping: powr285
skipping: remr285
skipping: subr285
skipping: comr286
skipping: divr286
skipping: dvir286
skipping: mulr286
skipping: powr286
skipping: remr286
skipping: subr286
skipping: comr287
skipping: divr287
skipping: dvir287
skipping: mulr287
skipping: powr287
skipping: remr287
skipping: subr287
skipping: comr288
skipping: divr288
skipping: dvir288
skipping: mulr288
skipping: powr288
skipping: remr288
skipping: subr288
skipping: comr289
skipping: divr289
skipping: dvir289
skipping: mulr289
skipping: powr289
skipping: remr289
skipping: subr289
skipping: comr290
skipping: divr290
skipping: dvir290
skipping: mulr290
skipping: powr290
skipping: remr290
skipping: subr290
skipping: comr291
skipping: divr291
skipping: dvir291
skipping: mulr291
skipping: powr291
skipping: remr291
skipping: subr291
skipping: comr292
skipping: divr292
skipping: dvir292
skipping: mulr292
skipping: powr292
skipping: remr292
skipping: subr292
skipping: comr293
skipping: divr293
skipping: dvir293
skipping: mulr293
skipping: powr293
skipping: remr293
skipping: subr293
skipping: comr294
skipping: divr294
skipping: dvir294
skipping: mulr294
skipping: powr294
skipping: remr294
skipping: subr294
skipping: comr295
skipping: divr295
skipping: dvir295
skipping: mulr295
skipping: powr295
skipping: remr295
skipping: subr295
skipping: comr296
skipping: divr296
skipping: dvir296
skipping: mulr296
skipping: powr296
skipping: remr296
skipping: subr296
skipping: comr297
skipping: divr297
skipping: dvir297
skipping: mulr297
skipping: powr297
skipping: remr297
skipping: subr297
skipping: comr298
skipping: divr298
skipping: dvir298
skipping: mulr298
skipping: powr298
skipping: remr298
skipping: subr298
skipping: comr299
skipping: divr299
skipping: dvir299
skipping: mulr299
skipping: powr299
skipping: remr299
skipping: subr299
skipping: comr300
skipping: divr300
skipping: dvir300
skipping: mulr300
skipping: powr300
skipping: remr300
skipping: subr300
context {
    rounding     : 4
    precision    : 33
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 33
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 33
    min exponent : -9999
    max exponent : 9999
    clamp:       : 0
}
skipping: comr401
skipping: divr401
skipping: dvir401
skipping: mulr401
skipping: powr401
skipping: remr401
skipping: subr401
skipping: comr402
skipping: divr402
skipping: dvir402
skipping: mulr402
skipping: powr402
skipping: remr402
skipping: subr402
skipping: comr403
skipping: divr403
skipping: dvir403
skipping: mulr403
skipping: powr403
skipping: remr403
skipping: subr403
skipping: comr404
skipping: divr404
skipping: dvir404
skipping: mulr404
skipping: powr404
skipping: remr404
skipping: subr404
skipping: comr405
skipping: divr405
skipping: dvir405
skipping: mulr405
skipping: powr405
skipping: remr405
skipping: subr405
skipping: comr406
skipping: divr406
skipping: dvir406
skipping: mulr406
skipping: powr406
skipping: remr406
skipping: subr406
skipping: comr407
skipping: divr407
skipping: dvir407
skipping: mulr407
skipping: powr407
skipping: remr407
skipping: subr407
skipping: comr408
skipping: divr408
skipping: dvir408
skipping: mulr408
skipping: powr408
skipping: remr408
skipping: subr408
skipping: comr409
skipping: divr409
skipping: dvir409
skipping: mulr409
skipping: powr409
skipping: remr409
skipping: subr409
skipping: comr410
skipping: divr410
skipping: dvir410
skipping: mulr410
skipping: powr410
skipping: remr410
skipping: subr410
skipping: comr411
skipping: divr411
skipping: dvir411
skipping: mulr411
skipping: powr411
skipping: remr411
skipping: subr411
skipping: comr412
skipping: divr412
skipping: dvir412
skipping: mulr412
skipping: powr412
skipping: remr412
skipping: subr412
skipping: comr413
skipping: divr413
skipping: dvir413
skipping: mulr413
skipping: powr413
skipping: remr413
skipping: subr413
skipping: comr414
skipping: divr414
skipping: dvir414
skipping: mulr414
skipping: powr414
skipping: remr414
skipping: subr414
skipping: comr415
skipping: divr415
skipping: dvir415
skipping: mulr415
skipping: powr415
skipping: remr415
skipping: subr415
skipping: comr416
skipping: divr416
skipping: dvir416
skipping: mulr416
skipping: powr416
skipping: remr416
skipping: subr416
skipping: comr417
skipping: divr417
skipping: dvir417
skipping: mulr417
skipping: powr417
skipping: remr417
skipping: subr417
skipping: comr418
skipping: divr418
skipping: dvir418
skipping: mulr418
skipping: powr418
skipping: remr418
skipping: subr418
skipping: comr419
skipping: divr419
skipping: dvir419
skipping: mulr419
skipping: powr419
skipping: remr419
skipping: subr419
skipping: comr420
skipping: divr420
skipping: dvir420
skipping: mulr420
skipping: powr420
skipping: remr420
skipping: subr420
skipping: comr421
skipping: divr421
skipping: dvir421
skipping: mulr421
skipping: powr421
skipping: remr421
skipping: subr421
skipping: comr422
skipping: divr422
skipping: dvir422
skipping: mulr422
skipping: powr422
skipping: remr422
skipping: subr422
skipping: comr423
skipping: divr423
skipping: dvir423
skipping: mulr423
skipping: powr423
skipping: remr423
skipping: subr423
skipping: comr424
skipping: divr424
skipping: dvir424
skipping: mulr424
skipping: powr424
skipping: remr424
skipping: subr424
skipping: comr425
skipping: divr425
skipping: dvir425
skipping: mulr425
skipping: powr425
skipping: remr425
skipping: subr425
skipping: comr426
skipping: divr426
skipping: dvir426
skipping: mulr426
skipping: powr426
skipping: remr426
skipping: subr426
skipping: comr427
skipping: divr427
skipping: dvir427
skipping: mulr427
skipping: powr427
skipping: remr427
skipping: subr427
skipping: comr428
skipping: divr428
skipping: dvir428
skipping: mulr428
skipping: powr428
skipping: remr428
skipping: subr428
skipping: comr429
skipping: divr429
skipping: dvir429
skipping: mulr429
skipping: powr429
skipping: remr429
skipping: subr429
skipping: comr430
skipping: divr430
skipping: dvir430
skipping: mulr430
skipping: powr430
skipping: remr430
skipping: subr430
skipping: comr431
skipping: divr431
skipping: dvir431
skipping: mulr431
skipping: powr431
skipping: remr431
skipping: subr431
skipping: comr432
skipping: divr432
skipping: dvir432
skipping: mulr432
skipping: powr432
skipping: remr432
skipping: subr432
skipping: comr433
skipping: divr433
skipping: dvir433
skipping: mulr433
skipping: powr433
skipping: remr433
skipping: subr433
skipping: comr434
skipping: divr434
skipping: dvir434
skipping: mulr434
skipping: powr434
skipping: remr434
skipping: subr434
skipping: comr435
skipping: divr435
skipping: dvir435
skipping: mulr435
skipping: powr435
skipping: remr435
skipping: subr435
skipping: comr436
skipping: divr436
skipping: dvir436
skipping: mulr436
skipping: powr436
skipping: remr436
skipping: subr436
skipping: comr437
skipping: divr437
skipping: dvir437
skipping: mulr437
skipping: powr437
skipping: remr437
skipping: subr437
skipping: comr438
skipping: divr438
skipping: dvir438
skipping: mulr438
skipping: powr438
skipping: remr438
skipping: subr438
skipping: comr439
skipping: divr439
skipping: dvir439
skipping: mulr439
skipping: powr439
skipping: remr439
skipping: subr439
skipping: comr440
skipping: divr440
skipping: dvir440
skipping: mulr440
skipping: powr440
skipping: remr440
skipping: subr440
skipping: comr441
skipping: divr441
skipping: dvir441
skipping: mulr441
skipping: powr441
skipping: remr441
skipping: subr441
skipping: comr442
skipping: divr442
skipping: dvir442
skipping: mulr442
skipping: powr442
skipping: remr442
skipping: subr442
skipping: comr443
skipping: divr443
skipping: dvir443
skipping: mulr443
skipping: powr443
skipping: remr443
skipping: subr443
skipping: comr444
skipping: divr444
skipping: dvir444
skipping: mulr444
skipping: powr444
skipping: remr444
skipping: subr444
skipping: comr445
skipping: divr445
skipping: dvir445
skipping: mulr445
skipping: powr445
skipping: remr445
skipping: subr445
skipping: comr446
skipping: divr446
skipping: dvir446
skipping: mulr446
skipping: powr446
skipping: remr446
skipping: subr446
skipping: comr447
skipping: divr447
skipping: dvir447
skipping: mulr447
skipping: powr447
skipping: remr447
skipping: subr447
skipping: comr448
skipping: divr448
skipping: dvir448
skipping: mulr448
skipping: powr448
skipping: remr448
skipping: subr448
skipping: comr449
skipping: divr449
skipping: dvir449
skipping: mulr449
skipping: powr449
skipping: remr449
skipping: subr449
skipping: comr450
skipping: divr450
skipping: dvir450
skipping: mulr450
skipping: powr450
skipping: remr450
skipping: subr450
skipping: comr451
skipping: divr451
skipping: dvir451
skipping: mulr451
skipping: powr451
skipping: remr451
skipping: subr451
skipping: comr452
skipping: divr452
skipping: dvir452
skipping: mulr452
skipping: powr452
skipping: remr452
skipping: subr452
skipping: comr453
skipping: divr453
skipping: dvir453
skipping: mulr453
skipping: powr453
skipping: remr453
skipping: subr453
skipping: comr454
skipping: divr454
skipping: dvir454
skipping: mulr454
skipping: powr454
skipping: remr454
skipping: subr454
skipping: comr455
skipping: divr455
skipping: dvir455
skipping: mulr455
skipping: powr455
skipping: remr455
skipping: subr455
skipping: comr456
skipping: divr456
skipping: dvir456
skipping: mulr456
skipping: powr456
skipping: remr456
skipping: subr456
skipping: comr457
skipping: divr457
skipping: dvir457
skipping: mulr457
skipping: powr457
skipping: remr457
skipping: subr457
skipping: comr458
skipping: divr458
skipping: dvir458
skipping: mulr458
skipping: powr458
skipping: remr458
skipping: subr458
skipping: comr459
skipping: divr459
skipping: dvir459
skipping: mulr459
skipping: powr459
skipping: remr459
skipping: subr459
skipping: comr460
skipping: divr460
skipping: dvir460
skipping: mulr460
skipping: powr460
skipping: remr460
skipping: subr460
skipping: comr461
skipping: divr461
skipping: dvir461
skipping: mulr461
skipping: powr461
skipping: remr461
skipping: subr461
skipping: comr462
skipping: divr462
skipping: dvir462
skipping: mulr462
skipping: powr462
skipping: remr462
skipping: subr462
skipping: comr463
skipping: divr463
skipping: dvir463
skipping: mulr463
skipping: powr463
skipping: remr463
skipping: subr463
skipping: comr464
skipping: divr464
skipping: dvir464
skipping: mulr464
skipping: powr464
skipping: remr464
skipping: subr464
skipping: comr465
skipping: divr465
skipping: dvir465
skipping: mulr465
skipping: powr465
skipping: remr465
skipping: subr465
skipping: comr466
skipping: divr466
skipping: dvir466
skipping: mulr466
skipping: powr466
skipping: remr466
skipping: subr466
skipping: comr467
skipping: divr467
skipping: dvir467
skipping: mulr467
skipping: powr467
skipping: remr467
skipping: subr467
skipping: comr468
skipping: divr468
skipping: dvir468
skipping: mulr468
skipping: powr468
skipping: remr468
skipping: subr468
skipping: comr469
skipping: divr469
skipping: dvir469
skipping: mulr469
skipping: powr469
skipping: remr469
skipping: subr469
skipping: comr470
skipping: divr470
skipping: dvir470
skipping: mulr470
skipping: powr470
skipping: remr470
skipping: subr470
skipping: comr471
skipping: divr471
skipping: dvir471
skipping: mulr471
skipping: powr471
skipping: remr471
skipping: subr471
skipping: comr472
skipping: divr472
skipping: dvir472
skipping: mulr472
skipping: powr472
skipping: remr472
skipping: subr472
skipping: comr473
skipping: divr473
skipping: dvir473
skipping: mulr473
skipping: powr473
skipping: remr473
skipping: subr473
skipping: comr474
skipping: divr474
skipping: dvir474
skipping: mulr474
skipping: powr474
skipping: remr474
skipping: subr474
skipping: comr475
skipping: divr475
skipping: dvir475
skipping: mulr475
skipping: powr475
skipping: remr475
skipping: subr475
skipping: comr476
skipping: divr476
skipping: dvir476
skipping: mulr476
skipping: powr476
skipping: remr476
skipping: subr476
skipping: comr477
skipping: divr477
skipping: dvir477
skipping: mulr477
skipping: powr477
skipping: remr477
skipping: subr477
skipping: comr478
skipping: divr478
skipping: dvir478
skipping: mulr478
skipping: powr478
skipping: remr478
skipping: subr478
skipping: comr479
skipping: divr479
skipping: dvir479
skipping: mulr479
skipping: powr479
skipping: remr479
skipping: subr479
skipping: comr480
skipping: divr480
skipping: dvir480
skipping: mulr480
skipping: powr480
skipping: remr480
skipping: subr480
skipping: comr481
skipping: divr481
skipping: dvir481
skipping: mulr481
skipping: powr481
skipping: remr481
skipping: subr481
skipping: comr482
skipping: divr482
skipping: dvir482
skipping: mulr482
skipping: powr482
skipping: remr482
skipping: subr482
skipping: comr483
skipping: divr483
skipping: dvir483
skipping: mulr483
skipping: powr483
skipping: remr483
skipping: subr483
skipping: comr484
skipping: divr484
skipping: dvir484
skipping: mulr484
skipping: powr484
skipping: remr484
skipping: subr484
skipping: comr485
skipping: divr485
skipping: dvir485
skipping: mulr485
skipping: powr485
skipping: remr485
skipping: subr485
skipping: comr486
skipping: divr486
skipping: dvir486
skipping: mulr486
skipping: powr486
skipping: remr486
skipping: subr486
skipping: comr487
skipping: divr487
skipping: dvir487
skipping: mulr487
skipping: powr487
skipping: remr487
skipping: subr487
skipping: comr488
skipping: divr488
skipping: dvir488
skipping: mulr488
skipping: powr488
skipping: remr488
skipping: subr488
skipping: comr489
skipping: divr489
skipping: dvir489
skipping: mulr489
skipping: powr489
skipping: remr489
skipping: subr489
skipping: comr490
skipping: divr490
skipping: dvir490
skipping: mulr490
skipping: powr490
skipping: remr490
skipping: subr490
skipping: comr491
skipping: divr491
skipping: dvir491
skipping: mulr491
skipping: powr491
skipping: remr491
skipping: subr491
skipping: comr492
skipping: divr492
skipping: dvir492
skipping: mulr492
skipping: powr492
skipping: remr492
skipping: subr492
skipping: comr493
skipping: divr493
skipping: dvir493
skipping: mulr493
skipping: powr493
skipping: remr493
skipping: subr493
skipping: comr494
skipping: divr494
skipping: dvir494
skipping: mulr494
skipping: powr494
skipping: remr494
skipping: subr494
skipping: comr495
skipping: divr495
skipping: dvir495
skipping: mulr495
skipping: powr495
skipping: remr495
skipping: subr495
skipping: comr496
skipping: divr496
skipping: dvir496
skipping: mulr496
skipping: powr496
skipping: remr496
skipping: subr496
skipping: comr497
skipping: divr497
skipping: dvir497
skipping: mulr497
skipping: powr497
skipping: remr497
skipping: subr497
skipping: comr498
skipping: divr498
skipping: dvir498
skipping: mulr498
skipping: powr498
skipping: remr498
skipping: subr498
skipping: comr499
skipping: divr499
skipping: dvir499
skipping: mulr499
skipping: powr499
skipping: remr499
skipping: subr499
skipping: comr500
skipping: divr500
skipping: dvir500
skipping: mulr500
skipping: powr500
skipping: remr500
skipping: subr500
general_decimal_arithmetic/test_cases/subset_arithmetic/randombound320.decTest
context {
    rounding     : 
    precision    : 
    min exponent : 
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 
    precision    : 
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rcom001
skipping: rdiv001
skipping: rdvi001
skipping: rmul001
skipping: rpow001
skipping: rrem001
skipping: rsub001
skipping: rcom002
skipping: rdiv002
skipping: rdvi002
skipping: rmul002
skipping: rpow002
skipping: rrem002
skipping: rsub002
skipping: rcom003
skipping: rdiv003
skipping: rdvi003
skipping: rmul003
skipping: rpow003
skipping: rrem003
skipping: rsub003
skipping: rcom004
skipping: rdiv004
skipping: rdvi004
skipping: rmul004
skipping: rpow004
skipping: rrem004
skipping: rsub004
skipping: rcom005
skipping: rdiv005
skipping: rdvi005
skipping: rmul005
skipping: rpow005
skipping: rrem005
skipping: rsub005
skipping: rcom006
skipping: rdiv006
skipping: rdvi006
skipping: rmul006
skipping: rpow006
skipping: rrem006
skipping: rsub006
skipping: rcom007
skipping: rdiv007
skipping: rdvi007
skipping: rmul007
skipping: rpow007
skipping: rrem007
skipping: rsub007
skipping: rcom008
skipping: rdiv008
skipping: rdvi008
skipping: rmul008
skipping: rpow008
skipping: rrem008
skipping: rsub008
skipping: rcom009
skipping: rdiv009
skipping: rdvi009
skipping: rmul009
skipping: rpow009
skipping: rrem009
skipping: rsub009
skipping: rcom010
skipping: rdiv010
skipping: rdvi010
skipping: rmul010
skipping: rpow010
skipping: rrem010
skipping: rsub010
skipping: rcom011
skipping: rdiv011
skipping: rdvi011
skipping: rmul011
skipping: rpow011
skipping: rrem011
skipping: rsub011
skipping: rcom012
skipping: rdiv012
skipping: rdvi012
skipping: rmul012
skipping: rpow012
skipping: rrem012
skipping: rsub012
skipping: rcom013
skipping: rdiv013
skipping: rdvi013
skipping: rmul013
skipping: rpow013
skipping: rrem013
skipping: rsub013
skipping: rcom014
skipping: rdiv014
skipping: rdvi014
skipping: rmul014
skipping: rpow014
skipping: rrem014
skipping: rsub014
skipping: rcom015
skipping: rdiv015
skipping: rdvi015
skipping: rmul015
skipping: rpow015
skipping: rrem015
skipping: rsub015
skipping: rcom016
skipping: rdiv016
skipping: rdvi016
skipping: rmul016
skipping: rpow016
skipping: rrem016
skipping: rsub016
skipping: rcom017
skipping: rdiv017
skipping: rdvi017
skipping: rmul017
skipping: rpow017
skipping: rrem017
skipping: rsub017
skipping: rcom018
skipping: rdiv018
skipping: rdvi018
skipping: rmul018
skipping: rpow018
skipping: rrem018
skipping: rsub018
skipping: rcom019
skipping: rdiv019
skipping: rdvi019
skipping: rmul019
skipping: rpow019
skipping: rrem019
skipping: rsub019
skipping: rcom020
skipping: rdiv020
skipping: rdvi020
skipping: rmul020
skipping: rpow020
skipping: rrem020
skipping: rsub020
skipping: rcom021
skipping: rdiv021
skipping: rdvi021
skipping: rmul021
skipping: rpow021
skipping: rrem021
skipping: rsub021
skipping: rcom022
skipping: rdiv022
skipping: rdvi022
skipping: rmul022
skipping: rpow022
skipping: rrem022
skipping: rsub022
skipping: rcom023
skipping: rdiv023
skipping: rdvi023
skipping: rmul023
skipping: rpow023
skipping: rrem023
skipping: rsub023
skipping: rcom024
skipping: rdiv024
skipping: rdvi024
skipping: rmul024
skipping: rpow024
skipping: rrem024
skipping: rsub024
skipping: rcom025
skipping: rdiv025
skipping: rdvi025
skipping: rmul025
skipping: rpow025
skipping: rrem025
skipping: rsub025
skipping: rcom026
skipping: rdiv026
skipping: rdvi026
skipping: rmul026
skipping: rpow026
skipping: rrem026
skipping: rsub026
skipping: rcom027
skipping: rdiv027
skipping: rdvi027
skipping: rmul027
skipping: rpow027
skipping: rrem027
skipping: rsub027
skipping: rcom028
skipping: rdiv028
skipping: rdvi028
skipping: rmul028
skipping: rpow028
skipping: rrem028
skipping: rsub028
skipping: rcom029
skipping: rdiv029
skipping: rdvi029
skipping: rmul029
skipping: rpow029
skipping: rrem029
skipping: rsub029
skipping: rcom030
skipping: rdiv030
skipping: rdvi030
skipping: rmul030
skipping: rpow030
skipping: rrem030
skipping: rsub030
skipping: rcom031
skipping: rdiv031
skipping: rdvi031
skipping: rmul031
skipping: rpow031
skipping: rrem031
skipping: rsub031
skipping: rcom032
skipping: rdiv032
skipping: rdvi032
skipping: rmul032
skipping: rpow032
skipping: rrem032
skipping: rsub032
skipping: rcom033
skipping: rdiv033
skipping: rdvi033
skipping: rmul033
skipping: rpow033
skipping: rrem033
skipping: rsub033
skipping: rcom034
skipping: rdiv034
skipping: rdvi034
skipping: rmul034
skipping: rpow034
skipping: rrem034
skipping: rsub034
skipping: rcom035
skipping: rdiv035
skipping: rdvi035
skipping: rmul035
skipping: rpow035
skipping: rrem035
skipping: rsub035
skipping: rcom036
skipping: rdiv036
skipping: rdvi036
skipping: rmul036
skipping: rpow036
skipping: rrem036
skipping: rsub036
skipping: rcom037
skipping: rdiv037
skipping: rdvi037
skipping: rmul037
skipping: rpow037
skipping: rrem037
skipping: rsub037
skipping: rcom038
skipping: rdiv038
skipping: rdvi038
skipping: rmul038
skipping: rpow038
skipping: rrem038
skipping: rsub038
skipping: rcom039
skipping: rdiv039
skipping: rdvi039
skipping: rmul039
skipping: rpow039
skipping: rrem039
skipping: rsub039
skipping: rcom040
skipping: rdiv040
skipping: rdvi040
skipping: rmul040
skipping: rpow040
skipping: rrem040
skipping: rsub040
skipping: rcom041
skipping: rdiv041
skipping: rdvi041
skipping: rmul041
skipping: rpow041
skipping: rrem041
skipping: rsub041
skipping: rcom042
skipping: rdiv042
skipping: rdvi042
skipping: rmul042
skipping: rpow042
skipping: rrem042
skipping: rsub042
skipping: rcom043
skipping: rdiv043
skipping: rdvi043
skipping: rmul043
skipping: rpow043
skipping: rrem043
skipping: rsub043
skipping: rcom044
skipping: rdiv044
skipping: rdvi044
skipping: rmul044
skipping: rpow044
skipping: rrem044
skipping: rsub044
skipping: rcom045
skipping: rdiv045
skipping: rdvi045
skipping: rmul045
skipping: rpow045
skipping: rrem045
skipping: rsub045
skipping: rcom046
skipping: rdiv046
skipping: rdvi046
skipping: rmul046
skipping: rpow046
skipping: rrem046
skipping: rsub046
skipping: rcom047
skipping: rdiv047
skipping: rdvi047
skipping: rmul047
skipping: rpow047
skipping: rrem047
skipping: rsub047
skipping: rcom048
skipping: rdiv048
skipping: rdvi048
skipping: rmul048
skipping: rpow048
skipping: rrem048
skipping: rsub048
skipping: rcom049
skipping: rdiv049
skipping: rdvi049
skipping: rmul049
skipping: rpow049
skipping: rrem049
skipping: rsub049
skipping: rcom050
skipping: rdiv050
skipping: rdvi050
skipping: rmul050
skipping: rpow050
skipping: rrem050
skipping: rsub050
skipping: rcom051
skipping: rdiv051
skipping: rdvi051
skipping: rmul051
skipping: rpow051
skipping: rrem051
skipping: rsub051
skipping: rcom052
skipping: rdiv052
skipping: rdvi052
skipping: rmul052
skipping: rpow052
skipping: rrem052
skipping: rsub052
skipping: rcom053
skipping: rdiv053
skipping: rdvi053
skipping: rmul053
skipping: rpow053
skipping: rrem053
skipping: rsub053
skipping: rcom054
skipping: rdiv054
skipping: rdvi054
skipping: rmul054
skipping: rpow054
skipping: rrem054
skipping: rsub054
skipping: rcom055
skipping: rdiv055
skipping: rdvi055
skipping: rmul055
skipping: rpow055
skipping: rrem055
skipping: rsub055
skipping: rcom056
skipping: rdiv056
skipping: rdvi056
skipping: rmul056
skipping: rpow056
skipping: rrem056
skipping: rsub056
skipping: rcom057
skipping: rdiv057
skipping: rdvi057
skipping: rmul057
skipping: rpow057
skipping: rrem057
skipping: rsub057
skipping: rcom058
skipping: rdiv058
skipping: rdvi058
skipping: rmul058
skipping: rpow058
skipping: rrem058
skipping: rsub058
skipping: rcom059
skipping: rdiv059
skipping: rdvi059
skipping: rmul059
skipping: rpow059
skipping: rrem059
skipping: rsub059
skipping: rcom060
skipping: rdiv060
skipping: rdvi060
skipping: rmul060
skipping: rpow060
skipping: rrem060
skipping: rsub060
skipping: rcom061
skipping: rdiv061
skipping: rdvi061
skipping: rmul061
skipping: rpow061
skipping: rrem061
skipping: rsub061
skipping: rcom062
skipping: rdiv062
skipping: rdvi062
skipping: rmul062
skipping: rpow062
skipping: rrem062
skipping: rsub062
skipping: rcom063
skipping: rdiv063
skipping: rdvi063
skipping: rmul063
skipping: rpow063
skipping: rrem063
skipping: rsub063
skipping: rcom064
skipping: rdiv064
skipping: rdvi064
skipping: rmul064
skipping: rpow064
skipping: rrem064
skipping: rsub064
skipping: rcom065
skipping: rdiv065
skipping: rdvi065
skipping: rmul065
skipping: rpow065
skipping: rrem065
skipping: rsub065
skipping: rcom066
skipping: rdiv066
skipping: rdvi066
skipping: rmul066
skipping: rpow066
skipping: rrem066
skipping: rsub066
skipping: rcom067
skipping: rdiv067
skipping: rdvi067
skipping: rmul067
skipping: rpow067
skipping: rrem067
skipping: rsub067
skipping: rcom068
skipping: rdiv068
skipping: rdvi068
skipping: rmul068
skipping: rpow068
skipping: rrem068
skipping: rsub068
skipping: rcom069
skipping: rdiv069
skipping: rdvi069
skipping: rmul069
skipping: rpow069
skipping: rrem069
skipping: rsub069
skipping: rcom070
skipping: rdiv070
skipping: rdvi070
skipping: rmul070
skipping: rpow070
skipping: rrem070
skipping: rsub070
skipping: rcom071
skipping: rdiv071
skipping: rdvi071
skipping: rmul071
skipping: rpow071
skipping: rrem071
skipping: rsub071
skipping: rcom072
skipping: rdiv072
skipping: rdvi072
skipping: rmul072
skipping: rpow072
skipping: rrem072
skipping: rsub072
skipping: rcom073
skipping: rdiv073
skipping: rdvi073
skipping: rmul073
skipping: rpow073
skipping: rrem073
skipping: rsub073
skipping: rcom074
skipping: rdiv074
skipping: rdvi074
skipping: rmul074
skipping: rpow074
skipping: rrem074
skipping: rsub074
skipping: rcom075
skipping: rdiv075
skipping: rdvi075
skipping: rmul075
skipping: rpow075
skipping: rrem075
skipping: rsub075
skipping: rcom076
skipping: rdiv076
skipping: rdvi076
skipping: rmul076
skipping: rpow076
skipping: rrem076
skipping: rsub076
skipping: rcom077
skipping: rdiv077
skipping: rdvi077
skipping: rmul077
skipping: rpow077
skipping: rrem077
skipping: rsub077
skipping: rcom078
skipping: rdiv078
skipping: rdvi078
skipping: rmul078
skipping: rpow078
skipping: rrem078
skipping: rsub078
skipping: rcom079
skipping: rdiv079
skipping: rdvi079
skipping: rmul079
skipping: rpow079
skipping: rrem079
skipping: rsub079
skipping: rcom080
skipping: rdiv080
skipping: rdvi080
skipping: rmul080
skipping: rpow080
skipping: rrem080
skipping: rsub080
skipping: rcom081
skipping: rdiv081
skipping: rdvi081
skipping: rmul081
skipping: rpow081
skipping: rrem081
skipping: rsub081
skipping: rcom082
skipping: rdiv082
skipping: rdvi082
skipping: rmul082
skipping: rpow082
skipping: rrem082
skipping: rsub082
skipping: rcom083
skipping: rdiv083
skipping: rdvi083
skipping: rmul083
skipping: rpow083
skipping: rrem083
skipping: rsub083
skipping: rcom084
skipping: rdiv084
skipping: rdvi084
skipping: rmul084
skipping: rpow084
skipping: rrem084
skipping: rsub084
skipping: rcom085
skipping: rdiv085
skipping: rdvi085
skipping: rmul085
skipping: rpow085
skipping: rrem085
skipping: rsub085
skipping: rcom086
skipping: rdiv086
skipping: rdvi086
skipping: rmul086
skipping: rpow086
skipping: rrem086
skipping: rsub086
skipping: rcom087
skipping: rdiv087
skipping: rdvi087
skipping: rmul087
skipping: rpow087
skipping: rrem087
skipping: rsub087
skipping: rcom088
skipping: rdiv088
skipping: rdvi088
skipping: rmul088
skipping: rpow088
skipping: rrem088
skipping: rsub088
skipping: rcom089
skipping: rdiv089
skipping: rdvi089
skipping: rmul089
skipping: rpow089
skipping: rrem089
skipping: rsub089
skipping: rcom090
skipping: rdiv090
skipping: rdvi090
skipping: rmul090
skipping: rpow090
skipping: rrem090
skipping: rsub090
skipping: rcom091
skipping: rdiv091
skipping: rdvi091
skipping: rmul091
skipping: rpow091
skipping: rrem091
skipping: rsub091
skipping: rcom092
skipping: rdiv092
skipping: rdvi092
skipping: rmul092
skipping: rpow092
skipping: rrem092
skipping: rsub092
skipping: rcom093
skipping: rdiv093
skipping: rdvi093
skipping: rmul093
skipping: rpow093
skipping: rrem093
skipping: rsub093
skipping: rcom094
skipping: rdiv094
skipping: rdvi094
skipping: rmul094
skipping: rpow094
skipping: rrem094
skipping: rsub094
skipping: rcom095
skipping: rdiv095
skipping: rdvi095
skipping: rmul095
skipping: rpow095
skipping: rrem095
skipping: rsub095
skipping: rcom096
skipping: rdiv096
skipping: rdvi096
skipping: rmul096
skipping: rpow096
skipping: rrem096
skipping: rsub096
skipping: rcom097
skipping: rdiv097
skipping: rdvi097
skipping: rmul097
skipping: rpow097
skipping: rrem097
skipping: rsub097
skipping: rcom098
skipping: rdiv098
skipping: rdvi098
skipping: rmul098
skipping: rpow098
skipping: rrem098
skipping: rsub098
skipping: rcom099
skipping: rdiv099
skipping: rdvi099
skipping: rmul099
skipping: rpow099
skipping: rrem099
skipping: rsub099
skipping: rcom100
skipping: rdiv100
skipping: rdvi100
skipping: rmul100
skipping: rpow100
skipping: rrem100
skipping: rsub100
skipping: rcom101
skipping: rdiv101
skipping: rdvi101
skipping: rmul101
skipping: rpow101
skipping: rrem101
skipping: rsub101
skipping: rcom102
skipping: rdiv102
skipping: rdvi102
skipping: rmul102
skipping: rpow102
skipping: rrem102
skipping: rsub102
skipping: rcom103
skipping: rdiv103
skipping: rdvi103
skipping: rmul103
skipping: rpow103
skipping: rrem103
skipping: rsub103
skipping: rcom104
skipping: rdiv104
skipping: rdvi104
skipping: rmul104
skipping: rpow104
skipping: rrem104
skipping: rsub104
skipping: rcom105
skipping: rdiv105
skipping: rdvi105
skipping: rmul105
skipping: rpow105
skipping: rrem105
skipping: rsub105
skipping: rcom106
skipping: rdiv106
skipping: rdvi106
skipping: rmul106
skipping: rpow106
skipping: rrem106
skipping: rsub106
skipping: rcom107
skipping: rdiv107
skipping: rdvi107
skipping: rmul107
skipping: rpow107
skipping: rrem107
skipping: rsub107
skipping: rcom108
skipping: rdiv108
skipping: rdvi108
skipping: rmul108
skipping: rpow108
skipping: rrem108
skipping: rsub108
skipping: rcom109
skipping: rdiv109
skipping: rdvi109
skipping: rmul109
skipping: rpow109
skipping: rrem109
skipping: rsub109
skipping: rcom110
skipping: rdiv110
skipping: rdvi110
skipping: rmul110
skipping: rpow110
skipping: rrem110
skipping: rsub110
skipping: rcom111
skipping: rdiv111
skipping: rdvi111
skipping: rmul111
skipping: rpow111
skipping: rrem111
skipping: rsub111
skipping: rcom112
skipping: rdiv112
skipping: rdvi112
skipping: rmul112
skipping: rpow112
skipping: rrem112
skipping: rsub112
skipping: rcom113
skipping: rdiv113
skipping: rdvi113
skipping: rmul113
skipping: rpow113
skipping: rrem113
skipping: rsub113
skipping: rcom114
skipping: rdiv114
skipping: rdvi114
skipping: rmul114
skipping: rpow114
skipping: rrem114
skipping: rsub114
skipping: rcom115
skipping: rdiv115
skipping: rdvi115
skipping: rmul115
skipping: rpow115
skipping: rrem115
skipping: rsub115
skipping: rcom116
skipping: rdiv116
skipping: rdvi116
skipping: rmul116
skipping: rpow116
skipping: rrem116
skipping: rsub116
skipping: rcom117
skipping: rdiv117
skipping: rdvi117
skipping: rmul117
skipping: rpow117
skipping: rrem117
skipping: rsub117
skipping: rcom118
skipping: rdiv118
skipping: rdvi118
skipping: rmul118
skipping: rpow118
skipping: rrem118
skipping: rsub118
skipping: rcom119
skipping: rdiv119
skipping: rdvi119
skipping: rmul119
skipping: rpow119
skipping: rrem119
skipping: rsub119
skipping: rcom120
skipping: rdiv120
skipping: rdvi120
skipping: rmul120
skipping: rpow120
skipping: rrem120
skipping: rsub120
skipping: rcom121
skipping: rdiv121
skipping: rdvi121
skipping: rmul121
skipping: rpow121
skipping: rrem121
skipping: rsub121
skipping: rcom122
skipping: rdiv122
skipping: rdvi122
skipping: rmul122
skipping: rpow122
skipping: rrem122
skipping: rsub122
skipping: rcom123
skipping: rdiv123
skipping: rdvi123
skipping: rmul123
skipping: rpow123
skipping: rrem123
skipping: rsub123
skipping: rcom124
skipping: rdiv124
skipping: rdvi124
skipping: rmul124
skipping: rpow124
skipping: rrem124
skipping: rsub124
skipping: rcom125
skipping: rdiv125
skipping: rdvi125
skipping: rmul125
skipping: rpow125
skipping: rrem125
skipping: rsub125
skipping: rcom126
skipping: rdiv126
skipping: rdvi126
skipping: rmul126
skipping: rpow126
skipping: rrem126
skipping: rsub126
skipping: rcom127
skipping: rdiv127
skipping: rdvi127
skipping: rmul127
skipping: rpow127
skipping: rrem127
skipping: rsub127
skipping: rcom128
skipping: rdiv128
skipping: rdvi128
skipping: rmul128
skipping: rpow128
skipping: rrem128
skipping: rsub128
skipping: rcom129
skipping: rdiv129
skipping: rdvi129
skipping: rmul129
skipping: rpow129
skipping: rrem129
skipping: rsub129
skipping: rcom130
skipping: rdiv130
skipping: rdvi130
skipping: rmul130
skipping: rpow130
skipping: rrem130
skipping: rsub130
skipping: rcom131
skipping: rdiv131
skipping: rdvi131
skipping: rmul131
skipping: rpow131
skipping: rrem131
skipping: rsub131
skipping: rcom132
skipping: rdiv132
skipping: rdvi132
skipping: rmul132
skipping: rpow132
skipping: rrem132
skipping: rsub132
skipping: rcom133
skipping: rdiv133
skipping: rdvi133
skipping: rmul133
skipping: rpow133
skipping: rrem133
skipping: rsub133
skipping: rcom134
skipping: rdiv134
skipping: rdvi134
skipping: rmul134
skipping: rpow134
skipping: rrem134
skipping: rsub134
skipping: rcom135
skipping: rdiv135
skipping: rdvi135
skipping: rmul135
skipping: rpow135
skipping: rrem135
skipping: rsub135
skipping: rcom136
skipping: rdiv136
skipping: rdvi136
skipping: rmul136
skipping: rpow136
skipping: rrem136
skipping: rsub136
skipping: rcom137
skipping: rdiv137
skipping: rdvi137
skipping: rmul137
skipping: rpow137
skipping: rrem137
skipping: rsub137
skipping: rcom138
skipping: rdiv138
skipping: rdvi138
skipping: rmul138
skipping: rpow138
skipping: rrem138
skipping: rsub138
skipping: rcom139
skipping: rdiv139
skipping: rdvi139
skipping: rmul139
skipping: rpow139
skipping: rrem139
skipping: rsub139
skipping: rcom140
skipping: rdiv140
skipping: rdvi140
skipping: rmul140
skipping: rpow140
skipping: rrem140
skipping: rsub140
skipping: rcom141
skipping: rdiv141
skipping: rdvi141
skipping: rmul141
skipping: rpow141
skipping: rrem141
skipping: rsub141
skipping: rcom142
skipping: rdiv142
skipping: rdvi142
skipping: rmul142
skipping: rpow142
skipping: rrem142
skipping: rsub142
skipping: rcom143
skipping: rdiv143
skipping: rdvi143
skipping: rmul143
skipping: rpow143
skipping: rrem143
skipping: rsub143
skipping: rcom144
skipping: rdiv144
skipping: rdvi144
skipping: rmul144
skipping: rpow144
skipping: rrem144
skipping: rsub144
skipping: rcom145
skipping: rdiv145
skipping: rdvi145
skipping: rmul145
skipping: rpow145
skipping: rrem145
skipping: rsub145
skipping: rcom146
skipping: rdiv146
skipping: rdvi146
skipping: rmul146
skipping: rpow146
skipping: rrem146
skipping: rsub146
skipping: rcom147
skipping: rdiv147
skipping: rdvi147
skipping: rmul147
skipping: rpow147
skipping: rrem147
skipping: rsub147
skipping: rcom148
skipping: rdiv148
skipping: rdvi148
skipping: rmul148
skipping: rpow148
skipping: rrem148
skipping: rsub148
skipping: rcom149
skipping: rdiv149
skipping: rdvi149
skipping: rmul149
skipping: rpow149
skipping: rrem149
skipping: rsub149
skipping: rcom150
skipping: rdiv150
skipping: rdvi150
skipping: rmul150
skipping: rpow150
skipping: rrem150
skipping: rsub150
skipping: rcom151
skipping: rdiv151
skipping: rdvi151
skipping: rmul151
skipping: rpow151
skipping: rrem151
skipping: rsub151
skipping: rcom152
skipping: rdiv152
skipping: rdvi152
skipping: rmul152
skipping: rpow152
skipping: rrem152
skipping: rsub152
skipping: rcom153
skipping: rdiv153
skipping: rdvi153
skipping: rmul153
skipping: rpow153
skipping: rrem153
skipping: rsub153
skipping: rcom154
skipping: rdiv154
skipping: rdvi154
skipping: rmul154
skipping: rpow154
skipping: rrem154
skipping: rsub154
skipping: rcom155
skipping: rdiv155
skipping: rdvi155
skipping: rmul155
skipping: rpow155
skipping: rrem155
skipping: rsub155
skipping: rcom156
skipping: rdiv156
skipping: rdvi156
skipping: rmul156
skipping: rpow156
skipping: rrem156
skipping: rsub156
skipping: rcom157
skipping: rdiv157
skipping: rdvi157
skipping: rmul157
skipping: rpow157
skipping: rrem157
skipping: rsub157
skipping: rcom158
skipping: rdiv158
skipping: rdvi158
skipping: rmul158
skipping: rpow158
skipping: rrem158
skipping: rsub158
skipping: rcom159
skipping: rdiv159
skipping: rdvi159
skipping: rmul159
skipping: rpow159
skipping: rrem159
skipping: rsub159
skipping: rcom160
skipping: rdiv160
skipping: rdvi160
skipping: rmul160
skipping: rpow160
skipping: rrem160
skipping: rsub160
skipping: rcom161
skipping: rdiv161
skipping: rdvi161
skipping: rmul161
skipping: rpow161
skipping: rrem161
skipping: rsub161
skipping: rcom162
skipping: rdiv162
skipping: rdvi162
skipping: rmul162
skipping: rpow162
skipping: rrem162
skipping: rsub162
skipping: rcom163
skipping: rdiv163
skipping: rdvi163
skipping: rmul163
skipping: rpow163
skipping: rrem163
skipping: rsub163
skipping: rcom164
skipping: rdiv164
skipping: rdvi164
skipping: rmul164
skipping: rpow164
skipping: rrem164
skipping: rsub164
skipping: rcom165
skipping: rdiv165
skipping: rdvi165
skipping: rmul165
skipping: rpow165
skipping: rrem165
skipping: rsub165
skipping: rcom166
skipping: rdiv166
skipping: rdvi166
skipping: rmul166
skipping: rpow166
skipping: rrem166
skipping: rsub166
skipping: rcom167
skipping: rdiv167
skipping: rdvi167
skipping: rmul167
skipping: rpow167
skipping: rrem167
skipping: rsub167
skipping: rcom168
skipping: rdiv168
skipping: rdvi168
skipping: rmul168
skipping: rpow168
skipping: rrem168
skipping: rsub168
skipping: rcom169
skipping: rdiv169
skipping: rdvi169
skipping: rmul169
skipping: rpow169
skipping: rrem169
skipping: rsub169
skipping: rcom170
skipping: rdiv170
skipping: rdvi170
skipping: rmul170
skipping: rpow170
skipping: rrem170
skipping: rsub170
skipping: rcom171
skipping: rdiv171
skipping: rdvi171
skipping: rmul171
skipping: rpow171
skipping: rrem171
skipping: rsub171
skipping: rcom172
skipping: rdiv172
skipping: rdvi172
skipping: rmul172
skipping: rpow172
skipping: rrem172
skipping: rsub172
skipping: rcom173
skipping: rdiv173
skipping: rdvi173
skipping: rmul173
skipping: rpow173
skipping: rrem173
skipping: rsub173
skipping: rcom174
skipping: rdiv174
skipping: rdvi174
skipping: rmul174
skipping: rpow174
skipping: rrem174
skipping: rsub174
skipping: rcom175
skipping: rdiv175
skipping: rdvi175
skipping: rmul175
skipping: rpow175
skipping: rrem175
skipping: rsub175
skipping: rcom176
skipping: rdiv176
skipping: rdvi176
skipping: rmul176
skipping: rpow176
skipping: rrem176
skipping: rsub176
skipping: rcom177
skipping: rdiv177
skipping: rdvi177
skipping: rmul177
skipping: rpow177
skipping: rrem177
skipping: rsub177
skipping: rcom178
skipping: rdiv178
skipping: rdvi178
skipping: rmul178
skipping: rpow178
skipping: rrem178
skipping: rsub178
skipping: rcom179
skipping: rdiv179
skipping: rdvi179
skipping: rmul179
skipping: rpow179
skipping: rrem179
skipping: rsub179
skipping: rcom180
skipping: rdiv180
skipping: rdvi180
skipping: rmul180
skipping: rpow180
skipping: rrem180
skipping: rsub180
skipping: rcom181
skipping: rdiv181
skipping: rdvi181
skipping: rmul181
skipping: rpow181
skipping: rrem181
skipping: rsub181
skipping: rcom182
skipping: rdiv182
skipping: rdvi182
skipping: rmul182
skipping: rpow182
skipping: rrem182
skipping: rsub182
skipping: rcom183
skipping: rdiv183
skipping: rdvi183
skipping: rmul183
skipping: rpow183
skipping: rrem183
skipping: rsub183
skipping: rcom184
skipping: rdiv184
skipping: rdvi184
skipping: rmul184
skipping: rpow184
skipping: rrem184
skipping: rsub184
skipping: rcom185
skipping: rdiv185
skipping: rdvi185
skipping: rmul185
skipping: rpow185
skipping: rrem185
skipping: rsub185
skipping: rcom186
skipping: rdiv186
skipping: rdvi186
skipping: rmul186
skipping: rpow186
skipping: rrem186
skipping: rsub186
skipping: rcom187
skipping: rdiv187
skipping: rdvi187
skipping: rmul187
skipping: rpow187
skipping: rrem187
skipping: rsub187
skipping: rcom188
skipping: rdiv188
skipping: rdvi188
skipping: rmul188
skipping: rpow188
skipping: rrem188
skipping: rsub188
skipping: rcom189
skipping: rdiv189
skipping: rdvi189
skipping: rmul189
skipping: rpow189
skipping: rrem189
skipping: rsub189
skipping: rcom190
skipping: rdiv190
skipping: rdvi190
skipping: rmul190
skipping: rpow190
skipping: rrem190
skipping: rsub190
skipping: rcom191
skipping: rdiv191
skipping: rdvi191
skipping: rmul191
skipping: rpow191
skipping: rrem191
skipping: rsub191
skipping: rcom192
skipping: rdiv192
skipping: rdvi192
skipping: rmul192
skipping: rpow192
skipping: rrem192
skipping: rsub192
skipping: rcom193
skipping: rdiv193
skipping: rdvi193
skipping: rmul193
skipping: rpow193
skipping: rrem193
skipping: rsub193
skipping: rcom194
skipping: rdiv194
skipping: rdvi194
skipping: rmul194
skipping: rpow194
skipping: rrem194
skipping: rsub194
skipping: rcom195
skipping: rdiv195
skipping: rdvi195
skipping: rmul195
skipping: rpow195
skipping: rrem195
skipping: rsub195
skipping: rcom196
skipping: rdiv196
skipping: rdvi196
skipping: rmul196
skipping: rpow196
skipping: rrem196
skipping: rsub196
skipping: rcom197
skipping: rdiv197
skipping: rdvi197
skipping: rmul197
skipping: rpow197
skipping: rrem197
skipping: rsub197
skipping: rcom198
skipping: rdiv198
skipping: rdvi198
skipping: rmul198
skipping: rpow198
skipping: rrem198
skipping: rsub198
skipping: rcom199
skipping: rdiv199
skipping: rdvi199
skipping: rmul199
skipping: rpow199
skipping: rrem199
skipping: rsub199
skipping: rcom200
skipping: rdiv200
skipping: rdvi200
skipping: rmul200
skipping: rpow200
skipping: rrem200
skipping: rsub200
skipping: rcom201
skipping: rdiv201
skipping: rdvi201
skipping: rmul201
skipping: rpow201
skipping: rrem201
skipping: rsub201
skipping: rcom202
skipping: rdiv202
skipping: rdvi202
skipping: rmul202
skipping: rpow202
skipping: rrem202
skipping: rsub202
skipping: rcom203
skipping: rdiv203
skipping: rdvi203
skipping: rmul203
skipping: rpow203
skipping: rrem203
skipping: rsub203
skipping: rcom204
skipping: rdiv204
skipping: rdvi204
skipping: rmul204
skipping: rpow204
skipping: rrem204
skipping: rsub204
skipping: rcom205
skipping: rdiv205
skipping: rdvi205
skipping: rmul205
skipping: rpow205
skipping: rrem205
skipping: rsub205
skipping: rcom206
skipping: rdiv206
skipping: rdvi206
skipping: rmul206
skipping: rpow206
skipping: rrem206
skipping: rsub206
skipping: rcom207
skipping: rdiv207
skipping: rdvi207
skipping: rmul207
skipping: rpow207
skipping: rrem207
skipping: rsub207
skipping: rcom208
skipping: rdiv208
skipping: rdvi208
skipping: rmul208
skipping: rpow208
skipping: rrem208
skipping: rsub208
skipping: rcom209
skipping: rdiv209
skipping: rdvi209
skipping: rmul209
skipping: rpow209
skipping: rrem209
skipping: rsub209
skipping: rcom210
skipping: rdiv210
skipping: rdvi210
skipping: rmul210
skipping: rpow210
skipping: rrem210
skipping: rsub210
skipping: rcom211
skipping: rdiv211
skipping: rdvi211
skipping: rmul211
skipping: rpow211
skipping: rrem211
skipping: rsub211
skipping: rcom212
skipping: rdiv212
skipping: rdvi212
skipping: rmul212
skipping: rpow212
skipping: rrem212
skipping: rsub212
skipping: rcom213
skipping: rdiv213
skipping: rdvi213
skipping: rmul213
skipping: rpow213
skipping: rrem213
skipping: rsub213
skipping: rcom214
skipping: rdiv214
skipping: rdvi214
skipping: rmul214
skipping: rpow214
skipping: rrem214
skipping: rsub214
skipping: rcom215
skipping: rdiv215
skipping: rdvi215
skipping: rmul215
skipping: rpow215
skipping: rrem215
skipping: rsub215
skipping: rcom216
skipping: rdiv216
skipping: rdvi216
skipping: rmul216
skipping: rpow216
skipping: rrem216
skipping: rsub216
skipping: rcom217
skipping: rdiv217
skipping: rdvi217
skipping: rmul217
skipping: rpow217
skipping: rrem217
skipping: rsub217
skipping: rcom218
skipping: rdiv218
skipping: rdvi218
skipping: rmul218
skipping: rpow218
skipping: rrem218
skipping: rsub218
skipping: rcom219
skipping: rdiv219
skipping: rdvi219
skipping: rmul219
skipping: rpow219
skipping: rrem219
skipping: rsub219
skipping: rcom220
skipping: rdiv220
skipping: rdvi220
skipping: rmul220
skipping: rpow220
skipping: rrem220
skipping: rsub220
skipping: rcom221
skipping: rdiv221
skipping: rdvi221
skipping: rmul221
skipping: rpow221
skipping: rrem221
skipping: rsub221
skipping: rcom222
skipping: rdiv222
skipping: rdvi222
skipping: rmul222
skipping: rpow222
skipping: rrem222
skipping: rsub222
skipping: rcom223
skipping: rdiv223
skipping: rdvi223
skipping: rmul223
skipping: rpow223
skipping: rrem223
skipping: rsub223
skipping: rcom224
skipping: rdiv224
skipping: rdvi224
skipping: rmul224
skipping: rpow224
skipping: rrem224
skipping: rsub224
skipping: rcom225
skipping: rdiv225
skipping: rdvi225
skipping: rmul225
skipping: rpow225
skipping: rrem225
skipping: rsub225
skipping: rcom226
skipping: rdiv226
skipping: rdvi226
skipping: rmul226
skipping: rpow226
skipping: rrem226
skipping: rsub226
skipping: rcom227
skipping: rdiv227
skipping: rdvi227
skipping: rmul227
skipping: rpow227
skipping: rrem227
skipping: rsub227
skipping: rcom228
skipping: rdiv228
skipping: rdvi228
skipping: rmul228
skipping: rpow228
skipping: rrem228
skipping: rsub228
skipping: rcom229
skipping: rdiv229
skipping: rdvi229
skipping: rmul229
skipping: rpow229
skipping: rrem229
skipping: rsub229
skipping: rcom230
skipping: rdiv230
skipping: rdvi230
skipping: rmul230
skipping: rpow230
skipping: rrem230
skipping: rsub230
skipping: rcom231
skipping: rdiv231
skipping: rdvi231
skipping: rmul231
skipping: rpow231
skipping: rrem231
skipping: rsub231
skipping: rcom232
skipping: rdiv232
skipping: rdvi232
skipping: rmul232
skipping: rpow232
skipping: rrem232
skipping: rsub232
skipping: rcom233
skipping: rdiv233
skipping: rdvi233
skipping: rmul233
skipping: rpow233
skipping: rrem233
skipping: rsub233
skipping: rcom234
skipping: rdiv234
skipping: rdvi234
skipping: rmul234
skipping: rpow234
skipping: rrem234
skipping: rsub234
skipping: rcom235
skipping: rdiv235
skipping: rdvi235
skipping: rmul235
skipping: rpow235
skipping: rrem235
skipping: rsub235
skipping: rcom236
skipping: rdiv236
skipping: rdvi236
skipping: rmul236
skipping: rpow236
skipping: rrem236
skipping: rsub236
skipping: rcom237
skipping: rdiv237
skipping: rdvi237
skipping: rmul237
skipping: rpow237
skipping: rrem237
skipping: rsub237
skipping: rcom238
skipping: rdiv238
skipping: rdvi238
skipping: rmul238
skipping: rpow238
skipping: rrem238
skipping: rsub238
skipping: rcom239
skipping: rdiv239
skipping: rdvi239
skipping: rmul239
skipping: rpow239
skipping: rrem239
skipping: rsub239
skipping: rcom240
skipping: rdiv240
skipping: rdvi240
skipping: rmul240
skipping: rpow240
skipping: rrem240
skipping: rsub240
skipping: rcom241
skipping: rdiv241
skipping: rdvi241
skipping: rmul241
skipping: rpow241
skipping: rrem241
skipping: rsub241
skipping: rcom242
skipping: rdiv242
skipping: rdvi242
skipping: rmul242
skipping: rpow242
skipping: rrem242
skipping: rsub242
skipping: rcom243
skipping: rdiv243
skipping: rdvi243
skipping: rmul243
skipping: rpow243
skipping: rrem243
skipping: rsub243
skipping: rcom244
skipping: rdiv244
skipping: rdvi244
skipping: rmul244
skipping: rpow244
skipping: rrem244
skipping: rsub244
skipping: rcom245
skipping: rdiv245
skipping: rdvi245
skipping: rmul245
skipping: rpow245
skipping: rrem245
skipping: rsub245
skipping: rcom246
skipping: rdiv246
skipping: rdvi246
skipping: rmul246
skipping: rpow246
skipping: rrem246
skipping: rsub246
skipping: rcom247
skipping: rdiv247
skipping: rdvi247
skipping: rmul247
skipping: rpow247
skipping: rrem247
skipping: rsub247
skipping: rcom248
skipping: rdiv248
skipping: rdvi248
skipping: rmul248
skipping: rpow248
skipping: rrem248
skipping: rsub248
skipping: rcom249
skipping: rdiv249
skipping: rdvi249
skipping: rmul249
skipping: rpow249
skipping: rrem249
skipping: rsub249
skipping: rcom250
skipping: rdiv250
skipping: rdvi250
skipping: rmul250
skipping: rpow250
skipping: rrem250
skipping: rsub250
skipping: rcom251
skipping: rdiv251
skipping: rdvi251
skipping: rmul251
skipping: rpow251
skipping: rrem251
skipping: rsub251
skipping: rcom252
skipping: rdiv252
skipping: rdvi252
skipping: rmul252
skipping: rpow252
skipping: rrem252
skipping: rsub252
skipping: rcom253
skipping: rdiv253
skipping: rdvi253
skipping: rmul253
skipping: rpow253
skipping: rrem253
skipping: rsub253
skipping: rcom254
skipping: rdiv254
skipping: rdvi254
skipping: rmul254
skipping: rpow254
skipping: rrem254
skipping: rsub254
skipping: rcom255
skipping: rdiv255
skipping: rdvi255
skipping: rmul255
skipping: rpow255
skipping: rrem255
skipping: rsub255
skipping: rcom256
skipping: rdiv256
skipping: rdvi256
skipping: rmul256
skipping: rpow256
skipping: rrem256
skipping: rsub256
skipping: rcom257
skipping: rdiv257
skipping: rdvi257
skipping: rmul257
skipping: rpow257
skipping: rrem257
skipping: rsub257
skipping: rcom258
skipping: rdiv258
skipping: rdvi258
skipping: rmul258
skipping: rpow258
skipping: rrem258
skipping: rsub258
skipping: rcom259
skipping: rdiv259
skipping: rdvi259
skipping: rmul259
skipping: rpow259
skipping: rrem259
skipping: rsub259
skipping: rcom260
skipping: rdiv260
skipping: rdvi260
skipping: rmul260
skipping: rpow260
skipping: rrem260
skipping: rsub260
skipping: rcom261
skipping: rdiv261
skipping: rdvi261
skipping: rmul261
skipping: rpow261
skipping: rrem261
skipping: rsub261
skipping: rcom262
skipping: rdiv262
skipping: rdvi262
skipping: rmul262
skipping: rpow262
skipping: rrem262
skipping: rsub262
skipping: rcom263
skipping: rdiv263
skipping: rdvi263
skipping: rmul263
skipping: rpow263
skipping: rrem263
skipping: rsub263
skipping: rcom264
skipping: rdiv264
skipping: rdvi264
skipping: rmul264
skipping: rpow264
skipping: rrem264
skipping: rsub264
skipping: rcom265
skipping: rdiv265
skipping: rdvi265
skipping: rmul265
skipping: rpow265
skipping: rrem265
skipping: rsub265
skipping: rcom266
skipping: rdiv266
skipping: rdvi266
skipping: rmul266
skipping: rpow266
skipping: rrem266
skipping: rsub266
skipping: rcom267
skipping: rdiv267
skipping: rdvi267
skipping: rmul267
skipping: rpow267
skipping: rrem267
skipping: rsub267
skipping: rcom268
skipping: rdiv268
skipping: rdvi268
skipping: rmul268
skipping: rpow268
skipping: rrem268
skipping: rsub268
skipping: rcom269
skipping: rdiv269
skipping: rdvi269
skipping: rmul269
skipping: rpow269
skipping: rrem269
skipping: rsub269
skipping: rcom270
skipping: rdiv270
skipping: rdvi270
skipping: rmul270
skipping: rpow270
skipping: rrem270
skipping: rsub270
skipping: rcom271
skipping: rdiv271
skipping: rdvi271
skipping: rmul271
skipping: rpow271
skipping: rrem271
skipping: rsub271
skipping: rcom272
skipping: rdiv272
skipping: rdvi272
skipping: rmul272
skipping: rpow272
skipping: rrem272
skipping: rsub272
skipping: rcom273
skipping: rdiv273
skipping: rdvi273
skipping: rmul273
skipping: rpow273
skipping: rrem273
skipping: rsub273
skipping: rcom274
skipping: rdiv274
skipping: rdvi274
skipping: rmul274
skipping: rpow274
skipping: rrem274
skipping: rsub274
skipping: rcom275
skipping: rdiv275
skipping: rdvi275
skipping: rmul275
skipping: rpow275
skipping: rrem275
skipping: rsub275
skipping: rcom276
skipping: rdiv276
skipping: rdvi276
skipping: rmul276
skipping: rpow276
skipping: rrem276
skipping: rsub276
skipping: rcom277
skipping: rdiv277
skipping: rdvi277
skipping: rmul277
skipping: rpow277
skipping: rrem277
skipping: rsub277
skipping: rcom278
skipping: rdiv278
skipping: rdvi278
skipping: rmul278
skipping: rpow278
skipping: rrem278
skipping: rsub278
skipping: rcom279
skipping: rdiv279
skipping: rdvi279
skipping: rmul279
skipping: rpow279
skipping: rrem279
skipping: rsub279
skipping: rcom280
skipping: rdiv280
skipping: rdvi280
skipping: rmul280
skipping: rpow280
skipping: rrem280
skipping: rsub280
skipping: rcom281
skipping: rdiv281
skipping: rdvi281
skipping: rmul281
skipping: rpow281
skipping: rrem281
skipping: rsub281
skipping: rcom282
skipping: rdiv282
skipping: rdvi282
skipping: rmul282
skipping: rpow282
skipping: rrem282
skipping: rsub282
skipping: rcom283
skipping: rdiv283
skipping: rdvi283
skipping: rmul283
skipping: rpow283
skipping: rrem283
skipping: rsub283
skipping: rcom284
skipping: rdiv284
skipping: rdvi284
skipping: rmul284
skipping: rpow284
skipping: rrem284
skipping: rsub284
skipping: rcom285
skipping: rdiv285
skipping: rdvi285
skipping: rmul285
skipping: rpow285
skipping: rrem285
skipping: rsub285
skipping: rcom286
skipping: rdiv286
skipping: rdvi286
skipping: rmul286
skipping: rpow286
skipping: rrem286
skipping: rsub286
skipping: rcom287
skipping: rdiv287
skipping: rdvi287
skipping: rmul287
skipping: rpow287
skipping: rrem287
skipping: rsub287
skipping: rcom288
skipping: rdiv288
skipping: rdvi288
skipping: rmul288
skipping: rpow288
skipping: rrem288
skipping: rsub288
skipping: rcom289
skipping: rdiv289
skipping: rdvi289
skipping: rmul289
skipping: rpow289
skipping: rrem289
skipping: rsub289
skipping: rcom290
skipping: rdiv290
skipping: rdvi290
skipping: rmul290
skipping: rpow290
skipping: rrem290
skipping: rsub290
skipping: rcom291
skipping: rdiv291
skipping: rdvi291
skipping: rmul291
skipping: rpow291
skipping: rrem291
skipping: rsub291
skipping: rcom292
skipping: rdiv292
skipping: rdvi292
skipping: rmul292
skipping: rpow292
skipping: rrem292
skipping: rsub292
skipping: rcom293
skipping: rdiv293
skipping: rdvi293
skipping: rmul293
skipping: rpow293
skipping: rrem293
skipping: rsub293
skipping: rcom294
skipping: rdiv294
skipping: rdvi294
skipping: rmul294
skipping: rpow294
skipping: rrem294
skipping: rsub294
skipping: rcom295
skipping: rdiv295
skipping: rdvi295
skipping: rmul295
skipping: rpow295
skipping: rrem295
skipping: rsub295
skipping: rcom296
skipping: rdiv296
skipping: rdvi296
skipping: rmul296
skipping: rpow296
skipping: rrem296
skipping: rsub296
skipping: rcom297
skipping: rdiv297
skipping: rdvi297
skipping: rmul297
skipping: rpow297
skipping: rrem297
skipping: rsub297
skipping: rcom298
skipping: rdiv298
skipping: rdvi298
skipping: rmul298
skipping: rpow298
skipping: rrem298
skipping: rsub298
skipping: rcom299
skipping: rdiv299
skipping: rdvi299
skipping: rmul299
skipping: rpow299
skipping: rrem299
skipping: rsub299
skipping: rcom300
skipping: rdiv300
skipping: rdvi300
skipping: rmul300
skipping: rpow300
skipping: rrem300
skipping: rsub300
skipping: rcom301
skipping: rdiv301
skipping: rdvi301
skipping: rmul301
skipping: rpow301
skipping: rrem301
skipping: rsub301
skipping: rcom302
skipping: rdiv302
skipping: rdvi302
skipping: rmul302
skipping: rpow302
skipping: rrem302
skipping: rsub302
skipping: rcom303
skipping: rdiv303
skipping: rdvi303
skipping: rmul303
skipping: rpow303
skipping: rrem303
skipping: rsub303
skipping: rcom304
skipping: rdiv304
skipping: rdvi304
skipping: rmul304
skipping: rpow304
skipping: rrem304
skipping: rsub304
skipping: rcom305
skipping: rdiv305
skipping: rdvi305
skipping: rmul305
skipping: rpow305
skipping: rrem305
skipping: rsub305
skipping: rcom306
skipping: rdiv306
skipping: rdvi306
skipping: rmul306
skipping: rpow306
skipping: rrem306
skipping: rsub306
skipping: rcom307
skipping: rdiv307
skipping: rdvi307
skipping: rmul307
skipping: rpow307
skipping: rrem307
skipping: rsub307
skipping: rcom308
skipping: rdiv308
skipping: rdvi308
skipping: rmul308
skipping: rpow308
skipping: rrem308
skipping: rsub308
skipping: rcom309
skipping: rdiv309
skipping: rdvi309
skipping: rmul309
skipping: rpow309
skipping: rrem309
skipping: rsub309
skipping: rcom310
skipping: rdiv310
skipping: rdvi310
skipping: rmul310
skipping: rpow310
skipping: rrem310
skipping: rsub310
skipping: rcom311
skipping: rdiv311
skipping: rdvi311
skipping: rmul311
skipping: rpow311
skipping: rrem311
skipping: rsub311
skipping: rcom312
skipping: rdiv312
skipping: rdvi312
skipping: rmul312
skipping: rpow312
skipping: rrem312
skipping: rsub312
skipping: rcom313
skipping: rdiv313
skipping: rdvi313
skipping: rmul313
skipping: rpow313
skipping: rrem313
skipping: rsub313
skipping: rcom314
skipping: rdiv314
skipping: rdvi314
skipping: rmul314
skipping: rpow314
skipping: rrem314
skipping: rsub314
skipping: rcom315
skipping: rdiv315
skipping: rdvi315
skipping: rmul315
skipping: rpow315
skipping: rrem315
skipping: rsub315
skipping: rcom316
skipping: rdiv316
skipping: rdvi316
skipping: rmul316
skipping: rpow316
skipping: rrem316
skipping: rsub316
skipping: rcom317
skipping: rdiv317
skipping: rdvi317
skipping: rmul317
skipping: rpow317
skipping: rrem317
skipping: rsub317
skipping: rcom318
skipping: rdiv318
skipping: rdvi318
skipping: rmul318
skipping: rpow318
skipping: rrem318
skipping: rsub318
skipping: rcom319
skipping: rdiv319
skipping: rdvi319
skipping: rmul319
skipping: rpow319
skipping: rrem319
skipping: rsub319
skipping: rcom320
skipping: rdiv320
skipping: rdvi320
skipping: rmul320
skipping: rpow320
skipping: rrem320
skipping: rsub320
skipping: rcom321
skipping: rdiv321
skipping: rdvi321
skipping: rmul321
skipping: rpow321
skipping: rrem321
skipping: rsub321
skipping: rcom322
skipping: rdiv322
skipping: rdvi322
skipping: rmul322
skipping: rpow322
skipping: rrem322
skipping: rsub322
skipping: rcom323
skipping: rdiv323
skipping: rdvi323
skipping: rmul323
skipping: rpow323
skipping: rrem323
skipping: rsub323
skipping: rcom324
skipping: rdiv324
skipping: rdvi324
skipping: rmul324
skipping: rpow324
skipping: rrem324
skipping: rsub324
skipping: rcom325
skipping: rdiv325
skipping: rdvi325
skipping: rmul325
skipping: rpow325
skipping: rrem325
skipping: rsub325
skipping: rcom326
skipping: rdiv326
skipping: rdvi326
skipping: rmul326
skipping: rpow326
skipping: rrem326
skipping: rsub326
skipping: rcom327
skipping: rdiv327
skipping: rdvi327
skipping: rmul327
skipping: rpow327
skipping: rrem327
skipping: rsub327
skipping: rcom328
skipping: rdiv328
skipping: rdvi328
skipping: rmul328
skipping: rpow328
skipping: rrem328
skipping: rsub328
skipping: rcom329
skipping: rdiv329
skipping: rdvi329
skipping: rmul329
skipping: rpow329
skipping: rrem329
skipping: rsub329
skipping: rcom330
skipping: rdiv330
skipping: rdvi330
skipping: rmul330
skipping: rpow330
skipping: rrem330
skipping: rsub330
skipping: rcom331
skipping: rdiv331
skipping: rdvi331
skipping: rmul331
skipping: rpow331
skipping: rrem331
skipping: rsub331
skipping: rcom332
skipping: rdiv332
skipping: rdvi332
skipping: rmul332
skipping: rpow332
skipping: rrem332
skipping: rsub332
skipping: rcom333
skipping: rdiv333
skipping: rdvi333
skipping: rmul333
skipping: rpow333
skipping: rrem333
skipping: rsub333
skipping: rcom334
skipping: rdiv334
skipping: rdvi334
skipping: rmul334
skipping: rpow334
skipping: rrem334
skipping: rsub334
skipping: rcom335
skipping: rdiv335
skipping: rdvi335
skipping: rmul335
skipping: rpow335
skipping: rrem335
skipping: rsub335
skipping: rcom336
skipping: rdiv336
skipping: rdvi336
skipping: rmul336
skipping: rpow336
skipping: rrem336
skipping: rsub336
skipping: rcom337
skipping: rdiv337
skipping: rdvi337
skipping: rmul337
skipping: rpow337
skipping: rrem337
skipping: rsub337
skipping: rcom338
skipping: rdiv338
skipping: rdvi338
skipping: rmul338
skipping: rpow338
skipping: rrem338
skipping: rsub338
skipping: rcom339
skipping: rdiv339
skipping: rdvi339
skipping: rmul339
skipping: rpow339
skipping: rrem339
skipping: rsub339
skipping: rcom340
skipping: rdiv340
skipping: rdvi340
skipping: rmul340
skipping: rpow340
skipping: rrem340
skipping: rsub340
skipping: rcom341
skipping: rdiv341
skipping: rdvi341
skipping: rmul341
skipping: rpow341
skipping: rrem341
skipping: rsub341
skipping: rcom342
skipping: rdiv342
skipping: rdvi342
skipping: rmul342
skipping: rpow342
skipping: rrem342
skipping: rsub342
skipping: rcom343
skipping: rdiv343
skipping: rdvi343
skipping: rmul343
skipping: rpow343
skipping: rrem343
skipping: rsub343
skipping: rcom344
skipping: rdiv344
skipping: rdvi344
skipping: rmul344
skipping: rpow344
skipping: rrem344
skipping: rsub344
skipping: rcom345
skipping: rdiv345
skipping: rdvi345
skipping: rmul345
skipping: rpow345
skipping: rrem345
skipping: rsub345
skipping: rcom346
skipping: rdiv346
skipping: rdvi346
skipping: rmul346
skipping: rpow346
skipping: rrem346
skipping: rsub346
skipping: rcom347
skipping: rdiv347
skipping: rdvi347
skipping: rmul347
skipping: rpow347
skipping: rrem347
skipping: rsub347
skipping: rcom348
skipping: rdiv348
skipping: rdvi348
skipping: rmul348
skipping: rpow348
skipping: rrem348
skipping: rsub348
skipping: rcom349
skipping: rdiv349
skipping: rdvi349
skipping: rmul349
skipping: rpow349
skipping: rrem349
skipping: rsub349
skipping: rcom350
skipping: rdiv350
skipping: rdvi350
skipping: rmul350
skipping: rpow350
skipping: rrem350
skipping: rsub350
skipping: rcom351
skipping: rdiv351
skipping: rdvi351
skipping: rmul351
skipping: rpow351
skipping: rrem351
skipping: rsub351
skipping: rcom352
skipping: rdiv352
skipping: rdvi352
skipping: rmul352
skipping: rpow352
skipping: rrem352
skipping: rsub352
skipping: rcom353
skipping: rdiv353
skipping: rdvi353
skipping: rmul353
skipping: rpow353
skipping: rrem353
skipping: rsub353
skipping: rcom354
skipping: rdiv354
skipping: rdvi354
skipping: rmul354
skipping: rpow354
skipping: rrem354
skipping: rsub354
skipping: rcom355
skipping: rdiv355
skipping: rdvi355
skipping: rmul355
skipping: rpow355
skipping: rrem355
skipping: rsub355
skipping: rcom356
skipping: rdiv356
skipping: rdvi356
skipping: rmul356
skipping: rpow356
skipping: rrem356
skipping: rsub356
skipping: rcom357
skipping: rdiv357
skipping: rdvi357
skipping: rmul357
skipping: rpow357
skipping: rrem357
skipping: rsub357
skipping: rcom358
skipping: rdiv358
skipping: rdvi358
skipping: rmul358
skipping: rpow358
skipping: rrem358
skipping: rsub358
skipping: rcom359
skipping: rdiv359
skipping: rdvi359
skipping: rmul359
skipping: rpow359
skipping: rrem359
skipping: rsub359
skipping: rcom360
skipping: rdiv360
skipping: rdvi360
skipping: rmul360
skipping: rpow360
skipping: rrem360
skipping: rsub360
skipping: rcom361
skipping: rdiv361
skipping: rdvi361
skipping: rmul361
skipping: rpow361
skipping: rrem361
skipping: rsub361
skipping: rcom362
skipping: rdiv362
skipping: rdvi362
skipping: rmul362
skipping: rpow362
skipping: rrem362
skipping: rsub362
skipping: rcom363
skipping: rdiv363
skipping: rdvi363
skipping: rmul363
skipping: rpow363
skipping: rrem363
skipping: rsub363
skipping: rcom364
skipping: rdiv364
skipping: rdvi364
skipping: rmul364
skipping: rpow364
skipping: rrem364
skipping: rsub364
skipping: rcom365
skipping: rdiv365
skipping: rdvi365
skipping: rmul365
skipping: rpow365
skipping: rrem365
skipping: rsub365
skipping: rcom366
skipping: rdiv366
skipping: rdvi366
skipping: rmul366
skipping: rpow366
skipping: rrem366
skipping: rsub366
skipping: rcom367
skipping: rdiv367
skipping: rdvi367
skipping: rmul367
skipping: rpow367
skipping: rrem367
skipping: rsub367
skipping: rcom368
skipping: rdiv368
skipping: rdvi368
skipping: rmul368
skipping: rpow368
skipping: rrem368
skipping: rsub368
skipping: rcom369
skipping: rdiv369
skipping: rdvi369
skipping: rmul369
skipping: rpow369
skipping: rrem369
skipping: rsub369
skipping: rcom370
skipping: rdiv370
skipping: rdvi370
skipping: rmul370
skipping: rpow370
skipping: rrem370
skipping: rsub370
skipping: rcom371
skipping: rdiv371
skipping: rdvi371
skipping: rmul371
skipping: rpow371
skipping: rrem371
skipping: rsub371
skipping: rcom372
skipping: rdiv372
skipping: rdvi372
skipping: rmul372
skipping: rpow372
skipping: rrem372
skipping: rsub372
skipping: rcom373
skipping: rdiv373
skipping: rdvi373
skipping: rmul373
skipping: rpow373
skipping: rrem373
skipping: rsub373
skipping: rcom374
skipping: rdiv374
skipping: rdvi374
skipping: rmul374
skipping: rpow374
skipping: rrem374
skipping: rsub374
skipping: rcom375
skipping: rdiv375
skipping: rdvi375
skipping: rmul375
skipping: rpow375
skipping: rrem375
skipping: rsub375
skipping: rcom376
skipping: rdiv376
skipping: rdvi376
skipping: rmul376
skipping: rpow376
skipping: rrem376
skipping: rsub376
skipping: rcom377
skipping: rdiv377
skipping: rdvi377
skipping: rmul377
skipping: rpow377
skipping: rrem377
skipping: rsub377
skipping: rcom378
skipping: rdiv378
skipping: rdvi378
skipping: rmul378
skipping: rpow378
skipping: rrem378
skipping: rsub378
skipping: rcom379
skipping: rdiv379
skipping: rdvi379
skipping: rmul379
skipping: rpow379
skipping: rrem379
skipping: rsub379
skipping: rcom380
skipping: rdiv380
skipping: rdvi380
skipping: rmul380
skipping: rpow380
skipping: rrem380
skipping: rsub380
skipping: rcom381
skipping: rdiv381
skipping: rdvi381
skipping: rmul381
skipping: rpow381
skipping: rrem381
skipping: rsub381
skipping: rcom382
skipping: rdiv382
skipping: rdvi382
skipping: rmul382
skipping: rpow382
skipping: rrem382
skipping: rsub382
skipping: rcom383
skipping: rdiv383
skipping: rdvi383
skipping: rmul383
skipping: rpow383
skipping: rrem383
skipping: rsub383
skipping: rcom384
skipping: rdiv384
skipping: rdvi384
skipping: rmul384
skipping: rpow384
skipping: rrem384
skipping: rsub384
skipping: rcom385
skipping: rdiv385
skipping: rdvi385
skipping: rmul385
skipping: rpow385
skipping: rrem385
skipping: rsub385
skipping: rcom386
skipping: rdiv386
skipping: rdvi386
skipping: rmul386
skipping: rpow386
skipping: rrem386
skipping: rsub386
skipping: rcom387
skipping: rdiv387
skipping: rdvi387
skipping: rmul387
skipping: rpow387
skipping: rrem387
skipping: rsub387
skipping: rcom388
skipping: rdiv388
skipping: rdvi388
skipping: rmul388
skipping: rpow388
skipping: rrem388
skipping: rsub388
skipping: rcom389
skipping: rdiv389
skipping: rdvi389
skipping: rmul389
skipping: rpow389
skipping: rrem389
skipping: rsub389
skipping: rcom390
skipping: rdiv390
skipping: rdvi390
skipping: rmul390
skipping: rpow390
skipping: rrem390
skipping: rsub390
skipping: rcom391
skipping: rdiv391
skipping: rdvi391
skipping: rmul391
skipping: rpow391
skipping: rrem391
skipping: rsub391
skipping: rcom392
skipping: rdiv392
skipping: rdvi392
skipping: rmul392
skipping: rpow392
skipping: rrem392
skipping: rsub392
skipping: rcom393
skipping: rdiv393
skipping: rdvi393
skipping: rmul393
skipping: rpow393
skipping: rrem393
skipping: rsub393
skipping: rcom394
skipping: rdiv394
skipping: rdvi394
skipping: rmul394
skipping: rpow394
skipping: rrem394
skipping: rsub394
skipping: rcom395
skipping: rdiv395
skipping: rdvi395
skipping: rmul395
skipping: rpow395
skipping: rrem395
skipping: rsub395
skipping: rcom396
skipping: rdiv396
skipping: rdvi396
skipping: rmul396
skipping: rpow396
skipping: rrem396
skipping: rsub396
skipping: rcom397
skipping: rdiv397
skipping: rdvi397
skipping: rmul397
skipping: rpow397
skipping: rrem397
skipping: rsub397
skipping: rcom398
skipping: rdiv398
skipping: rdvi398
skipping: rmul398
skipping: rpow398
skipping: rrem398
skipping: rsub398
skipping: rcom399
skipping: rdiv399
skipping: rdvi399
skipping: rmul399
skipping: rpow399
skipping: rrem399
skipping: rsub399
skipping: rcom400
skipping: rdiv400
skipping: rdvi400
skipping: rmul400
skipping: rpow400
skipping: rrem400
skipping: rsub400
skipping: rcom401
skipping: rdiv401
skipping: rdvi401
skipping: rmul401
skipping: rpow401
skipping: rrem401
skipping: rsub401
skipping: rcom402
skipping: rdiv402
skipping: rdvi402
skipping: rmul402
skipping: rpow402
skipping: rrem402
skipping: rsub402
skipping: rcom403
skipping: rdiv403
skipping: rdvi403
skipping: rmul403
skipping: rpow403
skipping: rrem403
skipping: rsub403
skipping: rcom404
skipping: rdiv404
skipping: rdvi404
skipping: rmul404
skipping: rpow404
skipping: rrem404
skipping: rsub404
skipping: rcom405
skipping: rdiv405
skipping: rdvi405
skipping: rmul405
skipping: rpow405
skipping: rrem405
skipping: rsub405
skipping: rcom406
skipping: rdiv406
skipping: rdvi406
skipping: rmul406
skipping: rpow406
skipping: rrem406
skipping: rsub406
skipping: rcom407
skipping: rdiv407
skipping: rdvi407
skipping: rmul407
skipping: rpow407
skipping: rrem407
skipping: rsub407
skipping: rcom408
skipping: rdiv408
skipping: rdvi408
skipping: rmul408
skipping: rpow408
skipping: rrem408
skipping: rsub408
skipping: rcom409
skipping: rdiv409
skipping: rdvi409
skipping: rmul409
skipping: rpow409
skipping: rrem409
skipping: rsub409
skipping: rcom410
skipping: rdiv410
skipping: rdvi410
skipping: rmul410
skipping: rpow410
skipping: rrem410
skipping: rsub410
skipping: rcom411
skipping: rdiv411
skipping: rdvi411
skipping: rmul411
skipping: rpow411
skipping: rrem411
skipping: rsub411
skipping: rcom412
skipping: rdiv412
skipping: rdvi412
skipping: rmul412
skipping: rpow412
skipping: rrem412
skipping: rsub412
skipping: rcom413
skipping: rdiv413
skipping: rdvi413
skipping: rmul413
skipping: rpow413
skipping: rrem413
skipping: rsub413
skipping: rcom414
skipping: rdiv414
skipping: rdvi414
skipping: rmul414
skipping: rpow414
skipping: rrem414
skipping: rsub414
skipping: rcom415
skipping: rdiv415
skipping: rdvi415
skipping: rmul415
skipping: rpow415
skipping: rrem415
skipping: rsub415
skipping: rcom416
skipping: rdiv416
skipping: rdvi416
skipping: rmul416
skipping: rpow416
skipping: rrem416
skipping: rsub416
skipping: rcom417
skipping: rdiv417
skipping: rdvi417
skipping: rmul417
skipping: rpow417
skipping: rrem417
skipping: rsub417
skipping: rcom418
skipping: rdiv418
skipping: rdvi418
skipping: rmul418
skipping: rpow418
skipping: rrem418
skipping: rsub418
skipping: rcom419
skipping: rdiv419
skipping: rdvi419
skipping: rmul419
skipping: rpow419
skipping: rrem419
skipping: rsub419
skipping: rcom420
skipping: rdiv420
skipping: rdvi420
skipping: rmul420
skipping: rpow420
skipping: rrem420
skipping: rsub420
skipping: rcom421
skipping: rdiv421
skipping: rdvi421
skipping: rmul421
skipping: rpow421
skipping: rrem421
skipping: rsub421
skipping: rcom422
skipping: rdiv422
skipping: rdvi422
skipping: rmul422
skipping: rpow422
skipping: rrem422
skipping: rsub422
skipping: rcom423
skipping: rdiv423
skipping: rdvi423
skipping: rmul423
skipping: rpow423
skipping: rrem423
skipping: rsub423
skipping: rcom424
skipping: rdiv424
skipping: rdvi424
skipping: rmul424
skipping: rpow424
skipping: rrem424
skipping: rsub424
skipping: rcom425
skipping: rdiv425
skipping: rdvi425
skipping: rmul425
skipping: rpow425
skipping: rrem425
skipping: rsub425
skipping: rcom426
skipping: rdiv426
skipping: rdvi426
skipping: rmul426
skipping: rpow426
skipping: rrem426
skipping: rsub426
skipping: rcom427
skipping: rdiv427
skipping: rdvi427
skipping: rmul427
skipping: rpow427
skipping: rrem427
skipping: rsub427
skipping: rcom428
skipping: rdiv428
skipping: rdvi428
skipping: rmul428
skipping: rpow428
skipping: rrem428
skipping: rsub428
skipping: rcom429
skipping: rdiv429
skipping: rdvi429
skipping: rmul429
skipping: rpow429
skipping: rrem429
skipping: rsub429
skipping: rcom430
skipping: rdiv430
skipping: rdvi430
skipping: rmul430
skipping: rpow430
skipping: rrem430
skipping: rsub430
skipping: rcom431
skipping: rdiv431
skipping: rdvi431
skipping: rmul431
skipping: rpow431
skipping: rrem431
skipping: rsub431
skipping: rcom432
skipping: rdiv432
skipping: rdvi432
skipping: rmul432
skipping: rpow432
skipping: rrem432
skipping: rsub432
skipping: rcom433
skipping: rdiv433
skipping: rdvi433
skipping: rmul433
skipping: rpow433
skipping: rrem433
skipping: rsub433
skipping: rcom434
skipping: rdiv434
skipping: rdvi434
skipping: rmul434
skipping: rpow434
skipping: rrem434
skipping: rsub434
skipping: rcom435
skipping: rdiv435
skipping: rdvi435
skipping: rmul435
skipping: rpow435
skipping: rrem435
skipping: rsub435
skipping: rcom436
skipping: rdiv436
skipping: rdvi436
skipping: rmul436
skipping: rpow436
skipping: rrem436
skipping: rsub436
skipping: rcom437
skipping: rdiv437
skipping: rdvi437
skipping: rmul437
skipping: rpow437
skipping: rrem437
skipping: rsub437
skipping: rcom438
skipping: rdiv438
skipping: rdvi438
skipping: rmul438
skipping: rpow438
skipping: rrem438
skipping: rsub438
skipping: rcom439
skipping: rdiv439
skipping: rdvi439
skipping: rmul439
skipping: rpow439
skipping: rrem439
skipping: rsub439
skipping: rcom440
skipping: rdiv440
skipping: rdvi440
skipping: rmul440
skipping: rpow440
skipping: rrem440
skipping: rsub440
skipping: rcom441
skipping: rdiv441
skipping: rdvi441
skipping: rmul441
skipping: rpow441
skipping: rrem441
skipping: rsub441
skipping: rcom442
skipping: rdiv442
skipping: rdvi442
skipping: rmul442
skipping: rpow442
skipping: rrem442
skipping: rsub442
skipping: rcom443
skipping: rdiv443
skipping: rdvi443
skipping: rmul443
skipping: rpow443
skipping: rrem443
skipping: rsub443
skipping: rcom444
skipping: rdiv444
skipping: rdvi444
skipping: rmul444
skipping: rpow444
skipping: rrem444
skipping: rsub444
skipping: rcom445
skipping: rdiv445
skipping: rdvi445
skipping: rmul445
skipping: rpow445
skipping: rrem445
skipping: rsub445
skipping: rcom446
skipping: rdiv446
skipping: rdvi446
skipping: rmul446
skipping: rpow446
skipping: rrem446
skipping: rsub446
skipping: rcom447
skipping: rdiv447
skipping: rdvi447
skipping: rmul447
skipping: rpow447
skipping: rrem447
skipping: rsub447
skipping: rcom448
skipping: rdiv448
skipping: rdvi448
skipping: rmul448
skipping: rpow448
skipping: rrem448
skipping: rsub448
skipping: rcom449
skipping: rdiv449
skipping: rdvi449
skipping: rmul449
skipping: rpow449
skipping: rrem449
skipping: rsub449
skipping: rcom450
skipping: rdiv450
skipping: rdvi450
skipping: rmul450
skipping: rpow450
skipping: rrem450
skipping: rsub450
skipping: rcom451
skipping: rdiv451
skipping: rdvi451
skipping: rmul451
skipping: rpow451
skipping: rrem451
skipping: rsub451
skipping: rcom452
skipping: rdiv452
skipping: rdvi452
skipping: rmul452
skipping: rpow452
skipping: rrem452
skipping: rsub452
skipping: rcom453
skipping: rdiv453
skipping: rdvi453
skipping: rmul453
skipping: rpow453
skipping: rrem453
skipping: rsub453
skipping: rcom454
skipping: rdiv454
skipping: rdvi454
skipping: rmul454
skipping: rpow454
skipping: rrem454
skipping: rsub454
skipping: rcom455
skipping: rdiv455
skipping: rdvi455
skipping: rmul455
skipping: rpow455
skipping: rrem455
skipping: rsub455
skipping: rcom456
skipping: rdiv456
skipping: rdvi456
skipping: rmul456
skipping: rpow456
skipping: rrem456
skipping: rsub456
skipping: rcom457
skipping: rdiv457
skipping: rdvi457
skipping: rmul457
skipping: rpow457
skipping: rrem457
skipping: rsub457
skipping: rcom458
skipping: rdiv458
skipping: rdvi458
skipping: rmul458
skipping: rpow458
skipping: rrem458
skipping: rsub458
skipping: rcom459
skipping: rdiv459
skipping: rdvi459
skipping: rmul459
skipping: rpow459
skipping: rrem459
skipping: rsub459
skipping: rcom460
skipping: rdiv460
skipping: rdvi460
skipping: rmul460
skipping: rpow460
skipping: rrem460
skipping: rsub460
skipping: rcom461
skipping: rdiv461
skipping: rdvi461
skipping: rmul461
skipping: rpow461
skipping: rrem461
skipping: rsub461
skipping: rcom462
skipping: rdiv462
skipping: rdvi462
skipping: rmul462
skipping: rpow462
skipping: rrem462
skipping: rsub462
skipping: rcom463
skipping: rdiv463
skipping: rdvi463
skipping: rmul463
skipping: rpow463
skipping: rrem463
skipping: rsub463
skipping: rcom464
skipping: rdiv464
skipping: rdvi464
skipping: rmul464
skipping: rpow464
skipping: rrem464
skipping: rsub464
skipping: rcom465
skipping: rdiv465
skipping: rdvi465
skipping: rmul465
skipping: rpow465
skipping: rrem465
skipping: rsub465
skipping: rcom466
skipping: rdiv466
skipping: rdvi466
skipping: rmul466
skipping: rpow466
skipping: rrem466
skipping: rsub466
skipping: rcom467
skipping: rdiv467
skipping: rdvi467
skipping: rmul467
skipping: rpow467
skipping: rrem467
skipping: rsub467
skipping: rcom468
skipping: rdiv468
skipping: rdvi468
skipping: rmul468
skipping: rpow468
skipping: rrem468
skipping: rsub468
skipping: rcom469
skipping: rdiv469
skipping: rdvi469
skipping: rmul469
skipping: rpow469
skipping: rrem469
skipping: rsub469
skipping: rcom470
skipping: rdiv470
skipping: rdvi470
skipping: rmul470
skipping: rpow470
skipping: rrem470
skipping: rsub470
skipping: rcom471
skipping: rdiv471
skipping: rdvi471
skipping: rmul471
skipping: rpow471
skipping: rrem471
skipping: rsub471
skipping: rcom472
skipping: rdiv472
skipping: rdvi472
skipping: rmul472
skipping: rpow472
skipping: rrem472
skipping: rsub472
skipping: rcom473
skipping: rdiv473
skipping: rdvi473
skipping: rmul473
skipping: rpow473
skipping: rrem473
skipping: rsub473
skipping: rcom474
skipping: rdiv474
skipping: rdvi474
skipping: rmul474
skipping: rpow474
skipping: rrem474
skipping: rsub474
skipping: rcom475
skipping: rdiv475
skipping: rdvi475
skipping: rmul475
skipping: rpow475
skipping: rrem475
skipping: rsub475
skipping: rcom476
skipping: rdiv476
skipping: rdvi476
skipping: rmul476
skipping: rpow476
skipping: rrem476
skipping: rsub476
skipping: rcom477
skipping: rdiv477
skipping: rdvi477
skipping: rmul477
skipping: rpow477
skipping: rrem477
skipping: rsub477
skipping: rcom478
skipping: rdiv478
skipping: rdvi478
skipping: rmul478
skipping: rpow478
skipping: rrem478
skipping: rsub478
skipping: rcom479
skipping: rdiv479
skipping: rdvi479
skipping: rmul479
skipping: rpow479
skipping: rrem479
skipping: rsub479
skipping: rcom480
skipping: rdiv480
skipping: rdvi480
skipping: rmul480
skipping: rpow480
skipping: rrem480
skipping: rsub480
skipping: rcom481
skipping: rdiv481
skipping: rdvi481
skipping: rmul481
skipping: rpow481
skipping: rrem481
skipping: rsub481
skipping: rcom482
skipping: rdiv482
skipping: rdvi482
skipping: rmul482
skipping: rpow482
skipping: rrem482
skipping: rsub482
skipping: rcom483
skipping: rdiv483
skipping: rdvi483
skipping: rmul483
skipping: rpow483
skipping: rrem483
skipping: rsub483
skipping: rcom484
skipping: rdiv484
skipping: rdvi484
skipping: rmul484
skipping: rpow484
skipping: rrem484
skipping: rsub484
skipping: rcom485
skipping: rdiv485
skipping: rdvi485
skipping: rmul485
skipping: rpow485
skipping: rrem485
skipping: rsub485
skipping: rcom486
skipping: rdiv486
skipping: rdvi486
skipping: rmul486
skipping: rpow486
skipping: rrem486
skipping: rsub486
skipping: rcom487
skipping: rdiv487
skipping: rdvi487
skipping: rmul487
skipping: rpow487
skipping: rrem487
skipping: rsub487
skipping: rcom488
skipping: rdiv488
skipping: rdvi488
skipping: rmul488
skipping: rpow488
skipping: rrem488
skipping: rsub488
skipping: rcom489
skipping: rdiv489
skipping: rdvi489
skipping: rmul489
skipping: rpow489
skipping: rrem489
skipping: rsub489
skipping: rcom490
skipping: rdiv490
skipping: rdvi490
skipping: rmul490
skipping: rpow490
skipping: rrem490
skipping: rsub490
skipping: rcom491
skipping: rdiv491
skipping: rdvi491
skipping: rmul491
skipping: rpow491
skipping: rrem491
skipping: rsub491
skipping: rcom492
skipping: rdiv492
skipping: rdvi492
skipping: rmul492
skipping: rpow492
skipping: rrem492
skipping: rsub492
skipping: rcom493
skipping: rdiv493
skipping: rdvi493
skipping: rmul493
skipping: rpow493
skipping: rrem493
skipping: rsub493
skipping: rcom494
skipping: rdiv494
skipping: rdvi494
skipping: rmul494
skipping: rpow494
skipping: rrem494
skipping: rsub494
skipping: rcom495
skipping: rdiv495
skipping: rdvi495
skipping: rmul495
skipping: rpow495
skipping: rrem495
skipping: rsub495
skipping: rcom496
skipping: rdiv496
skipping: rdvi496
skipping: rmul496
skipping: rpow496
skipping: rrem496
skipping: rsub496
skipping: rcom497
skipping: rdiv497
skipping: rdvi497
skipping: rmul497
skipping: rpow497
skipping: rrem497
skipping: rsub497
skipping: rcom498
skipping: rdiv498
skipping: rdvi498
skipping: rmul498
skipping: rpow498
skipping: rrem498
skipping: rsub498
skipping: rcom499
skipping: rdiv499
skipping: rdvi499
skipping: rmul499
skipping: rpow499
skipping: rrem499
skipping: rsub499
skipping: rcom500
skipping: rdiv500
skipping: rdvi500
skipping: rmul500
skipping: rpow500
skipping: rrem500
skipping: rsub500
general_decimal_arithmetic/test_cases/subset_arithmetic/randoms0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: red001
skipping: red002
skipping: red003
skipping: red004
skipping: red005
skipping: red006
skipping: red007
skipping: red008
skipping: red009
skipping: red010
skipping: red011
skipping: red012
skipping: red013
skipping: red014
skipping: red015
skipping: red016
skipping: red017
skipping: red018
skipping: red019
skipping: red020
skipping: red030
skipping: red031
skipping: red032
skipping: red033
skipping: red034
skipping: red035
skipping: red036
skipping: red037
skipping: red038
skipping: red039
skipping: red041
skipping: red042
skipping: red043
skipping: red044
skipping: red045
skipping: red046
skipping: red047
skipping: red048
skipping: red049
skipping: red050
skipping: red051
skipping: red052
skipping: red053
skipping: red054
skipping: red055
skipping: red056
skipping: red060
skipping: red061
skipping: red062
skipping: red063
skipping: red064
skipping: red065
skipping: red066
skipping: red067
skipping: red068
skipping: red069
skipping: red070
skipping: red071
skipping: red080
skipping: red081
skipping: red082
skipping: red083
skipping: red084
skipping: red085
skipping: red086
skipping: red087
skipping: red088
skipping: red089
skipping: red090
skipping: red091
skipping: red092
skipping: red093
skipping: red100
skipping: red101
skipping: red102
skipping: red103
skipping: red104
skipping: red105
skipping: red106
skipping: red107
skipping: red108
skipping: red109
skipping: red110
skipping: red111
skipping: red112
skipping: red113
skipping: red114
skipping: red115
skipping: red116
skipping: red117
skipping: red118
skipping: red119
skipping: red120
skipping: red121
skipping: red122
skipping: red123
skipping: red124
skipping: red125
skipping: red126
skipping: red140
skipping: red141
skipping: red142
skipping: red143
skipping: red144
skipping: red145
skipping: red900
general_decimal_arithmetic/test_cases/subset_arithmetic/reduce0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: rem001
skipping: rem002
skipping: rem003
skipping: rem004
skipping: rem005
skipping: rem006
skipping: rem007
skipping: rem008
skipping: rem009
skipping: rem010
skipping: rem011
skipping: rem012
skipping: rem013
skipping: rem014
skipping: rem015
skipping: rem016
skipping: rem017
skipping: rem018
skipping: rem019
skipping: rem020
skipping: rem021
skipping: rem022
skipping: rem023
skipping: rem024
skipping: rem025
skipping: rem030
skipping: rem031
skipping: rem032
skipping: rem033
skipping: rem034
skipping: rem035
skipping: rem040
skipping: rem041
skipping: rem042
skipping: rem043
skipping: rem044
skipping: rem045
skipping: rem050
skipping: rem051
skipping: rem052
skipping: rem053
skipping: rem054
skipping: rem055
skipping: rem060
skipping: rem061
skipping: rem062
skipping: rem063
skipping: rem064
skipping: rem065
skipping: rem070
skipping: rem071
skipping: rem072
skipping: rem073
skipping: rem074
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: rem080
skipping: rem081
skipping: rem082
skipping: rem083
skipping: rem084
skipping: rem085
skipping: rem086
skipping: rem087
skipping: rem088
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: rem090
skipping: rem091
skipping: rem092
skipping: rem093
skipping: rem094
skipping: rem100
skipping: rem101
skipping: rem102
skipping: rem103
skipping: rem104
skipping: rem105
skipping: rem106
skipping: rem107
skipping: rem108
skipping: rem109
skipping: rem110
skipping: rem111
skipping: rem112
skipping: rem113
skipping: rem114
skipping: rem115
skipping: rem116
skipping: rem117
skipping: rem118
skipping: rem119
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem201
skipping: rem202
skipping: rem203
skipping: rem204
skipping: rem205
skipping: rem206
skipping: rem207
skipping: rem208
skipping: rem209
skipping: rem210
skipping: rem211
skipping: rem231
skipping: rem232
skipping: rem233
skipping: rem234
skipping: rem235
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem270
skipping: rem271
skipping: rem272
skipping: rem273
skipping: rem274
skipping: rem275
skipping: rem276
skipping: rem277
skipping: rem280
skipping: rem281
skipping: rem282
skipping: rem283
skipping: rem284
skipping: rem285
skipping: rem286
skipping: rem287
skipping: rem288
skipping: rem301
skipping: rem302
skipping: rem303
skipping: rem304
skipping: rem305
skipping: rem306
skipping: rem307
skipping: rem308
skipping: rem309
skipping: rem310
skipping: rem311
skipping: rem312
skipping: rem313
skipping: rem314
skipping: rem315
skipping: rem316
skipping: rem317
skipping: rem318
skipping: rem319
skipping: rem320
skipping: rem321
skipping: rem322
skipping: rem323
skipping: rem324
skipping: rem325
skipping: rem326
skipping: rem327
skipping: rem328
skipping: rem329
skipping: rem330
skipping: rem331
skipping: rem332
skipping: rem333
skipping: rem334
skipping: rem335
skipping: rem336
skipping: rem337
skipping: rem338
skipping: rem339
skipping: rem340
skipping: rem341
skipping: rem342
skipping: rem343
skipping: rem344
skipping: rem345
skipping: rem346
skipping: rem347
skipping: rem348
skipping: rem349
skipping: rem350
skipping: rem351
skipping: rem352
skipping: rem353
skipping: rem354
skipping: rem355
skipping: rem356
skipping: rem357
skipping: rem358
skipping: rem360
skipping: rem361
skipping: rem362
skipping: rem363
skipping: rem364
skipping: rem365
skipping: rem366
context {
    rounding     : 4
    precision    : 6
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem371
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem372
context {
    rounding     : 4
    precision    : 5
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem381
skipping: rem382
skipping: rem383
skipping: rem384
skipping: rem385
skipping: rem386
skipping: rem387
skipping: rem388
skipping: rem389
skipping: rem390
skipping: rem391
skipping: rem392
skipping: rem393
skipping: rem394
skipping: rem395
skipping: rem396
skipping: rem397
skipping: rem398
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem401
skipping: rem402
skipping: rem403
skipping: rem404
skipping: rem405
skipping: rem406
skipping: rem407
skipping: rem408
skipping: rem409
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: rem430
skipping: rem431
skipping: rem432
skipping: rem433
skipping: rem435
skipping: rem436
skipping: rem437
skipping: rem438
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: rem501
skipping: rem502
skipping: rem503
skipping: rem504
skipping: rem505
skipping: rem506
skipping: rem507
skipping: rem508
skipping: rem509
skipping: rem510
skipping: rem511
skipping: rem512
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: rem541
skipping: rem542
skipping: rem543
skipping: rem544
skipping: rem545
skipping: rem546
skipping: rem547
skipping: rem548
skipping: rem549
skipping: rem550
skipping: rem551
skipping: rem552
skipping: rem900
skipping: rem901
general_decimal_arithmetic/test_cases/subset_arithmetic/remainder0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: remn001
skipping: remn002
skipping: remn003
skipping: remn004
skipping: remn005
skipping: remn006
skipping: remn007
skipping: remn008
skipping: remn009
skipping: remn010
skipping: remn011
skipping: remn012
skipping: remn013
skipping: remn014
skipping: remn015
skipping: remn016
skipping: remn017
skipping: remn018
skipping: remn019
skipping: remn020
skipping: remn021
skipping: remn022
skipping: remn023
skipping: remn024
skipping: remn025
skipping: remn030
skipping: remn031
skipping: remn032
skipping: remn033
skipping: remn034
skipping: remn035
skipping: remn040
skipping: remn041
skipping: remn042
skipping: remn043
skipping: remn044
skipping: remn045
skipping: remn050
skipping: remn051
skipping: remn052
skipping: remn053
skipping: remn054
skipping: remn055
skipping: remn060
skipping: remn061
skipping: remn062
skipping: remn063
skipping: remn064
skipping: remn065
skipping: remn070
skipping: remn071
skipping: remn072
skipping: remn073
skipping: remn074
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: remn080
skipping: remn081
skipping: remn082
skipping: remn083
skipping: remn084
skipping: remn085
skipping: remn086
skipping: remn087
skipping: remn088
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: remn090
skipping: remn091
skipping: remn092
skipping: remn093
skipping: remn094
skipping: remn100
skipping: remn101
skipping: remn102
skipping: remn103
skipping: remn104
skipping: remn105
skipping: remn106
skipping: remn107
skipping: remn108
skipping: remn109
skipping: remn110
skipping: remn111
skipping: remn112
skipping: remn113
skipping: remn114
skipping: remn115
skipping: remn116
skipping: remn117
skipping: remn118
skipping: remn119
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn201
skipping: remn202
skipping: remn203
skipping: remn204
skipping: remn205
skipping: remn206
skipping: remn207
skipping: remn208
skipping: remn209
skipping: remn210
skipping: remn211
skipping: remn221
skipping: remn222
skipping: remn223
skipping: remn224
skipping: remn225
skipping: remn226
skipping: remn227
skipping: remn231
skipping: remn232
skipping: remn233
skipping: remn234
skipping: remn235
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn270
skipping: remn271
skipping: remn272
skipping: remn273
skipping: remn274
skipping: remn275
skipping: remn276
skipping: remn277
skipping: remn280
skipping: remn281
skipping: remn282
skipping: remn283
skipping: remn284
skipping: remn285
skipping: remn286
skipping: remn287
skipping: remn288
skipping: remn301
skipping: remn302
skipping: remn303
skipping: remn304
skipping: remn305
skipping: remn306
skipping: remn307
skipping: remn308
skipping: remn309
skipping: remn310
skipping: remn311
skipping: remn312
skipping: remn313
skipping: remn314
skipping: remn315
skipping: remn316
skipping: remn317
skipping: remn318
skipping: remn319
skipping: remn320
skipping: remn321
skipping: remn322
skipping: remn323
skipping: remn324
skipping: remn325
skipping: remn326
skipping: remn327
skipping: remn328
skipping: remn329
skipping: remn330
skipping: remn331
skipping: remn332
skipping: remn333
skipping: remn334
skipping: remn335
skipping: remn336
skipping: remn337
skipping: remn338
skipping: remn339
skipping: remn340
skipping: remn341
skipping: remn342
skipping: remn343
skipping: remn344
skipping: remn345
skipping: remn346
skipping: remn347
skipping: remn348
skipping: remn349
skipping: remn350
skipping: remn351
skipping: remn352
skipping: remn353
skipping: remn354
skipping: remn355
skipping: remn356
skipping: remn357
skipping: remn358
skipping: remn360
skipping: remn361
skipping: remn362
skipping: remn363
skipping: remn364
skipping: remn365
skipping: remn366
context {
    rounding     : 4
    precision    : 6
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn371
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn372
context {
    rounding     : 4
    precision    : 5
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn381
skipping: remn382
skipping: remn383
skipping: remn384
skipping: remn385
skipping: remn386
skipping: remn387
skipping: remn388
skipping: remn389
skipping: remn390
skipping: remn391
skipping: remn392
skipping: remn393
skipping: remn394
skipping: remn395
skipping: remn396
skipping: remn397
skipping: remn398
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn401
skipping: remn402
skipping: remn403
skipping: remn404
skipping: remn405
skipping: remn406
skipping: remn407
skipping: remn408
skipping: remn409
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: remn430
skipping: remn431
skipping: remn432
skipping: remn433
skipping: remn435
skipping: remn436
skipping: remn437
skipping: remn438
context {
    rounding     : 4
    precision    : 9
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: remn501
skipping: remn502
skipping: remn503
skipping: remn504
skipping: remn505
skipping: remn506
skipping: remn507
skipping: remn508
skipping: remn509
skipping: remn510
skipping: remn511
skipping: remn512
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: remn541
skipping: remn542
skipping: remn543
skipping: remn544
skipping: remn545
skipping: remn546
skipping: remn547
skipping: remn548
skipping: remn549
skipping: remn550
skipping: remn551
skipping: remn552
skipping: remn601
skipping: remn602
skipping: remn603
skipping: remn604
skipping: remn605
skipping: remn606
skipping: remn607
skipping: remn900
skipping: remn901
general_decimal_arithmetic/test_cases/subset_arithmetic/remaindernear0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: res001
skipping: res002
skipping: res003
skipping: res005
skipping: res006
skipping: res007
skipping: res008
skipping: res009
skipping: res010
skipping: res011
skipping: res012
skipping: res013
skipping: res014
skipping: res015
skipping: res021
skipping: res022
skipping: res023
skipping: res025
skipping: res026
skipping: res027
skipping: res028
skipping: res029
skipping: res030
skipping: res031
skipping: res032
skipping: res033
skipping: res034
skipping: res035
skipping: res036
skipping: res037
skipping: res038
skipping: res039
skipping: res040
skipping: res041
skipping: res042
skipping: res043
skipping: res044
skipping: res045
skipping: res046
skipping: res047
skipping: res080
skipping: res081
skipping: res082
skipping: res083
skipping: res084
skipping: res085
skipping: res086
skipping: res087
skipping: res088
skipping: res089
skipping: res090
skipping: res091
skipping: res092
skipping: res093
skipping: res094
skipping: res095
skipping: res096
skipping: res097
skipping: res098
skipping: res099
skipping: res100
skipping: res101
skipping: res102
skipping: res103
skipping: res104
skipping: res105
skipping: res106
skipping: res107
skipping: res108
skipping: res109
skipping: res110
skipping: res111
skipping: res112
skipping: res120
skipping: res121
skipping: res122
skipping: res123
skipping: res124
skipping: res125
skipping: res126
skipping: res127
skipping: res128
skipping: res129
skipping: res130
skipping: res131
skipping: res132
skipping: res133
skipping: res134
skipping: res135
skipping: res140
skipping: res141
skipping: res142
skipping: res143
skipping: res144
skipping: res145
skipping: res146
skipping: res150
skipping: res151
skipping: res152
skipping: res153
skipping: res154
skipping: res155
skipping: res201
skipping: res202
skipping: res203
skipping: res204
skipping: res205
skipping: res206
skipping: res207
skipping: res208
skipping: res209
skipping: res220
skipping: res221
skipping: res222
skipping: res223
skipping: res224
skipping: res225
skipping: res226
skipping: res227
skipping: res228
skipping: res229
skipping: res230
skipping: res231
skipping: res232
skipping: res233
skipping: res234
skipping: res235
skipping: res240
skipping: res241
skipping: res242
skipping: res243
skipping: res244
skipping: res245
skipping: res246
skipping: res247
skipping: res248
skipping: res249
skipping: res250
skipping: res251
skipping: res252
skipping: res253
skipping: res254
skipping: res255
skipping: res260
skipping: res261
skipping: res262
skipping: res263
skipping: res264
skipping: res265
skipping: res266
skipping: res267
skipping: res268
skipping: res269
skipping: res270
skipping: res271
skipping: res272
skipping: res273
skipping: res274
skipping: res275
skipping: res280
skipping: res281
skipping: res282
skipping: res283
skipping: res284
skipping: res285
skipping: res286
skipping: res287
skipping: res288
skipping: res289
skipping: res290
skipping: res291
skipping: res292
skipping: res293
skipping: res294
skipping: res295
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: res380
skipping: res381
skipping: res382
skipping: res383
skipping: res384
skipping: res385
skipping: res386
skipping: res387
skipping: res394
skipping: res395
skipping: res396
skipping: res397
skipping: res398
skipping: res399
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: res401
skipping: res403
skipping: res405
skipping: res407
skipping: res409
skipping: res411
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: res441
skipping: res443
skipping: res445
skipping: res447
skipping: res449
skipping: res451
skipping: res900
skipping: res901
general_decimal_arithmetic/test_cases/subset_arithmetic/rescale0.decTest
context {
    rounding     : 
    precision    : 5
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 
    precision    : 5
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 
    precision    : 5
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 1
    precision    : 5
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: samq001
skipping: samq002
skipping: samq003
skipping: samq004
skipping: samq011
skipping: samq012
skipping: samq013
skipping: samq014
skipping: samq015
skipping: samq016
skipping: samq017
skipping: samq018
skipping: samq019
skipping: samq020
skipping: samq021
skipping: samq0413
skipping: samq0414
skipping: samq0415
skipping: samq0420
skipping: samq0422
skipping: samq0423
skipping: samq0424
skipping: samq0513
skipping: samq0514
skipping: samq0515
skipping: samq0520
skipping: samq0522
skipping: samq0523
skipping: samq0524
skipping: samq0613
skipping: samq0614
skipping: samq0615
skipping: samq0620
skipping: samq0622
skipping: samq0623
skipping: samq0624
skipping: samq1213
skipping: samq1214
skipping: samq1215
skipping: samq1220
skipping: samq1222
skipping: samq1223
skipping: samq1224
skipping: samq1413
skipping: samq1414
skipping: samq1415
skipping: samq1420
skipping: samq1422
skipping: samq1423
skipping: samq1424
skipping: samq1513
skipping: samq1514
skipping: samq1515
skipping: samq1520
skipping: samq1522
skipping: samq1523
skipping: samq1524
skipping: samq1613
skipping: samq1614
skipping: samq1615
skipping: samq1620
skipping: samq1622
skipping: samq1623
skipping: samq1624
general_decimal_arithmetic/test_cases/subset_arithmetic/samequantum0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx001
skipping: sqtx002
skipping: sqtx003
skipping: sqtx004
skipping: sqtx005
skipping: sqtx006
skipping: sqtx007
skipping: sqtx008
skipping: sqtx009
skipping: sqtx010
skipping: sqtx011
skipping: sqtx012
skipping: sqtx013
skipping: sqtx014
skipping: sqtx015
skipping: sqtx016
skipping: sqtx017
skipping: sqtx018
skipping: sqtx019
skipping: sqtx020
skipping: sqtx021
skipping: sqtx022
skipping: sqtx023
skipping: sqtx024
skipping: sqtx030
skipping: sqtx031
skipping: sqtx032
skipping: sqtx033
skipping: sqtx034
skipping: sqtx035
skipping: sqtx036
skipping: sqtx037
skipping: sqtx038
skipping: sqtx039
skipping: sqtx041
skipping: sqtx042
skipping: sqtx043
skipping: sqtx044
skipping: sqtx045
skipping: sqtx046
skipping: sqtx047
skipping: sqtx048
skipping: sqtx049
skipping: sqtx050
skipping: sqtx051
skipping: sqtx052
skipping: sqtx053
skipping: sqtx054
skipping: sqtx055
skipping: sqtx056
skipping: sqtx060
skipping: sqtx061
skipping: sqtx062
skipping: sqtx063
skipping: sqtx064
skipping: sqtx065
skipping: sqtx066
skipping: sqtx067
skipping: sqtx068
skipping: sqtx069
skipping: sqtx070
skipping: sqtx071
skipping: sqtx080
skipping: sqtx081
skipping: sqtx082
skipping: sqtx083
skipping: sqtx084
skipping: sqtx085
skipping: sqtx086
skipping: sqtx087
skipping: sqtx088
skipping: sqtx089
skipping: sqtx090
skipping: sqtx091
skipping: sqtx092
skipping: sqtx093
skipping: sqtx094
skipping: sqtx095
skipping: sqtx100
skipping: sqtx101
skipping: sqtx102
skipping: sqtx103
skipping: sqtx104
skipping: sqtx105
skipping: sqtx106
skipping: sqtx107
skipping: sqtx108
skipping: sqtx109
skipping: sqtx110
skipping: sqtx111
skipping: sqtx112
skipping: sqtx113
skipping: sqtx114
skipping: sqtx115
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 1
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx1201
skipping: sqtx1202
skipping: sqtx1203
skipping: sqtx1204
skipping: sqtx1205
skipping: sqtx1206
skipping: sqtx1207
skipping: sqtx1208
skipping: sqtx1209
skipping: sqtx1210
skipping: sqtx1211
skipping: sqtx1212
skipping: sqtx1213
skipping: sqtx1214
skipping: sqtx1215
skipping: sqtx1216
skipping: sqtx1217
skipping: sqtx1218
skipping: sqtx1219
skipping: sqtx1220
skipping: sqtx1221
skipping: sqtx1222
skipping: sqtx1223
skipping: sqtx1224
skipping: sqtx1225
skipping: sqtx1226
skipping: sqtx1227
skipping: sqtx1228
skipping: sqtx1229
skipping: sqtx1230
skipping: sqtx1231
skipping: sqtx1232
skipping: sqtx1233
skipping: sqtx1234
skipping: sqtx1235
skipping: sqtx1236
skipping: sqtx1237
skipping: sqtx1238
skipping: sqtx1239
skipping: sqtx1240
skipping: sqtx1241
skipping: sqtx1242
skipping: sqtx1243
skipping: sqtx1244
skipping: sqtx1245
skipping: sqtx1246
skipping: sqtx1247
skipping: sqtx1248
skipping: sqtx1249
skipping: sqtx1250
skipping: sqtx1251
skipping: sqtx1252
skipping: sqtx1253
skipping: sqtx1254
skipping: sqtx1255
skipping: sqtx1256
skipping: sqtx1257
skipping: sqtx1258
skipping: sqtx1259
skipping: sqtx1260
skipping: sqtx1261
skipping: sqtx1262
skipping: sqtx1263
skipping: sqtx1264
skipping: sqtx1265
skipping: sqtx1266
skipping: sqtx1267
skipping: sqtx1268
skipping: sqtx1269
skipping: sqtx1270
skipping: sqtx1271
skipping: sqtx1272
context {
    rounding     : 0
    precision    : 1
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 1
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 1
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 2
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx2201
skipping: sqtx2202
skipping: sqtx2203
skipping: sqtx2204
skipping: sqtx2205
skipping: sqtx2206
skipping: sqtx2207
skipping: sqtx2208
skipping: sqtx2209
skipping: sqtx2210
skipping: sqtx2211
skipping: sqtx2212
skipping: sqtx2213
skipping: sqtx2214
skipping: sqtx2215
skipping: sqtx2216
skipping: sqtx2217
skipping: sqtx2218
skipping: sqtx2219
skipping: sqtx2220
skipping: sqtx2221
skipping: sqtx2222
skipping: sqtx2223
skipping: sqtx2224
skipping: sqtx2225
skipping: sqtx2226
skipping: sqtx2227
skipping: sqtx2228
skipping: sqtx2229
skipping: sqtx2230
skipping: sqtx2231
skipping: sqtx2232
skipping: sqtx2233
skipping: sqtx2234
skipping: sqtx2235
skipping: sqtx2236
skipping: sqtx2237
skipping: sqtx2238
skipping: sqtx2239
skipping: sqtx2240
skipping: sqtx2241
skipping: sqtx2242
skipping: sqtx2243
skipping: sqtx2244
skipping: sqtx2245
skipping: sqtx2246
skipping: sqtx2247
skipping: sqtx2248
skipping: sqtx2249
skipping: sqtx2250
skipping: sqtx2251
skipping: sqtx2252
skipping: sqtx2253
skipping: sqtx2254
skipping: sqtx2255
skipping: sqtx2256
skipping: sqtx2257
skipping: sqtx2258
skipping: sqtx2259
skipping: sqtx2260
skipping: sqtx2261
skipping: sqtx2262
skipping: sqtx2263
skipping: sqtx2264
skipping: sqtx2265
skipping: sqtx2266
skipping: sqtx2267
skipping: sqtx2268
skipping: sqtx2269
skipping: sqtx2270
skipping: sqtx2271
skipping: sqtx2272
skipping: sqtx2273
skipping: sqtx2274
skipping: sqtx2275
skipping: sqtx2276
skipping: sqtx2277
skipping: sqtx2278
skipping: sqtx2279
skipping: sqtx2280
skipping: sqtx2281
skipping: sqtx2282
skipping: sqtx2283
skipping: sqtx2284
skipping: sqtx2285
skipping: sqtx2286
skipping: sqtx2287
skipping: sqtx2288
skipping: sqtx2289
skipping: sqtx2290
skipping: sqtx2291
skipping: sqtx2292
skipping: sqtx2293
skipping: sqtx2294
skipping: sqtx2295
skipping: sqtx2296
skipping: sqtx2297
skipping: sqtx2298
skipping: sqtx2299
skipping: sqtx2300
skipping: sqtx2301
skipping: sqtx2302
skipping: sqtx2303
skipping: sqtx2304
skipping: sqtx2305
skipping: sqtx2306
skipping: sqtx2307
skipping: sqtx2308
skipping: sqtx2309
skipping: sqtx2310
skipping: sqtx2311
skipping: sqtx2312
skipping: sqtx2313
skipping: sqtx2314
skipping: sqtx2315
skipping: sqtx2316
skipping: sqtx2317
skipping: sqtx2318
skipping: sqtx2319
skipping: sqtx2320
skipping: sqtx2321
skipping: sqtx2322
skipping: sqtx2323
skipping: sqtx2324
skipping: sqtx2325
skipping: sqtx2326
skipping: sqtx2327
skipping: sqtx2328
skipping: sqtx2329
skipping: sqtx2330
skipping: sqtx2331
skipping: sqtx2332
skipping: sqtx2333
skipping: sqtx2334
skipping: sqtx2335
skipping: sqtx2336
skipping: sqtx2337
skipping: sqtx2338
skipping: sqtx2339
skipping: sqtx2340
skipping: sqtx2341
skipping: sqtx2342
skipping: sqtx2343
skipping: sqtx2344
skipping: sqtx2345
skipping: sqtx2346
skipping: sqtx2347
skipping: sqtx2348
skipping: sqtx2349
skipping: sqtx2350
skipping: sqtx2351
skipping: sqtx2352
skipping: sqtx2353
skipping: sqtx2354
skipping: sqtx2355
skipping: sqtx2356
skipping: sqtx2357
skipping: sqtx2358
skipping: sqtx2359
skipping: sqtx2360
skipping: sqtx2361
skipping: sqtx2362
skipping: sqtx2363
skipping: sqtx2364
skipping: sqtx2365
skipping: sqtx2366
skipping: sqtx2367
skipping: sqtx2368
skipping: sqtx2369
skipping: sqtx2370
skipping: sqtx2371
skipping: sqtx2372
skipping: sqtx2373
skipping: sqtx2374
skipping: sqtx2375
skipping: sqtx2376
skipping: sqtx2377
skipping: sqtx2378
skipping: sqtx2379
skipping: sqtx2380
skipping: sqtx2381
skipping: sqtx2382
skipping: sqtx2383
skipping: sqtx2384
skipping: sqtx2385
skipping: sqtx2386
skipping: sqtx2387
skipping: sqtx2388
skipping: sqtx2389
skipping: sqtx2390
skipping: sqtx2391
skipping: sqtx2392
skipping: sqtx2393
skipping: sqtx2394
skipping: sqtx2395
skipping: sqtx2396
skipping: sqtx2397
skipping: sqtx2398
skipping: sqtx2399
skipping: sqtx2400
skipping: sqtx2401
skipping: sqtx2402
skipping: sqtx2403
skipping: sqtx2404
skipping: sqtx2405
skipping: sqtx2406
skipping: sqtx2407
skipping: sqtx2408
skipping: sqtx2409
skipping: sqtx2410
skipping: sqtx2411
skipping: sqtx2412
skipping: sqtx2413
skipping: sqtx2414
skipping: sqtx2415
skipping: sqtx2416
skipping: sqtx2417
skipping: sqtx2418
skipping: sqtx2419
skipping: sqtx2420
skipping: sqtx2421
skipping: sqtx2422
skipping: sqtx2423
skipping: sqtx2424
skipping: sqtx2425
skipping: sqtx2426
skipping: sqtx2427
skipping: sqtx2428
skipping: sqtx2429
skipping: sqtx2430
skipping: sqtx2431
skipping: sqtx2432
skipping: sqtx2433
skipping: sqtx2434
skipping: sqtx2435
skipping: sqtx2436
skipping: sqtx2437
skipping: sqtx2438
skipping: sqtx2439
skipping: sqtx2440
skipping: sqtx2441
skipping: sqtx2442
skipping: sqtx2443
skipping: sqtx2444
skipping: sqtx2445
skipping: sqtx2446
skipping: sqtx2447
skipping: sqtx2448
skipping: sqtx2449
skipping: sqtx2450
skipping: sqtx2451
skipping: sqtx2452
skipping: sqtx2453
skipping: sqtx2454
skipping: sqtx2455
skipping: sqtx2456
skipping: sqtx2457
skipping: sqtx2458
skipping: sqtx2459
skipping: sqtx2460
skipping: sqtx2461
skipping: sqtx2462
skipping: sqtx2463
skipping: sqtx2464
skipping: sqtx2465
skipping: sqtx2466
skipping: sqtx2467
skipping: sqtx2468
skipping: sqtx2469
skipping: sqtx2470
skipping: sqtx2471
skipping: sqtx2472
skipping: sqtx2473
skipping: sqtx2474
skipping: sqtx2475
skipping: sqtx2476
skipping: sqtx2477
skipping: sqtx2478
skipping: sqtx2479
skipping: sqtx2480
skipping: sqtx2481
skipping: sqtx2482
skipping: sqtx2483
skipping: sqtx2484
skipping: sqtx2485
skipping: sqtx2486
skipping: sqtx2487
skipping: sqtx2488
skipping: sqtx2489
skipping: sqtx2490
skipping: sqtx2491
skipping: sqtx2492
skipping: sqtx2493
skipping: sqtx2494
skipping: sqtx2495
skipping: sqtx2496
skipping: sqtx2497
skipping: sqtx2498
skipping: sqtx2499
skipping: sqtx2500
skipping: sqtx2501
skipping: sqtx2502
skipping: sqtx2503
skipping: sqtx2504
skipping: sqtx2505
skipping: sqtx2506
skipping: sqtx2507
skipping: sqtx2508
skipping: sqtx2509
skipping: sqtx2510
skipping: sqtx2511
skipping: sqtx2512
skipping: sqtx2513
skipping: sqtx2514
skipping: sqtx2515
skipping: sqtx2516
skipping: sqtx2517
skipping: sqtx2518
skipping: sqtx2519
skipping: sqtx2520
skipping: sqtx2521
skipping: sqtx2522
skipping: sqtx2523
skipping: sqtx2524
skipping: sqtx2525
skipping: sqtx2526
skipping: sqtx2527
skipping: sqtx2528
skipping: sqtx2529
skipping: sqtx2530
skipping: sqtx2531
skipping: sqtx2532
skipping: sqtx2533
skipping: sqtx2534
skipping: sqtx2535
skipping: sqtx2536
skipping: sqtx2537
skipping: sqtx2538
skipping: sqtx2539
skipping: sqtx2540
skipping: sqtx2541
skipping: sqtx2542
skipping: sqtx2543
skipping: sqtx2544
skipping: sqtx2545
skipping: sqtx2546
skipping: sqtx2547
skipping: sqtx2548
skipping: sqtx2549
skipping: sqtx2550
skipping: sqtx2551
skipping: sqtx2552
skipping: sqtx2553
skipping: sqtx2554
skipping: sqtx2555
skipping: sqtx2556
skipping: sqtx2557
skipping: sqtx2558
skipping: sqtx2559
skipping: sqtx2560
skipping: sqtx2561
skipping: sqtx2562
skipping: sqtx2563
skipping: sqtx2564
skipping: sqtx2565
skipping: sqtx2566
skipping: sqtx2567
skipping: sqtx2568
skipping: sqtx2569
skipping: sqtx2570
skipping: sqtx2571
skipping: sqtx2572
skipping: sqtx2573
skipping: sqtx2574
skipping: sqtx2575
skipping: sqtx2576
skipping: sqtx2577
skipping: sqtx2578
skipping: sqtx2579
skipping: sqtx2580
skipping: sqtx2581
skipping: sqtx2582
skipping: sqtx2583
skipping: sqtx2584
skipping: sqtx2585
skipping: sqtx2586
skipping: sqtx2587
skipping: sqtx2588
skipping: sqtx2589
skipping: sqtx2590
skipping: sqtx2591
skipping: sqtx2592
skipping: sqtx2593
skipping: sqtx2594
skipping: sqtx2595
skipping: sqtx2596
skipping: sqtx2597
skipping: sqtx2598
skipping: sqtx2599
skipping: sqtx2600
skipping: sqtx2601
skipping: sqtx2602
skipping: sqtx2603
skipping: sqtx2604
skipping: sqtx2605
skipping: sqtx2606
skipping: sqtx2607
skipping: sqtx2608
skipping: sqtx2609
skipping: sqtx2610
skipping: sqtx2611
skipping: sqtx2612
skipping: sqtx2613
skipping: sqtx2614
skipping: sqtx2615
skipping: sqtx2616
skipping: sqtx2617
skipping: sqtx2618
skipping: sqtx2619
skipping: sqtx2620
skipping: sqtx2621
skipping: sqtx2622
skipping: sqtx2623
skipping: sqtx2624
skipping: sqtx2625
skipping: sqtx2626
skipping: sqtx2627
skipping: sqtx2628
skipping: sqtx2629
skipping: sqtx2630
skipping: sqtx2631
skipping: sqtx2632
skipping: sqtx2633
skipping: sqtx2634
skipping: sqtx2635
skipping: sqtx2636
skipping: sqtx2637
skipping: sqtx2638
skipping: sqtx2639
skipping: sqtx2640
skipping: sqtx2641
skipping: sqtx2642
skipping: sqtx2643
skipping: sqtx2644
skipping: sqtx2645
skipping: sqtx2646
skipping: sqtx2647
skipping: sqtx2648
skipping: sqtx2649
skipping: sqtx2650
skipping: sqtx2651
skipping: sqtx2652
skipping: sqtx2653
skipping: sqtx2654
skipping: sqtx2655
skipping: sqtx2656
skipping: sqtx2657
skipping: sqtx2658
skipping: sqtx2659
skipping: sqtx2660
skipping: sqtx2661
skipping: sqtx2662
skipping: sqtx2663
skipping: sqtx2664
skipping: sqtx2665
skipping: sqtx2666
skipping: sqtx2667
skipping: sqtx2668
skipping: sqtx2669
skipping: sqtx2670
skipping: sqtx2671
skipping: sqtx2672
skipping: sqtx2673
skipping: sqtx2674
skipping: sqtx2675
skipping: sqtx2676
skipping: sqtx2677
skipping: sqtx2678
skipping: sqtx2679
skipping: sqtx2680
skipping: sqtx2681
skipping: sqtx2682
skipping: sqtx2683
skipping: sqtx2684
skipping: sqtx2685
skipping: sqtx2686
skipping: sqtx2687
skipping: sqtx2688
skipping: sqtx2689
skipping: sqtx2690
skipping: sqtx2691
skipping: sqtx2692
skipping: sqtx2693
skipping: sqtx2694
skipping: sqtx2695
skipping: sqtx2696
skipping: sqtx2697
skipping: sqtx2698
skipping: sqtx2699
skipping: sqtx2700
skipping: sqtx2701
skipping: sqtx2702
skipping: sqtx2703
skipping: sqtx2704
skipping: sqtx2705
skipping: sqtx2706
skipping: sqtx2707
skipping: sqtx2708
skipping: sqtx2709
skipping: sqtx2710
skipping: sqtx2711
skipping: sqtx2712
skipping: sqtx2713
skipping: sqtx2714
skipping: sqtx2715
skipping: sqtx2716
skipping: sqtx2717
skipping: sqtx2718
skipping: sqtx2719
skipping: sqtx2720
skipping: sqtx2721
skipping: sqtx2722
skipping: sqtx2723
skipping: sqtx2724
skipping: sqtx2725
skipping: sqtx2726
skipping: sqtx2727
skipping: sqtx2728
skipping: sqtx2729
skipping: sqtx2730
skipping: sqtx2731
skipping: sqtx2732
skipping: sqtx2733
skipping: sqtx2734
skipping: sqtx2735
skipping: sqtx2736
skipping: sqtx2737
skipping: sqtx2738
skipping: sqtx2739
skipping: sqtx2740
skipping: sqtx2741
skipping: sqtx2742
skipping: sqtx2743
skipping: sqtx2744
skipping: sqtx2745
skipping: sqtx2746
skipping: sqtx2747
skipping: sqtx2748
skipping: sqtx2749
skipping: sqtx2750
skipping: sqtx2751
skipping: sqtx2752
skipping: sqtx2753
skipping: sqtx2754
skipping: sqtx2755
skipping: sqtx2756
skipping: sqtx2757
skipping: sqtx2758
skipping: sqtx2759
skipping: sqtx2760
skipping: sqtx2761
skipping: sqtx2762
skipping: sqtx2763
skipping: sqtx2764
skipping: sqtx2765
skipping: sqtx2766
skipping: sqtx2767
skipping: sqtx2768
skipping: sqtx2769
skipping: sqtx2770
skipping: sqtx2771
skipping: sqtx2772
skipping: sqtx2773
skipping: sqtx2774
skipping: sqtx2775
skipping: sqtx2776
skipping: sqtx2777
skipping: sqtx2778
skipping: sqtx2779
skipping: sqtx2780
skipping: sqtx2781
skipping: sqtx2782
skipping: sqtx2783
skipping: sqtx2784
skipping: sqtx2785
skipping: sqtx2786
skipping: sqtx2787
skipping: sqtx2788
skipping: sqtx2789
skipping: sqtx2790
skipping: sqtx2791
skipping: sqtx2792
skipping: sqtx2793
skipping: sqtx2794
skipping: sqtx2795
skipping: sqtx2796
skipping: sqtx2797
skipping: sqtx2798
skipping: sqtx2799
skipping: sqtx2800
skipping: sqtx2801
skipping: sqtx2802
skipping: sqtx2803
skipping: sqtx2804
skipping: sqtx2805
skipping: sqtx2806
skipping: sqtx2807
skipping: sqtx2808
skipping: sqtx2809
skipping: sqtx2810
skipping: sqtx2811
skipping: sqtx2812
skipping: sqtx2813
skipping: sqtx2814
skipping: sqtx2815
skipping: sqtx2816
skipping: sqtx2817
skipping: sqtx2818
skipping: sqtx2819
skipping: sqtx2820
skipping: sqtx2821
skipping: sqtx2822
skipping: sqtx2823
skipping: sqtx2824
skipping: sqtx2825
skipping: sqtx2826
skipping: sqtx2827
skipping: sqtx2828
skipping: sqtx2829
skipping: sqtx2830
skipping: sqtx2831
skipping: sqtx2832
skipping: sqtx2833
skipping: sqtx2834
skipping: sqtx2835
skipping: sqtx2836
skipping: sqtx2837
skipping: sqtx2838
skipping: sqtx2839
skipping: sqtx2840
skipping: sqtx2841
skipping: sqtx2842
skipping: sqtx2843
skipping: sqtx2844
skipping: sqtx2845
skipping: sqtx2846
skipping: sqtx2847
skipping: sqtx2848
skipping: sqtx2849
skipping: sqtx2850
skipping: sqtx2851
skipping: sqtx2852
skipping: sqtx2853
skipping: sqtx2854
skipping: sqtx2855
skipping: sqtx2856
skipping: sqtx2857
skipping: sqtx2858
skipping: sqtx2859
skipping: sqtx2860
skipping: sqtx2861
skipping: sqtx2862
skipping: sqtx2863
skipping: sqtx2864
skipping: sqtx2865
skipping: sqtx2866
skipping: sqtx2867
skipping: sqtx2868
skipping: sqtx2869
skipping: sqtx2870
skipping: sqtx2871
skipping: sqtx2872
skipping: sqtx2873
skipping: sqtx2874
skipping: sqtx2875
skipping: sqtx2876
skipping: sqtx2877
skipping: sqtx2878
skipping: sqtx2879
skipping: sqtx2880
skipping: sqtx2881
skipping: sqtx2882
skipping: sqtx2883
skipping: sqtx2884
skipping: sqtx2885
skipping: sqtx2886
skipping: sqtx2887
skipping: sqtx2888
skipping: sqtx2889
skipping: sqtx2890
skipping: sqtx2891
skipping: sqtx2892
skipping: sqtx2893
skipping: sqtx2894
skipping: sqtx2895
skipping: sqtx2896
skipping: sqtx2897
skipping: sqtx2898
skipping: sqtx2899
skipping: sqtx2900
skipping: sqtx2901
skipping: sqtx2902
skipping: sqtx2903
skipping: sqtx2904
skipping: sqtx2905
skipping: sqtx2906
skipping: sqtx2907
skipping: sqtx2908
skipping: sqtx2909
skipping: sqtx2910
skipping: sqtx2911
skipping: sqtx2912
skipping: sqtx2913
skipping: sqtx2914
skipping: sqtx2915
skipping: sqtx2916
skipping: sqtx2917
skipping: sqtx2918
skipping: sqtx2919
skipping: sqtx2920
skipping: sqtx2921
skipping: sqtx2922
skipping: sqtx2923
skipping: sqtx2924
skipping: sqtx2925
skipping: sqtx2926
skipping: sqtx2927
skipping: sqtx2928
skipping: sqtx2929
skipping: sqtx2930
skipping: sqtx2931
skipping: sqtx2932
skipping: sqtx2933
skipping: sqtx2934
skipping: sqtx2935
skipping: sqtx2936
skipping: sqtx2937
skipping: sqtx2938
skipping: sqtx2939
skipping: sqtx2940
skipping: sqtx2941
skipping: sqtx2942
skipping: sqtx2943
skipping: sqtx2944
skipping: sqtx2945
skipping: sqtx2946
skipping: sqtx2947
skipping: sqtx2948
skipping: sqtx2949
skipping: sqtx2950
skipping: sqtx2951
skipping: sqtx2952
skipping: sqtx2953
skipping: sqtx2954
skipping: sqtx2955
skipping: sqtx2956
skipping: sqtx2957
skipping: sqtx2958
skipping: sqtx2959
skipping: sqtx2960
skipping: sqtx2961
skipping: sqtx2962
skipping: sqtx2963
skipping: sqtx2964
skipping: sqtx2965
skipping: sqtx2966
skipping: sqtx2967
skipping: sqtx2968
skipping: sqtx2969
skipping: sqtx2970
skipping: sqtx2971
skipping: sqtx2972
skipping: sqtx2973
skipping: sqtx2974
skipping: sqtx2975
skipping: sqtx2976
skipping: sqtx2977
skipping: sqtx2978
skipping: sqtx2979
skipping: sqtx2980
skipping: sqtx2981
skipping: sqtx2982
skipping: sqtx2983
skipping: sqtx2984
skipping: sqtx2985
skipping: sqtx2986
skipping: sqtx2987
skipping: sqtx2988
skipping: sqtx2989
skipping: sqtx2990
skipping: sqtx2991
skipping: sqtx2992
context {
    rounding     : 0
    precision    : 2
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 2
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 2
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx3001
skipping: sqtx3002
skipping: sqtx3003
skipping: sqtx3004
skipping: sqtx3005
skipping: sqtx3006
skipping: sqtx3007
skipping: sqtx3008
skipping: sqtx3009
skipping: sqtx3010
skipping: sqtx3011
skipping: sqtx3012
skipping: sqtx3013
skipping: sqtx3014
skipping: sqtx3015
skipping: sqtx3016
skipping: sqtx3017
skipping: sqtx3018
skipping: sqtx3019
skipping: sqtx3020
skipping: sqtx3021
skipping: sqtx3022
skipping: sqtx3023
skipping: sqtx3024
skipping: sqtx3025
skipping: sqtx3026
skipping: sqtx3027
skipping: sqtx3028
skipping: sqtx3029
skipping: sqtx3030
skipping: sqtx3031
skipping: sqtx3032
skipping: sqtx3033
skipping: sqtx3034
skipping: sqtx3035
skipping: sqtx3036
skipping: sqtx3037
skipping: sqtx3038
skipping: sqtx3039
skipping: sqtx3040
skipping: sqtx3041
skipping: sqtx3042
skipping: sqtx3043
skipping: sqtx3044
skipping: sqtx3045
skipping: sqtx3046
skipping: sqtx3047
skipping: sqtx3048
skipping: sqtx3049
skipping: sqtx3050
skipping: sqtx3051
skipping: sqtx3052
skipping: sqtx3053
skipping: sqtx3054
skipping: sqtx3055
skipping: sqtx3056
skipping: sqtx3057
skipping: sqtx3058
skipping: sqtx3059
skipping: sqtx3060
skipping: sqtx3061
skipping: sqtx3062
skipping: sqtx3063
skipping: sqtx3064
skipping: sqtx3065
skipping: sqtx3066
skipping: sqtx3067
skipping: sqtx3068
skipping: sqtx3069
skipping: sqtx3070
skipping: sqtx3071
skipping: sqtx3072
skipping: sqtx3073
skipping: sqtx3074
skipping: sqtx3075
skipping: sqtx3076
skipping: sqtx3077
skipping: sqtx3078
skipping: sqtx3079
skipping: sqtx3080
skipping: sqtx3081
skipping: sqtx3082
skipping: sqtx3083
skipping: sqtx3084
skipping: sqtx3085
skipping: sqtx3086
skipping: sqtx3087
skipping: sqtx3088
skipping: sqtx3089
skipping: sqtx3090
skipping: sqtx3091
skipping: sqtx3092
skipping: sqtx3093
skipping: sqtx3094
skipping: sqtx3095
skipping: sqtx3096
skipping: sqtx3097
skipping: sqtx3098
skipping: sqtx3099
skipping: sqtx3100
skipping: sqtx3101
skipping: sqtx3102
skipping: sqtx3103
skipping: sqtx3104
skipping: sqtx3105
skipping: sqtx3106
skipping: sqtx3107
skipping: sqtx3108
skipping: sqtx3109
skipping: sqtx3110
skipping: sqtx3111
skipping: sqtx3112
skipping: sqtx3113
skipping: sqtx3114
skipping: sqtx3115
skipping: sqtx3116
skipping: sqtx3117
skipping: sqtx3118
skipping: sqtx3119
skipping: sqtx3120
skipping: sqtx3121
skipping: sqtx3122
skipping: sqtx3123
skipping: sqtx3124
skipping: sqtx3125
skipping: sqtx3126
skipping: sqtx3127
skipping: sqtx3128
skipping: sqtx3129
skipping: sqtx3130
skipping: sqtx3131
skipping: sqtx3132
skipping: sqtx3133
skipping: sqtx3134
skipping: sqtx3135
skipping: sqtx3136
skipping: sqtx3137
skipping: sqtx3138
skipping: sqtx3139
skipping: sqtx3140
skipping: sqtx3141
skipping: sqtx3142
skipping: sqtx3143
skipping: sqtx3144
skipping: sqtx3145
skipping: sqtx3146
skipping: sqtx3147
skipping: sqtx3148
skipping: sqtx3149
skipping: sqtx3150
skipping: sqtx3151
skipping: sqtx3152
skipping: sqtx3153
skipping: sqtx3154
skipping: sqtx3155
skipping: sqtx3156
skipping: sqtx3157
skipping: sqtx3158
skipping: sqtx3159
skipping: sqtx3160
skipping: sqtx3161
skipping: sqtx3162
skipping: sqtx3163
skipping: sqtx3164
skipping: sqtx3165
skipping: sqtx3166
skipping: sqtx3167
skipping: sqtx3168
skipping: sqtx3169
skipping: sqtx3170
skipping: sqtx3171
skipping: sqtx3172
skipping: sqtx3173
skipping: sqtx3174
skipping: sqtx3175
skipping: sqtx3176
skipping: sqtx3177
skipping: sqtx3178
skipping: sqtx3179
skipping: sqtx3180
skipping: sqtx3181
skipping: sqtx3182
skipping: sqtx3183
skipping: sqtx3184
skipping: sqtx3185
skipping: sqtx3186
skipping: sqtx3187
skipping: sqtx3188
skipping: sqtx3189
skipping: sqtx3190
skipping: sqtx3191
skipping: sqtx3192
skipping: sqtx3193
skipping: sqtx3194
skipping: sqtx3195
skipping: sqtx3196
skipping: sqtx3197
skipping: sqtx3198
skipping: sqtx3199
skipping: sqtx3200
skipping: sqtx3201
skipping: sqtx3202
skipping: sqtx3203
skipping: sqtx3204
skipping: sqtx3205
skipping: sqtx3206
skipping: sqtx3207
skipping: sqtx3208
skipping: sqtx3209
skipping: sqtx3210
skipping: sqtx3211
skipping: sqtx3212
skipping: sqtx3213
skipping: sqtx3214
skipping: sqtx3215
skipping: sqtx3216
skipping: sqtx3217
skipping: sqtx3218
skipping: sqtx3219
skipping: sqtx3220
skipping: sqtx3221
skipping: sqtx3222
skipping: sqtx3223
skipping: sqtx3224
skipping: sqtx3225
skipping: sqtx3226
skipping: sqtx3227
skipping: sqtx3228
skipping: sqtx3229
skipping: sqtx3230
skipping: sqtx3231
skipping: sqtx3232
skipping: sqtx3233
skipping: sqtx3234
skipping: sqtx3235
skipping: sqtx3236
skipping: sqtx3237
skipping: sqtx3238
skipping: sqtx3239
skipping: sqtx3240
skipping: sqtx3241
skipping: sqtx3242
skipping: sqtx3243
skipping: sqtx3244
skipping: sqtx3245
skipping: sqtx3246
skipping: sqtx3247
skipping: sqtx3248
skipping: sqtx3249
skipping: sqtx3250
skipping: sqtx3251
skipping: sqtx3252
skipping: sqtx3253
skipping: sqtx3254
skipping: sqtx3255
skipping: sqtx3256
skipping: sqtx3257
skipping: sqtx3258
skipping: sqtx3259
skipping: sqtx3260
skipping: sqtx3261
skipping: sqtx3262
skipping: sqtx3263
skipping: sqtx3264
skipping: sqtx3265
skipping: sqtx3266
skipping: sqtx3267
skipping: sqtx3268
skipping: sqtx3269
skipping: sqtx3270
skipping: sqtx3271
skipping: sqtx3272
skipping: sqtx3273
skipping: sqtx3274
skipping: sqtx3275
skipping: sqtx3276
skipping: sqtx3277
skipping: sqtx3278
skipping: sqtx3279
skipping: sqtx3280
skipping: sqtx3281
skipping: sqtx3282
skipping: sqtx3283
skipping: sqtx3284
skipping: sqtx3285
skipping: sqtx3286
skipping: sqtx3287
skipping: sqtx3288
skipping: sqtx3289
skipping: sqtx3290
skipping: sqtx3291
skipping: sqtx3292
skipping: sqtx3293
skipping: sqtx3294
skipping: sqtx3295
skipping: sqtx3296
skipping: sqtx3297
skipping: sqtx3298
skipping: sqtx3299
skipping: sqtx3300
skipping: sqtx3301
skipping: sqtx3302
skipping: sqtx3303
skipping: sqtx3304
skipping: sqtx3305
skipping: sqtx3306
skipping: sqtx3307
skipping: sqtx3308
skipping: sqtx3309
skipping: sqtx3310
skipping: sqtx3311
skipping: sqtx3312
skipping: sqtx3313
skipping: sqtx3314
skipping: sqtx3315
skipping: sqtx3316
skipping: sqtx3317
skipping: sqtx3318
skipping: sqtx3319
skipping: sqtx3320
skipping: sqtx3321
skipping: sqtx3322
skipping: sqtx3323
skipping: sqtx3324
skipping: sqtx3325
skipping: sqtx3326
skipping: sqtx3327
skipping: sqtx3328
skipping: sqtx3329
skipping: sqtx3330
skipping: sqtx3331
skipping: sqtx3332
skipping: sqtx3333
skipping: sqtx3334
skipping: sqtx3335
skipping: sqtx3336
skipping: sqtx3337
skipping: sqtx3338
skipping: sqtx3339
skipping: sqtx3340
skipping: sqtx3341
skipping: sqtx3342
skipping: sqtx3343
skipping: sqtx3344
skipping: sqtx3345
skipping: sqtx3346
skipping: sqtx3347
skipping: sqtx3348
skipping: sqtx3349
skipping: sqtx3350
skipping: sqtx3351
skipping: sqtx3352
skipping: sqtx3353
skipping: sqtx3354
skipping: sqtx3355
skipping: sqtx3356
skipping: sqtx3357
skipping: sqtx3358
skipping: sqtx3359
skipping: sqtx3360
skipping: sqtx3361
skipping: sqtx3362
skipping: sqtx3363
skipping: sqtx3364
skipping: sqtx3365
skipping: sqtx3366
skipping: sqtx3367
skipping: sqtx3368
skipping: sqtx3369
skipping: sqtx3370
skipping: sqtx3371
skipping: sqtx3372
skipping: sqtx3373
skipping: sqtx3374
skipping: sqtx3375
skipping: sqtx3376
skipping: sqtx3377
skipping: sqtx3378
skipping: sqtx3379
skipping: sqtx3380
skipping: sqtx3381
skipping: sqtx3382
skipping: sqtx3383
skipping: sqtx3384
skipping: sqtx3385
skipping: sqtx3386
skipping: sqtx3387
skipping: sqtx3388
skipping: sqtx3389
skipping: sqtx3390
skipping: sqtx3391
skipping: sqtx3392
skipping: sqtx3393
skipping: sqtx3394
skipping: sqtx3395
skipping: sqtx3396
skipping: sqtx3397
skipping: sqtx3398
skipping: sqtx3399
skipping: sqtx3400
skipping: sqtx3401
skipping: sqtx3402
skipping: sqtx3403
skipping: sqtx3404
skipping: sqtx3405
skipping: sqtx3406
skipping: sqtx3407
skipping: sqtx3408
skipping: sqtx3409
skipping: sqtx3410
skipping: sqtx3411
skipping: sqtx3412
skipping: sqtx3413
skipping: sqtx3414
skipping: sqtx3415
skipping: sqtx3416
skipping: sqtx3417
skipping: sqtx3418
skipping: sqtx3419
skipping: sqtx3420
skipping: sqtx3421
skipping: sqtx3422
skipping: sqtx3423
skipping: sqtx3424
skipping: sqtx3425
skipping: sqtx3426
skipping: sqtx3427
skipping: sqtx3428
skipping: sqtx3429
skipping: sqtx3430
skipping: sqtx3431
skipping: sqtx3432
skipping: sqtx3433
skipping: sqtx3434
skipping: sqtx3435
skipping: sqtx3436
skipping: sqtx3437
skipping: sqtx3438
skipping: sqtx3439
skipping: sqtx3440
skipping: sqtx3441
skipping: sqtx3442
skipping: sqtx3443
skipping: sqtx3444
skipping: sqtx3445
skipping: sqtx3446
skipping: sqtx3447
skipping: sqtx3448
skipping: sqtx3449
skipping: sqtx3450
skipping: sqtx3451
skipping: sqtx3452
skipping: sqtx3453
skipping: sqtx3454
skipping: sqtx3455
skipping: sqtx3456
skipping: sqtx3457
skipping: sqtx3458
skipping: sqtx3459
skipping: sqtx3460
skipping: sqtx3461
skipping: sqtx3462
skipping: sqtx3463
skipping: sqtx3464
skipping: sqtx3465
skipping: sqtx3466
skipping: sqtx3467
skipping: sqtx3468
skipping: sqtx3469
skipping: sqtx3470
skipping: sqtx3471
skipping: sqtx3472
skipping: sqtx3473
skipping: sqtx3474
skipping: sqtx3475
skipping: sqtx3476
skipping: sqtx3477
skipping: sqtx3478
skipping: sqtx3479
skipping: sqtx3480
skipping: sqtx3481
skipping: sqtx3482
skipping: sqtx3483
skipping: sqtx3484
skipping: sqtx3485
skipping: sqtx3486
skipping: sqtx3487
skipping: sqtx3488
skipping: sqtx3489
skipping: sqtx3490
skipping: sqtx3491
skipping: sqtx3492
skipping: sqtx3493
skipping: sqtx3494
skipping: sqtx3495
skipping: sqtx3496
skipping: sqtx3497
skipping: sqtx3498
skipping: sqtx3499
skipping: sqtx3500
skipping: sqtx3501
skipping: sqtx3502
skipping: sqtx3503
skipping: sqtx3504
skipping: sqtx3505
skipping: sqtx3506
skipping: sqtx3507
skipping: sqtx3508
skipping: sqtx3509
skipping: sqtx3510
skipping: sqtx3511
skipping: sqtx3512
skipping: sqtx3513
skipping: sqtx3514
skipping: sqtx3515
skipping: sqtx3516
skipping: sqtx3517
skipping: sqtx3518
skipping: sqtx3519
skipping: sqtx3520
skipping: sqtx3521
skipping: sqtx3522
skipping: sqtx3523
skipping: sqtx3524
skipping: sqtx3525
skipping: sqtx3526
skipping: sqtx3527
skipping: sqtx3528
skipping: sqtx3529
skipping: sqtx3530
skipping: sqtx3531
skipping: sqtx3532
skipping: sqtx3533
skipping: sqtx3534
skipping: sqtx3535
skipping: sqtx3536
skipping: sqtx3537
skipping: sqtx3538
skipping: sqtx3539
skipping: sqtx3540
skipping: sqtx3541
skipping: sqtx3542
skipping: sqtx3543
skipping: sqtx3544
skipping: sqtx3545
skipping: sqtx3546
skipping: sqtx3547
skipping: sqtx3548
skipping: sqtx3549
skipping: sqtx3550
skipping: sqtx3551
skipping: sqtx3552
skipping: sqtx3553
skipping: sqtx3554
skipping: sqtx3555
skipping: sqtx3556
skipping: sqtx3557
skipping: sqtx3558
skipping: sqtx3559
skipping: sqtx3560
skipping: sqtx3561
skipping: sqtx3562
skipping: sqtx3563
skipping: sqtx3564
skipping: sqtx3565
skipping: sqtx3566
skipping: sqtx3567
skipping: sqtx3568
skipping: sqtx3569
skipping: sqtx3570
skipping: sqtx3571
skipping: sqtx3572
skipping: sqtx3573
skipping: sqtx3574
skipping: sqtx3575
skipping: sqtx3576
skipping: sqtx3577
skipping: sqtx3578
skipping: sqtx3579
skipping: sqtx3580
skipping: sqtx3581
skipping: sqtx3582
skipping: sqtx3583
skipping: sqtx3584
skipping: sqtx3585
skipping: sqtx3586
skipping: sqtx3587
skipping: sqtx3588
skipping: sqtx3589
skipping: sqtx3590
skipping: sqtx3591
skipping: sqtx3592
skipping: sqtx3593
skipping: sqtx3594
skipping: sqtx3595
skipping: sqtx3596
skipping: sqtx3597
skipping: sqtx3598
skipping: sqtx3599
skipping: sqtx3600
skipping: sqtx3601
skipping: sqtx3602
skipping: sqtx3603
skipping: sqtx3604
skipping: sqtx3605
skipping: sqtx3606
skipping: sqtx3607
skipping: sqtx3608
skipping: sqtx3609
skipping: sqtx3610
skipping: sqtx3611
skipping: sqtx3612
skipping: sqtx3613
skipping: sqtx3614
skipping: sqtx3615
skipping: sqtx3616
skipping: sqtx3617
skipping: sqtx3618
skipping: sqtx3619
skipping: sqtx3620
skipping: sqtx3621
skipping: sqtx3622
skipping: sqtx3623
skipping: sqtx3624
skipping: sqtx3625
skipping: sqtx3626
skipping: sqtx3627
skipping: sqtx3628
skipping: sqtx3629
skipping: sqtx3630
skipping: sqtx3631
skipping: sqtx3632
skipping: sqtx3633
skipping: sqtx3634
skipping: sqtx3635
skipping: sqtx3636
skipping: sqtx3637
skipping: sqtx3638
skipping: sqtx3639
skipping: sqtx3640
skipping: sqtx3641
skipping: sqtx3642
skipping: sqtx3643
skipping: sqtx3644
skipping: sqtx3645
skipping: sqtx3646
skipping: sqtx3647
skipping: sqtx3648
skipping: sqtx3649
skipping: sqtx3650
skipping: sqtx3651
skipping: sqtx3652
skipping: sqtx3653
skipping: sqtx3654
skipping: sqtx3655
skipping: sqtx3656
skipping: sqtx3657
skipping: sqtx3658
skipping: sqtx3659
skipping: sqtx3660
skipping: sqtx3661
skipping: sqtx3662
skipping: sqtx3663
skipping: sqtx3664
skipping: sqtx3665
skipping: sqtx3666
skipping: sqtx3667
skipping: sqtx3668
skipping: sqtx3669
skipping: sqtx3670
skipping: sqtx3671
skipping: sqtx3672
skipping: sqtx3673
skipping: sqtx3674
skipping: sqtx3675
skipping: sqtx3676
skipping: sqtx3677
skipping: sqtx3678
skipping: sqtx3679
skipping: sqtx3680
skipping: sqtx3681
skipping: sqtx3682
skipping: sqtx3683
skipping: sqtx3684
skipping: sqtx3685
skipping: sqtx3686
skipping: sqtx3687
skipping: sqtx3688
skipping: sqtx3689
skipping: sqtx3690
skipping: sqtx3691
skipping: sqtx3692
skipping: sqtx3693
skipping: sqtx3694
skipping: sqtx3695
skipping: sqtx3696
skipping: sqtx3697
skipping: sqtx3698
skipping: sqtx3699
skipping: sqtx3700
skipping: sqtx3701
skipping: sqtx3702
skipping: sqtx3703
skipping: sqtx3704
skipping: sqtx3705
skipping: sqtx3706
skipping: sqtx3707
skipping: sqtx3708
skipping: sqtx3709
skipping: sqtx3710
skipping: sqtx3711
skipping: sqtx3712
skipping: sqtx3713
skipping: sqtx3714
skipping: sqtx3715
skipping: sqtx3716
skipping: sqtx3717
skipping: sqtx3718
skipping: sqtx3719
skipping: sqtx3720
skipping: sqtx3721
skipping: sqtx3722
skipping: sqtx3723
skipping: sqtx3724
skipping: sqtx3725
skipping: sqtx3726
skipping: sqtx3727
skipping: sqtx3728
skipping: sqtx3729
skipping: sqtx3730
skipping: sqtx3731
skipping: sqtx3732
skipping: sqtx3733
skipping: sqtx3734
skipping: sqtx3735
skipping: sqtx3736
skipping: sqtx3737
skipping: sqtx3738
skipping: sqtx3739
skipping: sqtx3740
skipping: sqtx3741
skipping: sqtx3742
skipping: sqtx3743
skipping: sqtx3744
skipping: sqtx3745
skipping: sqtx3746
skipping: sqtx3747
skipping: sqtx3748
skipping: sqtx3749
skipping: sqtx3750
skipping: sqtx3751
skipping: sqtx3752
skipping: sqtx3753
skipping: sqtx3754
skipping: sqtx3755
skipping: sqtx3756
skipping: sqtx3757
skipping: sqtx3758
skipping: sqtx3759
skipping: sqtx3760
skipping: sqtx3761
skipping: sqtx3762
skipping: sqtx3763
skipping: sqtx3764
skipping: sqtx3765
skipping: sqtx3766
skipping: sqtx3767
skipping: sqtx3768
skipping: sqtx3769
skipping: sqtx3770
skipping: sqtx3771
skipping: sqtx3772
skipping: sqtx3773
skipping: sqtx3774
skipping: sqtx3775
skipping: sqtx3776
skipping: sqtx3777
skipping: sqtx3778
skipping: sqtx3779
skipping: sqtx3780
skipping: sqtx3781
skipping: sqtx3782
skipping: sqtx3783
skipping: sqtx3784
skipping: sqtx3785
skipping: sqtx3786
skipping: sqtx3787
skipping: sqtx3788
skipping: sqtx3789
skipping: sqtx3790
skipping: sqtx3791
skipping: sqtx3792
skipping: sqtx3793
skipping: sqtx3794
skipping: sqtx3795
skipping: sqtx3796
skipping: sqtx3797
skipping: sqtx3798
skipping: sqtx3799
skipping: sqtx3800
skipping: sqtx3801
skipping: sqtx3802
skipping: sqtx3803
skipping: sqtx3804
skipping: sqtx3805
skipping: sqtx3806
skipping: sqtx3807
skipping: sqtx3808
skipping: sqtx3809
skipping: sqtx3810
skipping: sqtx3811
skipping: sqtx3812
skipping: sqtx3813
skipping: sqtx3814
skipping: sqtx3815
skipping: sqtx3816
skipping: sqtx3817
skipping: sqtx3818
skipping: sqtx3819
skipping: sqtx3820
skipping: sqtx3821
skipping: sqtx3822
skipping: sqtx3823
skipping: sqtx3824
skipping: sqtx3825
skipping: sqtx3826
skipping: sqtx3827
skipping: sqtx3828
skipping: sqtx3829
skipping: sqtx3830
skipping: sqtx3831
skipping: sqtx3832
skipping: sqtx3833
skipping: sqtx3834
skipping: sqtx3835
skipping: sqtx3836
skipping: sqtx3837
skipping: sqtx3838
skipping: sqtx3839
skipping: sqtx3840
skipping: sqtx3841
skipping: sqtx3842
skipping: sqtx3843
skipping: sqtx3844
skipping: sqtx3845
skipping: sqtx3846
skipping: sqtx3847
skipping: sqtx3848
skipping: sqtx3849
skipping: sqtx3850
skipping: sqtx3851
skipping: sqtx3852
skipping: sqtx3853
skipping: sqtx3854
skipping: sqtx3855
skipping: sqtx3856
skipping: sqtx3857
skipping: sqtx3858
skipping: sqtx3859
skipping: sqtx3860
skipping: sqtx3861
skipping: sqtx3862
skipping: sqtx3863
skipping: sqtx3864
skipping: sqtx3865
skipping: sqtx3866
skipping: sqtx3867
skipping: sqtx3868
skipping: sqtx3869
skipping: sqtx3870
skipping: sqtx3871
skipping: sqtx3872
skipping: sqtx3873
skipping: sqtx3874
skipping: sqtx3875
skipping: sqtx3876
skipping: sqtx3877
skipping: sqtx3878
skipping: sqtx3879
skipping: sqtx3880
skipping: sqtx3881
skipping: sqtx3882
skipping: sqtx3883
skipping: sqtx3884
skipping: sqtx3885
skipping: sqtx3886
skipping: sqtx3887
skipping: sqtx3888
skipping: sqtx3889
skipping: sqtx3890
skipping: sqtx3891
skipping: sqtx3892
skipping: sqtx3893
skipping: sqtx3894
skipping: sqtx3895
skipping: sqtx3896
skipping: sqtx3897
skipping: sqtx3898
skipping: sqtx3899
skipping: sqtx3900
skipping: sqtx3901
skipping: sqtx3902
skipping: sqtx3903
skipping: sqtx3904
skipping: sqtx3905
skipping: sqtx3906
skipping: sqtx3907
skipping: sqtx3908
skipping: sqtx3909
skipping: sqtx3910
skipping: sqtx3911
skipping: sqtx3912
skipping: sqtx3913
skipping: sqtx3914
skipping: sqtx3915
skipping: sqtx3916
skipping: sqtx3917
skipping: sqtx3918
skipping: sqtx3919
skipping: sqtx3920
skipping: sqtx3921
skipping: sqtx3922
skipping: sqtx3923
skipping: sqtx3924
skipping: sqtx3925
skipping: sqtx3926
skipping: sqtx3927
skipping: sqtx3928
skipping: sqtx3929
skipping: sqtx3930
skipping: sqtx3931
skipping: sqtx3932
skipping: sqtx3933
skipping: sqtx3934
skipping: sqtx3935
skipping: sqtx3936
skipping: sqtx3937
skipping: sqtx3938
skipping: sqtx3939
skipping: sqtx3940
skipping: sqtx3941
skipping: sqtx3942
skipping: sqtx3943
skipping: sqtx3944
skipping: sqtx3945
skipping: sqtx3946
skipping: sqtx3947
skipping: sqtx3948
skipping: sqtx3949
skipping: sqtx3950
skipping: sqtx3951
skipping: sqtx3952
skipping: sqtx3953
skipping: sqtx3954
skipping: sqtx3955
skipping: sqtx3956
skipping: sqtx3957
skipping: sqtx3958
skipping: sqtx3959
skipping: sqtx3960
skipping: sqtx3961
skipping: sqtx3962
skipping: sqtx3963
skipping: sqtx3964
skipping: sqtx3965
skipping: sqtx3966
skipping: sqtx3967
skipping: sqtx3968
skipping: sqtx3969
skipping: sqtx3970
skipping: sqtx3971
skipping: sqtx3972
skipping: sqtx3973
skipping: sqtx3974
skipping: sqtx3975
skipping: sqtx3976
skipping: sqtx3977
skipping: sqtx3978
skipping: sqtx3979
skipping: sqtx3980
skipping: sqtx3981
skipping: sqtx3982
skipping: sqtx3983
skipping: sqtx3984
skipping: sqtx3985
skipping: sqtx3986
skipping: sqtx3987
skipping: sqtx3988
skipping: sqtx3989
skipping: sqtx3990
skipping: sqtx3991
skipping: sqtx3992
skipping: sqtx3993
skipping: sqtx3994
skipping: sqtx3995
skipping: sqtx3996
skipping: sqtx3997
skipping: sqtx3998
skipping: sqtx3999
skipping: sqtx4000
skipping: sqtx4001
skipping: sqtx4002
skipping: sqtx4003
skipping: sqtx4004
skipping: sqtx4005
skipping: sqtx4006
skipping: sqtx4007
skipping: sqtx4008
skipping: sqtx4009
skipping: sqtx4010
skipping: sqtx4011
skipping: sqtx4012
skipping: sqtx4013
skipping: sqtx4014
skipping: sqtx4015
skipping: sqtx4016
skipping: sqtx4017
skipping: sqtx4018
skipping: sqtx4019
skipping: sqtx4020
skipping: sqtx4021
skipping: sqtx4022
skipping: sqtx4023
skipping: sqtx4024
skipping: sqtx4025
skipping: sqtx4026
skipping: sqtx4027
skipping: sqtx4028
skipping: sqtx4029
skipping: sqtx4030
skipping: sqtx4031
skipping: sqtx4032
skipping: sqtx4033
skipping: sqtx4034
skipping: sqtx4035
skipping: sqtx4036
skipping: sqtx4037
skipping: sqtx4038
skipping: sqtx4039
skipping: sqtx4040
skipping: sqtx4041
skipping: sqtx4042
skipping: sqtx4043
skipping: sqtx4044
skipping: sqtx4045
skipping: sqtx4046
skipping: sqtx4047
skipping: sqtx4048
skipping: sqtx4049
skipping: sqtx4050
skipping: sqtx4051
skipping: sqtx4052
skipping: sqtx4053
skipping: sqtx4054
skipping: sqtx4055
skipping: sqtx4056
skipping: sqtx4057
skipping: sqtx4058
skipping: sqtx4059
skipping: sqtx4060
skipping: sqtx4061
skipping: sqtx4062
skipping: sqtx4063
skipping: sqtx4064
skipping: sqtx4065
skipping: sqtx4066
skipping: sqtx4067
skipping: sqtx4068
skipping: sqtx4069
skipping: sqtx4070
skipping: sqtx4071
skipping: sqtx4072
skipping: sqtx4073
skipping: sqtx4074
skipping: sqtx4075
skipping: sqtx4076
skipping: sqtx4077
skipping: sqtx4078
skipping: sqtx4079
skipping: sqtx4080
skipping: sqtx4081
skipping: sqtx4082
skipping: sqtx4083
skipping: sqtx4084
skipping: sqtx4085
skipping: sqtx4086
skipping: sqtx4087
skipping: sqtx4088
skipping: sqtx4089
skipping: sqtx4090
skipping: sqtx4091
skipping: sqtx4092
skipping: sqtx4093
skipping: sqtx4094
skipping: sqtx4095
skipping: sqtx4096
skipping: sqtx4097
skipping: sqtx4098
skipping: sqtx4099
skipping: sqtx4100
skipping: sqtx4101
skipping: sqtx4102
skipping: sqtx4103
skipping: sqtx4104
skipping: sqtx4105
skipping: sqtx4106
skipping: sqtx4107
skipping: sqtx4108
skipping: sqtx4109
skipping: sqtx4110
skipping: sqtx4111
skipping: sqtx4112
skipping: sqtx4113
skipping: sqtx4114
skipping: sqtx4115
skipping: sqtx4116
skipping: sqtx4117
skipping: sqtx4118
skipping: sqtx4119
skipping: sqtx4120
skipping: sqtx4121
skipping: sqtx4122
skipping: sqtx4123
skipping: sqtx4124
skipping: sqtx4125
skipping: sqtx4126
skipping: sqtx4127
skipping: sqtx4128
skipping: sqtx4129
skipping: sqtx4130
skipping: sqtx4131
skipping: sqtx4132
skipping: sqtx4133
skipping: sqtx4134
skipping: sqtx4135
skipping: sqtx4136
skipping: sqtx4137
skipping: sqtx4138
skipping: sqtx4139
skipping: sqtx4140
skipping: sqtx4141
skipping: sqtx4142
skipping: sqtx4143
skipping: sqtx4144
skipping: sqtx4145
skipping: sqtx4146
skipping: sqtx4147
skipping: sqtx4148
skipping: sqtx4149
skipping: sqtx4150
skipping: sqtx4151
skipping: sqtx4152
skipping: sqtx4153
skipping: sqtx4154
skipping: sqtx4155
skipping: sqtx4156
skipping: sqtx4157
skipping: sqtx4158
skipping: sqtx4159
skipping: sqtx4160
skipping: sqtx4161
skipping: sqtx4162
skipping: sqtx4163
skipping: sqtx4164
skipping: sqtx4165
skipping: sqtx4166
skipping: sqtx4167
skipping: sqtx4168
skipping: sqtx4169
skipping: sqtx4170
skipping: sqtx4171
skipping: sqtx4172
skipping: sqtx4173
skipping: sqtx4174
skipping: sqtx4175
skipping: sqtx4176
skipping: sqtx4177
skipping: sqtx4178
skipping: sqtx4179
skipping: sqtx4180
skipping: sqtx4181
skipping: sqtx4182
skipping: sqtx4183
skipping: sqtx4184
skipping: sqtx4185
skipping: sqtx4186
skipping: sqtx4187
skipping: sqtx4188
skipping: sqtx4189
skipping: sqtx4190
skipping: sqtx4191
skipping: sqtx4192
skipping: sqtx4193
skipping: sqtx4194
skipping: sqtx4195
skipping: sqtx4196
skipping: sqtx4197
skipping: sqtx4198
skipping: sqtx4199
skipping: sqtx4200
skipping: sqtx4201
skipping: sqtx4202
skipping: sqtx4203
skipping: sqtx4204
skipping: sqtx4205
skipping: sqtx4206
skipping: sqtx4207
skipping: sqtx4208
skipping: sqtx4209
skipping: sqtx4210
skipping: sqtx4211
skipping: sqtx4212
skipping: sqtx4213
skipping: sqtx4214
skipping: sqtx4215
skipping: sqtx4216
skipping: sqtx4217
skipping: sqtx4218
skipping: sqtx4219
skipping: sqtx4220
skipping: sqtx4221
skipping: sqtx4222
skipping: sqtx4223
skipping: sqtx4224
skipping: sqtx4225
skipping: sqtx4226
skipping: sqtx4227
skipping: sqtx4228
skipping: sqtx4229
skipping: sqtx4230
skipping: sqtx4231
skipping: sqtx4232
skipping: sqtx4233
skipping: sqtx4234
skipping: sqtx4235
skipping: sqtx4236
skipping: sqtx4237
skipping: sqtx4238
skipping: sqtx4239
skipping: sqtx4240
skipping: sqtx4241
skipping: sqtx4242
skipping: sqtx4243
skipping: sqtx4244
skipping: sqtx4245
skipping: sqtx4246
skipping: sqtx4247
skipping: sqtx4248
skipping: sqtx4249
skipping: sqtx4250
skipping: sqtx4251
skipping: sqtx4252
skipping: sqtx4253
skipping: sqtx4254
skipping: sqtx4255
skipping: sqtx4256
skipping: sqtx4257
skipping: sqtx4258
skipping: sqtx4259
skipping: sqtx4260
skipping: sqtx4261
skipping: sqtx4262
skipping: sqtx4263
skipping: sqtx4264
skipping: sqtx4265
skipping: sqtx4266
skipping: sqtx4267
skipping: sqtx4268
skipping: sqtx4269
skipping: sqtx4270
skipping: sqtx4271
skipping: sqtx4272
skipping: sqtx4273
skipping: sqtx4274
skipping: sqtx4275
skipping: sqtx4276
skipping: sqtx4277
skipping: sqtx4278
skipping: sqtx4279
skipping: sqtx4280
skipping: sqtx4281
skipping: sqtx4282
skipping: sqtx4283
skipping: sqtx4284
skipping: sqtx4285
skipping: sqtx4286
skipping: sqtx4287
skipping: sqtx4288
skipping: sqtx4289
skipping: sqtx4290
skipping: sqtx4291
skipping: sqtx4292
skipping: sqtx4293
skipping: sqtx4294
skipping: sqtx4295
skipping: sqtx4296
skipping: sqtx4297
skipping: sqtx4298
skipping: sqtx4299
skipping: sqtx4300
skipping: sqtx4301
skipping: sqtx4302
skipping: sqtx4303
skipping: sqtx4304
skipping: sqtx4305
skipping: sqtx4306
skipping: sqtx4307
skipping: sqtx4308
skipping: sqtx4309
skipping: sqtx4310
skipping: sqtx4311
skipping: sqtx4312
skipping: sqtx4313
skipping: sqtx4314
skipping: sqtx4315
skipping: sqtx4316
skipping: sqtx4317
skipping: sqtx4318
skipping: sqtx4319
skipping: sqtx4320
skipping: sqtx4321
skipping: sqtx4322
skipping: sqtx4323
skipping: sqtx4324
skipping: sqtx4325
skipping: sqtx4326
skipping: sqtx4327
skipping: sqtx4328
skipping: sqtx4329
skipping: sqtx4330
skipping: sqtx4331
skipping: sqtx4332
skipping: sqtx4333
skipping: sqtx4334
skipping: sqtx4335
skipping: sqtx4336
skipping: sqtx4337
skipping: sqtx4338
skipping: sqtx4339
skipping: sqtx4340
skipping: sqtx4341
skipping: sqtx4342
skipping: sqtx4343
skipping: sqtx4344
skipping: sqtx4345
skipping: sqtx4346
skipping: sqtx4347
skipping: sqtx4348
skipping: sqtx4349
skipping: sqtx4350
skipping: sqtx4351
skipping: sqtx4352
skipping: sqtx4353
skipping: sqtx4354
skipping: sqtx4355
skipping: sqtx4356
skipping: sqtx4357
skipping: sqtx4358
skipping: sqtx4359
skipping: sqtx4360
skipping: sqtx4361
skipping: sqtx4362
skipping: sqtx4363
skipping: sqtx4364
skipping: sqtx4365
skipping: sqtx4366
skipping: sqtx4367
skipping: sqtx4368
skipping: sqtx4369
skipping: sqtx4370
skipping: sqtx4371
skipping: sqtx4372
skipping: sqtx4373
skipping: sqtx4374
skipping: sqtx4375
skipping: sqtx4376
skipping: sqtx4377
skipping: sqtx4378
skipping: sqtx4379
skipping: sqtx4380
skipping: sqtx4381
skipping: sqtx4382
skipping: sqtx4383
skipping: sqtx4384
skipping: sqtx4385
skipping: sqtx4386
skipping: sqtx4387
skipping: sqtx4388
skipping: sqtx4389
skipping: sqtx4390
skipping: sqtx4391
skipping: sqtx4392
skipping: sqtx4393
skipping: sqtx4394
skipping: sqtx4395
skipping: sqtx4396
skipping: sqtx4397
skipping: sqtx4398
skipping: sqtx4399
skipping: sqtx4400
skipping: sqtx4401
skipping: sqtx4402
skipping: sqtx4403
skipping: sqtx4404
skipping: sqtx4405
skipping: sqtx4406
skipping: sqtx4407
skipping: sqtx4408
skipping: sqtx4409
skipping: sqtx4410
skipping: sqtx4411
skipping: sqtx4412
skipping: sqtx4413
skipping: sqtx4414
skipping: sqtx4415
skipping: sqtx4416
skipping: sqtx4417
skipping: sqtx4418
skipping: sqtx4419
skipping: sqtx4420
skipping: sqtx4421
skipping: sqtx4422
skipping: sqtx4423
skipping: sqtx4424
skipping: sqtx4425
skipping: sqtx4426
skipping: sqtx4427
skipping: sqtx4428
skipping: sqtx4429
skipping: sqtx4430
skipping: sqtx4431
skipping: sqtx4432
skipping: sqtx4433
skipping: sqtx4434
skipping: sqtx4435
skipping: sqtx4436
skipping: sqtx4437
skipping: sqtx4438
skipping: sqtx4439
skipping: sqtx4440
skipping: sqtx4441
skipping: sqtx4442
skipping: sqtx4443
skipping: sqtx4444
skipping: sqtx4445
skipping: sqtx4446
skipping: sqtx4447
skipping: sqtx4448
skipping: sqtx4449
skipping: sqtx4450
skipping: sqtx4451
skipping: sqtx4452
skipping: sqtx4453
skipping: sqtx4454
skipping: sqtx4455
skipping: sqtx4456
skipping: sqtx4457
skipping: sqtx4458
skipping: sqtx4459
skipping: sqtx4460
skipping: sqtx4461
skipping: sqtx4462
skipping: sqtx4463
skipping: sqtx4464
skipping: sqtx4465
skipping: sqtx4466
skipping: sqtx4467
skipping: sqtx4468
skipping: sqtx4469
skipping: sqtx4470
skipping: sqtx4471
skipping: sqtx4472
skipping: sqtx4473
skipping: sqtx4474
skipping: sqtx4475
skipping: sqtx4476
skipping: sqtx4477
skipping: sqtx4478
skipping: sqtx4479
skipping: sqtx4480
skipping: sqtx4481
skipping: sqtx4482
skipping: sqtx4483
skipping: sqtx4484
skipping: sqtx4485
skipping: sqtx4486
skipping: sqtx4487
skipping: sqtx4488
skipping: sqtx4489
skipping: sqtx4490
skipping: sqtx4491
skipping: sqtx4492
skipping: sqtx4493
skipping: sqtx4494
skipping: sqtx4495
skipping: sqtx4496
skipping: sqtx4497
skipping: sqtx4498
skipping: sqtx4499
skipping: sqtx4500
skipping: sqtx4501
skipping: sqtx4502
skipping: sqtx4503
skipping: sqtx4504
skipping: sqtx4505
skipping: sqtx4506
skipping: sqtx4507
skipping: sqtx4508
skipping: sqtx4509
skipping: sqtx4510
skipping: sqtx4511
skipping: sqtx4512
skipping: sqtx4513
skipping: sqtx4514
skipping: sqtx4515
skipping: sqtx4516
skipping: sqtx4517
skipping: sqtx4518
skipping: sqtx4519
skipping: sqtx4520
skipping: sqtx4521
skipping: sqtx4522
skipping: sqtx4523
skipping: sqtx4524
skipping: sqtx4525
skipping: sqtx4526
skipping: sqtx4527
skipping: sqtx4528
skipping: sqtx4529
skipping: sqtx4530
skipping: sqtx4531
skipping: sqtx4532
skipping: sqtx4533
skipping: sqtx4534
skipping: sqtx4535
skipping: sqtx4536
skipping: sqtx4537
skipping: sqtx4538
skipping: sqtx4539
skipping: sqtx4540
skipping: sqtx4541
skipping: sqtx4542
skipping: sqtx4543
skipping: sqtx4544
skipping: sqtx4545
skipping: sqtx4546
skipping: sqtx4547
skipping: sqtx4548
skipping: sqtx4549
skipping: sqtx4550
skipping: sqtx4551
skipping: sqtx4552
skipping: sqtx4553
skipping: sqtx4554
skipping: sqtx4555
skipping: sqtx4556
skipping: sqtx4557
skipping: sqtx4558
skipping: sqtx4559
skipping: sqtx4560
skipping: sqtx4561
skipping: sqtx4562
skipping: sqtx4563
skipping: sqtx4564
skipping: sqtx4565
skipping: sqtx4566
skipping: sqtx4567
skipping: sqtx4568
skipping: sqtx4569
skipping: sqtx4570
skipping: sqtx4571
skipping: sqtx4572
skipping: sqtx4573
skipping: sqtx4574
skipping: sqtx4575
skipping: sqtx4576
skipping: sqtx4577
skipping: sqtx4578
skipping: sqtx4579
skipping: sqtx4580
skipping: sqtx4581
skipping: sqtx4582
skipping: sqtx4583
skipping: sqtx4584
skipping: sqtx4585
skipping: sqtx4586
skipping: sqtx4587
skipping: sqtx4588
skipping: sqtx4589
skipping: sqtx4590
skipping: sqtx4591
skipping: sqtx4592
skipping: sqtx4593
skipping: sqtx4594
skipping: sqtx4595
skipping: sqtx4596
skipping: sqtx4597
skipping: sqtx4598
skipping: sqtx4599
skipping: sqtx4600
skipping: sqtx4601
skipping: sqtx4602
skipping: sqtx4603
skipping: sqtx4604
skipping: sqtx4605
skipping: sqtx4606
skipping: sqtx4607
skipping: sqtx4608
skipping: sqtx4609
skipping: sqtx4610
skipping: sqtx4611
skipping: sqtx4612
skipping: sqtx4613
skipping: sqtx4614
skipping: sqtx4615
skipping: sqtx4616
skipping: sqtx4617
skipping: sqtx4618
skipping: sqtx4619
skipping: sqtx4620
skipping: sqtx4621
skipping: sqtx4622
skipping: sqtx4623
skipping: sqtx4624
skipping: sqtx4625
skipping: sqtx4626
skipping: sqtx4627
skipping: sqtx4628
skipping: sqtx4629
skipping: sqtx4630
skipping: sqtx4631
skipping: sqtx4632
skipping: sqtx4633
skipping: sqtx4634
skipping: sqtx4635
skipping: sqtx4636
skipping: sqtx4637
skipping: sqtx4638
skipping: sqtx4639
skipping: sqtx4640
skipping: sqtx4641
skipping: sqtx4642
skipping: sqtx4643
skipping: sqtx4644
skipping: sqtx4645
skipping: sqtx4646
skipping: sqtx4647
skipping: sqtx4648
skipping: sqtx4649
skipping: sqtx4650
skipping: sqtx4651
skipping: sqtx4652
skipping: sqtx4653
skipping: sqtx4654
skipping: sqtx4655
skipping: sqtx4656
skipping: sqtx4657
skipping: sqtx4658
skipping: sqtx4659
skipping: sqtx4660
skipping: sqtx4661
skipping: sqtx4662
skipping: sqtx4663
skipping: sqtx4664
skipping: sqtx4665
skipping: sqtx4666
skipping: sqtx4667
skipping: sqtx4668
skipping: sqtx4669
skipping: sqtx4670
skipping: sqtx4671
skipping: sqtx4672
skipping: sqtx4673
skipping: sqtx4674
skipping: sqtx4675
skipping: sqtx4676
skipping: sqtx4677
skipping: sqtx4678
skipping: sqtx4679
skipping: sqtx4680
skipping: sqtx4681
skipping: sqtx4682
skipping: sqtx4683
skipping: sqtx4684
skipping: sqtx4685
skipping: sqtx4686
skipping: sqtx4687
skipping: sqtx4688
skipping: sqtx4689
skipping: sqtx4690
skipping: sqtx4691
skipping: sqtx4692
skipping: sqtx4693
skipping: sqtx4694
skipping: sqtx4695
skipping: sqtx4696
skipping: sqtx4697
skipping: sqtx4698
skipping: sqtx4699
skipping: sqtx4700
skipping: sqtx4701
skipping: sqtx4702
skipping: sqtx4703
skipping: sqtx4704
skipping: sqtx4705
skipping: sqtx4706
skipping: sqtx4707
skipping: sqtx4708
skipping: sqtx4709
skipping: sqtx4710
skipping: sqtx4711
skipping: sqtx4712
skipping: sqtx4713
skipping: sqtx4714
skipping: sqtx4715
skipping: sqtx4716
skipping: sqtx4717
skipping: sqtx4718
skipping: sqtx4719
skipping: sqtx4720
skipping: sqtx4721
skipping: sqtx4722
skipping: sqtx4723
skipping: sqtx4724
skipping: sqtx4725
skipping: sqtx4726
skipping: sqtx4727
skipping: sqtx4728
skipping: sqtx4729
skipping: sqtx4730
skipping: sqtx4731
skipping: sqtx4732
skipping: sqtx4733
skipping: sqtx4734
skipping: sqtx4735
skipping: sqtx4736
skipping: sqtx4737
skipping: sqtx4738
skipping: sqtx4739
skipping: sqtx4740
skipping: sqtx4741
skipping: sqtx4742
skipping: sqtx4743
skipping: sqtx4744
skipping: sqtx4745
skipping: sqtx4746
skipping: sqtx4747
skipping: sqtx4748
skipping: sqtx4749
skipping: sqtx4750
skipping: sqtx4751
skipping: sqtx4752
skipping: sqtx4753
skipping: sqtx4754
skipping: sqtx4755
skipping: sqtx4756
skipping: sqtx4757
skipping: sqtx4758
skipping: sqtx4759
skipping: sqtx4760
skipping: sqtx4761
skipping: sqtx4762
skipping: sqtx4763
skipping: sqtx4764
skipping: sqtx4765
skipping: sqtx4766
skipping: sqtx4767
skipping: sqtx4768
skipping: sqtx4769
skipping: sqtx4770
skipping: sqtx4771
skipping: sqtx4772
skipping: sqtx4773
skipping: sqtx4774
skipping: sqtx4775
skipping: sqtx4776
skipping: sqtx4777
skipping: sqtx4778
skipping: sqtx4779
skipping: sqtx4780
skipping: sqtx4781
skipping: sqtx4782
skipping: sqtx4783
skipping: sqtx4784
skipping: sqtx4785
skipping: sqtx4786
skipping: sqtx4787
skipping: sqtx4788
skipping: sqtx4789
skipping: sqtx4790
skipping: sqtx4791
skipping: sqtx4792
skipping: sqtx4793
skipping: sqtx4794
skipping: sqtx4795
skipping: sqtx4796
skipping: sqtx4797
skipping: sqtx4798
skipping: sqtx4799
skipping: sqtx4800
context {
    rounding     : 0
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 4
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx5001
skipping: sqtx5002
skipping: sqtx5003
skipping: sqtx5004
skipping: sqtx5005
skipping: sqtx5006
skipping: sqtx5007
skipping: sqtx5008
skipping: sqtx5009
skipping: sqtx5010
skipping: sqtx5011
skipping: sqtx5012
skipping: sqtx5013
skipping: sqtx5014
skipping: sqtx5015
skipping: sqtx5016
skipping: sqtx5017
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx700
skipping: sqtx701
skipping: sqtx702
skipping: sqtx703
skipping: sqtx704
skipping: sqtx705
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx711
skipping: sqtx712
skipping: sqtx713
skipping: sqtx714
skipping: sqtx715
skipping: sqtx716
skipping: sqtx717
skipping: sqtx718
skipping: sqtx719
context {
    rounding     : 0
    precision    : 10
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx720
context {
    rounding     : 0
    precision    : 11
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx721
context {
    rounding     : 0
    precision    : 12
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx722
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx748
context {
    rounding     : 0
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sqtx749
context {
    rounding     : 0
    precision    : 15
    min exponent : -999
    max exponent : 99
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 15
    min exponent : -99
    max exponent : 99
    clamp:       : 0
}
context {
    rounding     : 0
    precision    : 5
    min exponent : -99
    max exponent : 99
    clamp:       : 0
}
skipping: sqtx760
skipping: sqtx761
skipping: sqtx762
skipping: sqtx763
skipping: sqtx764
skipping: sqtx765
skipping: sqtx766
context {
    rounding     : 0
    precision    : 9
    min exponent : -99
    max exponent : 99
    clamp:       : 0
}
skipping: sqtx770
skipping: sqtx771
skipping: sqtx772
skipping: sqtx773
skipping: sqtx774
skipping: sqtx775
skipping: sqtx776
context {
    rounding     : 0
    precision    : 20
    min exponent : -99
    max exponent : 99
    clamp:       : 0
}
skipping: sqtx780
skipping: sqtx781
skipping: sqtx782
skipping: sqtx783
skipping: sqtx784
skipping: sqtx785
skipping: sqtx786
skipping: sqtx900
general_decimal_arithmetic/test_cases/subset_arithmetic/squareroot0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub001
skipping: sub002
skipping: sub003
skipping: sub004
skipping: sub005
skipping: sub006
skipping: sub007
skipping: sub011
skipping: sub012
skipping: sub013
skipping: sub014
skipping: sub015
skipping: sub016
skipping: sub017
skipping: sub021
skipping: sub022
skipping: sub023
skipping: sub024
skipping: sub025
skipping: sub026
skipping: sub027
skipping: sub030
skipping: sub031
skipping: sub032
skipping: sub033
skipping: sub034
skipping: sub035
skipping: sub036
skipping: sub037
skipping: sub038
skipping: sub040
skipping: sub041
skipping: sub042
skipping: sub043
skipping: sub044
skipping: sub045
skipping: sub046
skipping: sub050
skipping: sub051
skipping: sub052
skipping: sub053
skipping: sub054
skipping: sub055
skipping: sub056
skipping: sub057
skipping: sub060
skipping: sub061
skipping: sub062
skipping: sub063
skipping: sub064
skipping: sub065
skipping: sub066
skipping: sub067
skipping: sub068
skipping: sub069
skipping: sub080
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub081
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub090
skipping: sub091
skipping: sub092
skipping: sub093
skipping: sub094
skipping: sub095
skipping: sub096
skipping: sub097
skipping: sub098
skipping: sub099
skipping: sub100
skipping: sub101
skipping: sub102
skipping: sub103
skipping: sub104
skipping: sub105
skipping: sub106
skipping: sub107
skipping: sub108
skipping: sub120
skipping: sub121
skipping: sub122
skipping: sub123
skipping: sub124
skipping: sub125
skipping: sub126
skipping: sub127
skipping: sub128
skipping: sub129
skipping: sub130
skipping: sub131
skipping: sub132
skipping: sub133
skipping: sub134
skipping: sub135
skipping: sub136
skipping: sub137
skipping: sub138
skipping: sub139
skipping: sub140
skipping: sub141
skipping: sub142
skipping: sub143
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub150
skipping: sub151
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub152
skipping: sub153
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub154
skipping: sub155
context {
    rounding     : 4
    precision    : 12
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub156
skipping: sub157
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub158
skipping: sub159
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub160
skipping: sub161
skipping: sub162
skipping: sub163
skipping: sub164
skipping: sub165
skipping: sub166
skipping: sub167
skipping: sub168
skipping: sub169
skipping: sub170
skipping: sub171
skipping: sub172
skipping: sub173
skipping: sub174
skipping: sub180
skipping: sub181
skipping: sub182
skipping: sub183
skipping: sub184
skipping: sub185
skipping: sub186
skipping: sub187
skipping: sub188
skipping: sub189
skipping: sub190
skipping: sub191
skipping: sub192
skipping: sub193
skipping: sub194
skipping: sub200
skipping: sub201
skipping: sub202
skipping: sub203
skipping: sub204
skipping: sub205
skipping: sub206
skipping: sub207
skipping: sub208
skipping: sub209
skipping: sub210
skipping: sub211
skipping: sub212
skipping: sub213
skipping: sub214
skipping: sub220
skipping: sub221
skipping: sub222
skipping: sub223
skipping: sub224
skipping: sub225
skipping: sub226
skipping: sub227
skipping: sub228
skipping: sub229
skipping: sub230
skipping: sub240
skipping: sub241
skipping: sub242
skipping: sub243
skipping: sub244
skipping: sub245
skipping: sub246
skipping: sub247
skipping: sub248
skipping: sub249
skipping: sub250
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub301
skipping: sub302
skipping: sub311
skipping: sub312
skipping: sub313
skipping: sub314
skipping: sub315
skipping: sub316
skipping: sub317
skipping: sub318
skipping: sub319
skipping: sub320
skipping: sub321
skipping: sub322
skipping: sub323
skipping: sub324
skipping: sub325
skipping: sub326
skipping: sub327
skipping: sub328
skipping: sub330
skipping: sub331
skipping: sub332
skipping: sub333
skipping: sub334
skipping: sub335
skipping: sub340
skipping: sub341
skipping: sub342
skipping: sub343
skipping: sub344
skipping: sub345
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub346
skipping: sub347
skipping: sub348
skipping: sub349
skipping: sub350
skipping: sub351
skipping: sub352
skipping: sub353
skipping: sub354
skipping: sub355
skipping: sub356
skipping: sub357
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub360
skipping: sub361
skipping: sub362
skipping: sub363
skipping: sub364
skipping: sub365
skipping: sub370
skipping: sub371
skipping: sub372
skipping: sub373
skipping: sub374
skipping: sub375
skipping: sub376
skipping: sub377
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub910
skipping: sub911
skipping: sub920
skipping: sub921
skipping: sub922
skipping: sub923
skipping: sub924
skipping: sub925
skipping: sub926
skipping: sub927
skipping: sub928
skipping: sub929
context {
    rounding     : 4
    precision    : 1
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub930
context {
    rounding     : 4
    precision    : 2
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub932
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub934
skipping: sub935
context {
    rounding     : 4
    precision    : 4
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub936
skipping: sub937
context {
    rounding     : 4
    precision    : 5
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub938
skipping: sub939
context {
    rounding     : 4
    precision    : 6
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub940
skipping: sub941
context {
    rounding     : 4
    precision    : 7
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub942
skipping: sub943
context {
    rounding     : 4
    precision    : 8
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub944
skipping: sub945
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub946
skipping: sub947
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub390
skipping: sub391
skipping: sub392
skipping: sub393
skipping: sub394
skipping: sub395
skipping: sub396
skipping: sub397
skipping: sub398
skipping: sub399
skipping: sub400
skipping: sub401
skipping: sub402
skipping: sub403
skipping: sub404
skipping: sub405
skipping: sub406
skipping: sub407
skipping: sub408
skipping: sub409
skipping: sub410
skipping: sub411
skipping: sub420
skipping: sub421
skipping: sub422
skipping: sub423
skipping: sub424
skipping: sub425
skipping: sub426
skipping: sub427
skipping: sub428
skipping: sub429
skipping: sub430
skipping: sub431
skipping: sub432
skipping: sub433
skipping: sub434
skipping: sub435
skipping: sub436
skipping: sub437
skipping: sub438
skipping: sub439
skipping: sub440
skipping: sub441
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub461
skipping: sub462
skipping: sub463
skipping: sub464
skipping: sub465
skipping: sub466
skipping: sub467
skipping: sub468
skipping: sub470
skipping: sub471
skipping: sub472
skipping: sub473
skipping: sub474
skipping: sub475
skipping: sub476
skipping: sub477
skipping: sub478
skipping: sub479
skipping: sub480
skipping: sub481
skipping: sub482
skipping: sub483
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub500
skipping: sub501
skipping: sub502
skipping: sub503
skipping: sub504
skipping: sub505
skipping: sub506
skipping: sub507
skipping: sub508
skipping: sub509
skipping: sub510
skipping: sub511
skipping: sub512
skipping: sub513
skipping: sub514
skipping: sub515
skipping: sub516
skipping: sub517
skipping: sub518
skipping: sub519
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub520
skipping: sub521
skipping: sub522
skipping: sub523
skipping: sub524
skipping: sub525
skipping: sub526
skipping: sub527
skipping: sub528
skipping: sub529
skipping: sub530
skipping: sub531
skipping: sub532
skipping: sub533
skipping: sub534
skipping: sub535
skipping: sub536
skipping: sub537
skipping: sub538
skipping: sub539
skipping: sub540
skipping: sub541
skipping: sub542
context {
    rounding     : 1
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub550
skipping: sub551
skipping: sub552
skipping: sub553
skipping: sub554
skipping: sub555
skipping: sub556
skipping: sub557
skipping: sub558
skipping: sub559
skipping: sub560
skipping: sub561
skipping: sub562
skipping: sub563
skipping: sub564
skipping: sub565
skipping: sub566
skipping: sub567
skipping: sub568
skipping: sub569
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub600
skipping: sub601
skipping: sub602
skipping: sub603
skipping: sub604
skipping: sub605
skipping: sub606
skipping: sub607
skipping: sub608
skipping: sub609
skipping: sub610
skipping: sub611
skipping: sub612
skipping: sub613
skipping: sub614
skipping: sub615
skipping: sub616
skipping: sub617
skipping: sub618
skipping: sub619
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub620
skipping: sub621
skipping: sub622
skipping: sub623
skipping: sub624
skipping: sub625
skipping: sub626
skipping: sub627
skipping: sub628
skipping: sub629
skipping: sub630
skipping: sub631
skipping: sub632
skipping: sub633
skipping: sub634
skipping: sub635
skipping: sub636
skipping: sub637
skipping: sub638
skipping: sub639
skipping: sub640
skipping: sub641
skipping: sub642
context {
    rounding     : 1
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub650
skipping: sub651
skipping: sub652
skipping: sub653
skipping: sub654
skipping: sub655
skipping: sub656
skipping: sub657
skipping: sub658
skipping: sub659
skipping: sub660
skipping: sub661
skipping: sub662
skipping: sub663
skipping: sub664
skipping: sub665
skipping: sub666
skipping: sub667
skipping: sub668
skipping: sub669
context {
    rounding     : 1
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub670
skipping: sub671
skipping: sub672
skipping: sub673
skipping: sub674
context {
    rounding     : 0
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub680
skipping: sub681
skipping: sub682
skipping: sub683
skipping: sub684
skipping: sub685
skipping: sub686
skipping: sub687
skipping: sub688
skipping: sub689
context {
    rounding     : 1
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub690
skipping: sub691
skipping: sub692
skipping: sub693
skipping: sub694
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub700
skipping: sub701
skipping: sub702
skipping: sub703
skipping: sub704
skipping: sub705
skipping: sub706
skipping: sub707
skipping: sub708
skipping: sub709
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999999999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999999999
    clamp:       : 0
}
skipping: sub730
skipping: sub731
skipping: sub732
skipping: sub733
skipping: sub734
skipping: sub735
skipping: sub736
skipping: sub737
context {
    rounding     : 4
    precision    : 3
    min exponent : -999999999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 3
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub801
skipping: sub802
skipping: sub803
skipping: sub804
skipping: sub805
skipping: sub806
skipping: sub807
skipping: sub808
skipping: sub809
skipping: sub810
skipping: sub811
skipping: sub812
context {
    rounding     : 4
    precision    : 15
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: sub841
skipping: sub842
skipping: sub843
skipping: sub844
skipping: sub845
skipping: sub846
skipping: sub847
skipping: sub848
skipping: sub849
skipping: sub850
skipping: sub851
skipping: sub852
skipping: sub900
skipping: sub901
general_decimal_arithmetic/test_cases/subset_arithmetic/subtract0.decTest
general_decimal_arithmetic/test_cases/subset_arithmetic/testall0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: int001
skipping: int002
skipping: int003
skipping: int004
skipping: int005
skipping: int006
skipping: int007
skipping: int008
skipping: int009
skipping: int010
skipping: int011
skipping: int012
skipping: int013
skipping: int014
skipping: int015
skipping: int016
skipping: int017
skipping: int018
skipping: int019
skipping: int020
skipping: int021
skipping: int022
skipping: int031
skipping: int032
skipping: int033
skipping: int034
skipping: int035
skipping: int036
skipping: int037
skipping: int038
skipping: int039
skipping: int040
skipping: int041
skipping: int042
skipping: int043
skipping: int044
skipping: int045
skipping: int046
skipping: int047
skipping: int048
skipping: int049
skipping: int050
skipping: int051
skipping: int052
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: int060
skipping: int061
skipping: int062
skipping: int063
skipping: int065
skipping: int066
skipping: int067
skipping: int068
skipping: int069
skipping: int070
skipping: int071
skipping: int072
skipping: int073
skipping: int080
skipping: int081
skipping: int082
skipping: int083
skipping: int085
skipping: int086
skipping: int087
skipping: int088
skipping: int089
skipping: int090
skipping: int091
skipping: int092
skipping: int093
general_decimal_arithmetic/test_cases/subset_arithmetic/tointegral0.decTest
context {
    rounding     : 
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : 
    max exponent : 999
    clamp:       : 0
}
context {
    rounding     : 4
    precision    : 9
    min exponent : -999
    max exponent : 999
    clamp:       : 0
}
skipping: trm001
skipping: trm002
skipping: trm003
skipping: trm004
skipping: trm005
skipping: trm006
skipping: trm007
skipping: trm008
skipping: trm009
skipping: trm010
skipping: trm011
skipping: trm012
skipping: trm013
skipping: trm014
skipping: trm015
skipping: trm016
skipping: trm017
skipping: trm018
skipping: trm019
skipping: trm020
skipping: trm030
skipping: trm031
skipping: trm032
skipping: trm033
skipping: trm034
skipping: trm035
skipping: trm036
skipping: trm037
skipping: trm038
skipping: trm039
skipping: trm041
skipping: trm042
skipping: trm043
skipping: trm044
skipping: trm045
skipping: trm046
skipping: trm047
skipping: trm048
skipping: trm049
skipping: trm050
skipping: trm051
skipping: trm052
skipping: trm053
skipping: trm054
skipping: trm055
skipping: trm056
skipping: trm060
skipping: trm061
skipping: trm062
skipping: trm063
skipping: trm064
skipping: trm065
skipping: trm066
skipping: trm067
skipping: trm068
skipping: trm069
skipping: trm070
skipping: trm071
skipping: trm080
skipping: trm081
skipping: trm082
skipping: trm083
skipping: trm084
skipping: trm085
skipping: trm086
skipping: trm087
skipping: trm088
skipping: trm089
skipping: trm090
skipping: trm091
skipping: trm092
skipping: trm093
skipping: trm100
skipping: trm101
skipping: trm102
skipping: trm103
skipping: trm104
skipping: trm105
skipping: trm106
skipping: trm107
skipping: trm108
skipping: trm109
skipping: trm110
skipping: trm111
skipping: trm112
skipping: trm113
skipping: trm114
skipping: trm115
skipping: trm116
skipping: trm117
skipping: trm118
skipping: trm119
skipping: trm400
general_decimal_arithmetic/test_cases/subset_arithmetic/trim0.decTest
decimal32|0|1294|14169|
## Extended Arithmetic

|Type|Passed|Failed|Skipped|
|----|:----:|:----:|:-----:|
# Building

* std::decimal currently requires a C++ 17 compiler. It is built and tested on macOS with Apple Clang from the latest Xcode and on Ubuntu with Clang 10.
* The general_decimal_arithmetic/test_runner requires [boost](https://boost.org). If you don't want to install this just comment it out in the top level CMakeLists.txt
* Check the supplied [Dockerfile](https://github.com/GaryHughes/stddecimal/blob/main/Dockerfile) for detailed build requirements. This is the environment used to build in Github Actions [here](https://github.com/GaryHughes/stddecimal/actions?query=workflow%3ABuild).
# Floating Point Environment

The specification adds the following functions which have been implemented.

```c++
namespace std::decimal {

    int fe_dec_getround();
    int fe_dec_setround(int round);  

}
```

The specification does not add decimal specific exception state functions as [described here](https://en.cppreference.com/w/cpp/numeric/fenv). Because the state functions are opaque and we can't really use them I've introduced a decimal specific set by adding DEC\_ and \_dec\_ to the names as follows.

```c++
namespace std::decimal {

    constexpr fexcept_t FE_DEC_DIVBYZERO;
    constexpr fexcept_t FE_DEC_INEXACT;
    constexpr fexcept_t FE_DEC_INVALID;
    constexpr fexcept_t FE_DEC_OVERFLOW;
    constexpr fexcept_t FE_DEC_UNDERFLOW;
    constexpr fexcept_t FE_DEC_ALL_EXCEPT;

    struct fenv_t;

    int fe_dec_clearexcept(int except);
    int fe_dec_raiseexcept(int except);
    int fe_dec_setexceptflag(const fexcept_t *pflag, int except);
    int fe_dec_getexceptflag(fexcept_t *pflag, int except);
    int fe_dec_testexcept(int except);
    int fe_dec_getenv(fenv_t *penv);
    int fe_dec_setenv(const fenv_t *penv);
    int fe_dec_holdexcept(fenv_t *penv);
    int fe_dec_updateenv(const fenv_t *penv);

}
```

# Extensions

Support has been added for selectively throwing C++ exceptions.

```c++
// Throw std::decimal::exception if any of the exceptions in the except mask are raised.
// NB: Some operations will result in multiple floating point exceptions being raised and
// this will result in a single std::decimal::exception being thrown. The flags property of
/// this exception will include all raised exceptions.
void set_exceptions(int except) noexcept;
// Remove an exceptions in the except mask from the throw list.
void clear_exceptions(int except) noexcept;
// What exceptions have been configured to throw with set_exceptions?
int get_exceptions() noexcept;
// Check the decimal floating point environment exception flags and throw a std:decimal::exception if
// any exceptions have been raised.
// This function is called internally if any exceptions have been enabled with set_exceptions but it
// can also be called manually by the user.
void check_exceptions();
```



```c++
namespace std::decimal {

class exception : public std::exception
{
public:

    exception(fexcept_t flags);
    constexpr fexcept_t flags() const { return m_flags; }
    const char* what() const noexcept override { return m_what.c_str(); }

private:

    fexcept_t m_flags;
    std::string m_what;

};

}

```