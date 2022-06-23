import sys
import datetime

input_file = sys.argv[1]
output_file = sys.argv[2]

def get_day(month, date, year) :
    r = ['MON', 'TUE', 'WED', 'THU', 'FRI', 'SAT', 'SUN']
    return r[datetime.date(int(year), int(month), int(date)).weekday()]

dict = dict()

with open(input_file, "rt") as f :
    for line in f :
        list = line.strip('\n').split(',')

        day_list = list[1].split('/')
        key = list[0] + "," + get_day(day_list[0], day_list[1], day_list[2])
   
        if key not in dict :
            dict[key] = list[2] + "," + list[3]
        else :
            t_list = dict[key].split(',')
            tmp_1 = int(t_list[0]) + int(list[2]) 
            tmp_2 = int(t_list[1]) + int(list[3])
            dict[key] = str(tmp_1) + "," + str(tmp_2)

with open(output_file, "wt") as f :
    for k in dict.keys() :
        f.write(k + " " + dict[k] + "\n")
