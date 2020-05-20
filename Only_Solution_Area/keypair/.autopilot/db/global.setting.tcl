
set TopModule "crypto_sign_keypair"
set ClockPeriod 10
set ClockList ap_clk
set HasVivadoClockPeriod 0
set CombLogicFlag 0
set PipelineFlag 0
set DataflowTaskPipelineFlag 1
set TrivialPipelineFlag 0
set noPortSwitchingFlag 0
set FloatingPointFlag 0
set FftOrFirFlag 0
set NbRWValue 0
set intNbAccess 0
set NewDSPMapping 1
set HasDSPModule 0
set ResetLevelFlag 1
set ResetStyle control
set ResetSyncFlag 1
set ResetRegisterFlag 0
set ResetVariableFlag 0
set FsmEncStyle onehot
set MaxFanout 0
set RtlPrefix {}
set ExtraCCFlags {}
set ExtraCLdFlags {}
set SynCheckOptions {}
set PresynOptions {}
set PreprocOptions {}
set SchedOptions {}
set BindOptions {}
set RtlGenOptions {}
set RtlWriterOptions {}
set CbcGenFlag {}
set CasGenFlag {}
set CasMonitorFlag {}
set AutoSimOptions {}
set ExportMCPathFlag 0
set SCTraceFileName mytrace
set SCTraceFileFormat vcd
set SCTraceOption all
set TargetInfo xc7a200t:-fbg676:-2
set SourceFiles {sc {} c {../../sha3/KeccakHash.c ../../sha3/KeccakP-1600-reference.c ../../sha3/KeccakSpongeWidth1600.c ../../NIST-KATs/aes.c ../../api.c ../../hash.c ../../lowmc_constants.c ../../picnic.c ../../picnic2_impl.c ../../picnic_impl.c ../../picnic_types.c ../../NIST-KATs/rng.c ../../tree.c}}
set SourceFlags {sc {} c {{} {} {} {} {} {} {} {} {} {} {} {} {}}}
set DirectiveFile C:/picnic_keypair_16-master/project16-Optimized_Area/picnic1/keypair/keypair.directive
set TBFiles {verilog ../../newtest_sign_2.c bc ../../newtest_sign_2.c vhdl ../../newtest_sign_2.c sc ../../newtest_sign_2.c cas ../../newtest_sign_2.c c {}}
set SpecLanguage C
set TVInFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TVOutFiles {bc {} c {} sc {} cas {} vhdl {} verilog {}}
set TBTops {verilog {} bc {} vhdl {} sc {} cas {} c {}}
set TBInstNames {verilog {} bc {} vhdl {} sc {} cas {} c {}}
set XDCFiles {}
set ExtraGlobalOptions {"area_timing" 1 "clock_gate" 1 "impl_flow" map "power_gate" 0}
set TBTVFileNotFound {}
set AppFile ../vivado_hls.app
set ApsFile keypair.aps
set AvePath ../..
set DefaultPlatform DefaultPlatform
set multiClockList {}
set SCPortClockMap {}
set intNbAccess 0
set PlatformFiles {{DefaultPlatform {xilinx/artix7/artix7 xilinx/artix7/artix7_fpv6}}}
set HPFPO 0
