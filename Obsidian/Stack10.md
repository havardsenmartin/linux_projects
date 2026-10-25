##### Spørsmål 1
Finn grenseverdien
$$
\lim_{ x \to 0 } \frac{15 \tan(3x)-45x}{3x^{3}}
$$
Hint: Skriv om telleren ved hjelp av taylorpolynom. 

Svaret skal være et eksakt rasjonalt tall.


$$
T_{n}=\sum_{i=0}^{n} \frac{1}{i!} x^{i} f^{(i)}(0)
$$

$$
T_{3} = f(0) + x\cdot f'(0) + \frac{1}{2} x \cdot f''(0) + \frac{1}{6} x \cdot f'''(0)
$$
$$
\frac{d}{dx} [\tan x] = \tan ^{2}x+1
$$

$$
\frac{d}{dx}[\tan ^{2}x +1] = 2 \tan x \cdot (\tan ^{2} x + 1)
$$
$$
2\tan ^{3}x + 2\tan x
$$

$$
\frac{d}{dx} [2\tan ^{3}x+2\tan x]=6\tan ^{2}x \cdot(\tan ^{2} x +1) + 2\tan ^{2}x + 2
$$

$$
\frac{d}{dx}[6\tan ^{2}x \cdot(\tan ^{2} x +1) + 2\tan ^{2}x + 2]\\
=
\frac{d}{dx}[6 \tan ^{4} x + 6 \tan ^{2}x + 2\tan ^{2}x+2]\\
= 24 \tan ^{4}x \cdot(\tan ^{2}x+1) +12 \tan x\cdot(\tan ^{2}x+1) + 4 \tan x(\tan ^{2} x+1)
$$


| ${}i{}$ | ${}f^{(i)}(0){}$ | ${}f^{(i)}(x){}$                                                                                |
| ------- | ---------------- | ----------------------------------------------------------------------------------------------- |
| 0       | 0                | ${}\tan x{}$                                                                                    |
| 1       | 1                | ${}\tan ^{2}x+1{}$                                                                              |
| 2       | 0                | ${}2\tan ^{3}x + 2\tan x{}$                                                                     |
| 3       | 2                | ${}6\tan ^{2}x \cdot(\tan ^{2} x +1) + 2\tan ^{2}x + 2{}$                                       |
| 4       | 0                | ${}24 \tan ^{4}x \cdot(\tan ^{2}x+1) +12 \tan x\cdot(\tan ^{2}x+1) + 4 \tan x(\tan ^{2} x+1){}$ |
| 5       | 4                | ${}(0)\cdot(\dots) + 12 + 4{}$ = 16                                                             |

##### Conjecture

$$
\left[\frac{d^{(i)}}{dx^{(i)}}[\tan x] \right]_{x=0} = \begin{cases}
0  & i \text{ is even} \\
2^{(i-1)/2}  & i \text{ is odd} \\
\end{cases} 
$$
##### Resulting Maclaurin series


$$
T_{n}=\sum_{i=0}^{n} \frac{1}{i!} x^{i} f^{(i)}(0)
$$

Blir derfor 
$$
T_{n} = 1 x^{0} \cdot(0) + 1x \cdot(1) + (0)+\frac{1}{3!}x^{3}\cdot(2)+(0)+\frac{1}{5!}x^{5}\cdot(4) + \dots + \frac{1}{n} x^{n} (2^{(n-1)/2}) \quad \text{gitt odd }n
$$

##### Eksakt

$$
T_{\infty} = \tan x=1 x^{0} \cdot(0) + 1x \cdot(1) + (0)+\frac{1}{3!}x^{3}\cdot(2)+(0)+\frac{1}{5!}x^{5}\cdot(4) + \dots
$$

$$
= x + \sum_{i=1}^{\infty} \frac{2i}{(2i+1)!}x^{(2i+1)}
$$

##### Tilbake til oppgaven


$$
\lim_{ x \to 0 } \frac{15 \tan(3x)-45x}{3x^{3}}
$$

$$
= \lim_{ x \to 0 } \frac{15 \left[ (3x) + \frac{2}{3!}(3x)^{3}+\frac{4}{5!}(3x)^{5}+ + \frac{6}{7!}(3x)^{7} + \dots \right]-45x}{3x^{3}}
$$
