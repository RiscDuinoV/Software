# Software
Les librairies système du RiscDuinoV sont disponibles dans ce depôt. On va trouver dans ce dépôt les libraries C systèmes et les librairies Arduino qu'on peut utiliser lorsqu'on compile en C++.

## Using system libraries

Avant de pouvoir compiler un projet qui contient des libraries systèmes, il faut d'abord compiler les libraries systèmes. Vous devez le faire qu'une fois.

## Compiling system libraries

Pour compiler les libraries systèmes, vous devez installer CMake. Se referer [ici](https://github.com/RiscDuinoV/RISCV/tree/master/RiscV_Projects) pour comment le faire.

Des que vous avez configuré CMake, vous avez juste à le compiler comme un projet normal et tappant les commandes suivantes :

```sh
$ cmake -G "your generator"
...
-- Configuring done
-- Generating done
-- Build files have been written to: /home/...
$ make
...
# or
$ ninja
...
```

Les fichiers binaires seront crées dans **system/lib/riscv**.
