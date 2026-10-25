## Oppgave 1
$$
\lim_{ x \to 0 } \frac{15\tan(3x)-45x}{3x^{3}}
$$

$$
\frac{d ^{n}}{d x^{n}} [\sin (3x)]=3^{n}\left( \frac{d^{n} }{d x^{n}} \sin x \right)
$$

#### Taylor serie for ${}\sin (3x),\cos(3x),\tan(3x){}$
$$
\sin(3x)= \sum_{i=0}^{\infty} \frac{f^{(i)}(0)}{i!}x^{i}
=\sum_{i=0}^{\infty} \frac{3^{i}[\frac{d ^{i}}{d x^{i}}\sin x]_{x=0} }{i!}x^{i}
$$
$$
\sin(3x)=\frac{3^{1}}{1!}x^{1}-\frac{3^{3}}{3!}x^{3}+ \frac{3^{5}}{5!}x^{5}-\dots
$$
og ${}\cos(3x)=\frac{1}{3}\frac{d }{d x}\sin(3x){}$
$$
\cos(3x)=\frac{1}{3}\frac{d }{d x} \left[\frac{3^{1}}{1!}x^{1}-\frac{3^{3}}{3!}x^{3}+ \frac{3^{5}}{5!}x^{5}-\dots \right] \\
= 1 - \frac{3^{2}}{2!}x^{2}+ \frac{3^{4}}{4!}x^{4}-\dots
$$
Og til slutt for ${}\tan(3x)=\frac{\sin(3x)}{\cos(3x)}{}$,
$$
\tan(3x) = 
\frac{3x-\frac{3^{3}}{3!}x^{3}+ \frac{3^{5}}{5!}x^{5}-\dots}
{1 - \frac{3^{2}}{2!}x^{2}+ \frac{3^{4}}{4!}x^{4}-\dots}
$$
#### Anvendelse i oppgave
$$
\lim_{ x \to 0 } \frac{15\tan(3x)-45x}{3x^{3}}
=
\lim_{ x \to 0 } \frac{15\left[
\frac{3x-\frac{3^{3}}{3!}x^{3}+ \frac{3^{5}}{5!}x^{5}-\dots}
{1 - \frac{3^{2}}{2!}x^{2}+ \frac{3^{4}}{4!}x^{4}-\dots}
\right]-45x}{3x^{3}}
$$

### Jeg ga opp og og fant Taylor serie for ${}\tan x{}$ direkte
![[Pasted image 20261024212238.png]]
Dette uttrykket er lik ${}\tan(x){}$. Vi deriverer teller og nevner 3 ganger. For får da kun leddet med faktor ${}x^{3}{}$ i fra ${}\tan x{}$. Resten er enkelt.
$$
\lim_{ x \to 0 } \frac{3^{3}\cdot15\cdot 2}{3^{2}\cdot 2}=3\cdot 15 = 45
$$
---
## Oppgave 2

$$
6x=\frac{1}{2}\cos(3x)
$$
har én løsning på intervallet ${}[0,1]{}$. Finn en tilnærmet verdi for denne løsningen ved å erstatte høyresiden med et taylorpolynom av grad ${}2{}$ rundt ${}0{}$. Svaret skal gis som et eksakt reelt tall. Bruk sqrt() eller ^(1/2) for kvadratrøtter.
### Mitt svar
$$
\cos(3x)=1- \frac{3^{2}}{2!}x^{2}
$$
La oss substituere
$$
\begin{aligned}
6x-\frac{1}{2}\left( 1- \frac{3^{2}}{2!}x^{2} \right)&=0\\
6x-\frac{1}{2}+ \frac{3^{2}}{2^{2}}x^{2}&=0\\
\end{aligned}
$$
Vi har nå en andregradsligning. La ${}a=\frac{9}{4},b=6,c=-\frac{1}{2}{}$. Vi bruker abc-formelen,
$$
x=\frac{-b\pm \sqrt{ b^{2}-4ac }}{2a}
$$
$$
x= \frac{-6\pm \sqrt{ 6^{2}-4\cdot\left( \frac{9}{4} \right)\cdot\left( -\frac{1}{2} \right) }}{2\cdot\left( \frac{9}{4} \right)}
$$
$$
x= \frac{-6\pm \sqrt{ 36+4.5 }}{4.5}
$$
$$
x=\frac{-6\pm \sqrt{ \frac{405}{10} }}{\frac{9}{2}}
$$
---
## Oppgave 3
$$
x\cosh\left( \frac{x}{2} \right)=\frac{1}{7}
$$

har nøyaktig én løsning. Finn en tilnærmet verdi for løsningen ved å bruke to fikspunkiterasjoner med
$$
x_{0}=1
$$
u skal altså finne ${}x_{2}{}$. Svaret skal være et eksakt reelt tall. IKKE bruk avrunding når du regner ut svaret.
### Mitt svar
La funksjonen ${}f{}$ være gitt ved
$$
f(x)=\frac{1}{7\cosh\left( \frac{x}{2} \right)}
$$
Dermed vil løsningen av ligningen
$$
x\cosh\left( \frac{x}{2} \right)=\frac{1}{7}
$$
$$
\cosh\left( \frac{x}{2} \right)= \sqrt{ \frac{\cosh x+1}{2} }
$$
![[Pasted image 20261024220052.png]]

være et fikspunkt for ${}f{}$. 
#### Vi utfører fikspunktiterasjoner
La ${}\{ x_{n} \}_{n=0}^{2}{}$ være følgen med fikspunktiterasjonsverdier. *Målet er å finne ${}x_{2}{}$*. Følgen er gitt ved
$$
x_{n+1}=f(x_{n})
$$
så
$$
x_{1} = f(x_{0})=f(1)=\frac{1}{7\cosh\left( \frac{1}{2} \right)}
$$
$$
x_{2} = f(x_{1})=\frac{1}{7\cosh\left( \frac{\frac{1}{7\cosh\left( \frac{1}{2} \right)}}{2} \right)} \\
x_{2} = f(x_{1})=\frac{1}{7\cosh\left( \frac{1}{14\cosh\left( \frac{1}{2} \right)} \right)} \\
$$
> [!important] Svaret var
> $$
> x_{2} = \frac{1}{7\cosh\left( \frac{1}{14\cosh\left( \frac{1}{2} \right)} \right)}
> $$

> [!definition] Definition of ${}\cosh x{}$
> $$
> \cosh(x)=\frac{e^{ x }+e^{ -x }}{2}
> $$
> $$
> \cosh x=1+ \frac{x^{2}}{2!}+ \frac{x^{4}}{4!}+ \frac{x^{6}}{6!}+\dots
> $$

$$
\cosh\left( \frac{1}{2} \right)=1+ \frac{1}{2^{2}\cdot 2!}
+ \frac{1}{2^{4}\cdot 4!}
  + \frac{1}{2^{6}\cdot 6!}
    +\dots
$$

---

$$
\cosh\left( \frac{1}{2} \right)=\frac{e^{ 1/2 }+e^{ -1/2 }}{2}
$$
$$
x_{1}=\frac{1}{7\left[\frac{e^{ 1/2 }+e^{ -1/2 }}{2}\right]}
= \frac{2}{7(e^{ 1/2 }+e^{ -1/2 })}
$$

$$
\cosh\left(\frac{2}{7(e^{ 1/2 }+e^{ -1/2 })}\right)= 
\frac{e^{ \frac{2}{7(e^{ 1/2 }+e^{ -1/2 })} }+e^{ -\left(\frac{2}{7(e^{ 1/2 }+e^{ -1/2 })}\right) }}{2}
$$

$$
x_{2}=\frac{2}{7\left[e^{ \frac{2}{7(e^{ 1/2 }+e^{ -1/2 })} }+e^{ -\left(\frac{2}{7(e^{ 1/2 }+e^{ -1/2 })}\right) }\right]}
$$


$$
x_{2}=\frac{1}{7\cosh\left( \frac{1}{7\cosh\left( \frac{1}{2} \right)} \right)}
$$

---

$$
\frac{1}{2}x \left(e^{ x/2 }+e^{ -x/2 }\right) = \frac{1}{7} \\
x \left(e^{ x/2 }+e^{ -x/2 }\right) = \frac{2}{7}
$$

La ${}u=e^{ x/2 }{}$ som impliserer $x=2 \ln u$. 

$$
2\ln u \cdot(u+u^{-1})=\frac{2}{7} \\

2\ln u \cdot(u^{2}+u)=\frac{2}{7}u \\
$$

$$
u=7\ln u \cdot (u^{2}+u) \\
$$
## Oppgave 4

### Mitt svar
Husk at for trapesmetoden er feilestimatet ${}E_\text{T}{}$ avgrenset av
$$
\left| E_\text{T} \right| \leq \frac{M\cdot(b-a)^{3}}{12n^{2}}
$$
der ${}M{}$ er maksimum av ${}f''{}$, ${}\left| f''(x)\right|\leq M {}$ for alle ${}x \in[a,b]{}$. Og ${}n{}$ er mengde delintervaller og ${}[a,b]{}$ er integrasjonsintervallet.

$$
M=8
$$
$$
\frac{8}{12n^{2}}\leq7\cdot 10^{-3}
$$
$$
n^{2}\leq\frac{8000}{12\cdot 7} = \frac{8000}{84}
$$


## Oppgave 5

### Mitt svar
$$
I=\int_{0}^{3}(3+x^{2}) dx
$$
La ${}f(x)=x^{2}+3{}$
$$
I_{n}= \frac{b-a}{2n} \left( f(x_{0})+2\sum_{i=1}^{3}f(x_{i})+f(x_{4}) \right)
$$
${}a=0,\,b=3{}$

$$
I_{4}= \frac{3}{4} \left( f(x_{0})+2\sum_{i=1}^{3}f(x_{i})+f(x_{4}) \right)
$$
${}x_{0}=0{}$ og ${}x_{4}=3{}$. Resten ligger lineært, jevnt spredd mellom. 
$$
x_{n}=\frac{3}{4}n
$$
$$
I_{4}=\frac{3}{4}\left( f(0)+2f\left( \frac{3}{4} \right)+2f\left( \frac{3}{2} \right)+2f\left( \frac{9}{4} \right)+f(3) \right)
$$
$$
f(0)=3 \\
$$
$$
f\left( \frac{3}{4} \right) = 3+ \frac{9}{16} \\
$$
$$
f\left( \frac{3}{2} \right) = 3+ \frac{9\cdot 4}{16}
$$

$$
f\left( \frac{9}{4} \right) = 3+ \frac{81}{16}
$$
$$
f(3) = 3+9
$$
Summer for svaret. 
%% Jeg brukte kalkulator %%
## Oppgave 6
![[Pasted image 20261025111005.png]]
### Mitt svar

#### Del 1
La ${}f(x) = \frac{1}{1-x}{}$. 

Restleddet ${}R_{n+1}{}$ til ${}n{}$-te polynom
$$
R_{n+1}(x)= \frac{f^{(n+1)}(c)\cdot(x-a)^{n+1}}{(n+1)!}
$$
der ${}c{}$ er et tall mellom ${}a{}$ og ${}x{}$.
Vi har ${}a=0{}$
$$
R_{n+1}(x)= \frac{f^{(n+1)}(c)\cdot x^{n+1}}{(n+1)!}
$$

$$
P_{6}(x)= \sum_{i=0}^{6} \frac{f^{(i)}(0)}{i!}x^{i}
$$
og
$$
f(x)=P_{6}(x) + R_{7}(x) \\
$$
$$
R_{7}(x)=f(x)-P_{6}(x)
$$

$$
\left| R_{7}(x) \right| =\left| f(x)-P_{6}(x) \right|
$$
Siden vi ikke vet eksat hva ${}R_{7}(x){}$ er, grunnet ${}c{}$, må vi funne *maks* verdien og avgrense.

$$
f(x)=\frac{1}{1-x}
$$
$$
f(x)=(1-x)^{-1}
$$
$$
f'(x)=-1(1-x)^{-2}
$$
$$
f''(x)=-2(1-x)^{-3}
$$
$$
f^{(n)}(x)=n!\cdot(1-x)^{-n-1}
$$
Dermed blir 
$$
R_{7}(x)= \frac{f^{(7)}(c)\cdot x^{7}}{7!}
$$

$$
f^{(7)}(x)=7!\cdot(1-x)^{-7-1}
$$
$$
f^{(7)}(x)=7!\cdot(1-x)^{-8}
$$
$$
R_{7}(x)=(1-c)^{-8}\cdot x^{7}
$$
Husk at ${}c{}$ er avgrenset. La ${}x \in I=\left[ -\frac{1}{2}, \frac{1}{2} \right]{}$.
$$
\begin{cases}
0<c<x  & x>0 \\
x<c<0 & x<0
\end{cases}
$$
Merk at en høyere ${}x{}$-verdi gjør ${}R_{7}(x){}$ større. Og ${}c=\frac{1}{2}{}$ gjør ${}(1-c)^{-9}{}$ enn ${}c= -\frac{1}{2}{}$. Vi velger derfor maks mulig verdi for ${}x{}$. La ${}x=\frac{1}{2}{}$.
$$
0<c< \frac{1}{2}
$$
Videre, ${}(1-c)^{-9}{}$ blir større for større (gyldig) ${}c{}$. Så maksimum er ved ${}c= \frac{1}{2}{}$. Siden ${}c= \frac{1}{2}{}$ ikke er inkludert, er det grensen for erroren.
%%Note: Både ${}(1-c)^{-9}{}$ og ${}x^{8}{}$ er symmetriske om ${}c=0,x=0{}$ hhv., så den nedre grensen gir like absoluttverdier. FEIL OG IRR%%
$$
\left| f(x)-P_{6}(x) \right| < \left( \frac{1}{2} \right)^{-8}\cdot x^{7}
$$
$$
\left| f(x)-P_{6}(x) \right| < 2^{7}\cdot \frac{1}{2^{7}}=2
$$
> [!warning] Jeg fikk '${}<{}$' i stedet for '${}\leq{}$'!
> Grunnen er at ${}c{}$ skal være *mellom* ${}a{}$ og ${}x{}$. Som ga ${}0<c< \frac{1}{2}{}$.

#### Del 2
Nå skal vi løse oppgaven uten Taylors formel.
$$
f(x)=\sum_{i=0}^{6} \frac{f^{(i)}(0)}{i!}x^{i}
$$
Husk
$$
f^{(n)}(x)=n!\cdot(1-x)^{-n-1}
$$
Så
$$
\begin{aligned}
f(x)&=\sum_{i=0}^{6} \frac{i!\cdot(1)^{-i-1}}{i!}x^{i} \\
&=\sum_{i=0}^{6} (1)\cdot x^{i} \\
&=1+x+x^{2}+x^{3}+x^{4}+x^{5}+x^{6} &
\end{aligned}
$$
*Hint* oppga at
$$
1+x+x^{2}+x^{3}+\dots+x^{n}= \frac{1-x^{n+1}}{1-x}
$$
Så
$$
\begin{aligned}
f(x)&= \frac{1-x^{6+1}}{1-x} \\
&= \frac{1-x^{7}}{1-x}
\end{aligned}
$$
Nå bruker vi dette uttrykket til å analysere ${}\left| f(x) - P_{6}(x) \right|{}$.
$$
\begin{aligned}
\left| f(x)-P_{6}(x) \right| &= \left| \frac{1}{1-x} - \frac{1-x^{7}}{1-x} \right|  \\
 & =\left| \frac{x^{7}}{1-x} \right| 
\end{aligned}
$$
Vi kan nå analysere dette uttrykket for å finne dens maksimum. ${}\left| x^{7}\right|{}$ har maksimum ved ${}-\frac{1}{2}{}$ og ${}\frac{1}{2}{}$. ${}\left| \frac{1}{1-x} \right|{}$ har maksimum ved ${}\frac{1}{2}{}$. Så ${}\frac{1}{2}{}$ er maksimum.
$$
\left| f(x)-P_{6}(x) \right|  \leq \left| \frac{1}{2^{7}}\cdot 2 \right| = 2^{-6} 
$$
#### Refleksjon
Hvorfor ga Taylors formel en *så* mye større grense? Forskjellen var gigantisk, men begge beskrev det samme.
> [!info] Claude
> Begge formlene beskriver samme feil, men de forteller ulikt mye om den.
> 
> - **Taylors formel** sier: det finnes _et_ tall $c$ mellom $0$ og $x$ slik at feilen er eksakt $\frac{x^7}{(1-c)^8}$. Du vet ikke hvilket $c$, så du må anta det verste, $c\to\frac12$.
> - **Direkte utregning** gir feilen eksakt: $\frac{x^7}{1-x}$. Ingen ukjent $c$.




































