# aho-corasick-string-matching
- Aho-Corasick algorithm C implementation
- only for 7-bits ASCII

#### Usage
execute make:
```python
$ make
# print
# gcc -g -Wall -std=gnu99 -c main.c
# gcc -g -Wall -std=gnu99 -c Node.c
# gcc -g -Wall -std=gnu99 -c NodeQueueOperation.c
# gcc -g -Wall -std=gnu99 -c AhoCorasick.c
# gcc -o a.out main.o Node.o NodeQueue.o NodeQueueOperation.o AhoCorasick.o RawOperation.o
```
The first argument is the pattern file,
and the second argument is the content to be searched:
```python
$ ./a.out ./testcase/pattern1.txt ./testcase/content1.txt
# print
#  - Reading pattern file ...
#
#  - Total 4 patterns:
#  - Reading pattern file succeed.
# 
#    - he
#    - she
#    - his
#    - hers
# 
#  - Reading content file ...
# 
#  - Reading content file succeed.
# 
#  - Content:
#    - ushers
# 
# 
#  - find she at position 2 ~ 4
#  - find he at position 3 ~ 4
#  - find hers at position 3 ~ 6
```
more patterns, and longer content:
```python
$ ./a.out ./testcase/pattern3.txt ./testcase/content3.txt
#  print
#  - Reading pattern file ...
# 
#  - Total 15 patterns:
#  - Reading pattern file succeed.
# 
#    - microsome
#    - cytochrome
#    - cytochrome P450 activity
#    - ibberellic acid biosynthesis
#    - GA3
#    - cytochrome P450
#    - oxygen binding
#    - AT5G25900.1
#    - protein
#    - RNA
#    - gibberellin
#    - Arabidopsis
#    - ent-kaurene oxidase activity
#    - inflorescence
#    - tissue
# 
#  - Reading content file ...
# 
#  - Reading content file succeed.
# 
#  - Content:
#    - The ga3 mutant of Arabidopsis is a gibberellin-responsive dwarf. We present data 
# showing that the ga3-1 mutant is deficient in ent-kaurene oxidase activity, the first 
# cytochrome P450-mediated step in the gibberellin biosynthetic pathway. By using a combination
# of conventional map-based cloning and random sequencing we identified a putative cytochrome
# P450 gene mapping to the same location as GA3. Relative to the progenitor line, two ga3 mutant 
# alleles contained single base changes generating in-frame stop codons in the predicted amino 
# acid sequence of the P450. A genomic clone spanning the P450 locus complemented the ga3-2 mutant.
# The deduced GA3 protein defines an additional class of cytochrome P450 enzymes. The GA3 gene 
# was expressed in all tissues examined, RNA abundance being highest in inflorescence tissue.
# 
#  - find Arabidopsis at position 19 ~ 29
#  - find gibberellin at position 36 ~ 46
#  - find ent-kaurene oxidase activity at position 128 ~ 155
#  - find cytochrome at position 168 ~ 177
#  - find cytochrome P450 at position 168 ~ 182
#  - find gibberellin at position 205 ~ 215
#  - find cytochrome at position 343 ~ 352
#  - find cytochrome P450 at position 343 ~ 357
#  - find GA3 at position 396 ~ 398
#  - find GA3 at position 652 ~ 654
#  - find protein at position 656 ~ 662
#  - find cytochrome at position 695 ~ 704
#  - find cytochrome P450 at position 695 ~ 709
#  - find GA3 at position 724 ~ 726
#  - find tissue at position 754 ~ 759
#  - find RNA at position 772 ~ 774
#  - find inflorescence at position 803 ~ 815
#  - find tissue at position 817 ~ 822
```
