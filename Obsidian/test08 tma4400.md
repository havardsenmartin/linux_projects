Bestem grenseverdien

Du kan bruke funksjoner som asin, acos og atan (eller arcsin, arccos og arctan) i svaret ditt. Dette er inversfunksjonene til sin, cos og tan, respektivt.

Hint: Se på uttrykket som en Riemann-sum.
$$
\int \frac{15}{9x^2+25}dx
$$

$$
=\frac{15}{25}\int \frac{1}{\frac{9}{25}x^2+1}dx
$$

$$
=\frac{15}{25}\int \frac{1}{(\frac{3}{5}x)^2+1}dx
$$

Recall that

$$
\frac{d}{dx} \tan^{-1} u = \frac{du}{dx}\frac{1}{u^2+1}
$$

Let $u = \frac{3}{5}x$

$$
\frac{d}{dx} \tan^{-1} (\frac{3}{5}x) = \frac{d}{dx}(\frac{3}{5}x)\frac{1}{(\frac{3}{5}x)^2+1}
$$

$$
\frac{d}{dx} \tan^{-1} (\frac{3}{5}x) = \frac{3}{5}\frac{1}{(\frac{3}{5}x)^2+1}
$$

$$
\frac{5}{3}\frac{d}{dx} \tan^{-1} (\frac{3}{5}x) = \frac{1}{(\frac{3}{5}x)^2+1}
$$

Subbing this into the integral we get

$$
=\frac{15}{25}\int \frac{5}{3}\frac{d}{dx} \tan^{-1} (\frac{3}{5}x) dx
$$

$$
=\frac{15}{25}\frac{5}{3}\tan^{-1} (\frac{3}{5}x) + C
$$

$$
=\tan^{-1} (\frac{3}{5}x) + C
$$



$$
[\tan^{-1} (\frac{3}{5}x) + C]_{x=0}^{1}
$$


$$
=\tan^{-1} (\frac{3}{5})
-\tan^{-1} (0)
$$


$$
=\tan^{-1} (\frac{3}{5})

$$












