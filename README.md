
The script is used to summarize the base counts in fasta file.
It outputs the number of A/T/C/G in each sequences in fasta file, 
and calculates the percentage of the four bases.

## INSTALL

Download source file and compile, for example:

```bash
gcc FaATCG -o fatcg
./fatcg test.fasta
```

## OUTPUT

```
# Calculating ATCG in test.fasta.

>ScTTTmV_1	A	6	0.206897
>ScTTTmV_1	T	5	0.172414
>ScTTTmV_1	C	12	0.413793
>ScTTTmV_1	G	6	0.206897
# Number of bases:	29

>ScTTTmV_2	A	5	0.227273
>ScTTTmV_2	T	3	0.136364
>ScTTTmV_2	C	3	0.136364
>ScTTTmV_2	G	11	0.500000
# Number of bases:	22

>ScTTTmV_3	A	7	0.184211
>ScTTTmV_3	T	7	0.184211
>ScTTTmV_3	C	6	0.157895
>ScTTTmV_3	G	18	0.473684
# Number of bases:	38

# --------- Summary -----------
# The number of sequences:	3
# The number of bases:	89
# Total number of A:	18	0.202247
# Total number of T:	15	0.168539
# Total number of C:	21	0.235955
# Total number of G:	35	0.393258

```

The output will be directed into stdin. The output contains the name of sequences in fasta file, base, count, and percentage.

`# Number of bases:	29` is the total number of base, including N etc. 

At the end of output, you can find a summary of the whole fasta file.

For further analysis, using `grep` to create a table which can be directly used in R/Python.

```
./fatcg test.fasta | grep "^>" > final.txt
```