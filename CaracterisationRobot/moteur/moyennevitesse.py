import os

os.listdir

mesdir="./mesure"

listdir=os.listdir(mesdir)

f=open("mesureMoteur_pwm80.txt","r")
ff=f.readlines()

ff=ff[1:]
m=0
n=0
for i in ff:
    i=float(i)
    m+=i
    n+=1

m=m/(n*5)

print("Moyenne en cm/s :    ",m)