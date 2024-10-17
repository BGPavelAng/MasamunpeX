<h1>MasamunpeX</h1>
Version Masamunpe para Linux.<br>
Es una herramienta para analizar procesos en ejecución o binarios en linux.

----------------------------------------------------------------------------------------------------------------------

<h1>MasamunpeX GUI - 0.5.4</h1>

Agregado checador de seguridad

-RELRO<br>
-PIE<br>
-NX<br>
-Canarios<br>
-Verificador de randomize_va_space<br>

-Arreglo de errores.<br>
-Mejora visual.

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

![1](https://github.com/user-attachments/assets/6bc97b3f-aadc-4612-bb96-0bb281e35a5d)

![2](https://github.com/user-attachments/assets/2496e42f-1d7c-4135-b12f-2e2bb11b446d)

![3](https://github.com/user-attachments/assets/71bbea7b-b5ad-4e53-845e-6d46ec9963cc)

![4](https://github.com/user-attachments/assets/3091f3a5-f6a1-4128-bbb1-a373b7310fd5)

![5](https://github.com/user-attachments/assets/0439a91d-8164-47f9-97f2-ba986c19bdc1)
