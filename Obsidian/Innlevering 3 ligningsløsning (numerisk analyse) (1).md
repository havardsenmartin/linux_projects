#review
Løs likningen $\theta=\cos \theta$ med fikspunktiterasjon. 
Spiller initialverdien $a_0$ noen rolle i iterasjonen? Hvor mange interasjoner trengs for å nå presisjonen $10^{-12}$? 
Bruk gjerne Jupyter notebook-ene om fikspunktiterasjoner.

##### Fikspunktiterasjon
La ${}F(\theta)=\cos \theta{}$. Vi ønsker å løse 
 $$
 F(\theta)=\theta
 $$
La ${}\{ a_{n} \}_{n=0}^{\infty}{}$ være følgen gitt ved
$$
a_{n+1}=F(a_{n})
$$
##### Eksempel
La ${}a_{0}=0{}$.
Da får vi
$$
\begin{aligned}
&a_{1}=\cos 0 =1 \\
&a_{2}=\cos 1 \approx 0.54 \\
&a_{3}=\cos(\cos 1) \approx \cos(0.54) \approx 0.8577\\
&a_{4}=\cos(\cos(\cos 1)) \approx \cos(0.8577) \approx 0.65417\\
&
\end{aligned}
$$

### Hva spør oppgaven *egentlig* om?
>[!important] "Hvor mange iterasjoner trengs for å nå presisjonen ${}10^{-12}{}$?" -> 
	>Hvor mange iterasjoner trengs for at
> $$
> |\epsilon| = |\theta_{\text{eksakt}}-\theta_{\text{numerisk}}| \leq 10^{-12}
> $$
$$
\begin{aligned}
\cos\theta &=\theta \\
\cos ^{2}\theta  & =\theta^{2} \\
1-\sin ^{2}\theta & =\theta^{2} \\
\sqrt{ 1-\sin ^{2}\theta } & =\left| \theta \right| \\
\sin ^{2}\theta &=1-\theta^{2} \\
\left| \sin\theta \right| &=\sqrt{1-\theta^{2}} \\
\end{aligned}
$$

[[I3TMA4400 informert svar]]

>[!important] test der
> sdfjksdlflj 
> asdjkfsjd
> asdf
> ajsdf
> jasdf
> jasdf
> 
>


---
Fra beviset av Teorem 2 ser vi at

$$
\lim_{n\to\infty}\frac{e_{n+1}}{e_{n}}=\lim_{n\to\infty}|f'(\xi_n)|=|f'(r)|.
$$

Altså er konvergensorden for fikspunktiterasjonen med $f(x)$ lik 1 dersom $0 \neq |f'(r)|<1$. 

Merk at $|f'(r)|<1$ impliserer at feilen avtar. 

---

> [!question] Bør ikke ${}\lim_{ n \to \infty } \frac{e_{n}+1}{e_{n}}=0{}$. Ellers vil error kunne gå lavere?



`abs(følge[i]-np.sqrt(2))/(abs(følge[i-1]-np.sqrt(2))**2)`
$$
=\frac{\left| n_{i}-\sqrt{ 2 } \right|}{\left| n_{i-1} -\sqrt{ 2 }\right|^{2}}
$$
Eller
$$
= \frac{\left| n_{i+1}-\sqrt{ 2 } \right|}{\left| n_{i}-\sqrt{ 2 } ^{2}\right|}
$$

> [!important] LaTeX suite shortcuts
>Husk `sts` for `_\text{}`
>Husk `nsq` for `\sqrt[]{}`


