[[OP-amps]]

$$
v_{0}=A(v_{+}-v_{-})=Av_\text{i}
$$
For en *ideell* opamp
- ${}A=\infty{}$
- ${}R_\text{i}=\infty{}$
- ${}R_{0}{}$=0


![[Pasted image 20261024161303.png]]
![[Pasted image 20261024161902.png]]
![[Pasted image 20261024162658.png]]
For *lm358*
- ${}R_\text{i}=10\text{ M} \Omega{}$
- ${}A_\text{min}=70 \text{ MV/V}, A_\text{typ}=140 \text{ MV/V}{}$
- ${}R_\text{o}=300\Omega{}$, når ${}f=1\text{ MHz, }I_\text{O}=0\text{ A}{}$


Vi går ut i fra *Figur 1 (b)*. Strømmen ${}I_\text{inn}{}$ er gitt ved
$$
I_\text{i}=\frac{v_\text{i}}{R_\text{i}}
$$
For analysens skyld, la ${}v_\text{i}=5\text{ V }{}$. Så
$$
I_\text{i}= \frac{5\text{ V } }{10^{7}}=0.0000005\text{ A }
$$
La noden med open-krets-spenning ${}v_\text{o}{}$ være koblet til jord med 1 motstand ${}R_\text{load}{}$ mellom. En ideell OP-amp vil da ha en spenning over ${}R_\text{load}{}$ lik ${}v_\text{o}{}$.
$$
v_\text{load}=v_\text{o} \frac{R_\text{load}}{R_\text{load}+R_\text{o}}
$$
La ${}R_\text{load}=1\text{ k }, v_\text{o}=10\text{ V }{}$; forventer ${}v_\text{load}=10\text{ V }{}$. Da får vi
$$
\begin{aligned}
v_\text{load}&=10\text{ V } \frac{1\text{ k } }{1\text{ k } +300\Omega} \\
&\approx 7.692307692 \text{ V } 
\end{aligned}
$$
Som gir en error på
$$
10-7.692307692\approx 2.31\text{ V }
$$
#### Resultat
*lm358* OP-ampen oppfyller ${}A=\infty{}$ og ${}R_\text{i}=\infty{}$ nokså bra, men ikke ${}R_\text{o}=0{}$. Dermed er den ikke ideell.
%% Merk at jeg kan ha misforstått databladet. %%

## Oppgave 2
1. Strømmen gjennom inngangene til op-ampen er alltid lik null. 
	- Dette gir mening siden motstanden mellom inngangene er lik ${}\infty{}$
2. Spenningen mellom inngangene til op-ampen er ${}v_\text{+}-v_\text{-}=0{}$ i det lineære området.
	- Dersom ${}\|v_\text{i}\|=\|v_\text{+}-v_\text{-}\|>0{}$, vil ${}\|v_\text{o}\|=\|Av_\text{i}\|=\infty{}$. Dermed *må* ${}\left| v_\text{i} \right|=0{}$.

## Oppgave 3

$$
v_\text{i}=v_\text{-}
$$
Strømmen fra minus-inngang til ground gjennom motstand ${}R_{1}{}$
$$
I = \frac{v_\text{i}}{R_{1}}
$$
${}v_{2}{}$ er spenning over motstand ${}R_{2}{}$
${}v_{2}=v_\text{i} \frac{R_{2}}{R_{1}}{}$
$$
v_\text{o}=v_\text{i}+v_{2}\\
=v_\text{i}\left( 1+ \frac{R_{2}}{R_{1}} \right)
$$
## Oppgave 4
La ${}I_\text{inn}{}$ være strømmen fra ${}v_\text{i}{}$ til minus-inngangen til OP-ampen.
$$
I_\text{inn} = \frac{v_\text{i}}{R_{1}}
$$
Da blir strømmen gjennom ${}R_{2}{}$ også lik ${}I_\text{inn}{}$ og spenning ${}v_\text{o}{}$ over ${}R_{2}{}$ blir
$$
v_\text{o}=-I_\text{inn}R_{2} = -v_\text{i} \frac{R_{2}}{R_{1}}
$$
Merk minustegnet foran ${}I_\text{inn}{}$. Denne kommer av at den har retning *fra* jord *til* ${}v_\text{o}{}$. Så tegnkonvensjonen krever at plus-siden er ved jord.

## Oppgave 5
Den *inverterende forsterkerkretsen* inverterter inngangsspenningen. Den *ikke-inverterende forsterkerkretsen* gjør ikke dette. :)

## Oppgave 6

b) Vi antar at lydsignalet som inneholder lyden fra mikrofonen og CD-spilleren er lik summen av signalet fra hver.
$$
v_\text{cd og mic} = v_\text{cd} + v_\text{mic}
$$
La absoluttverdien av signalene beskrive styrken deres.
Vi kan da justere styrken av hvert signal med en skalar
$$
v_\text{cd og mic} = c_{1}v_\text{cd}+c_{2}v_\text{mic}
$$
Vi kan da bruke kretsen fra *Oppgave 6a*.
$$
v_\text{o} = -\left(  \frac{R_{2}}{R_{11}}v_{1} + \frac{R_{2}}{R_{12}}v_{2}\right)
$$
La ${}c_{1}= \frac{R_{2}}{R_{11}}, c_{2}= \frac{R_{2}}{R_{12}}{}$.
$$
v_\text{o}=-(c_{1}v_{1}+c_{2}v_{2})
$$
Det eneste problemet da er at utgangssignalet blir invertert. Du kan da ev. invertere det *igjen*. Du kan bruke kretsen fra *Oppgave 4* med ${}\frac{R_{2}}{R_{1}}=1{}$. Da får vi
$$
v_\text{o}=-v_\text{i}
$$
## Oppgave 7
$$
v_\text{i}=v_\text{o}
$$
Dette kan brukes for å unngå *load* på inngangssignalet dersom det er følsomt. For lydssignal kan dette være nyttig.

## Oppgave 8
(a) Hodetelefonene har lavere motstand. Derfor er det lavere motstand mellom positiv utgang av spenningsdeler og jord. Dermed blir spenningen lavere her. Du kan også tenke på det som at det går mer strøm gjennom hodetelefonene og mindre gjennom ${}R_{2}{}$. Så fra ${}V=I\cdot R{}$ vil spenning være mindre.
(b) Han oppnådde
$$
v_{2}(t) = v_{1}(t) \frac{1\text{ k }  \parallel 330\Omega }{2\text{ k } +1\text{ k } \parallel 330\Omega}=v_{1}(t)\frac{33}{299}
$$
$$
\frac{v_{1}}{v_{2}} = \frac{299}{33} \approx \underline{9.1 \text{ V/V }} 
$$
(c) ==🔴skip==

## Oppgave 9

![[Pasted image 20261024184737.png|810]]
(a) Den nye løsningen med å bruke en buffer bør fungere. Siden tilnærmet ingen strøm går fra utgang av spenningsdeler, vil all strøm gå gjennom ${}R_{2}{}$. 
En svakhet er at signalet nå er avhengig av hvor stort det lineære området på OP-ampen er. Altså, den nedre og øvre spenningsforsyningen.
(b) Husk at den interne motstanden i OP-ampen til utgangen ${}R_\text{o}=330\Omega{}$. La ${}v_{330}{}$ være spenningsfallet over denne motstanden fra spenningskilden til utgang.
$$
v_{330}=I_\text{o}\cdot 330
$$
Utgangspenningen er ${}v_{3}(t){}$. Gylne regel: ${}v_{2}=v_{3}{}$, siden det er bufferkrets
$$
v_{2}=-v_{330}+Av_{2} \\
=-v_{330} + Av_{2}
$$
dette blir
$$
I=-\frac{v_{2}}{330}(1-A)
$$
Merk at ${}A\gg 1{}$ så ${}I{}$ er et gigantisk tall. Spenningskilden bør ikke klare å levere dette, så spenningen vil bli mindre enn nødvendig. ${}v_{3}(t){}$ blir da *svakere*. Dette motsier oppgaven. Hva er feil?
**"Lyden nå er altfor høy"**, det at forsterkingen er blitt *veldig* stor peker på ${}A{}$. Forskjell i motstand i ledningene kan kanskje skape en negativ tilbakekoblingskrets med høy forsterkning. 

Sett opp modellen med utgangsmotstand:
- ${}v_{3}=A(v_\text{+}-v_\text{-})-I\cdot R_\text{o}{}$
- ${}v_\text{+}=v_{2}{}$
- ${}v_\text{-}=v_{3}{}$
- ${}I=\frac{v_{3}}{R_\text{HT}}{}$

$$
v_{3}=A(v_{2}-v_{3}) - v_{3} \frac{R_\text{o}}{R_\text{HT}}
$$
$$
v_{3}=Av_{2}-Av_{3} - v_{3} \frac{R_\text{o}}{R_\text{HT}}
$$
$$
v_{3}+Av_{3}+ \frac{R_\text{o}}{R_\text{HT}}v_{3}=Av_{2}
$$
$$
v_{3}\left( 1+A+ \frac{R_\text{o}}{R_\text{HT}} \right)=Av_{2}
$$
$$
v_{3}= \frac{Av_{2}}{1+A+ \frac{R_\text{o}}{R_\text{HT}}}
$$
$$
v_{3}\approx v_{2}
$$

Fra forrige oppgave fikk jeg at ${}v_{3}=v_{2}{}$ (uten buffer) var 
$$
v_{2}(t) = v_{1}(t) \frac{1\text{ k }  \parallel 330\Omega }{2\text{ k } +1\text{ k } \parallel 330\Omega}=v_{1}(t)\frac{33}{299}
$$
*Med* bufferen vil ${}v_{3}{}$ være ${}\frac{1}{3}v_{1}(t){}$. ${}\frac{v_{1}}{v_{2}}{}$ blir da ${}3{}$. Mens *uten* bufferen blir ${}\frac{v_{1}}{v_{2}}\approx9.1{}$. Her er årsaken til den *altfor høye lyden*.
Vi ønsker ${}\frac{v_{1}}{v_{2}}=9.1{}$. Så
$$
\begin{aligned}
\frac{R_{1}+R_{2}}{R_{2}}&=9.1 \\
\frac{R_{1}}{R_{2}} + 1&=9.1  \\
\frac{R_{1}}{R_{2}}&=8.1 \\
R_{1}&=8.1\cdot R_{2}
\end{aligned}
$$
For eksempel kan ${}R_{2}=1\text{ k },R_{1}=8.1\text{ k }{}$.
## Oppgave 10
$$
v_{2}=-\frac{R_{2}}{R_{1}}v_{1}
$$
$$
\frac{v_{1}}{v_{2}}=-\frac{R_{1}}{R_{2}}=-9.1
$$
Så ${}R_{1}=9.1\cdot R_{2}{}$. En eksempel løsning kan derfor være ${}R_{2}=1\text{ k },R_{1}=9.1\text{ k }{}$.

# Refleksjon
1. En inverterende forsterker kan skalere et signals absoluttverdi opp og ned, men signalet inverteres. En ikke-inverterende forsterker kan kun skalere *opp* signalets verdi. En inverterende forsterker bruker *positiv tilbakekobling*. En ikke-inverterende forsterker bruker *negativ tilbakekobling*.
2. Det er nyttig når du har et sensitivt signal. Eller når du har en varierende load-motstand, og du vil gjøre utgangsignalet insensitiv til denne load-en.
3. Besvart over ↑
4. Addisjonskretsen fra *ERT 8* var digital, kvantisert. Den hadde bestemte hakk den kunne hoppe mellom. Addisjonskretsen i *Figur 4* i denne ERT-økten, er kontinuerlig. Den vekter og adderer to analoge signal.

---
# OP-amps som comparators

I open-loop form (ingen tilbakekobling), lager OP-amper square waves. Siden amplificationen er såpass stor treffer den alltid grensen, *saturation*, og flater ut. Så dersom ${}v_+-v_-{}$ er bare litt mindre eller mer enn null, skyter den opp. 
OP-ampen fungerer dermed som en comparator.
### Hva skjer om du kobler en *sine wave* til en comparator med en inngangsterminal satt til et stabilt reference voltage, ${}v_\text{ref}{}$
Du får da et PWM signal som går av og på med jevne mellomrom. Perfekt for klokker etc.















