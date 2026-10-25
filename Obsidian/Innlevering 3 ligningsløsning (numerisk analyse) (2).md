> [!information] Newtons metode
> Newtons metode leter etter nullpunkter til funksjonen $f(x)$. Den er gitt ved
> 
> $$
 a_{n+1} = a_n - \frac{f(a_n)}{f'(a_n)}
$$

> [!question] ## Oppgave
> Løs likningen $\theta = \cos \theta$ med Newtons metode.
> Spiller initialverdien $a_0$ noen rolle i iterasjonen? Hvor mange iterasjoner trengs for å nå presisjonen $10^{-12}$? 
> Bruk gjerne Jupyter notebook-en om Newtons metode.^[Jeg fant ikke noen Jupyter notebook om Newtons metode.]

#### Steg 1

Newtons metode finner nullpunkter. Dermed trenger vi en funksjon som har nullpunkter ved løsninger av ligningen.
##### Eksempel
$$
f(\theta)=\theta-\cos\theta
$$
La oss bruke denne definisjonen.
#### Steg 2
Newtons metode er gitt ved
$$
 \theta_{n+1} = \theta_n - \frac{f(\theta_n)}{f'(\theta_n)}
$$
Vi finner ${}f'{}$,
$$
f'(\theta)=1+\sin\theta
$$
så
$$
 \theta _{n+1} = \theta_n - \frac{\theta-\cos\theta}{1+\sin\theta}
$$


#### Mål
La ${}n{}$ være mengde iterasjoner, ${}\theta_{0}{}$ initialverdi og ${}\epsilon(n,\theta_{0}){}$ error etter ${}n{}$ iterasjoner. Vi ønsker
$$
\epsilon(n,\theta_{0}) \leq 10^{-12}
$$
som vi da kan prøve å løse for ${}n{}$.

**For eksempel kan vi få**
$$
n = g(\epsilon_{0},\theta_{0})
$$
som i [[I3TMA4400 informert svar]].


# Etter hint fra *Claude*
> [!info] ### Nøkkelinnsikten
> 
> Newtons metode er $\theta_{n+1}=N(\theta_n)$ med
> 
> $$N(\theta)=\theta-\frac{f(\theta)}{f'(\theta)}$$
> 
> Altså: samme verktøykasse, med $N$ i stedet for $f$. Det du trenger å finne ut, er hva $N'(r)$ er.

La ${}N(\theta)=\theta- \frac{f(\theta)}{f'(\theta)}{}$ . La følgen ${}\{ \theta_{n} \}_{n=0}^{\infty}{}$ være gitt ved
$$
\theta_{n+1}=N(\theta_{n})
$$
og
$$
N(\theta)=\theta- \frac{\theta-\cos\theta}{1+\sin\theta}
$$
*Hvor er ${}N{}$ kontinuerlig?* 
${}N{}$ er kontinuerlig når ${}\frac{f(\theta)}{f'(\theta)}{}$ er kontinuerlig. ${}\frac{f(\theta)}{f'(\theta)}{}$ er kontinuerlig når teller og nevner er kontinuerlig. Siden ${}f(\theta)=\theta-\cos\theta{}$ er kontinuerlig overalt og ${}f'(\theta)=1+\sin\theta{}$ er kontinuerlig overalt, har vi vist nødvendig kontinuitet.
La grenseverdien r eksistere og oppfylle
$$
r = \lim_{ n \to \infty } \theta_{n}
$$
Da vil ${}r{}$ være et *fikspunkt*,
$$
N(r) = r
$$
##### Det viktige verktøyet fra beviset av *Teorem 2*
>Beviset er basert på middelverdisetningen. Legg merke til at
>
>$$a_{n+1}-r=f(a_n)-f(r)=f'(\xi_n)(a_n-r),\qquad \text{for en $\xi_n$ mellom $a_n$ og $r$.}$$
>
>Dette gir at 
>
>$$|a_{n+1}-r|=|f'(\xi_n)||a_n-r|.$$

La error, ${}e_{n}=\left| \theta_{n}-r \right|{}$. Da blir siste ligning i sitatet over
$$
e_{n+1}=\left| f'(\xi_{n})\right| e_{n} \quad \xi \in(\theta_{n}, r)
$$
Betingelsene for teoremet er at ...
- ${}N'(\theta){}$ er kont. på intervall ${}I=(r-d,r+d){}$
- det finnes et tall ${}\alpha<1{}$, ${}\left| N'(\theta) \right|\leq\alpha{}$ for alle ${}x \in I{}$
- initialverdien oppfyller: ${}\theta_{0} \in I{}$

Betingelse 2 kan brukes til å begrense ${}e_{n+1}{}$,
$$
e_{n+1}\leq\alpha e_{n}
$$
==NOTE TO SELF== : prøv å bruk uttrykket over rekursivt for å få noe lignende
$$
e_{n}\leq\alpha^{q(n)}e_{0} \quad \text{der }q \text{ er funksjon av } n
$$
$$
\begin{aligned}
e_{n}&\leq\alpha e_{n-1} \\
e_{n-1}&\leq\alpha e_{n-2} \\
e_{n-2}&\leq\alpha e_{n-3} \\
e_{n-3}&\leq\alpha e_{n-4} \\
&\dots \\
e_{2} &\leq\alpha e_{1} \\
e_{1} &\leq\alpha e_{0}
\end{aligned}
$$
Merk at ${}0<\alpha<1{}$. Vi multipliserer med ${}\alpha{}$,
$$
\begin{aligned}
e_{1}&\leq\alpha e_{0}\\
e_{1}\alpha&\leq\alpha^{2}e_{0}
\end{aligned}
$$
så
$$
e_{2}\leq e_{1}\alpha\leq\alpha^{2}e_{0}\\
e_{2}\leq\alpha^{2}e_{0}
$$
Slik fortsetter vi opp til ${}n{}$. **Til slutt:**
$$
e_{n}\leq\alpha^{n}e_{0}
$$
#### Vi anvender ${}e_{n}\leq\alpha^{n}e_{0}{}$
For å kunne bruke resultatet vi fikk, må betingelsene oppfylles.
![[Pasted image 20261024114635.png]]
Graf av ${}N(\theta)=\theta- \frac{\theta-\cos\theta}{1+\sin\theta}{}$.
Punktet ${}(r,N(r)){}$ er vist ved krysningen. Vi velger da et intervall som inneholder krysningen.
> **Bemerkning.**
> Den eneste grunnen til at vi krevde at intervallet $I$ er symmetrisk rundt $r$ er at vi da kan være sikker på at alle $a_n$ er i intervallet. Vi kan bruke vilkårlige åpne intervaller $I$ med $r \in I$ hvis vi passer på at følgen $(a_n)_{n=0}^\infty$ holder seg i $I$.

La ${}I=\left[ 0.4,1.2 \right]{}$. Det er da nødvendig å vise at alle ${}\theta_{n} \in I{}$. Vi trenger kun å gjøre dette for 1 initialverdi, men første prøver vi for alle.
**Først en kjapp numerisk sjekk**
```
import numpy as np
def N(t):
    return t - (t-np.cos(t))/(1+np.sin(t))

X = np.linspace(0.4,1.2,1000)

print("Sjekker N(t)")
print("...")
for t in X:
    if 1.2<N(t)<0.4:
        print(f"en utenfor {t}")
print("...")
print("Ferdig!")
```
Som gir:
```
Sjekker N(t)
...
...
Ferdig!
```
**Vi har nå numerisk grunnlag for å prøve dette intervallet videre**.
La dette numeriske grunnlaget være nok for nå. Første betingelse er da oppfylt. Nå må vi finne et tall ${}\alpha<1{}$, ${}\left| N'(\theta) \right|\leq \alpha{}$ for alle ${}x \in I{}$.
$$
N'(\theta)=\frac{d }{d \theta}\left( \theta- \frac{\theta-\cos\theta}{1+\sin\theta} \right) 
$$
$$
\begin{aligned}
&= 1 - \frac{(\theta-\cos\theta)'(1+\sin\theta)-(\theta-\cos\theta)(1+\sin\theta)'}{(1+\sin\theta)^{2}}\\
&= 1 - \frac{(1+\sin\theta)(1+\sin\theta)-(\theta-\cos\theta)(\cos\theta)}{(1+\sin\theta)^{2}}\\
&= 1-1 + \frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}}\\
&= \frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}}\\
\end{aligned}
$$

![[Pasted image 20261024132814.png|1200]]
*Graf av ${}N'(\theta)=- \frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}}{}$.*
${}\theta{}$ ligger i første kvadrant, ${}0<\theta< \frac{\pi}{2}{}$. Så ${}0<\cos\theta<1{}$ og ${}0<\sin\theta<1{}$.
Ekvivalent,
$$
1<1+\sin\theta<2\\
1<(1+\sin\theta)^{2}<4
$$
og,
$$
0<\cos ^{2}\theta<1 \\
0<\cos ^{2}\theta<\cos\theta \\
0<\theta\cos ^{2}\theta<\theta\cos\theta
$$
og til slutt,
$$
0<\theta \cos\theta<\theta
$$
Vi ønsker
$$
\left| \frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}}  \right| <\alpha<1
$$
$$
\iff
\frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}} <\alpha<1 \quad \land\quad
\frac{-\theta \cos\theta+\cos ^{2}\theta}{(1+\sin\theta)^{2}} < \alpha<1
$$
Vi bruker ulikhetene til å forenkle. Målet er da å finne et uttryk *større* enn ${}-N'(\theta),N'(\theta){}$ som vi kan enkelt vise er *mindre* enn ${}1{}$.
$$
\frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}}<
  \frac{\text{mulig større uttrykk}}{\text{mulig mindre uttrykk}}
$$

$$
2a^{2}>\left| a \right| \quad\text{der } a\neq 0 
$$
$$
\left| a+b \right| \leq \left| a \right| +\left| b \right|
$$

$$
\left| \frac{\theta \cos\theta-\cos ^{2}\theta}{(1+\sin\theta)^{2}} \right| 
\leq \left| \frac{\theta \cos\theta}{(1+\sin\theta)^{2}} \right|+\left| \frac{\cos ^{2}\theta}{(1+\sin\theta)^{2}} \right|
$$

$$
\left| \frac{\theta \cos\theta}{(1+\sin\theta)^{2}} \right|+\left| \frac{\cos ^{2}\theta}{(1+\sin\theta)^{2}} \right| = \frac{\theta \cos\theta}{(1+\sin\theta)^{2}}+ \frac{\cos ^{2}\theta}{(1+\sin\theta)^{2}}\\
= \frac{\theta \cos\theta+\cos ^{2}\theta}{(1+\sin\theta)^{2}}
$$
$$
= \frac{\theta \cos\theta+\cos ^{2}\theta}{\sin ^{2}\theta+2\sin\theta+1}
$$
$$
\leq \frac{\theta \cos\theta+\cos\theta}{\sin ^{2}\theta+2\sin\theta+1}\\ \\
=
\frac{(\theta+1)\cos\theta}{\sin ^{2}\theta+2\sin\theta+1}\\
$$
**Currently working here ↑↑↑↑**

---

> [!information] dobbel vinkel identitet
>$$
>\cos(2\theta)=\cos ^{2}\theta-\sin ^{2}\theta \\
>\cos(2\theta)=2\cos ^{2}\theta-1 \\
>\cos ^{2}\theta= \frac{\cos(2\theta)+1}{2}
>$$

#### Jeg er usikker. Dette tar for lang tid
> [!tip] ###### Random tanke
> $$
> \theta \cos\theta=\cos ^{2}\theta
> $$
> Dette vil kun gjelde dersom vi har nådd fikspunktet. Siden,
> $$
> \theta=\cos\theta \quad\text{dersom } \cos\theta\neq 0
> $$
> *Vi er på rett spor*































