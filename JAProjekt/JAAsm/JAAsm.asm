; Damian Wieczorek G5 Sekcja 1
; rok akademicki 2022/2023


.code


; Funkcja jest funkcj¹ dylatacji i oblicza czy œrodkowy piksel ma byæ czarny czy bia³y na podstawie pikseli otaczaj¹cych
; Jeœli choæ jeden piksel z pikseli otaczaj¹cych jest czarny to œrodkowy te¿ jest czarny
; a: Lewy górny piksel
; b: Œrodkowy górny piksel
; c: Prawy górny piksel
; d: Lewy œrodkowy piksel
; e: Prawy œrodkowy piksel
; f: Lewy dolny piksel
; g: Œrodkowy dolny piksel
; h: Prawy dolny piksel
; Funkcja zwraca wartoœæ 1 jeœli piksel jest czarny i 0 jeœli jest bia³y
dilatation proc a:DWORD, b:DWORD, c:DWORD, d:DWORD, e:DWORD, f:DWORD, g:DWORD, h:DWORD

pinsrw xmm0,rcx,0				;wpisanie do rejestru xmm0 na 0 miejsce wartoœci z rejestru rcx, czyli argument a
pinsrw xmm0,rdx,1				;wpisanie do rejestru xmm0 na 1 miejsce wartoœci z rejestru rdx, czyli argument b
pinsrw xmm0,r8,2				;wpisanie do rejestru xmm0 na 2 miejsce wartoœci z rejestru r8, czyli argument c
pinsrw xmm0,r9,3				;wpisanie do rejestru xmm0 na 3 miejsce wartoœci z rejestru r9, czyli argument d

mov rbx, QWORD PTR[rbp+48]		;wpisanie do rejestru rbx 1 wartoœci ze stosu, czyli argument e
pinsrw xmm1,rbx,0				;wpisanie do rejestru xmm1 na 0 miejsce wartoœci z rejestru rbx, czyli argument e

mov rbx, QWORD PTR[rbp+56]		;wpisanie do rejestru rbx 2 wartoœci ze stosu, czyli argument f
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce wartoœci z rejestru rbx, czyli argument f

mov rbx, QWORD PTR[rbp+64]		;wpisanie do rejestru rbx 3 wartoœci ze stosu, czyli argument g
pinsrw xmm1,rbx,2				;wpisanie do rejestru xmm1 na 2 miejsce wartoœci z rejestru rbx, czyli argument g

mov rbx, QWORD PTR[rbp+72]		;wpisanie do rejestru rbx 4 wartoœci ze stosu, czyli argument h
pinsrw xmm1,rbx,3				;wpisanie do rejestru xmm1 na 3 miejsce wartoœci z rejestru rbx, czyli argument h

pmaxsd xmm0,xmm1				;obliczanie maksymalnej wartoœci wektorowo na rejestrach xmm0 i xmm1

pextrw rbx,xmm0,3				;pobranie z rejestru xmm0 z miejsca 3 wartoœci i zapisanie do rejestru rbx
pextrw rax,xmm0,2				;pobranie z rejestru xmm0 z miejsca 2 wartoœci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce wartoœci z rejestru rax
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce wartoœci z rejestru rbx

pmaxsd xmm0,xmm1				;obliczanie maksymalnej wartoœci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,1				;pobranie z rejestru xmm0 z miejsca 1 wartoœci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce wartoœci z rejestru rax

pmaxsd xmm0,xmm1				;obliczanie maksymalnej wartoœci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,0				;pobranie z rejestru xmm0 z miejsca 0 wartoœci i zapisanie do rejestru rax
ret								;zwrócenie wartosci w rejestrze rax
dilatation endp


; Funkcja jest funkcj¹ eorzji i oblicza czy œrodkowy piksel ma byæ czarny czy bia³y na podstawie pikseli otaczaj¹cych
; Jeœli choæ jeden piksel z pikseli otaczaj¹cych jest bia³y to œrodkowy te¿ jest bia³y
; a: Lewy górny piksel
; b: Œrodkowy górny piksel
; c: Prawy górny piksel
; d: Lewy œrodkowy piksel
; e: Prawy œrodkowy piksel
; f: Lewy dolny piksel
; g: Œrodkowy dolny piksel
; h: Prawy dolny piksel
; Funkcja zwraca wartoœæ 1 jeœli piksel jest czarny i 0 jeœli jest bia³y
erosion proc a:DWORD, b:DWORD, c:DWORD, d:DWORD, e:DWORD, f:DWORD, g:DWORD, h:DWORD

pinsrw xmm0,rcx,0				;wpisanie do rejestru xmm0 na 0 miejsce wartoœci z rejestru rcx, czyli argument a
pinsrw xmm0,rdx,1				;wpisanie do rejestru xmm0 na 1 miejsce wartoœci z rejestru rdx, czyli argument b
pinsrw xmm0,r8,2				;wpisanie do rejestru xmm0 na 2 miejsce wartoœci z rejestru r8, czyli argument c
pinsrw xmm0,r9,3				;wpisanie do rejestru xmm0 na 3 miejsce wartoœci z rejestru r9, czyli argument d

mov rbx, QWORD PTR[rbp+48]		;wpisanie do rejestru rbx 1 wartoœci ze stosu, czyli argument e
pinsrw xmm1,rbx,0				;wpisanie do rejestru xmm1 na 0 miejsce wartoœci z rejestru rbx, czyli argument e

mov rbx, QWORD PTR[rbp+56]		;wpisanie do rejestru rbx 2 wartoœci ze stosu, czyli argument f
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce wartoœci z rejestru rbx, czyli argument f

mov rbx, QWORD PTR[rbp+64]		;wpisanie do rejestru rbx 3 wartoœci ze stosu, czyli argument g
pinsrw xmm1,rbx,2				;wpisanie do rejestru xmm1 na 2 miejsce wartoœci z rejestru rbx, czyli argument g

mov rbx, QWORD PTR[rbp+72]		;wpisanie do rejestru rbx 4 wartoœci ze stosu, czyli argument h
pinsrw xmm1,rbx,3				;wpisanie do rejestru xmm1 na 3 miejsce wartoœci z rejestru rbx, czyli argument h

pminsd xmm0,xmm1				;obliczanie minimalnej wartoœci wektorowo na rejestrach xmm0 i xmm1

pextrw rbx,xmm0,3				;pobranie z rejestru xmm0 z miejsca 3 wartoœci i zapisanie do rejestru rbx
pextrw rax,xmm0,2				;pobranie z rejestru xmm0 z miejsca 2 wartoœci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce wartoœci z rejestru rax
pinsrw xmm1,rbx,1				;wpisanie do rejestru xmm1 na 1 miejsce wartoœci z rejestru rbx

pminsd xmm0,xmm1				;obliczanie minimalnej wartoœci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,1				;pobranie z rejestru xmm0 z miejsca 1 wartoœci i zapisanie do rejestru rax

pinsrw xmm1,rax,0				;wpisanie do rejestru xmm1 na 0 miejsce wartoœci z rejestru rax

pminsd xmm0,xmm1				;obliczanie minimalnej wartoœci wektorowo na rejestrach xmm0 i xmm1

pextrw rax,xmm0,0				;pobranie z rejestru xmm0 z miejsca 0 wartoœci i zapisanie do rejestru rax
ret								;zwrócenie wartosci w rejestrze rax
erosion endp

end
