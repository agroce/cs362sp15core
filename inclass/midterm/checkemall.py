import glob
import subprocess

for f in glob.glob("mutant*.c"):
    cmd = "rm -rf outf; gcc -o tester countshortmut.c " + f
    subprocess.call([cmd], shell=True)
    subprocess.call(["./tester >& outf"], shell=True)
    numMismatches = 0
    for l in open("outf"):
        if "MISMATCH" in l:
            numMismatches += 1
    print "MUTANT:",f," : MISMATCHES =",numMismatches
