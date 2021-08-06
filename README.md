# RAxML
# Language: C++
# Input: TXT
# Output: SUFFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: RAxML 8.2

PluMA plugin to generate trees with Randomized Axelerated Maximum Likelihood (Stamatkis, 2014).

Input is a TXT file of keyword-value pairs:
inputfile: Input FFN file
model: Model used (i.e. GTRCAT)
seed: Random number seed

Trees will be generated using the user-specified output suffix.
