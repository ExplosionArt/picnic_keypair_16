<?xml version="1.0" encoding="UTF-8"?>
<project xmlns="com.autoesl.autopilot.project" name="picnic1" top="crypto_sign_keypair">
  <files>
    <file name="../../newtest_sign_2.c" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" blackbox="false" csimflags=" -Wno-unknown-pragmas"/>
    <file name="tree.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="NIST-KATs/rng.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="picnic_types.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="picnic_impl.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="picnic2_impl.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="picnic.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="lowmc_constants.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="hash.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="api.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="NIST-KATs/aes.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="sha3/KeccakSpongeWidth1600.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="sha3/KeccakP-1600-reference.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
    <file name="sha3/KeccakHash.c" sc="0" tb="false" cflags="" blackbox="false" csimflags=""/>
  </files>
  <solutions>
    <solution name="keypair" status="active"/>
  </solutions>
  <includePaths/>
  <libraryPaths/>
  <Simulation>
    <SimFlow askAgain="false" name="csim" clean="true" csimMode="2" lastCsimMode="2"/>
  </Simulation>
</project>
