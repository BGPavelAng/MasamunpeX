<h1>MasamunpeX</h1>
Version Masamunpe para Linux.<br>
Es una herramienta para analizar procesos en ejecución o binarios en linux.

----------------------------------------------------------------------------------------------------------------------

<h1>MasamunpeX GUI - 0.5.3</h1>

Agregado checador de seguridad

-RELRO
-PIE
-NX
-Verificador de randomize_va_space

-Arreglo de errores.

---------------------

Instalación necesaria

Gtk3<br>
libcurl<br>
curl

*Si persiste un anuncio sobre libcurl es probable que se necesite la librería de desarrollo
libcurl-devel (fedora) o libcurl-dev (ubuntu)

---------------------

Si aparece un error de D-bus de un archivo o directorio no encontrado, puede arrreglarse con el siguiente comando "systemctl restart dbus" o reiniciar tu sistema, sin embargo, la aplicación sigue funcionando sin problema.
(Precaución, si reinicias dbus habrá un reinicio de sistema y podrías perder tu información que no hayas guardado).

En caso de aparecer "tubería rota o Break pipe", es normal, al intentar abrir un archivo siendo root desde el usuario puede provocar ese tipo de alerta, puedes verificarlo con "ls ~/.config/dconf", pero es normal, no hay necesidad de arreglar nada.

Hay probabilidad de tener errores cuando se atacan procesos activos y producir congelamiento del sistema, hay que tener cuidado.

![1](https://github.com/user-attachments/assets/dc59b943-af57-4d1f-a369-bf6dc42bd872)}

![2](https://github.com/user-attachments/assets/4cdf6aea-e961-4cb8-a715-fb8bf3b8e76f)

![3](https://github.com/user-attachments/assets/ac591cc5-63ed-41f7-bb58-c52a077eb229)

![4](https://github.com/user-attachments/assets/aa801906-9586-426d-bdb6-fa92dcf2c194)

![5](https://github.com/user-attachments/assets/e026733e-049c-4d2f-bb94-1b82ae0a521c)
