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


MasamunpeX GUI

ChatGPT aun no lo activo, pero pronto estará listo.

Instalación necesaria - Gtk3

Si aparece un error de D-bus es normal, puede arrreglarse con el siguiente comando "systemctl restart dbus"
(Precaución, si reinicias dbus en tu sistema habrá un reinicio y podrías perder tu información).

En caso de aparecer "tubería rota o Break pipe", es normal, al intentar abrir un archivo siendo root desde el usuario puede provocar ese tipo de alerta, puedes verificarlo con "ls ~/.config/dconf", pero es normal, no hay necesidad de arreglar nada.

Hay probabilidad de tener errores cuando se atacan procesos activos y producir congelamiento del sistema, hay que tener cuidado, pronto se buscará una forma de ejecutar binarios de forma segura.

![Captura desde 2023-10-14 20-46-34](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/c92912fa-7f6e-4d20-a5a1-71af90ee4683)
![Captura desde 2023-10-14 20-46-40](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/69fbfdb0-6f77-40fb-84e8-394b3c7e1fa3)
![Captura desde 2023-10-14 20-46-58](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/ff2b7cc5-3e4a-4744-9fa5-7350cdddb65e)
![Captura desde 2023-10-14 20-47-05](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/e96c2950-96f7-4ba3-8944-95aba98495d2)
![Captura desde 2023-10-14 20-47-10](https://github.com/BGPavelAng/MasamunpeX/assets/50802374/d35a8447-66ed-4785-b5a7-196ffd6e431b)
