[[ERT16 Op-ampens gyldne regler]]


Given $v_i$ = 2

| R1  | R2  | v_max |
| --- | --- | ----- |
| 2   | 1   | 3/2   |
| 2   | 4   | 3     |
| 4   | 4   | 2     |
| 4   | 2   | 3/2   |
| 8   | 2   | 5/4   |

Konklusjon, $R1\cdot R2$ bestemmer $v_{max}$

### Spenningsdeling
Husk formelen
$$
v = V \frac{R_1}{R_1+R_2}
$$

La oss sjekke

$$
\frac{1}{2+1} = 1/3
$$

$$
\frac{2}{2+1} = 2/3
$$

$$
\frac{2+8}{8}=\frac{10}{8}=5/4
$$

### Conjecture
$$
v_0 = v_1 \frac{\max \{R_1, R_2\}}{R_1+R_2}
$$
Med vekselstrøm.


### Oppgave 4a)

$$
v_{0}=\frac{1}{\frac{1}{A}+\frac{R_{1}}{R_{1}+R_{2}}}v_{i}
$$

$$
v_{0}\left( \frac{1}{A}+\frac{R_{1}}{R_{1}+R_{2}} \right)=v_{i}
$$
![[Pasted image 20261021205806.png|568]]
La ${}I_{\text{out}}{}$ være strømmen ut opampen.
Husk at 
$$
v_{0} = A(v_{i}-v_{\text{-}})
$$

$$
v_{\text{-}}=v_{0}\cdot \frac{R_{1}}{R_{1}+R_{2}}
$$

$$
\therefore v_{0}=A\left( v_{i}-v_{0}\cdot \frac{R_{1}}{R_{1}+R_{2}} \right)
$$

$$
v_{0} = Av_{i} - Av_{0}\cdot \frac{R_{1}}{R_{1}+R_{2}}
$$

$$
v_{0}\left( 1+A\cdot \frac{R_{1}}{R_{1}+R_{2}} \right)=Av_{i}
$$

$$
v_{0} = \frac{Av_{i}}{1+A\cdot \frac{R_{1}}{R_{1}+R_{2}}}
$$

$$
v_{0}=\frac{1}{\frac{1}{A}+\frac{R_{1}}{R_{1}+R_{2}}}v_{i}
$$

$$
\text{QED}
$$

$$
v_{0}=\lim_{ A \to \infty } \frac{1}{\frac{1}{A}+\frac{R_{1}}{R_{1}+R_{2}}}v_{i}
$$

$$
v_{0}=\frac{1}{\frac{R_{1}}{R_{1}+R_{2}}}v_{i}
$$

$$
\begin{aligned}
v_{0}&=\frac{R_{1}+R_{2}}{R_{1}}v_{i} \\
&= \left( 1+\frac{R_{2}}{R_{1}} \right)v_{i}
\end{aligned}
$$

## Oppgave 4c)

Vi ønsker

$$
v_{0} = 10 v_{i}
$$
Siden vi har
$$
v_{0}=\left( 1+\frac{R_{2}}{R_{1}} \right)v_{i}
$$
Så har vi at
$$
1+\frac{R_{2}}{R_{1}} = 10
$$
La for eksempel ${}R_{1}=1k{}$. Da har vi
$$
\begin{aligned}
1+R_{2}\cdot 10^{-3}&=10 \\
R_{2}\cdot 10^{-3}&=9 \\
R_{2}=9k \\
\end{aligned}
$$
Dermed har vi ${}R_{1}=1k, R_{2}=9k{}$. 

![[Pasted image 20261022134411.png]]

Hvordan får vi ${}9k{}$ motstand? 
### Vi kan kombinere motstander!
$$
R_{\text{tot}}=\frac{1}{\frac{1}{R_{1}}+\frac{1}{R_{2}}+\frac{1}{R_{3}}}
$$
$$
R_{\text{tot}}=\frac{R_{1}R_{2}R_{3}}{R_{2}R_{3} + R_{1}R_{3}+R_{1}R_{2}}
$$
La ${}R=R_{1}=R_{2}=R_{3}{}$.
$$
R_{\text{tot}}=\frac{R^{3}}{3 R^{2}}
$$
$$
\therefore R_{\text{tot}}=\frac{1}{3}R
$$
Det viktige for vår situasjon er at ${}R_{2}=9 R_{1} \leftrightarrow R_{1}=\frac{1}{9}R_{2}{}$.

### Motstander
- 1k
- 10k
- 100k
- 1M
- 3.3
- 3.3k
- 33k
- 330k


# Vi løser mer generellt for to motstander i parallel

$$
R_{\text{tot}}=\frac{1}{\frac{1}{R_{1}}+\frac{1}{R_{2}}}
$$
$$
R_{\text{tot}}=\frac{R_{1}R_{2}}{R_{1}+R_{2}}
$$
La ${}R_{1}=A R, R_{2} = B R{}$.
$$
R_{\text{tot}}=\frac{ABR^{2}}{(A+B)R}
$$
$$
R_{\text{tot}}=R\frac{AB}{A+B}
$$
La ${}A=1{}$.
$$
\frac{R_{\text{tot}}}{R}=\frac{B}{1+B}
$$
Vi kan derfor få verdiene

| ${}\frac{R_{\text{tot}}}{R}{}$ | B   |
| ------------------------------ | --- |
| ${}\frac{1}{2}{}$              | 1   |
| ${}\frac{2}{3}{}$              | 2   |
| ${}\frac{3}{4}{}$              | 3   |
| 4/5                            | 4   |
| 5/6                            | 5   |
| 6/7                            | 6   |
| 7/8                            | 7   |


# Nå med 3 i parallel
$$
R_{\text{tot}}=\frac{R_{1}R_{2}R_{3}}{R_{2}R_{3} + R_{1}R_{3}+R_{1}R_{2}}
$$
La ${}R_{1}=R, R_{2}=AR, R_{3}=BR{}$.
$$
R_{\text{tot}}=\frac{ABR^{3}}{(AB+A+B)R^{2}}
$$
$$
\frac{R_{\text{tot}}}{R}=\frac{AB}{AB+A+B}
$$
$$
\frac{R_{\text{tot}}}{R} = \frac{1}{1+\frac{1}{A}+\frac{1}{B}}
$$
Vi kan derfor få

| ${}\frac{R_{\text{tot}}}{R}{}$ | A   | B   |
| ------------------------------ | --- | --- |
| 1/3                            | 1   | 1   |
| 1/2                            | 2   | 2   |
| 3/5                            | 3   | 3   |
| 2/3                            | 4   | 4   |
| 4/9                            | 4   | 1   |
| ...                            | 3   | 2   |
|                                | 2   | 3   |
|                                | 1   | 4   |
# Ny strategi

$$
3.3 \approx \frac{10}{3}
$$
Let ${}R_{1}=\frac{1}{3}R, R_{2}=3R{}$.
Så
$$
R = 3R_{1}
$$
Og videre
$$
R_{2}=9R_{1}
$$
Som er det vi ønsker.

### Liten test
$$
3.3 \cdot 9 = 29.7 \approx 30
$$
Vi lager en ${}30{}$k motstand med tre ${}10{}$k motstander i serie. Så bruker vi én ${}3.3{}$k motstand. #Løsning

### Praktisk
Jeg har tre ${}1{}$k motstander. Jeg trenger derfor én ${}330 \ohm{}$.




# Resultat
Jeg brukte  en ${}30{}$k motstand med tre ${}10{}$k motstander i serie som ${}R_{2}{}$. Og til slutt én ${}3.3{}$k motstand som ${}R_{1}{}$.

Som input i plussterminalen på OP-ampen delte jeg ${}5{}$V til ${}\approx 4.546{}$V med en ${}10{}$k og en ${}100{}$k motstand.

Forventning er rundt en 10 ganger økning av inngangsspenningen.

Voltemeteret målte ==🟢4V== som er ==🔴8.8== ganger så my som *inngangsspenning* ==🔵4.546V==.


# Dagens nøtt a)
Hvilken av lysdiodene i Figur 9 vil lyse dersom ${}v_{i}=V{}$? Hvilken vil lyse dersom ${}v_{i}=-V{}$?
Vi forutsetter at ${}V{}$ er positiv og større enn terskelspenningen til diodene.


![[Pasted image 20261022155403.png|416]]



${}D_{1}{}$ dersom ${}V>0{}$. ${}D_{2}{}$ dersom ${}V<0{}$.

Sett opp krets slik som i fuger 9 (a). La ${}v_{2}{}$ være GROUND, og ${}v_{1}{}$ være ${}v_{i}{}$. Lysdiodene lyser da etter forholdet mellom ${}v_{1}{}$ og ${}v_{2}{}$.


























# LaTeX garbo
$$
\text{If } X \sim \text{Normal}(\mu,\sigma^{2}), \text{ then } \mathbb{E}[X^{4}]=3\sigma^{4}+6\mu^{2}\sigma^{2}+\mu^{4}
$$

$$
f^{-1}(B)= \{ x \in X:f(x) \in B\}
$$

$$
\int_{0}^{\infty}J_{\upsilon}(ax)e^{ -bx }x^{\upsilon+1}dx=\frac{a^{\upsilon}}{(b^{2}+a^{2})^{\upsilon+1}}
$$

$$
\lim_{ x \to \infty } x \sin \left( \frac{1}{x} \right)=1
$$

$$
\log(ab)=\log a+\log b
$$

$$
\sin ^{2} \theta + \cos ^{2} \theta=1
$$

$$
\int \sec ^{2} xdx=\tan x + C
$$

$$
\tan(x)= \frac{\sin(x)}{\cos(x)}
$$

$$
M_{m+1}(N_{ij}):=M_{m}(N_{ij})-M_{m}^{*}\exp \{ -\beta \cdot d(N_{m}^{*}\cdot N_{ij}) \}
$$

$$
\sum_{k=1}^{n} k=\frac{n(n+1)}{2}
$$

$$
f(x)=-\frac{d}{dx}\left( \frac{1}{x} \frac{d}{dx} \right)
$$

$$
\int_{0}^{\infty}x^{s-1}\cos(ax)dx = \Gamma(s) \frac{\cos\left( \frac{\pi s}{2} \right)}{a^{s}}
$$
