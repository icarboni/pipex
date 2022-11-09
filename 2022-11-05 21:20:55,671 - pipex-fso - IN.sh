2022-11-05 21:20:55,671 - pipex-fso - INFO - command: native: "< infile.txt sed    "s/And/But/" | grep But > outfile.txt", pipex: "./pipex infile.txt 'sed    "s/And/But/"' 'grep But' outfile.txt"
3.KO 
2022-11-05 21:20:55,752 - pipex-fso - INFO - command: native: "< infile.txt sed "s/And/But/" | awk '{count++} END {print count}' > outfile.txt", pipex: "./pipex infile.txt 'sed "s/And/But/"' 'awk '"'"'{count++} END {print count}'"'"'' outfile.txt"
4.KO 
2022-11-05 21:20:55,834 - pipex-fso - INFO - command: native: "< infile.txt sed "s/And/But/" | awk "{count++} END {print count}" > outfile.txt", pipex: "./pipex infile.txt 'sed "s/And/But/"' 'awk "{count++} END {print count}"' outfile.txt"
5.KO 
2022-11-05 21:20:55,923 - pipex-fso - INFO - command: native: "< infile.txt sed "s/And/But/" | awk "{count++} END {printf \"count: %i\" , count}" > outfile.txt", pipex: "./pipex infile.txt 'sed "s/And/But/"' 'awk "{count++} END {printf \"count: %i\" , count}"' outfile.txt"
6.KO 
2022-11-05 21:20:56,014 - pipex-fso - INFO - command: native: "< infile.txt sed "s/And/But/" | awk '{count++} END {printf "count: %i", count}' > outfile.txt", pipex: "./pipex infile.txt 'sed "s/And/But/"' 'awk '"'"'{count++} END {printf "count: %i", count}'"'"'' outfile.txt"
7.KO 
2022-11-05 21:20:56,103 - pipex-fso - INFO - command: native: "< infile.txt ./script.sh | wc > outfile.txt", pipex: "./pipex infile.txt ./script.sh wc outfile.txt"
8.KO 
2022-11-05 21:20:56,263 - pipex-fso - INFO - command: native: "< infile.txt ./"script space.sh" | wc > outfile.txt", pipex: "./pipex infile.txt './"script space.sh"' wc outfile.txt"
9.KO 
2022-11-05 21:20:56,422 - pipex-fso - INFO - command: native: "< infile.txt ./"script\"quote.sh" | wc > outfile.txt", pipex: "./pipex infile.txt './"script\"quote.sh"' wc outfile.txt"
10.KO 
2022-11-05 21:20:56,573 - pipex-fso - INFO - command: native: "< infile.txt ./'script space.sh' | wc > outfile.txt", pipex: "./pipex infile.txt './'"'"'script space.sh'"'"'' wc outfile.txt"
11.KO 
2022-11-05 21:20:56,736 - pipex-fso - INFO - command: native: "< infile.txt /Users/icarboni/francinette/tests/pipex/fsoares/script.sh | wc > outfile.txt", pipex: "./pipex infile.txt /Users/icarboni/francinette/tests/pipex/fsoares/script.sh wc outfile.txt"
12.KO 
2022-11-05 21:20:56,824 - pipex-fso - INFO - command: native: "< no_in cat | wc > outfile.txt", pipex: "./pipex no_in cat wc outfile.txt"
13.KO
