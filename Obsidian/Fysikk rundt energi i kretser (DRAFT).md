## Punkt 1: Gir spenningskilder energi?

### Definisjon av spenningskilde
La spenningskilde med spenning ${}V\text{ [V] }{}$ være koblet mellom punkt ${}A{}$ til ${}B{}$, plusside ved ${}A{}$. 
- Da har ${}B{}$ et lavere potensial. 
- Spenningsfallet *fra* ${}A{}$ *til* ${}B{}$ er lik ${}V{}$.
	i. Ladningene *mister* energi når de beveger seg *fra* ${}A{}$ *til* ${}B{}$.
	ii. Ladningene *får* energi når de beveger seg *fra* ${}B{}$ *til* ${}A{}$.
#### Spenning
Spenning er definert som energiendring per mengde ladning.
$$
V\text{ [V] } = \frac{W\text{ [J] }  }{Q\text{ [C] } } 
$$
### Hva betyr det å levere energi i en krets?
Dersom spenningskilden gir energi vil energi tilføres kretsen, dvs. strømmen/ladningene. Dersom energi går til hva som helst annet (varme, kjemisk potensial, etc.) vil dette være *energibruk*.
### Spenningskilden *leverer energi*
Dersom ladningene beveger seg gjennom kilden slik at ladningene *mister* energi. Altså, fra ${}A{}$ til ${}B{}$. Da sier vi at det er *spenningskilden* som gir energien.
### Spenningskilden *forbruker energi*
Dersom ladningene beveger seg gjennom kilden slik at ladningene *får* energi. Altså, fra ${}B{}$ til ${}A{}$. Da sier vi at det er *spenningskilden* som får energien.
### Bemerkning
Det *kan* være slik at energien *kommer fra* eller *gis* til andre system enn *spenningskilden*. Men dette utelukker vi.
## Punkt 2: Hvorfor går strømmen slik som den går
La ${}A{}$ og ${}B{}$ være koblet sammen med en motstand med motstandsverdi ${}R\;\;\Omega\;{}$. Hvilken vei vil strømmen gå gjennom spenningskilden? Fra plussiden til minussiden? Hvorfor går det ikke noen strøm internt fra høypotensial til lavpotensial? Det er ikke særlig mye formler som kan brukes her. 
Vi har
- ${}V=IR{}$
- ${}V=\frac{W}{Q}{}$
- ${}I=\frac{Q}{T}{}$ eller ${}I=\frac{d Q}{d t}{}$
- ${}\sum v_\text{drop}=0{}$
- ${}\sum i_\text{out}=0{}$

Grunnen til at disse formlene ikke hjelper her er at de ikke beskriver retning. Du må anta konvensjoner og bruke skjulte, ekstra teorem. For eksempel må du anta hvilken side som ${}\frac{d Q}{d t}>0{}$ vil vise til en økning. 
**Du kan bruke Ohms lov og anta at den gjelder for negative I. Da vil den beskrive retning. Du kan da kombinere strømretningen du får her med KCL for spenningskilden. Siden strømmen inn må være lik ut, vil den ene siden måtte ha strøm ut.**


> [!info] Claude
> # Ideelle spenningskilder: oppklaring av notatene dine
> 
> Du er på riktig spor, særlig med slutten om Ohms lov og KCL. Jeg tar først det som må rettes, så en ryddig forklaring.
> 
> ## Ting som bør rettes
> 
> **1. Retningen i definisjonen er snudd.** Med pluss ved ${}A{}$ er ${}A{}$ på høyest potensial, og spenningsfallet fra ${}A{}$ til ${}B{}$ er ${}V{}$. Da gjelder:
> - Positive ladninger som beveger seg ${}A \to B$ *mister* potensiell energi (${}\Delta W = -QV{}$).
> - Positive ladninger som beveger seg ${}B \to A$ *får* energi (${}\Delta W = +QV{}$).
> 
> Punkt i og ii i definisjonen er altså byttet om. Det samme gjelder «leverer/forbruker» lenger ned: kilden **leverer** energi når ladningene går ${}B \to A$ *gjennom kilden*, altså når strømmen går inni kilden fra minus til pluss og ut av plussklemmen.
> 
> **2. ${}W = \frac{E}{T}{}$ er effekt, ikke arbeid.** Du bruker ${}W{}$ både som energi (i ${}V = W/Q{}$) og som effekt. Det gir feil dimensjon i utledningen din. Riktig er:
> 
> $$
> V = \frac{E}{Q}, \qquad I = \frac{Q}{T}, \qquad V = IR \;\Rightarrow\; \frac{E}{Q} = \frac{Q}{T}R \;\Rightarrow\; R = \frac{E\,T}{Q^2}
> $$
> 
> Ikke ${}E/Q^2{}$. Konklusjonen din om at formlene ikke gir retning, stemmer likevel. De er skalare relasjoner mellom størrelser.
> 
> ## Hvordan en ideell spenningskilde fungerer
> 
> Definisjonen er at **spenningen mellom klemmene alltid er ${}V{}$, uansett hva som kobles til**. Strømmen er ikke bestemt av kilden, men av resten av kretsen.
> 
> ## Hvorfor strømmen går som den gjør
> 
> Med motstanden ${}R{}$ mellom ${}A{}$ og ${}B{}$:
> 
> 1. **I motstanden:** Ohms lov med fortegn gir ${}I_{A\to B} = \frac{V_A - V_B}{R} = \frac{V}{R} > 0{}$. Strømmen går altså fra høyt til lavt potensial *i motstanden*. Her er det bare fortegnet som fastlegger retningen.
> 2. **KCL ved ${}A{}$ og ${}B{}$:** Strømmen som går inn i motstanden fra ${}A{}$ må komme fra kilden. Den som kommer ut ved ${}B{}$ må gå tilbake inn i kilden. Da må strømmen gå **gjennom kilden fra ${}B{}$ til ${}A{}$**, altså ut av plussklemmen.
> 
> Så strømmen går ikke «internt fra høypotensial til lavpotensial» i kilden, fordi KCL ikke tillater det. Ladning kan ikke hope seg opp, så strømmen må gå i en sløyfe. Siden den går ${}A \to B$ i motstanden, må den gå ${}B \to A$ i kilden.
> 
> ## Fysisk bakgrunn
> 
> Inni en ekte kilde (batteri) er det en ikke-elektrostatisk kraft, for eksempel kjemisk, som skyver ladningene *mot* det elektriske feltet, fra minus til pluss. Det er denne kraften som gjør arbeidet ${}W = QV{}$ på ladningene. I den ideelle modellen skjuler vi mekanismen og sier bare at spenningen er fastholdt.
> 
> ## Leverer eller forbruker kilden energi?
> 
> Effekten er ${}P = V \cdot I{}$, der ${}I{}$ er strømmen ut av plussklemmen.
> - ${}I > 0{}$: kilden **leverer** effekt (batteri som utlades).
> - ${}I < 0{}$: kilden **forbruker** effekt (batteri som lades).
> 
> Retningen bestemmes av kretsen. Hvis du kobler en ideell kilde med ${}V{}$ til en annen med høyere spenning, vil den med lavest spenning absorbere energi. Det gjelder uansett at spenningen over kilden er fast.
> 
> Vil du at jeg setter dette opp som en ryddig versjon av notatene dine
> 
> 
> 





