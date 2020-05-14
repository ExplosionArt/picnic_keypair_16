<project xmlns="com.autoesl.autopilot.project" name="picnic1" top="crypto_sign_keypair">
    <includePaths/>
    <libraryPaths/>
    <Simulation>
        <SimFlow askAgain="false" name="csim" clean="true" csimMode="2" lastCsimMode="2"/>
    </Simulation>
    <files xmlns="">
        <file name="../../newtest_sign_2.c" sc="0" tb="1" cflags=" -Wno-unknown-pragmas" csimflags=" -Wno-unknown-pragmas" blackbox="false"/>
        <file name="sha3/KeccakHash.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="sha3/KeccakP-1600-reference.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="sha3/KeccakSpongeWidth1600.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="NIST-KATs/aes.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="api.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="hash.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="lowmc_constants.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="picnic.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="picnic2_impl.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="picnic_impl.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="picnic_types.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="NIST-KATs/rng.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
        <file name="tree.c" sc="0" tb="false" cflags="" csimflags="" blackbox="false"/>
    </files>
    <solutions xmlns="">
        <solution name="keypair" status="active"/>
    </solutions>
</project>

