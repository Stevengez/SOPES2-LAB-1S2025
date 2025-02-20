# Compilación de un Kernel de Linux
## 0. Sistema Operativo
[Descarga de Linux Mint 22](https://www.linuxmint.com/edition.php?id=316) (Version compatible con linux kernel 6.8)

## 1. Extraer el código fuente del kernel  
[Descargar Kernel de Linux](https://www.kernel.org) (Descargar version 6.8)

Extrae el código fuente del kernel de Linux:
```sh
tar -xvf linux-6.8.tar.xz
```

## 2. Instalar dependencias necesarias  
Asegúrate de instalar los paquetes esenciales para la compilación del kernel:  

```sh
sudo apt -y install build-essential libncurses-dev bison flex libssl-dev libelf-dev fakeroot
```

## 3. Configurar el kernel 

Generar configuracion basada en el kernel actual
```sh
make localmodconfig
```

Desactiva las claves de confianza del sistema para evitar problemas con la firma de módulos:  

```sh
scripts/config --disable SYSTEM_TRUSTED_KEYS && \
scripts/config --disable SYSTEM_REVOCATION_KEYS && \
scripts/config --set-str CONFIG_SYSTEM_TRUSTED_KEYS "" && \
scripts/config --set-str CONFIG_SYSTEM_REVOCATION_KEYS ""
```

## 4. Compilar el kernel  
Ejecuta la compilación utilizando `fakeroot` y habilita el uso de 4 núcleos para acelerar el proceso:  

```sh
fakeroot make -j4
```

## 5. Instalar Kernel
```sh
sudo make modules_install
sudo make install
```

## Notas  
- Asegúrate de estar en el directorio correcto antes de ejecutar los comandos.  
- Puedes ajustar `-j4` según la cantidad de núcleos de tu CPU para optimizar el rendimiento.  
- La compilación puede tardar varios minutos o incluso horas dependiendo del hardware.  

