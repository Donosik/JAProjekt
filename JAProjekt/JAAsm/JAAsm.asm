; Damian Wieczorek G5 Sekcja 1
; rok akademicki 2022/2023


.code


; Funkcja jest funkcj� dylatacji i oblicza czy �rodkowy piksel ma by� czarny czy bia�y na podstawie pikseli otaczaj�cych
; Je�li cho� jeden piksel z pikseli otaczaj�cych jest czarny to �rodkowy te� jest czarny
; a: Lewy g�rny piksel
; b: �rodkowy g�rny piksel
; c: Prawy g�rny piksel
; d: Lewy �rodkowy piksel
; e: Prawy �rodkowy piksel
; f: Lewy dolny piksel
; g: �rodkowy dolny piksel
; h: Prawy dolny piksel
; Funkcja zwraca warto�� 1 je�li piksel jest czarny i 0 je�li jest bia�y
dilatation proc a:DWORD, b:DWORD, c:DWORD, d:DWORD, e:DWORD, f:DWORD, g:DWORD, h:DWORD

pinsrw xmm0,rcx,0				;wpisanie do rejestru xmm0 na 0 miejsce warto�ci z rejestru rcx, czyli argument a
pinsrw xmm0,rdx,1				;wpisanie do rejestru xmm0 na 1 miejsce warto�ci z rejestru rdx, czyli argument b
pinsrw xmm0,r8,2				;wpisanie do rejestru xmm0 na 2 miejsce warto�ci z rejestru r8, czyli argument c
pinsrw xmm0,r9,3				;wpisanie do rejestru xmm0 na 3 miejsce warto�ci z rejestru r9, czyli argument d

mov rbx, QWORD PTR[rbp+48]		;wpisanie do rejestru rbx 1 warto�ci ze stosu, czyli argument e
pinsrw xmm1,rbx,0				;wpisanie do rejestru xmm1 na 0 miejsce warto�ci z rejestru rbx, czyli argument e

mov rbx, QWORD PTR[rbp+56]		;wpisanie do rejestru rbx 2 warto�ci ze stosu, czyli argument f
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce warto�ci z rejestru rbx, czyli argument f

mov rbx, QWORD PTR[rbp+64]		;wpisanie do rejestru rbx 3 warto�ci ze stosu, czyli argument g
pinsrw xmm1,rbx,2				;wpisanie do rejestru xmm1 na 2 miejsce warto�ci z rejestru rbx, czyli argument g

mov rbx, QWORD PTR[rbp+72]		;wpisanie do rejestru rbx 4 warto�ci ze stosu, czyli argument h
pinsrw xmm1,rbx,3				;wpisanie do rejestru xmm1 na 3 miejsce warto�ci z rejestru rbx, czyli argument h

pmaxsd xmm0,xmm1				;obliczanie maksymalnej warto�ci wektorowo na rejestrach xmm0 i xmm1

pextrw rbx,xmm0,3				;pobranie z rejestru xmm0 z miejsca 3 warto�ci i zapisanie do rejestru rbx
pextrw rax,xmm0,2				;pobranie z rejestru xmm0 z miejsca 2 warto�ci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce warto�ci z rejestru rax
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce warto�ci z rejestru rbx

pmaxsd xmm0,xmm1				;obliczanie maksymalnej warto�ci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,1				;pobranie z rejestru xmm0 z miejsca 1 warto�ci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce warto�ci z rejestru rax

pmaxsd xmm0,xmm1				;obliczanie maksymalnej warto�ci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,0				;pobranie z rejestru xmm0 z miejsca 0 warto�ci i zapisanie do rejestru rax
ret								;zwr�cenie wartosci w rejestrze rax
dilatation endp


; Funkcja jest funkcj� eorzji i oblicza czy �rodkowy piksel ma by� czarny czy bia�y na podstawie pikseli otaczaj�cych
; Je�li cho� jeden piksel z pikseli otaczaj�cych jest bia�y to �rodkowy te� jest bia�y
; a: Lewy g�rny piksel
; b: �rodkowy g�rny piksel
; c: Prawy g�rny piksel
; d: Lewy �rodkowy piksel
; e: Prawy �rodkowy piksel
; f: Lewy dolny piksel
; g: �rodkowy dolny piksel
; h: Prawy dolny piksel
; Funkcja zwraca warto�� 1 je�li piksel jest czarny i 0 je�li jest bia�y
erosion proc a:DWORD, b:DWORD, c:DWORD, d:DWORD, e:DWORD, f:DWORD, g:DWORD, h:DWORD

pinsrw xmm0,rcx,0				;wpisanie do rejestru xmm0 na 0 miejsce warto�ci z rejestru rcx, czyli argument a
pinsrw xmm0,rdx,1				;wpisanie do rejestru xmm0 na 1 miejsce warto�ci z rejestru rdx, czyli argument b
pinsrw xmm0,r8,2				;wpisanie do rejestru xmm0 na 2 miejsce warto�ci z rejestru r8, czyli argument c
pinsrw xmm0,r9,3				;wpisanie do rejestru xmm0 na 3 miejsce warto�ci z rejestru r9, czyli argument d

mov rbx, QWORD PTR[rbp+48]		;wpisanie do rejestru rbx 1 warto�ci ze stosu, czyli argument e
pinsrw xmm1,rbx,0				;wpisanie do rejestru xmm1 na 0 miejsce warto�ci z rejestru rbx, czyli argument e

mov rbx, QWORD PTR[rbp+56]		;wpisanie do rejestru rbx 2 warto�ci ze stosu, czyli argument f
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce warto�ci z rejestru rbx, czyli argument f

mov rbx, QWORD PTR[rbp+64]		;wpisanie do rejestru rbx 3 warto�ci ze stosu, czyli argument g
pinsrw xmm1,rbx,2				;wpisanie do rejestru xmm1 na 2 miejsce warto�ci z rejestru rbx, czyli argument g

mov rbx, QWORD PTR[rbp+72]		;wpisanie do rejestru rbx 4 warto�ci ze stosu, czyli argument h
pinsrw xmm1,rbx,3				;wpisanie do rejestru xmm1 na 3 miejsce warto�ci z rejestru rbx, czyli argument h

pminsd xmm0,xmm1				;obliczanie minimalnej warto�ci wektorowo na rejestrach xmm0 i xmm1

pextrw rbx,xmm0,3				;pobranie z rejestru xmm0 z miejsca 3 warto�ci i zapisanie do rejestru rbx
pextrw rax,xmm0,2				;pobranie z rejestru xmm0 z miejsca 2 warto�ci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce warto�ci z rejestru rax
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce warto�ci z rejestru rbx

pminsd xmm0,xmm1				;obliczanie minimalnej warto�ci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,1				;pobranie z rejestru xmm0 z miejsca 1 warto�ci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce warto�ci z rejestru rax

pminsd xmm0,xmm1				;obliczanie minimalnej warto�ci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,0				;pobranie z rejestru xmm0 z miejsca 0 warto�ci i zapisanie do rejestru rax
ret								;zwr�cenie wartosci w rejestrze rax
erosion endp

end
