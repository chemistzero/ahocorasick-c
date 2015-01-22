# aho-corasick-string-matching

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
and the second argument is content to be checked.
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
