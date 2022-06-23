import sys

input_file = sys.argv[1]
output_file = sys.argv[2]

genre_dic = dict()

with open(input_file, "rt") as f :
    for line in f :
        genres = line.strip('\n').split('::')
        list = genres[2].split('|')

        for t in list :
            if t not in genre_dic :
                genre_dic[t] = 1
            else :
                genre_dic[t] += 1
                        
with open(output_file, "wt") as f :
    for k in genre_dic.keys():
        f.write(k + " " + str(genre_dic[k]) + "\n") 
