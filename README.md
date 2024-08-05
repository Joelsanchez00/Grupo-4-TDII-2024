# Grupo-4-TDII-2024

App 1.1: Desarrolle una aplicaci´on que encienda y apague de manera secuencial los
tres leds onboard de la placa de desarrollo. La secuencia debe encender 200 ms y
apagar 200 ms cada led comenzando por el LED1 (Green), continuando con el LED2
(Blue) y luego el LED3 (Red) para volver a iniciar con el LED1. La aplicaci´on debe
ser de car´acter general, de manera que pueda extenderse a una cantidad mayor de
leds con m´ınimas modificaciones, por este motivo se sugiere que use un vector para
el manejo de los Leds.

App 1.2: Desarrolle una aplicaci´on que utilice el pulsador onboard de la placa de
desarrollo para alternar entre dos secuencias diferentes. La aplicaci´on inicia con la
secuencia de la App 1.1 y, cuando se presione el pulsador, dicha secuencia debe
invertirse y continuar, de manera que, cada vez que se presione el pulsador la
secuencia actual se invierta. La aplicaci´on debe ser de car´acter general, por lo que
aplica la misma recomendaci´on para el punto anterior.


App 1.3: Desarrolle una aplicaci´on que utilice el pulsador onboard de la placa de
desarrollo para alternar entre cuatro secuencias diferentes. La app iniciar´a con la
secuencia 1 hasta que se presione el pulsador y pase a la secuencia 2, luego de presionar
de nuevo el pulsador pasar´a a la secuencia 3 y as´ı, sucesivamente, hasta la secuencia
4 para volver a comenzar con la secuencia 1. Descripci´on de las secuencias:
Secuencia 1: idem App 1.1 con una alternancia de 150 ms.
Secuencia 2: hace parpadear los tres leds simult´aneamente con una alternancia
de 300 ms.
Secuencia 3: hace parpadear el LED1 con una alternancia de 100 ms, el LED2
con una alternancia de 300 ms y el led3 con una alternancia de 600 ms.
Secuencia 4: Hace parpadear simult´aneamente LED1 y LED3, mientras que
LED2 lo har´a de manera inversa, con una alternancia de 150 ms. Mientras LED1
y LED3 est´an encendidos, LED2 estar´a apagado y luego a la inversa


App 1.4: Desarrolle una aplicaci´on que haga parpadear simult´aneamente los 3 leds
onboard de la placa y que use el pulsador onboard para cambiar la frecuencia de
parpadeo de manera secuencial entre 4 frecuencias predefinidas por los siguientes
tiempos de alternancia:
Tiempo 1: 100 ms.
Tiempo 2: 250 ms.
Tiempo 3: 500 ms.
Tiempo 4: 1000 ms.
La aplicaci´on inicia con la alternancia determinada por el tiempo 1, al presionar el
pulsador pasa al tiempo 2 y as´ı sucesivamente hasta llegar al tiempo 4, para reiniciar
con el tiempo 1.
