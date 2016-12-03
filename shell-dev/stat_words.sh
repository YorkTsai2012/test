cat words.txt | awk '{ for (i=1; i<=NF; i++) {S[$i]++}} END{for(j in S) {print j,S[j]}} ' | sort -rnk 2
