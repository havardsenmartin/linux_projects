# Bli kjent med kondensatoren
## Oppgave 1
![[Pasted image 20261025130150.png|420]]

| ${}S_{1}{}$ | ${}S_{2}{}$ | ${}D_{1}{}$                 | ${}D_{2}{}$                         |
| ----------- | ----------- | --------------------------- | ----------------------------------- |
| 1           | 1           | Svakt konstant lys konstant | Svakt konstant lys konstant         |
| 0           | 0           | går av                      | går av                              |
| 1           | 0           | svak puls                   | av                                  |
| 0           | 1           | av                          | svak puls (dersom ${}C{}$ er ladet) |

## Oppgave 2

| ${}v_\text{C} \text{ [V] }{}$ | ${}t \text{ [s] }{}$ |
| ----------------------------- | -------------------- |
| 0.4                           | 0                    |
| 3                             | 3                    |
| 5                             | 6                    |
| 7                             | 10                   |
| 8                             | 16                   |
| 9                             | 24                   |
| 9.95                          | 65                   |


| V   | t   |
| --- | --- |
| 9.1 | 0   |
| 7   | 3   |
| 5.5 | 5   |
| 4   | 9   |
| 3   | 13  |
| 2   | 17  |
| 1   | 23  |
| 0.5 | 24  |
| 0.2 | 47  |
| 0.1 | 60  |
```
%matplotlib inline

import numpy as np
import matplotlib.pyplot as plt

RESISTANCE = 100000 # 100 k ohm

def I(v):
    V_R=10-v
    return V_R / RESISTANCE

def der(V, T):
    Vder = np.array([])
    for i in range(len(T)-1):
        Vder = np.append(Vder, (V[i+1]-V[i])/(T[i+1]-T[i]))
    return np.append(Vder,Vder[-1]), T


V = np.array([
    0.4,
    3,
    5,
    7,
    8,
    9,
    9.95
])

T = np.array([
    0,
    3,
    6,
    10,
    16,
    24,
    65
])

I_C = I(V) * 100000 # strøm i 10*µA
print(I_C)

V_der, T_for_der = der(V,T)
V_der *= 10

plt.plot(T_for_der, V_der, label="Vprime")
plt.plot(T,V, label="V")
plt.plot(T,I_C, label="I_C")
plt.xlabel("tid")
plt.ylabel("spenning, V_c ELLER strøm x10µA")
plt.legend()
plt.show(
```

![[Pasted image 20261025165732.png]]



```
%matplotlib inline

import numpy as np
import matplotlib.pyplot as plt

RESISTANCE = 100000 # 100 k ohm

def I(v):
    return -v/RESISTANCE

V = np.array([
    9.1,
    7,
    5.5,
    4,
    3,
    2,
    1,
    0.5,
    0.2,
    0.1
])

T = np.array([
    0,
    3,
    5,
    9,
    13,
    17,
    23,
    24,
    47,
    60
])

I_C = I(V) * 1000000 # strøm i µA
print(I_C)


plt.plot(T,V, label="V")
plt.plot(T,I_C, label="I_C")
plt.xlabel("tid")
plt.ylabel("spenning, V_c")
plt.legend()
plt.show()
```

![[Pasted image 20261025165926.png]]

## Oppgave 3
Det ligner en ${}\ln (x+c){}$ funksjon.
1. Når ${}S_{2}{}$ er lukket er ${}I_\text{C}>0{}$ og kondensatoren *gir* energi. 
2. Når ${}S_{1}{}$ er lukket derimot, er ${}I_\text{C}<0{}$ og kondensatoren *får* energi.
### Begrunnelse for 2. punkt:
Vi bruker data fra ${}t=9\text{ s }{}$. Da var spenningen over kondensatoren ${}V_\text{C}=4\text{ V }{}$. Spenningkilden har konstant ${}V=10\text{ V }{}$ så spenningen over motstanden (plussiden nærmest spenningskilden) blir
$$
V_\text{R}= V - V_\text{C} = 10-4=6\text{ V } 
$$
Dermed blir strømmen i kretsen ${}I_\text{C}{}$ gitt ved
$$
I_\text{C}= \frac{V_\text{R}}{R_{1}}= \frac{6}{100\text{ k } }= 6\cdot 10^{-5}=60\text{ µA }
$$
Viktigst er å merke at strømmen går *inn* plussiden på kondensatoren. Vi regner energitap per komponent
$$
P_\text{spenningskilde}=(-10\text{ V } )\cdot 60\text{ µA } \\
P_\text{motstand}=\frac{6}{(100 \text{ k })^{2} } \\
P_\text{kondensator} = 3\text{ V } \cdot 60\text{ µA }
$$
Det er *kun* spenningskilden som *gir*, mens motstanden og kondensatoren *bruker* energi.
# Kondensatoren i modelldomenet
## Oppgave 4

> Hjelpehefte:
> I figuren har me og teke med ein pneumatisk analogi. Tenk på kondensatoren som to tankar
som er fylde med luft. Ei pumpe pumpar luft frå den eine tanken til den andre, slik at det vert
overtrykk i den eine og undertrykk i den andre. På tilsvarande måte vil spenningskjelda laga ein
straum som gjev overskot av ladning i den eine halvparten av kondensatoren (merka med pluss)
og underskot (minus) i den andre.
>Tenk fyrst på pumpa. Kor mykje luft vil pumpa totalt greie å flytta frå den nedre til den
øvre tanken? I starten vert mykje luft flytta, men ettersom trykket stig i den øvre tanken, vil
dette motverka pumpa sitt arbeid. Dermed vil pumpa flytta mindre og mindre luft heilt til trykk-
skilnaden fullstendig kansellerer det pumpa prøver på. Ei kraftig pumpe vil greia å flytta meir
luft (stå imot ein større trykkskilnad) enn ei svakare. I tillegg kjem det sjølvsagt an på kor store
tankane er. Di større tankar, di større luftmengd vil pumpa greia å flytta før ho lyt gje seg.
Med kondensatoren og spenningskjelda er det noko av det same. Det er grenser for kor stor lad-
ningsskilnad spenningskjelda kan oppretthalda. Spenninga V til spenningskjelda tilsvarar pumpe-
evena til pumpa. Di større spenning V, di større ladningsmengd Q vil verta flytta frå den nedre
delen av kondensatoren til den øvre. Men me har og ein analogi mellom kondensatoren og tan-
kane. Dersom me tenkjer på kondensatoren som to leiande plater isolerte frå kvarandre, er det
slik at di større areal platene har, di meir lading har kondenstoeren “plass til”. Denne evna til å
halda på ladningsskilnad kallast kondensatoren sin kapasitans C og er anlaogt til lufttankane sin
storleik. Kapasitansen aukar og med minkande avstand mellom platene, og er og påverka av kva
type isolasjon det er mellom dei.
I elektromagnetismen vil ein kunne visa at det er ein proporsjonalitet mellom lagra ladning Q
og spenninga V gjeve ved
> $$
Q=C\cdot V
 $$
>(15.2)
>Det å etablera eit slikt over/underskot av ladning på ein kondensator kallast å lada konden-
satoren. Med ein kjend verdi på C er det ein eintydig samanheng mellom ladning og spenning,
og i staden for å snakka om ladninga som er lagra, seier me heller at kondensatoren er lada med
spenninga V.

*Elementloven* samsvarer fint med målingene mine.

## Oppgave 5
### a)
$$
v(t)=V_{0}\cos(2\pi ft)
$$
Kondensatorstrømmen blir da
$$
i(t)=C \frac{d v(t)}{d t} =-2\pi fV_{0}\sin(2\pi ft)
$$
### b)
$$
v(t)=V_{0} \quad\quad(\text{konstant})
$$
Dermed blir strømmen ${}0{}$
$$
i(t)=\frac{d v(t)}{d t} =0\text{ A } 
$$

## Oppgave 6
> Ved bruk av kondensatorens elementlov gitt ved Ligning (1) sammen med Ohms lov (resisto-
> rens elementlov) og Kirchhoffs spenningslov kan du finne matematiske uttrykk som modellerer
> tidsforløpene for kondensatorspenning og -strøm som du har målt i Oppgave 2.

![[Pasted image 20261025170636.png]]
La ledningene høyre i bildet være ukoblet. La ${}v_\text{R}{}$ være spenning over motstanden (med plussiden nærmest spenningskilden).
#### KVL
$$
V = v_\text{C}+v_\text{R}
$$
#### Kondensatorens elementlov
$$
i_\text{C}=C \frac{d v_\text{C}}{d t} 
$$
#### Ohms lov
$$
v_\text{R}=i_\text{C}\cdot R_{1}
$$
Vi får 
$$
v_\text{R}=C R_{1} \frac{d v_\text{C}}{d t} 
$$
$$
V = CR_{1}\frac{d v_\text{C}}{d t}+v_\text{C}
$$

> [!info]
> $\tau \frac{d x}{d t} +x=k$>
> har løsning
> $x(t)=k+[x(0)-k]e^{ -t/\tau }$
 
Så ${}v_\text{C}{}$ vil ha form
$$
v_\text{C}=k+[v_{0}-k]e^{ -t/\tau }
$$
for konstanter ${}k,\tau{}$ og konstantledd ${}v_{0}{}$.
Vi ser at ${}\tau=CR_{1}{}$ og ${}k=V{}$. Så
$$
v_\text{C}=V+[v_{0}-V]e^{ -t/CR_{1} }
$$
## Oppgave 7
### Uttrykk for ${}v_\text{C}{}$ og ${}i_\text{C}{}$
La ${}v_{0}=0{}$.
$$
\begin{aligned}
v_\text{C}&=V+[0-V]e^{ -t/CR_{1} } \\
 & =V(1-e^{ -t/CR_{1} })
\end{aligned}
$$
#### Elementloven
$$
i_\text{C}=C\frac{d v_\text{C}}{d t}
$$
så
$$
\begin{aligned}
i_\text{C}&=VC\cdot \frac{d }{d t} (-e^{ -t/CR_{1} }) \\
 & =VC\cdot\left( -\frac{1}{CR_{1}} \right)(-e^{ -t/CR_{1} }) \\
 & =\frac{V}{R_{1}}e^{ -t/CR_{1} }
\end{aligned}
$$
### Verdier ved ${}t=0{}$ og ${}t\to \infty{}$
$$
\begin{cases}
v_\text{C}=0 & \text{ved }t=0 \\
v_\text{C}=V & \text{ved }t\to \infty
\end{cases}
$$
$$
\begin{cases}
i_\text{C}=\frac{V}{R_{1}} & \text{ved }t=0 \\
i_\text{C}=0 & \text{ved }t\to \infty
\end{cases}
$$
## Oppgave 8
### Finner uttrykk
![[Pasted image 20261025173009.png]]
Anta at ledninge til venstre er ukoblet. ${}i_{2}=i_\text{C}{}$.
$$
i_\text{C}=\frac{v_\text{C}}{R_{2}}
$$
$$
C\frac{d v_\text{C}}{d t} =\frac{v_\text{C}}{R_{2}}
$$
La ${}\tau=R_{2}C{}$.
$$
\frac{d v_\text{C}}{d t} =\frac{1}{\tau}v_\text{C}
$$
La ${}v_\text{C}=e^{ kt }+v_{0}{}$, der ${}k{}$ er en konstant.
$$
kt \cdot e^{ kt } = \frac{1}{\tau} (e^{ kt }+v_{0})
$$
$$
\tau kt\cdot e^{ kt }-e^{ kt }=v_{0}
$$
$$
e^{ kt }(\tau kt-1)=v_{0}
$$

---
$$
\frac{d v_\text{C}}{d t}=\frac{1}{\tau}v_\text{C} 
$$
gang med ${}dt{}$
$$
dv_\text{C}=\frac{1}{\tau}v_\text{C}dt
$$
$$
\frac{1}{v_\text{C}}dv_\text{C}=\frac{1}{\tau}dt
$$
Integrer begge sider
$$
\int \frac{1}{v_\text{C}}dv_\text{C}=\int\frac{1}{\tau}dt
$$
$$
\ln\left| v_\text{C} \right| =\frac{t}{\tau}+C
$$
Anta ${}v_\text{C}\geq0{}$
$$
\ln v_\text{C}=\frac{t}{\tau}+C
$$
$$
v_\text{C}=e^{ t/\tau+C }
$$
${}C{}$ er da konstantleddet, startspenningen.
$$
v_\text{C}=e^{ t/\tau }+v_{0}
$$

*Nå begynner vi på ${}i_\text{C}{}$*
$$
\begin{aligned}
i_\text{C}&=C \frac{d v_\text{C}}{d t}  \\
& = \frac{1}{R_{2}} e^{ t/\tau }
\end{aligned}
$$

### Finner verdier




















