# MasamunpeX
Version Masamunpe para Linux.<br>
Es una herramienta para analizar procesos en ejecución en linux que podrían estar dañando al sistema como algun malware.<br> Ataca programas en memoría para ayudar a comprender el funcionamiento.

Actualmente:
Se puede listar los procesos ejecutados.<br>
Mostrar datos del programa ( mapeo ELF).<br>
Mostrar datos de segmentos ( mapeo ELF).<br>
Lista de hexadecimales.<br>
Dumpeo de memoria (/proc/{id}/mem & maps)<br><br>

Procesos faltantes:<br><br>

Lista de Symbols utilizados en la aplicación.<br><br>

![sb1](https://user-images.githubusercontent.com/50802374/161444288-f9e518e9-e16e-42f3-858a-6adb0e8ff4d3.png)

----------------------------------------------------------------------------------------------------------------------

MasamunpeX GUI

ChatGPT aun no lo activo, pero pronto estará listo.

Instalación necesaria - Gtk3

Si aparece un error de D-bus de un archivo o directorio no encontrado, puede arrreglarse con el siguiente comando "systemctl restart dbus" o reiniciar tu sistema, sin embargo, la aplicación sigue funcionando sin problema.
(Precaución, si reinicias dbus habrá un reinicio de sistema y podrías perder tu información que no hayas guardado).

En caso de aparecer "tubería rota o Break pipe", es normal, al intentar abrir un archivo siendo root desde el usuario puede provocar ese tipo de alerta, puedes verificarlo con "ls ~/.config/dconf", pero es normal, no hay necesidad de arreglar nada.

Hay probabilidad de tener errores cuando se atacan procesos activos y producir congelamiento del sistema, hay que tener cuidado, pronto se buscará una forma de ejecutar binarios de forma segura.

![1](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/34ef46ce-3d97-41bc-9bc7-36ab41c2bbf8)
![2](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/4305db55-5a21-42fe-aeee-c0bf10d8e8ea)
![3](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/28e1a3a1-f868-44be-b657-e38ebd2ac64e)
![4](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/abcd4b16-bfca-4c71-8893-9821ea8b4188)
![5](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/684ddf0f-6248-4e26-946c-9b21209801ee)
![6](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/fd788dab-f88c-47dc-a158-230c82b1604f)
