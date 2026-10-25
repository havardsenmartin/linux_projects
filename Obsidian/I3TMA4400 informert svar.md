Gitt ${}f(\theta)=\cos\theta{}$. Merk at ${}f(\theta){}$ er kontinuerlig. La ${}\{ \theta_{n} \}_{n=0}^{\infty} \subseteq \mathbb{R}{}$ være følgen gitt ved
$$
\theta_{n+1}=f(\theta_{n}) \quad \text{med initialverdien }a_{0}
$$
#### Teorem 1 praktisk
**Vi antar at ${}\{ \theta_{n}\}_{n=0}^{\infty} {}$ konvergerer med grenseverdi ${}\lim_{ n \to \infty }a_{n}=r{}$.**
	Med *Teorem 1* har vi da at ${}r{}$ er et fikspunkt for ${}f(\theta){}$, det vil si ${}f(\theta)=\theta{}$.

---
#### Teorem 2 praktisk
Vi vet at fikspunktet, ${}\theta _\text{fiks}{}$, er avgrenset omtrent,
$$
\theta _\text{fiks} \in [0.6,0.8]
$$
I tillegg har vi at ${}f(\theta), f'(\theta){}$ er kontinuerlige over ${}\mathbb{R}{}$.
##### Analyse av ${}\left| f'(\theta) \right|{}$ for ${}\theta \in[0.6,0.8]{}$
$$
\begin{aligned}
f'(\theta) &= -\sin\theta \\
\left| f'(\theta) \right|  & = \left| \sin\theta \right|  \\

\end{aligned}
$$
Merk at dersom ${}\theta < \frac{\pi}{6}{}$,
$$
\sin\theta < \frac{1}{2}
$$
Og dersom ${}\theta > 0{}$,
$$
\sin\theta >0
$$
Dermed har vi at gitt ${}\theta \in[0.6,0.8]{}$,
$$
\left| f'(\theta) \right| =\left| \sin\theta \right| < \frac{1}{2} < 1
$$
Med *Teorem 2* har vi at følgen ${}\{ \theta_{n} \}_{n=0}^{\infty}{}$ vil konvergere mot ${}\theta _\text{fiks}{}$ for alle initialverdier, ${}\theta_{0} \in [0.6,0.8]{}$.

#### Kopiert logikk
---

> [!example] FRA JUPYTERNOTEBOOK
> **Definisjon.** Vi definerer feilen $e_n$ i steg $n$ av en fikspunktiterasjon $a_{n+1} = f(a_n)$ som  
> 
> $$ e_n=|a_n-r|. $$
> 
> Vi definerer også konvergensordenen til å være det positive tallet $q$ hvor grenseverdien
> 
> $$
> \lim_{n\to\infty}\frac{e_{n+1}}{(e_{n})^q}
> $$
> 
> eksisterer og er forskjellig fra $0$.
> 
> ---
> 
> Fra beviset av Teorem 2 ser vi at
> 
> $$
> \lim_{n\to\infty}\frac{e_{n+1}}{e_{n}}=\lim_{n\to\infty}|f'(\xi_n)|=|f'(r)|.
> $$
> 
> Altså er konvergensorden for fikspunktiterasjonen med $f(x)$ lik 1 dersom $0 \neq |f'(r)|<1$. 
> 
> Merk at $|f'(r)|<1$ impliserer at feilen avtar. 
> 
> I eksempelet hvor $f(x)=\frac{1}{2}(x+\frac{2}{x})$ ser vi at $f'(\sqrt{2})=0$. I dette tilfellet må vi gjøre en grundigere analyse for å fastslå konvergensordenen $q$. Fra Taylors teorem får vi
> 
> $$
> f(a_n) - r = f(a_n) - f(r) = \frac 1 2 f''(\xi_n) (a_n - r)^2
> $$
> for en $\xi_n$ mellom $a_n$ og $r$. Dette gir
> 
> $$
> \lim_{n\to\infty}\frac{e_{n+1}}{(e_{n})^2}=\lim_{n\to\infty}\frac{1}{2}|f''(\xi_n)|=\frac{1}{2}|f''(r)|,
> $$
> 
> hvor 
> 
> $$
> \frac{1}{2}|f''(\sqrt{2})|=\frac{1}{2}\left|\frac{2}{(\sqrt{2})^3}\right|\approx0.3535534.
> $$

---

#### Vi bruker logikken fra eksempelet
La ${}e_{n}{}$ være feilen i steg ${}n{}$ av en fikspunktiterasjon ${}\theta_{n+1}=f(\theta_{n}){}$ som
$$
e_{n}=\left| \theta_{n}-\theta _\text{fiks} \right|
$$
Vi sjekker om konvergensordenen er ${}q=1{}$ ved å sjekke om grenseverdien under eksisterer og er forskjellig fra ${}0{}$.
$$
\lim_{ n \to \infty }  \frac{e_{n+1}}{(e_{n})^{q}} = \lim_{ n \to \infty } \frac{\left| \theta_{n+1}-\theta _\text{fiks} \right|}{\left| \theta_{n}-\theta _\text{fiks} \right| } = \left| f'(\theta _\text{fiks}) \right| 
$$
Husk at vi har at gitt ${}\theta \in[0.6,0.8]{}$,
$$
\left| f'(\theta) \right| =\left| \sin\theta \right| < \frac{1}{2} < 1
$$
Så
$$
\lim_{ n \to \infty } \frac{e_{n+1}}{e_{n}} = \lim_{ n \to \infty } \frac{\left| \theta_{n+1}-\theta _\text{fiks} \right| }{\left| \theta_{n}-\theta _\text{fiks} \right| }< \frac{1}{2}
$$


> [!tip] ### Hva jeg ville gjort nå
> 1. Skriv ned bare denne setningen: _«Skal jeg garantere feil < ε, bruker jeg e_n ≤ αⁿ e₀ og løser for n.»_ Det er mønsteret.
> 2. Gå gjennom løsningen over én gang, og for hvert steg skriv _hvilken mangel i formelen det fyller_.
> 3. Lukk alt og løs en tilsvarende oppgave, for eksempel samme spørsmål for f(x) = ½(x + 2/x) med startverdi 1.5 og toleranse 10⁻¹⁰.
