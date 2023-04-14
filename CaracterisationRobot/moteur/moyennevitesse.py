import os
import matplotlib.pyplot as plt
import numpy as np
from scipy import stats as st
os.listdir

mesdir="./CaracterisationRobot/moteur/mesure/"


def mesure_moyene(filepath):
    f=open(filepath,"r")
    ff=f.readlines()
    m=0
    n=0
    mes=[]
    for i in ff:
        i=float(i)
        m+=i
        n+=1
        mes+=[i]
    return [mes , m/(n*int(filepath.split('_')[2].split('-')[0])),int(filepath.split('_')[1].split('-')[1])]

moyene=[mesure_moyene(mesdir+i) for i in os.listdir(mesdir)]

toplote=[[],[],[]]
toplotem=[[],[],[]]
for x in moyene:

    for y in x[0] :
        toplote[0]=toplote[0]+[y]
        toplote[1]=toplote[1]+[x[2]]
        toplote[2]=toplote[2]+[(0,0,1)]
for x in moyene:
    toplotem[0]=toplotem[0]+[x[1]]
    toplotem[1]=toplotem[1]+[x[2]]
    toplotem[2]=toplotem[2]+[(1,0,0)]

a, b, r, p, err = st.linregress(toplotem[1],toplotem[0])
def regress(x):
    return a*np.array(x)+b

fig,ax=plt.subplots(2,1)
ax[0].scatter(toplote[1],toplote[0],8,toplote[2])
ax[0].set_xlabel("pwm")
ax[1].scatter(toplotem[1],toplotem[0],32,toplotem[2])
ax[1].plot([75,145],regress([75,145]))
ax[1].set_xlabel("pwm")

plt.savefig(f'./CaracterisationRobot/moteur/autoplot_{a}_{b}.png')
