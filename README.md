# asteroids_sdl
После того как почитал и поделал туториалы с [lazyfoo](https://lazyfoo.net/tutorials/SDL/index.php). Решил сделать свою собственную труъ игрульку, но конечно самое простое для практики [asteroids](https://ru.wikipedia.org/wiki/Asteroids)

## история изменений: 
- 10.09 первый коммит. сделал только отрисовку сцены и корявое движение кораблика
- 12.09 сделал более плавное движение кораблика, оно умеет стрелять, оно умеет "выходить" с другой стороны экрана при достижении границы сверху/снизу. добавил первый астероид, вспомнил плюсовое наследование
- 13.09 сделал рандомный спавн астеройдов. сделал три типа астеройдов. перебрал некоторую логику и расфасовал по разным классам. теперь астеройды можно уничтожать. при уничтожении астеройда появляются новые, если убил большой - появляется на его месте два средних, убил средний - появляется на его месте три маленьких, при убийстве маленького астеройда ничего не спавнится.

## планы:
- сделать gui (количество жизней/количество патрон/счетчик очков)
- ~~сделать рандомный спавн астеройдов~~
- ~~три типа астеройдов. большой/средний/маленький. при убийстве большого астеройда - появляется два средних, при убийстве среднего - три маленьких~~
- ~~коллизии~~
- сделать какой нибудь бэкграунд
- прибить хоть какой нибуль звук
- поиграться с частицами, было бы круто что бы у кораблика был "двигатель"
- сделать какие нибудь бонусы, по типу защиты, расширение максимального кол-ва выстрелов, дополнительные жизни

## текущий вид игрули (13.09)
![animation](https://github.com/PeterLavreniuk/asteroids_sdl/blob/master/readme/130920_gplay.gif)
