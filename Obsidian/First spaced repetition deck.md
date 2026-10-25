#flashcards/besthet
Hvem er best::Jeg er best
<!--SR:!2026-10-27,4,270-->

#flashcards/numerisk_analyse
## Grunnidé

Hva er et fikspunkt?:: Et tall $r$ med $f(r)=r$.
<!--SR:!2026-10-27,3,250-->
Hva sier Teorem 1?:: Hvis $f$ er kontinuerlig og $a_{n+1}=f(a_n)$ konvergerer mot $r$, så er $f(r)=r$.
<!--SR:!2026-10-26,2,230-->
Hvilken egenskap ved $f$ brukes i beviset av Teorem 1, og hvor?:: Kontinuitet: $\lim f(a_n)=f(\lim a_n)=f(r)$.
<!--SR:!2026-10-26,2,230-->

## Konvergens (Teorem 2)

Hva er betingelsen i Teorem 2?:: $|f'(x)|\le\alpha<1$ på et intervall $I$ rundt fikspunktet $r$.
<!--SR:!2026-10-26,2,230-->
Hvorfor må alle $a_n$ ligge i $I$?:: Beviset bruker $|f'(\xi_n)|\le\alpha$ i hvert steg, og det vet vi bare på $I$.
<!--SR:!2026-10-24,0,230-->
Hvilket verktøy gir $a_{n+1}-r=f'(\xi_n)(a_n-r)$?:: Middelverdisetningen.
<!--SR:!2026-10-26,2,230-->
Hva er bevisideen til Teorem 2 i én linje?:: $e_{n+1}\le\alpha e_n$, så $e_n\le\alpha^n e_0\to0$.
<!--SR:!2026-10-24,0,230-->
Hvorfor konvergerer ikke $b_{n+1}=2/b_n$ mot $\sqrt2$?:: $g'(\sqrt2)=-1$, så $|g'|<1$ kan ikke gjelde nær fikspunktet. Følgen svinger mellom to verdier.
<!--SR:!2026-10-27,3,250-->

## Konvergensorden

Definer konvergensorden $q$.?
Det positive tallet $q$ der $\lim_{n\to\infty}\frac{e_{n+1}}{e_n^q}$ eksisterer og er $\neq0$.

Hva er $q$ hvis $0<|f'(r)|<1$?:: $q=1$, og grenseverdien er $|f'(r)|$.
<!--SR:!2026-10-27,3,250-->
Hva er $q$ hvis $f'(r)=0$ og $f''(r)\neq0$?:: $q=2$, og grenseverdien er $\frac12|f''(r)|$.
<!--SR:!2026-10-27,3,250-->
Hvilket teorem brukes for å finne $q=2$?:: Taylors teorem: $f(a_n)-f(r)=\frac12 f''(\xi_n)(a_n-r)^2$.
<!--SR:!2026-10-27,4,270-->
For å vise $q=1$, hva må du vise om $|f'(r)|$?:: At $0<|f'(r)|<1$. Et øvre tak på grenseverdien er ikke nok, den må være $\neq0$.
<!--SR:!2026-10-27,3,250-->

## Oppgavemønster: «garanter feil < ε»

Hvilken formel brukes for å garantere $e_n<\varepsilon$?:: $e_n\le\alpha^n e_0$, løs for $n$.
<!--SR:!2026-10-26,2,230-->
Hva er de fire stegene når du skal garantere feil $<\varepsilon$?
?
1. Velg intervall $I$ med $f(I)\subseteq I$
2. Finn $\alpha=\max_I|f'|<1$
3. Begrens $e_0$ (f.eks. lengden av $I$)
4. Løs $\alpha^n e_0<\varepsilon$, altså $n>\frac{\ln(\varepsilon/e_0)}{\ln\alpha}$
<!--SR:!2026-10-26,2,230-->

Hvorfor snur ulikhetstegnet når du løser $\alpha^n e_0<\varepsilon$ med $\ln$?:: $\ln\alpha<0$ fordi $\alpha<1$, og å dele på et negativt tall snur ulikheten.
<!--SR:!2026-10-26,2,230-->
Hvordan sjekker du at $f$ avbilder $I$ inn i seg selv?:: Finn bildet $f(I)$ (bruk at $f$ er voksende/avtagende) og sjekk at endepunktene ligger i $I$.
<!--SR:!2026-10-26,2,230-->

## Eksempel: $f(\theta)=\cos\theta$

Hvilket intervall passer for $\cos\theta=\theta$, og hvorfor?:: $I=[0.6,0.9]$, fordi $\cos 0.9\approx0.62$ og $\cos 0.6\approx0.83$ ligger begge i $I$.
<!--SR:!2026-10-25,1,230-->
Hvor stor er $\alpha$ for $\cos$ på $[0.6,0.9]$?:: $\alpha=\sin0.9\approx0.78$, siden $\sin$ er voksende.
<!--SR:!2026-10-26,2,230-->
Hvorfor er $\sin\theta<\tfrac12$ ikke gyldig på $[0.6,0.8]$?:: $\pi/6\approx0.52<0.6$, så intervallet ligger utenfor der påstanden gjelder.
<!--SR:!2026-10-27,3,250-->
Hva er den eksakte grenseverdien $e_{n+1}/e_n$ for $\cos$?:: $\sin r\approx0.67$, så $q=1$.

## Metode

Du sitter fast på en oppgave. Hva er det første du gjør?:: Jobb bakover fra målet: hva trenger jeg for å få det jeg vil ha?
<!--SR:!2026-10-25,1,230-->
Hvor lenge skal du sitte fast uten ny idé før du ser på en løsning?:: Ca. 20–30 minutter. Se løsningen, forstå hvert steg, lukk den og løs oppgaven på nytt.
<!--SR:!2026-10-27,4,270-->
